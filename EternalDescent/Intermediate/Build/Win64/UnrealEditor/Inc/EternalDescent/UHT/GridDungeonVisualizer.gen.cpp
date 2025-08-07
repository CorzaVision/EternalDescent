// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EternalDescent/Public/GridDungeonVisualizer.h"
#include "EternalDescent/Public/Tests/DungeonTestTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGridDungeonVisualizer() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntPoint();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRandomStream();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UInstancedStaticMeshComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
ETERNALDESCENT_API UClass* Z_Construct_UClass_AADASystem_NoRegister();
ETERNALDESCENT_API UClass* Z_Construct_UClass_AGridDungeonVisualizer();
ETERNALDESCENT_API UClass* Z_Construct_UClass_AGridDungeonVisualizer_NoRegister();
ETERNALDESCENT_API UEnum* Z_Construct_UEnum_EternalDescent_EDungeonGenerationType();
ETERNALDESCENT_API UEnum* Z_Construct_UEnum_EternalDescent_EGridCellType();
ETERNALDESCENT_API UEnum* Z_Construct_UEnum_EternalDescent_ERoomType();
ETERNALDESCENT_API UScriptStruct* Z_Construct_UScriptStruct_FDungeonLayout();
ETERNALDESCENT_API UScriptStruct* Z_Construct_UScriptStruct_FGridCell();
ETERNALDESCENT_API UScriptStruct* Z_Construct_UScriptStruct_FHallway();
ETERNALDESCENT_API UScriptStruct* Z_Construct_UScriptStruct_FOrganicDungeonLayout();
ETERNALDESCENT_API UScriptStruct* Z_Construct_UScriptStruct_FOrganicRoom();
ETERNALDESCENT_API UScriptStruct* Z_Construct_UScriptStruct_FRoomData();
UPackage* Z_Construct_UPackage__Script_EternalDescent();
// End Cross Module References

