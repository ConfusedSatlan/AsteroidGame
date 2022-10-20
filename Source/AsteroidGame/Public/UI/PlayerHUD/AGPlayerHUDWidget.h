// Confused Game. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AGPlayerHUDWidget.generated.h"


class UTextBlock;
class UHorizontalBox;
class UAGHealthIconWidget;

UCLASS()
class ASTEROIDGAME_API UAGPlayerHUDWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(meta = (BindWidget))
		UTextBlock* KillsCountText;

	UPROPERTY(meta = (BindWidget))
		UHorizontalBox* HorizontalBoxHealthItems;

	UPROPERTY(meta = (BindWidget))
		UHorizontalBox* HorizontalBoxBoostsItems;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
		TSubclassOf<UUserWidget> HealthIconClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
		TSubclassOf<UUserWidget> ShieldIconClass;

	UFUNCTION(BlueprintCallable, Category = "UI")
		int32 GetWeaponData() const;

	UFUNCTION(BlueprintCallable, Category = "UI")
		int32 GetKillsCountAsteroids() const;

	virtual void NativeOnInitialized() override;

private:
	UPROPERTY()
		TArray<UAGHealthIconWidget*> HealthIcons;
	UPROPERTY()
		TArray<UUserWidget*> BoostsIcons;
	int32 SizeHealth;
	
	void OnHealthChanged(float Health);
	void OnImmortalShield(float SecondsAmount);
	void InitHealthIcons();
	void InitBoostsIcons();
};
