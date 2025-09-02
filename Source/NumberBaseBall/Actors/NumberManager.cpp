#include "NumberManager.h"
#include "Number.h"

UNumberManager* UNumberManager::SingletonInstance = nullptr;

UNumberManager* UNumberManager::Get()
{
	if (!SingletonInstance)
	{
		SingletonInstance = NewObject<UNumberManager>();
		SingletonInstance->AddToRoot();
	}
	return SingletonInstance;
}

void UNumberManager::SpawnNumber(UObject* WorldContextObject, FString Number, FVector Location)
{
	if (!NumberActorClass || !WorldContextObject)
	{
		return;
	}

	UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject);

	if (!World)
	{
		return;
	}

	for (TCHAR Character : Number)
	{
		ANumber* SpawnedNumber = World->SpawnActor<ANumber>(NumberActorClass, Location, FRotator::ZeroRotator);
		if (SpawnedNumber)
		{
			
		}	
	}

}
