// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EternalDescent/Public/GridDungeonVisualizer.h"
#include "EternalDescent/Public/SnakeDungeonGenerator.h"
#include "EternalDescent/Public/Tests/DungeonTestTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGridDungeonVisualizer() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntPoint();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UInstancedStaticMeshComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
ETERNALDESCENT_API UClass* Z_Construct_UClass_AADASystem_NoRegister();
ETERNALDESCENT_API UClass* Z_Construct_UClass_AGridDungeonVisualizer();
ETERNALDESCENT_API UClass* Z_Construct_UClass_AGridDungeonVisualizer_NoRegister();
ETERNALDESCENT_API UClass* Z_Construct_UClass_ASnakeDungeonGenerator_NoRegister();
ETERNALDESCENT_API UEnum* Z_Construct_UEnum_EternalDescent_EGridCellType();
ETERNALDESCENT_API UEnum* Z_Construct_UEnum_EternalDescent_ERoomType();
ETERNALDESCENT_API UScriptStruct* Z_Construct_UScriptStruct_FDungeonLayout();
ETERNALDESCENT_API UScriptStruct* Z_Construct_UScriptStruct_FGridCell();
ETERNALDESCENT_API UScriptStruct* Z_Construct_UScriptStruct_FHallwayConnection();
ETERNALDESCENT_API UScriptStruct* Z_Construct_UScriptStruct_FRoomData();
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
		{ "Door.Comment", "// Solid cube\n" },
		{ "Door.DisplayName", "Door" },
		{ "Door.Name", "EGridCellType::Door" },
		{ "Door.ToolTip", "Solid cube" },
		{ "Empty.DisplayName", "Empty" },
		{ "Empty.Name", "EGridCellType::Empty" },
		{ "Floor.Comment", "// Nothing (air)\n" },
		{ "Floor.DisplayName", "Floor" },
		{ "Floor.Name", "EGridCellType::Floor" },
		{ "Floor.ToolTip", "Nothing (air)" },
		{ "Hallway.Comment", "// Door position (plane)\n" },
		{ "Hallway.DisplayName", "Hallway" },
		{ "Hallway.Name", "EGridCellType::Hallway" },
		{ "Hallway.ToolTip", "Door position (plane)" },
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
		{ "EGridCellType::Door", (int64)EGridCellType::Door },
		{ "EGridCellType::Hallway", (int64)EGridCellType::Hallway },
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoomID_MetaData[] = {
		{ "Category", "GridCell" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoomType_MetaData[] = {
		{ "Category", "GridCell" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Which room this cell belongs to (-1 for walls/empty)\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Which room this cell belongs to (-1 for walls/empty)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_CellType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_CellType;
	static const UECodeGen_Private::FIntPropertyParams NewProp_RoomID;
	static const UECodeGen_Private::FBytePropertyParams NewProp_RoomType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_RoomType;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FGridCell>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FGridCell_Statics::NewProp_CellType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FGridCell_Statics::NewProp_CellType = { "CellType", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGridCell, CellType), Z_Construct_UEnum_EternalDescent_EGridCellType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CellType_MetaData), NewProp_CellType_MetaData) }; // 3357014927
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FGridCell_Statics::NewProp_RoomID = { "RoomID", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGridCell, RoomID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoomID_MetaData), NewProp_RoomID_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FGridCell_Statics::NewProp_RoomType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FGridCell_Statics::NewProp_RoomType = { "RoomType", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGridCell, RoomType), Z_Construct_UEnum_EternalDescent_ERoomType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoomType_MetaData), NewProp_RoomType_MetaData) }; // 1291513837
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FGridCell_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGridCell_Statics::NewProp_CellType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGridCell_Statics::NewProp_CellType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGridCell_Statics::NewProp_RoomID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGridCell_Statics::NewProp_RoomType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGridCell_Statics::NewProp_RoomType,
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

