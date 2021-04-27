// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AIController.h"
#include "CustomBehaviorTreeNode.generated.h"

UCLASS()
class RACINGAI_API ACustomBehaviorTreeNode : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACustomBehaviorTreeNode();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/* Public Functions */
	UFUNCTION(BlueprintCallable) virtual ACustomBehaviorTreeNode * ExecuteNode(); // This function executes whenever the node is called
	UPROPERTY() AAIController* treeOwner; // Owner of this behavior tree

};
