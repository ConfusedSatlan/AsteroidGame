// Confused Game. All Rights Reserved


#include "UI/Menu/AGMenuPlayerController.h"


void AAGMenuPlayerController::BeginPlay()
{
	Super::BeginPlay();

	SetInputMode(FInputModeUIOnly());
	bShowMouseCursor = true;
}