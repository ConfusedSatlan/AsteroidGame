// Confused Game. All Rights Reserved


#include "AI/AGAIController.h"
#include "AI/AGAIShipCharacter.h"
#include "Components/AGAIPerceptionComponent.h"


AAGAIController::AAGAIController()
{
	AGAIPerceptionComponent = CreateDefaultSubobject<UAGAIPerceptionComponent>("AGAIPerceptionComponent");
	SetPerceptionComponent(*AGAIPerceptionComponent);
}

void AAGAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	const auto AGCharacter = Cast<AAGAIShipCharacter>(InPawn);
	if (AGCharacter)
	{
		RunBehaviorTree(AGCharacter->BehaviorTreeAsset);
	}
}

void AAGAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const auto AimActor = AGAIPerceptionComponent->GetClosestEnemy();
	SetFocus(AimActor);
}