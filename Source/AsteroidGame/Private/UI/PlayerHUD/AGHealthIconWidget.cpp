// Confused Game. All Rights Reserved


#include "UI/PlayerHUD/AGHealthIconWidget.h"
#include "Components/Image.h"


DEFINE_LOG_CATEGORY_STATIC(LogHealthIcon, All, All);

void UAGHealthIconWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	
}

void UAGHealthIconWidget::SetVisibilityToHealthStatus(bool bTakeDamage)
{
	if(bTakeDamage)
	{
		if (!HealthFull || !HealthEmpty || !bHealed) return
		HealthFull->SetOpacity(0.0f);
		HealthFull->SetColorAndOpacity(FLinearColor(0.0f, 0.0f, 0.0f, 0.0f));
		bHealed = false;
		UE_LOG(LogHealthIcon, Error, TEXT("TakeDamage Health Icon"));
	}
	else
	{
		if (!HealthEmpty || !HealthFull || bHealed) return;
		HealthFull->SetColorAndOpacity(FLinearColor(0.0f, 0.0f, 0.0f, 1.0f));
		bHealed = true;
		UE_LOG(LogHealthIcon, Error, TEXT("Heal Player Health Icon"));
	}
}