// Begin Enum EDungeonGenerationType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EDungeonGenerationType;
static UEnum* EDungeonGenerationType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EDungeonGenerationType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EDungeonGenerationType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_EternalDescent_EDungeonGenerationType, (UObject*)Z_Construct_UPackage__Script_EternalDescent(), TEXT("EDungeonGenerationType"));
	}
	return Z_Registration_Info_UEnum_EDungeonGenerationType.OuterSingleton;
}
template<> ETERNALDESCENT_API UEnum* StaticEnum<EDungeonGenerationType>()
{
	return EDungeonGenerationType_StaticEnum();
}
struct Z_Construct_UEnum_EternalDescent_EDungeonGenerationType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Grid.DisplayName", "Grid-Based" },
		{ "Grid.Name", "EDungeonGenerationType::Grid" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
		{ "Organic.DisplayName", "Organic/Natural" },
		{ "Organic.Name", "EDungeonGenerationType::Organic" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EDungeonGenerationType::Grid", (int64)EDungeonGenerationType::Grid },
		{ "EDungeonGenerationType::Organic", (int64)EDungeonGenerationType::Organic },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_EternalDescent_EDungeonGenerationType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_EternalDescent,
	nullptr,
	"EDungeonGenerationType",
	"EDungeonGenerationType",
	Z_Construct_UEnum_EternalDescent_EDungeonGenerationType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_EternalDescent_EDungeonGenerationType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_EternalDescent_EDungeonGenerationType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_EternalDescent_EDungeonGenerationType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_EternalDescent_EDungeonGenerationType()
{
	if (!Z_Registration_Info_UEnum_EDungeonGenerationType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EDungeonGenerationType.InnerSingleton, Z_Construct_UEnum_EternalDescent_EDungeonGenerationType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EDungeonGenerationType.InnerSingleton;
}
// End Enum EDungeonGenerationType

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

// Begin ScriptStruct FOrganicRoom
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_OrganicRoom;
class UScriptStruct* FOrganicRoom::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_OrganicRoom.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_OrganicRoom.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOrganicRoom, (UObject*)Z_Construct_UPackage__Script_EternalDescent(), TEXT("OrganicRoom"));
	}
	return Z_Registration_Info_UScriptStruct_OrganicRoom.OuterSingleton;
}
template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<FOrganicRoom>()
{
	return FOrganicRoom::StaticStruct();
}
struct Z_Construct_UScriptStruct_FOrganicRoom_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Position_MetaData[] = {
		{ "Category", "OrganicRoom" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Size_MetaData[] = {
		{ "Category", "OrganicRoom" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// World position of room center\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "World position of room center" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoomType_MetaData[] = {
		{ "Category", "OrganicRoom" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Width and Height in world units\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Width and Height in world units" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoomID_MetaData[] = {
		{ "Category", "OrganicRoom" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ConnectedRooms_MetaData[] = {
		{ "Category", "OrganicRoom" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsMainPath_MetaData[] = {
		{ "Category", "OrganicRoom" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// IDs of connected rooms\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "IDs of connected rooms" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Depth_MetaData[] = {
		{ "Category", "OrganicRoom" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Part of the critical path\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Part of the critical path" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Position;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Size;
	static const UECodeGen_Private::FBytePropertyParams NewProp_RoomType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_RoomType;
	static const UECodeGen_Private::FIntPropertyParams NewProp_RoomID;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ConnectedRooms_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ConnectedRooms;
	static void NewProp_bIsMainPath_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsMainPath;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Depth;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOrganicRoom>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOrganicRoom_Statics::NewProp_Position = { "Position", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOrganicRoom, Position), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Position_MetaData), NewProp_Position_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOrganicRoom_Statics::NewProp_Size = { "Size", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOrganicRoom, Size), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Size_MetaData), NewProp_Size_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FOrganicRoom_Statics::NewProp_RoomType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FOrganicRoom_Statics::NewProp_RoomType = { "RoomType", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOrganicRoom, RoomType), Z_Construct_UEnum_EternalDescent_ERoomType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoomType_MetaData), NewProp_RoomType_MetaData) }; // 1291513837
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FOrganicRoom_Statics::NewProp_RoomID = { "RoomID", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOrganicRoom, RoomID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoomID_MetaData), NewProp_RoomID_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FOrganicRoom_Statics::NewProp_ConnectedRooms_Inner = { "ConnectedRooms", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FOrganicRoom_Statics::NewProp_ConnectedRooms = { "ConnectedRooms", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOrganicRoom, ConnectedRooms), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ConnectedRooms_MetaData), NewProp_ConnectedRooms_MetaData) };
void Z_Construct_UScriptStruct_FOrganicRoom_Statics::NewProp_bIsMainPath_SetBit(void* Obj)
{
	((FOrganicRoom*)Obj)->bIsMainPath = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOrganicRoom_Statics::NewProp_bIsMainPath = { "bIsMainPath", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOrganicRoom), &Z_Construct_UScriptStruct_FOrganicRoom_Statics::NewProp_bIsMainPath_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsMainPath_MetaData), NewProp_bIsMainPath_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FOrganicRoom_Statics::NewProp_Depth = { "Depth", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOrganicRoom, Depth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Depth_MetaData), NewProp_Depth_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOrganicRoom_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOrganicRoom_Statics::NewProp_Position,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOrganicRoom_Statics::NewProp_Size,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOrganicRoom_Statics::NewProp_RoomType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOrganicRoom_Statics::NewProp_RoomType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOrganicRoom_Statics::NewProp_RoomID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOrganicRoom_Statics::NewProp_ConnectedRooms_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOrganicRoom_Statics::NewProp_ConnectedRooms,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOrganicRoom_Statics::NewProp_bIsMainPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOrganicRoom_Statics::NewProp_Depth,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOrganicRoom_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOrganicRoom_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_EternalDescent,
	nullptr,
	&NewStructOps,
	"OrganicRoom",
	Z_Construct_UScriptStruct_FOrganicRoom_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOrganicRoom_Statics::PropPointers),
	sizeof(FOrganicRoom),
	alignof(FOrganicRoom),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOrganicRoom_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOrganicRoom_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FOrganicRoom()
{
	if (!Z_Registration_Info_UScriptStruct_OrganicRoom.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_OrganicRoom.InnerSingleton, Z_Construct_UScriptStruct_FOrganicRoom_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_OrganicRoom.InnerSingleton;
}
// End ScriptStruct FOrganicRoom

// Begin ScriptStruct FHallway
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_Hallway;
class UScriptStruct* FHallway::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_Hallway.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_Hallway.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FHallway, (UObject*)Z_Construct_UPackage__Script_EternalDescent(), TEXT("Hallway"));
	}
	return Z_Registration_Info_UScriptStruct_Hallway.OuterSingleton;
}
template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<FHallway>()
{
	return FHallway::StaticStruct();
}
struct Z_Construct_UScriptStruct_FHallway_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoomA_MetaData[] = {
		{ "Category", "Hallway" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoomB_MetaData[] = {
		{ "Category", "Hallway" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PathPoints_MetaData[] = {
		{ "Category", "Hallway" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Width_MetaData[] = {
		{ "Category", "Hallway" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Points along the hallway\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Points along the hallway" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_RoomA;
	static const UECodeGen_Private::FIntPropertyParams NewProp_RoomB;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PathPoints_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_PathPoints;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Width;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FHallway>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FHallway_Statics::NewProp_RoomA = { "RoomA", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHallway, RoomA), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoomA_MetaData), NewProp_RoomA_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FHallway_Statics::NewProp_RoomB = { "RoomB", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHallway, RoomB), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoomB_MetaData), NewProp_RoomB_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FHallway_Statics::NewProp_PathPoints_Inner = { "PathPoints", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FHallway_Statics::NewProp_PathPoints = { "PathPoints", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHallway, PathPoints), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PathPoints_MetaData), NewProp_PathPoints_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FHallway_Statics::NewProp_Width = { "Width", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHallway, Width), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Width_MetaData), NewProp_Width_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FHallway_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHallway_Statics::NewProp_RoomA,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHallway_Statics::NewProp_RoomB,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHallway_Statics::NewProp_PathPoints_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHallway_Statics::NewProp_PathPoints,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHallway_Statics::NewProp_Width,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHallway_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FHallway_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_EternalDescent,
	nullptr,
	&NewStructOps,
	"Hallway",
	Z_Construct_UScriptStruct_FHallway_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHallway_Statics::PropPointers),
	sizeof(FHallway),
	alignof(FHallway),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHallway_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FHallway_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FHallway()
{
	if (!Z_Registration_Info_UScriptStruct_Hallway.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_Hallway.InnerSingleton, Z_Construct_UScriptStruct_FHallway_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_Hallway.InnerSingleton;
}
// End ScriptStruct FHallway

// Begin ScriptStruct FOrganicDungeonLayout
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_OrganicDungeonLayout;
class UScriptStruct* FOrganicDungeonLayout::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_OrganicDungeonLayout.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_OrganicDungeonLayout.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOrganicDungeonLayout, (UObject*)Z_Construct_UPackage__Script_EternalDescent(), TEXT("OrganicDungeonLayout"));
	}
	return Z_Registration_Info_UScriptStruct_OrganicDungeonLayout.OuterSingleton;
}
template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<FOrganicDungeonLayout>()
{
	return FOrganicDungeonLayout::StaticStruct();
}
struct Z_Construct_UScriptStruct_FOrganicDungeonLayout_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rooms_MetaData[] = {
		{ "Category", "OrganicDungeonLayout" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Hallways_MetaData[] = {
		{ "Category", "OrganicDungeonLayout" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StartRoomID_MetaData[] = {
		{ "Category", "OrganicDungeonLayout" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EndRoomID_MetaData[] = {
		{ "Category", "OrganicDungeonLayout" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FloorNumber_MetaData[] = {
		{ "Category", "OrganicDungeonLayout" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Rooms_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Rooms;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Hallways_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Hallways;
	static const UECodeGen_Private::FIntPropertyParams NewProp_StartRoomID;
	static const UECodeGen_Private::FIntPropertyParams NewProp_EndRoomID;
	static const UECodeGen_Private::FIntPropertyParams NewProp_FloorNumber;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOrganicDungeonLayout>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOrganicDungeonLayout_Statics::NewProp_Rooms_Inner = { "Rooms", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FOrganicRoom, METADATA_PARAMS(0, nullptr) }; // 444642103
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FOrganicDungeonLayout_Statics::NewProp_Rooms = { "Rooms", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOrganicDungeonLayout, Rooms), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rooms_MetaData), NewProp_Rooms_MetaData) }; // 444642103
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOrganicDungeonLayout_Statics::NewProp_Hallways_Inner = { "Hallways", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FHallway, METADATA_PARAMS(0, nullptr) }; // 3248599507
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FOrganicDungeonLayout_Statics::NewProp_Hallways = { "Hallways", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOrganicDungeonLayout, Hallways), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Hallways_MetaData), NewProp_Hallways_MetaData) }; // 3248599507
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FOrganicDungeonLayout_Statics::NewProp_StartRoomID = { "StartRoomID", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOrganicDungeonLayout, StartRoomID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StartRoomID_MetaData), NewProp_StartRoomID_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FOrganicDungeonLayout_Statics::NewProp_EndRoomID = { "EndRoomID", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOrganicDungeonLayout, EndRoomID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EndRoomID_MetaData), NewProp_EndRoomID_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FOrganicDungeonLayout_Statics::NewProp_FloorNumber = { "FloorNumber", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOrganicDungeonLayout, FloorNumber), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FloorNumber_MetaData), NewProp_FloorNumber_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOrganicDungeonLayout_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOrganicDungeonLayout_Statics::NewProp_Rooms_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOrganicDungeonLayout_Statics::NewProp_Rooms,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOrganicDungeonLayout_Statics::NewProp_Hallways_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOrganicDungeonLayout_Statics::NewProp_Hallways,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOrganicDungeonLayout_Statics::NewProp_StartRoomID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOrganicDungeonLayout_Statics::NewProp_EndRoomID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOrganicDungeonLayout_Statics::NewProp_FloorNumber,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOrganicDungeonLayout_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOrganicDungeonLayout_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_EternalDescent,
	nullptr,
	&NewStructOps,
	"OrganicDungeonLayout",
	Z_Construct_UScriptStruct_FOrganicDungeonLayout_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOrganicDungeonLayout_Statics::PropPointers),
	sizeof(FOrganicDungeonLayout),
	alignof(FOrganicDungeonLayout),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOrganicDungeonLayout_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOrganicDungeonLayout_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FOrganicDungeonLayout()
{
	if (!Z_Registration_Info_UScriptStruct_OrganicDungeonLayout.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_OrganicDungeonLayout.InnerSingleton, Z_Construct_UScriptStruct_FOrganicDungeonLayout_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_OrganicDungeonLayout.InnerSingleton;
}
// End ScriptStruct FOrganicDungeonLayout

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

// Begin Class AGridDungeonVisualizer Function ClearDebugGrid
struct Z_Construct_UFunction_AGridDungeonVisualizer_ClearDebugGrid_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Debug" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_ClearDebugGrid_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "ClearDebugGrid", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_ClearDebugGrid_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_ClearDebugGrid_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_ClearDebugGrid()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_ClearDebugGrid_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridDungeonVisualizer::execClearDebugGrid)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClearDebugGrid();
	P_NATIVE_END;
}
// End Class AGridDungeonVisualizer Function ClearDebugGrid

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

// Begin Class AGridDungeonVisualizer Function CreateHallway
struct Z_Construct_UFunction_AGridDungeonVisualizer_CreateHallway_Statics
{
	struct GridDungeonVisualizer_eventCreateHallway_Parms
	{
		int32 RoomA;
		int32 RoomB;
		FHallway ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Organic Dungeon" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_RoomA;
	static const UECodeGen_Private::FIntPropertyParams NewProp_RoomB;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_CreateHallway_Statics::NewProp_RoomA = { "RoomA", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridDungeonVisualizer_eventCreateHallway_Parms, RoomA), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_CreateHallway_Statics::NewProp_RoomB = { "RoomB", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridDungeonVisualizer_eventCreateHallway_Parms, RoomB), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_CreateHallway_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridDungeonVisualizer_eventCreateHallway_Parms, ReturnValue), Z_Construct_UScriptStruct_FHallway, METADATA_PARAMS(0, nullptr) }; // 3248599507
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGridDungeonVisualizer_CreateHallway_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_CreateHallway_Statics::NewProp_RoomA,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_CreateHallway_Statics::NewProp_RoomB,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_CreateHallway_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_CreateHallway_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_CreateHallway_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "CreateHallway", nullptr, nullptr, Z_Construct_UFunction_AGridDungeonVisualizer_CreateHallway_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_CreateHallway_Statics::PropPointers), sizeof(Z_Construct_UFunction_AGridDungeonVisualizer_CreateHallway_Statics::GridDungeonVisualizer_eventCreateHallway_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_CreateHallway_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_CreateHallway_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AGridDungeonVisualizer_CreateHallway_Statics::GridDungeonVisualizer_eventCreateHallway_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_CreateHallway()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_CreateHallway_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridDungeonVisualizer::execCreateHallway)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_RoomA);
	P_GET_PROPERTY(FIntProperty,Z_Param_RoomB);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FHallway*)Z_Param__Result=P_THIS->CreateHallway(Z_Param_RoomA,Z_Param_RoomB);
	P_NATIVE_END;
}
// End Class AGridDungeonVisualizer Function CreateHallway

// Begin Class AGridDungeonVisualizer Function DoRoomsOverlap
struct Z_Construct_UFunction_AGridDungeonVisualizer_DoRoomsOverlap_Statics
{
	struct GridDungeonVisualizer_eventDoRoomsOverlap_Parms
	{
		FOrganicRoom A;
		FOrganicRoom B;
		float Padding;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Organic Dungeon" },
		{ "CPP_Default_Padding", "100.000000" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_A_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_B_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_A;
	static const UECodeGen_Private::FStructPropertyParams NewProp_B;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Padding;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_DoRoomsOverlap_Statics::NewProp_A = { "A", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridDungeonVisualizer_eventDoRoomsOverlap_Parms, A), Z_Construct_UScriptStruct_FOrganicRoom, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_A_MetaData), NewProp_A_MetaData) }; // 444642103
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_DoRoomsOverlap_Statics::NewProp_B = { "B", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridDungeonVisualizer_eventDoRoomsOverlap_Parms, B), Z_Construct_UScriptStruct_FOrganicRoom, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_B_MetaData), NewProp_B_MetaData) }; // 444642103
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_DoRoomsOverlap_Statics::NewProp_Padding = { "Padding", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridDungeonVisualizer_eventDoRoomsOverlap_Parms, Padding), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_AGridDungeonVisualizer_DoRoomsOverlap_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((GridDungeonVisualizer_eventDoRoomsOverlap_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_DoRoomsOverlap_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(GridDungeonVisualizer_eventDoRoomsOverlap_Parms), &Z_Construct_UFunction_AGridDungeonVisualizer_DoRoomsOverlap_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGridDungeonVisualizer_DoRoomsOverlap_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_DoRoomsOverlap_Statics::NewProp_A,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_DoRoomsOverlap_Statics::NewProp_B,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_DoRoomsOverlap_Statics::NewProp_Padding,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_DoRoomsOverlap_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_DoRoomsOverlap_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_DoRoomsOverlap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "DoRoomsOverlap", nullptr, nullptr, Z_Construct_UFunction_AGridDungeonVisualizer_DoRoomsOverlap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_DoRoomsOverlap_Statics::PropPointers), sizeof(Z_Construct_UFunction_AGridDungeonVisualizer_DoRoomsOverlap_Statics::GridDungeonVisualizer_eventDoRoomsOverlap_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_DoRoomsOverlap_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_DoRoomsOverlap_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AGridDungeonVisualizer_DoRoomsOverlap_Statics::GridDungeonVisualizer_eventDoRoomsOverlap_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_DoRoomsOverlap()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_DoRoomsOverlap_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridDungeonVisualizer::execDoRoomsOverlap)
{
	P_GET_STRUCT_REF(FOrganicRoom,Z_Param_Out_A);
	P_GET_STRUCT_REF(FOrganicRoom,Z_Param_Out_B);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Padding);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->DoRoomsOverlap(Z_Param_Out_A,Z_Param_Out_B,Z_Param_Padding);
	P_NATIVE_END;
}
// End Class AGridDungeonVisualizer Function DoRoomsOverlap

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

