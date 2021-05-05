// Fill out your copyright notice in the Description page of Project Settings.


#include "TrackBoundaryActor.h"

// Sets default values
ATrackBoundaryActor::ATrackBoundaryActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Setup spline component
	boundary = CreateDefaultSubobject<USplineComponent>(TEXT("FollowCamera"));
	boundary->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ATrackBoundaryActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATrackBoundaryActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

