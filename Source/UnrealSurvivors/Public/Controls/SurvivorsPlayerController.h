// Created by Ed Makes Games

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SurvivorsPlayerController.generated.h"

class UInputAction;
class UInputMappingContext;
struct FInputActionValue;

/**
 * 
 */
UCLASS()
class UNREALSURVIVORS_API ASurvivorsPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ASurvivorsPlayerController();
	
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

	// Input handlers for Move action
	void OnInputStarted();
	void OnMoveTriggered();
	void OnMoveReleased();

private:
	UPROPERTY(EditAnywhere, Category = "Controls")
	TObjectPtr<UInputMappingContext> SurvivorsContext;

	UPROPERTY(EditAnywhere, Category = "Controls")
	TObjectPtr<UInputAction> MoveMouseAction;

	FVector CachedDestination;
	
};