// Begin Class AGridDungeonVisualizer Function FindValidRoomPosition
struct Z_Construct_UFunction_AGridDungeonVisualizer_FindValidRoomPosition_Statics
{
	struct GridDungeonVisualizer_eventFindValidRoomPosition_Parms
	{
		FOrganicRoom FromRoom;
		FVector2D NewRoomSize;
		float MinDistance;
		float MaxDistance;
		FVector ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Organic Dungeon" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FromRoom_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_FromRoom;
	static const UECodeGen_Private::FStructPropertyParams NewProp_NewRoomSize;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MinDistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxDistance;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_FindValidRoomPosition_Statics::NewProp_FromRoom = { "FromRoom", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridDungeonVisualizer_eventFindValidRoomPosition_Parms, FromRoom), Z_Construct_UScriptStruct_FOrganicRoom, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FromRoom_MetaData), NewProp_FromRoom_MetaData) }; // 444642103
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_FindValidRoomPosition_Statics::NewProp_NewRoomSize = { "NewRoomSize", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridDungeonVisualizer_eventFindValidRoomPosition_Parms, NewRoomSize), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_FindValidRoomPosition_Statics::NewProp_MinDistance = { "MinDistance", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridDungeonVisualizer_eventFindValidRoomPosition_Parms, MinDistance), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_FindValidRoomPosition_Statics::NewProp_MaxDistance = { "MaxDistance", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridDungeonVisualizer_eventFindValidRoomPosition_Parms, MaxDistance), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_FindValidRoomPosition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridDungeonVisualizer_eventFindValidRoomPosition_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGridDungeonVisualizer_FindValidRoomPosition_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_FindValidRoomPosition_Statics::NewProp_FromRoom,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_FindValidRoomPosition_Statics::NewProp_NewRoomSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_FindValidRoomPosition_Statics::NewProp_MinDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_FindValidRoomPosition_Statics::NewProp_MaxDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_FindValidRoomPosition_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_FindValidRoomPosition_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_FindValidRoomPosition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "FindValidRoomPosition", nullptr, nullptr, Z_Construct_UFunction_AGridDungeonVisualizer_FindValidRoomPosition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_FindValidRoomPosition_Statics::PropPointers), sizeof(Z_Construct_UFunction_AGridDungeonVisualizer_FindValidRoomPosition_Statics::GridDungeonVisualizer_eventFindValidRoomPosition_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_FindValidRoomPosition_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_FindValidRoomPosition_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AGridDungeonVisualizer_FindValidRoomPosition_Statics::GridDungeonVisualizer_eventFindValidRoomPosition_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_FindValidRoomPosition()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_FindValidRoomPosition_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridDungeonVisualizer::execFindValidRoomPosition)
{
	P_GET_STRUCT_REF(FOrganicRoom,Z_Param_Out_FromRoom);
	P_GET_STRUCT(FVector2D,Z_Param_NewRoomSize);
	P_GET_PROPERTY(FFloatProperty,Z_Param_MinDistance);
	P_GET_PROPERTY(FFloatProperty,Z_Param_MaxDistance);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FVector*)Z_Param__Result=P_THIS->FindValidRoomPosition(Z_Param_Out_FromRoom,Z_Param_NewRoomSize,Z_Param_MinDistance,Z_Param_MaxDistance);
	P_NATIVE_END;
}
// End Class AGridDungeonVisualizer Function FindValidRoomPosition

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

