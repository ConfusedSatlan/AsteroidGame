// Confused Game. All Rights Reserved


#include "Components/AGShipDefenceComponent.h"
#include "ShipWeapon/AGBaseWeapon.h"
#include "Player/AGShipCharacter.h"
#include "Components/SkeletalMeshComponent.h"


// Sets default values for this component's properties
UAGShipDefenceComponent::UAGShipDefenceComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UAGShipDefenceComponent::BeginPlay()
{
	Super::BeginPlay();

	CountBullet = CountBulletDefault;
}

void UAGShipDefenceComponent::StartFire()
{
	if (IsEmptyBullets()) return;

	const FTransform SpawnTransform(GetFireSocketRotation(), GetFireSocketLocation());
	if (!GetWorld()) return;

	AAGBaseWeapon* Projectile = GetWorld()->SpawnActorDeferred<AAGBaseWeapon>(WeaponData.BP_RocketWeapon, SpawnTransform);
	if (Projectile)
	{
		Projectile->SetOwner(GetOwner());
		Projectile->FinishSpawning(SpawnTransform);
	}
	--CountBullet;

	GetWorld()->GetTimerManager().SetTimer(ReloadTimerHandle, this, &UAGShipDefenceComponent::UpdateReloadTimer, 3.0f, true);
}

FVector UAGShipDefenceComponent::GetFireSocketLocation() const
{
	const auto PlayerOwner = Cast<AAGShipCharacter>(GetOwner());
	return PlayerOwner->GetSkeletalMeshComponent()->GetSocketLocation(MuzzleSocketName);
}

FRotator UAGShipDefenceComponent::GetFireSocketRotation() const
{
	const auto PlayerOwner = Cast<AAGShipCharacter>(GetOwner());
	return PlayerOwner->GetSkeletalMeshComponent()->GetSocketRotation(MuzzleSocketName);
}

bool UAGShipDefenceComponent::IsEmptyBullets() const
{
	return CountBullet == 0;
}

bool UAGShipDefenceComponent::IsAmmoFull() const
{
	return CountBullet == CountBulletDefault;
}

void UAGShipDefenceComponent::UpdateReloadTimer()
{
	if (IsAmmoFull())
	{
		GetWorld()->GetTimerManager().ClearTimer(ReloadTimerHandle);
	}
	else
	{ 
		CountBullet = CountBulletDefault;
	}
}