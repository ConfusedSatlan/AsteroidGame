// Confused Game. All Rights Reserved


#include "UI/PlayerHUD/AGGameOverWidget.h"
#include "Components/Button.h"
#include "AGGameInstance.h"
#include "Kismet/GameplayStatics.h"


void UAGGameOverWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (RestartGameButton)
	{
		RestartGameButton->OnClicked.AddDynamic(this, &UAGGameOverWidget::OnRestartGamePressed);
	}
}

void UAGGameOverWidget::OnRestartGamePressed()
{
	if(!GetWorld()) return;

	const auto GameInstance = GetWorld()->GetGameInstance<UAGGameInstance>();
	if (GameInstance)
	{
		UGameplayStatics::OpenLevel(this, GameInstance->GetMainLevelName());
	}
}