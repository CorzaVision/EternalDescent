// MixedRoomTestUtilities.h - Header for mixed room size test utilities
/*
 * INTENT: Define structures and functions for testing mixed room size systems
 * PURPOSE: Provide consistent, reusable test validation across all mixed room tests
 * EMPIRICAL VALIDATION: All functions provide measurable validation results
 * FAILURE CONDITIONS: Functions return false/invalid data when validation fails
 * KNOWLEDGE TRANSFER: Centralized test interface ensures consistent test patterns
 */

#pragma once

#include "CoreMinimal.h"
#include "MixedRoomTestUtilities.generated.h"

class AGridDungeonVisualizer;

// Analysis structure for mixed room size generation - MUST be outside preprocessor blocks
USTRUCT()
struct FMixedRoomAnalysis
{
    GENERATED_BODY()
    
    // Room counts by type
    int32 TotalRoomCount = 0;
    int32 StartRoomCount = 0;
    int32 EndRoomCount = 0;
    int32 RegularRoomCount = 0;
    
    // Correct room size counts
    int32 Correct2x2StartRooms = 0;
    int32 Correct2x2EndRooms = 0;
    int32 Correct3x3RegularRooms = 0;
    
    // Grid statistics
    int32 TotalFloorCells = 0;
    int32 TotalWallCells = 0;
    
    // Room pair analysis
    int32 TotalRoomPairs = 0;
    int32 TwoByTwoPairs = 0;          // 2x2 ↔ 2x2 pairs
    int32 TwoByThreePairs = 0;        // 2x2 ↔ 3x3 pairs
    int32 ThreeByThreePairs = 0;      // 3x3 ↔ 3x3 pairs
    
    // Validation results
    bool SpacingValid = false;
};

#if WITH_AUTOMATION_TESTS

/**
 * Utility class for testing mixed room size systems
 */
class MixedRoomTestUtilities
{
public:
    /**
     * Verify that a room at the given center has the expected size
     * @param Visualizer - The grid visualizer to test
     * @param RoomCenter - Center position of the room
     * @param ExpectedSize - Expected room size (2 for 2x2, 3 for 3x3)
     * @return true if the room has exactly the expected number of floor cells
     */
    static bool VerifyRoomSize(AGridDungeonVisualizer* Visualizer, FIntPoint RoomCenter, int32 ExpectedSize);
    
    /**
     * Verify that two rooms of given sizes maintain proper 1-cell gap
     * @param Visualizer - The grid visualizer to test
     * @param Room1Center - Center of first room
     * @param Room1Size - Size of first room (2 or 3)
     * @param Room2Center - Center of second room
     * @param Room2Size - Size of second room (2 or 3)
     * @return true if rooms maintain at least 1 cell gap
     */
    static bool VerifyGapBetweenRooms(AGridDungeonVisualizer* Visualizer,
        FIntPoint Room1Center, int32 Room1Size,
        FIntPoint Room2Center, int32 Room2Size);
    
    /**
     * Perform comprehensive analysis of mixed room generation
     * @param Visualizer - The grid visualizer to analyze
     * @return Analysis structure with detailed room system statistics
     */
    static FMixedRoomAnalysis AnalyzeMixedRoomGeneration(AGridDungeonVisualizer* Visualizer);
    
    /**
     * Validate that the room system maintains integrity requirements
     * @param Analysis - Analysis results to validate
     * @return true if all integrity checks pass
     */
    static bool ValidateRoomSystemIntegrity(const FMixedRoomAnalysis& Analysis);
    
    /**
     * Generate a detailed analysis report for logging
     * @param Analysis - Analysis results to format
     * @return Formatted string report
     */
    static FString GenerateAnalysisReport(const FMixedRoomAnalysis& Analysis);
};

#endif // WITH_AUTOMATION_TESTS