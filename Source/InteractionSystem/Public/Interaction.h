// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Interaction.generated.h"

class UInteractibleComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInteractionFailedSignature, const FText&, Message);

/**
 * 
 */
UCLASS(Blueprintable, ClassGroup = (Interactions))
class INTERACTIONSYSTEM_API UInteraction : public UObject
{
	GENERATED_BODY()

private:

	void UpdateActions();

protected:
	UPROPERTY(BlueprintReadOnly)
		UInteractibleComponent* CalledObject;

	UPROPERTY(BlueprintReadOnly)
		UInteractorComponent* CallerObject;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Interactions")
		FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Interactions")
		TArray<TSubclassOf<UInteraction>> ActionsToRemove;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Interactions")
		TArray<TSubclassOf<UInteraction>> ActionsToAdd;

public:
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
		FOnInteractionFailedSignature OnInteractionFailed;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interactions")
		void CheckInteraction(UPARAM(ref) UInteractibleComponent*& called, UPARAM(ref) UInteractorComponent*& caller);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interactions")
		void InteractionLogic();
	
	void UnbindEvents();
	
};
