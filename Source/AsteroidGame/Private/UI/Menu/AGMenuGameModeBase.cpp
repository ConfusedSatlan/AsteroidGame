// Confused Game. All Rights Reserved


#include "UI/Menu/AGMenuGameModeBase.h"
#include "UI/Menu/AGMenuPlayerController.h"
#include "UI/Menu/UI/AGMenuHUD.h"


AAGMenuGameModeBase::AAGMenuGameModeBase()
{
	PlayerControllerClass = AAGMenuPlayerController::StaticClass();
	HUDClass = AAGMenuHUD::StaticClass();
}