// Confused Game. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AGAsteroidActor.generated.h"


class UBoxComponent;
class UStaticMeshComponent;
class UProjectileMovementComponent;

UCLASS()
class ASTEROIDGAME_API AAGAsteroidActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAGAsteroidActor(const FObjectInitializer& ObjInit);

	void SetVelocityVector(FVector& PlayerLocation);

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "CollisionDamage")
		float DamageHit = 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Component")
		UBoxComponent* CollisionBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Component")
		UStaticMeshComponent* StaticMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Component")
		UProjectileMovementComponent* MovementComponent;

	UFUNCTION()
		virtual void OnTakeAnyDamageHandle(AActor* DamagedActor, 
			float Damage, 
			const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	float MaxDistanceBetweenPlayer = 6310.0f;
	float SphereDistanceAroundPlayer = 6305.0f;
	void Killed(AController* KillerActor, AActor* KilledActor);

	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			FVector NormalImpulse,
			const FHitResult& Hit);
};
