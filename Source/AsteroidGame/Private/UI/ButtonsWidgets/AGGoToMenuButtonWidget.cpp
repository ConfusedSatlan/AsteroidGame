// Confused Game. All Rights Reserved


#include "UI/ButtonsWidgets/AGGoToMenuButtonWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "AGGameInstance.h"


DEFINE_LOG_CATEGORY_STATIC(LogGoToMenuButton, All, All);

void UAGGoToMenuButtonWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (GoToMenuButton)
	{
		GoToMenuButton->OnClicked.AddDynamic(this, &UAGGoToMenuButtonWidget::OnClickedGoToMenu);
	}
}

void UAGGoToMenuButtonWidget::OnClickedGoToMenu()
{
	if (!GetWorld()) return;

	const auto AGGameInstance = GetWorld()->GetGameInstance<UAGGameInstance>();
	if (!AGGameInstance) return;

	if (AGGameInstance->GetMenuLevelName().IsNone())
	{
		UE_LOG(LogGoToMenuButton, Error, TEXT("Menu level is NONE"));
		return;
	}

	UGameplayStatics::OpenLevel(this, AGGameInstance->GetMenuLevelName());
}