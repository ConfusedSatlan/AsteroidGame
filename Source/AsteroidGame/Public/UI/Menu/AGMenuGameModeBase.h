// Confused Game. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AGMenuGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class ASTEROIDGAME_API AAGMenuGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	AAGMenuGameModeBase();

	FName GetStartLevelName() const { return StartLevelName; }

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
		FName StartLevelName = "MainMap";
};
