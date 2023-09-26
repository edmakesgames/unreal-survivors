// Created by Ed Makes Games

#pragma once

#include "CoreMinimal.h"
#include "Character/SurvivorsCharacterBase.h"
#include "SurvivorsCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

/**
 * 
 */
UCLASS()
class UNREALSURVIVORS_API ASurvivorsCharacter : public ASurvivorsCharacterBase
{
	GENERATED_BODY()

public:
	ASurvivorsCharacter();

protected:

private:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	USpringArmComponent* SpringArmComponent;
	
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UCameraComponent* CameraComponent;
	
};
