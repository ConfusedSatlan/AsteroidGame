// Confused Game. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AGBulletFire.generated.h"


class UBoxComponent;
class UStaticMeshComponent;
class UProjectileMovementComponent;
class UNiagaraComponent;

UCLASS()
class ASTEROIDGAME_API AAGBulletFire : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAGBulletFire();

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
		UBoxComponent* CollisionRocket;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
		UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
		UProjectileMovementComponent* MovementComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "FireSettings")
		float LifeTime = 3.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX")
		UNiagaraComponent* TraceFX;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
private:
	float TimeDestroyEffect = 0.6f;

	UFUNCTION()
		void OnProjectileHit(UPrimitiveComponent* HitComponent,
			AActor* OtherActor, UPrimitiveComponent* OtherComp,
			FVector NormalImpulse, const FHitResult& Hit);
};