// Begin Class AGridDungeonVisualizer Function GenerateBranches
struct Z_Construct_UFunction_AGridDungeonVisualizer_GenerateBranches_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Organic Dungeon" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_GenerateBranches_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "GenerateBranches", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_GenerateBranches_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_GenerateBranches_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_GenerateBranches()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_GenerateBranches_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridDungeonVisualizer::execGenerateBranches)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->GenerateBranches();
	P_NATIVE_END;
}
// End Class AGridDungeonVisualizer Function GenerateBranches

// Begin Class AGridDungeonVisualizer Function GenerateHallwayPath
struct Z_Construct_UFunction_AGridDungeonVisualizer_GenerateHallwayPath_Statics
{
	struct GridDungeonVisualizer_eventGenerateHallwayPath_Parms
	{
		FVector StartPos;
		FVector EndPos;
		TArray<FVector> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Organic Dungeon" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_StartPos;
	static const UECodeGen_Private::FStructPropertyParams NewProp_EndPos;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_GenerateHallwayPath_Statics::NewProp_StartPos = { "StartPos", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridDungeonVisualizer_eventGenerateHallwayPath_Parms, StartPos), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_GenerateHallwayPath_Statics::NewProp_EndPos = { "EndPos", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridDungeonVisualizer_eventGenerateHallwayPath_Parms, EndPos), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_GenerateHallwayPath_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_GenerateHallwayPath_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridDungeonVisualizer_eventGenerateHallwayPath_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGridDungeonVisualizer_GenerateHallwayPath_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_GenerateHallwayPath_Statics::NewProp_StartPos,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_GenerateHallwayPath_Statics::NewProp_EndPos,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_GenerateHallwayPath_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_GenerateHallwayPath_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_GenerateHallwayPath_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_GenerateHallwayPath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "GenerateHallwayPath", nullptr, nullptr, Z_Construct_UFunction_AGridDungeonVisualizer_GenerateHallwayPath_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_GenerateHallwayPath_Statics::PropPointers), sizeof(Z_Construct_UFunction_AGridDungeonVisualizer_GenerateHallwayPath_Statics::GridDungeonVisualizer_eventGenerateHallwayPath_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_GenerateHallwayPath_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_GenerateHallwayPath_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AGridDungeonVisualizer_GenerateHallwayPath_Statics::GridDungeonVisualizer_eventGenerateHallwayPath_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_GenerateHallwayPath()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_GenerateHallwayPath_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridDungeonVisualizer::execGenerateHallwayPath)
{
	P_GET_STRUCT(FVector,Z_Param_StartPos);
	P_GET_STRUCT(FVector,Z_Param_EndPos);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FVector>*)Z_Param__Result=P_THIS->GenerateHallwayPath(Z_Param_StartPos,Z_Param_EndPos);
	P_NATIVE_END;
}
// End Class AGridDungeonVisualizer Function GenerateHallwayPath

