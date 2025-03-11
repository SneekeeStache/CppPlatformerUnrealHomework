// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/levier.h"

#include "Gamemodes/PlatformerGameMode.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"

// Sets default values
Alevier::Alevier()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BodyMesh = CreateDefaultSubobject<UStaticMeshComponent>("BodyMesh");
	headMesh=CreateDefaultSubobject<UStaticMeshComponent>("HeadMesh");
	
	
}

// Called when the game starts or when spawned
void Alevier::BeginPlay()
{
	Super::BeginPlay();
	ConstraintHeadObject=NewObject<UPhysicsConstraintComponent>(this);
	ConstraintHeadObject->RegisterComponent();
	ConstraintHeadObject->AttachToComponent(headMesh,FAttachmentTransformRules::KeepRelativeTransform);
	ConstraintHeadObject->SetAngularSwing1Limit(ACM_Limited,ContrainteRota.X);
	ConstraintHeadObject->SetAngularSwing2Limit(ACM_Limited,ContrainteRota.Y);
	ConstraintHeadObject->SetAngularTwistLimit(ACM_Limited,ContrainteRota.Z);

	ConstraintHeadObject->SetConstrainedComponents(headMesh,NAME_None,nullptr,NAME_None);
	PlatformerGameMode= Cast<APlatformerGameMode>(GetWorld()->GetAuthGameMode());
}

// Called every frame
void Alevier::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FRotator checkRotation=headMesh->GetRelativeRotation();
	if (checkRotation.Roll >= ActivationLevier.Roll)
	{
		if (PlatformerGameMode)
		{
			PlatformerGameMode->WindStrenght=windStrenghtValue;
		}
		
	}
	else if (checkRotation.Roll <= DeactivationLevier.Roll)
	{
		if (PlatformerGameMode)
		{
			PlatformerGameMode->WindStrenght=windStrenghtValue;
			if (PlatformerGameMode)
			{
				PlatformerGameMode->WindStrenght=0;
			}
		}
	}
}

