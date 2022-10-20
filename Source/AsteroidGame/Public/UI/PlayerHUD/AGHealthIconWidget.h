// Confused Game. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AGHealthIconWidget.generated.h"


class UImage;

UCLASS()
class ASTEROIDGAME_API UAGHealthIconWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	void SetVisibilityToHealthStatus(bool bTakeDamage);

	bool GetVisibleHealth() const { return bHealed; }
protected:
	UPROPERTY(meta = (BindWidget))
		UImage* HealthFull;
	UPROPERTY(meta = (BindWidget))
		UImage* HealthEmpty;

	virtual void NativeOnInitialized() override;

private:
	bool bHealed = true;
};
