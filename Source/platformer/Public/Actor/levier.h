// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "levier.generated.h"

class UPhysicsConstraintComponent;

UCLASS()
class PLATFORMER_API Alevier : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Alevier();
	UPROPERTY(EditAnywhere,Category="Components")
	UStaticMeshComponent* BodyMesh;
	UPROPERTY(EditAnywhere,Category="Components")
	UStaticMeshComponent* headMesh;
	
	UPROPERTY(EditAnywhere,Category="Parametre")
	FVector ContrainteRota;

	UPhysicsConstraintComponent* ConstraintHeadObject;
	class APlatformerGameMode* PlatformerGameMode;
	
	UPROPERTY(EditAnywhere,Category="Parametre")
	FRotator ActivationLevier;
	UPROPERTY(EditAnywhere,Category="Parametre")
	FRotator DeactivationLevier;

	UPROPERTY(EditAnywhere,Category="Parametre")
	float windStrenghtValue;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	
};
