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
#include "Elevator.generated.h"

UCLASS()
class FUNPROJECT_API AElevator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AElevator();

	// scene componet for root
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		class USceneComponent* TheRoot;

	// scene componet for Base
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		class UStaticMeshComponent* TheBase;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		class UBoxComponent* Collider;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Elevator Stuff")
		UCurveFloat* ElevatorCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Elevator Stuff")
		float WidthOfBase = 200;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Elevator Stuff")
		float HeightOfBase = 25;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Elevator Stuff")
		float DepthOfBase = 200;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnAnimUpdate(float val);

	UTimelineComponent* DoorAnim;

	bool IsElevatorFlipped = false;
	bool IsElevatorUp = false;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void OnConstruction(const FTransform& xform) override;

	virtual void Interact();
};
