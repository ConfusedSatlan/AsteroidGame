// Confused Game. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AGMenuPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ASTEROIDGAME_API AAGMenuPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:

	virtual void BeginPlay() override;
};
