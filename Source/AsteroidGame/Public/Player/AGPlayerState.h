// Confused Game. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AGPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class ASTEROIDGAME_API AAGPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	void AddKillsAsteroids() { ++KillsNumAsteroids; }
	int32 GetKillsAsteroids() const { return KillsNumAsteroids; }
private:
	int32 KillsNumAsteroids = 0;
};