// Begin Class AGridDungeonVisualizer Function BuildGridFromLayout
struct Z_Construct_UFunction_AGridDungeonVisualizer_BuildGridFromLayout_Statics
{
	struct GridDungeonVisualizer_eventBuildGridFromLayout_Parms
	{
		FDungeonLayout Layout;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Grid Dungeon" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Layout_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Layout;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_BuildGridFromLayout_Statics::NewProp_Layout = { "Layout", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridDungeonVisualizer_eventBuildGridFromLayout_Parms, Layout), Z_Construct_UScriptStruct_FDungeonLayout, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Layout_MetaData), NewProp_Layout_MetaData) }; // 3903890264
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGridDungeonVisualizer_BuildGridFromLayout_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_BuildGridFromLayout_Statics::NewProp_Layout,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_BuildGridFromLayout_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_BuildGridFromLayout_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "BuildGridFromLayout", nullptr, nullptr, Z_Construct_UFunction_AGridDungeonVisualizer_BuildGridFromLayout_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_BuildGridFromLayout_Statics::PropPointers), sizeof(Z_Construct_UFunction_AGridDungeonVisualizer_BuildGridFromLayout_Statics::GridDungeonVisualizer_eventBuildGridFromLayout_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_BuildGridFromLayout_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_BuildGridFromLayout_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AGridDungeonVisualizer_BuildGridFromLayout_Statics::GridDungeonVisualizer_eventBuildGridFromLayout_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_BuildGridFromLayout()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_BuildGridFromLayout_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridDungeonVisualizer::execBuildGridFromLayout)
{
	P_GET_STRUCT_REF(FDungeonLayout,Z_Param_Out_Layout);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->BuildGridFromLayout(Z_Param_Out_Layout);
	P_NATIVE_END;
}
// End Class AGridDungeonVisualizer Function BuildGridFromLayout

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
		{ "Category", "Grid Dungeon" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Debug\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Debug" },
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
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_GetGridCell_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridDungeonVisualizer_eventGetGridCell_Parms, ReturnValue), Z_Construct_UScriptStruct_FGridCell, METADATA_PARAMS(0, nullptr) }; // 357869723
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

// Begin Class AGridDungeonVisualizer Function GetStartPosition
struct Z_Construct_UFunction_AGridDungeonVisualizer_GetStartPosition_Statics
{
	struct GridDungeonVisualizer_eventGetStartPosition_Parms
	{
		FVector ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Grid Dungeon" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_GetStartPosition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridDungeonVisualizer_eventGetStartPosition_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGridDungeonVisualizer_GetStartPosition_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_GetStartPosition_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_GetStartPosition_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_GetStartPosition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "GetStartPosition", nullptr, nullptr, Z_Construct_UFunction_AGridDungeonVisualizer_GetStartPosition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_GetStartPosition_Statics::PropPointers), sizeof(Z_Construct_UFunction_AGridDungeonVisualizer_GetStartPosition_Statics::GridDungeonVisualizer_eventGetStartPosition_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_GetStartPosition_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_GetStartPosition_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AGridDungeonVisualizer_GetStartPosition_Statics::GridDungeonVisualizer_eventGetStartPosition_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_GetStartPosition()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_GetStartPosition_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridDungeonVisualizer::execGetStartPosition)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FVector*)Z_Param__Result=P_THIS->GetStartPosition();
	P_NATIVE_END;
}
// End Class AGridDungeonVisualizer Function GetStartPosition

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
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Conversion Functions\n" },
#endif
		{ "CPP_Default_bIsFloor", "true" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Conversion Functions" },
#endif
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

// Begin Class AGridDungeonVisualizer Function OnTestChestSpawned
struct GridDungeonVisualizer_eventOnTestChestSpawned_Parms
{
	FVector Position;
	ERoomType RoomType;
};
static const FName NAME_AGridDungeonVisualizer_OnTestChestSpawned = FName(TEXT("OnTestChestSpawned"));
void AGridDungeonVisualizer::OnTestChestSpawned(FVector Position, ERoomType RoomType)
{
	GridDungeonVisualizer_eventOnTestChestSpawned_Parms Parms;
	Parms.Position=Position;
	Parms.RoomType=RoomType;
	UFunction* Func = FindFunctionChecked(NAME_AGridDungeonVisualizer_OnTestChestSpawned);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AGridDungeonVisualizer_OnTestChestSpawned_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Grid Dungeon" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Position;
	static const UECodeGen_Private::FBytePropertyParams NewProp_RoomType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_RoomType;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_OnTestChestSpawned_Statics::NewProp_Position = { "Position", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridDungeonVisualizer_eventOnTestChestSpawned_Parms, Position), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_OnTestChestSpawned_Statics::NewProp_RoomType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_OnTestChestSpawned_Statics::NewProp_RoomType = { "RoomType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridDungeonVisualizer_eventOnTestChestSpawned_Parms, RoomType), Z_Construct_UEnum_EternalDescent_ERoomType, METADATA_PARAMS(0, nullptr) }; // 1291513837
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGridDungeonVisualizer_OnTestChestSpawned_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_OnTestChestSpawned_Statics::NewProp_Position,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_OnTestChestSpawned_Statics::NewProp_RoomType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_OnTestChestSpawned_Statics::NewProp_RoomType,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_OnTestChestSpawned_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_OnTestChestSpawned_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "OnTestChestSpawned", nullptr, nullptr, Z_Construct_UFunction_AGridDungeonVisualizer_OnTestChestSpawned_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_OnTestChestSpawned_Statics::PropPointers), sizeof(GridDungeonVisualizer_eventOnTestChestSpawned_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08820800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_OnTestChestSpawned_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_OnTestChestSpawned_Statics::Function_MetaDataParams) };
static_assert(sizeof(GridDungeonVisualizer_eventOnTestChestSpawned_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_OnTestChestSpawned()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_OnTestChestSpawned_Statics::FuncParams);
	}
	return ReturnFunction;
}
// End Class AGridDungeonVisualizer Function OnTestChestSpawned

// Begin Class AGridDungeonVisualizer Function OnTestEnemySpawned
struct GridDungeonVisualizer_eventOnTestEnemySpawned_Parms
{
	FVector Position;
	ERoomType RoomType;
};
static const FName NAME_AGridDungeonVisualizer_OnTestEnemySpawned = FName(TEXT("OnTestEnemySpawned"));
void AGridDungeonVisualizer::OnTestEnemySpawned(FVector Position, ERoomType RoomType)
{
	GridDungeonVisualizer_eventOnTestEnemySpawned_Parms Parms;
	Parms.Position=Position;
	Parms.RoomType=RoomType;
	UFunction* Func = FindFunctionChecked(NAME_AGridDungeonVisualizer_OnTestEnemySpawned);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AGridDungeonVisualizer_OnTestEnemySpawned_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Grid Dungeon" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Position;
	static const UECodeGen_Private::FBytePropertyParams NewProp_RoomType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_RoomType;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_OnTestEnemySpawned_Statics::NewProp_Position = { "Position", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridDungeonVisualizer_eventOnTestEnemySpawned_Parms, Position), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_OnTestEnemySpawned_Statics::NewProp_RoomType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_OnTestEnemySpawned_Statics::NewProp_RoomType = { "RoomType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridDungeonVisualizer_eventOnTestEnemySpawned_Parms, RoomType), Z_Construct_UEnum_EternalDescent_ERoomType, METADATA_PARAMS(0, nullptr) }; // 1291513837
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGridDungeonVisualizer_OnTestEnemySpawned_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_OnTestEnemySpawned_Statics::NewProp_Position,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_OnTestEnemySpawned_Statics::NewProp_RoomType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_OnTestEnemySpawned_Statics::NewProp_RoomType,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_OnTestEnemySpawned_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_OnTestEnemySpawned_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "OnTestEnemySpawned", nullptr, nullptr, Z_Construct_UFunction_AGridDungeonVisualizer_OnTestEnemySpawned_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_OnTestEnemySpawned_Statics::PropPointers), sizeof(GridDungeonVisualizer_eventOnTestEnemySpawned_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08820800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_OnTestEnemySpawned_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_OnTestEnemySpawned_Statics::Function_MetaDataParams) };
static_assert(sizeof(GridDungeonVisualizer_eventOnTestEnemySpawned_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_OnTestEnemySpawned()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_OnTestEnemySpawned_Statics::FuncParams);
	}
	return ReturnFunction;
}
// End Class AGridDungeonVisualizer Function OnTestEnemySpawned

