// Confused Game. All Rights Reserved


#include "AI/Tasks/AGMoveToEnemyTask.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"


UAGMoveToEnemyTask::UAGMoveToEnemyTask()
{
	NodeName = "Move To Target";
}

EBTNodeResult::Type UAGMoveToEnemyTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	const auto Controller = OwnerComp.GetAIOwner();
	const auto Blackboard = OwnerComp.GetBlackboardComponent();
	if (!Controller || !Blackboard) return EBTNodeResult::Failed;

	const auto Pawn = Controller->GetPawn();
	if (!Pawn) return EBTNodeResult::Failed;

	Pawn->AddMovementInput(Pawn->GetActorForwardVector(), 1);
	return EBTNodeResult::Succeeded;
}