// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractibleComponent.generated.h"

class UInteraction;
class UInteractorComponent;

UCLASS(Blueprintable, ClassGroup = (Interactions))
class INTERACTIONSYSTEM_API UInteractibleComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractibleComponent();

private:
	UInteraction* CurrentAction;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	UPROPERTY(BlueprintReadOnly, Category = "UI")
		int currentSelection = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interactions")
		TArray<TSubclassOf<UInteraction>> AvaiableActions;
	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "UI")
		void ShowUserInterface();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "UI")
		void HideUserInterface();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interactions")
		void ChangeSelectedInteraction(int indexOffset);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interactions")
		void SelectInteraction(int interactionIndex);

	UFUNCTION(BlueprintCallable, Category = "Interactions")
		void CallInteraction(UPARAM(ref) UInteractorComponent*& caller);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "UI")//(BlueprintNativeEvent, BlueprintCallable, Category = "UI")
		void DisplayError(const FText& Message);

	UFUNCTION()
		void DestroyAction();
	
};
