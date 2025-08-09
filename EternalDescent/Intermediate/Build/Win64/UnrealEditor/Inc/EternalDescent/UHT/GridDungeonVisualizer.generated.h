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
enum class ERoomSizeType : uint8;
struct FGridCell;
#ifdef ETERNALDESCENT_GridDungeonVisualizer_generated_h
#error "GridDungeonVisualizer.generated.h already included, missing '#pragma once' in GridDungeonVisualizer.h"
#endif
#define ETERNALDESCENT_GridDungeonVisualizer_generated_h

#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_43_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FGridCell_Statics; \
	ETERNALDESCENT_API static class UScriptStruct* StaticStruct();


template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<struct FGridCell>();

#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_52_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FGridRoomInfo_Statics; \
	ETERNALDESCENT_API static class UScriptStruct* StaticStruct();


template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<struct FGridRoomInfo>();

#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_70_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execCalculateRequiredDistance); \
	DECLARE_FUNCTION(execValidateMixedRoomSpacing); \
	DECLARE_FUNCTION(execCalculateGridSizeInEditor); \
	DECLARE_FUNCTION(execValidateRoomSpacing); \
	DECLARE_FUNCTION(execAutoClearDebugAfterGeneration); \
	DECLARE_FUNCTION(execClearDebugVisualization); \
	DECLARE_FUNCTION(execClearSnakePath); \
	DECLARE_FUNCTION(execValidateSpacing); \
	DECLARE_FUNCTION(execMatchCubesToDebugBoxes); \
	DECLARE_FUNCTION(execTestAlternativeAlignment); \
	DECLARE_FUNCTION(execTestGridAlignment); \
	DECLARE_FUNCTION(execSkipToEnd); \
	DECLARE_FUNCTION(execTogglePause); \
	DECLARE_FUNCTION(execGenerateInstant); \
	DECLARE_FUNCTION(execGenerateInEditor); \
	DECLARE_FUNCTION(execDrawRoomBoundaries); \
	DECLARE_FUNCTION(execDrawDebugGrid); \
	DECLARE_FUNCTION(execGetOptimalGridSizeForRooms); \
	DECLARE_FUNCTION(execCalculateOptimalGridSize); \
	DECLARE_FUNCTION(execGridToWorldPosition); \
	DECLARE_FUNCTION(execIsValidGridPosition); \
	DECLARE_FUNCTION(execGetGridCell); \
	DECLARE_FUNCTION(execSetGridCell); \
	DECLARE_FUNCTION(execClearDungeon); \
	DECLARE_FUNCTION(execGenerateAndVisualizeDungeon);


#if WITH_EDITOR
#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_70_RPC_WRAPPERS_NO_PURE_DECLS_EOD \
	DECLARE_FUNCTION(execStopAnimation); \
	DECLARE_FUNCTION(execAnimateSnakeGeneration); \
	DECLARE_FUNCTION(execToggleDebugVisualization); \
	DECLARE_FUNCTION(execStepThroughGeneration); \
	DECLARE_FUNCTION(execClearInEditor);
#else // WITH_EDITOR
#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_70_RPC_WRAPPERS_NO_PURE_DECLS_EOD
#endif // WITH_EDITOR


#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_70_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGridDungeonVisualizer(); \
	friend struct Z_Construct_UClass_AGridDungeonVisualizer_Statics; \
public: \
	DECLARE_CLASS(AGridDungeonVisualizer, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/EternalDescent"), NO_API) \
	DECLARE_SERIALIZER(AGridDungeonVisualizer)


#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_70_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AGridDungeonVisualizer(AGridDungeonVisualizer&&); \
	AGridDungeonVisualizer(const AGridDungeonVisualizer&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGridDungeonVisualizer); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGridDungeonVisualizer); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGridDungeonVisualizer) \
	NO_API virtual ~AGridDungeonVisualizer();


#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_67_PROLOG
#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_70_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_70_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_70_RPC_WRAPPERS_NO_PURE_DECLS_EOD \
	FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_70_INCLASS_NO_PURE_DECLS \
	FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_70_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ETERNALDESCENT_API UClass* StaticClass<class AGridDungeonVisualizer>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h


#define FOREACH_ENUM_EGRIDCELLTYPE(op) \
	op(EGridCellType::Empty) \
	op(EGridCellType::Floor) \
	op(EGridCellType::Wall) 

enum class EGridCellType : uint8;
template<> struct TIsUEnumClass<EGridCellType> { enum { Value = true }; };
template<> ETERNALDESCENT_API UEnum* StaticEnum<EGridCellType>();

#define FOREACH_ENUM_EROOMSIZETYPE(op) \
	op(ERoomSizeType::None) \
	op(ERoomSizeType::Small_2x2) \
	op(ERoomSizeType::Standard_3x3) 

enum class ERoomSizeType : uint8;
template<> struct TIsUEnumClass<ERoomSizeType> { enum { Value = true }; };
template<> ETERNALDESCENT_API UEnum* StaticEnum<ERoomSizeType>();

#define FOREACH_ENUM_EGENERATIONPHASE(op) \
	op(EGenerationPhase::Idle) \
	op(EGenerationPhase::GeneratingPath) \
	op(EGenerationPhase::SpawningCubes) \
	op(EGenerationPhase::SpawningPlanes) \
	op(EGenerationPhase::Complete) 

enum class EGenerationPhase : uint8;
template<> struct TIsUEnumClass<EGenerationPhase> { enum { Value = true }; };
template<> ETERNALDESCENT_API UEnum* StaticEnum<EGenerationPhase>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
