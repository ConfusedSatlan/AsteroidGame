// Confused Game. All Rights Reserved


#include "UI/PlayerHUD/AGShieldIconWidget.h"
#include "Components/Overlay.h"
#include "Components/TextBlock.h"


DEFINE_LOG_CATEGORY_STATIC(LogShieldIcon, All, All);

void UAGShieldIconWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

}

void UAGShieldIconWidget::StartShieldBoost(float AmoundSeconds)
{
	if (!OverlayShield) return;

	UE_LOG(LogShieldIcon, Display, TEXT("Start Shield Defence"));
	OverlayShield->SetRenderOpacity(1.0f);
	SecondsDurationShield = AmoundSeconds;
	SetTimerText(SecondsDurationShield);
	GetWorld()->GetTimerManager().SetTimer(TimerDurationShield, this, &UAGShieldIconWidget::UpdateTimer, 1.0f, true);
}

void UAGShieldIconWidget::UpdateTimer()
{
	if (FMath::IsNearlyZero(SecondsDurationShield))
	{
		GetWorld()->GetTimerManager().ClearTimer(TimerDurationShield);
		SetTimerText(SecondsDurationShield);
		OverlayShield->SetRenderOpacity(0.0f);
	}
	--SecondsDurationShield;
	SetTimerText(SecondsDurationShield);
}

void UAGShieldIconWidget::SetTimerText(float SecondsAmount)
{
	TimerShieldText->SetText(FText::FromString(FString::SanitizeFloat(SecondsDurationShield)));
}