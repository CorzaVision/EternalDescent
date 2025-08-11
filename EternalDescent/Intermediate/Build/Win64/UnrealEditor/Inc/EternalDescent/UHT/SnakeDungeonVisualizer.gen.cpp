// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EternalDescent/Public/SnakeDungeonVisualizer.h"
#include "EternalDescent/Public/SnakePathGenerator.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSnakeDungeonVisualizer() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
ETERNALDESCENT_API UClass* Z_Construct_UClass_ASnakeDungeonVisualizer();
ETERNALDESCENT_API UClass* Z_Construct_UClass_ASnakeDungeonVisualizer_NoRegister();
ETERNALDESCENT_API UClass* Z_Construct_UClass_USnakePathGenerator_NoRegister();
ETERNALDESCENT_API UScriptStruct* Z_Construct_UScriptStruct_FSnakeGenerationResult();
UPackage* Z_Construct_UPackage__Script_EternalDescent();
// End Cross Module References

// Begin Class ASnakeDungeonVisualizer Function ClearVisualization
struct Z_Construct_UFunction_ASnakeDungeonVisualizer_ClearVisualization_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Visualization" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Clear all current visualization */" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Clear all current visualization" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASnakeDungeonVisualizer_ClearVisualization_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASnakeDungeonVisualizer, nullptr, "ClearVisualization", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonVisualizer_ClearVisualization_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASnakeDungeonVisualizer_ClearVisualization_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ASnakeDungeonVisualizer_ClearVisualization()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASnakeDungeonVisualizer_ClearVisualization_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASnakeDungeonVisualizer::execClearVisualization)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClearVisualization();
	P_NATIVE_END;
}
// End Class ASnakeDungeonVisualizer Function ClearVisualization

// Begin Class ASnakeDungeonVisualizer Function GenerateAndVisualize
struct Z_Construct_UFunction_ASnakeDungeonVisualizer_GenerateAndVisualize_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Generate and visualize a new dungeon */" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Generate and visualize a new dungeon" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASnakeDungeonVisualizer_GenerateAndVisualize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASnakeDungeonVisualizer, nullptr, "GenerateAndVisualize", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonVisualizer_GenerateAndVisualize_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASnakeDungeonVisualizer_GenerateAndVisualize_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ASnakeDungeonVisualizer_GenerateAndVisualize()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASnakeDungeonVisualizer_GenerateAndVisualize_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASnakeDungeonVisualizer::execGenerateAndVisualize)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->GenerateAndVisualize();
	P_NATIVE_END;
}
// End Class ASnakeDungeonVisualizer Function GenerateAndVisualize

// Begin Class ASnakeDungeonVisualizer Function GetCurrentResult
struct Z_Construct_UFunction_ASnakeDungeonVisualizer_GetCurrentResult_Statics
{
	struct SnakeDungeonVisualizer_eventGetCurrentResult_Parms
	{
		FSnakeGenerationResult ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Get the current generation result */" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the current generation result" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASnakeDungeonVisualizer_GetCurrentResult_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SnakeDungeonVisualizer_eventGetCurrentResult_Parms, ReturnValue), Z_Construct_UScriptStruct_FSnakeGenerationResult, METADATA_PARAMS(0, nullptr) }; // 2380905576
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASnakeDungeonVisualizer_GetCurrentResult_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASnakeDungeonVisualizer_GetCurrentResult_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonVisualizer_GetCurrentResult_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASnakeDungeonVisualizer_GetCurrentResult_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASnakeDungeonVisualizer, nullptr, "GetCurrentResult", nullptr, nullptr, Z_Construct_UFunction_ASnakeDungeonVisualizer_GetCurrentResult_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonVisualizer_GetCurrentResult_Statics::PropPointers), sizeof(Z_Construct_UFunction_ASnakeDungeonVisualizer_GetCurrentResult_Statics::SnakeDungeonVisualizer_eventGetCurrentResult_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonVisualizer_GetCurrentResult_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASnakeDungeonVisualizer_GetCurrentResult_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ASnakeDungeonVisualizer_GetCurrentResult_Statics::SnakeDungeonVisualizer_eventGetCurrentResult_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ASnakeDungeonVisualizer_GetCurrentResult()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASnakeDungeonVisualizer_GetCurrentResult_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASnakeDungeonVisualizer::execGetCurrentResult)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FSnakeGenerationResult*)Z_Param__Result=P_THIS->GetCurrentResult();
	P_NATIVE_END;
}
// End Class ASnakeDungeonVisualizer Function GetCurrentResult

