// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/InteractibleComponent.h"

#include "Interaction.h"
#include "Components/InteractorComponent.h"

// Sets default values for this component's properties
UInteractibleComponent::UInteractibleComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInteractibleComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInteractibleComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UInteractibleComponent::CallInteraction(UPARAM(ref) UInteractorComponent*& caller)
{
	CurrentAction = Cast<UInteraction>(NewObject<UObject>(this, AvaiableActions[currentSelection]));
	if (CurrentAction)
	{
		//CurrentAction->OnInteractionFailed.AddDynamic(this, &UInteractibleComponent::DisplayError);

		UInteractibleComponent* tempCalled = this;
		CurrentAction->CheckInteraction(tempCalled, caller);
	}
	currentSelection = 0;
}

void UInteractibleComponent::DestroyAction()
{
	if (CurrentAction)
	{
		CurrentAction->ConditionalBeginDestroy();
		CurrentAction = nullptr;
	}
}

void UInteractibleComponent::DisplayError_Implementation(const FText& Message)
{
	CurrentAction->UnbindEvents();
	this->DestroyAction();
}

void UInteractibleComponent::ShowUserInterface_Implementation() { }

void UInteractibleComponent::HideUserInterface_Implementation() { }

void UInteractibleComponent::ChangeSelectedInteraction_Implementation(int indexOffset)
{
	currentSelection += indexOffset;

	if (currentSelection > AvaiableActions.Num() - 1)
	{
		currentSelection = 0;
	}
	else if (currentSelection < 0)
	{
		currentSelection = AvaiableActions.Num() - 1;
	}
}

void UInteractibleComponent::SelectInteraction_Implementation(int interactionIndex)
{
	currentSelection = interactionIndex;

	if (currentSelection > AvaiableActions.Num() - 1)
	{
		currentSelection = 0;
	}
	else if (currentSelection < 0)
	{
		currentSelection = AvaiableActions.Num() - 1;
	}
}