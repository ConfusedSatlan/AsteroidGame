// Confused Game. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "AGRocketBaseWeapon.generated.h"


class AAGBulletFire;

UCLASS()
class ASTEROIDGAME_API UAGRocketBaseWeapon : public UObject
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	UAGRocketBaseWeapon();

	void StartFire(const FTransform& SpawnTransform);

//protected:
//	// Called when the game starts or when spawned
//	virtual void BeginPlay() override;

};
