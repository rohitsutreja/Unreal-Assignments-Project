// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "Engine/Engine.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h" 
#include "Components/CapsuleComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
AMyActor::AMyActor()
{

	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(RootComponent);
	MeshComponent->SetSimulatePhysics(true);
	MeshComponent->WakeRigidBody();

	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));

	if (StaticMeshAsset.Succeeded())
	{
		MeshComponent->SetStaticMesh(StaticMeshAsset.Object);
	}


	CollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionComponent"));
	CollisionComponent->SetBoxExtent(MeshComponent->Bounds.BoxExtent * 1.25f);
	CollisionComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f));
	CollisionComponent->SetupAttachment(MeshComponent);





}





// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, str);
	privateint++;
}

void AMyActor::OnConstruction(const FTransform& transform) {
	GEngine->AddOnScreenDebugMessage(-1 , 2 , FColor::Red ,"This is a construction");
	UE_LOG(LogTemp, Warning, TEXT("This is a construction"));
}

