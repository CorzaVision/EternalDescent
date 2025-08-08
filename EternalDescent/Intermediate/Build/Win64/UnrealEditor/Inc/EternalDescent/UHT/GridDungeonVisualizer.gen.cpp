// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EternalDescent/Public/GridDungeonVisualizer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGridDungeonVisualizer() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UInstancedStaticMeshComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
ETERNALDESCENT_API UClass* Z_Construct_UClass_AGridDungeonVisualizer();
ETERNALDESCENT_API UClass* Z_Construct_UClass_AGridDungeonVisualizer_NoRegister();
ETERNALDESCENT_API UEnum* Z_Construct_UEnum_EternalDescent_EGridCellType();
ETERNALDESCENT_API UScriptStruct* Z_Construct_UScriptStruct_FGridCell();
UPackage* Z_Construct_UPackage__Script_EternalDescent();
// End Cross Module References

// Begin Enum EGridCellType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EGridCellType;
static UEnum* EGridCellType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EGridCellType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EGridCellType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_EternalDescent_EGridCellType, (UObject*)Z_Construct_UPackage__Script_EternalDescent(), TEXT("EGridCellType"));
	}
	return Z_Registration_Info_UEnum_EGridCellType.OuterSingleton;
}
template<> ETERNALDESCENT_API UEnum* StaticEnum<EGridCellType>()
{
	return EGridCellType_StaticEnum();
}
struct Z_Construct_UEnum_EternalDescent_EGridCellType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Empty.DisplayName", "Empty" },
		{ "Empty.Name", "EGridCellType::Empty" },
		{ "Floor.Comment", "// Nothing (air)\n" },
		{ "Floor.DisplayName", "Floor" },
		{ "Floor.Name", "EGridCellType::Floor" },
		{ "Floor.ToolTip", "Nothing (air)" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
		{ "Wall.Comment", "// Walkable plane\n" },
		{ "Wall.DisplayName", "Wall" },
		{ "Wall.Name", "EGridCellType::Wall" },
		{ "Wall.ToolTip", "Walkable plane" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EGridCellType::Empty", (int64)EGridCellType::Empty },
		{ "EGridCellType::Floor", (int64)EGridCellType::Floor },
		{ "EGridCellType::Wall", (int64)EGridCellType::Wall },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_EternalDescent_EGridCellType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_EternalDescent,
	nullptr,
	"EGridCellType",
	"EGridCellType",
	Z_Construct_UEnum_EternalDescent_EGridCellType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_EternalDescent_EGridCellType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_EternalDescent_EGridCellType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_EternalDescent_EGridCellType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_EternalDescent_EGridCellType()
{
	if (!Z_Registration_Info_UEnum_EGridCellType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EGridCellType.InnerSingleton, Z_Construct_UEnum_EternalDescent_EGridCellType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EGridCellType.InnerSingleton;
}
// End Enum EGridCellType

// Begin ScriptStruct FGridCell
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_GridCell;
class UScriptStruct* FGridCell::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_GridCell.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_GridCell.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FGridCell, (UObject*)Z_Construct_UPackage__Script_EternalDescent(), TEXT("GridCell"));
	}
	return Z_Registration_Info_UScriptStruct_GridCell.OuterSingleton;
}
template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<FGridCell>()
{
	return FGridCell::StaticStruct();
}
struct Z_Construct_UScriptStruct_FGridCell_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CellType_MetaData[] = {
		{ "Category", "GridCell" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_CellType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_CellType;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FGridCell>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FGridCell_Statics::NewProp_CellType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FGridCell_Statics::NewProp_CellType = { "CellType", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGridCell, CellType), Z_Construct_UEnum_EternalDescent_EGridCellType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CellType_MetaData), NewProp_CellType_MetaData) }; // 1186920181
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FGridCell_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGridCell_Statics::NewProp_CellType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGridCell_Statics::NewProp_CellType,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGridCell_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FGridCell_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_EternalDescent,
	nullptr,
	&NewStructOps,
	"GridCell",
	Z_Construct_UScriptStruct_FGridCell_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGridCell_Statics::PropPointers),
	sizeof(FGridCell),
	alignof(FGridCell),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGridCell_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FGridCell_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FGridCell()
{
	if (!Z_Registration_Info_UScriptStruct_GridCell.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_GridCell.InnerSingleton, Z_Construct_UScriptStruct_FGridCell_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_GridCell.InnerSingleton;
}
// End ScriptStruct FGridCell

// Begin Class AGridDungeonVisualizer Function ClearDungeon
struct Z_Construct_UFunction_AGridDungeonVisualizer_ClearDungeon_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Grid Dungeon" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_ClearDungeon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "ClearDungeon", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_ClearDungeon_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_ClearDungeon_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_ClearDungeon()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_ClearDungeon_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridDungeonVisualizer::execClearDungeon)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClearDungeon();
	P_NATIVE_END;
}
// End Class AGridDungeonVisualizer Function ClearDungeon

