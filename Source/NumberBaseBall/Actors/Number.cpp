#include "Number.h"
#include "Components/BillboardComponent.h"

ANumber::ANumber()
{
	PrimaryActorTick.bCanEverTick = false;

	Root = CreateDefaultSubobject<USceneComponent>("Root");
	SetRootComponent(Root);
	
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(Root);
}

void ANumber::BeginPlay()
{
	Super::BeginPlay();
}

void ANumber::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

