// Confused Game. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AGGameOverWidget.generated.h"


class UButton;

UCLASS()
class ASTEROIDGAME_API UAGGameOverWidget : public UUserWidget
{
	GENERATED_BODY()
	

protected:
	UPROPERTY(meta = (BindWidget))
		UButton* RestartGameButton;

	virtual void NativeOnInitialized() override;

private:
	UFUNCTION()
		void OnRestartGamePressed();
};
