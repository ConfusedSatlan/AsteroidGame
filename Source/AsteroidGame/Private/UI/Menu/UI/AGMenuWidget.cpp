// Confused Game. All Rights Reserved


#include "UI/Menu/UI/AGMenuWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "UI/Menu/AGMenuGameModeBase.h"


void UAGMenuWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (StartGameButton)
	{
		StartGameButton->OnClicked.AddDynamic(this, &UAGMenuWidget::OnStartGame);
	}

	if (ExitGameButton)
	{
		ExitGameButton->OnClicked.AddDynamic(this, &UAGMenuWidget::OnQuitGame);
	}
}

void UAGMenuWidget::OnStartGame()
{
	const auto GameMode = Cast<AAGMenuGameModeBase>(GetWorld()->GetAuthGameMode());
	if (!GetWorld()) return;


	UGameplayStatics::OpenLevel(this, GameMode->GetStartLevelName());
}

void UAGMenuWidget::OnQuitGame()
{
	UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, true);
}