// Confused Game. All Rights Reserved


#include "AI/EQS/EnvQueryTest_PickUpCouldBeTaken.h"
#include "EnvironmentQuery/Items/EnvQueryItemType_ActorBase.h"
#include "PickUp/AGPickUpItem.h"


UEnvQueryTest_PickUpCouldBeTaken::UEnvQueryTest_PickUpCouldBeTaken(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	//складність теста
	Cost = EEnvTestCost::Low;
	//з якими даними буде працювати тест
	ValidItemType = UEnvQueryItemType_ActorBase::StaticClass();
	//фільтр тайп(мин макс рендж, або матч(якщо false))
	SetWorkOnFloatValues(false);
}

void UEnvQueryTest_PickUpCouldBeTaken::RunTest(FEnvQueryInstance& QueryInstance) const
{
	const auto DataOwner = QueryInstance.Owner.Get();
	BoolValue.BindData(DataOwner, QueryInstance.QueryID);
	const auto WantsBeTakable = BoolValue.GetValue();

	//проходе по всім згенерованим сутностям
	for (FEnvQueryInstance::ItemIterator It(this, QueryInstance); It; ++It)
	{
		//get actor
		const auto ItemActor = GetItemActor(QueryInstance, It.GetIndex());
		const auto PickupActor = Cast<AAGPickUpItem>(ItemActor);
		if (!PickupActor) continue;

		const auto CouldBeTaken = PickupActor->CouldBeTaken();
		//встановлюєм значення output чи можно використати PickUpActor
		It.SetScore(TestPurpose, FilterType, CouldBeTaken, WantsBeTakable);
	}
}