// Fill out your copyright notice in the Description page of Project Settings.


#include "DecisionTree.h"

// Sets default values
ADecisionTree::ADecisionTree()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADecisionTree::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ADecisionTree::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// This function creates the entire decision tree
void ADecisionTree::ConstructTree(AMyHatchbackAIController* newController)
{
	if (rootClass == nullptr) 
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Root Class Invalid!"));
		return;
	}

	FVector Location(0.0f, 0.0f, 0.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;

	controller = newController;

	rootDecision = GetWorld()->SpawnActor<ABaseDecisionNode>(rootClass,Location, Rotation, SpawnInfo);
	rootDecision->ConstructDecision();
}

// This function traverses the decision tree to get the correct action. Returns if a valid action was found
bool ADecisionTree::TraverseTree() 
{
	// Exit function if root is null
	if (rootDecision == nullptr) 
	{
		return false;
	}

	ABaseDecisionNode* currentNode = rootDecision; // Set current node to root
	bHasFoundAnAction = false; // reset action found conditional

	// Traverse tree until current node is equal to null 
	while (currentNode != nullptr) 
	{
		currentNode = currentNode->ExecuteDecision(controller, bHasFoundAnAction);
	}

	return bHasFoundAnAction; // Return if action has been found
}