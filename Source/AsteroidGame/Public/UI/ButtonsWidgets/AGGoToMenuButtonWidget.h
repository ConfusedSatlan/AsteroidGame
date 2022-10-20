// Confused Game. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AGGoToMenuButtonWidget.generated.h"


class UButton;

UCLASS()
class ASTEROIDGAME_API UAGGoToMenuButtonWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(meta = (BindWidget))
		UButton* GoToMenuButton;

	virtual void NativeOnInitialized() override;

private:
	UFUNCTION()
		void OnClickedGoToMenu();
};
