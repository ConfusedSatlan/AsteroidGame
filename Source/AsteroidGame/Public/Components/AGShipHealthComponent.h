// Confused Game. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AGCoreTypes.h"
#include "AGShipHealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ASTEROIDGAME_API UAGShipHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAGShipHealthComponent();

	float GetHealth() const{ return Health; }

	UFUNCTION(BlueprintCallable, Category = "Health")
		float GetMaxHealth() const { return MaxHealth; }

	UFUNCTION(BlueprintCallable)
		bool IsDead() const { return FMath::IsNearlyZero(Health); }
	FOnDeathSignature OnDeath;
	FOnHealthChangedSignature OnHealthChanged;
	FOnImmortalShieldSignature OnImmortalShield;

	bool TryToHeal(float AmountHeal);
	bool IsHealthFull() const;
	void TurnOnShield(float SecondsImmortal);

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Health", meta = (ClampMin = "0.0", ClampMax = "5.0"))
		float MaxHealth = 3.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Health")
		bool bImmortal = false;
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	FTimerHandle ImmortalTimerHandle;
	void TurnOffShield();
	float Health = 0.0f;

	UFUNCTION()
		void OnTakeAnyDamageHandle(AActor* DamagedActor, 
			float Damage, 
			const class UDamageType* DamageType, 
			class AController* InstigatedBy, 
			AActor* DamageCauser);

	void SetHealth(float NewHealth);
};
