// Confused Game. All Rights Reserved


#include "Components/AGShipFloatingPawnMovement.h"


UAGShipFloatingPawnMovement::UAGShipFloatingPawnMovement(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	MaxSpeed = 500.0f;
	Acceleration = 500.0f;
	Deceleration = 200.f;
	TurningBoost = 0.1f;
}