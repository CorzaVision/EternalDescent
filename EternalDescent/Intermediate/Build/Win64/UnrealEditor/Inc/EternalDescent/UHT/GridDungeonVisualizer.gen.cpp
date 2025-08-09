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
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntPoint();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UHierarchicalInstancedStaticMeshComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
ETERNALDESCENT_API UClass* Z_Construct_UClass_AGridDungeonVisualizer();
ETERNALDESCENT_API UClass* Z_Construct_UClass_AGridDungeonVisualizer_NoRegister();
ETERNALDESCENT_API UEnum* Z_Construct_UEnum_EternalDescent_EGenerationPhase();
ETERNALDESCENT_API UEnum* Z_Construct_UEnum_EternalDescent_EGridCellType();
ETERNALDESCENT_API UEnum* Z_Construct_UEnum_EternalDescent_ERoomSizeType();
ETERNALDESCENT_API UScriptStruct* Z_Construct_UScriptStruct_FGridCell();
ETERNALDESCENT_API UScriptStruct* Z_Construct_UScriptStruct_FGridRoomInfo();
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

// Begin Enum ERoomSizeType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ERoomSizeType;
static UEnum* ERoomSizeType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ERoomSizeType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ERoomSizeType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_EternalDescent_ERoomSizeType, (UObject*)Z_Construct_UPackage__Script_EternalDescent(), TEXT("ERoomSizeType"));
	}
	return Z_Registration_Info_UEnum_ERoomSizeType.OuterSingleton;
}
template<> ETERNALDESCENT_API UEnum* StaticEnum<ERoomSizeType>()
{
	return ERoomSizeType_StaticEnum();
}
struct Z_Construct_UEnum_EternalDescent_ERoomSizeType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
		{ "None.DisplayName", "None" },
		{ "None.Name", "ERoomSizeType::None" },
		{ "Small_2x2.DisplayName", "2x2 Room" },
		{ "Small_2x2.Name", "ERoomSizeType::Small_2x2" },
		{ "Standard_3x3.DisplayName", "3x3 Room" },
		{ "Standard_3x3.Name", "ERoomSizeType::Standard_3x3" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ERoomSizeType::None", (int64)ERoomSizeType::None },
		{ "ERoomSizeType::Small_2x2", (int64)ERoomSizeType::Small_2x2 },
		{ "ERoomSizeType::Standard_3x3", (int64)ERoomSizeType::Standard_3x3 },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_EternalDescent_ERoomSizeType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_EternalDescent,
	nullptr,
	"ERoomSizeType",
	"ERoomSizeType",
	Z_Construct_UEnum_EternalDescent_ERoomSizeType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_EternalDescent_ERoomSizeType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_EternalDescent_ERoomSizeType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_EternalDescent_ERoomSizeType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_EternalDescent_ERoomSizeType()
{
	if (!Z_Registration_Info_UEnum_ERoomSizeType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ERoomSizeType.InnerSingleton, Z_Construct_UEnum_EternalDescent_ERoomSizeType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ERoomSizeType.InnerSingleton;
}
// End Enum ERoomSizeType

// Begin Enum EGenerationPhase
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EGenerationPhase;
static UEnum* EGenerationPhase_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EGenerationPhase.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EGenerationPhase.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_EternalDescent_EGenerationPhase, (UObject*)Z_Construct_UPackage__Script_EternalDescent(), TEXT("EGenerationPhase"));
	}
	return Z_Registration_Info_UEnum_EGenerationPhase.OuterSingleton;
}
template<> ETERNALDESCENT_API UEnum* StaticEnum<EGenerationPhase>()
{
	return EGenerationPhase_StaticEnum();
}
struct Z_Construct_UEnum_EternalDescent_EGenerationPhase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Complete.DisplayName", "Complete" },
		{ "Complete.Name", "EGenerationPhase::Complete" },
		{ "GeneratingPath.DisplayName", "Generating Path" },
		{ "GeneratingPath.Name", "EGenerationPhase::GeneratingPath" },
		{ "Idle.DisplayName", "Idle" },
		{ "Idle.Name", "EGenerationPhase::Idle" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
		{ "SpawningCubes.DisplayName", "Spawning Cubes" },
		{ "SpawningCubes.Name", "EGenerationPhase::SpawningCubes" },
		{ "SpawningPlanes.DisplayName", "Spawning Planes" },
		{ "SpawningPlanes.Name", "EGenerationPhase::SpawningPlanes" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EGenerationPhase::Idle", (int64)EGenerationPhase::Idle },
		{ "EGenerationPhase::GeneratingPath", (int64)EGenerationPhase::GeneratingPath },
		{ "EGenerationPhase::SpawningCubes", (int64)EGenerationPhase::SpawningCubes },
		{ "EGenerationPhase::SpawningPlanes", (int64)EGenerationPhase::SpawningPlanes },
		{ "EGenerationPhase::Complete", (int64)EGenerationPhase::Complete },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_EternalDescent_EGenerationPhase_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_EternalDescent,
	nullptr,
	"EGenerationPhase",
	"EGenerationPhase",
	Z_Construct_UEnum_EternalDescent_EGenerationPhase_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_EternalDescent_EGenerationPhase_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_EternalDescent_EGenerationPhase_Statics::Enum_MetaDataParams), Z_Construct_UEnum_EternalDescent_EGenerationPhase_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_EternalDescent_EGenerationPhase()
{
	if (!Z_Registration_Info_UEnum_EGenerationPhase.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EGenerationPhase.InnerSingleton, Z_Construct_UEnum_EternalDescent_EGenerationPhase_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EGenerationPhase.InnerSingleton;
}
// End Enum EGenerationPhase

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

// Begin ScriptStruct FGridRoomInfo
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_GridRoomInfo;
class UScriptStruct* FGridRoomInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_GridRoomInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_GridRoomInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FGridRoomInfo, (UObject*)Z_Construct_UPackage__Script_EternalDescent(), TEXT("GridRoomInfo"));
	}
	return Z_Registration_Info_UScriptStruct_GridRoomInfo.OuterSingleton;
}
template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<FGridRoomInfo>()
{
	return FGridRoomInfo::StaticStruct();
}
struct Z_Construct_UScriptStruct_FGridRoomInfo_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoomSize_MetaData[] = {
		{ "Category", "GridRoomInfo" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsStartRoom_MetaData[] = {
		{ "Category", "GridRoomInfo" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsEndRoom_MetaData[] = {
		{ "Category", "GridRoomInfo" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Center_MetaData[] = {
		{ "Category", "GridRoomInfo" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_RoomSize_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_RoomSize;
	static void NewProp_bIsStartRoom_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsStartRoom;
	static void NewProp_bIsEndRoom_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsEndRoom;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Center;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FGridRoomInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FGridRoomInfo_Statics::NewProp_RoomSize_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FGridRoomInfo_Statics::NewProp_RoomSize = { "RoomSize", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGridRoomInfo, RoomSize), Z_Construct_UEnum_EternalDescent_ERoomSizeType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoomSize_MetaData), NewProp_RoomSize_MetaData) }; // 4214052988
void Z_Construct_UScriptStruct_FGridRoomInfo_Statics::NewProp_bIsStartRoom_SetBit(void* Obj)
{
	((FGridRoomInfo*)Obj)->bIsStartRoom = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FGridRoomInfo_Statics::NewProp_bIsStartRoom = { "bIsStartRoom", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FGridRoomInfo), &Z_Construct_UScriptStruct_FGridRoomInfo_Statics::NewProp_bIsStartRoom_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsStartRoom_MetaData), NewProp_bIsStartRoom_MetaData) };
void Z_Construct_UScriptStruct_FGridRoomInfo_Statics::NewProp_bIsEndRoom_SetBit(void* Obj)
{
	((FGridRoomInfo*)Obj)->bIsEndRoom = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FGridRoomInfo_Statics::NewProp_bIsEndRoom = { "bIsEndRoom", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FGridRoomInfo), &Z_Construct_UScriptStruct_FGridRoomInfo_Statics::NewProp_bIsEndRoom_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsEndRoom_MetaData), NewProp_bIsEndRoom_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FGridRoomInfo_Statics::NewProp_Center = { "Center", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGridRoomInfo, Center), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Center_MetaData), NewProp_Center_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FGridRoomInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGridRoomInfo_Statics::NewProp_RoomSize_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGridRoomInfo_Statics::NewProp_RoomSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGridRoomInfo_Statics::NewProp_bIsStartRoom,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGridRoomInfo_Statics::NewProp_bIsEndRoom,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGridRoomInfo_Statics::NewProp_Center,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGridRoomInfo_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FGridRoomInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_EternalDescent,
	nullptr,
	&NewStructOps,
	"GridRoomInfo",
	Z_Construct_UScriptStruct_FGridRoomInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGridRoomInfo_Statics::PropPointers),
	sizeof(FGridRoomInfo),
	alignof(FGridRoomInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGridRoomInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FGridRoomInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FGridRoomInfo()
{
	if (!Z_Registration_Info_UScriptStruct_GridRoomInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_GridRoomInfo.InnerSingleton, Z_Construct_UScriptStruct_FGridRoomInfo_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_GridRoomInfo.InnerSingleton;
}
// End ScriptStruct FGridRoomInfo

// Begin Class AGridDungeonVisualizer Function AnimateSnakeGeneration
#if WITH_EDITOR
struct Z_Construct_UFunction_AGridDungeonVisualizer_AnimateSnakeGeneration_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Snake Generation|Animation" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_AnimateSnakeGeneration_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "AnimateSnakeGeneration", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x24020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_AnimateSnakeGeneration_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_AnimateSnakeGeneration_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_AnimateSnakeGeneration()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_AnimateSnakeGeneration_Statics::FuncParams);
	}
	return ReturnFunction;
}
#endif // WITH_EDITOR
#if WITH_EDITOR
DEFINE_FUNCTION(AGridDungeonVisualizer::execAnimateSnakeGeneration)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AnimateSnakeGeneration();
	P_NATIVE_END;
}
#endif // WITH_EDITOR
// End Class AGridDungeonVisualizer Function AnimateSnakeGeneration

