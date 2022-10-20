// Confused Game. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "AGShipFloatingPawnMovement.generated.h"

/**
 * 
 */
UCLASS()
class ASTEROIDGAME_API UAGShipFloatingPawnMovement : public UFloatingPawnMovement
{
	GENERATED_BODY()
	
public:
	UAGShipFloatingPawnMovement(const FObjectInitializer& ObjectInitializer);
};
