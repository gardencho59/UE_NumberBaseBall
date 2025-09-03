#include "NumberManager.h"
#include "Number.h"

UNumberManager* UNumberManager::SingletonInstance = nullptr;

UNumberManager::UNumberManager()
{
	static ConstructorHelpers::FClassFinder<ANumber> NumberBPClass(TEXT("/Game/Actors/BP_Number"));
	if (NumberBPClass.Succeeded())
	{
		NumberActorClass = NumberBPClass.Class;
	}
}

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
	if (!NumberActorClass)
	{
		UE_LOG(LogTemp, Log, TEXT("!NumberActorClass"))
		return;
	}

	if (!WorldContextObject)
	{
		UE_LOG(LogTemp, Log, TEXT("!WorldContextObject"))
		return;
	}

	UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject);

	if (!World)
	{
		return;
	}
	
	FVector SpawnLocation = Location;
	float OffsetX = 50.f;    
	for (TCHAR Character : Number)
	{			
		if (!NumberActorClass) return;
		
		ANumber* SpawnedNumber = World->SpawnActor<ANumber>(NumberActorClass, SpawnLocation, FRotator(-90, 0, 0));
		if (SpawnedNumber)
		{
			SpawnedNumber->SetNumber(Character);
		}	
		SpawnLocation.Y -= OffsetX;
	}

}
