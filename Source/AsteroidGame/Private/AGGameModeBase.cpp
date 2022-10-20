// Confused Game. All Rights Reserved


#include "AGGameModeBase.h"
#include "Player/AGShipCharacter.h"
#include "Player/AGPlayerController.h"
#include "Player/AGPlayerState.h"
#include "UI/AGGameHUD.h"
#include "Asteroid/AGAsteroidActor.h"
#include "Kismet/GameplayStatics.h"
#include "PickUp/AGPickUpItem.h"


DEFINE_LOG_CATEGORY_STATIC(LogAsteroidTemp, All, All);

AAGGameModeBase::AAGGameModeBase()
{
	DefaultPawnClass = AAGShipCharacter::StaticClass();
	PlayerControllerClass = AAGPlayerController::StaticClass();
	HUDClass = AAGGameHUD::StaticClass();
	PlayerStateClass = AAGPlayerState::StaticClass();
}

void AAGGameModeBase::StartPlay()
{
	Super::StartPlay();

	SpawnAsteroids();
	SetMatchState(EAGMatchState::InProgress);
}

void AAGGameModeBase::SpawnAsteroids()
{
	if (!GetWorld()) return;


	TArray<AActor*> Asteroids;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AAGAsteroidActor::StaticClass(), Asteroids);
	CounterSpawnAsteroid = Asteroids.Num();
	//UE_LOG(LogAsteroidTemp, Display, TEXT("CounterSpawnAsteroid first call: %d"), CounterSpawnAsteroid);
	while (CountAsteroids > CounterSpawnAsteroid)
	{
		if (!GetWorld()->GetFirstPlayerController()->GetPawn()) return;
		auto PlayerLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();

		//UE_LOG(LogAsteroidTemp, Display, TEXT("CountAsteroids call in chycil: %d"), CountAsteroids);
		FTransform SpawnTransform;
		SpawnTransform.SetLocation(RandomPoint(PlayerLocation));
		SpawnTransform.SetRotation(FQuat(FRotator::ZeroRotator));
		auto Asteroid = GetWorld()->SpawnActor<AAGAsteroidActor>(AsteroidsType[FMath::RandRange(0, AsteroidsType.Num()-1)].BP_AsteroidActor, SpawnTransform);
		if (!Asteroid) return;

		Asteroid->SetVelocityVector(PlayerLocation);
		++CounterSpawnAsteroid;
		//UE_LOG(LogAsteroidTemp, Display, TEXT("CounterSpawnAsteroid call in chycil: %d"), CounterSpawnAsteroid);
	}

	GetWorld()->GetTimerManager().SetTimer(SpawnAsteroidHandle, this, &AAGGameModeBase::SpawnAsteroids, 10.0, true);
}

FVector AAGGameModeBase::RandomPoint(FVector& PlayerLocation)
{
	auto FirstPoint = FMath::RandRange(PlayerLocation.X, PlayerLocation.X + MaxDistanceSpawnAsteroids);
	auto SecondPoint = FirstPoint - PlayerLocation.X < MinDistanceAroundPlayer ? //
		FMath::RandRange(PlayerLocation.Y + MinDistanceAroundPlayer, PlayerLocation.Y + MaxDistanceSpawnAsteroids) //
		: FMath::RandRange(PlayerLocation.Y, PlayerLocation.Y + MaxDistanceSpawnAsteroids);

	FirstPoint = FMath::RandBool() ? PlayerLocation.X - (FirstPoint - PlayerLocation.X) : FirstPoint;
	SecondPoint = FMath::RandBool() ? PlayerLocation.Y - (SecondPoint - PlayerLocation.Y) : SecondPoint;

	return FVector(FirstPoint, SecondPoint, 0);
}

void AAGGameModeBase::Killed(AController* KillerActor, AActor* KilledActor)
{
	if (!KilledActor) return;
	if (FMath::FRand() <= 0.1f)
	{
		FTransform SpawnTransform(KilledActor->GetActorRotation(), KilledActor->GetActorLocation());
		GetWorld()->SpawnActor<AAGPickUpItem>(PickUpItems[FMath::RandRange(0, PickUpItems.Num() - 1)], SpawnTransform);
	}
	if (!KillerActor) return;

	auto PlayerStateCount = Cast<AAGPlayerState>(KillerActor->PlayerState);
	if (!PlayerStateCount) return;

	PlayerStateCount->AddKillsAsteroids();
	if (!GetWorld()->GetFirstPlayerController()->GetPawn()) return;
	++CountKills;

	if(CountKills >= 10)
	{
		for(int32 i = 0; i < CountsPiratShips; ++i)
		{
			auto PlayerLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
			FTransform SpawnTransform;
			SpawnTransform.SetLocation(RandomPoint(PlayerLocation));
			SpawnTransform.SetRotation(FQuat(FRotator::ZeroRotator));

			GetWorld()->SpawnActor<AActor>(BP_PiratShip, SpawnTransform);
		}
		CountKills = 0;
		++CountWaves;
	}
}

void AAGGameModeBase::SetMatchState(EAGMatchState State)
{
	if (MatchState == State) return;

	MatchState = State;
	OnMatchStateChanged.Broadcast(MatchState);
}

void AAGGameModeBase::GameOver()
{
	SetMatchState(EAGMatchState::GameOver);
}

bool AAGGameModeBase::SetPause(APlayerController* PC, FCanUnpause CanUnpauseDelegate)
{
	const auto PauseSet = Super::SetPause(PC, CanUnpauseDelegate);

	if (PauseSet)
	{
		SetMatchState(EAGMatchState::Pause);
	}

	return PauseSet;
}

bool AAGGameModeBase::ClearPause()
{
	const auto PauseCleared = Super::ClearPause();
	if (PauseCleared)
	{
		SetMatchState(EAGMatchState::InProgress);
	}
	return PauseCleared;
}