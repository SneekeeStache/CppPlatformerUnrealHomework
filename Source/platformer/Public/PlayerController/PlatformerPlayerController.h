// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlatformerPlayerController.generated.h"


/**
 * 
 */
UCLASS()
class PLATFORMER_API APlatformerPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	
public:
	APlatformerPlayerController();
	virtual void SetupInputComponent() override;
	
	UPROPERTY(EditAnywhere, Category="Input")
	class UInputMappingContext* InputMappingContext;

	UPROPERTY()
	class UEnhancedInputLocalPlayerSubsystem *Subsystem;

	UPROPERTY(EditAnywhere, Category="debug")
	class APlayerBall *PlayerBall;
	
	UPROPERTY(EditAnywhere, Category="Input")
	class UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, Category="Input")
	class UInputAction* JumpAction;

	UPROPERTY()
	class UEnhancedInputComponent* EnhancedInputComponent;
};
