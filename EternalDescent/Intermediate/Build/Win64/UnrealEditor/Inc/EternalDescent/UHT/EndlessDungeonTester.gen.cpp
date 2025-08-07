// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EternalDescent/Public/EndlessDungeonTester.h"
#include "EternalDescent/Public/Tests/DungeonTestTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEndlessDungeonTester() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
ETERNALDESCENT_API UClass* Z_Construct_UClass_AADASystem_NoRegister();
ETERNALDESCENT_API UClass* Z_Construct_UClass_AEndlessDungeonTester();
ETERNALDESCENT_API UClass* Z_Construct_UClass_AEndlessDungeonTester_NoRegister();
ETERNALDESCENT_API UClass* Z_Construct_UClass_AGridDungeonVisualizer_NoRegister();
ETERNALDESCENT_API UScriptStruct* Z_Construct_UScriptStruct_FDungeonLayout();
ETERNALDESCENT_API UScriptStruct* Z_Construct_UScriptStruct_FEndlessTestStats();
ETERNALDESCENT_API UScriptStruct* Z_Construct_UScriptStruct_FStageGenerationResult();
UPackage* Z_Construct_UPackage__Script_EternalDescent();
// End Cross Module References

// Begin ScriptStruct FStageGenerationResult
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_StageGenerationResult;
class UScriptStruct* FStageGenerationResult::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_StageGenerationResult.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_StageGenerationResult.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FStageGenerationResult, (UObject*)Z_Construct_UPackage__Script_EternalDescent(), TEXT("StageGenerationResult"));
	}
	return Z_Registration_Info_UScriptStruct_StageGenerationResult.OuterSingleton;
}
template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<FStageGenerationResult>()
{
	return FStageGenerationResult::StaticStruct();
}
struct Z_Construct_UScriptStruct_FStageGenerationResult_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StageNumber_MetaData[] = {
		{ "Category", "StageGenerationResult" },
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSuccess_MetaData[] = {
		{ "Category", "StageGenerationResult" },
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoomCount_MetaData[] = {
		{ "Category", "StageGenerationResult" },
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GenerationTime_MetaData[] = {
		{ "Category", "StageGenerationResult" },
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalEnemies_MetaData[] = {
		{ "Category", "StageGenerationResult" },
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalChests_MetaData[] = {
		{ "Category", "StageGenerationResult" },
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FailureReason_MetaData[] = {
		{ "Category", "StageGenerationResult" },
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_StageNumber;
	static void NewProp_bSuccess_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
	static const UECodeGen_Private::FIntPropertyParams NewProp_RoomCount;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GenerationTime;
	static const UECodeGen_Private::FIntPropertyParams NewProp_TotalEnemies;
	static const UECodeGen_Private::FIntPropertyParams NewProp_TotalChests;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FailureReason;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FStageGenerationResult>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FStageGenerationResult_Statics::NewProp_StageNumber = { "StageNumber", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStageGenerationResult, StageNumber), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StageNumber_MetaData), NewProp_StageNumber_MetaData) };
void Z_Construct_UScriptStruct_FStageGenerationResult_Statics::NewProp_bSuccess_SetBit(void* Obj)
{
	((FStageGenerationResult*)Obj)->bSuccess = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FStageGenerationResult_Statics::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FStageGenerationResult), &Z_Construct_UScriptStruct_FStageGenerationResult_Statics::NewProp_bSuccess_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSuccess_MetaData), NewProp_bSuccess_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FStageGenerationResult_Statics::NewProp_RoomCount = { "RoomCount", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStageGenerationResult, RoomCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoomCount_MetaData), NewProp_RoomCount_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FStageGenerationResult_Statics::NewProp_GenerationTime = { "GenerationTime", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStageGenerationResult, GenerationTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GenerationTime_MetaData), NewProp_GenerationTime_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FStageGenerationResult_Statics::NewProp_TotalEnemies = { "TotalEnemies", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStageGenerationResult, TotalEnemies), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalEnemies_MetaData), NewProp_TotalEnemies_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FStageGenerationResult_Statics::NewProp_TotalChests = { "TotalChests", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStageGenerationResult, TotalChests), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalChests_MetaData), NewProp_TotalChests_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FStageGenerationResult_Statics::NewProp_FailureReason = { "FailureReason", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStageGenerationResult, FailureReason), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FailureReason_MetaData), NewProp_FailureReason_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FStageGenerationResult_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStageGenerationResult_Statics::NewProp_StageNumber,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStageGenerationResult_Statics::NewProp_bSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStageGenerationResult_Statics::NewProp_RoomCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStageGenerationResult_Statics::NewProp_GenerationTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStageGenerationResult_Statics::NewProp_TotalEnemies,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStageGenerationResult_Statics::NewProp_TotalChests,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStageGenerationResult_Statics::NewProp_FailureReason,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStageGenerationResult_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FStageGenerationResult_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_EternalDescent,
	nullptr,
	&NewStructOps,
	"StageGenerationResult",
	Z_Construct_UScriptStruct_FStageGenerationResult_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStageGenerationResult_Statics::PropPointers),
	sizeof(FStageGenerationResult),
	alignof(FStageGenerationResult),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStageGenerationResult_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FStageGenerationResult_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FStageGenerationResult()
{
	if (!Z_Registration_Info_UScriptStruct_StageGenerationResult.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_StageGenerationResult.InnerSingleton, Z_Construct_UScriptStruct_FStageGenerationResult_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_StageGenerationResult.InnerSingleton;
}
// End ScriptStruct FStageGenerationResult

// Begin ScriptStruct FEndlessTestStats
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_EndlessTestStats;
class UScriptStruct* FEndlessTestStats::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_EndlessTestStats.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_EndlessTestStats.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FEndlessTestStats, (UObject*)Z_Construct_UPackage__Script_EternalDescent(), TEXT("EndlessTestStats"));
	}
	return Z_Registration_Info_UScriptStruct_EndlessTestStats.OuterSingleton;
}
template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<FEndlessTestStats>()
{
	return FEndlessTestStats::StaticStruct();
}
struct Z_Construct_UScriptStruct_FEndlessTestStats_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalStagesGenerated_MetaData[] = {
		{ "Category", "EndlessTestStats" },
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalRoomsGenerated_MetaData[] = {
		{ "Category", "EndlessTestStats" },
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalEnemiesSpawned_MetaData[] = {
		{ "Category", "EndlessTestStats" },
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalChestsSpawned_MetaData[] = {
		{ "Category", "EndlessTestStats" },
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalGenerationTime_MetaData[] = {
		{ "Category", "EndlessTestStats" },
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AverageGenerationTime_MetaData[] = {
		{ "Category", "EndlessTestStats" },
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LargestStage_MetaData[] = {
		{ "Category", "EndlessTestStats" },
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SmallestStage_MetaData[] = {
		{ "Category", "EndlessTestStats" },
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentFPS_MetaData[] = {
		{ "Category", "EndlessTestStats" },
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LowestFPS_MetaData[] = {
		{ "Category", "EndlessTestStats" },
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentMemoryUsageMB_MetaData[] = {
		{ "Category", "EndlessTestStats" },
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PeakMemoryUsageMB_MetaData[] = {
		{ "Category", "EndlessTestStats" },
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_TotalStagesGenerated;
	static const UECodeGen_Private::FIntPropertyParams NewProp_TotalRoomsGenerated;
	static const UECodeGen_Private::FIntPropertyParams NewProp_TotalEnemiesSpawned;
	static const UECodeGen_Private::FIntPropertyParams NewProp_TotalChestsSpawned;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TotalGenerationTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AverageGenerationTime;
	static const UECodeGen_Private::FIntPropertyParams NewProp_LargestStage;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SmallestStage;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentFPS;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LowestFPS;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentMemoryUsageMB;
	static const UECodeGen_Private::FIntPropertyParams NewProp_PeakMemoryUsageMB;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FEndlessTestStats>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FEndlessTestStats_Statics::NewProp_TotalStagesGenerated = { "TotalStagesGenerated", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEndlessTestStats, TotalStagesGenerated), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalStagesGenerated_MetaData), NewProp_TotalStagesGenerated_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FEndlessTestStats_Statics::NewProp_TotalRoomsGenerated = { "TotalRoomsGenerated", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEndlessTestStats, TotalRoomsGenerated), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalRoomsGenerated_MetaData), NewProp_TotalRoomsGenerated_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FEndlessTestStats_Statics::NewProp_TotalEnemiesSpawned = { "TotalEnemiesSpawned", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEndlessTestStats, TotalEnemiesSpawned), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalEnemiesSpawned_MetaData), NewProp_TotalEnemiesSpawned_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FEndlessTestStats_Statics::NewProp_TotalChestsSpawned = { "TotalChestsSpawned", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEndlessTestStats, TotalChestsSpawned), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalChestsSpawned_MetaData), NewProp_TotalChestsSpawned_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FEndlessTestStats_Statics::NewProp_TotalGenerationTime = { "TotalGenerationTime", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEndlessTestStats, TotalGenerationTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalGenerationTime_MetaData), NewProp_TotalGenerationTime_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FEndlessTestStats_Statics::NewProp_AverageGenerationTime = { "AverageGenerationTime", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEndlessTestStats, AverageGenerationTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AverageGenerationTime_MetaData), NewProp_AverageGenerationTime_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FEndlessTestStats_Statics::NewProp_LargestStage = { "LargestStage", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEndlessTestStats, LargestStage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LargestStage_MetaData), NewProp_LargestStage_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FEndlessTestStats_Statics::NewProp_SmallestStage = { "SmallestStage", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEndlessTestStats, SmallestStage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SmallestStage_MetaData), NewProp_SmallestStage_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FEndlessTestStats_Statics::NewProp_CurrentFPS = { "CurrentFPS", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEndlessTestStats, CurrentFPS), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentFPS_MetaData), NewProp_CurrentFPS_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FEndlessTestStats_Statics::NewProp_LowestFPS = { "LowestFPS", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEndlessTestStats, LowestFPS), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LowestFPS_MetaData), NewProp_LowestFPS_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FEndlessTestStats_Statics::NewProp_CurrentMemoryUsageMB = { "CurrentMemoryUsageMB", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEndlessTestStats, CurrentMemoryUsageMB), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentMemoryUsageMB_MetaData), NewProp_CurrentMemoryUsageMB_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FEndlessTestStats_Statics::NewProp_PeakMemoryUsageMB = { "PeakMemoryUsageMB", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEndlessTestStats, PeakMemoryUsageMB), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PeakMemoryUsageMB_MetaData), NewProp_PeakMemoryUsageMB_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FEndlessTestStats_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEndlessTestStats_Statics::NewProp_TotalStagesGenerated,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEndlessTestStats_Statics::NewProp_TotalRoomsGenerated,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEndlessTestStats_Statics::NewProp_TotalEnemiesSpawned,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEndlessTestStats_Statics::NewProp_TotalChestsSpawned,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEndlessTestStats_Statics::NewProp_TotalGenerationTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEndlessTestStats_Statics::NewProp_AverageGenerationTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEndlessTestStats_Statics::NewProp_LargestStage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEndlessTestStats_Statics::NewProp_SmallestStage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEndlessTestStats_Statics::NewProp_CurrentFPS,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEndlessTestStats_Statics::NewProp_LowestFPS,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEndlessTestStats_Statics::NewProp_CurrentMemoryUsageMB,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEndlessTestStats_Statics::NewProp_PeakMemoryUsageMB,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEndlessTestStats_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FEndlessTestStats_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_EternalDescent,
	nullptr,
	&NewStructOps,
	"EndlessTestStats",
	Z_Construct_UScriptStruct_FEndlessTestStats_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEndlessTestStats_Statics::PropPointers),
	sizeof(FEndlessTestStats),
	alignof(FEndlessTestStats),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEndlessTestStats_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FEndlessTestStats_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FEndlessTestStats()
{
	if (!Z_Registration_Info_UScriptStruct_EndlessTestStats.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_EndlessTestStats.InnerSingleton, Z_Construct_UScriptStruct_FEndlessTestStats_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_EndlessTestStats.InnerSingleton;
}
// End ScriptStruct FEndlessTestStats

// Begin Class AEndlessDungeonTester Function ClearCurrentStage
struct Z_Construct_UFunction_AEndlessDungeonTester_ClearCurrentStage_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Endless Test" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Stage Management\n" },
#endif
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Stage Management" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEndlessDungeonTester_ClearCurrentStage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEndlessDungeonTester, nullptr, "ClearCurrentStage", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEndlessDungeonTester_ClearCurrentStage_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEndlessDungeonTester_ClearCurrentStage_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AEndlessDungeonTester_ClearCurrentStage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEndlessDungeonTester_ClearCurrentStage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEndlessDungeonTester::execClearCurrentStage)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClearCurrentStage();
	P_NATIVE_END;
}
// End Class AEndlessDungeonTester Function ClearCurrentStage

// Begin Class AEndlessDungeonTester Function GenerateMaximumStages
struct Z_Construct_UFunction_AEndlessDungeonTester_GenerateMaximumStages_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Endless Test" },
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEndlessDungeonTester_GenerateMaximumStages_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEndlessDungeonTester, nullptr, "GenerateMaximumStages", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEndlessDungeonTester_GenerateMaximumStages_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEndlessDungeonTester_GenerateMaximumStages_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AEndlessDungeonTester_GenerateMaximumStages()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEndlessDungeonTester_GenerateMaximumStages_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEndlessDungeonTester::execGenerateMaximumStages)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->GenerateMaximumStages();
	P_NATIVE_END;
}
// End Class AEndlessDungeonTester Function GenerateMaximumStages

