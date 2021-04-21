// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseDecisionNode.h"
#include "BaseAction.h"

// Sets default values
ABaseDecisionNode::ABaseDecisionNode()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseDecisionNode::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseDecisionNode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// This function executes to find the next node or find that the action has been found
ABaseDecisionNode* ABaseDecisionNode::ExecuteDecision(bool& bHasFoundAction) 
{
	return nullptr;
}