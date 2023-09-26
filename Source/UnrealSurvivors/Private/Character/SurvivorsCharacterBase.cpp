// Created by Ed Makes Games


#include "Character/SurvivorsCharacterBase.h"

// Sets default values
ASurvivorsCharacterBase::ASurvivorsCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASurvivorsCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASurvivorsCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASurvivorsCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

