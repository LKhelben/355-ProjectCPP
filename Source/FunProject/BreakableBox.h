// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "UObject/ConstructorHelpers.h"
#include "InteractableThing.h"

#include "BreakableBox.generated.h"

UCLASS()
class FUNPROJECT_API ABreakableBox : public AActor, public IInteractableThing
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABreakableBox();

	// scene componet for root
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class USceneComponent* TheRoot;

	// Mesh for box
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UStaticMeshComponent* TheBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Box Stuff")
		float WidthOfBox = 250;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Box Stuff")
		float HeightOfBox = 150;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Box Stuff")
		float DepthOfBox = 150;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void OnConstruction(const FTransform& xform) override;

	virtual void Interact();
};