// Begin Class AGridDungeonVisualizer Function PlaceHallwayInGrid
struct Z_Construct_UFunction_AGridDungeonVisualizer_PlaceHallwayInGrid_Statics
{
	struct GridDungeonVisualizer_eventPlaceHallwayInGrid_Parms
	{
		FHallwayConnection Hallway;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Grid Dungeon" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Hallway_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Hallway;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_PlaceHallwayInGrid_Statics::NewProp_Hallway = { "Hallway", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridDungeonVisualizer_eventPlaceHallwayInGrid_Parms, Hallway), Z_Construct_UScriptStruct_FHallwayConnection, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Hallway_MetaData), NewProp_Hallway_MetaData) }; // 3960234035
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGridDungeonVisualizer_PlaceHallwayInGrid_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_PlaceHallwayInGrid_Statics::NewProp_Hallway,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_PlaceHallwayInGrid_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_PlaceHallwayInGrid_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "PlaceHallwayInGrid", nullptr, nullptr, Z_Construct_UFunction_AGridDungeonVisualizer_PlaceHallwayInGrid_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_PlaceHallwayInGrid_Statics::PropPointers), sizeof(Z_Construct_UFunction_AGridDungeonVisualizer_PlaceHallwayInGrid_Statics::GridDungeonVisualizer_eventPlaceHallwayInGrid_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_PlaceHallwayInGrid_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_PlaceHallwayInGrid_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AGridDungeonVisualizer_PlaceHallwayInGrid_Statics::GridDungeonVisualizer_eventPlaceHallwayInGrid_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_PlaceHallwayInGrid()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_PlaceHallwayInGrid_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridDungeonVisualizer::execPlaceHallwayInGrid)
{
	P_GET_STRUCT_REF(FHallwayConnection,Z_Param_Out_Hallway);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->PlaceHallwayInGrid(Z_Param_Out_Hallway);
	P_NATIVE_END;
}
// End Class AGridDungeonVisualizer Function PlaceHallwayInGrid

// Begin Class AGridDungeonVisualizer Function PlaceRoomInGrid
struct Z_Construct_UFunction_AGridDungeonVisualizer_PlaceRoomInGrid_Statics
{
	struct GridDungeonVisualizer_eventPlaceRoomInGrid_Parms
	{
		FRoomData Room;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Grid Dungeon" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Room Building\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Room Building" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Room_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Room;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_PlaceRoomInGrid_Statics::NewProp_Room = { "Room", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridDungeonVisualizer_eventPlaceRoomInGrid_Parms, Room), Z_Construct_UScriptStruct_FRoomData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Room_MetaData), NewProp_Room_MetaData) }; // 987753016
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGridDungeonVisualizer_PlaceRoomInGrid_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_PlaceRoomInGrid_Statics::NewProp_Room,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_PlaceRoomInGrid_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_PlaceRoomInGrid_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "PlaceRoomInGrid", nullptr, nullptr, Z_Construct_UFunction_AGridDungeonVisualizer_PlaceRoomInGrid_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_PlaceRoomInGrid_Statics::PropPointers), sizeof(Z_Construct_UFunction_AGridDungeonVisualizer_PlaceRoomInGrid_Statics::GridDungeonVisualizer_eventPlaceRoomInGrid_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_PlaceRoomInGrid_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_PlaceRoomInGrid_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AGridDungeonVisualizer_PlaceRoomInGrid_Statics::GridDungeonVisualizer_eventPlaceRoomInGrid_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_PlaceRoomInGrid()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_PlaceRoomInGrid_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridDungeonVisualizer::execPlaceRoomInGrid)
{
	P_GET_STRUCT_REF(FRoomData,Z_Param_Out_Room);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->PlaceRoomInGrid(Z_Param_Out_Room);
	P_NATIVE_END;
}
// End Class AGridDungeonVisualizer Function PlaceRoomInGrid

