// Confused Game. All Rights Reserved


#include "AI/AGAIShipCharacter.h"
#include "AI/AGAIController.h"


AAGAIShipCharacter::AAGAIShipCharacter(const FObjectInitializer& ObjInit) : Super(ObjInit)
{
	AutoPossessAI = EAutoPossessAI::Disabled;
	AIControllerClass = AAGAIController::StaticClass();	
}

void AAGAIShipCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	//AddMovementInput(GetActorForwardVector(), 1);
}

void AAGAIShipCharacter::OnDeath()
{
	Super::OnDeath();

	Destroy();
}