// Begin Class AEndlessDungeonTester Function GenerateMultipleStages
struct Z_Construct_UFunction_AEndlessDungeonTester_GenerateMultipleStages_Statics
{
	struct EndlessDungeonTester_eventGenerateMultipleStages_Parms
	{
		int32 Count;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Endless Test" },
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_Count;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AEndlessDungeonTester_GenerateMultipleStages_Statics::NewProp_Count = { "Count", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EndlessDungeonTester_eventGenerateMultipleStages_Parms, Count), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEndlessDungeonTester_GenerateMultipleStages_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEndlessDungeonTester_GenerateMultipleStages_Statics::NewProp_Count,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEndlessDungeonTester_GenerateMultipleStages_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEndlessDungeonTester_GenerateMultipleStages_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEndlessDungeonTester, nullptr, "GenerateMultipleStages", nullptr, nullptr, Z_Construct_UFunction_AEndlessDungeonTester_GenerateMultipleStages_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEndlessDungeonTester_GenerateMultipleStages_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEndlessDungeonTester_GenerateMultipleStages_Statics::EndlessDungeonTester_eventGenerateMultipleStages_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEndlessDungeonTester_GenerateMultipleStages_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEndlessDungeonTester_GenerateMultipleStages_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AEndlessDungeonTester_GenerateMultipleStages_Statics::EndlessDungeonTester_eventGenerateMultipleStages_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEndlessDungeonTester_GenerateMultipleStages()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEndlessDungeonTester_GenerateMultipleStages_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEndlessDungeonTester::execGenerateMultipleStages)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_Count);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->GenerateMultipleStages(Z_Param_Count);
	P_NATIVE_END;
}
// End Class AEndlessDungeonTester Function GenerateMultipleStages

