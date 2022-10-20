// Confused Game. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Asteroid/AGAsteroidActor.h"
#include "AGAsteroidLarge.generated.h"

/**
 * 
 */
UCLASS()
class ASTEROIDGAME_API AAGAsteroidLarge : public AAGAsteroidActor
{
	GENERATED_BODY()

public:
	AAGAsteroidLarge(const FObjectInitializer& ObjInit);
protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Settings")
		TSubclassOf<AAGAsteroidActor> BP_AsteroidMini;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void OnTakeAnyDamageHandle(AActor* DamagedActor,
			float Damage,
			const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser) override;
	//virtual void OnHit(UPrimitiveComponent* HitComponent, //
	//		AActor* OtherActor, //
	//		UPrimitiveComponent* OtherComp, //
	//		FVector NormalImpulse, //
	//		const FHitResult& Hit) override;
};
