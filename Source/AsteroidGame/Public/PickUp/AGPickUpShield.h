// Confused Game. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "PickUp/AGPickUpItem.h"
#include "AGPickUpShield.generated.h"

/**
 * 
 */
UCLASS()
class ASTEROIDGAME_API AAGPickUpShield : public AAGPickUpItem
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "SettingsShield")
		float TimeDirection = 5.0f;
private:
	virtual bool GivePickupTo(APawn* PlayerPawn) override;
};
