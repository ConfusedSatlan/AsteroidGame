// Confused Game. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AGMenuWidget.generated.h"


class UButton;

UCLASS()
class ASTEROIDGAME_API UAGMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(meta = (BindWidget))
		UButton* StartGameButton;
	
	UPROPERTY(meta = (BindWidget))
		UButton* ExitGameButton;

	virtual void NativeOnInitialized() override;

private:
	UFUNCTION()
		void OnStartGame();

	UFUNCTION()
		void OnQuitGame();
};
