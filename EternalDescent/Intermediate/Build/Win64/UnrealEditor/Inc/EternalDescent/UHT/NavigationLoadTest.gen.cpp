// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EternalDescent/Public/NavigationLoadTest.h"
#include "EternalDescent/Public/Tests/DungeonTestTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNavigationLoadTest() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ETERNALDESCENT_API UClass* Z_Construct_UClass_AGridDungeonVisualizer_NoRegister();
ETERNALDESCENT_API UClass* Z_Construct_UClass_ANavigationLoadTest();
ETERNALDESCENT_API UClass* Z_Construct_UClass_ANavigationLoadTest_NoRegister();
ETERNALDESCENT_API UScriptStruct* Z_Construct_UScriptStruct_FDungeonLayout();
ETERNALDESCENT_API UScriptStruct* Z_Construct_UScriptStruct_FNavigationTestResult();
ETERNALDESCENT_API UScriptStruct* Z_Construct_UScriptStruct_FNavigationTestStats();
UPackage* Z_Construct_UPackage__Script_EternalDescent();
// End Cross Module References

// Begin ScriptStruct FNavigationTestResult
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_NavigationTestResult;
class UScriptStruct* FNavigationTestResult::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_NavigationTestResult.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_NavigationTestResult.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FNavigationTestResult, (UObject*)Z_Construct_UPackage__Script_EternalDescent(), TEXT("NavigationTestResult"));
	}
	return Z_Registration_Info_UScriptStruct_NavigationTestResult.OuterSingleton;
}
template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<FNavigationTestResult>()
{
	return FNavigationTestResult::StaticStruct();
}
struct Z_Construct_UScriptStruct_FNavigationTestResult_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CycleNumber_MetaData[] = {
		{ "Category", "NavigationTestResult" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bPathFound_MetaData[] = {
		{ "Category", "NavigationTestResult" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PathLength_MetaData[] = {
		{ "Category", "NavigationTestResult" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PathNodes_MetaData[] = {
		{ "Category", "NavigationTestResult" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NavigationTime_MetaData[] = {
		{ "Category", "NavigationTestResult" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LoadTime_MetaData[] = {
		{ "Category", "NavigationTestResult" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UnloadTime_MetaData[] = {
		{ "Category", "NavigationTestResult" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MemoryBeforeMB_MetaData[] = {
		{ "Category", "NavigationTestResult" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MemoryAfterMB_MetaData[] = {
		{ "Category", "NavigationTestResult" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoomCount_MetaData[] = {
		{ "Category", "NavigationTestResult" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FailureReason_MetaData[] = {
		{ "Category", "NavigationTestResult" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_CycleNumber;
	static void NewProp_bPathFound_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bPathFound;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PathLength;
	static const UECodeGen_Private::FIntPropertyParams NewProp_PathNodes;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_NavigationTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LoadTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_UnloadTime;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MemoryBeforeMB;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MemoryAfterMB;
	static const UECodeGen_Private::FIntPropertyParams NewProp_RoomCount;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FailureReason;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FNavigationTestResult>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FNavigationTestResult_Statics::NewProp_CycleNumber = { "CycleNumber", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FNavigationTestResult, CycleNumber), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CycleNumber_MetaData), NewProp_CycleNumber_MetaData) };
void Z_Construct_UScriptStruct_FNavigationTestResult_Statics::NewProp_bPathFound_SetBit(void* Obj)
{
	((FNavigationTestResult*)Obj)->bPathFound = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FNavigationTestResult_Statics::NewProp_bPathFound = { "bPathFound", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FNavigationTestResult), &Z_Construct_UScriptStruct_FNavigationTestResult_Statics::NewProp_bPathFound_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bPathFound_MetaData), NewProp_bPathFound_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FNavigationTestResult_Statics::NewProp_PathLength = { "PathLength", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FNavigationTestResult, PathLength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PathLength_MetaData), NewProp_PathLength_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FNavigationTestResult_Statics::NewProp_PathNodes = { "PathNodes", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FNavigationTestResult, PathNodes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PathNodes_MetaData), NewProp_PathNodes_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FNavigationTestResult_Statics::NewProp_NavigationTime = { "NavigationTime", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FNavigationTestResult, NavigationTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NavigationTime_MetaData), NewProp_NavigationTime_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FNavigationTestResult_Statics::NewProp_LoadTime = { "LoadTime", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FNavigationTestResult, LoadTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LoadTime_MetaData), NewProp_LoadTime_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FNavigationTestResult_Statics::NewProp_UnloadTime = { "UnloadTime", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FNavigationTestResult, UnloadTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UnloadTime_MetaData), NewProp_UnloadTime_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FNavigationTestResult_Statics::NewProp_MemoryBeforeMB = { "MemoryBeforeMB", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FNavigationTestResult, MemoryBeforeMB), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MemoryBeforeMB_MetaData), NewProp_MemoryBeforeMB_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FNavigationTestResult_Statics::NewProp_MemoryAfterMB = { "MemoryAfterMB", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FNavigationTestResult, MemoryAfterMB), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MemoryAfterMB_MetaData), NewProp_MemoryAfterMB_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FNavigationTestResult_Statics::NewProp_RoomCount = { "RoomCount", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FNavigationTestResult, RoomCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoomCount_MetaData), NewProp_RoomCount_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FNavigationTestResult_Statics::NewProp_FailureReason = { "FailureReason", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FNavigationTestResult, FailureReason), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FailureReason_MetaData), NewProp_FailureReason_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FNavigationTestResult_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNavigationTestResult_Statics::NewProp_CycleNumber,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNavigationTestResult_Statics::NewProp_bPathFound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNavigationTestResult_Statics::NewProp_PathLength,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNavigationTestResult_Statics::NewProp_PathNodes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNavigationTestResult_Statics::NewProp_NavigationTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNavigationTestResult_Statics::NewProp_LoadTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNavigationTestResult_Statics::NewProp_UnloadTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNavigationTestResult_Statics::NewProp_MemoryBeforeMB,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNavigationTestResult_Statics::NewProp_MemoryAfterMB,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNavigationTestResult_Statics::NewProp_RoomCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNavigationTestResult_Statics::NewProp_FailureReason,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FNavigationTestResult_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FNavigationTestResult_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_EternalDescent,
	nullptr,
	&NewStructOps,
	"NavigationTestResult",
	Z_Construct_UScriptStruct_FNavigationTestResult_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FNavigationTestResult_Statics::PropPointers),
	sizeof(FNavigationTestResult),
	alignof(FNavigationTestResult),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FNavigationTestResult_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FNavigationTestResult_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FNavigationTestResult()
{
	if (!Z_Registration_Info_UScriptStruct_NavigationTestResult.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_NavigationTestResult.InnerSingleton, Z_Construct_UScriptStruct_FNavigationTestResult_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_NavigationTestResult.InnerSingleton;
}
// End ScriptStruct FNavigationTestResult

// Begin ScriptStruct FNavigationTestStats
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_NavigationTestStats;
class UScriptStruct* FNavigationTestStats::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_NavigationTestStats.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_NavigationTestStats.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FNavigationTestStats, (UObject*)Z_Construct_UPackage__Script_EternalDescent(), TEXT("NavigationTestStats"));
	}
	return Z_Registration_Info_UScriptStruct_NavigationTestStats.OuterSingleton;
}
template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<FNavigationTestStats>()
{
	return FNavigationTestStats::StaticStruct();
}
struct Z_Construct_UScriptStruct_FNavigationTestStats_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalCycles_MetaData[] = {
		{ "Category", "NavigationTestStats" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SuccessfulPaths_MetaData[] = {
		{ "Category", "NavigationTestStats" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FailedPaths_MetaData[] = {
		{ "Category", "NavigationTestStats" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalNavigationTime_MetaData[] = {
		{ "Category", "NavigationTestStats" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalLoadTime_MetaData[] = {
		{ "Category", "NavigationTestStats" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalUnloadTime_MetaData[] = {
		{ "Category", "NavigationTestStats" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AveragePathLength_MetaData[] = {
		{ "Category", "NavigationTestStats" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShortestPath_MetaData[] = {
		{ "Category", "NavigationTestStats" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LongestPath_MetaData[] = {
		{ "Category", "NavigationTestStats" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StartMemoryMB_MetaData[] = {
		{ "Category", "NavigationTestStats" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentMemoryMB_MetaData[] = {
		{ "Category", "NavigationTestStats" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PeakMemoryMB_MetaData[] = {
		{ "Category", "NavigationTestStats" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MemoryLeakMB_MetaData[] = {
		{ "Category", "NavigationTestStats" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentFPS_MetaData[] = {
		{ "Category", "NavigationTestStats" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LowestFPS_MetaData[] = {
		{ "Category", "NavigationTestStats" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_TotalCycles;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SuccessfulPaths;
	static const UECodeGen_Private::FIntPropertyParams NewProp_FailedPaths;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TotalNavigationTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TotalLoadTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TotalUnloadTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AveragePathLength;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ShortestPath;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LongestPath;
	static const UECodeGen_Private::FIntPropertyParams NewProp_StartMemoryMB;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentMemoryMB;
	static const UECodeGen_Private::FIntPropertyParams NewProp_PeakMemoryMB;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MemoryLeakMB;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentFPS;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LowestFPS;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FNavigationTestStats>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FNavigationTestStats_Statics::NewProp_TotalCycles = { "TotalCycles", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FNavigationTestStats, TotalCycles), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalCycles_MetaData), NewProp_TotalCycles_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FNavigationTestStats_Statics::NewProp_SuccessfulPaths = { "SuccessfulPaths", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FNavigationTestStats, SuccessfulPaths), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SuccessfulPaths_MetaData), NewProp_SuccessfulPaths_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FNavigationTestStats_Statics::NewProp_FailedPaths = { "FailedPaths", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FNavigationTestStats, FailedPaths), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FailedPaths_MetaData), NewProp_FailedPaths_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FNavigationTestStats_Statics::NewProp_TotalNavigationTime = { "TotalNavigationTime", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FNavigationTestStats, TotalNavigationTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalNavigationTime_MetaData), NewProp_TotalNavigationTime_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FNavigationTestStats_Statics::NewProp_TotalLoadTime = { "TotalLoadTime", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FNavigationTestStats, TotalLoadTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalLoadTime_MetaData), NewProp_TotalLoadTime_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FNavigationTestStats_Statics::NewProp_TotalUnloadTime = { "TotalUnloadTime", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FNavigationTestStats, TotalUnloadTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalUnloadTime_MetaData), NewProp_TotalUnloadTime_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FNavigationTestStats_Statics::NewProp_AveragePathLength = { "AveragePathLength", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FNavigationTestStats, AveragePathLength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AveragePathLength_MetaData), NewProp_AveragePathLength_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FNavigationTestStats_Statics::NewProp_ShortestPath = { "ShortestPath", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FNavigationTestStats, ShortestPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShortestPath_MetaData), NewProp_ShortestPath_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FNavigationTestStats_Statics::NewProp_LongestPath = { "LongestPath", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FNavigationTestStats, LongestPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LongestPath_MetaData), NewProp_LongestPath_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FNavigationTestStats_Statics::NewProp_StartMemoryMB = { "StartMemoryMB", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FNavigationTestStats, StartMemoryMB), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StartMemoryMB_MetaData), NewProp_StartMemoryMB_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FNavigationTestStats_Statics::NewProp_CurrentMemoryMB = { "CurrentMemoryMB", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FNavigationTestStats, CurrentMemoryMB), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentMemoryMB_MetaData), NewProp_CurrentMemoryMB_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FNavigationTestStats_Statics::NewProp_PeakMemoryMB = { "PeakMemoryMB", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FNavigationTestStats, PeakMemoryMB), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PeakMemoryMB_MetaData), NewProp_PeakMemoryMB_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FNavigationTestStats_Statics::NewProp_MemoryLeakMB = { "MemoryLeakMB", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FNavigationTestStats, MemoryLeakMB), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MemoryLeakMB_MetaData), NewProp_MemoryLeakMB_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FNavigationTestStats_Statics::NewProp_CurrentFPS = { "CurrentFPS", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FNavigationTestStats, CurrentFPS), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentFPS_MetaData), NewProp_CurrentFPS_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FNavigationTestStats_Statics::NewProp_LowestFPS = { "LowestFPS", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FNavigationTestStats, LowestFPS), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LowestFPS_MetaData), NewProp_LowestFPS_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FNavigationTestStats_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNavigationTestStats_Statics::NewProp_TotalCycles,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNavigationTestStats_Statics::NewProp_SuccessfulPaths,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNavigationTestStats_Statics::NewProp_FailedPaths,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNavigationTestStats_Statics::NewProp_TotalNavigationTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNavigationTestStats_Statics::NewProp_TotalLoadTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNavigationTestStats_Statics::NewProp_TotalUnloadTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNavigationTestStats_Statics::NewProp_AveragePathLength,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNavigationTestStats_Statics::NewProp_ShortestPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNavigationTestStats_Statics::NewProp_LongestPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNavigationTestStats_Statics::NewProp_StartMemoryMB,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNavigationTestStats_Statics::NewProp_CurrentMemoryMB,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNavigationTestStats_Statics::NewProp_PeakMemoryMB,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNavigationTestStats_Statics::NewProp_MemoryLeakMB,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNavigationTestStats_Statics::NewProp_CurrentFPS,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNavigationTestStats_Statics::NewProp_LowestFPS,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FNavigationTestStats_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FNavigationTestStats_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_EternalDescent,
	nullptr,
	&NewStructOps,
	"NavigationTestStats",
	Z_Construct_UScriptStruct_FNavigationTestStats_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FNavigationTestStats_Statics::PropPointers),
	sizeof(FNavigationTestStats),
	alignof(FNavigationTestStats),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FNavigationTestStats_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FNavigationTestStats_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FNavigationTestStats()
{
	if (!Z_Registration_Info_UScriptStruct_NavigationTestStats.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_NavigationTestStats.InnerSingleton, Z_Construct_UScriptStruct_FNavigationTestStats_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_NavigationTestStats.InnerSingleton;
}
// End ScriptStruct FNavigationTestStats

// Begin Class ANavigationLoadTest Function ClearAllMemory
struct Z_Construct_UFunction_ANavigationLoadTest_ClearAllMemory_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Navigation Test" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANavigationLoadTest_ClearAllMemory_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANavigationLoadTest, nullptr, "ClearAllMemory", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANavigationLoadTest_ClearAllMemory_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANavigationLoadTest_ClearAllMemory_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ANavigationLoadTest_ClearAllMemory()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANavigationLoadTest_ClearAllMemory_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ANavigationLoadTest::execClearAllMemory)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClearAllMemory();
	P_NATIVE_END;
}
// End Class ANavigationLoadTest Function ClearAllMemory

// Begin Class ANavigationLoadTest Function FindPathBetweenRooms
struct Z_Construct_UFunction_ANavigationLoadTest_FindPathBetweenRooms_Statics
{
	struct NavigationLoadTest_eventFindPathBetweenRooms_Parms
	{
		int32 StartRoomID;
		int32 EndRoomID;
		TArray<FVector> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Navigation Test" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_StartRoomID;
	static const UECodeGen_Private::FIntPropertyParams NewProp_EndRoomID;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ANavigationLoadTest_FindPathBetweenRooms_Statics::NewProp_StartRoomID = { "StartRoomID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NavigationLoadTest_eventFindPathBetweenRooms_Parms, StartRoomID), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ANavigationLoadTest_FindPathBetweenRooms_Statics::NewProp_EndRoomID = { "EndRoomID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NavigationLoadTest_eventFindPathBetweenRooms_Parms, EndRoomID), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ANavigationLoadTest_FindPathBetweenRooms_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ANavigationLoadTest_FindPathBetweenRooms_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NavigationLoadTest_eventFindPathBetweenRooms_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANavigationLoadTest_FindPathBetweenRooms_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANavigationLoadTest_FindPathBetweenRooms_Statics::NewProp_StartRoomID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANavigationLoadTest_FindPathBetweenRooms_Statics::NewProp_EndRoomID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANavigationLoadTest_FindPathBetweenRooms_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANavigationLoadTest_FindPathBetweenRooms_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANavigationLoadTest_FindPathBetweenRooms_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANavigationLoadTest_FindPathBetweenRooms_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANavigationLoadTest, nullptr, "FindPathBetweenRooms", nullptr, nullptr, Z_Construct_UFunction_ANavigationLoadTest_FindPathBetweenRooms_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANavigationLoadTest_FindPathBetweenRooms_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANavigationLoadTest_FindPathBetweenRooms_Statics::NavigationLoadTest_eventFindPathBetweenRooms_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANavigationLoadTest_FindPathBetweenRooms_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANavigationLoadTest_FindPathBetweenRooms_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ANavigationLoadTest_FindPathBetweenRooms_Statics::NavigationLoadTest_eventFindPathBetweenRooms_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ANavigationLoadTest_FindPathBetweenRooms()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANavigationLoadTest_FindPathBetweenRooms_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ANavigationLoadTest::execFindPathBetweenRooms)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_StartRoomID);
	P_GET_PROPERTY(FIntProperty,Z_Param_EndRoomID);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FVector>*)Z_Param__Result=P_THIS->FindPathBetweenRooms(Z_Param_StartRoomID,Z_Param_EndRoomID);
	P_NATIVE_END;
}
// End Class ANavigationLoadTest Function FindPathBetweenRooms

// Begin Class ANavigationLoadTest Function GetTestStats
struct Z_Construct_UFunction_ANavigationLoadTest_GetTestStats_Statics
{
	struct NavigationLoadTest_eventGetTestStats_Parms
	{
		FNavigationTestStats ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Navigation Test" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Stats & Reporting\n" },
#endif
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Stats & Reporting" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ANavigationLoadTest_GetTestStats_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NavigationLoadTest_eventGetTestStats_Parms, ReturnValue), Z_Construct_UScriptStruct_FNavigationTestStats, METADATA_PARAMS(0, nullptr) }; // 3843661947
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANavigationLoadTest_GetTestStats_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANavigationLoadTest_GetTestStats_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANavigationLoadTest_GetTestStats_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANavigationLoadTest_GetTestStats_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANavigationLoadTest, nullptr, "GetTestStats", nullptr, nullptr, Z_Construct_UFunction_ANavigationLoadTest_GetTestStats_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANavigationLoadTest_GetTestStats_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANavigationLoadTest_GetTestStats_Statics::NavigationLoadTest_eventGetTestStats_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANavigationLoadTest_GetTestStats_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANavigationLoadTest_GetTestStats_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ANavigationLoadTest_GetTestStats_Statics::NavigationLoadTest_eventGetTestStats_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ANavigationLoadTest_GetTestStats()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANavigationLoadTest_GetTestStats_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ANavigationLoadTest::execGetTestStats)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FNavigationTestStats*)Z_Param__Result=P_THIS->GetTestStats();
	P_NATIVE_END;
}
// End Class ANavigationLoadTest Function GetTestStats

// Begin Class ANavigationLoadTest Function LoadDungeon
struct Z_Construct_UFunction_ANavigationLoadTest_LoadDungeon_Statics
{
	struct NavigationLoadTest_eventLoadDungeon_Parms
	{
		int32 Seed;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Navigation Test" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Load/Unload Functions\n" },
#endif
		{ "CPP_Default_Seed", "-1" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Load/Unload Functions" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_Seed;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ANavigationLoadTest_LoadDungeon_Statics::NewProp_Seed = { "Seed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NavigationLoadTest_eventLoadDungeon_Parms, Seed), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_ANavigationLoadTest_LoadDungeon_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((NavigationLoadTest_eventLoadDungeon_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ANavigationLoadTest_LoadDungeon_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(NavigationLoadTest_eventLoadDungeon_Parms), &Z_Construct_UFunction_ANavigationLoadTest_LoadDungeon_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANavigationLoadTest_LoadDungeon_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANavigationLoadTest_LoadDungeon_Statics::NewProp_Seed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANavigationLoadTest_LoadDungeon_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANavigationLoadTest_LoadDungeon_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANavigationLoadTest_LoadDungeon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANavigationLoadTest, nullptr, "LoadDungeon", nullptr, nullptr, Z_Construct_UFunction_ANavigationLoadTest_LoadDungeon_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANavigationLoadTest_LoadDungeon_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANavigationLoadTest_LoadDungeon_Statics::NavigationLoadTest_eventLoadDungeon_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANavigationLoadTest_LoadDungeon_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANavigationLoadTest_LoadDungeon_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ANavigationLoadTest_LoadDungeon_Statics::NavigationLoadTest_eventLoadDungeon_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ANavigationLoadTest_LoadDungeon()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANavigationLoadTest_LoadDungeon_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ANavigationLoadTest::execLoadDungeon)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_Seed);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->LoadDungeon(Z_Param_Seed);
	P_NATIVE_END;
}
// End Class ANavigationLoadTest Function LoadDungeon

// Begin Class ANavigationLoadTest Function NavigateFromStartToExit
struct Z_Construct_UFunction_ANavigationLoadTest_NavigateFromStartToExit_Statics
{
	struct NavigationLoadTest_eventNavigateFromStartToExit_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Navigation Test" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Navigation Functions\n" },
#endif
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Navigation Functions" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_ANavigationLoadTest_NavigateFromStartToExit_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((NavigationLoadTest_eventNavigateFromStartToExit_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ANavigationLoadTest_NavigateFromStartToExit_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(NavigationLoadTest_eventNavigateFromStartToExit_Parms), &Z_Construct_UFunction_ANavigationLoadTest_NavigateFromStartToExit_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANavigationLoadTest_NavigateFromStartToExit_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANavigationLoadTest_NavigateFromStartToExit_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANavigationLoadTest_NavigateFromStartToExit_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANavigationLoadTest_NavigateFromStartToExit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANavigationLoadTest, nullptr, "NavigateFromStartToExit", nullptr, nullptr, Z_Construct_UFunction_ANavigationLoadTest_NavigateFromStartToExit_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANavigationLoadTest_NavigateFromStartToExit_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANavigationLoadTest_NavigateFromStartToExit_Statics::NavigationLoadTest_eventNavigateFromStartToExit_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANavigationLoadTest_NavigateFromStartToExit_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANavigationLoadTest_NavigateFromStartToExit_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ANavigationLoadTest_NavigateFromStartToExit_Statics::NavigationLoadTest_eventNavigateFromStartToExit_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ANavigationLoadTest_NavigateFromStartToExit()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANavigationLoadTest_NavigateFromStartToExit_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ANavigationLoadTest::execNavigateFromStartToExit)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->NavigateFromStartToExit();
	P_NATIVE_END;
}
// End Class ANavigationLoadTest Function NavigateFromStartToExit

// Begin Class ANavigationLoadTest Function OnCycleCompleted
struct NavigationLoadTest_eventOnCycleCompleted_Parms
{
	FNavigationTestResult Result;
};
static const FName NAME_ANavigationLoadTest_OnCycleCompleted = FName(TEXT("OnCycleCompleted"));
void ANavigationLoadTest::OnCycleCompleted(FNavigationTestResult const& Result)
{
	NavigationLoadTest_eventOnCycleCompleted_Parms Parms;
	Parms.Result=Result;
	UFunction* Func = FindFunctionChecked(NAME_ANavigationLoadTest_OnCycleCompleted);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_ANavigationLoadTest_OnCycleCompleted_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Navigation Test" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Result_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Result;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ANavigationLoadTest_OnCycleCompleted_Statics::NewProp_Result = { "Result", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NavigationLoadTest_eventOnCycleCompleted_Parms, Result), Z_Construct_UScriptStruct_FNavigationTestResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Result_MetaData), NewProp_Result_MetaData) }; // 1839902008
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANavigationLoadTest_OnCycleCompleted_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANavigationLoadTest_OnCycleCompleted_Statics::NewProp_Result,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANavigationLoadTest_OnCycleCompleted_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANavigationLoadTest_OnCycleCompleted_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANavigationLoadTest, nullptr, "OnCycleCompleted", nullptr, nullptr, Z_Construct_UFunction_ANavigationLoadTest_OnCycleCompleted_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANavigationLoadTest_OnCycleCompleted_Statics::PropPointers), sizeof(NavigationLoadTest_eventOnCycleCompleted_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANavigationLoadTest_OnCycleCompleted_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANavigationLoadTest_OnCycleCompleted_Statics::Function_MetaDataParams) };
static_assert(sizeof(NavigationLoadTest_eventOnCycleCompleted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ANavigationLoadTest_OnCycleCompleted()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANavigationLoadTest_OnCycleCompleted_Statics::FuncParams);
	}
	return ReturnFunction;
}
// End Class ANavigationLoadTest Function OnCycleCompleted

// Begin Class ANavigationLoadTest Function OnPathVisualization
struct NavigationLoadTest_eventOnPathVisualization_Parms
{
	TArray<FVector> Path;
};
static const FName NAME_ANavigationLoadTest_OnPathVisualization = FName(TEXT("OnPathVisualization"));
void ANavigationLoadTest::OnPathVisualization(TArray<FVector> const& Path)
{
	NavigationLoadTest_eventOnPathVisualization_Parms Parms;
	Parms.Path=Path;
	UFunction* Func = FindFunctionChecked(NAME_ANavigationLoadTest_OnPathVisualization);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_ANavigationLoadTest_OnPathVisualization_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Navigation Test" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Path_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Path_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Path;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ANavigationLoadTest_OnPathVisualization_Statics::NewProp_Path_Inner = { "Path", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ANavigationLoadTest_OnPathVisualization_Statics::NewProp_Path = { "Path", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NavigationLoadTest_eventOnPathVisualization_Parms, Path), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Path_MetaData), NewProp_Path_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANavigationLoadTest_OnPathVisualization_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANavigationLoadTest_OnPathVisualization_Statics::NewProp_Path_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANavigationLoadTest_OnPathVisualization_Statics::NewProp_Path,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANavigationLoadTest_OnPathVisualization_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANavigationLoadTest_OnPathVisualization_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANavigationLoadTest, nullptr, "OnPathVisualization", nullptr, nullptr, Z_Construct_UFunction_ANavigationLoadTest_OnPathVisualization_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANavigationLoadTest_OnPathVisualization_Statics::PropPointers), sizeof(NavigationLoadTest_eventOnPathVisualization_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANavigationLoadTest_OnPathVisualization_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANavigationLoadTest_OnPathVisualization_Statics::Function_MetaDataParams) };
static_assert(sizeof(NavigationLoadTest_eventOnPathVisualization_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ANavigationLoadTest_OnPathVisualization()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANavigationLoadTest_OnPathVisualization_Statics::FuncParams);
	}
	return ReturnFunction;
}
// End Class ANavigationLoadTest Function OnPathVisualization

// Begin Class ANavigationLoadTest Function OnTestCompleted
struct NavigationLoadTest_eventOnTestCompleted_Parms
{
	FNavigationTestStats FinalStats;
};
static const FName NAME_ANavigationLoadTest_OnTestCompleted = FName(TEXT("OnTestCompleted"));
void ANavigationLoadTest::OnTestCompleted(FNavigationTestStats const& FinalStats)
{
	NavigationLoadTest_eventOnTestCompleted_Parms Parms;
	Parms.FinalStats=FinalStats;
	UFunction* Func = FindFunctionChecked(NAME_ANavigationLoadTest_OnTestCompleted);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_ANavigationLoadTest_OnTestCompleted_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Navigation Test" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FinalStats_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_FinalStats;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ANavigationLoadTest_OnTestCompleted_Statics::NewProp_FinalStats = { "FinalStats", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NavigationLoadTest_eventOnTestCompleted_Parms, FinalStats), Z_Construct_UScriptStruct_FNavigationTestStats, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FinalStats_MetaData), NewProp_FinalStats_MetaData) }; // 3843661947
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANavigationLoadTest_OnTestCompleted_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANavigationLoadTest_OnTestCompleted_Statics::NewProp_FinalStats,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANavigationLoadTest_OnTestCompleted_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANavigationLoadTest_OnTestCompleted_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANavigationLoadTest, nullptr, "OnTestCompleted", nullptr, nullptr, Z_Construct_UFunction_ANavigationLoadTest_OnTestCompleted_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANavigationLoadTest_OnTestCompleted_Statics::PropPointers), sizeof(NavigationLoadTest_eventOnTestCompleted_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANavigationLoadTest_OnTestCompleted_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANavigationLoadTest_OnTestCompleted_Statics::Function_MetaDataParams) };
static_assert(sizeof(NavigationLoadTest_eventOnTestCompleted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ANavigationLoadTest_OnTestCompleted()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANavigationLoadTest_OnTestCompleted_Statics::FuncParams);
	}
	return ReturnFunction;
}
// End Class ANavigationLoadTest Function OnTestCompleted

// Begin Class ANavigationLoadTest Function PrintTestReport
struct Z_Construct_UFunction_ANavigationLoadTest_PrintTestReport_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Navigation Test" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANavigationLoadTest_PrintTestReport_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANavigationLoadTest, nullptr, "PrintTestReport", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANavigationLoadTest_PrintTestReport_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANavigationLoadTest_PrintTestReport_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ANavigationLoadTest_PrintTestReport()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANavigationLoadTest_PrintTestReport_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ANavigationLoadTest::execPrintTestReport)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->PrintTestReport();
	P_NATIVE_END;
}
// End Class ANavigationLoadTest Function PrintTestReport

// Begin Class ANavigationLoadTest Function RunMultipleCycles
struct Z_Construct_UFunction_ANavigationLoadTest_RunMultipleCycles_Statics
{
	struct NavigationLoadTest_eventRunMultipleCycles_Parms
	{
		int32 NumCycles;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Navigation Test" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_NumCycles;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ANavigationLoadTest_RunMultipleCycles_Statics::NewProp_NumCycles = { "NumCycles", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NavigationLoadTest_eventRunMultipleCycles_Parms, NumCycles), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANavigationLoadTest_RunMultipleCycles_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANavigationLoadTest_RunMultipleCycles_Statics::NewProp_NumCycles,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANavigationLoadTest_RunMultipleCycles_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANavigationLoadTest_RunMultipleCycles_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANavigationLoadTest, nullptr, "RunMultipleCycles", nullptr, nullptr, Z_Construct_UFunction_ANavigationLoadTest_RunMultipleCycles_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANavigationLoadTest_RunMultipleCycles_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANavigationLoadTest_RunMultipleCycles_Statics::NavigationLoadTest_eventRunMultipleCycles_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANavigationLoadTest_RunMultipleCycles_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANavigationLoadTest_RunMultipleCycles_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ANavigationLoadTest_RunMultipleCycles_Statics::NavigationLoadTest_eventRunMultipleCycles_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ANavigationLoadTest_RunMultipleCycles()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANavigationLoadTest_RunMultipleCycles_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ANavigationLoadTest::execRunMultipleCycles)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_NumCycles);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RunMultipleCycles(Z_Param_NumCycles);
	P_NATIVE_END;
}
// End Class ANavigationLoadTest Function RunMultipleCycles

// Begin Class ANavigationLoadTest Function RunSingleCycle
struct Z_Construct_UFunction_ANavigationLoadTest_RunSingleCycle_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Navigation Test" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANavigationLoadTest_RunSingleCycle_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANavigationLoadTest, nullptr, "RunSingleCycle", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANavigationLoadTest_RunSingleCycle_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANavigationLoadTest_RunSingleCycle_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ANavigationLoadTest_RunSingleCycle()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANavigationLoadTest_RunSingleCycle_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ANavigationLoadTest::execRunSingleCycle)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RunSingleCycle();
	P_NATIVE_END;
}
// End Class ANavigationLoadTest Function RunSingleCycle

// Begin Class ANavigationLoadTest Function SaveTestResults
struct Z_Construct_UFunction_ANavigationLoadTest_SaveTestResults_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Navigation Test" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANavigationLoadTest_SaveTestResults_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANavigationLoadTest, nullptr, "SaveTestResults", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANavigationLoadTest_SaveTestResults_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANavigationLoadTest_SaveTestResults_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ANavigationLoadTest_SaveTestResults()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANavigationLoadTest_SaveTestResults_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ANavigationLoadTest::execSaveTestResults)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SaveTestResults();
	P_NATIVE_END;
}
// End Class ANavigationLoadTest Function SaveTestResults

// Begin Class ANavigationLoadTest Function SimulatePlayerMovement
struct Z_Construct_UFunction_ANavigationLoadTest_SimulatePlayerMovement_Statics
{
	struct NavigationLoadTest_eventSimulatePlayerMovement_Parms
	{
		TArray<FVector> Path;
		float Speed;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Navigation Test" },
		{ "CPP_Default_Speed", "600.000000" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Path_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Path_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Path;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Speed;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ANavigationLoadTest_SimulatePlayerMovement_Statics::NewProp_Path_Inner = { "Path", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ANavigationLoadTest_SimulatePlayerMovement_Statics::NewProp_Path = { "Path", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NavigationLoadTest_eventSimulatePlayerMovement_Parms, Path), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Path_MetaData), NewProp_Path_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ANavigationLoadTest_SimulatePlayerMovement_Statics::NewProp_Speed = { "Speed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NavigationLoadTest_eventSimulatePlayerMovement_Parms, Speed), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_ANavigationLoadTest_SimulatePlayerMovement_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((NavigationLoadTest_eventSimulatePlayerMovement_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ANavigationLoadTest_SimulatePlayerMovement_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(NavigationLoadTest_eventSimulatePlayerMovement_Parms), &Z_Construct_UFunction_ANavigationLoadTest_SimulatePlayerMovement_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANavigationLoadTest_SimulatePlayerMovement_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANavigationLoadTest_SimulatePlayerMovement_Statics::NewProp_Path_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANavigationLoadTest_SimulatePlayerMovement_Statics::NewProp_Path,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANavigationLoadTest_SimulatePlayerMovement_Statics::NewProp_Speed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANavigationLoadTest_SimulatePlayerMovement_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANavigationLoadTest_SimulatePlayerMovement_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANavigationLoadTest_SimulatePlayerMovement_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANavigationLoadTest, nullptr, "SimulatePlayerMovement", nullptr, nullptr, Z_Construct_UFunction_ANavigationLoadTest_SimulatePlayerMovement_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANavigationLoadTest_SimulatePlayerMovement_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANavigationLoadTest_SimulatePlayerMovement_Statics::NavigationLoadTest_eventSimulatePlayerMovement_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANavigationLoadTest_SimulatePlayerMovement_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANavigationLoadTest_SimulatePlayerMovement_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ANavigationLoadTest_SimulatePlayerMovement_Statics::NavigationLoadTest_eventSimulatePlayerMovement_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ANavigationLoadTest_SimulatePlayerMovement()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANavigationLoadTest_SimulatePlayerMovement_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ANavigationLoadTest::execSimulatePlayerMovement)
{
	P_GET_TARRAY_REF(FVector,Z_Param_Out_Path);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Speed);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->SimulatePlayerMovement(Z_Param_Out_Path,Z_Param_Speed);
	P_NATIVE_END;
}
// End Class ANavigationLoadTest Function SimulatePlayerMovement

// Begin Class ANavigationLoadTest Function StartNavigationTest
struct Z_Construct_UFunction_ANavigationLoadTest_StartNavigationTest_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Navigation Test" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Core Test Functions\n" },
#endif
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Core Test Functions" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANavigationLoadTest_StartNavigationTest_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANavigationLoadTest, nullptr, "StartNavigationTest", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANavigationLoadTest_StartNavigationTest_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANavigationLoadTest_StartNavigationTest_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ANavigationLoadTest_StartNavigationTest()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANavigationLoadTest_StartNavigationTest_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ANavigationLoadTest::execStartNavigationTest)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StartNavigationTest();
	P_NATIVE_END;
}
// End Class ANavigationLoadTest Function StartNavigationTest

// Begin Class ANavigationLoadTest Function StopNavigationTest
struct Z_Construct_UFunction_ANavigationLoadTest_StopNavigationTest_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Navigation Test" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANavigationLoadTest_StopNavigationTest_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANavigationLoadTest, nullptr, "StopNavigationTest", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANavigationLoadTest_StopNavigationTest_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANavigationLoadTest_StopNavigationTest_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ANavigationLoadTest_StopNavigationTest()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANavigationLoadTest_StopNavigationTest_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ANavigationLoadTest::execStopNavigationTest)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StopNavigationTest();
	P_NATIVE_END;
}
// End Class ANavigationLoadTest Function StopNavigationTest

// Begin Class ANavigationLoadTest Function StressTestNavigation
struct Z_Construct_UFunction_ANavigationLoadTest_StressTestNavigation_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Navigation Test" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANavigationLoadTest_StressTestNavigation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANavigationLoadTest, nullptr, "StressTestNavigation", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANavigationLoadTest_StressTestNavigation_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANavigationLoadTest_StressTestNavigation_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ANavigationLoadTest_StressTestNavigation()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANavigationLoadTest_StressTestNavigation_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ANavigationLoadTest::execStressTestNavigation)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StressTestNavigation();
	P_NATIVE_END;
}
// End Class ANavigationLoadTest Function StressTestNavigation

// Begin Class ANavigationLoadTest Function TestMemoryLeaks
struct Z_Construct_UFunction_ANavigationLoadTest_TestMemoryLeaks_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Navigation Test" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Testing Functions\n" },
#endif
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Testing Functions" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANavigationLoadTest_TestMemoryLeaks_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANavigationLoadTest, nullptr, "TestMemoryLeaks", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANavigationLoadTest_TestMemoryLeaks_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANavigationLoadTest_TestMemoryLeaks_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ANavigationLoadTest_TestMemoryLeaks()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANavigationLoadTest_TestMemoryLeaks_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ANavigationLoadTest::execTestMemoryLeaks)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->TestMemoryLeaks();
	P_NATIVE_END;
}
// End Class ANavigationLoadTest Function TestMemoryLeaks

// Begin Class ANavigationLoadTest Function TestPathfindingPerformance
struct Z_Construct_UFunction_ANavigationLoadTest_TestPathfindingPerformance_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Navigation Test" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANavigationLoadTest_TestPathfindingPerformance_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANavigationLoadTest, nullptr, "TestPathfindingPerformance", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANavigationLoadTest_TestPathfindingPerformance_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANavigationLoadTest_TestPathfindingPerformance_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ANavigationLoadTest_TestPathfindingPerformance()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANavigationLoadTest_TestPathfindingPerformance_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ANavigationLoadTest::execTestPathfindingPerformance)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->TestPathfindingPerformance();
	P_NATIVE_END;
}
// End Class ANavigationLoadTest Function TestPathfindingPerformance

// Begin Class ANavigationLoadTest Function UnloadDungeon
struct Z_Construct_UFunction_ANavigationLoadTest_UnloadDungeon_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Navigation Test" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANavigationLoadTest_UnloadDungeon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANavigationLoadTest, nullptr, "UnloadDungeon", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANavigationLoadTest_UnloadDungeon_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANavigationLoadTest_UnloadDungeon_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ANavigationLoadTest_UnloadDungeon()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANavigationLoadTest_UnloadDungeon_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ANavigationLoadTest::execUnloadDungeon)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UnloadDungeon();
	P_NATIVE_END;
}
// End Class ANavigationLoadTest Function UnloadDungeon

// Begin Class ANavigationLoadTest
void ANavigationLoadTest::StaticRegisterNativesANavigationLoadTest()
{
	UClass* Class = ANavigationLoadTest::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ClearAllMemory", &ANavigationLoadTest::execClearAllMemory },
		{ "FindPathBetweenRooms", &ANavigationLoadTest::execFindPathBetweenRooms },
		{ "GetTestStats", &ANavigationLoadTest::execGetTestStats },
		{ "LoadDungeon", &ANavigationLoadTest::execLoadDungeon },
		{ "NavigateFromStartToExit", &ANavigationLoadTest::execNavigateFromStartToExit },
		{ "PrintTestReport", &ANavigationLoadTest::execPrintTestReport },
		{ "RunMultipleCycles", &ANavigationLoadTest::execRunMultipleCycles },
		{ "RunSingleCycle", &ANavigationLoadTest::execRunSingleCycle },
		{ "SaveTestResults", &ANavigationLoadTest::execSaveTestResults },
		{ "SimulatePlayerMovement", &ANavigationLoadTest::execSimulatePlayerMovement },
		{ "StartNavigationTest", &ANavigationLoadTest::execStartNavigationTest },
		{ "StopNavigationTest", &ANavigationLoadTest::execStopNavigationTest },
		{ "StressTestNavigation", &ANavigationLoadTest::execStressTestNavigation },
		{ "TestMemoryLeaks", &ANavigationLoadTest::execTestMemoryLeaks },
		{ "TestPathfindingPerformance", &ANavigationLoadTest::execTestPathfindingPerformance },
		{ "UnloadDungeon", &ANavigationLoadTest::execUnloadDungeon },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ANavigationLoadTest);
UClass* Z_Construct_UClass_ANavigationLoadTest_NoRegister()
{
	return ANavigationLoadTest::StaticClass();
}
struct Z_Construct_UClass_ANavigationLoadTest_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "NavigationLoadTest.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxCyclesToRun_MetaData[] = {
		{ "Category", "Configuration" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Configuration\n" },
#endif
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Configuration" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutoStartTest_MetaData[] = {
		{ "Category", "Configuration" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DelayBetweenCycles_MetaData[] = {
		{ "Category", "Configuration" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bVisualizeNavigation_MetaData[] = {
		{ "Category", "Configuration" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSimulateMovement_MetaData[] = {
		{ "Category", "Configuration" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SimulatedPlayerSpeed_MetaData[] = {
		{ "Category", "Configuration" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bLogDetailedInfo_MetaData[] = {
		{ "Category", "Configuration" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Units per second\n" },
#endif
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Units per second" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxMemoryMB_MetaData[] = {
		{ "Category", "Performance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Performance Limits\n" },
#endif
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Performance Limits" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinAcceptableFPS_MetaData[] = {
		{ "Category", "Performance" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MemoryLeakThresholdMB_MetaData[] = {
		{ "Category", "Performance" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bStopOnMemoryLeak_MetaData[] = {
		{ "Category", "Performance" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bStopOnPathFailure_MetaData[] = {
		{ "Category", "Performance" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DungeonVisualizer_MetaData[] = {
		{ "Category", "References" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// References\n" },
#endif
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "References" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentCycle_MetaData[] = {
		{ "Category", "Runtime" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Runtime Data\n" },
#endif
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Runtime Data" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsTestRunning_MetaData[] = {
		{ "Category", "Runtime" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentLayout_MetaData[] = {
		{ "Category", "Runtime" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CycleResults_MetaData[] = {
		{ "Category", "Runtime" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TestStats_MetaData[] = {
		{ "Category", "Runtime" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentPath_MetaData[] = {
		{ "Category", "Runtime" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StartRoomLocation_MetaData[] = {
		{ "Category", "Runtime" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExitRoomLocation_MetaData[] = {
		{ "Category", "Runtime" },
		{ "ModuleRelativePath", "Public/NavigationLoadTest.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxCyclesToRun;
	static void NewProp_bAutoStartTest_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoStartTest;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DelayBetweenCycles;
	static void NewProp_bVisualizeNavigation_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bVisualizeNavigation;
	static void NewProp_bSimulateMovement_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSimulateMovement;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SimulatedPlayerSpeed;
	static void NewProp_bLogDetailedInfo_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bLogDetailedInfo;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxMemoryMB;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MinAcceptableFPS;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MemoryLeakThresholdMB;
	static void NewProp_bStopOnMemoryLeak_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bStopOnMemoryLeak;
	static void NewProp_bStopOnPathFailure_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bStopOnPathFailure;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DungeonVisualizer;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentCycle;
	static void NewProp_bIsTestRunning_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsTestRunning;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CurrentLayout;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CycleResults_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_CycleResults;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TestStats;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CurrentPath_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_CurrentPath;
	static const UECodeGen_Private::FStructPropertyParams NewProp_StartRoomLocation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ExitRoomLocation;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ANavigationLoadTest_ClearAllMemory, "ClearAllMemory" }, // 634480924
		{ &Z_Construct_UFunction_ANavigationLoadTest_FindPathBetweenRooms, "FindPathBetweenRooms" }, // 4215134017
		{ &Z_Construct_UFunction_ANavigationLoadTest_GetTestStats, "GetTestStats" }, // 253456740
		{ &Z_Construct_UFunction_ANavigationLoadTest_LoadDungeon, "LoadDungeon" }, // 1031056573
		{ &Z_Construct_UFunction_ANavigationLoadTest_NavigateFromStartToExit, "NavigateFromStartToExit" }, // 2353045536
		{ &Z_Construct_UFunction_ANavigationLoadTest_OnCycleCompleted, "OnCycleCompleted" }, // 574763806
		{ &Z_Construct_UFunction_ANavigationLoadTest_OnPathVisualization, "OnPathVisualization" }, // 3317834347
		{ &Z_Construct_UFunction_ANavigationLoadTest_OnTestCompleted, "OnTestCompleted" }, // 976260775
		{ &Z_Construct_UFunction_ANavigationLoadTest_PrintTestReport, "PrintTestReport" }, // 382388423
		{ &Z_Construct_UFunction_ANavigationLoadTest_RunMultipleCycles, "RunMultipleCycles" }, // 3478347669
		{ &Z_Construct_UFunction_ANavigationLoadTest_RunSingleCycle, "RunSingleCycle" }, // 2387100577
		{ &Z_Construct_UFunction_ANavigationLoadTest_SaveTestResults, "SaveTestResults" }, // 1965200333
		{ &Z_Construct_UFunction_ANavigationLoadTest_SimulatePlayerMovement, "SimulatePlayerMovement" }, // 3940880499
		{ &Z_Construct_UFunction_ANavigationLoadTest_StartNavigationTest, "StartNavigationTest" }, // 4257024615
		{ &Z_Construct_UFunction_ANavigationLoadTest_StopNavigationTest, "StopNavigationTest" }, // 614695273
		{ &Z_Construct_UFunction_ANavigationLoadTest_StressTestNavigation, "StressTestNavigation" }, // 706868575
		{ &Z_Construct_UFunction_ANavigationLoadTest_TestMemoryLeaks, "TestMemoryLeaks" }, // 2904776353
		{ &Z_Construct_UFunction_ANavigationLoadTest_TestPathfindingPerformance, "TestPathfindingPerformance" }, // 1773333523
		{ &Z_Construct_UFunction_ANavigationLoadTest_UnloadDungeon, "UnloadDungeon" }, // 1986384213
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ANavigationLoadTest>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_MaxCyclesToRun = { "MaxCyclesToRun", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANavigationLoadTest, MaxCyclesToRun), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxCyclesToRun_MetaData), NewProp_MaxCyclesToRun_MetaData) };
void Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_bAutoStartTest_SetBit(void* Obj)
{
	((ANavigationLoadTest*)Obj)->bAutoStartTest = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_bAutoStartTest = { "bAutoStartTest", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ANavigationLoadTest), &Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_bAutoStartTest_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutoStartTest_MetaData), NewProp_bAutoStartTest_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_DelayBetweenCycles = { "DelayBetweenCycles", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANavigationLoadTest, DelayBetweenCycles), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DelayBetweenCycles_MetaData), NewProp_DelayBetweenCycles_MetaData) };
void Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_bVisualizeNavigation_SetBit(void* Obj)
{
	((ANavigationLoadTest*)Obj)->bVisualizeNavigation = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_bVisualizeNavigation = { "bVisualizeNavigation", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ANavigationLoadTest), &Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_bVisualizeNavigation_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bVisualizeNavigation_MetaData), NewProp_bVisualizeNavigation_MetaData) };
void Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_bSimulateMovement_SetBit(void* Obj)
{
	((ANavigationLoadTest*)Obj)->bSimulateMovement = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_bSimulateMovement = { "bSimulateMovement", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ANavigationLoadTest), &Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_bSimulateMovement_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSimulateMovement_MetaData), NewProp_bSimulateMovement_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_SimulatedPlayerSpeed = { "SimulatedPlayerSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANavigationLoadTest, SimulatedPlayerSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SimulatedPlayerSpeed_MetaData), NewProp_SimulatedPlayerSpeed_MetaData) };
void Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_bLogDetailedInfo_SetBit(void* Obj)
{
	((ANavigationLoadTest*)Obj)->bLogDetailedInfo = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_bLogDetailedInfo = { "bLogDetailedInfo", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ANavigationLoadTest), &Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_bLogDetailedInfo_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bLogDetailedInfo_MetaData), NewProp_bLogDetailedInfo_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_MaxMemoryMB = { "MaxMemoryMB", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANavigationLoadTest, MaxMemoryMB), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxMemoryMB_MetaData), NewProp_MaxMemoryMB_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_MinAcceptableFPS = { "MinAcceptableFPS", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANavigationLoadTest, MinAcceptableFPS), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinAcceptableFPS_MetaData), NewProp_MinAcceptableFPS_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_MemoryLeakThresholdMB = { "MemoryLeakThresholdMB", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANavigationLoadTest, MemoryLeakThresholdMB), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MemoryLeakThresholdMB_MetaData), NewProp_MemoryLeakThresholdMB_MetaData) };
void Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_bStopOnMemoryLeak_SetBit(void* Obj)
{
	((ANavigationLoadTest*)Obj)->bStopOnMemoryLeak = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_bStopOnMemoryLeak = { "bStopOnMemoryLeak", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ANavigationLoadTest), &Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_bStopOnMemoryLeak_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bStopOnMemoryLeak_MetaData), NewProp_bStopOnMemoryLeak_MetaData) };
void Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_bStopOnPathFailure_SetBit(void* Obj)
{
	((ANavigationLoadTest*)Obj)->bStopOnPathFailure = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_bStopOnPathFailure = { "bStopOnPathFailure", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ANavigationLoadTest), &Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_bStopOnPathFailure_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bStopOnPathFailure_MetaData), NewProp_bStopOnPathFailure_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_DungeonVisualizer = { "DungeonVisualizer", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANavigationLoadTest, DungeonVisualizer), Z_Construct_UClass_AGridDungeonVisualizer_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DungeonVisualizer_MetaData), NewProp_DungeonVisualizer_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_CurrentCycle = { "CurrentCycle", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANavigationLoadTest, CurrentCycle), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentCycle_MetaData), NewProp_CurrentCycle_MetaData) };
void Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_bIsTestRunning_SetBit(void* Obj)
{
	((ANavigationLoadTest*)Obj)->bIsTestRunning = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_bIsTestRunning = { "bIsTestRunning", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ANavigationLoadTest), &Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_bIsTestRunning_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsTestRunning_MetaData), NewProp_bIsTestRunning_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_CurrentLayout = { "CurrentLayout", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANavigationLoadTest, CurrentLayout), Z_Construct_UScriptStruct_FDungeonLayout, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentLayout_MetaData), NewProp_CurrentLayout_MetaData) }; // 3903890264
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_CycleResults_Inner = { "CycleResults", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FNavigationTestResult, METADATA_PARAMS(0, nullptr) }; // 1839902008
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_CycleResults = { "CycleResults", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANavigationLoadTest, CycleResults), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CycleResults_MetaData), NewProp_CycleResults_MetaData) }; // 1839902008
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_TestStats = { "TestStats", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANavigationLoadTest, TestStats), Z_Construct_UScriptStruct_FNavigationTestStats, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TestStats_MetaData), NewProp_TestStats_MetaData) }; // 3843661947
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_CurrentPath_Inner = { "CurrentPath", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_CurrentPath = { "CurrentPath", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANavigationLoadTest, CurrentPath), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentPath_MetaData), NewProp_CurrentPath_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_StartRoomLocation = { "StartRoomLocation", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANavigationLoadTest, StartRoomLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StartRoomLocation_MetaData), NewProp_StartRoomLocation_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_ExitRoomLocation = { "ExitRoomLocation", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANavigationLoadTest, ExitRoomLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExitRoomLocation_MetaData), NewProp_ExitRoomLocation_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ANavigationLoadTest_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_MaxCyclesToRun,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_bAutoStartTest,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_DelayBetweenCycles,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_bVisualizeNavigation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_bSimulateMovement,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_SimulatedPlayerSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_bLogDetailedInfo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_MaxMemoryMB,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_MinAcceptableFPS,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_MemoryLeakThresholdMB,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_bStopOnMemoryLeak,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_bStopOnPathFailure,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_DungeonVisualizer,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_CurrentCycle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_bIsTestRunning,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_CurrentLayout,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_CycleResults_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_CycleResults,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_TestStats,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_CurrentPath_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_CurrentPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_StartRoomLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANavigationLoadTest_Statics::NewProp_ExitRoomLocation,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANavigationLoadTest_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ANavigationLoadTest_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_EternalDescent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANavigationLoadTest_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ANavigationLoadTest_Statics::ClassParams = {
	&ANavigationLoadTest::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ANavigationLoadTest_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ANavigationLoadTest_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANavigationLoadTest_Statics::Class_MetaDataParams), Z_Construct_UClass_ANavigationLoadTest_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ANavigationLoadTest()
{
	if (!Z_Registration_Info_UClass_ANavigationLoadTest.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ANavigationLoadTest.OuterSingleton, Z_Construct_UClass_ANavigationLoadTest_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ANavigationLoadTest.OuterSingleton;
}
template<> ETERNALDESCENT_API UClass* StaticClass<ANavigationLoadTest>()
{
	return ANavigationLoadTest::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ANavigationLoadTest);
ANavigationLoadTest::~ANavigationLoadTest() {}
// End Class ANavigationLoadTest

// Begin Registration
struct Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_NavigationLoadTest_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FNavigationTestResult::StaticStruct, Z_Construct_UScriptStruct_FNavigationTestResult_Statics::NewStructOps, TEXT("NavigationTestResult"), &Z_Registration_Info_UScriptStruct_NavigationTestResult, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FNavigationTestResult), 1839902008U) },
		{ FNavigationTestStats::StaticStruct, Z_Construct_UScriptStruct_FNavigationTestStats_Statics::NewStructOps, TEXT("NavigationTestStats"), &Z_Registration_Info_UScriptStruct_NavigationTestStats, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FNavigationTestStats), 3843661947U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ANavigationLoadTest, ANavigationLoadTest::StaticClass, TEXT("ANavigationLoadTest"), &Z_Registration_Info_UClass_ANavigationLoadTest, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ANavigationLoadTest), 1869673255U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_NavigationLoadTest_h_2003252362(TEXT("/Script/EternalDescent"),
	Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_NavigationLoadTest_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_NavigationLoadTest_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_NavigationLoadTest_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_NavigationLoadTest_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
