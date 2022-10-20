// Confused Game. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Perception/AIPerceptionComponent.h"
#include "AGAIPerceptionComponent.generated.h"

/**
 * 
 */
UCLASS()
class ASTEROIDGAME_API UAGAIPerceptionComponent : public UAIPerceptionComponent
{
	GENERATED_BODY()
public:
	AActor* GetClosestEnemy() const;
};
