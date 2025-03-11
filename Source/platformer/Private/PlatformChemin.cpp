// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformChemin.h"

// Sets default values
APlatformChemin::APlatformChemin()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>("PlatformMesh");
	
}

// Called when the game starts or when spawned
void APlatformChemin::BeginPlay()
{
	Super::BeginPlay();
	startingLocation = GetActorLocation();
}

// Called every frame
void APlatformChemin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CurrentLocation=GetActorLocation();
	FVector Target= movingToTarget ? startingLocation+PlatformDirection :startingLocation;
	FVector newPosition = FMath::VInterpTo(CurrentLocation,Target,DeltaTime,speed/100.f);
	SetActorLocation(newPosition);
	if (FVector::Dist(newPosition,Target) < treshold)
	{
		movingToTarget=!movingToTarget;
	}
	
}

