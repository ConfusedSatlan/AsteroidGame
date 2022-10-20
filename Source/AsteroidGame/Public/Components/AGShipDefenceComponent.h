// Confused Game. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AGCoreTypes.h"
#include "AGShipDefenceComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ASTEROIDGAME_API UAGShipDefenceComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAGShipDefenceComponent();

	void StartFire();
	
	FVector GetFireSocketLocation() const;
	FRotator GetFireSocketRotation() const;

	int32 GetCurrentCountBullet() const { return CountBullet; }

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "WeaponSettings")
		FName MuzzleSocketName = "ShipFireSocket";

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "WeaponSettings")
		int32 CountBulletDefault = 3;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "WeaponSettings")
		FWeaponData WeaponData;

	// Called when the game starts
	virtual void BeginPlay() override;

private:
	FTimerHandle ReloadTimerHandle;
	int32 CountBullet = 0;

	void SpawnWeapon();
	bool IsEmptyBullets() const;
	bool IsAmmoFull() const;

	void UpdateReloadTimer();
};
