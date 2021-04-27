// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CustomBehaviorTreeNode.h"
#include "CustomBehaviorTree.generated.h"

UCLASS()
class RACINGAI_API ACustomBehaviorTree : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACustomBehaviorTree();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/* Private Vars */
	UPROPERTY() ACustomBehaviorTreeNode * rootObject; // Represents the root node

	/* Private Funcs */
	UFUNCTION() void InitializeTree(); // This function initializes the tree at start by spawning the root

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/* Public Vars */
	UPROPERTY(EditDefaultsOnly) TSubclassOf<ACustomBehaviorTreeNode> rootClass; // Represents the class the root node will take shape to

	/* Public Funcs */
	UFUNCTION(BlueprintCallable) void RunTree(); // This function executes the tree

	UPROPERTY(BlueprintReadWrite) AAIController* treeOwner; // Owner of this behavior tree

};