// Begin Class AGridDungeonVisualizer Function SetGridCell
struct Z_Construct_UFunction_AGridDungeonVisualizer_SetGridCell_Statics
{
	struct GridDungeonVisualizer_eventSetGridCell_Parms
	{
		int32 X;
		int32 Y;
		EGridCellType Type;
		int32 RoomID;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Grid Dungeon" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Grid Operations\n" },
#endif
		{ "CPP_Default_RoomID", "-1" },
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
	static const UECodeGen_Private::FIntPropertyParams NewProp_RoomID;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_SetGridCell_Statics::NewProp_X = { "X", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridDungeonVisualizer_eventSetGridCell_Parms, X), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_SetGridCell_Statics::NewProp_Y = { "Y", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridDungeonVisualizer_eventSetGridCell_Parms, Y), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_SetGridCell_Statics::NewProp_Type_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_SetGridCell_Statics::NewProp_Type = { "Type", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridDungeonVisualizer_eventSetGridCell_Parms, Type), Z_Construct_UEnum_EternalDescent_EGridCellType, METADATA_PARAMS(0, nullptr) }; // 3357014927
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_SetGridCell_Statics::NewProp_RoomID = { "RoomID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridDungeonVisualizer_eventSetGridCell_Parms, RoomID), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGridDungeonVisualizer_SetGridCell_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_SetGridCell_Statics::NewProp_X,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_SetGridCell_Statics::NewProp_Y,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_SetGridCell_Statics::NewProp_Type_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_SetGridCell_Statics::NewProp_Type,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_SetGridCell_Statics::NewProp_RoomID,
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
	P_GET_PROPERTY(FIntProperty,Z_Param_RoomID);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetGridCell(Z_Param_X,Z_Param_Y,EGridCellType(Z_Param_Type),Z_Param_RoomID);
	P_NATIVE_END;
}
// End Class AGridDungeonVisualizer Function SetGridCell

// Begin Class AGridDungeonVisualizer Function SpawnGridVisualization
struct Z_Construct_UFunction_AGridDungeonVisualizer_SpawnGridVisualization_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Grid Dungeon" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_SpawnGridVisualization_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "SpawnGridVisualization", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_SpawnGridVisualization_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_SpawnGridVisualization_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_SpawnGridVisualization()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_SpawnGridVisualization_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridDungeonVisualizer::execSpawnGridVisualization)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SpawnGridVisualization();
	P_NATIVE_END;
}
// End Class AGridDungeonVisualizer Function SpawnGridVisualization

// Begin Class AGridDungeonVisualizer Function SpawnPlayerAtStart
struct Z_Construct_UFunction_AGridDungeonVisualizer_SpawnPlayerAtStart_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Grid Dungeon" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Player Functions\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Player Functions" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_SpawnPlayerAtStart_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "SpawnPlayerAtStart", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_SpawnPlayerAtStart_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_SpawnPlayerAtStart_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_SpawnPlayerAtStart()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_SpawnPlayerAtStart_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridDungeonVisualizer::execSpawnPlayerAtStart)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SpawnPlayerAtStart();
	P_NATIVE_END;
}
// End Class AGridDungeonVisualizer Function SpawnPlayerAtStart

