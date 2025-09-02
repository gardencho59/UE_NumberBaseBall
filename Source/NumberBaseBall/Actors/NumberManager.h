#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "NumberManager.generated.h"

UCLASS()
class NUMBERBASEBALL_API UNumberManager : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "NumberManager")
	static UNumberManager* Get();

	UFUNCTION(BlueprintCallable, Category = "NumberManager")
	void SpawnNumber(UObject* WorldContextObject, FString Number, FVector Location);

private:
	static UNumberManager* SingletonInstance;
	
public:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class ANumber> NumberActorClass;
};
