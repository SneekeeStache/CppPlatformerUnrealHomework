// Fill out your copyright notice in the Description page of Project Settings.


#include "Gamemodes/PlatformerGameMode.h"

void APlatformerGameMode::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(timerHandle,this,&APlatformerGameMode::ImpulseTimer,ImpulseTimerDuration,true);
}

void APlatformerGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void APlatformerGameMode::ImpulseTimer()
{
	for (UStaticMeshComponent* ActorAffected : windAffectedActors)
	{
		ActorAffected->AddImpulse(WindDirection*WindStrenght);
	}
}

