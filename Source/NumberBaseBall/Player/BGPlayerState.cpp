// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/BGPlayerState.h"
#include "Player/BGPlayerController.h"
#include "Net/UnrealNetwork.h"



ABGPlayerState::ABGPlayerState()
	: PlayerNameString(TEXT("None"))
	, CurrentGuessCount(0)
	, MaxGuessCount(3)
	, TurnTime(30.0f)
{
	bReplicates = true;
}


void ABGPlayerState::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ThisClass, PlayerNameString);
	DOREPLIFETIME(ThisClass, CurrentGuessCount);
	DOREPLIFETIME(ThisClass, MaxGuessCount);
}


FString ABGPlayerState::GetPlayerInfoString()
{
	FString PlayerInfoString = PlayerNameString + TEXT("(") + FString::FromInt(CurrentGuessCount) + TEXT("/") + FString::FromInt(MaxGuessCount) + TEXT(")");
	return PlayerInfoString;
}

void ABGPlayerState::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(
		UpdateTimerHandle,
		this,
		&ABGPlayerState::UpdateTurnTimer,
		0.1f,
		true
	);

	StartTurnTime();
}

void ABGPlayerState::UpdateTurnTimer()
{
	float RemainingTime = GetWorldTimerManager().GetTimerRemaining(TurnTimerHandle);
	ABGPlayerController* BGPC = Cast<ABGPlayerController>(GetOwner());
	if (BGPC)
	{
		BGPC->ClientRPCUpdateRemainingTime(RemainingTime);
	}
}

void ABGPlayerState::StartTurnTime()
{
	GetWorldTimerManager().SetTimer(
		TurnTimerHandle,
		this,
		&ABGPlayerState::OnTurnTimeout,
		TurnTime,
		false
	);
}

void ABGPlayerState::OnTurnTimeout()
{
	CurrentGuessCount++;
	if (CurrentGuessCount <= MaxGuessCount)
	{
		StartTurnTime();
	}
}

void ABGPlayerState::ClearTurnTimerHandle()
{
	GetWorldTimerManager().ClearTimer(TurnTimerHandle);
}
