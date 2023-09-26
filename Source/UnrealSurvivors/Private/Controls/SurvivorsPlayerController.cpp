// Created by Ed Makes Games


#include "Controls/SurvivorsPlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"

ASurvivorsPlayerController::ASurvivorsPlayerController()
{
	bReplicates = true;
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
	CachedDestination = FVector::ZeroVector;
}

void ASurvivorsPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(SurvivorsContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(SurvivorsContext, 0);

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void ASurvivorsPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	
	EnhancedInputComponent->BindAction(MoveMouseAction, ETriggerEvent::Started, this, &ASurvivorsPlayerController::OnInputStarted);
	EnhancedInputComponent->BindAction(MoveMouseAction, ETriggerEvent::Triggered, this, &ASurvivorsPlayerController::OnMoveTriggered);
	EnhancedInputComponent->BindAction(MoveMouseAction, ETriggerEvent::Completed, this, &ASurvivorsPlayerController::OnMoveReleased);
	EnhancedInputComponent->BindAction(MoveMouseAction, ETriggerEvent::Canceled, this, &ASurvivorsPlayerController::OnMoveReleased);
}

void ASurvivorsPlayerController::OnInputStarted()
{
	StopMovement();
}

void ASurvivorsPlayerController::OnMoveTriggered()
{
	FHitResult Hit;
	bool bHitSuccessful = GetHitResultUnderCursor(ECC_Visibility, true, Hit);

	if(bHitSuccessful)
	{
		CachedDestination = Hit.Location;
	}

	APawn* ControlledPawn = GetPawn();
	if(ControlledPawn != nullptr)
	{
		FVector WorldDirection = (CachedDestination - ControlledPawn->GetActorLocation()).GetSafeNormal();
		ControlledPawn->AddMovementInput(WorldDirection, 1.0, false);
	}
}

void ASurvivorsPlayerController::OnMoveReleased()
{
	UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, CachedDestination);
}


