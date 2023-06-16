// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CountDown.generated.h"

UCLASS()
class WIDGETTESTINGFP_API ACountDown : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACountDown();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//How long, in seconds, it will count down
	UPROPERTY(EditAnywhere)
	int32 CountDownTime;

	UPROPERTY(EditAnywhere)
	FVector TimerPostion;

	UPROPERTY(Instanced, EditAnywhere)
	class UTextRenderComponent* CountDownText;

	void UpdateTimerDisplay();

	void AdvanceTimer();

	UFUNCTION(BlueprintNativeEvent)
	void CountDownHasFinished();
	virtual void CountDownHasFinished_Implementation();

	FTimerHandle CountDownTimerHandle;
};
