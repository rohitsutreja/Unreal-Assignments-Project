// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StairCaseActor.generated.h"


//To store StepComponents along with childes in array.
USTRUCT()
struct FStepComponent {
	GENERATED_BODY()
	UStaticMeshComponent* BaseComponent{};
	UStaticMeshComponent* LeftRailComponent{};
	UStaticMeshComponent* RightRailComponent{};

	void Destroy() {
		if(BaseComponent){
			BaseComponent->DestroyComponent();
		}
		if (LeftRailComponent) {
			LeftRailComponent->DestroyComponent();
		}
		if (RightRailComponent) {
			RightRailComponent->DestroyComponent();
		}
	}
};


//Represents scale of single step
USTRUCT(BlueprintType)
struct FStepSize {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	double Length;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	double Width;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	double Depth;
};


UENUM(BlueprintType)
enum class EStairTypes : uint8 {
	OpenStair,
	ClosedStair,
	BoxStair
};

UCLASS()
class DAY2_API AStairCaseActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AStairCaseActor();

	//Will be called from construction script of blueprint.
	UFUNCTION(BlueprintCallable)
	void GenerateStair();

protected:
	//to calculate the angle of stair from surface, so that railing can be created.

	double DepthLengthRatio;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 NumberOfSteps;

	//Scale of single step
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FStepSize StepScale;

	//Open, Close or Box
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EStairTypes TypeOfStairs;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool ShowRailings = false;

	//distance between steps in case of open stair
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "TypeOfStairs == EStairTypes::OpenStair" ))
	double distance;

	//Materials
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Materials")
	UMaterialInterface* StepMaterial;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Materials")
	UMaterialInterface* RailConnectorMaterial;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Materials")
	UMaterialInterface* RailMaterial;


	//Meshes
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite ,Category = "Meshes")
	class UStaticMesh* StairMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Meshes")
	class UStaticMesh* RailingConnectorMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Meshes")
	class UStaticMesh* RailingMesh;


	//Array Of Component
	UPROPERTY()
	TArray<FStepComponent> ArrayOfStepComponent;

	UPROPERTY()
	TArray<UStaticMeshComponent*> Rails;

};
