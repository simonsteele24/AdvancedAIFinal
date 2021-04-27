// Fill out your copyright notice in the Description page of Project Settings.


#include "DrivingStyleSelector.h"

ACustomBehaviorTreeNode* ADrivingStyleSelector::SelectNode() 
{
	selectorObjects[0]->ExecuteNode();
	return selectorObjects[0];
}