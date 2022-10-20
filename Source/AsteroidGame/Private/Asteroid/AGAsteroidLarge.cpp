// Confused Game. All Rights Reserved


#include "Asteroid/AGAsteroidLarge.h"


AAGAsteroidLarge::AAGAsteroidLarge(const FObjectInitializer& ObjInit) : Super(ObjInit)
{
	PrimaryActorTick.bCanEverTick = true;
}

void AAGAsteroidLarge::BeginPlay()
{
	Super::BeginPlay();
}

void AAGAsteroidLarge::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAGAsteroidLarge::OnTakeAnyDamageHandle(AActor* DamagedActor,
	float Damage,
	const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser)
{	
	FTransform SpawnTransform(GetActorRotation(), GetActorLocation());
	GetWorld()->SpawnActor<AAGAsteroidActor>(BP_AsteroidMini, SpawnTransform);
		
	auto SecondLocationAsteroid = SpawnTransform.GetLocation();
	SecondLocationAsteroid.X += 100.0f;
	SpawnTransform.SetLocation(SecondLocationAsteroid);
	GetWorld()->SpawnActor<AAGAsteroidActor>(BP_AsteroidMini, SpawnTransform);

	Super::OnTakeAnyDamageHandle(DamagedActor, Damage, DamageType, InstigatedBy, DamageCauser);
}