// Begin Class ASnakeDungeonVisualizer Function RegenerateWithNewSeed
struct Z_Construct_UFunction_ASnakeDungeonVisualizer_RegenerateWithNewSeed_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Generation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Regenerate with a new random seed */" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Regenerate with a new random seed" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASnakeDungeonVisualizer_RegenerateWithNewSeed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASnakeDungeonVisualizer, nullptr, "RegenerateWithNewSeed", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonVisualizer_RegenerateWithNewSeed_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASnakeDungeonVisualizer_RegenerateWithNewSeed_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ASnakeDungeonVisualizer_RegenerateWithNewSeed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASnakeDungeonVisualizer_RegenerateWithNewSeed_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASnakeDungeonVisualizer::execRegenerateWithNewSeed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RegenerateWithNewSeed();
	P_NATIVE_END;
}
// End Class ASnakeDungeonVisualizer Function RegenerateWithNewSeed

// Begin Class ASnakeDungeonVisualizer
void ASnakeDungeonVisualizer::StaticRegisterNativesASnakeDungeonVisualizer()
{
	UClass* Class = ASnakeDungeonVisualizer::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ClearVisualization", &ASnakeDungeonVisualizer::execClearVisualization },
		{ "GenerateAndVisualize", &ASnakeDungeonVisualizer::execGenerateAndVisualize },
		{ "GetCurrentResult", &ASnakeDungeonVisualizer::execGetCurrentResult },
		{ "RegenerateWithNewSeed", &ASnakeDungeonVisualizer::execRegenerateWithNewSeed },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASnakeDungeonVisualizer);
