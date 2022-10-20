// Confused Game. All Rights Reserved


#include "PickUp/AGPickUpHealth.h"
#include "Components/AGShipHealthComponent.h"
#include "AGUtils.h"

bool AAGPickUpHealth::GivePickupTo(APawn* PlayerPawn)
{
	const auto HealthComponent = AGUtils::GetAGPlayerComponent<UAGShipHealthComponent>(PlayerPawn);
	if (!HealthComponent) return false;

	return HealthComponent->TryToHeal(HealAmount);;
}