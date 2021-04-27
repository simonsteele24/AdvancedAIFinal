// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomBehaviorTreeNode.h"

// Sets default values
ACustomBehaviorTreeNode::ACustomBehaviorTreeNode()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACustomBehaviorTreeNode::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACustomBehaviorTreeNode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// This function executes whenever the node is called
ACustomBehaviorTreeNode * ACustomBehaviorTreeNode::ExecuteNode() 
{
	return nullptr;
}