UClass* Z_Construct_UClass_ASnakeDungeonVisualizer_NoRegister()
{
	return ASnakeDungeonVisualizer::StaticClass();
}
struct Z_Construct_UClass_ASnakeDungeonVisualizer_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Visual debugging actor for SnakePathGenerator backend.\n * \n * This actor provides real-time visualization of the snake path generation algorithm:\n * - Spawns debug boxes for each room with color coding\n * - Draws path connections between rooms  \n * - Displays room indices and generation statistics\n * - Editor-friendly with regeneration controls\n * \n * Color Coding:\n * - START room: Green\n * - END room: Red  \n * - Regular rooms: Blue\n * \n * Features:\n * - Real-time regeneration with different seeds\n * - Configurable visualization scale and grid size\n * - Debug output with generation statistics\n * - Editor properties for easy testing\n */" },
#endif
		{ "IncludePath", "SnakeDungeonVisualizer.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/SnakeDungeonVisualizer.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Visual debugging actor for SnakePathGenerator backend.\n\nThis actor provides real-time visualization of the snake path generation algorithm:\n- Spawns debug boxes for each room with color coding\n- Draws path connections between rooms\n- Displays room indices and generation statistics\n- Editor-friendly with regeneration controls\n\nColor Coding:\n- START room: Green\n- END room: Red\n- Regular rooms: Blue\n\nFeatures:\n- Real-time regeneration with different seeds\n- Configurable visualization scale and grid size\n- Debug output with generation statistics\n- Editor properties for easy testing" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RandomSeed_MetaData[] = {
		{ "Category", "Generation" },
		{ "ClampMin", "-1" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Random seed for generation (-1 for random) */" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Random seed for generation (-1 for random)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GridSizeX_MetaData[] = {
		{ "Category", "Generation" },
		{ "ClampMax", "60" },
		{ "ClampMin", "30" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Grid size X dimension */" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Grid size X dimension" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GridSizeY_MetaData[] = {
		{ "Category", "Generation" },
		{ "ClampMax", "60" },
		{ "ClampMin", "30" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Grid size Y dimension */" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Grid size Y dimension" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VisualizationScale_MetaData[] = {
		{ "Category", "Visualization" },
		{ "ClampMax", "10.0" },
		{ "ClampMin", "0.1" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Scale multiplier for visualization */" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Scale multiplier for visualization" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutoCalculateGridSize_MetaData[] = {
		{ "Category", "Generation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Auto-calculate grid size based on room count */" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Auto-calculate grid size based on room count" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bVerboseLogging_MetaData[] = {
		{ "Category", "Debug" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Enable verbose logging during generation */" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Enable verbose logging during generation" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowRoomIndices_MetaData[] = {
		{ "Category", "Visualization" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Show room indices as text */" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Show room indices as text" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowPathConnections_MetaData[] = {
		{ "Category", "Visualization" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Show path connections between rooms */" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Show path connections between rooms" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowGenerationStats_MetaData[] = {
		{ "Category", "Debug" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Show generation statistics */" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Show generation statistics" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutoRegenerate_MetaData[] = {
		{ "Category", "Debug" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Regenerate dungeon on property change */" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Regenerate dungeon on property change" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StartRoomMaterial_MetaData[] = {
		{ "Category", "Materials" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Material for START room (Green) */" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Material for START room (Green)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EndRoomMaterial_MetaData[] = {
		{ "Category", "Materials" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Material for END room (Red) */" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Material for END room (Red)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RegularRoomMaterial_MetaData[] = {
		{ "Category", "Materials" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Material for regular rooms (Blue) */" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Material for regular rooms (Blue)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoomMesh_MetaData[] = {
		{ "Category", "Meshes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Static mesh for room visualization */" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Static mesh for room visualization" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RootSceneComponent_MetaData[] = {
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Root scene component */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/SnakeDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Root scene component" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PathGenerator_MetaData[] = {
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Snake path generator instance */" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Snake path generator instance" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoomComponents_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Array of spawned room visualization components */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/SnakeDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Array of spawned room visualization components" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentResult_MetaData[] = {
		{ "Category", "Debug" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current generation result */" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current generation result" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_RandomSeed;
	static const UECodeGen_Private::FIntPropertyParams NewProp_GridSizeX;
	static const UECodeGen_Private::FIntPropertyParams NewProp_GridSizeY;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_VisualizationScale;
	static void NewProp_bAutoCalculateGridSize_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoCalculateGridSize;
	static void NewProp_bVerboseLogging_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bVerboseLogging;
	static void NewProp_bShowRoomIndices_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowRoomIndices;
	static void NewProp_bShowPathConnections_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowPathConnections;
	static void NewProp_bShowGenerationStats_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowGenerationStats;
	static void NewProp_bAutoRegenerate_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoRegenerate;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_StartRoomMaterial;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_EndRoomMaterial;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_RegularRoomMaterial;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_RoomMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RootSceneComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PathGenerator;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RoomComponents_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_RoomComponents;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CurrentResult;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ASnakeDungeonVisualizer_ClearVisualization, "ClearVisualization" }, // 2556276561
		{ &Z_Construct_UFunction_ASnakeDungeonVisualizer_GenerateAndVisualize, "GenerateAndVisualize" }, // 370607408
		{ &Z_Construct_UFunction_ASnakeDungeonVisualizer_GetCurrentResult, "GetCurrentResult" }, // 265312021
		{ &Z_Construct_UFunction_ASnakeDungeonVisualizer_RegenerateWithNewSeed, "RegenerateWithNewSeed" }, // 2648033763
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASnakeDungeonVisualizer>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::NewProp_RandomSeed = { "RandomSeed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakeDungeonVisualizer, RandomSeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RandomSeed_MetaData), NewProp_RandomSeed_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::NewProp_GridSizeX = { "GridSizeX", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakeDungeonVisualizer, GridSizeX), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GridSizeX_MetaData), NewProp_GridSizeX_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::NewProp_GridSizeY = { "GridSizeY", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakeDungeonVisualizer, GridSizeY), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GridSizeY_MetaData), NewProp_GridSizeY_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::NewProp_VisualizationScale = { "VisualizationScale", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakeDungeonVisualizer, VisualizationScale), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VisualizationScale_MetaData), NewProp_VisualizationScale_MetaData) };
void Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::NewProp_bAutoCalculateGridSize_SetBit(void* Obj)
{
	((ASnakeDungeonVisualizer*)Obj)->bAutoCalculateGridSize = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::NewProp_bAutoCalculateGridSize = { "bAutoCalculateGridSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ASnakeDungeonVisualizer), &Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::NewProp_bAutoCalculateGridSize_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutoCalculateGridSize_MetaData), NewProp_bAutoCalculateGridSize_MetaData) };
void Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::NewProp_bVerboseLogging_SetBit(void* Obj)
{
	((ASnakeDungeonVisualizer*)Obj)->bVerboseLogging = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::NewProp_bVerboseLogging = { "bVerboseLogging", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ASnakeDungeonVisualizer), &Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::NewProp_bVerboseLogging_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bVerboseLogging_MetaData), NewProp_bVerboseLogging_MetaData) };
void Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::NewProp_bShowRoomIndices_SetBit(void* Obj)
{
	((ASnakeDungeonVisualizer*)Obj)->bShowRoomIndices = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::NewProp_bShowRoomIndices = { "bShowRoomIndices", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ASnakeDungeonVisualizer), &Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::NewProp_bShowRoomIndices_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowRoomIndices_MetaData), NewProp_bShowRoomIndices_MetaData) };
void Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::NewProp_bShowPathConnections_SetBit(void* Obj)
{
	((ASnakeDungeonVisualizer*)Obj)->bShowPathConnections = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::NewProp_bShowPathConnections = { "bShowPathConnections", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ASnakeDungeonVisualizer), &Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::NewProp_bShowPathConnections_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowPathConnections_MetaData), NewProp_bShowPathConnections_MetaData) };
void Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::NewProp_bShowGenerationStats_SetBit(void* Obj)
{
	((ASnakeDungeonVisualizer*)Obj)->bShowGenerationStats = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::NewProp_bShowGenerationStats = { "bShowGenerationStats", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ASnakeDungeonVisualizer), &Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::NewProp_bShowGenerationStats_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowGenerationStats_MetaData), NewProp_bShowGenerationStats_MetaData) };
void Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::NewProp_bAutoRegenerate_SetBit(void* Obj)
{
	((ASnakeDungeonVisualizer*)Obj)->bAutoRegenerate = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::NewProp_bAutoRegenerate = { "bAutoRegenerate", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ASnakeDungeonVisualizer), &Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::NewProp_bAutoRegenerate_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutoRegenerate_MetaData), NewProp_bAutoRegenerate_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::NewProp_StartRoomMaterial = { "StartRoomMaterial", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakeDungeonVisualizer, StartRoomMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StartRoomMaterial_MetaData), NewProp_StartRoomMaterial_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::NewProp_EndRoomMaterial = { "EndRoomMaterial", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakeDungeonVisualizer, EndRoomMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EndRoomMaterial_MetaData), NewProp_EndRoomMaterial_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::NewProp_RegularRoomMaterial = { "RegularRoomMaterial", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakeDungeonVisualizer, RegularRoomMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RegularRoomMaterial_MetaData), NewProp_RegularRoomMaterial_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::NewProp_RoomMesh = { "RoomMesh", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakeDungeonVisualizer, RoomMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoomMesh_MetaData), NewProp_RoomMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::NewProp_RootSceneComponent = { "RootSceneComponent", nullptr, (EPropertyFlags)0x01240800000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakeDungeonVisualizer, RootSceneComponent), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RootSceneComponent_MetaData), NewProp_RootSceneComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::NewProp_PathGenerator = { "PathGenerator", nullptr, (EPropertyFlags)0x0124080000020015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakeDungeonVisualizer, PathGenerator), Z_Construct_UClass_USnakePathGenerator_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PathGenerator_MetaData), NewProp_PathGenerator_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::NewProp_RoomComponents_Inner = { "RoomComponents", nullptr, (EPropertyFlags)0x0104000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::NewProp_RoomComponents = { "RoomComponents", nullptr, (EPropertyFlags)0x0124088000000008, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakeDungeonVisualizer, RoomComponents), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoomComponents_MetaData), NewProp_RoomComponents_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::NewProp_CurrentResult = { "CurrentResult", nullptr, (EPropertyFlags)0x0020080000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakeDungeonVisualizer, CurrentResult), Z_Construct_UScriptStruct_FSnakeGenerationResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentResult_MetaData), NewProp_CurrentResult_MetaData) }; // 2380905576
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::NewProp_RandomSeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::NewProp_GridSizeX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::NewProp_GridSizeY,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::NewProp_VisualizationScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::NewProp_bAutoCalculateGridSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::NewProp_bVerboseLogging,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::NewProp_bShowRoomIndices,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::NewProp_bShowPathConnections,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::NewProp_bShowGenerationStats,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::NewProp_bAutoRegenerate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::NewProp_StartRoomMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::NewProp_EndRoomMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::NewProp_RegularRoomMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::NewProp_RoomMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::NewProp_RootSceneComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::NewProp_PathGenerator,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::NewProp_RoomComponents_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::NewProp_RoomComponents,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::NewProp_CurrentResult,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_EternalDescent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::ClassParams = {
	&ASnakeDungeonVisualizer::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::Class_MetaDataParams), Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ASnakeDungeonVisualizer()
{
	if (!Z_Registration_Info_UClass_ASnakeDungeonVisualizer.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASnakeDungeonVisualizer.OuterSingleton, Z_Construct_UClass_ASnakeDungeonVisualizer_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ASnakeDungeonVisualizer.OuterSingleton;
}
template<> ETERNALDESCENT_API UClass* StaticClass<ASnakeDungeonVisualizer>()
{
	return ASnakeDungeonVisualizer::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ASnakeDungeonVisualizer);
ASnakeDungeonVisualizer::~ASnakeDungeonVisualizer() {}
// End Class ASnakeDungeonVisualizer

// Begin Registration
struct Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonVisualizer_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ASnakeDungeonVisualizer, ASnakeDungeonVisualizer::StaticClass, TEXT("ASnakeDungeonVisualizer"), &Z_Registration_Info_UClass_ASnakeDungeonVisualizer, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASnakeDungeonVisualizer), 1745284477U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonVisualizer_h_2141706802(TEXT("/Script/EternalDescent"),
	Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonVisualizer_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonVisualizer_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
