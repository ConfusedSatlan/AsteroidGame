// Confused Game. All Rights Reserved


#include "AI/Decorators/AGCheckActorDecorator.h"
#include "AIController.h"
#include "Asteroid/AGAsteroidActor.h"
#include "BehaviorTree/BlackboardComponent.h"


DEFINE_LOG_CATEGORY_STATIC(LogCheckDecorator, All, All);

UAGCheckActorDecorator::UAGCheckActorDecorator()
{
	NodeName = "Check Actor";
}

bool UAGCheckActorDecorator::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	const auto Controller = OwnerComp.GetAIOwner();
	const auto Blackboard = OwnerComp.GetBlackboardComponent();
	if (!Controller || !Blackboard) return false;

	const auto Pawn = Controller->GetPawn();
	if (!Pawn) return false;

	auto CurrentEnemyKey = Cast<AAGAsteroidActor>(Blackboard->GetValueAsObject(EnemyKeySelector.SelectedKeyName));
	if (!CurrentEnemyKey) return false;

	return true;
}