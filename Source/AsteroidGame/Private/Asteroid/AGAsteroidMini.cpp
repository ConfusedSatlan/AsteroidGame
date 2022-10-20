// Confused Game. All Rights Reserved


#include "Asteroid/AGAsteroidMini.h"


AAGAsteroidMini::AAGAsteroidMini(const FObjectInitializer& ObjInit) : Super(ObjInit)
{
	PrimaryActorTick.bCanEverTick = true;
}


void AAGAsteroidMini::BeginPlay()
{
	Super::BeginPlay();

}

void AAGAsteroidMini::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}