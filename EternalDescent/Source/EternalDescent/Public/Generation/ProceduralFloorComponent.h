// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ProceduralFloorComponent.generated.h"

class URoomGraphBuilder;
class UWallEnvironmentBuilder;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ETERNALDESCENT_API UProceduralFloorComponent : public UActorComponent

{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UProceduralFloorComponent();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generation|Config", meta=(ClampMin="5", ClampMax="64")) int32 GridWidth = 25;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generation|Config", meta=(ClampMin="5", ClampMax="64")) int32 GridHeight = 25;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generation|Config", meta=(ClampMin="10.0")) float CellSize = 200.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generation|Config", meta=(ClampMin="1", ClampMax="64")) int32 RoomCount = 25;
	
	UFUNCTION(BlueprintCallable, Category="Generation|Actions") void GenerateFloor();
	UFUNCTION(BlueprintCallable, Category="Generation|Actions") void ClearGenerate();

private:
UPROPERTY(Transient) TObjectPtr<URoomGraphBuilder> GraphBuilder;
UPROPERTY(Transient) TObjectPtr<UWallEnvironmentBuilder> WallBuilder;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
