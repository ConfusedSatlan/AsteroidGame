// Confused Game. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "AGHealthNeedBTDecorator.generated.h"

/**
 * 
 */
UCLASS()
class ASTEROIDGAME_API UAGHealthNeedBTDecorator : public UBTDecorator
{
	GENERATED_BODY()
	
public:
	UAGHealthNeedBTDecorator();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
		float HealthPercent = 2.0f;

	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};