// Begin Class AGridDungeonVisualizer Function GenerateInEditor
struct Z_Construct_UFunction_AGridDungeonVisualizer_GenerateInEditor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Grid Dungeon" },
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

// Begin Class AGridDungeonVisualizer Function GenerateMainPath
struct Z_Construct_UFunction_AGridDungeonVisualizer_GenerateMainPath_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Organic Dungeon" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_GenerateMainPath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "GenerateMainPath", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_GenerateMainPath_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_GenerateMainPath_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_GenerateMainPath()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_GenerateMainPath_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridDungeonVisualizer::execGenerateMainPath)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->GenerateMainPath();
	P_NATIVE_END;
}
// End Class AGridDungeonVisualizer Function GenerateMainPath

// Begin Class AGridDungeonVisualizer Function GenerateOrganicDungeon
struct Z_Construct_UFunction_AGridDungeonVisualizer_GenerateOrganicDungeon_Statics
{
	struct GridDungeonVisualizer_eventGenerateOrganicDungeon_Parms
	{
		int32 Seed;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Organic Dungeon" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Organic generation functions\n" },
#endif
		{ "CPP_Default_Seed", "-1" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Organic generation functions" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_Seed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AGridDungeonVisualizer_GenerateOrganicDungeon_Statics::NewProp_Seed = { "Seed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridDungeonVisualizer_eventGenerateOrganicDungeon_Parms, Seed), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGridDungeonVisualizer_GenerateOrganicDungeon_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridDungeonVisualizer_GenerateOrganicDungeon_Statics::NewProp_Seed,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_GenerateOrganicDungeon_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_GenerateOrganicDungeon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "GenerateOrganicDungeon", nullptr, nullptr, Z_Construct_UFunction_AGridDungeonVisualizer_GenerateOrganicDungeon_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_GenerateOrganicDungeon_Statics::PropPointers), sizeof(Z_Construct_UFunction_AGridDungeonVisualizer_GenerateOrganicDungeon_Statics::GridDungeonVisualizer_eventGenerateOrganicDungeon_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_GenerateOrganicDungeon_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_GenerateOrganicDungeon_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AGridDungeonVisualizer_GenerateOrganicDungeon_Statics::GridDungeonVisualizer_eventGenerateOrganicDungeon_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_GenerateOrganicDungeon()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_GenerateOrganicDungeon_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridDungeonVisualizer::execGenerateOrganicDungeon)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_Seed);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->GenerateOrganicDungeon(Z_Param_Seed);
	P_NATIVE_END;
}
// End Class AGridDungeonVisualizer Function GenerateOrganicDungeon

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

