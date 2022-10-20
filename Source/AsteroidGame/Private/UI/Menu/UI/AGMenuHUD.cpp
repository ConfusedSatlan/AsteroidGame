// Confused Game. All Rights Reserved


#include "UI/Menu/UI/AGMenuHUD.h"
#include "Blueprint/UserWidget.h"


void AAGMenuHUD::BeginPlay()
{
	Super::BeginPlay();

	if (MenuWidgetClass)
	{
		const auto MenuWidget = CreateWidget<UUserWidget>(GetWorld(), MenuWidgetClass);
		if (MenuWidget)
		{
			MenuWidget->AddToViewport();
		}
	}
}