// Begin Class AEndlessDungeonTester Function GenerateNextStage
struct Z_Construct_UFunction_AEndlessDungeonTester_GenerateNextStage_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Endless Test" },
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEndlessDungeonTester_GenerateNextStage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEndlessDungeonTester, nullptr, "GenerateNextStage", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEndlessDungeonTester_GenerateNextStage_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEndlessDungeonTester_GenerateNextStage_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AEndlessDungeonTester_GenerateNextStage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEndlessDungeonTester_GenerateNextStage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEndlessDungeonTester::execGenerateNextStage)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->GenerateNextStage();
	P_NATIVE_END;
}
// End Class AEndlessDungeonTester Function GenerateNextStage

// Begin Class AEndlessDungeonTester Function GetStageResult
struct Z_Construct_UFunction_AEndlessDungeonTester_GetStageResult_Statics
{
	struct EndlessDungeonTester_eventGetStageResult_Parms
	{
		int32 StageNumber;
		FStageGenerationResult ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Endless Test" },
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_StageNumber;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AEndlessDungeonTester_GetStageResult_Statics::NewProp_StageNumber = { "StageNumber", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EndlessDungeonTester_eventGetStageResult_Parms, StageNumber), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEndlessDungeonTester_GetStageResult_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EndlessDungeonTester_eventGetStageResult_Parms, ReturnValue), Z_Construct_UScriptStruct_FStageGenerationResult, METADATA_PARAMS(0, nullptr) }; // 1143632389
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEndlessDungeonTester_GetStageResult_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEndlessDungeonTester_GetStageResult_Statics::NewProp_StageNumber,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEndlessDungeonTester_GetStageResult_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEndlessDungeonTester_GetStageResult_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEndlessDungeonTester_GetStageResult_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEndlessDungeonTester, nullptr, "GetStageResult", nullptr, nullptr, Z_Construct_UFunction_AEndlessDungeonTester_GetStageResult_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEndlessDungeonTester_GetStageResult_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEndlessDungeonTester_GetStageResult_Statics::EndlessDungeonTester_eventGetStageResult_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEndlessDungeonTester_GetStageResult_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEndlessDungeonTester_GetStageResult_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AEndlessDungeonTester_GetStageResult_Statics::EndlessDungeonTester_eventGetStageResult_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEndlessDungeonTester_GetStageResult()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEndlessDungeonTester_GetStageResult_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEndlessDungeonTester::execGetStageResult)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_StageNumber);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FStageGenerationResult*)Z_Param__Result=P_THIS->GetStageResult(Z_Param_StageNumber);
	P_NATIVE_END;
}
// End Class AEndlessDungeonTester Function GetStageResult

// Begin Class AEndlessDungeonTester Function GetTestStats
struct Z_Construct_UFunction_AEndlessDungeonTester_GetTestStats_Statics
{
	struct EndlessDungeonTester_eventGetTestStats_Parms
	{
		FEndlessTestStats ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Endless Test" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Stats & Monitoring\n" },
#endif
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Stats & Monitoring" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEndlessDungeonTester_GetTestStats_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EndlessDungeonTester_eventGetTestStats_Parms, ReturnValue), Z_Construct_UScriptStruct_FEndlessTestStats, METADATA_PARAMS(0, nullptr) }; // 1990716653
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEndlessDungeonTester_GetTestStats_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEndlessDungeonTester_GetTestStats_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEndlessDungeonTester_GetTestStats_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEndlessDungeonTester_GetTestStats_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEndlessDungeonTester, nullptr, "GetTestStats", nullptr, nullptr, Z_Construct_UFunction_AEndlessDungeonTester_GetTestStats_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEndlessDungeonTester_GetTestStats_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEndlessDungeonTester_GetTestStats_Statics::EndlessDungeonTester_eventGetTestStats_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEndlessDungeonTester_GetTestStats_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEndlessDungeonTester_GetTestStats_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AEndlessDungeonTester_GetTestStats_Statics::EndlessDungeonTester_eventGetTestStats_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEndlessDungeonTester_GetTestStats()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEndlessDungeonTester_GetTestStats_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEndlessDungeonTester::execGetTestStats)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FEndlessTestStats*)Z_Param__Result=P_THIS->GetTestStats();
	P_NATIVE_END;
}
// End Class AEndlessDungeonTester Function GetTestStats

