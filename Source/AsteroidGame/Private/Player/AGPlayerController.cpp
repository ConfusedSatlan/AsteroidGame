// Confused Game. All Rights Reserved


#include "Player/AGPlayerController.h"
#include "AGGameModeBase.h"


AAGPlayerController::AAGPlayerController()
{

}

void AAGPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (GetWorld())
	{
		const auto GameMode = Cast<AAGGameModeBase>(GetWorld()->GetAuthGameMode());
		if (!GameMode) return;

		GameMode->OnMatchStateChanged.AddUObject(this, &AAGPlayerController::OnMatchStateChanged);
	}
}

void AAGPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (!InputComponent) return;

	InputComponent->BindAction("PauseGame", IE_Pressed, this, &AAGPlayerController::OnPauseGame);
}

void AAGPlayerController::OnPauseGame()
{
	if (!GetWorld() || !GetWorld()->GetAuthGameMode()) return;

	GetWorld()->GetAuthGameMode()->SetPause(this);
}

void AAGPlayerController::OnMatchStateChanged(EAGMatchState State)
{
	if (State == EAGMatchState::InProgress)
	{
		SetInputMode(FInputModeGameOnly());
		bShowMouseCursor = false;
	}
	else
	{
		SetInputMode(FInputModeUIOnly());
		bShowMouseCursor = true;
	}
}