// Confused Game. All Rights Reserved


#include "ShipWeapon/AGBaseWeapon.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Asteroid/AGAsteroidActor.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"


// Sets default values
AAGBaseWeapon::AAGBaseWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CollisionRocket = CreateDefaultSubobject<UBoxComponent>("BoxCollision");
	CollisionRocket->SetupAttachment(RootComponent);
	CollisionRocket->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	CollisionRocket->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	CollisionRocket->bReturnMaterialOnMove = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	StaticMesh->SetupAttachment(CollisionRocket);
	StaticMesh->SetCollisionProfileName("NoCollision");

	MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovement");
	MovementComponent->InitialSpeed = 1000.0f;
	MovementComponent->ProjectileGravityScale = 0.0f;

	TraceFX = CreateDefaultSubobject<UNiagaraComponent>("NiagaraComponent");
	TraceFX->SetupAttachment(CollisionRocket);

}

void AAGBaseWeapon::BeginPlay()
{
	Super::BeginPlay();

	check(MovementComponent);

	/*CollisionRocket->OnComponentHit.AddDynamic(this, &AAGBaseWeapon::OnProjectileHit);*/

	SetLifeSpan(LifeTime);
}

void AAGBaseWeapon::OnProjectileHit(UPrimitiveComponent* HitComponent,
	AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{
	StaticMesh->SetVisibility(false);
	CollisionRocket->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	SetLifeSpan(TimeDestroyEffect);
}
	
AController* AAGBaseWeapon::GetController() const
{
	const auto Pawn = Cast<APawn>(GetOwner());
	return Pawn ? Pawn->GetController() : nullptr;
}