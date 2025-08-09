// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SnakeDungeonGenerator.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class ERoomType : uint8;
enum class ESnakeDirection : uint8;
struct FSnakeGenerationStats;
#ifdef ETERNALDESCENT_SnakeDungeonGenerator_generated_h
#error "SnakeDungeonGenerator.generated.h already included, missing '#pragma once' in SnakeDungeonGenerator.h"
#endif
#define ETERNALDESCENT_SnakeDungeonGenerator_generated_h

#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonGenerator_h_25_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSnakePathNode_Statics; \
	ETERNALDESCENT_API static class UScriptStruct* StaticStruct();


template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<struct FSnakePathNode>();

#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonGenerator_h_50_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSnakeGenerationSettings_Statics; \
	ETERNALDESCENT_API static class UScriptStruct* StaticStruct();


template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<struct FSnakeGenerationSettings>();

#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonGenerator_h_88_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSnakeGenerationStats_Statics; \
	ETERNALDESCENT_API static class UScriptStruct* StaticStruct();


template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<struct FSnakeGenerationStats>();

#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonGenerator_h_133_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execCalculateManhattanDistance); \
	DECLARE_FUNCTION(execGetDirectionToNeighbor); \
	DECLARE_FUNCTION(execGetValidNeighbors); \
	DECLARE_FUNCTION(execIsValidSnakePosition); \
	DECLARE_FUNCTION(execGetLastGenerationStats); \
	DECLARE_FUNCTION(execValidateSnakeGeneration); \
	DECLARE_FUNCTION(execDrawDebugSnakePath); \
	DECLARE_FUNCTION(execSpawnConnectionHallways); \
	DECLARE_FUNCTION(execSpawnWallCubesBetweenRooms); \
	DECLARE_FUNCTION(execSpawnRoomMeshesForSnake); \
	DECLARE_FUNCTION(execGetADADifficultyModifier); \
	DECLARE_FUNCTION(execApplyADAInfluence); \
	DECLARE_FUNCTION(execAttemptBranchFromPosition); \
	DECLARE_FUNCTION(execGenerateBranches); \
	DECLARE_FUNCTION(execDetermineRoomTypeForPosition); \
	DECLARE_FUNCTION(execAssignRoomTypes); \
	DECLARE_FUNCTION(execGetShortestPath); \
	DECLARE_FUNCTION(execValidatePathConnectivity); \
	DECLARE_FUNCTION(execCreateSnakePathFromStartToExit); \
	DECLARE_FUNCTION(execGenerateAndVisualizeSnakeDungeon); \
	DECLARE_FUNCTION(execSpawnSnakeVisualization); \
	DECLARE_FUNCTION(execGenerateSnakePath);


#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonGenerator_h_133_CALLBACK_WRAPPERS
#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonGenerator_h_133_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASnakeDungeonGenerator(); \
	friend struct Z_Construct_UClass_ASnakeDungeonGenerator_Statics; \
public: \
	DECLARE_CLASS(ASnakeDungeonGenerator, ADungeonVisualizer, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/EternalDescent"), NO_API) \
	DECLARE_SERIALIZER(ASnakeDungeonGenerator)


#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonGenerator_h_133_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ASnakeDungeonGenerator(ASnakeDungeonGenerator&&); \
	ASnakeDungeonGenerator(const ASnakeDungeonGenerator&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASnakeDungeonGenerator); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASnakeDungeonGenerator); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASnakeDungeonGenerator) \
	NO_API virtual ~ASnakeDungeonGenerator();


#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonGenerator_h_130_PROLOG
#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonGenerator_h_133_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonGenerator_h_133_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonGenerator_h_133_CALLBACK_WRAPPERS \
	FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonGenerator_h_133_INCLASS_NO_PURE_DECLS \
	FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonGenerator_h_133_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ETERNALDESCENT_API UClass* StaticClass<class ASnakeDungeonGenerator>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonGenerator_h


#define FOREACH_ENUM_ESNAKEDIRECTION(op) \
	op(ESnakeDirection::North) \
	op(ESnakeDirection::South) \
	op(ESnakeDirection::East) \
	op(ESnakeDirection::West) 

enum class ESnakeDirection : uint8;
template<> struct TIsUEnumClass<ESnakeDirection> { enum { Value = true }; };
template<> ETERNALDESCENT_API UEnum* StaticEnum<ESnakeDirection>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
