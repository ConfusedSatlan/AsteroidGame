// Confused Game. All Rights Reserved


#include "AI/Decorators/AGHealthNeedBTDecorator.h"
#include "AIController.h"
#include "Components/AGShipHealthComponent.h"
#include "AGUtils.h"


UAGHealthNeedBTDecorator::UAGHealthNeedBTDecorator()
{
	NodeName = "Health Need";
}

bool UAGHealthNeedBTDecorator::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	const auto Controller = OwnerComp.GetAIOwner();
	if (!Controller) return false;

	const auto HealthComponent = AGUtils::GetAGPlayerComponent<UAGShipHealthComponent>(Controller->GetPawn());
	if (!HealthComponent || HealthComponent->IsDead()) return false;

	return HealthComponent->GetHealth() <= HealthPercent;
}