// Begin Class AGridDungeonVisualizer Function DrawDebugGrid
struct Z_Construct_UFunction_AGridDungeonVisualizer_DrawDebugGrid_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Debug" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Debug Visualization\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Debug Visualization" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_DrawDebugGrid_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "DrawDebugGrid", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_DrawDebugGrid_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_DrawDebugGrid_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_DrawDebugGrid()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_DrawDebugGrid_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridDungeonVisualizer::execDrawDebugGrid)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DrawDebugGrid();
	P_NATIVE_END;
}
// End Class AGridDungeonVisualizer Function DrawDebugGrid

// Begin Class AGridDungeonVisualizer Function GenerateAndVisualizeDungeon
struct Z_Construct_UFunction_AGridDungeonVisualizer_GenerateAndVisualizeDungeon_Statics
{
	struct GridDungeonVisualizer_eventGenerateAndVisualizeDungeon_Parms
	{
		int32 Seed;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Grid Dungeon" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Core Generation\n" },
#endif
		{ "CPP_Default_Seed", "-1" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Core Generation" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_Seed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_GenerateAndVisualizeDungeon_Statics::NewProp_Seed = { "Seed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridDungeonVisualizer_eventGenerateAndVisualizeDungeon_Parms, Seed), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGridDungeonVisualizer_GenerateAndVisualizeDungeon_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_GenerateAndVisualizeDungeon_Statics::NewProp_Seed,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_GenerateAndVisualizeDungeon_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_GenerateAndVisualizeDungeon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "GenerateAndVisualizeDungeon", nullptr, nullptr, Z_Construct_UFunction_AGridDungeonVisualizer_GenerateAndVisualizeDungeon_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_GenerateAndVisualizeDungeon_Statics::PropPointers), sizeof(Z_Construct_UFunction_AGridDungeonVisualizer_GenerateAndVisualizeDungeon_Statics::GridDungeonVisualizer_eventGenerateAndVisualizeDungeon_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_GenerateAndVisualizeDungeon_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_GenerateAndVisualizeDungeon_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AGridDungeonVisualizer_GenerateAndVisualizeDungeon_Statics::GridDungeonVisualizer_eventGenerateAndVisualizeDungeon_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_GenerateAndVisualizeDungeon()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_GenerateAndVisualizeDungeon_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridDungeonVisualizer::execGenerateAndVisualizeDungeon)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_Seed);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->GenerateAndVisualizeDungeon(Z_Param_Seed);
	P_NATIVE_END;
}
// End Class AGridDungeonVisualizer Function GenerateAndVisualizeDungeon

// Begin Class AGridDungeonVisualizer Function GenerateInEditor
struct Z_Construct_UFunction_AGridDungeonVisualizer_GenerateInEditor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Debug" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_GenerateInEditor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "GenerateInEditor", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_GenerateInEditor_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_GenerateInEditor_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_GenerateInEditor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_GenerateInEditor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridDungeonVisualizer::execGenerateInEditor)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->GenerateInEditor();
	P_NATIVE_END;
}
// End Class AGridDungeonVisualizer Function GenerateInEditor

