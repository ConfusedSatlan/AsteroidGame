// Confused Game. All Rights Reserved


#include "UI/PlayerHUD/AGPauseWidget.h"
#include "Components/Button.h"
#include "GameFramework/GameModeBase.h"


void UAGPauseWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (ContinueGameButton)
	{
		ContinueGameButton->OnClicked.AddDynamic(this, &UAGPauseWidget::OnContinueGamePressed);
	}
}

void UAGPauseWidget::OnContinueGamePressed()
{
	if (!GetWorld()) return;

	GetWorld()->GetAuthGameMode()->ClearPause();
}