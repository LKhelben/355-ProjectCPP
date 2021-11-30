// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TimelineComponent.h"
#include "Components/BoxComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "InteractableThing.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "Door.generated.h"


UCLASS()
class FUNPROJECT_API ADoor : public AActor, public IInteractableThing
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ADoor();

		// scene componet for root
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	class USceneComponent* TheRoot;

	// scene componet for hinge
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class USceneComponent* TheHinge;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UBoxComponent* Collider;

	// Mesh for door
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		class UStaticMeshComponent* TheMeshDoor;

	//mesh for doorframe
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		class UInstancedStaticMeshComponent* TheMeshFrame;

	UPROPERTY (EditAnywhere, BlueprintReadWrite, Category = "Door Stuff")
	UCurveFloat* doorOpenCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door Stuff")
		float WidthOfDoor = 200;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door Stuff")
		float HeightOfDoor = 300;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door Stuff")
		float DepthOfDoor = 25;

	//collider

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnAnimUpdate(float val);

	UTimelineComponent* DoorAnim;

	bool IsDoorFlipped = false;
	bool IsDoorOpen = false;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void OnConstruction(const FTransform& xform) override;

	virtual void Interact(); 
};
