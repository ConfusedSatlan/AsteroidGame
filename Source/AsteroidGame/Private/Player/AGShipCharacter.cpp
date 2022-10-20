// Confused Game. All Rights Reserved


#include "Player/AGShipCharacter.h"
#include "Components/BoxComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/AGShipFloatingPawnMovement.h"
#include "Components/AGShipHealthComponent.h"
#include "Components/AGShipDefenceComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"


DEFINE_LOG_CATEGORY_STATIC(CharacterLog, All, All);

// Sets default values
AAGShipCharacter::AAGShipCharacter(const FObjectInitializer& ObjInit)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>("CollisionBox");
	SetRootComponent(CollisionBox);
	CollisionBox->SetCollisionProfileName("Pawn");

	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>("SkeletalMesh");
	SkeletalMesh->SetupAttachment(CollisionBox);

	SkeletalMesh->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));

	ShieldMeshEffect = CreateDefaultSubobject<USkeletalMeshComponent>("MeshSheildEffect");
	ShieldMeshEffect->SetupAttachment(SkeletalMesh);

	PawnMovement = CreateDefaultSubobject<UAGShipFloatingPawnMovement>("PawnComponent");
	PawnMovement->MaxSpeed = 300.0f;
	PawnMovement->Acceleration = 300.0f;
	PawnMovement->Deceleration = 200.0f;
	PawnMovement->TurningBoost = 0.1f;

	HealthComponent = CreateDefaultSubobject<UAGShipHealthComponent>("HealthComponent");
	WeaponComponent = CreateDefaultSubobject<UAGShipDefenceComponent>("SkillComponent");
}

// Called when the game starts or when spawned
void AAGShipCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	HealthComponent->OnDeath.AddUObject(this, &AAGShipCharacter::OnDeath);
	HealthComponent->OnImmortalShield.AddUObject(this, &AAGShipCharacter::OnImmortalShield);

	InitEngineFX();
	OffShieldEffect();
}

// Called every frame
void AAGShipCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAGShipCharacter::OnDeath()
{
	PawnMovement->Deactivate();
	UE_LOG(CharacterLog, Error, TEXT("Death"));
}

UNiagaraComponent* AAGShipCharacter::SpawnMuzzleFXEngine(FName EngineFXSocketName)
{
	return UNiagaraFunctionLibrary::SpawnSystemAttached(MuzzleFXEngine, //
		SkeletalMesh, //
		EngineFXSocketName, //
		FVector::ZeroVector, //
		FRotator(0.0f, -90.0f, 0.0f), //
		EAttachLocation::SnapToTarget, true);
}

void AAGShipCharacter::InitEngineFX()
{
	if(EngineComponents.IsEmpty())
	{
		for(int32 i = 0; i<6; ++i)
		{
			auto StringEngineSocketName = MuzzleEngineSocketName.ToString();
			StringEngineSocketName += FString::FromInt(i);
			EngineComponents.Add(SpawnMuzzleFXEngine(FName(*StringEngineSocketName)));
		}
	}
}

void AAGShipCharacter::OnImmortalShield(float ShieldTimeDuraction)
{
	ShieldMeshEffect->SetVisibility(true);
	GetWorld()->GetTimerManager().SetTimer(ShieldEffectTimerHandle, this, &AAGShipCharacter::OffShieldEffect, ShieldTimeDuraction, false);
}

void AAGShipCharacter::OffShieldEffect()
{
	ShieldMeshEffect->SetVisibility(false);
}