// Begin Class AGridDungeonVisualizer Function GetGridCell
struct Z_Construct_UFunction_AGridDungeonVisualizer_GetGridCell_Statics
{
	struct GridDungeonVisualizer_eventGetGridCell_Parms
	{
		int32 X;
		int32 Y;
		FGridCell ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Grid Dungeon" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_X;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Y;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_GetGridCell_Statics::NewProp_X = { "X", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridDungeonVisualizer_eventGetGridCell_Parms, X), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_GetGridCell_Statics::NewProp_Y = { "Y", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridDungeonVisualizer_eventGetGridCell_Parms, Y), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_GetGridCell_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridDungeonVisualizer_eventGetGridCell_Parms, ReturnValue), Z_Construct_UScriptStruct_FGridCell, METADATA_PARAMS(0, nullptr) }; // 2314947957
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGridDungeonVisualizer_GetGridCell_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_GetGridCell_Statics::NewProp_X,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_GetGridCell_Statics::NewProp_Y,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_GetGridCell_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_GetGridCell_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_GetGridCell_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "GetGridCell", nullptr, nullptr, Z_Construct_UFunction_AGridDungeonVisualizer_GetGridCell_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_GetGridCell_Statics::PropPointers), sizeof(Z_Construct_UFunction_AGridDungeonVisualizer_GetGridCell_Statics::GridDungeonVisualizer_eventGetGridCell_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_GetGridCell_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_GetGridCell_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AGridDungeonVisualizer_GetGridCell_Statics::GridDungeonVisualizer_eventGetGridCell_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_GetGridCell()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_GetGridCell_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridDungeonVisualizer::execGetGridCell)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_X);
	P_GET_PROPERTY(FIntProperty,Z_Param_Y);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGridCell*)Z_Param__Result=P_THIS->GetGridCell(Z_Param_X,Z_Param_Y);
	P_NATIVE_END;
}
// End Class AGridDungeonVisualizer Function GetGridCell

