// Fill out your copyright notice in the Description page of Project Settings.


#include "RandomWidget.h"
#include <Components/Button.h>
#include <Components/TextBlock.h>

void URandomWidget::NativeConstruct()
{
	Super::NativeConstruct();

	GenerateRandom();

	GenerateButton->OnClicked.AddUniqueDynamic(this, &URandomWidget::OnGenerateButtonClicked);
}

void URandomWidget::GenerateRandom()
{
	int32 RandomeNumber = FMath::RandRange(0, 100);

	RandomNumberLabel->SetText(FText::AsNumber(RandomeNumber));
}

void URandomWidget::OnGenerateButtonClicked()
{
	GenerateRandom();
}