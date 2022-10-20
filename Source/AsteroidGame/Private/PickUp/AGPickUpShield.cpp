// Confused Game. All Rights Reserved


#include "PickUp/AGPickUpShield.h"
#include "Components/AGShipHealthComponent.h"
#include "AGUtils.h"


bool AAGPickUpShield::GivePickupTo(APawn* PlayerPawn)
{
	const auto HealthComponent = AGUtils::GetAGPlayerComponent<UAGShipHealthComponent>(PlayerPawn);
	if (!HealthComponent) return false;

	HealthComponent->TurnOnShield(TimeDirection);
	return true;
}