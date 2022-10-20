// Confused Game. All Rights Reserved


#include "ShipWeapon/AGBulletFire.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Asteroid/AGAsteroidActor.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"


// Sets default values
AAGBulletFire::AAGBulletFire()
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

	MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovement");
	MovementComponent->InitialSpeed = 1000.0f;
	MovementComponent->ProjectileGravityScale = 0.0f;

	TraceFX = CreateDefaultSubobject<UNiagaraComponent>("NiagaraComponent");
	TraceFX->SetupAttachment(CollisionRocket);

}

// Called when the game starts or when spawned
void AAGBulletFire::BeginPlay()
{
	Super::BeginPlay();
	
	check(MovementComponent);

	CollisionRocket->OnComponentHit.AddDynamic(this, &AAGBulletFire::OnProjectileHit);

	SetLifeSpan(LifeTime);
}

void AAGBulletFire::OnProjectileHit(UPrimitiveComponent* HitComponent,
	AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{
	StaticMesh->SetVisibility(false);
	CollisionRocket->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	SetLifeSpan(TimeDestroyEffect);
}

