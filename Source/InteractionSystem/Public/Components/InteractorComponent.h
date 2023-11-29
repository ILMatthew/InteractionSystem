// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractorComponent.generated.h"

class UInteractibleComponent;
class UInteraction;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInteractionConfirmed, TSubclassOf<UInteraction>, Action);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPreInteractionComplited);

UCLASS(Blueprintable, ClassGroup = (Custom))
class INTERACTIONSYSTEM_API UInteractorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UInteractorComponent();

private:


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, Category = "Interactions")
		UInteractibleComponent* FocusedInteractible;

public:
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
		FOnInteractionConfirmed OnInteractionConfirmed;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
		FOnPreInteractionComplited OnPreInteractionComplited;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Interactions")
		void CallInteraction();

	UFUNCTION(BlueprintCallable, Category = "Interactions")
		void ChangeInteraction(int Index, bool IsOffest);

	UFUNCTION(BlueprintCallable, Category = "Interactions")
		void InteractionGoAhead(TSubclassOf<UInteraction> Action);

	UFUNCTION(BlueprintCallable, Category = "Interactions")
		void InteractionCallback() { OnPreInteractionComplited.Broadcast(); }
		
};