// Begin Class AGridDungeonVisualizer Function ToggleDebugGridInEditor
struct Z_Construct_UFunction_AGridDungeonVisualizer_ToggleDebugGridInEditor_Statics
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
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridDungeonVisualizer_ToggleDebugGridInEditor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridDungeonVisualizer, nullptr, "ToggleDebugGridInEditor", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridDungeonVisualizer_ToggleDebugGridInEditor_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridDungeonVisualizer_ToggleDebugGridInEditor_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AGridDungeonVisualizer_ToggleDebugGridInEditor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridDungeonVisualizer_ToggleDebugGridInEditor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridDungeonVisualizer::execToggleDebugGridInEditor)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ToggleDebugGridInEditor();
	P_NATIVE_END;
}
// End Class AGridDungeonVisualizer Function ToggleDebugGridInEditor

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
		{ "ClearDebugGrid", &AGridDungeonVisualizer::execClearDebugGrid },
		{ "ClearDungeon", &AGridDungeonVisualizer::execClearDungeon },
		{ "CreateHallway", &AGridDungeonVisualizer::execCreateHallway },
		{ "DoRoomsOverlap", &AGridDungeonVisualizer::execDoRoomsOverlap },
		{ "DrawDebugGrid", &AGridDungeonVisualizer::execDrawDebugGrid },
		{ "FindValidRoomPosition", &AGridDungeonVisualizer::execFindValidRoomPosition },
		{ "GenerateAndVisualizeDungeon", &AGridDungeonVisualizer::execGenerateAndVisualizeDungeon },
		{ "GenerateBranches", &AGridDungeonVisualizer::execGenerateBranches },
		{ "GenerateHallwayPath", &AGridDungeonVisualizer::execGenerateHallwayPath },
		{ "GenerateInEditor", &AGridDungeonVisualizer::execGenerateInEditor },
		{ "GenerateMainPath", &AGridDungeonVisualizer::execGenerateMainPath },
		{ "GenerateOrganicDungeon", &AGridDungeonVisualizer::execGenerateOrganicDungeon },
		{ "GetGridCell", &AGridDungeonVisualizer::execGetGridCell },
		{ "GetStartPosition", &AGridDungeonVisualizer::execGetStartPosition },
		{ "GridToWorldPosition", &AGridDungeonVisualizer::execGridToWorldPosition },
		{ "IsValidGridPosition", &AGridDungeonVisualizer::execIsValidGridPosition },
		{ "PlaceRoomInGrid", &AGridDungeonVisualizer::execPlaceRoomInGrid },
		{ "SetGridCell", &AGridDungeonVisualizer::execSetGridCell },
		{ "SpawnGridVisualization", &AGridDungeonVisualizer::execSpawnGridVisualization },
		{ "SpawnPlayerAtStart", &AGridDungeonVisualizer::execSpawnPlayerAtStart },
		{ "SpawnRoomContents", &AGridDungeonVisualizer::execSpawnRoomContents },
		{ "SpawnTestChestsInRoom", &AGridDungeonVisualizer::execSpawnTestChestsInRoom },
		{ "SpawnTestEnemiesInRoom", &AGridDungeonVisualizer::execSpawnTestEnemiesInRoom },
		{ "ToggleDebugGridInEditor", &AGridDungeonVisualizer::execToggleDebugGridInEditor },
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GenerationType_MetaData[] = {
		{ "Category", "Generation Mode" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Properties - Generation Mode\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Properties - Generation Mode" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoomsPerRow_MetaData[] = {
		{ "Category", "Grid Layout" },
		{ "ClampMax", "10" },
		{ "ClampMin", "1" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Grid-based properties\n" },
#endif
		{ "EditCondition", "GenerationType==EDungeonGenerationType::Grid" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Grid-based properties" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoomsPerColumn_MetaData[] = {
		{ "Category", "Grid Layout" },
		{ "ClampMax", "10" },
		{ "ClampMin", "1" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Number of rooms horizontally\n" },
#endif
		{ "EditCondition", "GenerationType==EDungeonGenerationType::Grid" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Number of rooms horizontally" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TilesPerRoom_MetaData[] = {
		{ "Category", "Grid Layout" },
		{ "ClampMax", "50" },
		{ "ClampMin", "10" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Number of rooms vertically (5x5 = 25 rooms total)\n" },
#endif
		{ "EditCondition", "GenerationType==EDungeonGenerationType::Grid" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Number of rooms vertically (5x5 = 25 rooms total)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TileSizeMultiplier_MetaData[] = {
		{ "Category", "Grid Layout" },
		{ "ClampMax", "10" },
		{ "ClampMin", "1" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Number of tiles per room (20x20 tiles per room)\n" },
#endif
		{ "EditCondition", "GenerationType==EDungeonGenerationType::Grid" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Number of tiles per room (20x20 tiles per room)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinRoomCount_MetaData[] = {
		{ "Category", "Organic Layout" },
		{ "ClampMax", "50" },
		{ "ClampMin", "10" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Organic generation properties\n" },
#endif
		{ "EditCondition", "GenerationType==EDungeonGenerationType::Organic" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Organic generation properties" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxRoomCount_MetaData[] = {
		{ "Category", "Organic Layout" },
		{ "ClampMax", "50" },
		{ "ClampMin", "10" },
		{ "EditCondition", "GenerationType==EDungeonGenerationType::Organic" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinRoomSize_MetaData[] = {
		{ "Category", "Organic Layout" },
		{ "EditCondition", "GenerationType==EDungeonGenerationType::Organic" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxRoomSize_MetaData[] = {
		{ "Category", "Organic Layout" },
		{ "EditCondition", "GenerationType==EDungeonGenerationType::Organic" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HallwayWidth_MetaData[] = {
		{ "Category", "Organic Layout" },
		{ "EditCondition", "GenerationType==EDungeonGenerationType::Organic" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinRoomDistance_MetaData[] = {
		{ "Category", "Organic Layout" },
		{ "EditCondition", "GenerationType==EDungeonGenerationType::Organic" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxRoomDistance_MetaData[] = {
		{ "Category", "Organic Layout" },
		{ "EditCondition", "GenerationType==EDungeonGenerationType::Organic" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BranchingFactor_MetaData[] = {
		{ "Category", "Organic Layout" },
		{ "EditCondition", "GenerationType==EDungeonGenerationType::Organic" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DeadEndChance_MetaData[] = {
		{ "Category", "Organic Layout" },
		{ "EditCondition", "GenerationType==EDungeonGenerationType::Organic" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WallHeight_MetaData[] = {
		{ "Category", "General Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Shared properties\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Shared properties" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GridSizeX_MetaData[] = {
		{ "Category", "Grid Info" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Calculated grid size (read-only in editor)\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Calculated grid size (read-only in editor)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GridSizeY_MetaData[] = {
		{ "Category", "Grid Info" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Will be RoomsPerRow * TilesPerRoom\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Will be RoomsPerRow * TilesPerRoom" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CellSize_MetaData[] = {
		{ "Category", "Grid Info" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Will be RoomsPerColumn * TilesPerRoom\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Will be RoomsPerColumn * TilesPerRoom" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutoGenerateOnBeginPlay_MetaData[] = {
		{ "Category", "Grid Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Will be equal to TileSize\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Will be equal to TileSize" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowDebugGrid_MetaData[] = {
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DebugDrawDuration_MetaData[] = {
		{ "Category", "Debug" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentFloor_MetaData[] = {
		{ "Category", "Grid Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// 0 = persistent\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "0 = persistent" },
#endif
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
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Scaled up for spacious mannequin-sized rooms\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Scaled up for spacious mannequin-sized rooms" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ADASystem_MetaData[] = {
		{ "Category", "References" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// References\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "References" },
#endif
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
		{ "Comment", "// 1D array representing 2D grid (for grid mode)\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "1D array representing 2D grid (for grid mode)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OrganicLayout_MetaData[] = {
		{ "Category", "Runtime" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// For grid mode\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "For grid mode" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StartRoomGridPos_MetaData[] = {
		{ "Category", "Runtime" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// For organic mode\n" },
#endif
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "For organic mode" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExitRoomGridPos_MetaData[] = {
		{ "Category", "Runtime" },
		{ "ModuleRelativePath", "Public/GridDungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RandomStream_MetaData[] = {
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
	static const UECodeGen_Private::FBytePropertyParams NewProp_GenerationType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_GenerationType;
	static const UECodeGen_Private::FIntPropertyParams NewProp_RoomsPerRow;
	static const UECodeGen_Private::FIntPropertyParams NewProp_RoomsPerColumn;
	static const UECodeGen_Private::FIntPropertyParams NewProp_TilesPerRoom;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TileSizeMultiplier;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MinRoomCount;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxRoomCount;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MinRoomSize;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxRoomSize;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_HallwayWidth;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MinRoomDistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxRoomDistance;
	static const UECodeGen_Private::FIntPropertyParams NewProp_BranchingFactor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DeadEndChance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WallHeight;
	static const UECodeGen_Private::FIntPropertyParams NewProp_GridSizeX;
	static const UECodeGen_Private::FIntPropertyParams NewProp_GridSizeY;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CellSize;
	static void NewProp_bAutoGenerateOnBeginPlay_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoGenerateOnBeginPlay;
	static void NewProp_bShowDebugGrid_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowDebugGrid;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DebugLineThickness;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DebugGridColor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DebugDrawDuration;
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
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ADASystem;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Grid_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Grid;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CurrentLayout;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OrganicLayout;
	static const UECodeGen_Private::FStructPropertyParams NewProp_StartRoomGridPos;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ExitRoomGridPos;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RandomStream;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlaneInstances;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CubeInstances;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TestEnemyInstances;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TestChestInstances;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_BuildGridFromLayout, "BuildGridFromLayout" }, // 1493721323
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_ClearDebugGrid, "ClearDebugGrid" }, // 3473848458
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_ClearDungeon, "ClearDungeon" }, // 3547271859
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_CreateHallway, "CreateHallway" }, // 1832708661
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_DoRoomsOverlap, "DoRoomsOverlap" }, // 2343941400
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_DrawDebugGrid, "DrawDebugGrid" }, // 2869966766
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_FindValidRoomPosition, "FindValidRoomPosition" }, // 3501609226
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_GenerateAndVisualizeDungeon, "GenerateAndVisualizeDungeon" }, // 2237856306
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_GenerateBranches, "GenerateBranches" }, // 1704557269
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_GenerateHallwayPath, "GenerateHallwayPath" }, // 1255095547
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_GenerateInEditor, "GenerateInEditor" }, // 3405822899
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_GenerateMainPath, "GenerateMainPath" }, // 2829238691
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_GenerateOrganicDungeon, "GenerateOrganicDungeon" }, // 3490737950
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_GetGridCell, "GetGridCell" }, // 1374691265
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_GetStartPosition, "GetStartPosition" }, // 1733970434
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_GridToWorldPosition, "GridToWorldPosition" }, // 1370963437
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_IsValidGridPosition, "IsValidGridPosition" }, // 3376793452
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_OnTestChestSpawned, "OnTestChestSpawned" }, // 2857963953
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_OnTestEnemySpawned, "OnTestEnemySpawned" }, // 81384815
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_PlaceRoomInGrid, "PlaceRoomInGrid" }, // 3695893506
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_SetGridCell, "SetGridCell" }, // 1300402336
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_SpawnGridVisualization, "SpawnGridVisualization" }, // 3357062006
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_SpawnPlayerAtStart, "SpawnPlayerAtStart" }, // 1533279445
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_SpawnRoomContents, "SpawnRoomContents" }, // 1362863565
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_SpawnTestChestsInRoom, "SpawnTestChestsInRoom" }, // 3559755509
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_SpawnTestEnemiesInRoom, "SpawnTestEnemiesInRoom" }, // 876117065
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_ToggleDebugGridInEditor, "ToggleDebugGridInEditor" }, // 805795200
		{ &Z_Construct_UFunction_AGridDungeonVisualizer_WorldToGridPosition, "WorldToGridPosition" }, // 3633239547
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGridDungeonVisualizer>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_GenerationType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_GenerationType = { "GenerationType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, GenerationType), Z_Construct_UEnum_EternalDescent_EDungeonGenerationType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GenerationType_MetaData), NewProp_GenerationType_MetaData) }; // 341224637
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_RoomsPerRow = { "RoomsPerRow", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, RoomsPerRow), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoomsPerRow_MetaData), NewProp_RoomsPerRow_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_RoomsPerColumn = { "RoomsPerColumn", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, RoomsPerColumn), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoomsPerColumn_MetaData), NewProp_RoomsPerColumn_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_TilesPerRoom = { "TilesPerRoom", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, TilesPerRoom), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TilesPerRoom_MetaData), NewProp_TilesPerRoom_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_TileSizeMultiplier = { "TileSizeMultiplier", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, TileSizeMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TileSizeMultiplier_MetaData), NewProp_TileSizeMultiplier_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_MinRoomCount = { "MinRoomCount", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, MinRoomCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinRoomCount_MetaData), NewProp_MinRoomCount_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_MaxRoomCount = { "MaxRoomCount", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, MaxRoomCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxRoomCount_MetaData), NewProp_MaxRoomCount_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_MinRoomSize = { "MinRoomSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, MinRoomSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinRoomSize_MetaData), NewProp_MinRoomSize_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_MaxRoomSize = { "MaxRoomSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, MaxRoomSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxRoomSize_MetaData), NewProp_MaxRoomSize_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_HallwayWidth = { "HallwayWidth", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, HallwayWidth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HallwayWidth_MetaData), NewProp_HallwayWidth_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_MinRoomDistance = { "MinRoomDistance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, MinRoomDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinRoomDistance_MetaData), NewProp_MinRoomDistance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_MaxRoomDistance = { "MaxRoomDistance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, MaxRoomDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxRoomDistance_MetaData), NewProp_MaxRoomDistance_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_BranchingFactor = { "BranchingFactor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, BranchingFactor), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BranchingFactor_MetaData), NewProp_BranchingFactor_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_DeadEndChance = { "DeadEndChance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, DeadEndChance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DeadEndChance_MetaData), NewProp_DeadEndChance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_WallHeight = { "WallHeight", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, WallHeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WallHeight_MetaData), NewProp_WallHeight_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_GridSizeX = { "GridSizeX", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, GridSizeX), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GridSizeX_MetaData), NewProp_GridSizeX_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_GridSizeY = { "GridSizeY", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, GridSizeY), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GridSizeY_MetaData), NewProp_GridSizeY_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_CellSize = { "CellSize", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, CellSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CellSize_MetaData), NewProp_CellSize_MetaData) };
void Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bAutoGenerateOnBeginPlay_SetBit(void* Obj)
{
	((AGridDungeonVisualizer*)Obj)->bAutoGenerateOnBeginPlay = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bAutoGenerateOnBeginPlay = { "bAutoGenerateOnBeginPlay", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AGridDungeonVisualizer), &Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bAutoGenerateOnBeginPlay_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutoGenerateOnBeginPlay_MetaData), NewProp_bAutoGenerateOnBeginPlay_MetaData) };
void Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bShowDebugGrid_SetBit(void* Obj)
{
	((AGridDungeonVisualizer*)Obj)->bShowDebugGrid = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bShowDebugGrid = { "bShowDebugGrid", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AGridDungeonVisualizer), &Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bShowDebugGrid_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowDebugGrid_MetaData), NewProp_bShowDebugGrid_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_DebugLineThickness = { "DebugLineThickness", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, DebugLineThickness), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DebugLineThickness_MetaData), NewProp_DebugLineThickness_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_DebugGridColor = { "DebugGridColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, DebugGridColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DebugGridColor_MetaData), NewProp_DebugGridColor_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_DebugDrawDuration = { "DebugDrawDuration", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, DebugDrawDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DebugDrawDuration_MetaData), NewProp_DebugDrawDuration_MetaData) };
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
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_ADASystem = { "ADASystem", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, ADASystem), Z_Construct_UClass_AADASystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ADASystem_MetaData), NewProp_ADASystem_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_Grid_Inner = { "Grid", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FGridCell, METADATA_PARAMS(0, nullptr) }; // 357869723
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_Grid = { "Grid", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, Grid), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Grid_MetaData), NewProp_Grid_MetaData) }; // 357869723
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_CurrentLayout = { "CurrentLayout", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, CurrentLayout), Z_Construct_UScriptStruct_FDungeonLayout, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentLayout_MetaData), NewProp_CurrentLayout_MetaData) }; // 3903890264
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_OrganicLayout = { "OrganicLayout", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, OrganicLayout), Z_Construct_UScriptStruct_FOrganicDungeonLayout, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OrganicLayout_MetaData), NewProp_OrganicLayout_MetaData) }; // 3367489019
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_StartRoomGridPos = { "StartRoomGridPos", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, StartRoomGridPos), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StartRoomGridPos_MetaData), NewProp_StartRoomGridPos_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_ExitRoomGridPos = { "ExitRoomGridPos", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, ExitRoomGridPos), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExitRoomGridPos_MetaData), NewProp_ExitRoomGridPos_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_RandomStream = { "RandomStream", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, RandomStream), Z_Construct_UScriptStruct_FRandomStream, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RandomStream_MetaData), NewProp_RandomStream_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_PlaneInstances = { "PlaneInstances", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, PlaneInstances), Z_Construct_UClass_UInstancedStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlaneInstances_MetaData), NewProp_PlaneInstances_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_CubeInstances = { "CubeInstances", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, CubeInstances), Z_Construct_UClass_UInstancedStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CubeInstances_MetaData), NewProp_CubeInstances_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_TestEnemyInstances = { "TestEnemyInstances", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, TestEnemyInstances), Z_Construct_UClass_UInstancedStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TestEnemyInstances_MetaData), NewProp_TestEnemyInstances_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_TestChestInstances = { "TestChestInstances", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridDungeonVisualizer, TestChestInstances), Z_Construct_UClass_UInstancedStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TestChestInstances_MetaData), NewProp_TestChestInstances_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGridDungeonVisualizer_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_GenerationType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_GenerationType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_RoomsPerRow,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_RoomsPerColumn,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_TilesPerRoom,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_TileSizeMultiplier,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_MinRoomCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_MaxRoomCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_MinRoomSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_MaxRoomSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_HallwayWidth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_MinRoomDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_MaxRoomDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_BranchingFactor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_DeadEndChance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_WallHeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_GridSizeX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_GridSizeY,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_CellSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bAutoGenerateOnBeginPlay,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_bShowDebugGrid,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_DebugLineThickness,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_DebugGridColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_DebugDrawDuration,
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
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_ADASystem,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_Grid_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_Grid,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_CurrentLayout,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_OrganicLayout,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_StartRoomGridPos,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_ExitRoomGridPos,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridDungeonVisualizer_Statics::NewProp_RandomStream,
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
		{ EDungeonGenerationType_StaticEnum, TEXT("EDungeonGenerationType"), &Z_Registration_Info_UEnum_EDungeonGenerationType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 341224637U) },
		{ EGridCellType_StaticEnum, TEXT("EGridCellType"), &Z_Registration_Info_UEnum_EGridCellType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3357014927U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FGridCell::StaticStruct, Z_Construct_UScriptStruct_FGridCell_Statics::NewStructOps, TEXT("GridCell"), &Z_Registration_Info_UScriptStruct_GridCell, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FGridCell), 357869723U) },
		{ FOrganicRoom::StaticStruct, Z_Construct_UScriptStruct_FOrganicRoom_Statics::NewStructOps, TEXT("OrganicRoom"), &Z_Registration_Info_UScriptStruct_OrganicRoom, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOrganicRoom), 444642103U) },
		{ FHallway::StaticStruct, Z_Construct_UScriptStruct_FHallway_Statics::NewStructOps, TEXT("Hallway"), &Z_Registration_Info_UScriptStruct_Hallway, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FHallway), 3248599507U) },
		{ FOrganicDungeonLayout::StaticStruct, Z_Construct_UScriptStruct_FOrganicDungeonLayout_Statics::NewStructOps, TEXT("OrganicDungeonLayout"), &Z_Registration_Info_UScriptStruct_OrganicDungeonLayout, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOrganicDungeonLayout), 3367489019U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AGridDungeonVisualizer, AGridDungeonVisualizer::StaticClass, TEXT("AGridDungeonVisualizer"), &Z_Registration_Info_UClass_AGridDungeonVisualizer, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGridDungeonVisualizer), 2214703673U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_2966519688(TEXT("/Script/EternalDescent"),
	Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_GridDungeonVisualizer_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
