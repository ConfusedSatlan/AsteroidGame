// Confused Game. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Player/AGShipCharacter.h"
#include "AGAIShipCharacter.generated.h"


class UBehaviorTree;

UCLASS()
class ASTEROIDGAME_API AAGAIShipCharacter : public AAGShipCharacter
{
	GENERATED_BODY()
	
public:
	AAGAIShipCharacter(const FObjectInitializer& ObjInit);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI")
		UBehaviorTree* BehaviorTreeAsset;

	virtual void Tick(float DeltaTime) override;
protected:
	virtual void OnDeath() override;
};
