// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseDecisionNode.h"
#include "DecisionTree.generated.h"

UCLASS()
class RACINGAI_API ADecisionTree : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADecisionTree();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/* Private Functions */
	UFUNCTION() void ConstructTree();

	/* Private Conditionals */
	UPROPERTY() bool bHasFoundAnAction = false;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/* Decision Nodes */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)	ABaseDecisionNode* rootDecision;

	/* Public Functions */
	UFUNCTION(BlueprintCallable) bool TraverseTree();

};
