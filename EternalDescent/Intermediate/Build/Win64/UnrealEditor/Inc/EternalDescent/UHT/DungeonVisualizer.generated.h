// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DungeonVisualizer.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FDungeonLayout;
struct FHallwayConnection;
struct FRoomData;
struct FRoomVisualData;
#ifdef ETERNALDESCENT_DungeonVisualizer_generated_h
#error "DungeonVisualizer.generated.h already included, missing '#pragma once' in DungeonVisualizer.h"
#endif
#define ETERNALDESCENT_DungeonVisualizer_generated_h

#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_DungeonVisualizer_h_15_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FRoomMeshSet_Statics; \
	ETERNALDESCENT_API static class UScriptStruct* StaticStruct();


template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<struct FRoomMeshSet>();

#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_DungeonVisualizer_h_36_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FRoomVisualData_Statics; \
	ETERNALDESCENT_API static class UScriptStruct* StaticStruct();


template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<struct FRoomVisualData>();

#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_DungeonVisualizer_h_60_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetRoomVisualData); \
	DECLARE_FUNCTION(execWorldToGridPosition); \
	DECLARE_FUNCTION(execGridToWorldPosition); \
	DECLARE_FUNCTION(execApplyLighting); \
	DECLARE_FUNCTION(execSetRoomTheme); \
	DECLARE_FUNCTION(execSpawnLootInRoom); \
	DECLARE_FUNCTION(execSpawnEnemiesInRoom); \
	DECLARE_FUNCTION(execGetStartRoomPosition); \
	DECLARE_FUNCTION(execSpawnPlayerAtStart); \
	DECLARE_FUNCTION(execSpawnDoor); \
	DECLARE_FUNCTION(execCreateHallwayPath); \
	DECLARE_FUNCTION(execSpawnHallway); \
	DECLARE_FUNCTION(execSpawnRoomMeshes); \
	DECLARE_FUNCTION(execSpawnRoom); \
	DECLARE_FUNCTION(execClearDungeon); \
	DECLARE_FUNCTION(execVisualizeDungeonLayout); \
	DECLARE_FUNCTION(execGenerateAndVisualizeDungeon);


#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_DungeonVisualizer_h_60_CALLBACK_WRAPPERS
#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_DungeonVisualizer_h_60_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesADungeonVisualizer(); \
	friend struct Z_Construct_UClass_ADungeonVisualizer_Statics; \
public: \
	DECLARE_CLASS(ADungeonVisualizer, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/EternalDescent"), NO_API) \
	DECLARE_SERIALIZER(ADungeonVisualizer)


#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_DungeonVisualizer_h_60_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ADungeonVisualizer(ADungeonVisualizer&&); \
	ADungeonVisualizer(const ADungeonVisualizer&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADungeonVisualizer); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADungeonVisualizer); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ADungeonVisualizer) \
	NO_API virtual ~ADungeonVisualizer();


#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_DungeonVisualizer_h_57_PROLOG
#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_DungeonVisualizer_h_60_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_DungeonVisualizer_h_60_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_DungeonVisualizer_h_60_CALLBACK_WRAPPERS \
	FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_DungeonVisualizer_h_60_INCLASS_NO_PURE_DECLS \
	FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_DungeonVisualizer_h_60_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ETERNALDESCENT_API UClass* StaticClass<class ADungeonVisualizer>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_DungeonVisualizer_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
