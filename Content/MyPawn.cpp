// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/Actor.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"





// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	CreateDefaultSubobject<UFloatingPawnMovement>("PawnMovement"); 

	CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>("CubeMesh");
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");



}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);


	//check(PlayerInputComponent);
	//PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMyPawn::Jump);
	//PlayerInputComponent->BindAction("Jump", IE_Released, this, &AMyPawn::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &AMyPawn::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyPawn::MoveRight);


	PlayerInputComponent->BindAxis("Turn", this, &AMyPawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AMyPawn::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &AMyPawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AMyPawn::LookUpAtRate);

}

void AMyPawn::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);
}


void AMyPawn::MoveRight(float Value)
{
	AddMovementInput(GetActorRightVector(), Value);
}

void AMyPawn::TurnAtRate(float Rate)
{
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AMyPawn::LookUpAtRate(float Rate)
{
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}
