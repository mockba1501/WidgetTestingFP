// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CustomProgressBar.generated.h"

/**
 * 
 */
UCLASS()
class WIDGETTESTINGFP_API UCustomProgressBar : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UProgressBar* HealthBar;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UProgressBar* EnergyBar;

	//Get reference of playerCharacter (Is jumping and not falling) Increment the Health value
	//Bind the progress bars with the actual variables of health and energy
};
