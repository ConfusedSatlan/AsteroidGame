// Confused Game. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "AGCheckActorDecorator.generated.h"

/**
 * 
 */
UCLASS()
class ASTEROIDGAME_API UAGCheckActorDecorator : public UBTDecorator
{
	GENERATED_BODY()
	
public:
	UAGCheckActorDecorator();
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
		FBlackboardKeySelector EnemyKeySelector;

	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};
