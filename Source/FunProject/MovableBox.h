// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "UObject/ConstructorHelpers.h"
#include "InteractableThing.h"

#include "MovableBox.generated.h"

UCLASS()
class FUNPROJECT_API AMovableBox : public AActor, public IInteractableThing
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMovableBox();

	// scene componet for root
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		class USceneComponent* TheRoot;

	// Mesh for box
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		class UStaticMeshComponent* TheBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Box Stuff")
		float WidthOfBox = 75;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Box Stuff")
		float HeightOfBox = 75;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Box Stuff")
		float DepthOfBox = 75;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform& xform) override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Interact();
};
