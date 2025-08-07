// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "EndlessDungeonTester.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FEndlessTestStats;
struct FStageGenerationResult;
#ifdef ETERNALDESCENT_EndlessDungeonTester_generated_h
#error "EndlessDungeonTester.generated.h already included, missing '#pragma once' in EndlessDungeonTester.h"
#endif
#define ETERNALDESCENT_EndlessDungeonTester_generated_h

#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_EndlessDungeonTester_h_15_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FStageGenerationResult_Statics; \
	ETERNALDESCENT_API static class UScriptStruct* StaticStruct();


template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<struct FStageGenerationResult>();

#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_EndlessDungeonTester_h_42_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FEndlessTestStats_Statics; \
	ETERNALDESCENT_API static class UScriptStruct* StaticStruct();


template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<struct FEndlessTestStats>();

#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_EndlessDungeonTester_h_84_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execShowAllStagesOverview); \
	DECLARE_FUNCTION(execVisualizeStage); \
	DECLARE_FUNCTION(execSaveTestResults); \
	DECLARE_FUNCTION(execPrintTestReport); \
	DECLARE_FUNCTION(execUpdatePerformanceMetrics); \
	DECLARE_FUNCTION(execGetStageResult); \
	DECLARE_FUNCTION(execGetTestStats); \
	DECLARE_FUNCTION(execTestGenerationSpeed); \
	DECLARE_FUNCTION(execTestRoomScaling); \
	DECLARE_FUNCTION(execRunStressTest); \
	DECLARE_FUNCTION(execValidateStage); \
	DECLARE_FUNCTION(execTransitionToStage); \
	DECLARE_FUNCTION(execClearCurrentStage); \
	DECLARE_FUNCTION(execGenerateMaximumStages); \
	DECLARE_FUNCTION(execGenerateMultipleStages); \
	DECLARE_FUNCTION(execGenerateNextStage); \
	DECLARE_FUNCTION(execStopEndlessTest); \
	DECLARE_FUNCTION(execStartEndlessTest);


#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_EndlessDungeonTester_h_84_CALLBACK_WRAPPERS
#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_EndlessDungeonTester_h_84_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAEndlessDungeonTester(); \
	friend struct Z_Construct_UClass_AEndlessDungeonTester_Statics; \
public: \
	DECLARE_CLASS(AEndlessDungeonTester, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/EternalDescent"), NO_API) \
	DECLARE_SERIALIZER(AEndlessDungeonTester)


#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_EndlessDungeonTester_h_84_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AEndlessDungeonTester(AEndlessDungeonTester&&); \
	AEndlessDungeonTester(const AEndlessDungeonTester&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEndlessDungeonTester); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEndlessDungeonTester); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AEndlessDungeonTester) \
	NO_API virtual ~AEndlessDungeonTester();


#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_EndlessDungeonTester_h_81_PROLOG
#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_EndlessDungeonTester_h_84_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_EndlessDungeonTester_h_84_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_EndlessDungeonTester_h_84_CALLBACK_WRAPPERS \
	FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_EndlessDungeonTester_h_84_INCLASS_NO_PURE_DECLS \
	FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_EndlessDungeonTester_h_84_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ETERNALDESCENT_API UClass* StaticClass<class AEndlessDungeonTester>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_EndlessDungeonTester_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
