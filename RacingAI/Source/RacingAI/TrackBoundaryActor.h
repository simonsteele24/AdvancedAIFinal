// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SplineComponent.h"
#include "TrackBoundaryActor.generated.h"

UCLASS()
class RACINGAI_API ATrackBoundaryActor : public AActor
{
	GENERATED_BODY()

	// Spline Component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))	class USplineComponent* boundary;

public:	
	// Sets default values for this actor's properties
	ATrackBoundaryActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(Editanywhere, BlueprintReadWrite) bool bIsRightBoundary;

	class USplineComponent* getPath() { return boundary; }
};
