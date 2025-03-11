// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerController/PlatformerPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "Actor/Pawn/PlayerBall.h"

APlatformerPlayerController::APlatformerPlayerController()
{
	
}

void APlatformerPlayerController::BeginPlay()
{
	Super::BeginPlay();
	PlayerBall=Cast<APlayerBall>(GetPawn());
	Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem)
	{
		Subsystem->AddMappingContext(InputMappingContext,0);
		UE_LOG(LogTemp, Warning, TEXT("subsystem loaded"));
	}
}



void APlatformerPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	
}
