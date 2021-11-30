// Fill out your copyright notice in the Description page of Project Settings.


#include "MovableBox.h"

FVector ForwardVector;
 

// Sets default values
AMovableBox::AMovableBox()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TheRoot = CreateDefaultSubobject<USceneComponent>(FName("TheRoot"));
	RootComponent = TheRoot;

	TheBox = CreateDefaultSubobject<UStaticMeshComponent>(FName("TheBox"));
	TheBox->SetupAttachment(TheRoot);

	ConstructorHelpers::FObjectFinder<UStaticMesh> TheCubeMesh(TEXT("/Game/Art/Meshes/1M_Cube"));

	if (TheCubeMesh.Object)
	{
		TheBox->SetStaticMesh(TheCubeMesh.Object);
	}
}

// Called when the game starts or when spawned
void AMovableBox::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMovableBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMovableBox::OnConstruction(const FTransform& xform)
{
	Super::OnConstruction(xform);

	TheBox->SetWorldScale3D(FVector(WidthOfBox, DepthOfBox, HeightOfBox) / 100);
	TheBox->SetWorldLocation(FVector(-WidthOfBox / 2, 0, 0));
}

void AMovableBox::Interact()
{
	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Green, "player moved box");
		TheBox->SetRelativeLocation((ForwardVector * 5));
		//TheRoot->SetRelativeLocation((ForwardVector * 5));
}
