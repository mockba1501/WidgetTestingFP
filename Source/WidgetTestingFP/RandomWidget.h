// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RandomWidget.generated.h"

/**
 * 
 */
UCLASS()
class WIDGETTESTINGFP_API URandomWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	void GenerateRandom();
	
	void NativeConstruct() override;
	
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* RandomNumberLabel;
	
	UPROPERTY(meta = (BindWidget))
		class UButton* GenerateButton;

	UFUNCTION()
		void OnGenerateButtonClicked();
};
