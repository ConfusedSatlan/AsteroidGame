#pragma once

#include "AGCoreTypes.generated.h"


//Health

DECLARE_MULTICAST_DELEGATE(FOnDeathSignature);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnHealthChangedSignature, float);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnImmortalShieldSignature, float);


//Weapon

class AAGBaseWeapon;

USTRUCT(BlueprintType)
struct FWeaponData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
		TSubclassOf<AAGBaseWeapon> BP_RocketWeapon;

	UPROPERTY()
		AAGBaseWeapon* WeaponBase;
};


//GameModeSettings
class AAGAsteroidActor;

USTRUCT(BlueprintType)
struct FAsteroidType
{
	GENERATED_USTRUCT_BODY()

		UPROPERTY(EditDefaultsOnly, Category = "SpawnSettings")
		TSubclassOf<AAGAsteroidActor> BP_AsteroidActor;
};

UENUM(BlueprintType)
enum class EAGMatchState : uint8
{
	WaitingToStart = 0, 
	InProgress,
	Pause,
	GameOver
};

DECLARE_MULTICAST_DELEGATE_OneParam(FOnMatchStateChangedSignature, EAGMatchState);