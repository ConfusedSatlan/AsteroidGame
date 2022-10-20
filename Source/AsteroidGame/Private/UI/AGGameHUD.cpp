// Confused Game. All Rights Reserved


#include "UI/AGGameHUD.h"
#include "Engine/Canvas.h"
#include "Blueprint/UserWidget.h"
#include "AGGameModeBase.h"


void AAGGameHUD::BeginPlay()
{
	Super::BeginPlay();

	GameWidgets.Add(EAGMatchState::InProgress, CreateWidget<UUserWidget>(GetWorld(), PlayerHUDWidgetClass));
	GameWidgets.Add(EAGMatchState::Pause, CreateWidget<UUserWidget>(GetWorld(), PauseWidgetClass));
	GameWidgets.Add(EAGMatchState::GameOver, CreateWidget<UUserWidget>(GetWorld(), GameOverWidgetClass));

	for (auto GameWidgetPair : GameWidgets)
	{
		const auto GameWidget = GameWidgetPair.Value;
		if (!GameWidget) continue;
		{
			GameWidget->AddToViewport();
			GameWidget->SetVisibility(ESlateVisibility::Hidden);
		}
	}

	if (GetWorld())
	{
		const auto GameMode = Cast<AAGGameModeBase>(GetWorld()->GetAuthGameMode());
		if (!GameMode) return;

		GameMode->OnMatchStateChanged.AddUObject(this, &AAGGameHUD::OnMatchStateChanged);
	}
}

void AAGGameHUD::OnMatchStateChanged(EAGMatchState State)
{
	if (CurrentWidget)
	{
		CurrentWidget->SetVisibility(ESlateVisibility::Hidden);
	}

	if (GameWidgets.Contains(State))
	{
		CurrentWidget = GameWidgets[State];
	}

	if (CurrentWidget)
	{
		CurrentWidget->SetVisibility(ESlateVisibility::Visible);
	}
}