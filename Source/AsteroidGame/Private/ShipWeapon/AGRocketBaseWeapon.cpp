// Confused Game. All Rights Reserved


#include "ShipWeapon/AGRocketBaseWeapon.h"
#include "ShipWeapon/AGBulletFire.h"

// Sets default values
UAGRocketBaseWeapon::UAGRocketBaseWeapon()
{


}

//// Called when the game starts or when spawned
//void AAGRocketBaseWeapon::BeginPlay()
//{
//	Super::BeginPlay();
//	
//}

void UAGRocketBaseWeapon::StartFire(const FTransform& SpawnTransform)
{
	GetWorld()->SpawnActor<AAGBulletFire>();
}