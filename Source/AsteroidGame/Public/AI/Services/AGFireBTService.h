// Confused Game. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "AGFireBTService.generated.h"

/**
 * 
 */
UCLASS()
class ASTEROIDGAME_API UAGFireBTService : public UBTService
{
	GENERATED_BODY()

public:
	UAGFireBTService();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
		FBlackboardKeySelector EnemyActorKey;

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
