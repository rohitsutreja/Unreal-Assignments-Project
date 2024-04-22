// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class DAY2_API AMyActor : public AActor
{
	GENERATED_BODY()

public:	
	AMyActor();

	void BeginPlay();

	virtual void Tick(float DeltaTime) override;

	void OnConstruction(const FTransform& transform) override;

	UPROPERTY(BlueprintReadWrite, Category = "Numbers")
	int64 publicint = 30;

protected:
	UPROPERTY()
	FString str = "Hello";

	UPROPERTY(EditAnywhere, Category = "Numbers")
	int32 protectedint = 20;


private:
	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* MeshComponent;

	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* CollisionComponent;

	UPROPERTY(EditAnywhere, Category = "Numbers")
	int32 privateint = 10;
};
