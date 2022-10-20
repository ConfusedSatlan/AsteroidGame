// Confused Game. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "AGMoveToEnemyTask.generated.h"

/**
 * 
 */
UCLASS()
class ASTEROIDGAME_API UAGMoveToEnemyTask : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UAGMoveToEnemyTask();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
		FBlackboardKeySelector EnemyKeySelector;
};
