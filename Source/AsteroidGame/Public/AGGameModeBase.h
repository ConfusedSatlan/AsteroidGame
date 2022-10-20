// Confused Game. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AGCoreTypes.h"
#include "AGGameModeBase.generated.h"


class AAGPickUpItem;

UCLASS()
class ASTEROIDGAME_API AAGGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	AAGGameModeBase();

	FOnMatchStateChangedSignature OnMatchStateChanged;

	virtual void StartPlay() override;

	void Killed(AController* KillerActor, AActor* KilledActor);

	virtual bool SetPause(APlayerController* PC, FCanUnpause CanUnpauseDelegate = FCanUnpause()) override;
	virtual bool ClearPause() override;

	void GameOver();
protected:
	UPROPERTY(EditDefaultsOnly, Category = "Game")
		int32 CountAsteroids = 20;

	UPROPERTY(EditDefaultsOnly, Category = "SpawnSettings")
		TArray<FAsteroidType> AsteroidsType;

	UPROPERTY(EditDefaultsOnly, Category = "SpawnSettings")
		TArray<TSubclassOf<AAGPickUpItem>> PickUpItems;

	UPROPERTY(EditDefaultsOnly, Category = "SpawnSettings")
		TSubclassOf<AActor> BP_PiratShip;

	UPROPERTY(EditDefaultsOnly, Category = "SpawnSettings")
		int32 CountsPiratShips = 3;

	/*UPROPERTY(EditDefaultsOnly, Category = "SpawnSettings")
		*/


private:
	int32 CountKills = 0;
	int32 CountWaves = 0;

	EAGMatchState MatchState = EAGMatchState::WaitingToStart;
	void SetMatchState(EAGMatchState State);

	float MaxDistanceSpawnAsteroids = 4000.0f;
	float MinDistanceAroundPlayer = 400.0f;

	FTimerHandle SpawnAsteroidHandle;
	int32 CounterSpawnAsteroid = 0;
	void SpawnAsteroids();
	FVector RandomPoint(FVector& PlayerLocation);
};
