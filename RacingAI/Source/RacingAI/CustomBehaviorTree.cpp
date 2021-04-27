// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomBehaviorTree.h"

// Sets default values
ACustomBehaviorTree::ACustomBehaviorTree()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACustomBehaviorTree::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACustomBehaviorTree::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// This function executes the tree
void ACustomBehaviorTree::RunTree() 
{
	if (rootObject != nullptr) 
	{
		rootObject->ExecuteNode();
	}
	else 
	{
		InitializeTree();
	}
}

// This function initializes the tree at start by spawning the root
void ACustomBehaviorTree::InitializeTree() 
{
	// Create default parameters for spawning
	FVector Location(0.0f, 0.0f, 0.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;

	// Spawn root
	rootObject = GetWorld()->SpawnActor<ACustomBehaviorTreeNode>(rootClass, Location, Rotation, SpawnInfo);
	rootObject->treeOwner = treeOwner;
}