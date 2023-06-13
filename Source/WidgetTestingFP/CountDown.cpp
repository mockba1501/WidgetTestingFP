// Fill out your copyright notice in the Description page of Project Settings.


#include "CountDown.h"
#include <Components/TextRenderComponent.h>

// Sets default values
ACountDown::ACountDown()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CountDownText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("CountDownNumber"));
	CountDownText->SetHorizontalAlignment(EHTA_Center);
	CountDownText->SetWorldSize(150.0f);
	CountDownText->SetRelativeRotation(FRotator(0.0f, 180.0f, 0.0f));

	//CountDownText->AddLocalTransform()
	RootComponent = CountDownText;
	RootComponent->AddRelativeLocation(FVector(2000.f, 1000.f, 300.f));
	CountDownTime = 5;
}

// Called when the game starts or when spawned
void ACountDown::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(CountDownTimerHandle, this, &ACountDown::AdvanceTimer, 1.0f, true);
}

// Called every frame
void ACountDown::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACountDown::UpdateTimerDisplay()
{
	CountDownText->SetText(FText::AsNumber(FMath::Max(CountDownTime, 0))); //FString::FromInt Not working no conversion from 
}

void ACountDown::AdvanceTimer()
{
	CountDownTime--;
	UpdateTimerDisplay();
	if (CountDownTime < 1)
	{
		//Stop running the timer
		GetWorldTimerManager().ClearTimer(CountDownTimerHandle);
		CountDownHasFinished();
	}
}

/*
void ACountDown::CountDownHasFinished()
{
	CountDownText->SetText(FText::FromString("Done Counting!!"));
}
*/
void ACountDown::CountDownHasFinished_Implementation()
{
	CountDownText->SetText(FText::FromString("Done Counting!!"));

}

