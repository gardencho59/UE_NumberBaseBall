#include "Number.h"
#include "Components/BillboardComponent.h"

ANumber::ANumber()
{
	PrimaryActorTick.bCanEverTick = false;
	
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);
	
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(Root);
}

void ANumber::BeginPlay()
{
	Super::BeginPlay();
}

void ANumber::SetNumber(TCHAR Character)
{
	int32 Index = -1;

	if (Character >= '0' && Character <= '9')
		Index = Character - '0';
	else if (Character == 'S')
		Index = 10;
	else if (Character == 'B')
		Index = 11;
	
	if (NumberMeshes.IsValidIndex(Index))
	{
		StaticMesh->SetStaticMesh(NumberMeshes[Index]);
	}
}

void ANumber::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}