// Begin Class AGridDungeonVisualizer Function GridToWorldPosition
struct Z_Construct_UFunction_AGridDungeonVisualizer_GridToWorldPosition_Statics
{
	struct GridDungeonVisualizer_eventGridToWorldPosition_Parms
	{
		int32 X;
		int32 Y;
		bool bIsFloor;
		FVector ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Grid Dungeon" },
		{ "CPP_Default_bIsFloor", "true" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_X;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Y;
	static void NewProp_bIsFloor_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsFloor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_GridToWorldPosition_Statics::NewProp_X = { "X", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridDungeonVisualizer_eventGridToWorldPosition_Parms, X), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_GridToWorldPosition_Statics::NewProp_Y = { "Y", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridDungeonVisualizer_eventGridToWorldPosition_Parms, Y), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_AGridDungeonVisualizer_GridToWorldPosition_Statics::NewProp_bIsFloor_SetBit(void* Obj)
{
	((GridDungeonVisualizer_eventGridToWorldPosition_Parms*)Obj)->bIsFloor = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_GridToWorldPosition_Statics::NewProp_bIsFloor = { "bIsFloor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(GridDungeonVisualizer_eventGridToWorldPosition_Parms), &Z_Construct_UFunction_AGridDungeonVisualizer_GridToWorldPosition_Statics::NewProp_bIsFloor_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_GridToWorldPosition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridDungeonVisualizer_eventGridToWorldPosition_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGridDungeonVisualizer_GridToWorldPosition_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_GridToWorldPosition_Statics::NewProp_X,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_GridToWorldPosition_Statics::NewProp_Y,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_GridToWorldPosition_Statics::NewProp_bIsFloor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_GridToWorldPosition_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_GridToWorldPosition_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_GridToWorldPosition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "GridToWorldPosition", nullptr, nullptr, Z_Construct_UFunction_AGridDungeonVisualizer_GridToWorldPosition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_GridToWorldPosition_Statics::PropPointers), sizeof(Z_Construct_UFunction_AGridDungeonVisualizer_GridToWorldPosition_Statics::GridDungeonVisualizer_eventGridToWorldPosition_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_GridToWorldPosition_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_GridToWorldPosition_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AGridDungeonVisualizer_GridToWorldPosition_Statics::GridDungeonVisualizer_eventGridToWorldPosition_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_GridToWorldPosition()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_GridToWorldPosition_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridDungeonVisualizer::execGridToWorldPosition)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_X);
	P_GET_PROPERTY(FIntProperty,Z_Param_Y);
	P_GET_UBOOL(Z_Param_bIsFloor);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FVector*)Z_Param__Result=P_THIS->GridToWorldPosition(Z_Param_X,Z_Param_Y,Z_Param_bIsFloor);
	P_NATIVE_END;
}
// End Class AGridDungeonVisualizer Function GridToWorldPosition

// Begin Class AGridDungeonVisualizer Function IsValidGridPosition
struct Z_Construct_UFunction_AGridDungeonVisualizer_IsValidGridPosition_Statics
{
	struct GridDungeonVisualizer_eventIsValidGridPosition_Parms
	{
		int32 X;
		int32 Y;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Grid Dungeon" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_X;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Y;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_IsValidGridPosition_Statics::NewProp_X = { "X", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridDungeonVisualizer_eventIsValidGridPosition_Parms, X), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_IsValidGridPosition_Statics::NewProp_Y = { "Y", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridDungeonVisualizer_eventIsValidGridPosition_Parms, Y), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_AGridDungeonVisualizer_IsValidGridPosition_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((GridDungeonVisualizer_eventIsValidGridPosition_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_IsValidGridPosition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(GridDungeonVisualizer_eventIsValidGridPosition_Parms), &Z_Construct_UFunction_AGridDungeonVisualizer_IsValidGridPosition_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGridDungeonVisualizer_IsValidGridPosition_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_IsValidGridPosition_Statics::NewProp_X,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_IsValidGridPosition_Statics::NewProp_Y,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_IsValidGridPosition_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_IsValidGridPosition_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_IsValidGridPosition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "IsValidGridPosition", nullptr, nullptr, Z_Construct_UFunction_AGridDungeonVisualizer_IsValidGridPosition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_IsValidGridPosition_Statics::PropPointers), sizeof(Z_Construct_UFunction_AGridDungeonVisualizer_IsValidGridPosition_Statics::GridDungeonVisualizer_eventIsValidGridPosition_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_IsValidGridPosition_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_IsValidGridPosition_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AGridDungeonVisualizer_IsValidGridPosition_Statics::GridDungeonVisualizer_eventIsValidGridPosition_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_IsValidGridPosition()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_IsValidGridPosition_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridDungeonVisualizer::execIsValidGridPosition)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_X);
	P_GET_PROPERTY(FIntProperty,Z_Param_Y);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsValidGridPosition(Z_Param_X,Z_Param_Y);
	P_NATIVE_END;
}
// End Class AGridDungeonVisualizer Function IsValidGridPosition

// Begin Class AGridDungeonVisualizer Function MatchCubesToDebugBoxes
struct Z_Construct_UFunction_AGridDungeonVisualizer_MatchCubesToDebugBoxes_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Debug" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_MatchCubesToDebugBoxes_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "MatchCubesToDebugBoxes", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_MatchCubesToDebugBoxes_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_MatchCubesToDebugBoxes_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_MatchCubesToDebugBoxes()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_MatchCubesToDebugBoxes_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridDungeonVisualizer::execMatchCubesToDebugBoxes)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->MatchCubesToDebugBoxes();
	P_NATIVE_END;
}
// End Class AGridDungeonVisualizer Function MatchCubesToDebugBoxes

// Begin Class AGridDungeonVisualizer Function SetGridCell
struct Z_Construct_UFunction_AGridDungeonVisualizer_SetGridCell_Statics
{
	struct GridDungeonVisualizer_eventSetGridCell_Parms
	{
		int32 X;
		int32 Y;
		EGridCellType Type;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Grid Dungeon" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Grid Operations\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Grid Operations" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_X;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Y;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Type_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Type;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_SetGridCell_Statics::NewProp_X = { "X", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridDungeonVisualizer_eventSetGridCell_Parms, X), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_SetGridCell_Statics::NewProp_Y = { "Y", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridDungeonVisualizer_eventSetGridCell_Parms, Y), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_SetGridCell_Statics::NewProp_Type_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_SetGridCell_Statics::NewProp_Type = { "Type", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridDungeonVisualizer_eventSetGridCell_Parms, Type), Z_Construct_UEnum_EternalDescent_EGridCellType, METADATA_PARAMS(0, nullptr) }; // 1186920181
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGridDungeonVisualizer_SetGridCell_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_SetGridCell_Statics::NewProp_X,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_SetGridCell_Statics::NewProp_Y,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_SetGridCell_Statics::NewProp_Type_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_SetGridCell_Statics::NewProp_Type,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_SetGridCell_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_SetGridCell_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "SetGridCell", nullptr, nullptr, Z_Construct_UFunction_AGridDungeonVisualizer_SetGridCell_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_SetGridCell_Statics::PropPointers), sizeof(Z_Construct_UFunction_AGridDungeonVisualizer_SetGridCell_Statics::GridDungeonVisualizer_eventSetGridCell_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_SetGridCell_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_SetGridCell_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AGridDungeonVisualizer_SetGridCell_Statics::GridDungeonVisualizer_eventSetGridCell_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_SetGridCell()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_SetGridCell_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridDungeonVisualizer::execSetGridCell)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_X);
	P_GET_PROPERTY(FIntProperty,Z_Param_Y);
	P_GET_ENUM(EGridCellType,Z_Param_Type);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetGridCell(Z_Param_X,Z_Param_Y,EGridCellType(Z_Param_Type));
	P_NATIVE_END;
}
// End Class AGridDungeonVisualizer Function SetGridCell

// Begin Class AGridDungeonVisualizer Function TestAlternativeAlignment
struct Z_Construct_UFunction_AGridDungeonVisualizer_TestAlternativeAlignment_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Debug" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_TestAlternativeAlignment_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "TestAlternativeAlignment", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_TestAlternativeAlignment_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_TestAlternativeAlignment_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_TestAlternativeAlignment()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_TestAlternativeAlignment_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridDungeonVisualizer::execTestAlternativeAlignment)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->TestAlternativeAlignment();
	P_NATIVE_END;
}
// End Class AGridDungeonVisualizer Function TestAlternativeAlignment

