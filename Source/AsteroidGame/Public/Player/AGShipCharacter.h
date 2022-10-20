// Confused Game. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "AGShipCharacter.generated.h"


class UBoxComponent;
class USkeletalMeshComponent;
class UArrowComponent;
class UAGShipFloatingPawnMovement;
class UAGShipHealthComponent;
class UAGShipDefenceComponent;
class UNiagaraSystem;
class UNiagaraComponent;

UCLASS()
class ASTEROIDGAME_API AAGShipCharacter : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAGShipCharacter(const FObjectInitializer& ObjInit);

	USkeletalMeshComponent* GetSkeletalMeshComponent() const { return SkeletalMesh; }
	UBoxComponent* GetBoxComponent() const { return CollisionBox; }
	FVector GetMuzzleFXEngineLocation() { return SkeletalMesh->GetSocketLocation(MuzzleEngineSocketName); }

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Component")
		UBoxComponent* CollisionBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Component")
		USkeletalMeshComponent* SkeletalMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "VFX")
		USkeletalMeshComponent* ShieldMeshEffect;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Component")
		UAGShipFloatingPawnMovement* PawnMovement;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Component")
		UAGShipHealthComponent* HealthComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Component")
		UAGShipDefenceComponent* WeaponComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX")
		FName MuzzleEngineSocketName = "ShipEngineSocket";

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX")
		UNiagaraSystem* MuzzleFXEngine;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX")
		FString FXEngineTargetName = "MuzzleLocation";

	virtual void OnDeath();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UNiagaraComponent* SpawnMuzzleFXEngine(FName EngineFXSocketName);
	UPROPERTY()
		TArray<UNiagaraComponent*> EngineComponents;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	void InitEngineFX();

	FTimerHandle ShieldEffectTimerHandle;
	void OnImmortalShield(float ShieldTimeDuraction);
	void OffShieldEffect();
};
