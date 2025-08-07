// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "GridDungeonVisualizer.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EGridCellType : uint8;
enum class ERoomType : uint8;
struct FDungeonLayout;
struct FGridCell;
struct FHallway;
struct FOrganicRoom;
struct FRoomData;
#ifdef ETERNALDESCENT_GridDungeonVisualizer_generated_h
#error "GridDungeonVisualizer.generated.h already included, missing '#pragma once' in GridDungeonVisualizer.h"
#endif
#define ETERNALDESCENT_GridDungeonVisualizer_generated_h

#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_31_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FGridCell_Statics; \
	ETERNALDESCENT_API static class UScriptStruct* StaticStruct();


template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<struct FGridCell>();

#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_46_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FOrganicRoom_Statics; \
	ETERNALDESCENT_API static class UScriptStruct* StaticStruct();


template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<struct FOrganicRoom>();

#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_73_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FHallway_Statics; \
	ETERNALDESCENT_API static class UScriptStruct* StaticStruct();


template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<struct FHallway>();

#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_91_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FOrganicDungeonLayout_Statics; \
	ETERNALDESCENT_API static class UScriptStruct* StaticStruct();


template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<struct FOrganicDungeonLayout>();

#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_112_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execFindValidRoomPosition); \
	DECLARE_FUNCTION(execDoRoomsOverlap); \
	DECLARE_FUNCTION(execGenerateHallwayPath); \
	DECLARE_FUNCTION(execCreateHallway); \
	DECLARE_FUNCTION(execGenerateBranches); \
	DECLARE_FUNCTION(execGenerateMainPath); \
	DECLARE_FUNCTION(execGenerateOrganicDungeon); \
	DECLARE_FUNCTION(execSpawnTestChestsInRoom); \
	DECLARE_FUNCTION(execSpawnTestEnemiesInRoom); \
	DECLARE_FUNCTION(execSpawnRoomContents); \
	DECLARE_FUNCTION(execGetStartPosition); \
	DECLARE_FUNCTION(execSpawnPlayerAtStart); \
	DECLARE_FUNCTION(execGenerateInEditor); \
	DECLARE_FUNCTION(execToggleDebugGridInEditor); \
	DECLARE_FUNCTION(execClearDebugGrid); \
	DECLARE_FUNCTION(execDrawDebugGrid); \
	DECLARE_FUNCTION(execPlaceRoomInGrid); \
	DECLARE_FUNCTION(execWorldToGridPosition); \
	DECLARE_FUNCTION(execGridToWorldPosition); \
	DECLARE_FUNCTION(execIsValidGridPosition); \
	DECLARE_FUNCTION(execGetGridCell); \
	DECLARE_FUNCTION(execSetGridCell); \
	DECLARE_FUNCTION(execSpawnGridVisualization); \
	DECLARE_FUNCTION(execClearDungeon); \
	DECLARE_FUNCTION(execBuildGridFromLayout); \
	DECLARE_FUNCTION(execGenerateAndVisualizeDungeon);


#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_112_CALLBACK_WRAPPERS
#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_112_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGridDungeonVisualizer(); \
	friend struct Z_Construct_UClass_AGridDungeonVisualizer_Statics; \
public: \
	DECLARE_CLASS(AGridDungeonVisualizer, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/EternalDescent"), NO_API) \
	DECLARE_SERIALIZER(AGridDungeonVisualizer)


#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_112_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AGridDungeonVisualizer(AGridDungeonVisualizer&&); \
	AGridDungeonVisualizer(const AGridDungeonVisualizer&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGridDungeonVisualizer); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGridDungeonVisualizer); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGridDungeonVisualizer) \
	NO_API virtual ~AGridDungeonVisualizer();


#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_109_PROLOG
#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_112_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_112_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_112_CALLBACK_WRAPPERS \
	FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_112_INCLASS_NO_PURE_DECLS \
	FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_112_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ETERNALDESCENT_API UClass* StaticClass<class AGridDungeonVisualizer>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h


#define FOREACH_ENUM_EDUNGEONGENERATIONTYPE(op) \
	op(EDungeonGenerationType::Grid) \
	op(EDungeonGenerationType::Organic) 

enum class EDungeonGenerationType : uint8;
template<> struct TIsUEnumClass<EDungeonGenerationType> { enum { Value = true }; };
template<> ETERNALDESCENT_API UEnum* StaticEnum<EDungeonGenerationType>();

#define FOREACH_ENUM_EGRIDCELLTYPE(op) \
	op(EGridCellType::Empty) \
	op(EGridCellType::Floor) \
	op(EGridCellType::Wall) \
	op(EGridCellType::Door) \
	op(EGridCellType::Hallway) 

enum class EGridCellType : uint8;
template<> struct TIsUEnumClass<EGridCellType> { enum { Value = true }; };
template<> ETERNALDESCENT_API UEnum* StaticEnum<EGridCellType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
