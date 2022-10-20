// Confused Game. All Rights Reserved


#include "AI/Services/AGFindEnemyBTService.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "AGUtils.h"
#include "Components/AGAIPerceptionComponent.h"


UAGFindEnemyBTService::UAGFindEnemyBTService()
{
	NodeName = "FindEnemy";
}

void UAGFindEnemyBTService::TickNode(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory, float DeltaSeconds)
{
	const auto Blackboard = OwnerComp.GetBlackboardComponent();
	if (Blackboard)
	{
		const auto Controller = OwnerComp.GetAIOwner();
		const auto PerceptionComponent = AGUtils::GetAGPlayerComponent<UAGAIPerceptionComponent>(Controller);
		if (PerceptionComponent)
		{
			Blackboard->SetValueAsObject(EnemyActorKey.SelectedKeyName, PerceptionComponent->GetClosestEnemy());
		}
	}

	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}