// Confused Game. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AGAIController.generated.h"


class UAGAIPerceptionComponent;

UCLASS()
class ASTEROIDGAME_API AAGAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	AAGAIController();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
		UAGAIPerceptionComponent* AGAIPerceptionComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
		FName FocusOnKeyName = "EnemyActor";

	virtual void OnPossess(APawn* InPawn) override;
	virtual void Tick(float DeltaTime) override;

private:
	AActor* GetFocusOnActor() const;
};