// Begin Class AEndlessDungeonTester Function OnStageGenerated
struct EndlessDungeonTester_eventOnStageGenerated_Parms
{
	FStageGenerationResult Result;
};
static const FName NAME_AEndlessDungeonTester_OnStageGenerated = FName(TEXT("OnStageGenerated"));
void AEndlessDungeonTester::OnStageGenerated(FStageGenerationResult const& Result)
{
	EndlessDungeonTester_eventOnStageGenerated_Parms Parms;
	Parms.Result=Result;
	UFunction* Func = FindFunctionChecked(NAME_AEndlessDungeonTester_OnStageGenerated);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AEndlessDungeonTester_OnStageGenerated_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Endless Test" },
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Result_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Result;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEndlessDungeonTester_OnStageGenerated_Statics::NewProp_Result = { "Result", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EndlessDungeonTester_eventOnStageGenerated_Parms, Result), Z_Construct_UScriptStruct_FStageGenerationResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Result_MetaData), NewProp_Result_MetaData) }; // 1143632389
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEndlessDungeonTester_OnStageGenerated_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEndlessDungeonTester_OnStageGenerated_Statics::NewProp_Result,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEndlessDungeonTester_OnStageGenerated_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEndlessDungeonTester_OnStageGenerated_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEndlessDungeonTester, nullptr, "OnStageGenerated", nullptr, nullptr, Z_Construct_UFunction_AEndlessDungeonTester_OnStageGenerated_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEndlessDungeonTester_OnStageGenerated_Statics::PropPointers), sizeof(EndlessDungeonTester_eventOnStageGenerated_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEndlessDungeonTester_OnStageGenerated_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEndlessDungeonTester_OnStageGenerated_Statics::Function_MetaDataParams) };
static_assert(sizeof(EndlessDungeonTester_eventOnStageGenerated_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEndlessDungeonTester_OnStageGenerated()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEndlessDungeonTester_OnStageGenerated_Statics::FuncParams);
	}
	return ReturnFunction;
}
// End Class AEndlessDungeonTester Function OnStageGenerated

// Begin Class AEndlessDungeonTester Function OnTestCompleted
struct EndlessDungeonTester_eventOnTestCompleted_Parms
{
	FEndlessTestStats FinalStats;
};
static const FName NAME_AEndlessDungeonTester_OnTestCompleted = FName(TEXT("OnTestCompleted"));
void AEndlessDungeonTester::OnTestCompleted(FEndlessTestStats const& FinalStats)
{
	EndlessDungeonTester_eventOnTestCompleted_Parms Parms;
	Parms.FinalStats=FinalStats;
	UFunction* Func = FindFunctionChecked(NAME_AEndlessDungeonTester_OnTestCompleted);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AEndlessDungeonTester_OnTestCompleted_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Endless Test" },
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FinalStats_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_FinalStats;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEndlessDungeonTester_OnTestCompleted_Statics::NewProp_FinalStats = { "FinalStats", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EndlessDungeonTester_eventOnTestCompleted_Parms, FinalStats), Z_Construct_UScriptStruct_FEndlessTestStats, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FinalStats_MetaData), NewProp_FinalStats_MetaData) }; // 1990716653
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEndlessDungeonTester_OnTestCompleted_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEndlessDungeonTester_OnTestCompleted_Statics::NewProp_FinalStats,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEndlessDungeonTester_OnTestCompleted_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEndlessDungeonTester_OnTestCompleted_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEndlessDungeonTester, nullptr, "OnTestCompleted", nullptr, nullptr, Z_Construct_UFunction_AEndlessDungeonTester_OnTestCompleted_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEndlessDungeonTester_OnTestCompleted_Statics::PropPointers), sizeof(EndlessDungeonTester_eventOnTestCompleted_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEndlessDungeonTester_OnTestCompleted_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEndlessDungeonTester_OnTestCompleted_Statics::Function_MetaDataParams) };
static_assert(sizeof(EndlessDungeonTester_eventOnTestCompleted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEndlessDungeonTester_OnTestCompleted()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEndlessDungeonTester_OnTestCompleted_Statics::FuncParams);
	}
	return ReturnFunction;
}
// End Class AEndlessDungeonTester Function OnTestCompleted

// Begin Class AEndlessDungeonTester Function PrintTestReport
struct Z_Construct_UFunction_AEndlessDungeonTester_PrintTestReport_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Endless Test" },
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEndlessDungeonTester_PrintTestReport_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEndlessDungeonTester, nullptr, "PrintTestReport", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEndlessDungeonTester_PrintTestReport_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEndlessDungeonTester_PrintTestReport_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AEndlessDungeonTester_PrintTestReport()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEndlessDungeonTester_PrintTestReport_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEndlessDungeonTester::execPrintTestReport)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->PrintTestReport();
	P_NATIVE_END;
}
// End Class AEndlessDungeonTester Function PrintTestReport

// Begin Class AEndlessDungeonTester Function RunStressTest
struct Z_Construct_UFunction_AEndlessDungeonTester_RunStressTest_Statics
{
	struct EndlessDungeonTester_eventRunStressTest_Parms
	{
		int32 MaxStages;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Endless Test" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Testing Functions\n" },
#endif
		{ "CPP_Default_MaxStages", "1000" },
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Testing Functions" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxStages;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AEndlessDungeonTester_RunStressTest_Statics::NewProp_MaxStages = { "MaxStages", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EndlessDungeonTester_eventRunStressTest_Parms, MaxStages), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEndlessDungeonTester_RunStressTest_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEndlessDungeonTester_RunStressTest_Statics::NewProp_MaxStages,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEndlessDungeonTester_RunStressTest_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEndlessDungeonTester_RunStressTest_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEndlessDungeonTester, nullptr, "RunStressTest", nullptr, nullptr, Z_Construct_UFunction_AEndlessDungeonTester_RunStressTest_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEndlessDungeonTester_RunStressTest_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEndlessDungeonTester_RunStressTest_Statics::EndlessDungeonTester_eventRunStressTest_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEndlessDungeonTester_RunStressTest_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEndlessDungeonTester_RunStressTest_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AEndlessDungeonTester_RunStressTest_Statics::EndlessDungeonTester_eventRunStressTest_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEndlessDungeonTester_RunStressTest()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEndlessDungeonTester_RunStressTest_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEndlessDungeonTester::execRunStressTest)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_MaxStages);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RunStressTest(Z_Param_MaxStages);
	P_NATIVE_END;
}
// End Class AEndlessDungeonTester Function RunStressTest