// Begin Class AGridDungeonVisualizer Function AutoClearDebugAfterGeneration
struct Z_Construct_UFunction_AGridDungeonVisualizer_AutoClearDebugAfterGeneration_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Snake Generation|Debug" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_AutoClearDebugAfterGeneration_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "AutoClearDebugAfterGeneration", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_AutoClearDebugAfterGeneration_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_AutoClearDebugAfterGeneration_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_AutoClearDebugAfterGeneration()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_AutoClearDebugAfterGeneration_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridDungeonVisualizer::execAutoClearDebugAfterGeneration)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AutoClearDebugAfterGeneration();
	P_NATIVE_END;
}
// End Class AGridDungeonVisualizer Function AutoClearDebugAfterGeneration

// Begin Class AGridDungeonVisualizer Function CalculateGridSizeInEditor
struct Z_Construct_UFunction_AGridDungeonVisualizer_CalculateGridSizeInEditor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Grid Layout" },
		{ "DisplayName", "Calculate Grid Size" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_CalculateGridSizeInEditor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "CalculateGridSizeInEditor", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_CalculateGridSizeInEditor_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_CalculateGridSizeInEditor_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_CalculateGridSizeInEditor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_CalculateGridSizeInEditor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridDungeonVisualizer::execCalculateGridSizeInEditor)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CalculateGridSizeInEditor();
	P_NATIVE_END;
}
// End Class AGridDungeonVisualizer Function CalculateGridSizeInEditor

// Begin Class AGridDungeonVisualizer Function CalculateOptimalGridSize
struct Z_Construct_UFunction_AGridDungeonVisualizer_CalculateOptimalGridSize_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Grid Layout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Grid Size Calculation\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Grid Size Calculation" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_CalculateOptimalGridSize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "CalculateOptimalGridSize", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_CalculateOptimalGridSize_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_CalculateOptimalGridSize_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_CalculateOptimalGridSize()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_CalculateOptimalGridSize_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridDungeonVisualizer::execCalculateOptimalGridSize)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CalculateOptimalGridSize();
	P_NATIVE_END;
}
// End Class AGridDungeonVisualizer Function CalculateOptimalGridSize

// Begin Class AGridDungeonVisualizer Function CalculateRequiredDistance
struct Z_Construct_UFunction_AGridDungeonVisualizer_CalculateRequiredDistance_Statics
{
	struct GridDungeonVisualizer_eventCalculateRequiredDistance_Parms
	{
		ERoomSizeType Room1Size;
		ERoomSizeType Room2Size;
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Mixed Room Validation" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_Room1Size_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Room1Size;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Room2Size_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Room2Size;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_CalculateRequiredDistance_Statics::NewProp_Room1Size_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_CalculateRequiredDistance_Statics::NewProp_Room1Size = { "Room1Size", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridDungeonVisualizer_eventCalculateRequiredDistance_Parms, Room1Size), Z_Construct_UEnum_EternalDescent_ERoomSizeType, METADATA_PARAMS(0, nullptr) }; // 4214052988
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_CalculateRequiredDistance_Statics::NewProp_Room2Size_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_CalculateRequiredDistance_Statics::NewProp_Room2Size = { "Room2Size", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridDungeonVisualizer_eventCalculateRequiredDistance_Parms, Room2Size), Z_Construct_UEnum_EternalDescent_ERoomSizeType, METADATA_PARAMS(0, nullptr) }; // 4214052988
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_CalculateRequiredDistance_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridDungeonVisualizer_eventCalculateRequiredDistance_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGridDungeonVisualizer_CalculateRequiredDistance_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_CalculateRequiredDistance_Statics::NewProp_Room1Size_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_CalculateRequiredDistance_Statics::NewProp_Room1Size,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_CalculateRequiredDistance_Statics::NewProp_Room2Size_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_CalculateRequiredDistance_Statics::NewProp_Room2Size,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_CalculateRequiredDistance_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_CalculateRequiredDistance_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_CalculateRequiredDistance_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "CalculateRequiredDistance", nullptr, nullptr, Z_Construct_UFunction_AGridDungeonVisualizer_CalculateRequiredDistance_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_CalculateRequiredDistance_Statics::PropPointers), sizeof(Z_Construct_UFunction_AGridDungeonVisualizer_CalculateRequiredDistance_Statics::GridDungeonVisualizer_eventCalculateRequiredDistance_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_CalculateRequiredDistance_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_CalculateRequiredDistance_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AGridDungeonVisualizer_CalculateRequiredDistance_Statics::GridDungeonVisualizer_eventCalculateRequiredDistance_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_CalculateRequiredDistance()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_CalculateRequiredDistance_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridDungeonVisualizer::execCalculateRequiredDistance)
{
	P_GET_ENUM(ERoomSizeType,Z_Param_Room1Size);
	P_GET_ENUM(ERoomSizeType,Z_Param_Room2Size);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->CalculateRequiredDistance(ERoomSizeType(Z_Param_Room1Size),ERoomSizeType(Z_Param_Room2Size));
	P_NATIVE_END;
}
// End Class AGridDungeonVisualizer Function CalculateRequiredDistance

