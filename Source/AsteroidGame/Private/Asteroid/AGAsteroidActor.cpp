// Confused Game. All Rights Reserved


#include "Asteroid/AGAsteroidActor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Player/AGShipCharacter.h"
#include "AGGameModeBase.h"


DEFINE_LOG_CATEGORY_STATIC(LogAsteroid, All , All);

// Sets default values
AAGAsteroidActor::AAGAsteroidActor(const FObjectInitializer& ObjInit) : Super(ObjInit)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>("CollisionBox");
	SetRootComponent(CollisionBox);
	CollisionBox->SetGenerateOverlapEvents(true);
	CollisionBox->SetCollisionProfileName("BlockAll");

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	StaticMesh->SetupAttachment(CollisionBox);

	MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovement");
	MovementComponent->bShouldBounce = 1;
	MovementComponent->bBounceAngleAffectsFriction = true;
	MovementComponent->Bounciness = 1.0f;
	MovementComponent->Friction = 1.0f;
	MovementComponent->InitialSpeed = 60.0f;
	MovementComponent->ProjectileGravityScale = 0.0f;
}

// Called when the game starts or when spawned
void AAGAsteroidActor::BeginPlay()
{
	Super::BeginPlay();
	
	AActor* ComponentOwner = Cast<AActor>(this);
	if (ComponentOwner)
	{
		ComponentOwner->OnTakeAnyDamage.AddDynamic(this, &AAGAsteroidActor::OnTakeAnyDamageHandle);
		CollisionBox->OnComponentHit.AddDynamic(this, &AAGAsteroidActor::OnHit);
	}
	/*CollisionBox->OnComponentBeginOverlap.AddDynamic(this, );*/
}

// Called every frame
void AAGAsteroidActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!GetWorld() || !GetWorld()->GetFirstPlayerController()) return;
	const auto PlayerLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	const auto AsteroidLocation = GetActorLocation();
	const auto Distance = FVector::Distance(PlayerLocation, AsteroidLocation);
	if (Distance > SphereDistanceAroundPlayer-5.0f && Distance < SphereDistanceAroundPlayer)
	{
		MovementComponent->Velocity *= -1.0f;
	}
	else if (Distance >= MaxDistanceBetweenPlayer)
	{
		Destroy();
	}
}

void AAGAsteroidActor::OnHit(UPrimitiveComponent* HitComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	FVector NormalImpulse,
	const FHitResult& Hit)
{
	const auto ShipActor = Cast<AAGShipCharacter>(OtherActor);
	if(ShipActor)
	{
		UGameplayStatics::ApplyDamage(ShipActor, DamageHit, nullptr, this, nullptr);
	}
}

void AAGAsteroidActor::OnTakeAnyDamageHandle(AActor* DamagedActor, 
	float Damage, 
	const class UDamageType* DamageType, 
	class AController* InstigatedBy, 
	AActor* DamageCauser)
{
	Killed(InstigatedBy, Cast<AActor>(this));
	Destroy();
}

void AAGAsteroidActor::SetVelocityVector(FVector& PlayerLocation)
{
	const auto Oldlocation = CollisionBox->GetRelativeLocation();
	MovementComponent->Velocity.X = (Oldlocation.X > PlayerLocation.X ? -MovementComponent->InitialSpeed : MovementComponent->InitialSpeed)+ FMath::RandRange(-40.0f, 40.0f);
	MovementComponent->Velocity.Y = (Oldlocation.Y > PlayerLocation.Y ? -MovementComponent->InitialSpeed : MovementComponent->InitialSpeed)+ FMath::RandRange(-40.0f, 40.0f);
}

void AAGAsteroidActor::Killed(AController* KillerActor, AActor* KilledActor)
{
	if (!GetWorld()) return;

	const auto GameMode = Cast<AAGGameModeBase>(GetWorld()->GetAuthGameMode());
	if (!GameMode) return;

	GameMode->Killed(KillerActor, KilledActor);
}