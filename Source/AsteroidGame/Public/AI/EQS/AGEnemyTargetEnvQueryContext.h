// Confused Game. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryContext.h"
#include "AGEnemyTargetEnvQueryContext.generated.h"

/**
 * 
 */
UCLASS()
class ASTEROIDGAME_API UAGEnemyTargetEnvQueryContext : public UEnvQueryContext
{
	GENERATED_BODY()
public:
	UAGEnemyTargetEnvQueryContext();

	virtual void ProvideContext(FEnvQueryInstance& QueryInstance, FEnvQueryContextData& ContextData) const override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
		FName EnemyActorKeyName = "EnemyActor";
};
