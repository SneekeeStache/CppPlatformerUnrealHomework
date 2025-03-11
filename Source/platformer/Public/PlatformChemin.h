// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlatformChemin.generated.h"

UCLASS()
class PLATFORMER_API APlatformChemin : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlatformChemin();
	UPROPERTY(EditAnywhere,Category="Components")
	UStaticMeshComponent* PlatformMesh;
	UPROPERTY(EditAnywhere,Category="Parameters")
	FVector PlatformDirection;
	UPROPERTY()
	FVector startingLocation;

	UPROPERTY(EditAnywhere,Category="Parameters")
	float speed;

	bool movingToTarget=true;

	FVector CurrentLocation;
	UPROPERTY(EditAnywhere,Category="parameters")
	float treshold=5;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
