// Confused Game. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "AGFindEnemyBTService.generated.h"

/**
 * 
 */
UCLASS()
class ASTEROIDGAME_API UAGFindEnemyBTService : public UBTService
{
	GENERATED_BODY()
	
public:
	UAGFindEnemyBTService();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
		FBlackboardKeySelector EnemyActorKey;

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
