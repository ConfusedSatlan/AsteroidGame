// Confused Game. All Rights Reserved


#include "UI/PlayerHUD/AGPlayerHUDWidget.h"
#include "Components/TextBlock.h"
#include "Components/HorizontalBox.h"
#include "UI/PlayerHUD/AGHealthIconWidget.h"
#include "UI/PlayerHUD/AGShieldIconWidget.h"
#include "Components/AGShipHealthComponent.h"
#include "Components/AGShipDefenceComponent.h"
#include "Player/AGPlayerState.h"
#include "AGUtils.h"



void UAGPlayerHUDWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	const auto HealthComponent = AGUtils::GetAGPlayerComponent<UAGShipHealthComponent>(GetOwningPlayerPawn());
	if (HealthComponent)
	{
		HealthComponent->OnHealthChanged.AddUObject(this, &UAGPlayerHUDWidget::OnHealthChanged);
		HealthComponent->OnImmortalShield.AddUObject(this, &UAGPlayerHUDWidget::OnImmortalShield);
		SizeHealth = HealthComponent->GetMaxHealth();
	}

	InitHealthIcons();
	InitBoostsIcons();
}

void UAGPlayerHUDWidget::OnHealthChanged(float Health)
{
	int32 StartHealth = 0;
	for (auto HealthIcon : HealthIcons)
	{
		++StartHealth;
		if (Health >= StartHealth)
		{
			if (HealthIcon->GetVisibleHealth()) continue;
			HealthIcon->SetVisibilityToHealthStatus(false);
		}
		else
		{
			if (!HealthIcon->GetVisibleHealth()) return;
			HealthIcon->SetVisibilityToHealthStatus(true);
		}
	}
}

void UAGPlayerHUDWidget::OnImmortalShield(float SecondsAmount)
{
	for (auto BoostIcon : BoostsIcons)
	{
		auto ShieldIcon = Cast<UAGShieldIconWidget>(BoostIcon);
		if (ShieldIcon)
		{
			ShieldIcon->StartShieldBoost(SecondsAmount);
			return;
		}
	}
}

void UAGPlayerHUDWidget::InitHealthIcons()
{
	if (!HorizontalBoxHealthItems) return;
	HorizontalBoxHealthItems->ClearChildren();
	for (int32 i=0; i<SizeHealth; ++i)
	{
		const auto HealthIconWidget = CreateWidget<UAGHealthIconWidget>(GetWorld(), HealthIconClass);
		if (!HealthIconWidget) continue;

		HorizontalBoxHealthItems->AddChild(HealthIconWidget);
		HealthIcons.Add(HealthIconWidget);
	}
}

void UAGPlayerHUDWidget::InitBoostsIcons()
{
	if (!HorizontalBoxBoostsItems) return;
	HorizontalBoxBoostsItems->ClearChildren();

	const auto BoostIcon = CreateWidget<UUserWidget>(GetWorld(), ShieldIconClass);
	if (BoostIcon)
	{
		HorizontalBoxBoostsItems->AddChild(BoostIcon);
		BoostsIcons.Add(BoostIcon);
	}
}

int32 UAGPlayerHUDWidget::GetWeaponData() const
{
	const auto WeaponComponent = AGUtils::GetAGPlayerComponent<UAGShipDefenceComponent>(GetOwningPlayerPawn());
	if (!WeaponComponent) return 0;

	return WeaponComponent->GetCurrentCountBullet();
}

int32 UAGPlayerHUDWidget::GetKillsCountAsteroids() const
{
	if (!GetWorld()) return 0;

	auto PlayerState = Cast<AAGPlayerState>(GetWorld()->GetFirstPlayerController()->PlayerState);
	if (!PlayerState) return 0;
	
	return PlayerState->GetKillsAsteroids();
}