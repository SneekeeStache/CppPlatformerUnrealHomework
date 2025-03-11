// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PlatformerGameMode.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMER_API APlatformerGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere,Category="wind")
	FVector WindDirection;
	UPROPERTY(EditAnywhere,Category="wind")
	float WindStrenght;
	UPROPERTY(EditAnywhere,Category="Debug")
	TArray<UStaticMeshComponent*> windAffectedActors;
	UPROPERTY(EditAnywhere,Category="wind")
	float ImpulseTimerDuration;
	
	FTimerHandle timerHandle;

	UFUNCTION()
	void ImpulseTimer();
};

