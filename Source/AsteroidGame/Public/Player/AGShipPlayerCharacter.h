// Confused Game. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Player/AGShipCharacter.h"
#include "AGShipPlayerCharacter.generated.h"


class USpringArmComponent;
class UCameraComponent;

UCLASS()
class ASTEROIDGAME_API AAGShipPlayerCharacter : public AAGShipCharacter
{
	GENERATED_BODY()
	
public:
	AAGShipPlayerCharacter(const FObjectInitializer& ObjInit);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Component")
		USpringArmComponent* CameraSpring;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Component")
		UCameraComponent* CameraComponent;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void OnDeath() override;

	virtual void BeginPlay() override;

private:
	FTimerHandle MovingTimerHandle;
	FTimerHandle CalibrationRotationTimerHandle;
	float DegreesRotationMesh = 30.0f;
	double RotationDegreesCounter = 0.0f;

	void MoveForward(float Amount);
	void MoveRight();
	void CalibrationMesh();
	void MoveLeft();
	void TurnAround(float Amount);
	void UpdateDegreesRotation();
	void SetRotationToSkeletalMeshInMovingRightLeft();
};
