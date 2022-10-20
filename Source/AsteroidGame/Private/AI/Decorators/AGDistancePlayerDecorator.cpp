// Confused Game. All Rights Reserved


#include "AI/Decorators/AGDistancePlayerDecorator.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UAGDistancePlayerDecorator::UAGDistancePlayerDecorator()
{
	NodeName = "DistanceTrue";
}

bool UAGDistancePlayerDecorator::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	const auto Controller = OwnerComp.GetAIOwner();
	const auto Blackboard = OwnerComp.GetBlackboardComponent();
	if (!Controller || !Blackboard) return false;

	const auto Pawn = Controller->GetPawn();
	if (!Pawn) return false;

	auto CurrentEnemyKey = Cast<AActor>(Blackboard->GetValueAsObject(EnemyKeySelector.SelectedKeyName));
	if (!CurrentEnemyKey) return false;

	if (FVector::Distance(Pawn->GetActorLocation(), CurrentEnemyKey->GetActorLocation()) <= 700.0f) return false;

	return true;
}