// Begin Class AEndlessDungeonTester Function SaveTestResults
struct Z_Construct_UFunction_AEndlessDungeonTester_SaveTestResults_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Endless Test" },
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEndlessDungeonTester_SaveTestResults_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEndlessDungeonTester, nullptr, "SaveTestResults", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEndlessDungeonTester_SaveTestResults_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEndlessDungeonTester_SaveTestResults_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AEndlessDungeonTester_SaveTestResults()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEndlessDungeonTester_SaveTestResults_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEndlessDungeonTester::execSaveTestResults)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SaveTestResults();
	P_NATIVE_END;
}
// End Class AEndlessDungeonTester Function SaveTestResults

// Begin Class AEndlessDungeonTester Function ShowAllStagesOverview
struct Z_Construct_UFunction_AEndlessDungeonTester_ShowAllStagesOverview_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Endless Test" },
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEndlessDungeonTester_ShowAllStagesOverview_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEndlessDungeonTester, nullptr, "ShowAllStagesOverview", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEndlessDungeonTester_ShowAllStagesOverview_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEndlessDungeonTester_ShowAllStagesOverview_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AEndlessDungeonTester_ShowAllStagesOverview()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEndlessDungeonTester_ShowAllStagesOverview_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEndlessDungeonTester::execShowAllStagesOverview)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ShowAllStagesOverview();
	P_NATIVE_END;
}
// End Class AEndlessDungeonTester Function ShowAllStagesOverview

// Begin Class AEndlessDungeonTester Function StartEndlessTest
struct Z_Construct_UFunction_AEndlessDungeonTester_StartEndlessTest_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Endless Test" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Core Testing Functions\n" },
#endif
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Core Testing Functions" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEndlessDungeonTester_StartEndlessTest_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEndlessDungeonTester, nullptr, "StartEndlessTest", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEndlessDungeonTester_StartEndlessTest_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEndlessDungeonTester_StartEndlessTest_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AEndlessDungeonTester_StartEndlessTest()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEndlessDungeonTester_StartEndlessTest_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEndlessDungeonTester::execStartEndlessTest)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StartEndlessTest();
	P_NATIVE_END;
}
// End Class AEndlessDungeonTester Function StartEndlessTest

// Begin Class AEndlessDungeonTester Function StopEndlessTest
struct Z_Construct_UFunction_AEndlessDungeonTester_StopEndlessTest_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Endless Test" },
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEndlessDungeonTester_StopEndlessTest_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEndlessDungeonTester, nullptr, "StopEndlessTest", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEndlessDungeonTester_StopEndlessTest_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEndlessDungeonTester_StopEndlessTest_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AEndlessDungeonTester_StopEndlessTest()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEndlessDungeonTester_StopEndlessTest_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEndlessDungeonTester::execStopEndlessTest)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StopEndlessTest();
	P_NATIVE_END;
}
// End Class AEndlessDungeonTester Function StopEndlessTest

// Begin Class AEndlessDungeonTester Function TestGenerationSpeed
struct Z_Construct_UFunction_AEndlessDungeonTester_TestGenerationSpeed_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Endless Test" },
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEndlessDungeonTester_TestGenerationSpeed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEndlessDungeonTester, nullptr, "TestGenerationSpeed", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEndlessDungeonTester_TestGenerationSpeed_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEndlessDungeonTester_TestGenerationSpeed_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AEndlessDungeonTester_TestGenerationSpeed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEndlessDungeonTester_TestGenerationSpeed_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEndlessDungeonTester::execTestGenerationSpeed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->TestGenerationSpeed();
	P_NATIVE_END;
}
// End Class AEndlessDungeonTester Function TestGenerationSpeed

// Begin Class AEndlessDungeonTester Function TestRoomScaling
struct Z_Construct_UFunction_AEndlessDungeonTester_TestRoomScaling_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Endless Test" },
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEndlessDungeonTester_TestRoomScaling_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEndlessDungeonTester, nullptr, "TestRoomScaling", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEndlessDungeonTester_TestRoomScaling_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEndlessDungeonTester_TestRoomScaling_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AEndlessDungeonTester_TestRoomScaling()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEndlessDungeonTester_TestRoomScaling_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEndlessDungeonTester::execTestRoomScaling)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->TestRoomScaling();
	P_NATIVE_END;
}
// End Class AEndlessDungeonTester Function TestRoomScaling

// Begin Class AEndlessDungeonTester Function TransitionToStage
struct Z_Construct_UFunction_AEndlessDungeonTester_TransitionToStage_Statics
{
	struct EndlessDungeonTester_eventTransitionToStage_Parms
	{
		int32 StageNumber;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Endless Test" },
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_StageNumber;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AEndlessDungeonTester_TransitionToStage_Statics::NewProp_StageNumber = { "StageNumber", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EndlessDungeonTester_eventTransitionToStage_Parms, StageNumber), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEndlessDungeonTester_TransitionToStage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEndlessDungeonTester_TransitionToStage_Statics::NewProp_StageNumber,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEndlessDungeonTester_TransitionToStage_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEndlessDungeonTester_TransitionToStage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEndlessDungeonTester, nullptr, "TransitionToStage", nullptr, nullptr, Z_Construct_UFunction_AEndlessDungeonTester_TransitionToStage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEndlessDungeonTester_TransitionToStage_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEndlessDungeonTester_TransitionToStage_Statics::EndlessDungeonTester_eventTransitionToStage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEndlessDungeonTester_TransitionToStage_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEndlessDungeonTester_TransitionToStage_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AEndlessDungeonTester_TransitionToStage_Statics::EndlessDungeonTester_eventTransitionToStage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEndlessDungeonTester_TransitionToStage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEndlessDungeonTester_TransitionToStage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEndlessDungeonTester::execTransitionToStage)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_StageNumber);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->TransitionToStage(Z_Param_StageNumber);
	P_NATIVE_END;
}
// End Class AEndlessDungeonTester Function TransitionToStage

// Begin Class AEndlessDungeonTester Function UpdatePerformanceMetrics
struct Z_Construct_UFunction_AEndlessDungeonTester_UpdatePerformanceMetrics_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Endless Test" },
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEndlessDungeonTester_UpdatePerformanceMetrics_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEndlessDungeonTester, nullptr, "UpdatePerformanceMetrics", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEndlessDungeonTester_UpdatePerformanceMetrics_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEndlessDungeonTester_UpdatePerformanceMetrics_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AEndlessDungeonTester_UpdatePerformanceMetrics()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEndlessDungeonTester_UpdatePerformanceMetrics_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEndlessDungeonTester::execUpdatePerformanceMetrics)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UpdatePerformanceMetrics();
	P_NATIVE_END;
}
// End Class AEndlessDungeonTester Function UpdatePerformanceMetrics

