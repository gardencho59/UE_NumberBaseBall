#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "NumberManager.generated.h"

UCLASS()
class NUMBERBASEBALL_API UNumberManager : public UObject
{
	GENERATED_BODY()

public:
	UNumberManager();
	
	UFUNCTION(BlueprintCallable, Category = "NumberManager")
	static UNumberManager* Get();

	UFUNCTION(BlueprintCallable, Category = "NumberManager", meta = (WorldContext = "WorldContextObject"))
	void SpawnNumber(UObject* WorldContextObject, FString Number, FVector Location);

private:
	static UNumberManager* SingletonInstance;
	
public:
	UPROPERTY(EditDefaultsOnly, Category = "NumberManager")
	TSubclassOf<class ANumber> NumberActorClass;

};