// Begin Class AGridDungeonVisualizer Function ClearDebugVisualization
struct Z_Construct_UFunction_AGridDungeonVisualizer_ClearDebugVisualization_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Snake Generation|Debug" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_ClearDebugVisualization_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "ClearDebugVisualization", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_ClearDebugVisualization_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_ClearDebugVisualization_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_ClearDebugVisualization()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_ClearDebugVisualization_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridDungeonVisualizer::execClearDebugVisualization)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClearDebugVisualization();
	P_NATIVE_END;
}
// End Class AGridDungeonVisualizer Function ClearDebugVisualization

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

// Begin Class AGridDungeonVisualizer Function ClearInEditor
#if WITH_EDITOR
struct Z_Construct_UFunction_AGridDungeonVisualizer_ClearInEditor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Snake Generation|Editor" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Editor-only visualization controls\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Editor-only visualization controls" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_ClearInEditor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "ClearInEditor", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x24020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_ClearInEditor_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_ClearInEditor_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_ClearInEditor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_ClearInEditor_Statics::FuncParams);
	}
	return ReturnFunction;
}
#endif // WITH_EDITOR
#if WITH_EDITOR
DEFINE_FUNCTION(AGridDungeonVisualizer::execClearInEditor)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClearInEditor();
	P_NATIVE_END;
}
#endif // WITH_EDITOR
// End Class AGridDungeonVisualizer Function ClearInEditor

// Begin Class AGridDungeonVisualizer Function ClearSnakePath
struct Z_Construct_UFunction_AGridDungeonVisualizer_ClearSnakePath_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Snake Generation|Debug" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Clear Functions\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Clear Functions" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_ClearSnakePath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "ClearSnakePath", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_ClearSnakePath_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_ClearSnakePath_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_ClearSnakePath()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_ClearSnakePath_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridDungeonVisualizer::execClearSnakePath)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClearSnakePath();
	P_NATIVE_END;
}
// End Class AGridDungeonVisualizer Function ClearSnakePath

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

// Begin Class AGridDungeonVisualizer Function DrawRoomBoundaries
struct Z_Construct_UFunction_AGridDungeonVisualizer_DrawRoomBoundaries_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Debug" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_DrawRoomBoundaries_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "DrawRoomBoundaries", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_DrawRoomBoundaries_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_DrawRoomBoundaries_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_DrawRoomBoundaries()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_DrawRoomBoundaries_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridDungeonVisualizer::execDrawRoomBoundaries)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DrawRoomBoundaries();
	P_NATIVE_END;
}
// End Class AGridDungeonVisualizer Function DrawRoomBoundaries

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
		{ "Category", "Snake Generation" },
		{ "DisplayName", "Generate (Animated)" },
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

// Begin Class AGridDungeonVisualizer Function GenerateInstant
struct Z_Construct_UFunction_AGridDungeonVisualizer_GenerateInstant_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Snake Generation" },
		{ "DisplayName", "Generate (Instant)" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_GenerateInstant_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "GenerateInstant", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_GenerateInstant_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_GenerateInstant_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_GenerateInstant()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_GenerateInstant_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridDungeonVisualizer::execGenerateInstant)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->GenerateInstant();
	P_NATIVE_END;
}
// End Class AGridDungeonVisualizer Function GenerateInstant

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

// Begin Class AGridDungeonVisualizer Function GetOptimalGridSizeForRooms
struct Z_Construct_UFunction_AGridDungeonVisualizer_GetOptimalGridSizeForRooms_Statics
{
	struct GridDungeonVisualizer_eventGetOptimalGridSizeForRooms_Parms
	{
		int32 RoomCount;
		FIntPoint ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Grid Layout" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_RoomCount;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_GetOptimalGridSizeForRooms_Statics::NewProp_RoomCount = { "RoomCount", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridDungeonVisualizer_eventGetOptimalGridSizeForRooms_Parms, RoomCount), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_GetOptimalGridSizeForRooms_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridDungeonVisualizer_eventGetOptimalGridSizeForRooms_Parms, ReturnValue), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGridDungeonVisualizer_GetOptimalGridSizeForRooms_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_GetOptimalGridSizeForRooms_Statics::NewProp_RoomCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_GetOptimalGridSizeForRooms_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_GetOptimalGridSizeForRooms_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_GetOptimalGridSizeForRooms_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "GetOptimalGridSizeForRooms", nullptr, nullptr, Z_Construct_UFunction_AGridDungeonVisualizer_GetOptimalGridSizeForRooms_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_GetOptimalGridSizeForRooms_Statics::PropPointers), sizeof(Z_Construct_UFunction_AGridDungeonVisualizer_GetOptimalGridSizeForRooms_Statics::GridDungeonVisualizer_eventGetOptimalGridSizeForRooms_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_GetOptimalGridSizeForRooms_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_GetOptimalGridSizeForRooms_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AGridDungeonVisualizer_GetOptimalGridSizeForRooms_Statics::GridDungeonVisualizer_eventGetOptimalGridSizeForRooms_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_GetOptimalGridSizeForRooms()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_GetOptimalGridSizeForRooms_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridDungeonVisualizer::execGetOptimalGridSizeForRooms)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_RoomCount);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FIntPoint*)Z_Param__Result=P_THIS->GetOptimalGridSizeForRooms(Z_Param_RoomCount);
	P_NATIVE_END;
}
// End Class AGridDungeonVisualizer Function GetOptimalGridSizeForRooms

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

// Begin Class AGridDungeonVisualizer Function SkipToEnd
struct Z_Construct_UFunction_AGridDungeonVisualizer_SkipToEnd_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Snake Generation" },
		{ "DisplayName", "Skip to End" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_SkipToEnd_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "SkipToEnd", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_SkipToEnd_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_SkipToEnd_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_SkipToEnd()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_SkipToEnd_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridDungeonVisualizer::execSkipToEnd)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SkipToEnd();
	P_NATIVE_END;
}
// End Class AGridDungeonVisualizer Function SkipToEnd

// Begin Class AGridDungeonVisualizer Function StepThroughGeneration
#if WITH_EDITOR
struct Z_Construct_UFunction_AGridDungeonVisualizer_StepThroughGeneration_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Snake Generation|Editor" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_StepThroughGeneration_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "StepThroughGeneration", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x24020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_StepThroughGeneration_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_StepThroughGeneration_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_StepThroughGeneration()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_StepThroughGeneration_Statics::FuncParams);
	}
	return ReturnFunction;
}
#endif // WITH_EDITOR
#if WITH_EDITOR
DEFINE_FUNCTION(AGridDungeonVisualizer::execStepThroughGeneration)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StepThroughGeneration();
	P_NATIVE_END;
}
#endif // WITH_EDITOR
// End Class AGridDungeonVisualizer Function StepThroughGeneration