// Begin Class AEndlessDungeonTester Function ValidateStage
struct Z_Construct_UFunction_AEndlessDungeonTester_ValidateStage_Statics
{
	struct EndlessDungeonTester_eventValidateStage_Parms
	{
		int32 StageNumber;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Endless Test" },
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_StageNumber;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AEndlessDungeonTester_ValidateStage_Statics::NewProp_StageNumber = { "StageNumber", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EndlessDungeonTester_eventValidateStage_Parms, StageNumber), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_AEndlessDungeonTester_ValidateStage_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((EndlessDungeonTester_eventValidateStage_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AEndlessDungeonTester_ValidateStage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(EndlessDungeonTester_eventValidateStage_Parms), &Z_Construct_UFunction_AEndlessDungeonTester_ValidateStage_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEndlessDungeonTester_ValidateStage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEndlessDungeonTester_ValidateStage_Statics::NewProp_StageNumber,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEndlessDungeonTester_ValidateStage_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEndlessDungeonTester_ValidateStage_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEndlessDungeonTester_ValidateStage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEndlessDungeonTester, nullptr, "ValidateStage", nullptr, nullptr, Z_Construct_UFunction_AEndlessDungeonTester_ValidateStage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEndlessDungeonTester_ValidateStage_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEndlessDungeonTester_ValidateStage_Statics::EndlessDungeonTester_eventValidateStage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEndlessDungeonTester_ValidateStage_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEndlessDungeonTester_ValidateStage_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AEndlessDungeonTester_ValidateStage_Statics::EndlessDungeonTester_eventValidateStage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEndlessDungeonTester_ValidateStage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEndlessDungeonTester_ValidateStage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEndlessDungeonTester::execValidateStage)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_StageNumber);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ValidateStage(Z_Param_StageNumber);
	P_NATIVE_END;
}
// End Class AEndlessDungeonTester Function ValidateStage

// Begin Class AEndlessDungeonTester Function VisualizeStage
struct Z_Construct_UFunction_AEndlessDungeonTester_VisualizeStage_Statics
{
	struct EndlessDungeonTester_eventVisualizeStage_Parms
	{
		int32 StageNumber;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Endless Test" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Visualization\n" },
#endif
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Visualization" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_StageNumber;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AEndlessDungeonTester_VisualizeStage_Statics::NewProp_StageNumber = { "StageNumber", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EndlessDungeonTester_eventVisualizeStage_Parms, StageNumber), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEndlessDungeonTester_VisualizeStage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEndlessDungeonTester_VisualizeStage_Statics::NewProp_StageNumber,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEndlessDungeonTester_VisualizeStage_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEndlessDungeonTester_VisualizeStage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEndlessDungeonTester, nullptr, "VisualizeStage", nullptr, nullptr, Z_Construct_UFunction_AEndlessDungeonTester_VisualizeStage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEndlessDungeonTester_VisualizeStage_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEndlessDungeonTester_VisualizeStage_Statics::EndlessDungeonTester_eventVisualizeStage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEndlessDungeonTester_VisualizeStage_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEndlessDungeonTester_VisualizeStage_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AEndlessDungeonTester_VisualizeStage_Statics::EndlessDungeonTester_eventVisualizeStage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEndlessDungeonTester_VisualizeStage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEndlessDungeonTester_VisualizeStage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEndlessDungeonTester::execVisualizeStage)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_StageNumber);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->VisualizeStage(Z_Param_StageNumber);
	P_NATIVE_END;
}
// End Class AEndlessDungeonTester Function VisualizeStage

// Begin Class AEndlessDungeonTester
void AEndlessDungeonTester::StaticRegisterNativesAEndlessDungeonTester()
{
	UClass* Class = AEndlessDungeonTester::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ClearCurrentStage", &AEndlessDungeonTester::execClearCurrentStage },
		{ "GenerateMaximumStages", &AEndlessDungeonTester::execGenerateMaximumStages },
		{ "GenerateMultipleStages", &AEndlessDungeonTester::execGenerateMultipleStages },
		{ "GenerateNextStage", &AEndlessDungeonTester::execGenerateNextStage },
		{ "GetStageResult", &AEndlessDungeonTester::execGetStageResult },
		{ "GetTestStats", &AEndlessDungeonTester::execGetTestStats },
		{ "PrintTestReport", &AEndlessDungeonTester::execPrintTestReport },
		{ "RunStressTest", &AEndlessDungeonTester::execRunStressTest },
		{ "SaveTestResults", &AEndlessDungeonTester::execSaveTestResults },
		{ "ShowAllStagesOverview", &AEndlessDungeonTester::execShowAllStagesOverview },
		{ "StartEndlessTest", &AEndlessDungeonTester::execStartEndlessTest },
		{ "StopEndlessTest", &AEndlessDungeonTester::execStopEndlessTest },
		{ "TestGenerationSpeed", &AEndlessDungeonTester::execTestGenerationSpeed },
		{ "TestRoomScaling", &AEndlessDungeonTester::execTestRoomScaling },
		{ "TransitionToStage", &AEndlessDungeonTester::execTransitionToStage },
		{ "UpdatePerformanceMetrics", &AEndlessDungeonTester::execUpdatePerformanceMetrics },
		{ "ValidateStage", &AEndlessDungeonTester::execValidateStage },
		{ "VisualizeStage", &AEndlessDungeonTester::execVisualizeStage },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AEndlessDungeonTester);
UClass* Z_Construct_UClass_AEndlessDungeonTester_NoRegister()
{
	return AEndlessDungeonTester::StaticClass();
}
struct Z_Construct_UClass_AEndlessDungeonTester_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "EndlessDungeonTester.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxStagesToGenerate_MetaData[] = {
		{ "Category", "Configuration" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Configuration\n" },
#endif
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Configuration" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutoGenerateOnStart_MetaData[] = {
		{ "Category", "Configuration" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Start with 100, can go up to 1000+\n" },
#endif
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Start with 100, can go up to 1000+" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DelayBetweenStages_MetaData[] = {
		{ "Category", "Configuration" },
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bVisualizeEachStage_MetaData[] = {
		{ "Category", "Configuration" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Small delay to prevent freezing\n" },
#endif
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Small delay to prevent freezing" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bLogDetailedStats_MetaData[] = {
		{ "Category", "Configuration" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Set false for max performance\n" },
#endif
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Set false for max performance" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinRoomsPerStage_MetaData[] = {
		{ "Category", "Configuration" },
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxRoomsPerStage_MetaData[] = {
		{ "Category", "Configuration" },
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIncreaseComplexityOverTime_MetaData[] = {
		{ "Category", "Configuration" },
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ComplexityGrowthRate_MetaData[] = {
		{ "Category", "Configuration" },
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinAcceptableFPS_MetaData[] = {
		{ "Category", "Performance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Performance Limits\n" },
#endif
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Performance Limits" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxMemoryUsageMB_MetaData[] = {
		{ "Category", "Performance" },
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bStopOnPerformanceIssue_MetaData[] = {
		{ "Category", "Performance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// 4GB limit\n" },
#endif
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "4GB limit" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DungeonVisualizer_MetaData[] = {
		{ "Category", "References" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// References\n" },
#endif
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "References" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ADASystem_MetaData[] = {
		{ "Category", "References" },
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentStage_MetaData[] = {
		{ "Category", "Runtime" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Runtime Data\n" },
#endif
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Runtime Data" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsTestRunning_MetaData[] = {
		{ "Category", "Runtime" },
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StageResults_MetaData[] = {
		{ "Category", "Runtime" },
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GeneratedLayouts_MetaData[] = {
		{ "Category", "Runtime" },
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TestStats_MetaData[] = {
		{ "Category", "Runtime" },
		{ "ModuleRelativePath", "Public/EndlessDungeonTester.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxStagesToGenerate;
	static void NewProp_bAutoGenerateOnStart_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoGenerateOnStart;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DelayBetweenStages;
	static void NewProp_bVisualizeEachStage_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bVisualizeEachStage;
	static void NewProp_bLogDetailedStats_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bLogDetailedStats;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MinRoomsPerStage;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxRoomsPerStage;
	static void NewProp_bIncreaseComplexityOverTime_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIncreaseComplexityOverTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ComplexityGrowthRate;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MinAcceptableFPS;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxMemoryUsageMB;
	static void NewProp_bStopOnPerformanceIssue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bStopOnPerformanceIssue;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DungeonVisualizer;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ADASystem;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentStage;
	static void NewProp_bIsTestRunning_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsTestRunning;
	static const UECodeGen_Private::FStructPropertyParams NewProp_StageResults_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_StageResults;
	static const UECodeGen_Private::FStructPropertyParams NewProp_GeneratedLayouts_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_GeneratedLayouts;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TestStats;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AEndlessDungeonTester_ClearCurrentStage, "ClearCurrentStage" }, // 201283043
		{ &Z_Construct_UFunction_AEndlessDungeonTester_GenerateMaximumStages, "GenerateMaximumStages" }, // 2371897708
		{ &Z_Construct_UFunction_AEndlessDungeonTester_GenerateMultipleStages, "GenerateMultipleStages" }, // 1715581753
		{ &Z_Construct_UFunction_AEndlessDungeonTester_GenerateNextStage, "GenerateNextStage" }, // 1726949333
		{ &Z_Construct_UFunction_AEndlessDungeonTester_GetStageResult, "GetStageResult" }, // 1943428287
		{ &Z_Construct_UFunction_AEndlessDungeonTester_GetTestStats, "GetTestStats" }, // 2235484149
		{ &Z_Construct_UFunction_AEndlessDungeonTester_OnStageGenerated, "OnStageGenerated" }, // 2912709711
		{ &Z_Construct_UFunction_AEndlessDungeonTester_OnTestCompleted, "OnTestCompleted" }, // 3701940876
		{ &Z_Construct_UFunction_AEndlessDungeonTester_PrintTestReport, "PrintTestReport" }, // 4186093995
		{ &Z_Construct_UFunction_AEndlessDungeonTester_RunStressTest, "RunStressTest" }, // 3005625014
		{ &Z_Construct_UFunction_AEndlessDungeonTester_SaveTestResults, "SaveTestResults" }, // 3590586666
		{ &Z_Construct_UFunction_AEndlessDungeonTester_ShowAllStagesOverview, "ShowAllStagesOverview" }, // 3647194120
		{ &Z_Construct_UFunction_AEndlessDungeonTester_StartEndlessTest, "StartEndlessTest" }, // 4103034442
		{ &Z_Construct_UFunction_AEndlessDungeonTester_StopEndlessTest, "StopEndlessTest" }, // 1200481079
		{ &Z_Construct_UFunction_AEndlessDungeonTester_TestGenerationSpeed, "TestGenerationSpeed" }, // 1839360377
		{ &Z_Construct_UFunction_AEndlessDungeonTester_TestRoomScaling, "TestRoomScaling" }, // 1637243881
		{ &Z_Construct_UFunction_AEndlessDungeonTester_TransitionToStage, "TransitionToStage" }, // 3062324716
		{ &Z_Construct_UFunction_AEndlessDungeonTester_UpdatePerformanceMetrics, "UpdatePerformanceMetrics" }, // 2533663243
		{ &Z_Construct_UFunction_AEndlessDungeonTester_ValidateStage, "ValidateStage" }, // 4058050666
		{ &Z_Construct_UFunction_AEndlessDungeonTester_VisualizeStage, "VisualizeStage" }, // 3279094319
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEndlessDungeonTester>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_MaxStagesToGenerate = { "MaxStagesToGenerate", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEndlessDungeonTester, MaxStagesToGenerate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxStagesToGenerate_MetaData), NewProp_MaxStagesToGenerate_MetaData) };
void Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_bAutoGenerateOnStart_SetBit(void* Obj)
{
	((AEndlessDungeonTester*)Obj)->bAutoGenerateOnStart = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_bAutoGenerateOnStart = { "bAutoGenerateOnStart", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AEndlessDungeonTester), &Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_bAutoGenerateOnStart_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutoGenerateOnStart_MetaData), NewProp_bAutoGenerateOnStart_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_DelayBetweenStages = { "DelayBetweenStages", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEndlessDungeonTester, DelayBetweenStages), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DelayBetweenStages_MetaData), NewProp_DelayBetweenStages_MetaData) };
void Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_bVisualizeEachStage_SetBit(void* Obj)
{
	((AEndlessDungeonTester*)Obj)->bVisualizeEachStage = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_bVisualizeEachStage = { "bVisualizeEachStage", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AEndlessDungeonTester), &Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_bVisualizeEachStage_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bVisualizeEachStage_MetaData), NewProp_bVisualizeEachStage_MetaData) };
void Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_bLogDetailedStats_SetBit(void* Obj)
{
	((AEndlessDungeonTester*)Obj)->bLogDetailedStats = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_bLogDetailedStats = { "bLogDetailedStats", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AEndlessDungeonTester), &Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_bLogDetailedStats_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bLogDetailedStats_MetaData), NewProp_bLogDetailedStats_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_MinRoomsPerStage = { "MinRoomsPerStage", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEndlessDungeonTester, MinRoomsPerStage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinRoomsPerStage_MetaData), NewProp_MinRoomsPerStage_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_MaxRoomsPerStage = { "MaxRoomsPerStage", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEndlessDungeonTester, MaxRoomsPerStage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxRoomsPerStage_MetaData), NewProp_MaxRoomsPerStage_MetaData) };
void Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_bIncreaseComplexityOverTime_SetBit(void* Obj)
{
	((AEndlessDungeonTester*)Obj)->bIncreaseComplexityOverTime = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_bIncreaseComplexityOverTime = { "bIncreaseComplexityOverTime", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AEndlessDungeonTester), &Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_bIncreaseComplexityOverTime_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIncreaseComplexityOverTime_MetaData), NewProp_bIncreaseComplexityOverTime_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_ComplexityGrowthRate = { "ComplexityGrowthRate", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEndlessDungeonTester, ComplexityGrowthRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ComplexityGrowthRate_MetaData), NewProp_ComplexityGrowthRate_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_MinAcceptableFPS = { "MinAcceptableFPS", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEndlessDungeonTester, MinAcceptableFPS), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinAcceptableFPS_MetaData), NewProp_MinAcceptableFPS_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_MaxMemoryUsageMB = { "MaxMemoryUsageMB", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEndlessDungeonTester, MaxMemoryUsageMB), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxMemoryUsageMB_MetaData), NewProp_MaxMemoryUsageMB_MetaData) };
void Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_bStopOnPerformanceIssue_SetBit(void* Obj)
{
	((AEndlessDungeonTester*)Obj)->bStopOnPerformanceIssue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_bStopOnPerformanceIssue = { "bStopOnPerformanceIssue", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AEndlessDungeonTester), &Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_bStopOnPerformanceIssue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bStopOnPerformanceIssue_MetaData), NewProp_bStopOnPerformanceIssue_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_DungeonVisualizer = { "DungeonVisualizer", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEndlessDungeonTester, DungeonVisualizer), Z_Construct_UClass_AGridDungeonVisualizer_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DungeonVisualizer_MetaData), NewProp_DungeonVisualizer_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_ADASystem = { "ADASystem", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEndlessDungeonTester, ADASystem), Z_Construct_UClass_AADASystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ADASystem_MetaData), NewProp_ADASystem_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_CurrentStage = { "CurrentStage", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEndlessDungeonTester, CurrentStage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentStage_MetaData), NewProp_CurrentStage_MetaData) };
void Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_bIsTestRunning_SetBit(void* Obj)
{
	((AEndlessDungeonTester*)Obj)->bIsTestRunning = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_bIsTestRunning = { "bIsTestRunning", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AEndlessDungeonTester), &Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_bIsTestRunning_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsTestRunning_MetaData), NewProp_bIsTestRunning_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_StageResults_Inner = { "StageResults", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FStageGenerationResult, METADATA_PARAMS(0, nullptr) }; // 1143632389
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_StageResults = { "StageResults", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEndlessDungeonTester, StageResults), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StageResults_MetaData), NewProp_StageResults_MetaData) }; // 1143632389
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_GeneratedLayouts_Inner = { "GeneratedLayouts", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDungeonLayout, METADATA_PARAMS(0, nullptr) }; // 3903890264
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_GeneratedLayouts = { "GeneratedLayouts", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEndlessDungeonTester, GeneratedLayouts), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GeneratedLayouts_MetaData), NewProp_GeneratedLayouts_MetaData) }; // 3903890264
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_TestStats = { "TestStats", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEndlessDungeonTester, TestStats), Z_Construct_UScriptStruct_FEndlessTestStats, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TestStats_MetaData), NewProp_TestStats_MetaData) }; // 1990716653
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AEndlessDungeonTester_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_MaxStagesToGenerate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_bAutoGenerateOnStart,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_DelayBetweenStages,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_bVisualizeEachStage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_bLogDetailedStats,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_MinRoomsPerStage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_MaxRoomsPerStage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_bIncreaseComplexityOverTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_ComplexityGrowthRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_MinAcceptableFPS,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_MaxMemoryUsageMB,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_bStopOnPerformanceIssue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_DungeonVisualizer,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_ADASystem,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_CurrentStage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_bIsTestRunning,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_StageResults_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_StageResults,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_GeneratedLayouts_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_GeneratedLayouts,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEndlessDungeonTester_Statics::NewProp_TestStats,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEndlessDungeonTester_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AEndlessDungeonTester_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_EternalDescent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEndlessDungeonTester_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AEndlessDungeonTester_Statics::ClassParams = {
	&AEndlessDungeonTester::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AEndlessDungeonTester_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AEndlessDungeonTester_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AEndlessDungeonTester_Statics::Class_MetaDataParams), Z_Construct_UClass_AEndlessDungeonTester_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AEndlessDungeonTester()
{
	if (!Z_Registration_Info_UClass_AEndlessDungeonTester.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AEndlessDungeonTester.OuterSingleton, Z_Construct_UClass_AEndlessDungeonTester_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AEndlessDungeonTester.OuterSingleton;
}
template<> ETERNALDESCENT_API UClass* StaticClass<AEndlessDungeonTester>()
{
	return AEndlessDungeonTester::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AEndlessDungeonTester);
AEndlessDungeonTester::~AEndlessDungeonTester() {}
// End Class AEndlessDungeonTester

// Begin Registration
struct Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_EndlessDungeonTester_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FStageGenerationResult::StaticStruct, Z_Construct_UScriptStruct_FStageGenerationResult_Statics::NewStructOps, TEXT("StageGenerationResult"), &Z_Registration_Info_UScriptStruct_StageGenerationResult, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FStageGenerationResult), 1143632389U) },
		{ FEndlessTestStats::StaticStruct, Z_Construct_UScriptStruct_FEndlessTestStats_Statics::NewStructOps, TEXT("EndlessTestStats"), &Z_Registration_Info_UScriptStruct_EndlessTestStats, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FEndlessTestStats), 1990716653U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AEndlessDungeonTester, AEndlessDungeonTester::StaticClass, TEXT("AEndlessDungeonTester"), &Z_Registration_Info_UClass_AEndlessDungeonTester, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AEndlessDungeonTester), 4035892641U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_EndlessDungeonTester_h_2321010837(TEXT("/Script/EternalDescent"),
	Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_EndlessDungeonTester_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_EndlessDungeonTester_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_EndlessDungeonTester_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_EndlessDungeonTester_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
