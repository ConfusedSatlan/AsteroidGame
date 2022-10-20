// Confused Game. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "PickUp/AGPickUpItem.h"
#include "AGPickUpHealth.generated.h"

/**
 * 
 */
UCLASS()
class ASTEROIDGAME_API AAGPickUpHealth : public AAGPickUpItem
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "SettingsShield")
		float HealAmount = 1.0f;
private:
	virtual bool GivePickupTo(APawn* PlayerPawn) override;
};
