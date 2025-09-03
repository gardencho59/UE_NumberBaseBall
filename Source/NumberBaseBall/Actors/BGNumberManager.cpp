#include "BGNumberManager.h"
#include "BGNumber.h"

UBGNumberManager* UBGNumberManager::SingletonInstance = nullptr;

UBGNumberManager::UBGNumberManager()
{
	static ConstructorHelpers::FClassFinder<ABGNumber> NumberBPClass(TEXT("/Game/Actors/BP_Number"));
	if (NumberBPClass.Succeeded())
	{
		NumberActorClass = NumberBPClass.Class;
	}
}

UBGNumberManager* UBGNumberManager::Get()
{
	if (!SingletonInstance)
	{
		SingletonInstance = NewObject<UBGNumberManager>();
		SingletonInstance->AddToRoot();
	}
	return SingletonInstance;
}

void UBGNumberManager::SpawnNumber(UObject* WorldContextObject, FString Number, FVector Location)
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
		
		ABGNumber* SpawnedNumber = World->SpawnActor<ABGNumber>(NumberActorClass, SpawnLocation, FRotator(-90, 0, 0));
		if (SpawnedNumber)
		{
			SpawnedNumber->SetNumber(Character);
		}	
		SpawnLocation.Y -= OffsetX;
	}

}