// Begin Class AGridDungeonVisualizer Function TestGridAlignment
struct Z_Construct_UFunction_AGridDungeonVisualizer_TestGridAlignment_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Debug" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_TestGridAlignment_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "TestGridAlignment", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_TestGridAlignment_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_TestGridAlignment_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_TestGridAlignment()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_TestGridAlignment_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridDungeonVisualizer::execTestGridAlignment)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->TestGridAlignment();
	P_NATIVE_END;
}
// End Class AGridDungeonVisualizer Function TestGridAlignment

// Begin Class AGridDungeonVisualizer
void AGridDungeonVisualizer::StaticRegisterNativesAGridDungeonVisualizer()
{
	UClass* Class = AGridDungeonVisualizer::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ClearDungeon", &AGridDungeonVisualizer::execClearDungeon },
		{ "DrawDebugGrid", &AGridDungeonVisualizer::execDrawDebugGrid },
		{ "GenerateAndVisualizeDungeon", &AGridDungeonVisualizer::execGenerateAndVisualizeDungeon },
		{ "GenerateInEditor", &AGridDungeonVisualizer::execGenerateInEditor },
		{ "GetGridCell", &AGridDungeonVisualizer::execGetGridCell },
		{ "GridToWorldPosition", &AGridDungeonVisualizer::execGridToWorldPosition },
		{ "IsValidGridPosition", &AGridDungeonVisualizer::execIsValidGridPosition },
		{ "MatchCubesToDebugBoxes", &AGridDungeonVisualizer::execMatchCubesToDebugBoxes },
		{ "SetGridCell", &AGridDungeonVisualizer::execSetGridCell },
		{ "TestAlternativeAlignment", &AGridDungeonVisualizer::execTestAlternativeAlignment },
		{ "TestGridAlignment", &AGridDungeonVisualizer::execTestGridAlignment },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AGridDungeonVisualizer);
