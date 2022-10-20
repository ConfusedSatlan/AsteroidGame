// Confused Game. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AGCoreTypes.h"
#include "AGPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ASTEROIDGAME_API AAGPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AAGPlayerController();

protected:
	virtual void SetupInputComponent() override;
	virtual void BeginPlay() override;

private:

	void OnPauseGame();
	void OnMatchStateChanged(EAGMatchState State);
};
