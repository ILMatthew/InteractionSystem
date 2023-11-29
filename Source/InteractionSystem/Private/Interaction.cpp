// Fill out your copyright notice in the Description page of Project Settings.


#include "Interaction.h"

#include "Components/InteractibleComponent.h"
#include "Components/InteractorComponent.h"

void UInteraction::CheckInteraction_Implementation(UPARAM(ref) UInteractibleComponent*& called, UPARAM(ref) UInteractorComponent*& caller)
{
	CalledObject = called;
	CallerObject = caller;

	OnInteractionFailed.AddDynamic(called, &UInteractibleComponent::DisplayError);

	if (!CalledObject || !CallerObject)
	{
		FText tempError;
		tempError.FromString("Something went wrong");
		
		OnInteractionFailed.Broadcast(tempError);
		return;
	}

	CallerObject->OnPreInteractionComplited.AddDynamic(this, &UInteraction::InteractionLogic);
	//Remember to call if interaction is successfull
	//	CallerObject->InteractionGoAhead(this->StaticClass());
}

void UInteraction::InteractionLogic_Implementation()
{
	UpdateActions();
	UnbindEvents();
	CalledObject->DestroyAction();
}

void UInteraction::UpdateActions()
{
	for (int i = 0; i != ActionsToRemove.Num(); ++i)
	{
		CalledObject->AvaiableActions.Remove(ActionsToRemove[i]);
	}

	for (int i = 0; i != ActionsToAdd.Num(); ++i)
	{
		CalledObject->AvaiableActions.AddUnique(ActionsToAdd[i]);
	}
}

void UInteraction::UnbindEvents()
{
	if(OnInteractionFailed.IsBound())
		OnInteractionFailed.Clear();
	CallerObject->OnPreInteractionComplited.Clear();
}