UClass* Z_Construct_UClass_AGridDungeonVisualizer_NoRegister()
{
	return AGridDungeonVisualizer::StaticClass();
}
struct Z_Construct_UClass_AGridDungeonVisualizer_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "GridDungeonVisualizer.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GridSizeX_MetaData[] = {
		{ "Category", "Grid Layout" },
		{ "ClampMax", "50" },
		{ "ClampMin", "2" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Grid Configuration\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Grid Configuration" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GridSizeY_MetaData[] = {
		{ "Category", "Grid Layout" },
		{ "ClampMax", "50" },
		{ "ClampMin", "2" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CellSize_MetaData[] = {
		{ "Category", "Grid Layout" },
		{ "ClampMax", "1000" },
		{ "ClampMin", "100" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CubeSizePercentage_MetaData[] = {
		{ "Category", "Grid Layout" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.1" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// 3.5 * 100 units per cell\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "3.5 * 100 units per cell" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlaneMesh_MetaData[] = {
		{ "Category", "Prefabs" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Prefabs\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Prefabs" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CubeMesh_MetaData[] = {
		{ "Category", "Prefabs" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// For floors\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "For floors" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FloorMaterial_MetaData[] = {
		{ "Category", "Visuals" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Visual Settings\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Visual Settings" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WallMaterial_MetaData[] = {
		{ "Category", "Visuals" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowDebugGrid_MetaData[] = {
		{ "Category", "Debug" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Debug Settings\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Debug Settings" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DebugLineThickness_MetaData[] = {
		{ "Category", "Debug" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DebugGridColor_MetaData[] = {
		{ "Category", "Debug" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlaneInstances_MetaData[] = {
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Components\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Components" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CubeInstances_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Grid_MetaData[] = {
		{ "Category", "Runtime" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Runtime Data\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Runtime Data" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_GridSizeX;
	static const UECodeGen_Private::FIntPropertyParams NewProp_GridSizeY;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CellSize;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CubeSizePercentage;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlaneMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CubeMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FloorMaterial;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WallMaterial;
	static void NewProp_bShowDebugGrid_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowDebugGrid;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DebugLineThickness;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DebugGridColor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlaneInstances;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CubeInstances;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Grid_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Grid;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_ClearDungeon, "ClearDungeon" }, // 3547271859
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_DrawDebugGrid, "DrawDebugGrid" }, // 2869966766
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_GenerateAndVisualizeDungeon, "GenerateAndVisualizeDungeon" }, // 2237856306
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_GenerateInEditor, "GenerateInEditor" }, // 2501310811
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_GetGridCell, "GetGridCell" }, // 982663425
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_GridToWorldPosition, "GridToWorldPosition" }, // 2646692030
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_IsValidGridPosition, "IsValidGridPosition" }, // 3376793452
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_MatchCubesToDebugBoxes, "MatchCubesToDebugBoxes" }, // 3506967339
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_SetGridCell, "SetGridCell" }, // 748086578
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_TestAlternativeAlignment, "TestAlternativeAlignment" }, // 3764426828
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_TestGridAlignment, "TestGridAlignment" }, // 2561120545
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGridDungeonVisualizer>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_GridSizeX = { "GridSizeX", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, GridSizeX), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GridSizeX_MetaData), NewProp_GridSizeX_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_GridSizeY = { "GridSizeY", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, GridSizeY), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GridSizeY_MetaData), NewProp_GridSizeY_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_CellSize = { "CellSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, CellSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CellSize_MetaData), NewProp_CellSize_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_CubeSizePercentage = { "CubeSizePercentage", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, CubeSizePercentage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CubeSizePercentage_MetaData), NewProp_CubeSizePercentage_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_PlaneMesh = { "PlaneMesh", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, PlaneMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlaneMesh_MetaData), NewProp_PlaneMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_CubeMesh = { "CubeMesh", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, CubeMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CubeMesh_MetaData), NewProp_CubeMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_FloorMaterial = { "FloorMaterial", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, FloorMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FloorMaterial_MetaData), NewProp_FloorMaterial_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_WallMaterial = { "WallMaterial", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, WallMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WallMaterial_MetaData), NewProp_WallMaterial_MetaData) };
void Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bShowDebugGrid_SetBit(void* Obj)
{
	((AGridDungeonVisualizer*)Obj)->bShowDebugGrid = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bShowDebugGrid = { "bShowDebugGrid", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AGridDungeonVisualizer), &Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bShowDebugGrid_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowDebugGrid_MetaData), NewProp_bShowDebugGrid_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_DebugLineThickness = { "DebugLineThickness", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, DebugLineThickness), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DebugLineThickness_MetaData), NewProp_DebugLineThickness_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_DebugGridColor = { "DebugGridColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, DebugGridColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DebugGridColor_MetaData), NewProp_DebugGridColor_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_PlaneInstances = { "PlaneInstances", nullptr, (EPropertyFlags)0x001000000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, PlaneInstances), Z_Construct_UClass_UInstancedStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlaneInstances_MetaData), NewProp_PlaneInstances_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_CubeInstances = { "CubeInstances", nullptr, (EPropertyFlags)0x001000000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, CubeInstances), Z_Construct_UClass_UInstancedStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CubeInstances_MetaData), NewProp_CubeInstances_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_Grid_Inner = { "Grid", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FGridCell, METADATA_PARAMS(0, nullptr) }; // 2314947957
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_Grid = { "Grid", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, Grid), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Grid_MetaData), NewProp_Grid_MetaData) }; // 2314947957
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGridDungeonVisualizer_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_GridSizeX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_GridSizeY,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_CellSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_CubeSizePercentage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_PlaneMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_CubeMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_FloorMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_WallMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bShowDebugGrid,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_DebugLineThickness,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_DebugGridColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_PlaneInstances,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_CubeInstances,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_Grid_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_Grid,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGridDungeonVisualizer_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AGridDungeonVisualizer_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_EternalDescent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGridDungeonVisualizer_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::ClassParams = {
	&AGridDungeonVisualizer::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AGridDungeonVisualizer_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AGridDungeonVisualizer_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGridDungeonVisualizer_Statics::Class_MetaDataParams), Z_Construct_UClass_AGridDungeonVisualizer_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AGridDungeonVisualizer()
{
	if (!Z_Registration_Info_UClass_AGridDungeonVisualizer.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AGridDungeonVisualizer.OuterSingleton, Z_Construct_UClass_AGridDungeonVisualizer_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AGridDungeonVisualizer.OuterSingleton;
}
template<> ETERNALDESCENT_API UClass* StaticClass<AGridDungeonVisualizer>()
{
	return AGridDungeonVisualizer::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AGridDungeonVisualizer);
AGridDungeonVisualizer::~AGridDungeonVisualizer() {}
// End Class AGridDungeonVisualizer

// Begin Registration
struct Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EGridCellType_StaticEnum, TEXT("EGridCellType"), &Z_Registration_Info_UEnum_EGridCellType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1186920181U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FGridCell::StaticStruct, Z_Construct_UScriptStruct_FGridCell_Statics::NewStructOps, TEXT("GridCell"), &Z_Registration_Info_UScriptStruct_GridCell, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FGridCell), 2314947957U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AGridDungeonVisualizer, AGridDungeonVisualizer::StaticClass, TEXT("AGridDungeonVisualizer"), &Z_Registration_Info_UClass_AGridDungeonVisualizer, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGridDungeonVisualizer), 49467013U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_3826432618(TEXT("/Script/EternalDescent"),
	Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
