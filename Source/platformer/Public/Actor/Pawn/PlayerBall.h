// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "InputActionValue.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerBall.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class PLATFORMER_API APlayerBall : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerBall();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void StartMoveBall(const FInputActionValue& Value);
	UFUNCTION()
	void MoveBall(const FInputActionValue& Value);
	UFUNCTION()
	void StopMoveBall(const FInputActionValue& Value);
	UFUNCTION()
	void jumpBall(const FInputActionValue& Value);
	UFUNCTION()
	void setBumpOff();

	UPROPERTY(EditAnywhere,Category="Components")
	UStaticMeshComponent* CharacterMesh;

	UPROPERTY(EditAnywhere,Category="Components")
	USpringArmComponent* SpringArm;
	
	UPROPERTY(EditAnywhere,Category="Components")
	UCameraComponent* CameraComp;

	UPROPERTY(EditAnywhere,Category="parameters")
	float MovementSpeed;

	UPROPERTY(EditAnywhere,Category="parameters")
	float JumpForce;

	UPROPERTY(EditAnywhere,Category="parameters")
	float alphaLerp;

	UPROPERTY(EditAnywhere,Category="parameters")
	FVector clampVelocityMin;
	UPROPERTY(EditAnywhere,Category="parameters")
	FVector clampVelocityMax;

	UPROPERTY(EditAnywhere,Category="Debug")
	bool moving=false;
	UPROPERTY(EditAnywhere,Category="Debug")
	bool bumped=false;
	UPROPERTY(EditAnywhere,Category="Debug")
	bool isOnGround;
	UPROPERTY(EditAnywhere,Category="Debug")
	bool onPlatform=false;
	UPROPERTY(EditAnywhere,Category="Debug")
	int nbJump=0;

	UPROPERTY(EditAnywhere,Category="Debug")
	FVector PlatformVelocity;

	FHitResult HitResult;
	
	
	FVector TraceEndDirection;
	

};
