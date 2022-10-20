// Confused Game. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AGShieldIconWidget.generated.h"


class UOverlay;
class UTextBlock;

UCLASS()
class ASTEROIDGAME_API UAGShieldIconWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void StartShieldBoost(float AmoundSeconds);

protected:
	UPROPERTY(meta = (BindWidget))
		UOverlay* OverlayShield;

	UPROPERTY(meta = (BindWidget))
		UTextBlock* TimerShieldText;

	virtual void NativeOnInitialized() override;

private:
	FTimerHandle TimerDurationShield;
	void UpdateTimer();
	float SecondsDurationShield = 0;
	void SetTimerText(float SecondsAmount);
};
