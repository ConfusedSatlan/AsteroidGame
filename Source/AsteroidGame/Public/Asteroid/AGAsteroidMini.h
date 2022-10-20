// Confused Game. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Asteroid/AGAsteroidActor.h"
#include "AGAsteroidMini.generated.h"

/**
 * 
 */
UCLASS()
class ASTEROIDGAME_API AAGAsteroidMini : public AAGAsteroidActor
{
	GENERATED_BODY()
	
public:
	AAGAsteroidMini(const FObjectInitializer& ObjInit);
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	//virtual void OnHit(UPrimitiveComponent* HitComponent, //
	//		AActor* OtherActor, //
	//		UPrimitiveComponent* OtherComp, //
	//		FVector NormalImpulse, //
	//		const FHitResult& Hit) override;
};
