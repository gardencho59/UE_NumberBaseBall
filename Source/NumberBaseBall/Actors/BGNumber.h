#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BGNumber.generated.h"

UCLASS()
class NUMBERBASEBALL_API ABGNumber : public AActor
{
	GENERATED_BODY()

public:
	ABGNumber();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Scene Root")
	USceneComponent* Root;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "StaticMeh Component")
	UStaticMeshComponent* StaticMesh;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	void SetNumber(TCHAR Character);

	UPROPERTY(EditDefaultsOnly, Category="Number")
	TArray<UStaticMesh*> NumberMeshes;

	UFUNCTION(NetMulticast, Reliable)
	void MulticastSetNumber(int32 Index);
};
