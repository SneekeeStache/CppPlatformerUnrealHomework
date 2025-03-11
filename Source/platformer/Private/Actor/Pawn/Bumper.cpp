// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/Pawn/Bumper.h"
#include "TimerManager.h"
#include "Actor/Pawn/PlayerBall.h"

// Sets default values
ABumper::ABumper()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BumperMesh=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BumperMesh"));
	RootComponent = BumperMesh;
	BumperMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics); 
	BumperMesh->SetCollisionObjectType(ECollisionChannel::ECC_PhysicsBody); 
	BumperMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	BumperMesh->OnComponentHit.AddDynamic(this, &ABumper::onHit); 
}

void ABumper::onHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{
	FVector reverseDir = -Hit.Normal;
	FVector bumperForceAdd= reverseDir + ForceBumper;
	bumperForceAdd.Z*=ZMultiplier;
	if (OtherActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("got actor"));
		if (APlayerBall* playerBall = Cast<APlayerBall>(OtherActor))
		{
			playerBall->CharacterMesh->AddForce(bumperForceAdd);
			UE_LOG(LogTemp, Warning, TEXT("Bumper active"));
			FTimerHandle timerHandle;
			playerBall->bumped=true;
			GetWorld()->GetTimerManager().SetTimer(timerHandle,playerBall,&APlayerBall::setBumpOff,dureeTimerInactivePlayerVelocityOn);
			
		}
	}
}


// Called when the game starts or when spawned
void ABumper::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABumper::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

