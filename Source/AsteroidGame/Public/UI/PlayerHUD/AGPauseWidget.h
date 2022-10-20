// Confused Game. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AGPauseWidget.generated.h"


class UButton;

UCLASS()
class ASTEROIDGAME_API UAGPauseWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(meta = (BindWidget))
		UButton* ContinueGameButton;

	virtual void NativeOnInitialized() override;

private:
	UFUNCTION()
		void OnContinueGamePressed();
};
