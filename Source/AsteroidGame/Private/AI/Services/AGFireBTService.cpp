// Confused Game. All Rights Reserved


#include "AI/Services/AGFireBTService.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Components/AGShipDefenceComponent.h"
#include "AGUtils.h"


DEFINE_LOG_CATEGORY_STATIC(LogFireService, All, All);

UAGFireBTService::UAGFireBTService()
{
	NodeName = "Fire";
}

void UAGFireBTService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	const auto Controller = OwnerComp.GetAIOwner();
	const auto OwnerPlayer = Controller->GetPawn();
	const auto Blackboard = OwnerComp.GetBlackboardComponent();
	const auto TargetFocus = Cast<AActor>(Blackboard->GetValueAsObject(EnemyActorKey.SelectedKeyName));
	if (!TargetFocus) return;

	if (Controller)
	{
		//UE_LOG(LogFireService, Display, TEXT("FireServiceWork"));
		const auto WeaponComponent = AGUtils::GetAGPlayerComponent<UAGShipDefenceComponent>(Controller->GetPawn());
		if (WeaponComponent && FVector::Distance(OwnerPlayer->GetActorLocation(), TargetFocus->GetActorLocation()) <= 2500.0f)
		{
			WeaponComponent->StartFire();
		}
	}

	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}