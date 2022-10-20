// Confused Game. All Rights Reserved


#include "Player/AGShipPlayerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/BoxComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/AGShipDefenceComponent.h"
#include "AGGameModeBase.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"


DEFINE_LOG_CATEGORY_STATIC(LogPlayerCharacter, All, All);

AAGShipPlayerCharacter::AAGShipPlayerCharacter(const FObjectInitializer& ObjInit) : Super(ObjInit)
{
	PrimaryActorTick.bCanEverTick = true;

	CameraSpring = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	CameraSpring->SetupAttachment(GetRootComponent());

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(CameraSpring, USpringArmComponent::SocketName);

	CameraSpring->SetRelativeRotation(FRotator(-90.f, 0.0f, 0.0f));
	CameraSpring->TargetArmLength = 1000.f;
	CameraSpring->bDoCollisionTest = false;
}

void AAGShipPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called to bind functionality to input
void AAGShipPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (PlayerInputComponent)
	{
		PlayerInputComponent->BindAxis("MoveForward", this, &AAGShipPlayerCharacter::MoveForward);
		PlayerInputComponent->BindAxis("TurnAround", this, &AAGShipPlayerCharacter::TurnAround);

		PlayerInputComponent->BindAction("MoveRight", IE_Pressed , this, &AAGShipPlayerCharacter::MoveRight);
		PlayerInputComponent->BindAction("MoveRight", IE_Released, this, &AAGShipPlayerCharacter::CalibrationMesh);
		PlayerInputComponent->BindAction("MoveLeft", IE_Pressed, this, &AAGShipPlayerCharacter::MoveLeft);
		PlayerInputComponent->BindAction("MoveLeft", IE_Released, this, &AAGShipPlayerCharacter::CalibrationMesh);
		PlayerInputComponent->BindAction("Fire", IE_Pressed, WeaponComponent, &UAGShipDefenceComponent::StartFire);
	}
}

void AAGShipPlayerCharacter::MoveForward(float Amount)
{
	AddMovementInput(GetActorForwardVector(), Amount, true);
}

void AAGShipPlayerCharacter::MoveRight()
{
	if (DegreesRotationMesh > RotationDegreesCounter && !(RotationDegreesCounter < 0))
	{
		++RotationDegreesCounter;
		SetRotationToSkeletalMeshInMovingRightLeft();
	}
	AddMovementInput(GetActorRightVector(), 1, true);
	GetWorld()->GetTimerManager().SetTimer(MovingTimerHandle, this, &AAGShipPlayerCharacter::MoveRight, 0.01, true);
}

void AAGShipPlayerCharacter::MoveLeft()
{
	if (-DegreesRotationMesh < RotationDegreesCounter && !(RotationDegreesCounter > 0))
	{
		--RotationDegreesCounter;
		SetRotationToSkeletalMeshInMovingRightLeft();
	}
	AddMovementInput(GetActorRightVector(), -1, true);
	GetWorld()->GetTimerManager().SetTimer(MovingTimerHandle, this, &AAGShipPlayerCharacter::MoveLeft, 0.01, true);
}

void AAGShipPlayerCharacter::CalibrationMesh()
{
	if (!GetWorld()) return;
	if (GetWorld()->GetTimerManager().IsTimerActive(MovingTimerHandle))
	{
		GetWorld()->GetTimerManager().ClearTimer(MovingTimerHandle);
	}
	GetWorld()->GetTimerManager().SetTimer(CalibrationRotationTimerHandle, this, &AAGShipPlayerCharacter::UpdateDegreesRotation, 0.005f, true);
}

void AAGShipPlayerCharacter::TurnAround(float Amount)
{
	GetRootComponent()->AddLocalRotation(FRotator(0.0f, Amount, 0.0f));
}

void AAGShipPlayerCharacter::OnDeath()
{
	Super::OnDeath();

	UE_LOG(LogPlayerCharacter, Error, TEXT("Death PlayerCharacter"));
	const auto GameMode = Cast<AAGGameModeBase>(GetWorld()->GetAuthGameMode());
	if (GameMode)
	{
		GameMode->GameOver();
	}
	GetBoxComponent()->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	GetSkeletalMeshComponent()->SetHiddenInGame(true);
}

void AAGShipPlayerCharacter::UpdateDegreesRotation()
{
	if (RotationDegreesCounter == 0)
	{
		if (!GetWorld()) return;
		GetWorld()->GetTimerManager().ClearTimer(CalibrationRotationTimerHandle);
	} 
	else if (RotationDegreesCounter > 0)
	{
		--RotationDegreesCounter;
	}
	else if (RotationDegreesCounter < 0)
	{
		++RotationDegreesCounter;
	}
	SetRotationToSkeletalMeshInMovingRightLeft();
}

void AAGShipPlayerCharacter::SetRotationToSkeletalMeshInMovingRightLeft()
{
	FRotator RotationMesh = SkeletalMesh->GetRelativeRotation();
	RotationMesh.Pitch = RotationDegreesCounter;
	SkeletalMesh->SetRelativeRotation(RotationMesh);
}
