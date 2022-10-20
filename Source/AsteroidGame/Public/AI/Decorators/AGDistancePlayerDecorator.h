// Confused Game. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "AGDistancePlayerDecorator.generated.h"

/**
 * 
 */
UCLASS()
class ASTEROIDGAME_API UAGDistancePlayerDecorator : public UBTDecorator
{
	GENERATED_BODY()
public:
	UAGDistancePlayerDecorator();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
		FBlackboardKeySelector EnemyKeySelector;

	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};
