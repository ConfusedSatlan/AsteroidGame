// Confused Game. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "AGGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class ASTEROIDGAME_API UAGGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	FName GetMenuLevelName() const { return MenuLevelName; }
	FName GetMainLevelName() const { return MainLevelName; }

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Game")
		FName MenuLevelName = NAME_None;

	UPROPERTY(EditDefaultsOnly, Category = "Game")
		FName MainLevelName = NAME_None;
};