// Begin Class AGridDungeonVisualizer Function StopAnimation
#if WITH_EDITOR
struct Z_Construct_UFunction_AGridDungeonVisualizer_StopAnimation_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Snake Generation|Animation" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_StopAnimation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "StopAnimation", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x24020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_StopAnimation_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_StopAnimation_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_StopAnimation()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_StopAnimation_Statics::FuncParams);
	}
	return ReturnFunction;
}
#endif // WITH_EDITOR
#if WITH_EDITOR
DEFINE_FUNCTION(AGridDungeonVisualizer::execStopAnimation)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StopAnimation();
	P_NATIVE_END;
}
#endif // WITH_EDITOR
// End Class AGridDungeonVisualizer Function StopAnimation

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

// Begin Class AGridDungeonVisualizer Function ToggleDebugVisualization
#if WITH_EDITOR
struct Z_Construct_UFunction_AGridDungeonVisualizer_ToggleDebugVisualization_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Snake Generation|Editor" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_ToggleDebugVisualization_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "ToggleDebugVisualization", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x24020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_ToggleDebugVisualization_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_ToggleDebugVisualization_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_ToggleDebugVisualization()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_ToggleDebugVisualization_Statics::FuncParams);
	}
	return ReturnFunction;
}
#endif // WITH_EDITOR
#if WITH_EDITOR
DEFINE_FUNCTION(AGridDungeonVisualizer::execToggleDebugVisualization)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ToggleDebugVisualization();
	P_NATIVE_END;
}
#endif // WITH_EDITOR
// End Class AGridDungeonVisualizer Function ToggleDebugVisualization

// Begin Class AGridDungeonVisualizer Function TogglePause
struct Z_Construct_UFunction_AGridDungeonVisualizer_TogglePause_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Snake Generation" },
		{ "DisplayName", "Pause/Resume" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_TogglePause_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "TogglePause", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_TogglePause_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_TogglePause_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_TogglePause()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_TogglePause_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridDungeonVisualizer::execTogglePause)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->TogglePause();
	P_NATIVE_END;
}
// End Class AGridDungeonVisualizer Function TogglePause

// Begin Class AGridDungeonVisualizer Function ValidateMixedRoomSpacing
struct Z_Construct_UFunction_AGridDungeonVisualizer_ValidateMixedRoomSpacing_Statics
{
	struct GridDungeonVisualizer_eventValidateMixedRoomSpacing_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Mixed Room Validation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Mixed Room Validation (public for testing)\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Mixed Room Validation (public for testing)" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_AGridDungeonVisualizer_ValidateMixedRoomSpacing_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((GridDungeonVisualizer_eventValidateMixedRoomSpacing_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_ValidateMixedRoomSpacing_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(GridDungeonVisualizer_eventValidateMixedRoomSpacing_Parms), &Z_Construct_UFunction_AGridDungeonVisualizer_ValidateMixedRoomSpacing_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGridDungeonVisualizer_ValidateMixedRoomSpacing_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_ValidateMixedRoomSpacing_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_ValidateMixedRoomSpacing_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_ValidateMixedRoomSpacing_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "ValidateMixedRoomSpacing", nullptr, nullptr, Z_Construct_UFunction_AGridDungeonVisualizer_ValidateMixedRoomSpacing_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_ValidateMixedRoomSpacing_Statics::PropPointers), sizeof(Z_Construct_UFunction_AGridDungeonVisualizer_ValidateMixedRoomSpacing_Statics::GridDungeonVisualizer_eventValidateMixedRoomSpacing_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_ValidateMixedRoomSpacing_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_ValidateMixedRoomSpacing_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AGridDungeonVisualizer_ValidateMixedRoomSpacing_Statics::GridDungeonVisualizer_eventValidateMixedRoomSpacing_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_ValidateMixedRoomSpacing()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_ValidateMixedRoomSpacing_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridDungeonVisualizer::execValidateMixedRoomSpacing)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ValidateMixedRoomSpacing();
	P_NATIVE_END;
}
// End Class AGridDungeonVisualizer Function ValidateMixedRoomSpacing

// Begin Class AGridDungeonVisualizer Function ValidateRoomSpacing
struct Z_Construct_UFunction_AGridDungeonVisualizer_ValidateRoomSpacing_Statics
{
	struct GridDungeonVisualizer_eventValidateRoomSpacing_Parms
	{
		TArray<FIntPoint> Path;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Room Generation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Spacing between room centers (3 room + 1 gap)\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Spacing between room centers (3 room + 1 gap)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Path_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Path_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Path;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_ValidateRoomSpacing_Statics::NewProp_Path_Inner = { "Path", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_ValidateRoomSpacing_Statics::NewProp_Path = { "Path", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridDungeonVisualizer_eventValidateRoomSpacing_Parms, Path), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Path_MetaData), NewProp_Path_MetaData) };
void Z_Construct_UFunction_AGridDungeonVisualizer_ValidateRoomSpacing_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((GridDungeonVisualizer_eventValidateRoomSpacing_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_ValidateRoomSpacing_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(GridDungeonVisualizer_eventValidateRoomSpacing_Parms), &Z_Construct_UFunction_AGridDungeonVisualizer_ValidateRoomSpacing_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGridDungeonVisualizer_ValidateRoomSpacing_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_ValidateRoomSpacing_Statics::NewProp_Path_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_ValidateRoomSpacing_Statics::NewProp_Path,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_ValidateRoomSpacing_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_ValidateRoomSpacing_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_ValidateRoomSpacing_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "ValidateRoomSpacing", nullptr, nullptr, Z_Construct_UFunction_AGridDungeonVisualizer_ValidateRoomSpacing_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_ValidateRoomSpacing_Statics::PropPointers), sizeof(Z_Construct_UFunction_AGridDungeonVisualizer_ValidateRoomSpacing_Statics::GridDungeonVisualizer_eventValidateRoomSpacing_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_ValidateRoomSpacing_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_ValidateRoomSpacing_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AGridDungeonVisualizer_ValidateRoomSpacing_Statics::GridDungeonVisualizer_eventValidateRoomSpacing_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_ValidateRoomSpacing()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_ValidateRoomSpacing_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridDungeonVisualizer::execValidateRoomSpacing)
{
	P_GET_TARRAY_REF(FIntPoint,Z_Param_Out_Path);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ValidateRoomSpacing(Z_Param_Out_Path);
	P_NATIVE_END;
}
// End Class AGridDungeonVisualizer Function ValidateRoomSpacing

// Begin Class AGridDungeonVisualizer Function ValidateSpacing
struct Z_Construct_UFunction_AGridDungeonVisualizer_ValidateSpacing_Statics
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
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_ValidateSpacing_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "ValidateSpacing", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_ValidateSpacing_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_ValidateSpacing_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_ValidateSpacing()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_ValidateSpacing_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridDungeonVisualizer::execValidateSpacing)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ValidateSpacing();
	P_NATIVE_END;
}
// End Class AGridDungeonVisualizer Function ValidateSpacing

