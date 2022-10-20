// Confused Game. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "ShipWeapon/AGBaseWeapon.h"
#include "AGSilverRocketWeapon.generated.h"

/**
 * 
 */
UCLASS()
class ASTEROIDGAME_API AAGSilverRocketWeapon : public AAGBaseWeapon
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
		float DamageHit = 1.0f;

	virtual void BeginPlay() override;
	virtual void OnProjectileHit(UPrimitiveComponent* HitComponent,
			AActor* OtherActor, UPrimitiveComponent* OtherComp,
			FVector NormalImpulse, const FHitResult& Hit) override;
};