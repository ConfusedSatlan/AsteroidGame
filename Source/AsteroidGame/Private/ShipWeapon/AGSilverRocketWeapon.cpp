// Confused Game. All Rights Reserved


#include "ShipWeapon/AGSilverRocketWeapon.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"


void AAGSilverRocketWeapon::BeginPlay()
{
	Super::BeginPlay();
	
	GetOwnRootComponent()->OnComponentHit.AddDynamic(this, &AAGSilverRocketWeapon::OnProjectileHit);
}

void AAGSilverRocketWeapon::OnProjectileHit(UPrimitiveComponent* HitComponent,
	AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{
	UGameplayStatics::ApplyDamage(OtherActor, DamageHit, GetController(), this, nullptr);

	Super::OnProjectileHit(HitComponent, OtherActor, OtherComp, NormalImpulse, Hit);
}