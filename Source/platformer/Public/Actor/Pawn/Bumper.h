// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bumper.generated.h"

UCLASS()
class PLATFORMER_API ABumper : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABumper();
	UPROPERTY(EditAnywhere,Category="components")
	UStaticMeshComponent* BumperMesh;
	UFUNCTION()
	void onHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(EditAnywhere,Category="parameters")
	float ForceBumper=5000.f;
	UPROPERTY(EditAnywhere,Category="parameters")
	float ZMultiplier=5.f;

	UPROPERTY(EditAnywhere,Category="parameters")
	float dureeTimerInactivePlayerVelocityOn=0.5f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
