// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/Pawn/PlayerBall.h"

#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "PlayerController/PlatformerPlayerController.h"
#include "DrawDebugHelpers.h"
#include "PlatformChemin.h"
#include "Gamemodes/PlatformerGameMode.h"

// Sets default values
APlayerBall::APlayerBall()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	CharacterMesh= CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CharacterMesh"));
	CharacterMesh->SetupAttachment(RootComponent);
	CharacterMesh->SetSimulatePhysics(true);
	
	SpringArm=CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(CharacterMesh);
	SpringArm->bUsePawnControlRotation = true;
	
	
	CameraComp=CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
	CameraComp->SetupAttachment(SpringArm);

	

}

// Called when the game starts or when spawned
void APlayerBall::BeginPlay()
{
	Super::BeginPlay();
	APlatformerGameMode* gamemode=Cast<APlatformerGameMode>(GetWorld()->GetAuthGameMode());
	gamemode->windAffectedActors.Add(CharacterMesh);
	
	
}


// Called every frame
void APlayerBall::Tick(float DeltaTime)
{
	TraceEndDirection=FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z-60);
	Super::Tick(DeltaTime);
	
	
	
	if (GetWorld()->LineTraceSingleByChannel(HitResult,GetActorLocation(),TraceEndDirection,ECC_Visibility,FCollisionQueryParams::DefaultQueryParam))
	{
		nbJump=0;
		isOnGround=true;
		if (HitResult.GetActor())
		{
			if (APlatformChemin* platformMouvent = Cast<APlatformChemin>(HitResult.GetActor()))
			{
				onPlatform=true;
				if (!moving)
				{
					CharacterMesh->SetPhysicsLinearVelocity(FVector(0.f,0.f,CharacterMesh->GetPhysicsLinearVelocity().Z));
					CharacterMesh->SetPhysicsLinearVelocity(CharacterMesh->GetPhysicsLinearVelocity()+PlatformVelocity);
				}
				PlatformVelocity=platformMouvent->PlatformMesh->GetPhysicsLinearVelocity();

			}
			else
			{
				onPlatform=false;
				PlatformVelocity=FVector(0, 0, 0);
			}
		}
		
	}else
	{
		isOnGround=false;
		onPlatform=false;
		
	}
	CharacterMesh->SetPhysicsLinearVelocity(FVector(
		FMath::Clamp(CharacterMesh->GetPhysicsLinearVelocity().X,clampVelocityMin.X,clampVelocityMax.X),
		FMath::Clamp(CharacterMesh->GetPhysicsLinearVelocity().Y,clampVelocityMin.Y,clampVelocityMax.Y),
		CharacterMesh->GetPhysicsLinearVelocity().Z
			)
		);
	DrawDebugLine(GetWorld(),GetActorLocation(),TraceEndDirection,FColor::Red);
}

// Called to bind functionality to input
void APlayerBall::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	APlatformerPlayerController* PlayerController = Cast<APlatformerPlayerController>(GetController());
	if (PlayerController)
	{
		
		PlayerController->EnhancedInputComponent->BindAction(PlayerController->MoveAction, ETriggerEvent::Started, this, &APlayerBall::StartMoveBall);
		PlayerController->EnhancedInputComponent->BindAction(PlayerController->MoveAction, ETriggerEvent::Triggered, this, &APlayerBall::MoveBall);
		PlayerController->EnhancedInputComponent->BindAction(PlayerController->MoveAction, ETriggerEvent::Completed, this, &APlayerBall::StopMoveBall);
		PlayerController->EnhancedInputComponent->BindAction(PlayerController->JumpAction,ETriggerEvent::Started,this,&APlayerBall::jumpBall);
	}
}

void APlayerBall::StartMoveBall(const FInputActionValue& Value)
{
	UE_LOG(LogTemp,Log,TEXT("StartMoveBall"));
	moving=true;
}

void APlayerBall::MoveBall(const FInputActionValue& Value)
{
	UE_LOG(LogTemp,Log,TEXT("APlayerBall::MoveBall"));
	FVector2d MoveInput = Value.Get<FVector2d>();
	if (!bumped)
	{
		CharacterMesh->AddImpulse(FVector(MoveInput.Y*MovementSpeed, MoveInput.X*MovementSpeed, 0));
	}
	
}

void APlayerBall::StopMoveBall(const FInputActionValue& Value)
{
	UE_LOG(LogTemp,Log,TEXT("StopMoveBall"));
	moving=false;
}


void APlayerBall::jumpBall(const FInputActionValue& Value)
{
	if (nbJump<1)
	{
		CharacterMesh->AddImpulse(FVector(0.0f, 0.0f, JumpForce));
		++nbJump;
	}
	
}

void APlayerBall::setBumpOff()
{
	 bumped=false;
}





