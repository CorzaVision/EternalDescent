#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tests/DungeonTestTypes.h"
#include "DungeonGenerator.generated.h"

DECLARE_DELEGATE_OneParam(FOnDungeonGenerationComplete, const FDungeonLayout&);

UCLASS()
class ETERNALDESCENT_API ADungeonGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	ADungeonGenerator();

	// Core generation functions
	UFUNCTION(BlueprintCallable, Category = "Dungeon Generation")
	FDungeonLayout GenerateFloor(int32 FloorNumber);
	
	// Async generation
	void GenerateFloorAsync(int32 FloorNumber, FOnDungeonGenerationComplete OnComplete);
	
	// Configuration
	UFUNCTION(BlueprintCallable, Category = "Dungeon Generation")
	void SetActiveZone(EDungeonZone Zone);
	
	UFUNCTION(BlueprintCallable, Category = "Dungeon Generation")
	void SetEntityProfile(const FEntityProfile& Profile);
	
protected:
	virtual void BeginPlay() override;

private:
	// Generation parameters
	static constexpr int32 GRID_SIZE = 5;
	static constexpr int32 ROOMS_PER_FLOOR = 25;
	static constexpr float TARGET_GENERATION_TIME_MS = 16.0f;
	
	// Current configuration
	UPROPERTY()
	EDungeonZone CurrentZone;
	
	UPROPERTY()
	FEntityProfile EntityProfile;
	
	// Generation helpers
	void GenerateLayout(FDungeonLayout& Layout);
	void PopulateRooms(FDungeonLayout& Layout);
	void GenerateConnections(FDungeonLayout& Layout);
	void ApplyZoneTheme(FDungeonLayout& Layout);
	void ApplyEntityInfluence(FDungeonLayout& Layout);
	
	// Room selection
	ERoomType SelectRoomType(int32 FloorNumber, const FIntVector& Position);
	float CalculateDifficulty(int32 FloorNumber, float EntityInfluence);
	
	// Connectivity
	bool IsValidConnection(const FIntVector& From, const FIntVector& To);
	void EnsureConnectivity(FDungeonLayout& Layout);
	
	// Performance optimization
	void OptimizeLayout(FDungeonLayout& Layout);
};