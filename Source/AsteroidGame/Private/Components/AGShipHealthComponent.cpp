// Confused Game. All Rights Reserved


#include "Components/AGShipHealthComponent.h"
#include "Asteroid/AGAsteroidActor.h"


DEFINE_LOG_CATEGORY_STATIC(HealthLog, All, All);

// Sets default values for this component's properties
UAGShipHealthComponent::UAGShipHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UAGShipHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	check(MaxHealth > 0);

	SetHealth(MaxHealth);

	AActor* ComponentOwner = GetOwner();
	if (ComponentOwner)
	{
		ComponentOwner->OnTakeAnyDamage.AddDynamic(this, &UAGShipHealthComponent::OnTakeAnyDamageHandle);
	}
}

void UAGShipHealthComponent::SetHealth(float NewHealth)
{
	const auto NextHealth = FMath::Clamp(NewHealth, 0.0f, MaxHealth);
	//const auto HealthDelta = NextHealth - Health;

	Health = NextHealth;
	OnHealthChanged.Broadcast(Health);
}

void UAGShipHealthComponent::OnTakeAnyDamageHandle(AActor* DamagedActor,
	float Damage,
	const class UDamageType* DamageType,
	class AController* InstigatedBy,
	AActor* DamageCauser)
{
	if (Damage <= 0.0f || IsDead() || !GetWorld() || bImmortal) return;

	SetHealth(Health - Damage);
	UE_LOG(HealthLog, Display, TEXT("Health is: %f"), GetHealth());

	if (IsDead())
	{
		OnDeath.Broadcast();
	}

	const auto Asteroid = Cast<AAGAsteroidActor>(DamageCauser);
	if (Asteroid)
	{
		TurnOnShield(2.0f); 
	}
}

bool UAGShipHealthComponent::IsHealthFull() const
{
	return FMath::IsNearlyEqual(Health, MaxHealth);
}

bool UAGShipHealthComponent::TryToHeal(float AmountHeal)
{
	if (IsHealthFull()) return false;
	SetHealth(Health + AmountHeal);
	return true;
}

void UAGShipHealthComponent::TurnOnShield(float SecondsImmortal)
{
	if (!GetWorld()) return;

	if (!bImmortal)
	{
		bImmortal = true;
		
	}
	OnImmortalShield.Broadcast(SecondsImmortal);
	GetWorld()->GetTimerManager().SetTimer(ImmortalTimerHandle, this, &UAGShipHealthComponent::TurnOffShield, SecondsImmortal, false);
}

void UAGShipHealthComponent::TurnOffShield()
{
	bImmortal = false;
}