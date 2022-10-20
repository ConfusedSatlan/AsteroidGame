// Confused Game. All Rights Reserved


#include "Components/AGAIPerceptionComponent.h"
#include "AIController.h"
#include "AGUtils.h"
#include "Perception/AISense_Sight.h"
#include "Asteroid/AGAsteroidActor.h"
#include "Kismet/GameplayStatics.h"


DEFINE_LOG_CATEGORY_STATIC(LogPerceptionComponent, All, All);

AActor* UAGAIPerceptionComponent::GetClosestEnemy() const
{
	TArray<AActor*> PercieveActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AAGAsteroidActor::StaticClass(), PercieveActors);
	const auto Controller = Cast<AAIController>(GetOwner());
	if (!Controller) return nullptr;
	const auto Player = Controller->GetPawn();
	if (!Player) return nullptr;
	//UE_LOG(LogPerceptionComponent, Display, TEXT("Vector: %f, %f, %f"), Player->GetActorLocation().X, Player->GetActorLocation().Y, Player->GetActorLocation().Z);
	for (auto PercieveActor : PercieveActors)
	{
		//UE_LOG(LogPerceptionComponent, Display, TEXT("Actor: %s"), *PercieveActor->GetName());
		if(FVector::Distance(Player->GetActorLocation(), PercieveActor->GetActorLocation()) <= 400.0f)
		{
			return Cast<AActor>(PercieveActor);
		}
	}
	return Cast<AActor>(GetWorld()->GetFirstPlayerController()->GetPawn());
}