// Begin Class AGridDungeonVisualizer Function SpawnRoomContents
struct Z_Construct_UFunction_AGridDungeonVisualizer_SpawnRoomContents_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Grid Dungeon" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Content Spawning\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Content Spawning" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_SpawnRoomContents_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "SpawnRoomContents", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_SpawnRoomContents_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_SpawnRoomContents_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_SpawnRoomContents()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_SpawnRoomContents_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridDungeonVisualizer::execSpawnRoomContents)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SpawnRoomContents();
	P_NATIVE_END;
}
// End Class AGridDungeonVisualizer Function SpawnRoomContents

// Begin Class AGridDungeonVisualizer Function SpawnTestChestsInRoom
struct Z_Construct_UFunction_AGridDungeonVisualizer_SpawnTestChestsInRoom_Statics
{
	struct GridDungeonVisualizer_eventSpawnTestChestsInRoom_Parms
	{
		FRoomData Room;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Grid Dungeon" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Room_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Room;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_SpawnTestChestsInRoom_Statics::NewProp_Room = { "Room", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridDungeonVisualizer_eventSpawnTestChestsInRoom_Parms, Room), Z_Construct_UScriptStruct_FRoomData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Room_MetaData), NewProp_Room_MetaData) }; // 987753016
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGridDungeonVisualizer_SpawnTestChestsInRoom_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_SpawnTestChestsInRoom_Statics::NewProp_Room,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_SpawnTestChestsInRoom_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_SpawnTestChestsInRoom_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "SpawnTestChestsInRoom", nullptr, nullptr, Z_Construct_UFunction_AGridDungeonVisualizer_SpawnTestChestsInRoom_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_SpawnTestChestsInRoom_Statics::PropPointers), sizeof(Z_Construct_UFunction_AGridDungeonVisualizer_SpawnTestChestsInRoom_Statics::GridDungeonVisualizer_eventSpawnTestChestsInRoom_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_SpawnTestChestsInRoom_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_SpawnTestChestsInRoom_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AGridDungeonVisualizer_SpawnTestChestsInRoom_Statics::GridDungeonVisualizer_eventSpawnTestChestsInRoom_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_SpawnTestChestsInRoom()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_SpawnTestChestsInRoom_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridDungeonVisualizer::execSpawnTestChestsInRoom)
{
	P_GET_STRUCT_REF(FRoomData,Z_Param_Out_Room);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SpawnTestChestsInRoom(Z_Param_Out_Room);
	P_NATIVE_END;
}
// End Class AGridDungeonVisualizer Function SpawnTestChestsInRoom

// Begin Class AGridDungeonVisualizer Function SpawnTestEnemiesInRoom
struct Z_Construct_UFunction_AGridDungeonVisualizer_SpawnTestEnemiesInRoom_Statics
{
	struct GridDungeonVisualizer_eventSpawnTestEnemiesInRoom_Parms
	{
		FRoomData Room;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Grid Dungeon" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Room_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Room;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_SpawnTestEnemiesInRoom_Statics::NewProp_Room = { "Room", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridDungeonVisualizer_eventSpawnTestEnemiesInRoom_Parms, Room), Z_Construct_UScriptStruct_FRoomData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Room_MetaData), NewProp_Room_MetaData) }; // 987753016
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGridDungeonVisualizer_SpawnTestEnemiesInRoom_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_SpawnTestEnemiesInRoom_Statics::NewProp_Room,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_SpawnTestEnemiesInRoom_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_SpawnTestEnemiesInRoom_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "SpawnTestEnemiesInRoom", nullptr, nullptr, Z_Construct_UFunction_AGridDungeonVisualizer_SpawnTestEnemiesInRoom_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_SpawnTestEnemiesInRoom_Statics::PropPointers), sizeof(Z_Construct_UFunction_AGridDungeonVisualizer_SpawnTestEnemiesInRoom_Statics::GridDungeonVisualizer_eventSpawnTestEnemiesInRoom_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_SpawnTestEnemiesInRoom_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_SpawnTestEnemiesInRoom_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AGridDungeonVisualizer_SpawnTestEnemiesInRoom_Statics::GridDungeonVisualizer_eventSpawnTestEnemiesInRoom_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_SpawnTestEnemiesInRoom()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_SpawnTestEnemiesInRoom_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridDungeonVisualizer::execSpawnTestEnemiesInRoom)
{
	P_GET_STRUCT_REF(FRoomData,Z_Param_Out_Room);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SpawnTestEnemiesInRoom(Z_Param_Out_Room);
	P_NATIVE_END;
}
// End Class AGridDungeonVisualizer Function SpawnTestEnemiesInRoom

// Begin Class AGridDungeonVisualizer Function WorldToGridPosition
struct Z_Construct_UFunction_AGridDungeonVisualizer_WorldToGridPosition_Statics
{
	struct GridDungeonVisualizer_eventWorldToGridPosition_Parms
	{
		FVector WorldPos;
		FIntPoint ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Grid Dungeon" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_WorldPos;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_WorldToGridPosition_Statics::NewProp_WorldPos = { "WorldPos", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridDungeonVisualizer_eventWorldToGridPosition_Parms, WorldPos), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_WorldToGridPosition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridDungeonVisualizer_eventWorldToGridPosition_Parms, ReturnValue), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGridDungeonVisualizer_WorldToGridPosition_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_WorldToGridPosition_Statics::NewProp_WorldPos,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_WorldToGridPosition_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_WorldToGridPosition_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_WorldToGridPosition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "WorldToGridPosition", nullptr, nullptr, Z_Construct_UFunction_AGridDungeonVisualizer_WorldToGridPosition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_WorldToGridPosition_Statics::PropPointers), sizeof(Z_Construct_UFunction_AGridDungeonVisualizer_WorldToGridPosition_Statics::GridDungeonVisualizer_eventWorldToGridPosition_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_WorldToGridPosition_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_WorldToGridPosition_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AGridDungeonVisualizer_WorldToGridPosition_Statics::GridDungeonVisualizer_eventWorldToGridPosition_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_WorldToGridPosition()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_WorldToGridPosition_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridDungeonVisualizer::execWorldToGridPosition)
{
	P_GET_STRUCT(FVector,Z_Param_WorldPos);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FIntPoint*)Z_Param__Result=P_THIS->WorldToGridPosition(Z_Param_WorldPos);
	P_NATIVE_END;
}
// End Class AGridDungeonVisualizer Function WorldToGridPosition

// Begin Class AGridDungeonVisualizer
void AGridDungeonVisualizer::StaticRegisterNativesAGridDungeonVisualizer()
{
	UClass* Class = AGridDungeonVisualizer::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "BuildGridFromLayout", &AGridDungeonVisualizer::execBuildGridFromLayout },
		{ "ClearDungeon", &AGridDungeonVisualizer::execClearDungeon },
		{ "DrawDebugGrid", &AGridDungeonVisualizer::execDrawDebugGrid },
		{ "GenerateAndVisualizeDungeon", &AGridDungeonVisualizer::execGenerateAndVisualizeDungeon },
		{ "GetGridCell", &AGridDungeonVisualizer::execGetGridCell },
		{ "GetStartPosition", &AGridDungeonVisualizer::execGetStartPosition },
		{ "GridToWorldPosition", &AGridDungeonVisualizer::execGridToWorldPosition },
		{ "IsValidGridPosition", &AGridDungeonVisualizer::execIsValidGridPosition },
		{ "PlaceHallwayInGrid", &AGridDungeonVisualizer::execPlaceHallwayInGrid },
		{ "PlaceRoomInGrid", &AGridDungeonVisualizer::execPlaceRoomInGrid },
		{ "SetGridCell", &AGridDungeonVisualizer::execSetGridCell },
		{ "SpawnGridVisualization", &AGridDungeonVisualizer::execSpawnGridVisualization },
		{ "SpawnPlayerAtStart", &AGridDungeonVisualizer::execSpawnPlayerAtStart },
		{ "SpawnRoomContents", &AGridDungeonVisualizer::execSpawnRoomContents },
		{ "SpawnTestChestsInRoom", &AGridDungeonVisualizer::execSpawnTestChestsInRoom },
		{ "SpawnTestEnemiesInRoom", &AGridDungeonVisualizer::execSpawnTestEnemiesInRoom },
		{ "WorldToGridPosition", &AGridDungeonVisualizer::execWorldToGridPosition },
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
		{ "Category", "Grid Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Properties\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Properties" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GridSizeY_MetaData[] = {
		{ "Category", "Grid Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Total grid width\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Total grid width" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CellSize_MetaData[] = {
		{ "Category", "Grid Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Total grid height\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Total grid height" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WallHeight_MetaData[] = {
		{ "Category", "Grid Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Size of each grid cell in world units\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Size of each grid cell in world units" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutoGenerateOnBeginPlay_MetaData[] = {
		{ "Category", "Grid Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Height of wall cubes\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Height of wall cubes" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentFloor_MetaData[] = {
		{ "Category", "Grid Settings" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlaneMesh_MetaData[] = {
		{ "Category", "Prefabs" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Prefabs (only 2 needed!)\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Prefabs (only 2 needed!)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CubeMesh_MetaData[] = {
		{ "Category", "Prefabs" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// For floors/walkable spaces\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "For floors/walkable spaces" },
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HallwayMaterial_MetaData[] = {
		{ "Category", "Visuals" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpecialRoomMaterial_MetaData[] = {
		{ "Category", "Visuals" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TestEnemyMesh_MetaData[] = {
		{ "Category", "Test Content" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Test Content Prefabs\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Test Content Prefabs" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TestChestMesh_MetaData[] = {
		{ "Category", "Test Content" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Simple mesh to represent enemies\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Simple mesh to represent enemies" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TestEnemyMaterial_MetaData[] = {
		{ "Category", "Test Content" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Simple mesh to represent chests\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Simple mesh to represent chests" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TestChestMaterial_MetaData[] = {
		{ "Category", "Test Content" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TestEnemyScale_MetaData[] = {
		{ "Category", "Test Content" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TestChestScale_MetaData[] = {
		{ "Category", "Test Content" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DungeonGenerator_MetaData[] = {
		{ "Category", "References" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// References\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "References" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ADASystem_MetaData[] = {
		{ "Category", "References" },
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentLayout_MetaData[] = {
		{ "Category", "Runtime" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// 1D array representing 2D grid\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "1D array representing 2D grid" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StartRoomGridPos_MetaData[] = {
		{ "Category", "Runtime" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExitRoomGridPos_MetaData[] = {
		{ "Category", "Runtime" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlaneInstances_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Instanced mesh components for performance\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Instanced mesh components for performance" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CubeInstances_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// All floor planes\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "All floor planes" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TestEnemyInstances_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// All wall cubes\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "All wall cubes" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TestChestInstances_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Test enemy representations\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Test enemy representations" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_GridSizeX;
	static const UECodeGen_Private::FIntPropertyParams NewProp_GridSizeY;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CellSize;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WallHeight;
	static void NewProp_bAutoGenerateOnBeginPlay_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoGenerateOnBeginPlay;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentFloor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlaneMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CubeMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FloorMaterial;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WallMaterial;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HallwayMaterial;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpecialRoomMaterial;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TestEnemyMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TestChestMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TestEnemyMaterial;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TestChestMaterial;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TestEnemyScale;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TestChestScale;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DungeonGenerator;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ADASystem;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Grid_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Grid;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CurrentLayout;
	static const UECodeGen_Private::FStructPropertyParams NewProp_StartRoomGridPos;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ExitRoomGridPos;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlaneInstances;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CubeInstances;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TestEnemyInstances;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TestChestInstances;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_BuildGridFromLayout, "BuildGridFromLayout" }, // 1493721323
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_ClearDungeon, "ClearDungeon" }, // 3547271859
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_DrawDebugGrid, "DrawDebugGrid" }, // 778072285
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_GenerateAndVisualizeDungeon, "GenerateAndVisualizeDungeon" }, // 2237856306
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_GetGridCell, "GetGridCell" }, // 1374691265
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_GetStartPosition, "GetStartPosition" }, // 1733970434
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_GridToWorldPosition, "GridToWorldPosition" }, // 1370963437
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_IsValidGridPosition, "IsValidGridPosition" }, // 3376793452
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_OnTestChestSpawned, "OnTestChestSpawned" }, // 2857963953
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_OnTestEnemySpawned, "OnTestEnemySpawned" }, // 81384815
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_PlaceHallwayInGrid, "PlaceHallwayInGrid" }, // 3025046406
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_PlaceRoomInGrid, "PlaceRoomInGrid" }, // 3695893506
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_SetGridCell, "SetGridCell" }, // 1300402336
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_SpawnGridVisualization, "SpawnGridVisualization" }, // 3357062006
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_SpawnPlayerAtStart, "SpawnPlayerAtStart" }, // 1533279445
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_SpawnRoomContents, "SpawnRoomContents" }, // 1362863565
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_SpawnTestChestsInRoom, "SpawnTestChestsInRoom" }, // 3559755509
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_SpawnTestEnemiesInRoom, "SpawnTestEnemiesInRoom" }, // 876117065
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_WorldToGridPosition, "WorldToGridPosition" }, // 3633239547
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
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_WallHeight = { "WallHeight", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, WallHeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WallHeight_MetaData), NewProp_WallHeight_MetaData) };
void Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bAutoGenerateOnBeginPlay_SetBit(void* Obj)
{
	((AGridDungeonVisualizer*)Obj)->bAutoGenerateOnBeginPlay = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bAutoGenerateOnBeginPlay = { "bAutoGenerateOnBeginPlay", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AGridDungeonVisualizer), &Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bAutoGenerateOnBeginPlay_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutoGenerateOnBeginPlay_MetaData), NewProp_bAutoGenerateOnBeginPlay_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_CurrentFloor = { "CurrentFloor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, CurrentFloor), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentFloor_MetaData), NewProp_CurrentFloor_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_PlaneMesh = { "PlaneMesh", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, PlaneMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlaneMesh_MetaData), NewProp_PlaneMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_CubeMesh = { "CubeMesh", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, CubeMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CubeMesh_MetaData), NewProp_CubeMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_FloorMaterial = { "FloorMaterial", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, FloorMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FloorMaterial_MetaData), NewProp_FloorMaterial_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_WallMaterial = { "WallMaterial", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, WallMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WallMaterial_MetaData), NewProp_WallMaterial_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_HallwayMaterial = { "HallwayMaterial", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, HallwayMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HallwayMaterial_MetaData), NewProp_HallwayMaterial_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_SpecialRoomMaterial = { "SpecialRoomMaterial", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, SpecialRoomMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpecialRoomMaterial_MetaData), NewProp_SpecialRoomMaterial_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_TestEnemyMesh = { "TestEnemyMesh", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, TestEnemyMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TestEnemyMesh_MetaData), NewProp_TestEnemyMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_TestChestMesh = { "TestChestMesh", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, TestChestMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TestChestMesh_MetaData), NewProp_TestChestMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_TestEnemyMaterial = { "TestEnemyMaterial", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, TestEnemyMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TestEnemyMaterial_MetaData), NewProp_TestEnemyMaterial_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_TestChestMaterial = { "TestChestMaterial", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, TestChestMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TestChestMaterial_MetaData), NewProp_TestChestMaterial_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_TestEnemyScale = { "TestEnemyScale", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, TestEnemyScale), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TestEnemyScale_MetaData), NewProp_TestEnemyScale_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_TestChestScale = { "TestChestScale", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, TestChestScale), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TestChestScale_MetaData), NewProp_TestChestScale_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_DungeonGenerator = { "DungeonGenerator", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, DungeonGenerator), Z_Construct_UClass_ASnakeDungeonGenerator_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DungeonGenerator_MetaData), NewProp_DungeonGenerator_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_ADASystem = { "ADASystem", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, ADASystem), Z_Construct_UClass_AADASystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ADASystem_MetaData), NewProp_ADASystem_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_Grid_Inner = { "Grid", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FGridCell, METADATA_PARAMS(0, nullptr) }; // 357869723
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_Grid = { "Grid", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, Grid), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Grid_MetaData), NewProp_Grid_MetaData) }; // 357869723
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_CurrentLayout = { "CurrentLayout", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, CurrentLayout), Z_Construct_UScriptStruct_FDungeonLayout, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentLayout_MetaData), NewProp_CurrentLayout_MetaData) }; // 3903890264
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_StartRoomGridPos = { "StartRoomGridPos", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, StartRoomGridPos), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StartRoomGridPos_MetaData), NewProp_StartRoomGridPos_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_ExitRoomGridPos = { "ExitRoomGridPos", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, ExitRoomGridPos), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExitRoomGridPos_MetaData), NewProp_ExitRoomGridPos_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_PlaneInstances = { "PlaneInstances", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, PlaneInstances), Z_Construct_UClass_UInstancedStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlaneInstances_MetaData), NewProp_PlaneInstances_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_CubeInstances = { "CubeInstances", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, CubeInstances), Z_Construct_UClass_UInstancedStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CubeInstances_MetaData), NewProp_CubeInstances_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_TestEnemyInstances = { "TestEnemyInstances", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, TestEnemyInstances), Z_Construct_UClass_UInstancedStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TestEnemyInstances_MetaData), NewProp_TestEnemyInstances_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_TestChestInstances = { "TestChestInstances", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, TestChestInstances), Z_Construct_UClass_UInstancedStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TestChestInstances_MetaData), NewProp_TestChestInstances_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGridDungeonVisualizer_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_GridSizeX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_GridSizeY,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_CellSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_WallHeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bAutoGenerateOnBeginPlay,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_CurrentFloor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_PlaneMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_CubeMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_FloorMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_WallMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_HallwayMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_SpecialRoomMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_TestEnemyMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_TestChestMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_TestEnemyMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_TestChestMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_TestEnemyScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_TestChestScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_DungeonGenerator,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_ADASystem,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_Grid_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_Grid,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_CurrentLayout,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_StartRoomGridPos,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_ExitRoomGridPos,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_PlaneInstances,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_CubeInstances,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_TestEnemyInstances,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_TestChestInstances,
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
		{ EGridCellType_StaticEnum, TEXT("EGridCellType"), &Z_Registration_Info_UEnum_EGridCellType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3357014927U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FGridCell::StaticStruct, Z_Construct_UScriptStruct_FGridCell_Statics::NewStructOps, TEXT("GridCell"), &Z_Registration_Info_UScriptStruct_GridCell, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FGridCell), 357869723U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AGridDungeonVisualizer, AGridDungeonVisualizer::StaticClass, TEXT("AGridDungeonVisualizer"), &Z_Registration_Info_UClass_AGridDungeonVisualizer, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGridDungeonVisualizer), 3492978316U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_993070519(TEXT("/Script/EternalDescent"),
	Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
