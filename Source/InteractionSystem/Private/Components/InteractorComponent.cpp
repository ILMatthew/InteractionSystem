// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/InteractorComponent.h"

#include "Components/InteractibleComponent.h"

// Sets default values for this component's properties
UInteractorComponent::UInteractorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInteractorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInteractorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UInteractorComponent::CallInteraction()
{
	if (FocusedInteractible)
	{
		UInteractorComponent* temp = this;
		//FocusedInteractible->HideUserInterface();
		FocusedInteractible->CallInteraction(temp);
	}
	FocusedInteractible = nullptr;
}

void UInteractorComponent::ChangeInteraction(int Index, bool IsOffest)
{
}

void UInteractorComponent::InteractionGoAhead(TSubclassOf<UInteraction> Action)
{
	FocusedInteractible->HideUserInterface();
	OnInteractionConfirmed.Broadcast(Action);
}

