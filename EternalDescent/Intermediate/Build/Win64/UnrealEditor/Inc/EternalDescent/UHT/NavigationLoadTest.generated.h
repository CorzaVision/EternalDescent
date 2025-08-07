// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "NavigationLoadTest.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FNavigationTestResult;
struct FNavigationTestStats;
#ifdef ETERNALDESCENT_NavigationLoadTest_generated_h
#error "NavigationLoadTest.generated.h already included, missing '#pragma once' in NavigationLoadTest.h"
#endif
#define ETERNALDESCENT_NavigationLoadTest_generated_h

#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_NavigationLoadTest_h_16_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FNavigationTestResult_Statics; \
	ETERNALDESCENT_API static class UScriptStruct* StaticStruct();


template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<struct FNavigationTestResult>();

#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_NavigationLoadTest_h_55_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FNavigationTestStats_Statics; \
	ETERNALDESCENT_API static class UScriptStruct* StaticStruct();


template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<struct FNavigationTestStats>();

#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_NavigationLoadTest_h_106_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSaveTestResults); \
	DECLARE_FUNCTION(execPrintTestReport); \
	DECLARE_FUNCTION(execGetTestStats); \
	DECLARE_FUNCTION(execStressTestNavigation); \
	DECLARE_FUNCTION(execTestPathfindingPerformance); \
	DECLARE_FUNCTION(execTestMemoryLeaks); \
	DECLARE_FUNCTION(execClearAllMemory); \
	DECLARE_FUNCTION(execUnloadDungeon); \
	DECLARE_FUNCTION(execLoadDungeon); \
	DECLARE_FUNCTION(execSimulatePlayerMovement); \
	DECLARE_FUNCTION(execFindPathBetweenRooms); \
	DECLARE_FUNCTION(execNavigateFromStartToExit); \
	DECLARE_FUNCTION(execRunMultipleCycles); \
	DECLARE_FUNCTION(execRunSingleCycle); \
	DECLARE_FUNCTION(execStopNavigationTest); \
	DECLARE_FUNCTION(execStartNavigationTest);


#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_NavigationLoadTest_h_106_CALLBACK_WRAPPERS
#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_NavigationLoadTest_h_106_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesANavigationLoadTest(); \
	friend struct Z_Construct_UClass_ANavigationLoadTest_Statics; \
public: \
	DECLARE_CLASS(ANavigationLoadTest, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/EternalDescent"), NO_API) \
	DECLARE_SERIALIZER(ANavigationLoadTest)


#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_NavigationLoadTest_h_106_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ANavigationLoadTest(ANavigationLoadTest&&); \
	ANavigationLoadTest(const ANavigationLoadTest&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ANavigationLoadTest); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ANavigationLoadTest); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ANavigationLoadTest) \
	NO_API virtual ~ANavigationLoadTest();


#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_NavigationLoadTest_h_103_PROLOG
#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_NavigationLoadTest_h_106_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_NavigationLoadTest_h_106_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_NavigationLoadTest_h_106_CALLBACK_WRAPPERS \
	FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_NavigationLoadTest_h_106_INCLASS_NO_PURE_DECLS \
	FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_NavigationLoadTest_h_106_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ETERNALDESCENT_API UClass* StaticClass<class ANavigationLoadTest>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_NavigationLoadTest_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
