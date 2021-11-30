// Fill out your copyright notice in the Description page of Project Settings.


#include "BreakableBox.h"

// Sets default values
ABreakableBox::ABreakableBox()
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
void ABreakableBox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABreakableBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABreakableBox::OnConstruction(const FTransform& xform)
{
	Super::OnConstruction(xform);

	TheBox->SetWorldScale3D(FVector(WidthOfBox, DepthOfBox, HeightOfBox) / 100);

	TheBox->SetRelativeLocation(FVector(-WidthOfBox / 2, 0, 0));
}

void ABreakableBox::Interact()
{
	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Green, "player destroyed box");
	Destroy();
}

