// Fill out your copyright notice in the Description page of Project Settings.


#include "Elevator.h"

// Sets default values
AElevator::AElevator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TheRoot = CreateDefaultSubobject<USceneComponent>(FName("TheRoot"));
	RootComponent = TheRoot;
	//TheRoot->SetupAttachment(RootComponent);

	TheBase = CreateDefaultSubobject<UStaticMeshComponent>(FName("TheBase"));
	TheBase->SetupAttachment(TheRoot);

	ConstructorHelpers::FObjectFinder<UStaticMesh> TheCubeMesh(TEXT("/Game/Art/Meshes/1M_Cube"));

	if (TheCubeMesh.Object)
	{
		TheBase->SetStaticMesh(TheCubeMesh.Object);
	}

	DoorAnim = CreateDefaultSubobject<UTimelineComponent>(FName("DoorOpenTimeline"));

}

void AElevator::OnAnimUpdate(float val)
{
	FRotator rot(0, val * 90, 0);

	if (IsElevatorFlipped) rot.Yaw *= -1;

	TheBase->SetRelativeRotation(rot);
}

// Called when the game starts or when spawned
void AElevator::BeginPlay()
{
	Super::BeginPlay();

	if (ElevatorCurve) {
		FOnTimelineFloat eventHandler;
		//eventHandler.BindUFunction(this, TEXT("OnAnimUpdate"));
		eventHandler.BindDynamic(this, &AElevator::OnAnimUpdate);
		DoorAnim->AddInterpFloat(ElevatorCurve, eventHandler, TEXT("HandleCurveFunc"));
		DoorAnim->SetTimelineLengthMode(ETimelineLengthMode::TL_LastKeyFrame);
	}
	
}

// Called every frame
void AElevator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AElevator::OnConstruction(const FTransform& xform)
{
	Super::OnConstruction(xform);

	TheBase->SetWorldScale3D(FVector(WidthOfBase, DepthOfBase, HeightOfBase) / 100);

	//TheMeshDoor->SetRelativeLocation(FVector(WidthOfDoor / 2, 0, HeightOfDoor / 2));

	//TheHinge->SetRelativeLocation(FVector(-WidthOfDoor / 2, 0, 0));

	//TheMeshFrame->ClearInstances();
	//TheMeshFrame->AddInstance(FTransform(FRotator(0, 0, 0), FVector(WidthOfDoor / 2 + DepthOfDoor / 2, 0, HeightOfDoor / 2), FVector(DepthOfDoor, DepthOfDoor, HeightOfDoor) / 100));
	//TheMeshFrame->AddInstance(FTransform(FRotator(0, 0, 0), FVector(-WidthOfDoor / 2 - DepthOfDoor / 2, 0, HeightOfDoor / 2), FVector(DepthOfDoor, DepthOfDoor, HeightOfDoor) / 100));

	FVector ElevatorSize = FVector(WidthOfBase, DepthOfBase, HeightOfBase) / 2;
	ElevatorSize.X += 50;
	ElevatorSize.Y += 25;
	Collider->SetBoxExtent(ElevatorSize);
	Collider->SetRelativeLocation(FVector(0, 0, HeightOfBase / 2.f));
}

void AElevator::Interact()
{
	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Green, "player go up");

	if (IsElevatorUp) {
		DoorAnim->Reverse();
		IsElevatorUp = false;
	}
	else {

		ACharacter* player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

		FVector vecToDoor = GetActorLocation() - player->GetActorLocation();
		vecToDoor.Normalize();

		GetActorRightVector();

		float align = FVector::DotProduct(vecToDoor, GetActorRightVector());

		IsElevatorFlipped = (align < 0);

		DoorAnim->Play();
		IsElevatorUp = true;
	}
}