// Begin Class AGridDungeonVisualizer
void AGridDungeonVisualizer::StaticRegisterNativesAGridDungeonVisualizer()
{
	UClass* Class = AGridDungeonVisualizer::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
#if WITH_EDITOR
		{ "AnimateSnakeGeneration", &AGridDungeonVisualizer::execAnimateSnakeGeneration },
#endif // WITH_EDITOR
		{ "AutoClearDebugAfterGeneration", &AGridDungeonVisualizer::execAutoClearDebugAfterGeneration },
		{ "CalculateGridSizeInEditor", &AGridDungeonVisualizer::execCalculateGridSizeInEditor },
		{ "CalculateOptimalGridSize", &AGridDungeonVisualizer::execCalculateOptimalGridSize },
		{ "CalculateRequiredDistance", &AGridDungeonVisualizer::execCalculateRequiredDistance },
		{ "ClearDebugVisualization", &AGridDungeonVisualizer::execClearDebugVisualization },
		{ "ClearDungeon", &AGridDungeonVisualizer::execClearDungeon },
#if WITH_EDITOR
		{ "ClearInEditor", &AGridDungeonVisualizer::execClearInEditor },
#endif // WITH_EDITOR
		{ "ClearSnakePath", &AGridDungeonVisualizer::execClearSnakePath },
		{ "DrawDebugGrid", &AGridDungeonVisualizer::execDrawDebugGrid },
		{ "DrawRoomBoundaries", &AGridDungeonVisualizer::execDrawRoomBoundaries },
		{ "GenerateAndVisualizeDungeon", &AGridDungeonVisualizer::execGenerateAndVisualizeDungeon },
		{ "GenerateInEditor", &AGridDungeonVisualizer::execGenerateInEditor },
		{ "GenerateInstant", &AGridDungeonVisualizer::execGenerateInstant },
		{ "GetGridCell", &AGridDungeonVisualizer::execGetGridCell },
		{ "GetOptimalGridSizeForRooms", &AGridDungeonVisualizer::execGetOptimalGridSizeForRooms },
		{ "GridToWorldPosition", &AGridDungeonVisualizer::execGridToWorldPosition },
		{ "IsValidGridPosition", &AGridDungeonVisualizer::execIsValidGridPosition },
		{ "MatchCubesToDebugBoxes", &AGridDungeonVisualizer::execMatchCubesToDebugBoxes },
		{ "SetGridCell", &AGridDungeonVisualizer::execSetGridCell },
		{ "SkipToEnd", &AGridDungeonVisualizer::execSkipToEnd },
#if WITH_EDITOR
		{ "StepThroughGeneration", &AGridDungeonVisualizer::execStepThroughGeneration },
		{ "StopAnimation", &AGridDungeonVisualizer::execStopAnimation },
#endif // WITH_EDITOR
		{ "TestAlternativeAlignment", &AGridDungeonVisualizer::execTestAlternativeAlignment },
		{ "TestGridAlignment", &AGridDungeonVisualizer::execTestGridAlignment },
#if WITH_EDITOR
		{ "ToggleDebugVisualization", &AGridDungeonVisualizer::execToggleDebugVisualization },
#endif // WITH_EDITOR
		{ "TogglePause", &AGridDungeonVisualizer::execTogglePause },
		{ "ValidateMixedRoomSpacing", &AGridDungeonVisualizer::execValidateMixedRoomSpacing },
		{ "ValidateRoomSpacing", &AGridDungeonVisualizer::execValidateRoomSpacing },
		{ "ValidateSpacing", &AGridDungeonVisualizer::execValidateSpacing },
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DesiredRoomCount_MetaData[] = {
		{ "Category", "Grid Layout" },
		{ "ClampMax", "50" },
		{ "ClampMin", "5" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Grid Configuration\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Grid Configuration" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutoCalculateGridSize_MetaData[] = {
		{ "Category", "Grid Layout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// How many rooms we want\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "How many rooms we want" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CalculatedGridSizeX_MetaData[] = {
		{ "Category", "Grid Layout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Auto-size grid based on room count\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Auto-size grid based on room count" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CalculatedGridSizeY_MetaData[] = {
		{ "Category", "Grid Layout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Calculated optimal size\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Calculated optimal size" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GridSizeX_MetaData[] = {
		{ "Category", "Grid Layout" },
		{ "ClampMax", "50" },
		{ "ClampMin", "20" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Calculated optimal size\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Calculated optimal size" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GridSizeY_MetaData[] = {
		{ "Category", "Grid Layout" },
		{ "ClampMax", "50" },
		{ "ClampMin", "20" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoomSize_MetaData[] = {
		{ "Category", "Grid Layout" },
		{ "ClampMax", "3" },
		{ "ClampMin", "3" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Room Size Configuration\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Room Size Configuration" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoomGap_MetaData[] = {
		{ "Category", "Grid Layout" },
		{ "ClampMax", "1" },
		{ "ClampMin", "1" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Rooms are 3x3\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Rooms are 3x3" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CellSize_MetaData[] = {
		{ "Category", "Grid Layout" },
		{ "ClampMax", "1000" },
		{ "ClampMin", "100" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Exactly 1 cell gap between rooms\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Exactly 1 cell gap between rooms" },
#endif
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StartRoomMaterial_MetaData[] = {
		{ "Category", "Visuals" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EndRoomMaterial_MetaData[] = {
		{ "Category", "Visuals" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bUseNanite_MetaData[] = {
		{ "Category", "UE5.5 Features" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// UE 5.5 Optimization Settings\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UE 5.5 Optimization Settings" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCastShadows_MetaData[] = {
		{ "Category", "UE5.5 Features" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LODBias_MetaData[] = {
		{ "Category", "UE5.5 Features" },
		{ "ClampMax", "7" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bUseInstancePooling_MetaData[] = {
		{ "Category", "UE5.5 HISM" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// UE 5.5 HISM Pooling Settings\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UE 5.5 HISM Pooling Settings" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InstanceBatchSize_MetaData[] = {
		{ "Category", "UE5.5 HISM" },
		{ "ClampMax", "1024" },
		{ "ClampMin", "64" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bLumenEnabled_MetaData[] = {
		{ "Category", "UE5.5 Rendering" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// UE 5.5 Lumen Support\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UE 5.5 Lumen Support" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bVirtualShadowMaps_MetaData[] = {
		{ "Category", "UE5.5 Rendering" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutoClearDebugAfterGeneration_MetaData[] = {
		{ "Category", "Snake Generation|Debug" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Auto-clear properties\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Auto-clear properties" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DebugAutoClearDelay_MetaData[] = {
		{ "Category", "Snake Generation|Debug" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentGenerationPhase_MetaData[] = {
		{ "Category", "Generation State" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Generation State\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Generation State" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PathStepDelay_MetaData[] = {
		{ "Category", "Generation|Animation" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CubeSpawnDelay_MetaData[] = {
		{ "Category", "Generation|Animation" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.01" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Delay between path steps\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Delay between path steps" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlaneSpawnDelay_MetaData[] = {
		{ "Category", "Generation|Animation" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.01" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Delay between cube spawns\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Delay between cube spawns" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAnimateGeneration_MetaData[] = {
		{ "Category", "Generation|Animation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Delay between plane spawns\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Delay between plane spawns" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bGenerationPaused_MetaData[] = {
		{ "Category", "Generation|Animation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Toggle for animated vs instant generation\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Toggle for animated vs instant generation" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutoValidateSpacing_MetaData[] = {
		{ "Category", "Generation|Validation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Animation pause state\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Animation pause state" },
#endif
	};
#if WITH_EDITORONLY_DATA
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AnimationStepDelay_MetaData[] = {
		{ "Category", "Snake Generation|Animation" },
		{ "ClampMax", "2.0" },
		{ "ClampMin", "0.1" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Legacy animation property for backwards compatibility\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Legacy animation property for backwards compatibility" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowPathNumbers_MetaData[] = {
		{ "Category", "Snake Generation|Visualization" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowRoomConnections_MetaData[] = {
		{ "Category", "Snake Generation|Visualization" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHighlightCurrentStep_MetaData[] = {
		{ "Category", "Snake Generation|Visualization" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PathColor_MetaData[] = {
		{ "Category", "Snake Generation|Visualization" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StartColor_MetaData[] = {
		{ "Category", "Snake Generation|Visualization" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EndColor_MetaData[] = {
		{ "Category", "Snake Generation|Visualization" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutoGenerateOnChange_MetaData[] = {
		{ "Category", "Snake Generation|Visualization" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoomSpacing_MetaData[] = {
		{ "Category", "Room Generation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Room Generation Validation\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Room Generation Validation" },
#endif
	};
#endif // WITH_EDITORONLY_DATA
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowCellCoordinates_MetaData[] = {
		{ "Category", "Debug" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowRoomBoundaries_MetaData[] = {
		{ "Category", "Debug" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoomBoundaryColor_MetaData[] = {
		{ "Category", "Debug" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
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
		{ "Comment", "// HISM Components for better performance with large instance counts\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "HISM Components for better performance with large instance counts" },
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoomInfoList_MetaData[] = {
		{ "Category", "Runtime" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_DesiredRoomCount;
	static void NewProp_bAutoCalculateGridSize_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoCalculateGridSize;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CalculatedGridSizeX;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CalculatedGridSizeY;
	static const UECodeGen_Private::FIntPropertyParams NewProp_GridSizeX;
	static const UECodeGen_Private::FIntPropertyParams NewProp_GridSizeY;
	static const UECodeGen_Private::FIntPropertyParams NewProp_RoomSize;
	static const UECodeGen_Private::FIntPropertyParams NewProp_RoomGap;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CellSize;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CubeSizePercentage;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlaneMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CubeMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FloorMaterial;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WallMaterial;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StartRoomMaterial;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_EndRoomMaterial;
	static void NewProp_bUseNanite_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseNanite;
	static void NewProp_bCastShadows_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCastShadows;
	static const UECodeGen_Private::FIntPropertyParams NewProp_LODBias;
	static void NewProp_bUseInstancePooling_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseInstancePooling;
	static const UECodeGen_Private::FIntPropertyParams NewProp_InstanceBatchSize;
	static void NewProp_bLumenEnabled_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bLumenEnabled;
	static void NewProp_bVirtualShadowMaps_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bVirtualShadowMaps;
	static void NewProp_bAutoClearDebugAfterGeneration_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoClearDebugAfterGeneration;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DebugAutoClearDelay;
	static const UECodeGen_Private::FBytePropertyParams NewProp_CurrentGenerationPhase_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_CurrentGenerationPhase;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PathStepDelay;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CubeSpawnDelay;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlaneSpawnDelay;
	static void NewProp_bAnimateGeneration_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAnimateGeneration;
	static void NewProp_bGenerationPaused_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bGenerationPaused;
	static void NewProp_bAutoValidateSpacing_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoValidateSpacing;
#if WITH_EDITORONLY_DATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AnimationStepDelay;
	static void NewProp_bShowPathNumbers_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowPathNumbers;
	static void NewProp_bShowRoomConnections_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowRoomConnections;
	static void NewProp_bHighlightCurrentStep_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHighlightCurrentStep;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PathColor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_StartColor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_EndColor;
	static void NewProp_bAutoGenerateOnChange_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoGenerateOnChange;
	static const UECodeGen_Private::FIntPropertyParams NewProp_RoomSpacing;
#endif // WITH_EDITORONLY_DATA
	static void NewProp_bShowDebugGrid_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowDebugGrid;
	static void NewProp_bShowCellCoordinates_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowCellCoordinates;
	static void NewProp_bShowRoomBoundaries_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowRoomBoundaries;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RoomBoundaryColor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DebugLineThickness;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DebugGridColor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlaneInstances;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CubeInstances;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Grid_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Grid;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RoomInfoList_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_RoomInfoList;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
#if WITH_EDITOR
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_AnimateSnakeGeneration, "AnimateSnakeGeneration" }, // 3616493240
#endif // WITH_EDITOR
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_AutoClearDebugAfterGeneration, "AutoClearDebugAfterGeneration" }, // 1817083205
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_CalculateGridSizeInEditor, "CalculateGridSizeInEditor" }, // 1237837982
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_CalculateOptimalGridSize, "CalculateOptimalGridSize" }, // 302376123
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_CalculateRequiredDistance, "CalculateRequiredDistance" }, // 4033113085
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_ClearDebugVisualization, "ClearDebugVisualization" }, // 182015823
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_ClearDungeon, "ClearDungeon" }, // 3547271859
#if WITH_EDITOR
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_ClearInEditor, "ClearInEditor" }, // 2761965517
#endif // WITH_EDITOR
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_ClearSnakePath, "ClearSnakePath" }, // 2585258438
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_DrawDebugGrid, "DrawDebugGrid" }, // 2869966766
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_DrawRoomBoundaries, "DrawRoomBoundaries" }, // 2721337806
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_GenerateAndVisualizeDungeon, "GenerateAndVisualizeDungeon" }, // 2237856306
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_GenerateInEditor, "GenerateInEditor" }, // 3232249966
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_GenerateInstant, "GenerateInstant" }, // 2505253609
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_GetGridCell, "GetGridCell" }, // 982663425
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_GetOptimalGridSizeForRooms, "GetOptimalGridSizeForRooms" }, // 106695918
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_GridToWorldPosition, "GridToWorldPosition" }, // 2646692030
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_IsValidGridPosition, "IsValidGridPosition" }, // 3376793452
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_MatchCubesToDebugBoxes, "MatchCubesToDebugBoxes" }, // 3506967339
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_SetGridCell, "SetGridCell" }, // 748086578
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_SkipToEnd, "SkipToEnd" }, // 1751868492
#if WITH_EDITOR
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_StepThroughGeneration, "StepThroughGeneration" }, // 2407455314
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_StopAnimation, "StopAnimation" }, // 25640948
#endif // WITH_EDITOR
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_TestAlternativeAlignment, "TestAlternativeAlignment" }, // 3764426828
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_TestGridAlignment, "TestGridAlignment" }, // 2561120545
#if WITH_EDITOR
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_ToggleDebugVisualization, "ToggleDebugVisualization" }, // 3704727372
#endif // WITH_EDITOR
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_TogglePause, "TogglePause" }, // 3778160898
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_ValidateMixedRoomSpacing, "ValidateMixedRoomSpacing" }, // 624158255
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_ValidateRoomSpacing, "ValidateRoomSpacing" }, // 788016128
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_ValidateSpacing, "ValidateSpacing" }, // 493452904
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGridDungeonVisualizer>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_DesiredRoomCount = { "DesiredRoomCount", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, DesiredRoomCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DesiredRoomCount_MetaData), NewProp_DesiredRoomCount_MetaData) };
void Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bAutoCalculateGridSize_SetBit(void* Obj)
{
	((AGridDungeonVisualizer*)Obj)->bAutoCalculateGridSize = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bAutoCalculateGridSize = { "bAutoCalculateGridSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AGridDungeonVisualizer), &Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bAutoCalculateGridSize_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutoCalculateGridSize_MetaData), NewProp_bAutoCalculateGridSize_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_CalculatedGridSizeX = { "CalculatedGridSizeX", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, CalculatedGridSizeX), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CalculatedGridSizeX_MetaData), NewProp_CalculatedGridSizeX_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_CalculatedGridSizeY = { "CalculatedGridSizeY", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, CalculatedGridSizeY), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CalculatedGridSizeY_MetaData), NewProp_CalculatedGridSizeY_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_GridSizeX = { "GridSizeX", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, GridSizeX), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GridSizeX_MetaData), NewProp_GridSizeX_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_GridSizeY = { "GridSizeY", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, GridSizeY), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GridSizeY_MetaData), NewProp_GridSizeY_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_RoomSize = { "RoomSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, RoomSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoomSize_MetaData), NewProp_RoomSize_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_RoomGap = { "RoomGap", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, RoomGap), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoomGap_MetaData), NewProp_RoomGap_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_CellSize = { "CellSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, CellSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CellSize_MetaData), NewProp_CellSize_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_CubeSizePercentage = { "CubeSizePercentage", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, CubeSizePercentage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CubeSizePercentage_MetaData), NewProp_CubeSizePercentage_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_PlaneMesh = { "PlaneMesh", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, PlaneMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlaneMesh_MetaData), NewProp_PlaneMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_CubeMesh = { "CubeMesh", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, CubeMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CubeMesh_MetaData), NewProp_CubeMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_FloorMaterial = { "FloorMaterial", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, FloorMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FloorMaterial_MetaData), NewProp_FloorMaterial_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_WallMaterial = { "WallMaterial", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, WallMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WallMaterial_MetaData), NewProp_WallMaterial_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_StartRoomMaterial = { "StartRoomMaterial", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, StartRoomMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StartRoomMaterial_MetaData), NewProp_StartRoomMaterial_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_EndRoomMaterial = { "EndRoomMaterial", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, EndRoomMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EndRoomMaterial_MetaData), NewProp_EndRoomMaterial_MetaData) };
void Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bUseNanite_SetBit(void* Obj)
{
	((AGridDungeonVisualizer*)Obj)->bUseNanite = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bUseNanite = { "bUseNanite", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AGridDungeonVisualizer), &Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bUseNanite_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bUseNanite_MetaData), NewProp_bUseNanite_MetaData) };
void Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bCastShadows_SetBit(void* Obj)
{
	((AGridDungeonVisualizer*)Obj)->bCastShadows = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bCastShadows = { "bCastShadows", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AGridDungeonVisualizer), &Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bCastShadows_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCastShadows_MetaData), NewProp_bCastShadows_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_LODBias = { "LODBias", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, LODBias), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LODBias_MetaData), NewProp_LODBias_MetaData) };
void Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bUseInstancePooling_SetBit(void* Obj)
{
	((AGridDungeonVisualizer*)Obj)->bUseInstancePooling = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bUseInstancePooling = { "bUseInstancePooling", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AGridDungeonVisualizer), &Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bUseInstancePooling_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bUseInstancePooling_MetaData), NewProp_bUseInstancePooling_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_InstanceBatchSize = { "InstanceBatchSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, InstanceBatchSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InstanceBatchSize_MetaData), NewProp_InstanceBatchSize_MetaData) };
void Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bLumenEnabled_SetBit(void* Obj)
{
	((AGridDungeonVisualizer*)Obj)->bLumenEnabled = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bLumenEnabled = { "bLumenEnabled", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AGridDungeonVisualizer), &Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bLumenEnabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bLumenEnabled_MetaData), NewProp_bLumenEnabled_MetaData) };
void Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bVirtualShadowMaps_SetBit(void* Obj)
{
	((AGridDungeonVisualizer*)Obj)->bVirtualShadowMaps = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bVirtualShadowMaps = { "bVirtualShadowMaps", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AGridDungeonVisualizer), &Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bVirtualShadowMaps_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bVirtualShadowMaps_MetaData), NewProp_bVirtualShadowMaps_MetaData) };
void Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bAutoClearDebugAfterGeneration_SetBit(void* Obj)
{
	((AGridDungeonVisualizer*)Obj)->bAutoClearDebugAfterGeneration = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bAutoClearDebugAfterGeneration = { "bAutoClearDebugAfterGeneration", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AGridDungeonVisualizer), &Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bAutoClearDebugAfterGeneration_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutoClearDebugAfterGeneration_MetaData), NewProp_bAutoClearDebugAfterGeneration_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_DebugAutoClearDelay = { "DebugAutoClearDelay", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, DebugAutoClearDelay), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DebugAutoClearDelay_MetaData), NewProp_DebugAutoClearDelay_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_CurrentGenerationPhase_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_CurrentGenerationPhase = { "CurrentGenerationPhase", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, CurrentGenerationPhase), Z_Construct_UEnum_EternalDescent_EGenerationPhase, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentGenerationPhase_MetaData), NewProp_CurrentGenerationPhase_MetaData) }; // 2138987337
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_PathStepDelay = { "PathStepDelay", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, PathStepDelay), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PathStepDelay_MetaData), NewProp_PathStepDelay_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_CubeSpawnDelay = { "CubeSpawnDelay", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, CubeSpawnDelay), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CubeSpawnDelay_MetaData), NewProp_CubeSpawnDelay_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_PlaneSpawnDelay = { "PlaneSpawnDelay", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, PlaneSpawnDelay), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlaneSpawnDelay_MetaData), NewProp_PlaneSpawnDelay_MetaData) };
void Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bAnimateGeneration_SetBit(void* Obj)
{
	((AGridDungeonVisualizer*)Obj)->bAnimateGeneration = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bAnimateGeneration = { "bAnimateGeneration", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AGridDungeonVisualizer), &Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bAnimateGeneration_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAnimateGeneration_MetaData), NewProp_bAnimateGeneration_MetaData) };
void Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bGenerationPaused_SetBit(void* Obj)
{
	((AGridDungeonVisualizer*)Obj)->bGenerationPaused = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bGenerationPaused = { "bGenerationPaused", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AGridDungeonVisualizer), &Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bGenerationPaused_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bGenerationPaused_MetaData), NewProp_bGenerationPaused_MetaData) };
void Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bAutoValidateSpacing_SetBit(void* Obj)
{
	((AGridDungeonVisualizer*)Obj)->bAutoValidateSpacing = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bAutoValidateSpacing = { "bAutoValidateSpacing", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AGridDungeonVisualizer), &Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bAutoValidateSpacing_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutoValidateSpacing_MetaData), NewProp_bAutoValidateSpacing_MetaData) };
#if WITH_EDITORONLY_DATA
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_AnimationStepDelay = { "AnimationStepDelay", nullptr, (EPropertyFlags)0x0010000800000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, AnimationStepDelay), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AnimationStepDelay_MetaData), NewProp_AnimationStepDelay_MetaData) };
void Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bShowPathNumbers_SetBit(void* Obj)
{
	((AGridDungeonVisualizer*)Obj)->bShowPathNumbers = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bShowPathNumbers = { "bShowPathNumbers", nullptr, (EPropertyFlags)0x0010000800000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AGridDungeonVisualizer), &Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bShowPathNumbers_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowPathNumbers_MetaData), NewProp_bShowPathNumbers_MetaData) };
void Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bShowRoomConnections_SetBit(void* Obj)
{
	((AGridDungeonVisualizer*)Obj)->bShowRoomConnections = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bShowRoomConnections = { "bShowRoomConnections", nullptr, (EPropertyFlags)0x0010000800000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AGridDungeonVisualizer), &Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bShowRoomConnections_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowRoomConnections_MetaData), NewProp_bShowRoomConnections_MetaData) };
void Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bHighlightCurrentStep_SetBit(void* Obj)
{
	((AGridDungeonVisualizer*)Obj)->bHighlightCurrentStep = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bHighlightCurrentStep = { "bHighlightCurrentStep", nullptr, (EPropertyFlags)0x0010000800000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AGridDungeonVisualizer), &Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bHighlightCurrentStep_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHighlightCurrentStep_MetaData), NewProp_bHighlightCurrentStep_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_PathColor = { "PathColor", nullptr, (EPropertyFlags)0x0010000800000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, PathColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PathColor_MetaData), NewProp_PathColor_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_StartColor = { "StartColor", nullptr, (EPropertyFlags)0x0010000800000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, StartColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StartColor_MetaData), NewProp_StartColor_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_EndColor = { "EndColor", nullptr, (EPropertyFlags)0x0010000800000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, EndColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EndColor_MetaData), NewProp_EndColor_MetaData) };
void Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bAutoGenerateOnChange_SetBit(void* Obj)
{
	((AGridDungeonVisualizer*)Obj)->bAutoGenerateOnChange = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bAutoGenerateOnChange = { "bAutoGenerateOnChange", nullptr, (EPropertyFlags)0x0010000800000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AGridDungeonVisualizer), &Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bAutoGenerateOnChange_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutoGenerateOnChange_MetaData), NewProp_bAutoGenerateOnChange_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_RoomSpacing = { "RoomSpacing", nullptr, (EPropertyFlags)0x0010000800000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, RoomSpacing), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoomSpacing_MetaData), NewProp_RoomSpacing_MetaData) };
#endif // WITH_EDITORONLY_DATA
void Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bShowDebugGrid_SetBit(void* Obj)
{
	((AGridDungeonVisualizer*)Obj)->bShowDebugGrid = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bShowDebugGrid = { "bShowDebugGrid", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AGridDungeonVisualizer), &Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bShowDebugGrid_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowDebugGrid_MetaData), NewProp_bShowDebugGrid_MetaData) };
void Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bShowCellCoordinates_SetBit(void* Obj)
{
	((AGridDungeonVisualizer*)Obj)->bShowCellCoordinates = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bShowCellCoordinates = { "bShowCellCoordinates", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AGridDungeonVisualizer), &Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bShowCellCoordinates_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowCellCoordinates_MetaData), NewProp_bShowCellCoordinates_MetaData) };
void Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bShowRoomBoundaries_SetBit(void* Obj)
{
	((AGridDungeonVisualizer*)Obj)->bShowRoomBoundaries = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bShowRoomBoundaries = { "bShowRoomBoundaries", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AGridDungeonVisualizer), &Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bShowRoomBoundaries_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowRoomBoundaries_MetaData), NewProp_bShowRoomBoundaries_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_RoomBoundaryColor = { "RoomBoundaryColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, RoomBoundaryColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoomBoundaryColor_MetaData), NewProp_RoomBoundaryColor_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_DebugLineThickness = { "DebugLineThickness", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, DebugLineThickness), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DebugLineThickness_MetaData), NewProp_DebugLineThickness_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_DebugGridColor = { "DebugGridColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, DebugGridColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DebugGridColor_MetaData), NewProp_DebugGridColor_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_PlaneInstances = { "PlaneInstances", nullptr, (EPropertyFlags)0x001000000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, PlaneInstances), Z_Construct_UClass_UHierarchicalInstancedStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlaneInstances_MetaData), NewProp_PlaneInstances_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_CubeInstances = { "CubeInstances", nullptr, (EPropertyFlags)0x001000000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, CubeInstances), Z_Construct_UClass_UHierarchicalInstancedStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CubeInstances_MetaData), NewProp_CubeInstances_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_Grid_Inner = { "Grid", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FGridCell, METADATA_PARAMS(0, nullptr) }; // 2314947957
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_Grid = { "Grid", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, Grid), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Grid_MetaData), NewProp_Grid_MetaData) }; // 2314947957
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_RoomInfoList_Inner = { "RoomInfoList", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FGridRoomInfo, METADATA_PARAMS(0, nullptr) }; // 3116174836
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_RoomInfoList = { "RoomInfoList", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, RoomInfoList), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoomInfoList_MetaData), NewProp_RoomInfoList_MetaData) }; // 3116174836
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGridDungeonVisualizer_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_DesiredRoomCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bAutoCalculateGridSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_CalculatedGridSizeX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_CalculatedGridSizeY,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_GridSizeX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_GridSizeY,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_RoomSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_RoomGap,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_CellSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_CubeSizePercentage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_PlaneMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_CubeMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_FloorMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_WallMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_StartRoomMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_EndRoomMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bUseNanite,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bCastShadows,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_LODBias,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bUseInstancePooling,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_InstanceBatchSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bLumenEnabled,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bVirtualShadowMaps,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bAutoClearDebugAfterGeneration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_DebugAutoClearDelay,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_CurrentGenerationPhase_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_CurrentGenerationPhase,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_PathStepDelay,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_CubeSpawnDelay,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_PlaneSpawnDelay,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bAnimateGeneration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bGenerationPaused,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bAutoValidateSpacing,
#if WITH_EDITORONLY_DATA
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_AnimationStepDelay,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bShowPathNumbers,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bShowRoomConnections,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bHighlightCurrentStep,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_PathColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_StartColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_EndColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bAutoGenerateOnChange,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_RoomSpacing,
#endif // WITH_EDITORONLY_DATA
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bShowDebugGrid,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bShowCellCoordinates,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bShowRoomBoundaries,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_RoomBoundaryColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_DebugLineThickness,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_DebugGridColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_PlaneInstances,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_CubeInstances,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_Grid_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_Grid,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_RoomInfoList_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_RoomInfoList,
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
		{ ERoomSizeType_StaticEnum, TEXT("ERoomSizeType"), &Z_Registration_Info_UEnum_ERoomSizeType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 4214052988U) },
		{ EGenerationPhase_StaticEnum, TEXT("EGenerationPhase"), &Z_Registration_Info_UEnum_EGenerationPhase, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2138987337U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FGridCell::StaticStruct, Z_Construct_UScriptStruct_FGridCell_Statics::NewStructOps, TEXT("GridCell"), &Z_Registration_Info_UScriptStruct_GridCell, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FGridCell), 2314947957U) },
		{ FGridRoomInfo::StaticStruct, Z_Construct_UScriptStruct_FGridRoomInfo_Statics::NewStructOps, TEXT("GridRoomInfo"), &Z_Registration_Info_UScriptStruct_GridRoomInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FGridRoomInfo), 3116174836U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AGridDungeonVisualizer, AGridDungeonVisualizer::StaticClass, TEXT("AGridDungeonVisualizer"), &Z_Registration_Info_UClass_AGridDungeonVisualizer, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGridDungeonVisualizer), 3971916118U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_3756802132(TEXT("/Script/EternalDescent"),
	Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
