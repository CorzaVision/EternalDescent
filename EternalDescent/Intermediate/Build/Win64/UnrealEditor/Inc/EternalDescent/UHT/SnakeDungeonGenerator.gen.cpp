// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EternalDescent/Public/SnakeDungeonGenerator.h"
#include "EternalDescent/Public/CubeDungeonTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSnakeDungeonGenerator() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntVector();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ETERNALDESCENT_API UClass* Z_Construct_UClass_ASnakeDungeonGenerator();
ETERNALDESCENT_API UClass* Z_Construct_UClass_ASnakeDungeonGenerator_NoRegister();
ETERNALDESCENT_API UEnum* Z_Construct_UEnum_EternalDescent_EContentMarkerType();
ETERNALDESCENT_API UEnum* Z_Construct_UEnum_EternalDescent_ERoomType();
ETERNALDESCENT_API UEnum* Z_Construct_UEnum_EternalDescent_EStageType();
ETERNALDESCENT_API UScriptStruct* Z_Construct_UScriptStruct_FContentMarker();
ETERNALDESCENT_API UScriptStruct* Z_Construct_UScriptStruct_FDungeonCube();
ETERNALDESCENT_API UScriptStruct* Z_Construct_UScriptStruct_FHallwayConnection();
ETERNALDESCENT_API UScriptStruct* Z_Construct_UScriptStruct_FSnakeDungeonLayout();
ETERNALDESCENT_API UScriptStruct* Z_Construct_UScriptStruct_FSnakeRoom();
UPackage* Z_Construct_UPackage__Script_EternalDescent();
// End Cross Module References

// Begin Enum EStageType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EStageType;
static UEnum* EStageType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EStageType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EStageType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_EternalDescent_EStageType, (UObject*)Z_Construct_UPackage__Script_EternalDescent(), TEXT("EStageType"));
	}
	return Z_Registration_Info_UEnum_EStageType.OuterSingleton;
}
template<> ETERNALDESCENT_API UEnum* StaticEnum<EStageType>()
{
	return EStageType_StaticEnum();
}
struct Z_Construct_UEnum_EternalDescent_EStageType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Boss.DisplayName", "Boss Stage (Every 10)" },
		{ "Boss.Name", "EStageType::Boss" },
		{ "Elite.DisplayName", "Elite Stage (Every 5)" },
		{ "Elite.Name", "EStageType::Elite" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
		{ "Normal.DisplayName", "Normal Stage" },
		{ "Normal.Name", "EStageType::Normal" },
		{ "SafeZone.DisplayName", "Safe Zone" },
		{ "SafeZone.Name", "EStageType::SafeZone" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EStageType::Normal", (int64)EStageType::Normal },
		{ "EStageType::Elite", (int64)EStageType::Elite },
		{ "EStageType::Boss", (int64)EStageType::Boss },
		{ "EStageType::SafeZone", (int64)EStageType::SafeZone },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_EternalDescent_EStageType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_EternalDescent,
	nullptr,
	"EStageType",
	"EStageType",
	Z_Construct_UEnum_EternalDescent_EStageType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_EternalDescent_EStageType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_EternalDescent_EStageType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_EternalDescent_EStageType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_EternalDescent_EStageType()
{
	if (!Z_Registration_Info_UEnum_EStageType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EStageType.InnerSingleton, Z_Construct_UEnum_EternalDescent_EStageType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EStageType.InnerSingleton;
}
// End Enum EStageType

// Begin Enum EContentMarkerType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EContentMarkerType;
static UEnum* EContentMarkerType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EContentMarkerType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EContentMarkerType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_EternalDescent_EContentMarkerType, (UObject*)Z_Construct_UPackage__Script_EternalDescent(), TEXT("EContentMarkerType"));
	}
	return Z_Registration_Info_UEnum_EContentMarkerType.OuterSingleton;
}
template<> ETERNALDESCENT_API UEnum* StaticEnum<EContentMarkerType>()
{
	return EContentMarkerType_StaticEnum();
}
struct Z_Construct_UEnum_EternalDescent_EContentMarkerType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Boss.DisplayName", "Boss Enemy" },
		{ "Boss.Name", "EContentMarkerType::Boss" },
		{ "Chest.DisplayName", "Treasure Chest" },
		{ "Chest.Name", "EContentMarkerType::Chest" },
		{ "Elite.DisplayName", "Elite Enemy" },
		{ "Elite.Name", "EContentMarkerType::Elite" },
		{ "Enemy.DisplayName", "Enemy Spawn" },
		{ "Enemy.Name", "EContentMarkerType::Enemy" },
		{ "Interactable.DisplayName", "Interactable Object" },
		{ "Interactable.Name", "EContentMarkerType::Interactable" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
		{ "Puzzle.DisplayName", "Puzzle Element" },
		{ "Puzzle.Name", "EContentMarkerType::Puzzle" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EContentMarkerType::Enemy", (int64)EContentMarkerType::Enemy },
		{ "EContentMarkerType::Chest", (int64)EContentMarkerType::Chest },
		{ "EContentMarkerType::Puzzle", (int64)EContentMarkerType::Puzzle },
		{ "EContentMarkerType::Interactable", (int64)EContentMarkerType::Interactable },
		{ "EContentMarkerType::Elite", (int64)EContentMarkerType::Elite },
		{ "EContentMarkerType::Boss", (int64)EContentMarkerType::Boss },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_EternalDescent_EContentMarkerType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_EternalDescent,
	nullptr,
	"EContentMarkerType",
	"EContentMarkerType",
	Z_Construct_UEnum_EternalDescent_EContentMarkerType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_EternalDescent_EContentMarkerType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_EternalDescent_EContentMarkerType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_EternalDescent_EContentMarkerType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_EternalDescent_EContentMarkerType()
{
	if (!Z_Registration_Info_UEnum_EContentMarkerType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EContentMarkerType.InnerSingleton, Z_Construct_UEnum_EternalDescent_EContentMarkerType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EContentMarkerType.InnerSingleton;
}
// End Enum EContentMarkerType

// Begin ScriptStruct FContentMarker
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_ContentMarker;
class UScriptStruct* FContentMarker::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_ContentMarker.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_ContentMarker.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FContentMarker, (UObject*)Z_Construct_UPackage__Script_EternalDescent(), TEXT("ContentMarker"));
	}
	return Z_Registration_Info_UScriptStruct_ContentMarker.OuterSingleton;
}
template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<FContentMarker>()
{
	return FContentMarker::StaticStruct();
}
struct Z_Construct_UScriptStruct_FContentMarker_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Content marker for spawning entities in rooms\n" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Content marker for spawning entities in rooms" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RelativePosition_MetaData[] = {
		{ "Category", "ContentMarker" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Type_MetaData[] = {
		{ "Category", "ContentMarker" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Position relative to room center\n" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Position relative to room center" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Radius_MetaData[] = {
		{ "Category", "ContentMarker" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Height_MetaData[] = {
		{ "Category", "ContentMarker" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Capsule radius for enemies, sphere radius for chests\n" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Capsule radius for enemies, sphere radius for chests" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DifficultyTier_MetaData[] = {
		{ "Category", "ContentMarker" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Capsule height for enemies (ignored for spheres)\n" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Capsule height for enemies (ignored for spheres)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ContentID_MetaData[] = {
		{ "Category", "ContentMarker" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// 1-3 for enemy difficulty\n" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "1-3 for enemy difficulty" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_RelativePosition;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Type_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Type;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Radius;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Height;
	static const UECodeGen_Private::FIntPropertyParams NewProp_DifficultyTier;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ContentID;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FContentMarker>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FContentMarker_Statics::NewProp_RelativePosition = { "RelativePosition", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FContentMarker, RelativePosition), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RelativePosition_MetaData), NewProp_RelativePosition_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FContentMarker_Statics::NewProp_Type_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FContentMarker_Statics::NewProp_Type = { "Type", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FContentMarker, Type), Z_Construct_UEnum_EternalDescent_EContentMarkerType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Type_MetaData), NewProp_Type_MetaData) }; // 923544256
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FContentMarker_Statics::NewProp_Radius = { "Radius", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FContentMarker, Radius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Radius_MetaData), NewProp_Radius_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FContentMarker_Statics::NewProp_Height = { "Height", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FContentMarker, Height), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Height_MetaData), NewProp_Height_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FContentMarker_Statics::NewProp_DifficultyTier = { "DifficultyTier", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FContentMarker, DifficultyTier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DifficultyTier_MetaData), NewProp_DifficultyTier_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FContentMarker_Statics::NewProp_ContentID = { "ContentID", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FContentMarker, ContentID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ContentID_MetaData), NewProp_ContentID_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FContentMarker_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FContentMarker_Statics::NewProp_RelativePosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FContentMarker_Statics::NewProp_Type_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FContentMarker_Statics::NewProp_Type,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FContentMarker_Statics::NewProp_Radius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FContentMarker_Statics::NewProp_Height,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FContentMarker_Statics::NewProp_DifficultyTier,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FContentMarker_Statics::NewProp_ContentID,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FContentMarker_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FContentMarker_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_EternalDescent,
	nullptr,
	&NewStructOps,
	"ContentMarker",
	Z_Construct_UScriptStruct_FContentMarker_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FContentMarker_Statics::PropPointers),
	sizeof(FContentMarker),
	alignof(FContentMarker),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FContentMarker_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FContentMarker_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FContentMarker()
{
	if (!Z_Registration_Info_UScriptStruct_ContentMarker.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_ContentMarker.InnerSingleton, Z_Construct_UScriptStruct_FContentMarker_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_ContentMarker.InnerSingleton;
}
// End ScriptStruct FContentMarker

// Begin ScriptStruct FSnakeRoom
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SnakeRoom;
class UScriptStruct* FSnakeRoom::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SnakeRoom.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SnakeRoom.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSnakeRoom, (UObject*)Z_Construct_UPackage__Script_EternalDescent(), TEXT("SnakeRoom"));
	}
	return Z_Registration_Info_UScriptStruct_SnakeRoom.OuterSingleton;
}
template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<FSnakeRoom>()
{
	return FSnakeRoom::StaticStruct();
}
struct Z_Construct_UScriptStruct_FSnakeRoom_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoomID_MetaData[] = {
		{ "Category", "SnakeRoom" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Center_MetaData[] = {
		{ "Category", "SnakeRoom" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Size_MetaData[] = {
		{ "Category", "SnakeRoom" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Type_MetaData[] = {
		{ "Category", "SnakeRoom" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StageType_MetaData[] = {
		{ "Category", "SnakeRoom" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ConnectedRooms_MetaData[] = {
		{ "Category", "SnakeRoom" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PathOrder_MetaData[] = {
		{ "Category", "SnakeRoom" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsMainPath_MetaData[] = {
		{ "Category", "SnakeRoom" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Position in snake path (0 = start)\n" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Position in snake path (0 = start)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAllowBranching_MetaData[] = {
		{ "Category", "SnakeRoom" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ContentMarkers_MetaData[] = {
		{ "Category", "SnakeRoom" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_RoomID;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Center;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Size;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Type_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Type;
	static const UECodeGen_Private::FBytePropertyParams NewProp_StageType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_StageType;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ConnectedRooms_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ConnectedRooms;
	static const UECodeGen_Private::FIntPropertyParams NewProp_PathOrder;
	static void NewProp_bIsMainPath_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsMainPath;
	static void NewProp_bAllowBranching_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAllowBranching;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ContentMarkers_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ContentMarkers;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSnakeRoom>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSnakeRoom_Statics::NewProp_RoomID = { "RoomID", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeRoom, RoomID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoomID_MetaData), NewProp_RoomID_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSnakeRoom_Statics::NewProp_Center = { "Center", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeRoom, Center), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Center_MetaData), NewProp_Center_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSnakeRoom_Statics::NewProp_Size = { "Size", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeRoom, Size), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Size_MetaData), NewProp_Size_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FSnakeRoom_Statics::NewProp_Type_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FSnakeRoom_Statics::NewProp_Type = { "Type", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeRoom, Type), Z_Construct_UEnum_EternalDescent_ERoomType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Type_MetaData), NewProp_Type_MetaData) }; // 1291513837
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FSnakeRoom_Statics::NewProp_StageType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FSnakeRoom_Statics::NewProp_StageType = { "StageType", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeRoom, StageType), Z_Construct_UEnum_EternalDescent_EStageType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StageType_MetaData), NewProp_StageType_MetaData) }; // 1048845958
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSnakeRoom_Statics::NewProp_ConnectedRooms_Inner = { "ConnectedRooms", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FSnakeRoom_Statics::NewProp_ConnectedRooms = { "ConnectedRooms", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeRoom, ConnectedRooms), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ConnectedRooms_MetaData), NewProp_ConnectedRooms_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSnakeRoom_Statics::NewProp_PathOrder = { "PathOrder", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeRoom, PathOrder), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PathOrder_MetaData), NewProp_PathOrder_MetaData) };
void Z_Construct_UScriptStruct_FSnakeRoom_Statics::NewProp_bIsMainPath_SetBit(void* Obj)
{
	((FSnakeRoom*)Obj)->bIsMainPath = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSnakeRoom_Statics::NewProp_bIsMainPath = { "bIsMainPath", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FSnakeRoom), &Z_Construct_UScriptStruct_FSnakeRoom_Statics::NewProp_bIsMainPath_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsMainPath_MetaData), NewProp_bIsMainPath_MetaData) };
void Z_Construct_UScriptStruct_FSnakeRoom_Statics::NewProp_bAllowBranching_SetBit(void* Obj)
{
	((FSnakeRoom*)Obj)->bAllowBranching = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSnakeRoom_Statics::NewProp_bAllowBranching = { "bAllowBranching", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FSnakeRoom), &Z_Construct_UScriptStruct_FSnakeRoom_Statics::NewProp_bAllowBranching_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAllowBranching_MetaData), NewProp_bAllowBranching_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSnakeRoom_Statics::NewProp_ContentMarkers_Inner = { "ContentMarkers", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FContentMarker, METADATA_PARAMS(0, nullptr) }; // 4001349238
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FSnakeRoom_Statics::NewProp_ContentMarkers = { "ContentMarkers", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeRoom, ContentMarkers), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ContentMarkers_MetaData), NewProp_ContentMarkers_MetaData) }; // 4001349238
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSnakeRoom_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeRoom_Statics::NewProp_RoomID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeRoom_Statics::NewProp_Center,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeRoom_Statics::NewProp_Size,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeRoom_Statics::NewProp_Type_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeRoom_Statics::NewProp_Type,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeRoom_Statics::NewProp_StageType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeRoom_Statics::NewProp_StageType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeRoom_Statics::NewProp_ConnectedRooms_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeRoom_Statics::NewProp_ConnectedRooms,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeRoom_Statics::NewProp_PathOrder,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeRoom_Statics::NewProp_bIsMainPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeRoom_Statics::NewProp_bAllowBranching,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeRoom_Statics::NewProp_ContentMarkers_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeRoom_Statics::NewProp_ContentMarkers,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSnakeRoom_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSnakeRoom_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_EternalDescent,
	nullptr,
	&NewStructOps,
	"SnakeRoom",
	Z_Construct_UScriptStruct_FSnakeRoom_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSnakeRoom_Statics::PropPointers),
	sizeof(FSnakeRoom),
	alignof(FSnakeRoom),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSnakeRoom_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSnakeRoom_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FSnakeRoom()
{
	if (!Z_Registration_Info_UScriptStruct_SnakeRoom.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SnakeRoom.InnerSingleton, Z_Construct_UScriptStruct_FSnakeRoom_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_SnakeRoom.InnerSingleton;
}
// End ScriptStruct FSnakeRoom

// Begin ScriptStruct FHallwayConnection
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_HallwayConnection;
class UScriptStruct* FHallwayConnection::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_HallwayConnection.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_HallwayConnection.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FHallwayConnection, (UObject*)Z_Construct_UPackage__Script_EternalDescent(), TEXT("HallwayConnection"));
	}
	return Z_Registration_Info_UScriptStruct_HallwayConnection.OuterSingleton;
}
template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<FHallwayConnection>()
{
	return FHallwayConnection::StaticStruct();
}
struct Z_Construct_UScriptStruct_FHallwayConnection_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FromRoomID_MetaData[] = {
		{ "Category", "HallwayConnection" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ToRoomID_MetaData[] = {
		{ "Category", "HallwayConnection" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Path_MetaData[] = {
		{ "Category", "HallwayConnection" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Length_MetaData[] = {
		{ "Category", "HallwayConnection" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsMainPath_MetaData[] = {
		{ "Category", "HallwayConnection" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// In cubes\n" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "In cubes" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_FromRoomID;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ToRoomID;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Path_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Path;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Length;
	static void NewProp_bIsMainPath_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsMainPath;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FHallwayConnection>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FHallwayConnection_Statics::NewProp_FromRoomID = { "FromRoomID", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHallwayConnection, FromRoomID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FromRoomID_MetaData), NewProp_FromRoomID_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FHallwayConnection_Statics::NewProp_ToRoomID = { "ToRoomID", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHallwayConnection, ToRoomID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ToRoomID_MetaData), NewProp_ToRoomID_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FHallwayConnection_Statics::NewProp_Path_Inner = { "Path", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FHallwayConnection_Statics::NewProp_Path = { "Path", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHallwayConnection, Path), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Path_MetaData), NewProp_Path_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FHallwayConnection_Statics::NewProp_Length = { "Length", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHallwayConnection, Length), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Length_MetaData), NewProp_Length_MetaData) };
void Z_Construct_UScriptStruct_FHallwayConnection_Statics::NewProp_bIsMainPath_SetBit(void* Obj)
{
	((FHallwayConnection*)Obj)->bIsMainPath = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FHallwayConnection_Statics::NewProp_bIsMainPath = { "bIsMainPath", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FHallwayConnection), &Z_Construct_UScriptStruct_FHallwayConnection_Statics::NewProp_bIsMainPath_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsMainPath_MetaData), NewProp_bIsMainPath_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FHallwayConnection_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHallwayConnection_Statics::NewProp_FromRoomID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHallwayConnection_Statics::NewProp_ToRoomID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHallwayConnection_Statics::NewProp_Path_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHallwayConnection_Statics::NewProp_Path,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHallwayConnection_Statics::NewProp_Length,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHallwayConnection_Statics::NewProp_bIsMainPath,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHallwayConnection_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FHallwayConnection_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_EternalDescent,
	nullptr,
	&NewStructOps,
	"HallwayConnection",
	Z_Construct_UScriptStruct_FHallwayConnection_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHallwayConnection_Statics::PropPointers),
	sizeof(FHallwayConnection),
	alignof(FHallwayConnection),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHallwayConnection_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FHallwayConnection_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FHallwayConnection()
{
	if (!Z_Registration_Info_UScriptStruct_HallwayConnection.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_HallwayConnection.InnerSingleton, Z_Construct_UScriptStruct_FHallwayConnection_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_HallwayConnection.InnerSingleton;
}
// End ScriptStruct FHallwayConnection

// Begin ScriptStruct FSnakeDungeonLayout
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SnakeDungeonLayout;
class UScriptStruct* FSnakeDungeonLayout::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SnakeDungeonLayout.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SnakeDungeonLayout.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSnakeDungeonLayout, (UObject*)Z_Construct_UPackage__Script_EternalDescent(), TEXT("SnakeDungeonLayout"));
	}
	return Z_Registration_Info_UScriptStruct_SnakeDungeonLayout.OuterSingleton;
}
template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<FSnakeDungeonLayout>()
{
	return FSnakeDungeonLayout::StaticStruct();
}
struct Z_Construct_UScriptStruct_FSnakeDungeonLayout_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StageNumber_MetaData[] = {
		{ "Category", "SnakeDungeonLayout" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StageType_MetaData[] = {
		{ "Category", "SnakeDungeonLayout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// 1-20\n" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "1-20" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rooms_MetaData[] = {
		{ "Category", "SnakeDungeonLayout" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Hallways_MetaData[] = {
		{ "Category", "SnakeDungeonLayout" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MainPathRoomOrder_MetaData[] = {
		{ "Category", "SnakeDungeonLayout" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FillerCubes_MetaData[] = {
		{ "Category", "SnakeDungeonLayout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Room IDs in snake path order\n" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Room IDs in snake path order" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GridBounds_MetaData[] = {
		{ "Category", "SnakeDungeonLayout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Space-filling cubes\n" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Space-filling cubes" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StartRoomID_MetaData[] = {
		{ "Category", "SnakeDungeonLayout" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EndRoomID_MetaData[] = {
		{ "Category", "SnakeDungeonLayout" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EliteRoomID_MetaData[] = {
		{ "Category", "SnakeDungeonLayout" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BossRoomID_MetaData[] = {
		{ "Category", "SnakeDungeonLayout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// -1 if not elite stage\n" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "-1 if not elite stage" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GenerationTime_MetaData[] = {
		{ "Category", "SnakeDungeonLayout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// -1 if not boss stage\n" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "-1 if not boss stage" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_StageNumber;
	static const UECodeGen_Private::FBytePropertyParams NewProp_StageType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_StageType;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Rooms_ValueProp;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Rooms_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_Rooms;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Hallways_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Hallways;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MainPathRoomOrder_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_MainPathRoomOrder;
	static const UECodeGen_Private::FStructPropertyParams NewProp_FillerCubes_ValueProp;
	static const UECodeGen_Private::FStructPropertyParams NewProp_FillerCubes_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_FillerCubes;
	static const UECodeGen_Private::FStructPropertyParams NewProp_GridBounds;
	static const UECodeGen_Private::FIntPropertyParams NewProp_StartRoomID;
	static const UECodeGen_Private::FIntPropertyParams NewProp_EndRoomID;
	static const UECodeGen_Private::FIntPropertyParams NewProp_EliteRoomID;
	static const UECodeGen_Private::FIntPropertyParams NewProp_BossRoomID;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GenerationTime;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSnakeDungeonLayout>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSnakeDungeonLayout_Statics::NewProp_StageNumber = { "StageNumber", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeDungeonLayout, StageNumber), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StageNumber_MetaData), NewProp_StageNumber_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FSnakeDungeonLayout_Statics::NewProp_StageType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FSnakeDungeonLayout_Statics::NewProp_StageType = { "StageType", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeDungeonLayout, StageType), Z_Construct_UEnum_EternalDescent_EStageType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StageType_MetaData), NewProp_StageType_MetaData) }; // 1048845958
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSnakeDungeonLayout_Statics::NewProp_Rooms_ValueProp = { "Rooms", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FSnakeRoom, METADATA_PARAMS(0, nullptr) }; // 3798690907
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSnakeDungeonLayout_Statics::NewProp_Rooms_Key_KeyProp = { "Rooms_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UScriptStruct_FSnakeDungeonLayout_Statics::NewProp_Rooms = { "Rooms", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeDungeonLayout, Rooms), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rooms_MetaData), NewProp_Rooms_MetaData) }; // 3798690907
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSnakeDungeonLayout_Statics::NewProp_Hallways_Inner = { "Hallways", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FHallwayConnection, METADATA_PARAMS(0, nullptr) }; // 3960234035
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FSnakeDungeonLayout_Statics::NewProp_Hallways = { "Hallways", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeDungeonLayout, Hallways), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Hallways_MetaData), NewProp_Hallways_MetaData) }; // 3960234035
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSnakeDungeonLayout_Statics::NewProp_MainPathRoomOrder_Inner = { "MainPathRoomOrder", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FSnakeDungeonLayout_Statics::NewProp_MainPathRoomOrder = { "MainPathRoomOrder", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeDungeonLayout, MainPathRoomOrder), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MainPathRoomOrder_MetaData), NewProp_MainPathRoomOrder_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSnakeDungeonLayout_Statics::NewProp_FillerCubes_ValueProp = { "FillerCubes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FDungeonCube, METADATA_PARAMS(0, nullptr) }; // 2403584286
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSnakeDungeonLayout_Statics::NewProp_FillerCubes_Key_KeyProp = { "FillerCubes_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UScriptStruct_FSnakeDungeonLayout_Statics::NewProp_FillerCubes = { "FillerCubes", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeDungeonLayout, FillerCubes), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FillerCubes_MetaData), NewProp_FillerCubes_MetaData) }; // 2403584286
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSnakeDungeonLayout_Statics::NewProp_GridBounds = { "GridBounds", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeDungeonLayout, GridBounds), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GridBounds_MetaData), NewProp_GridBounds_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSnakeDungeonLayout_Statics::NewProp_StartRoomID = { "StartRoomID", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeDungeonLayout, StartRoomID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StartRoomID_MetaData), NewProp_StartRoomID_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSnakeDungeonLayout_Statics::NewProp_EndRoomID = { "EndRoomID", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeDungeonLayout, EndRoomID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EndRoomID_MetaData), NewProp_EndRoomID_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSnakeDungeonLayout_Statics::NewProp_EliteRoomID = { "EliteRoomID", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeDungeonLayout, EliteRoomID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EliteRoomID_MetaData), NewProp_EliteRoomID_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSnakeDungeonLayout_Statics::NewProp_BossRoomID = { "BossRoomID", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeDungeonLayout, BossRoomID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BossRoomID_MetaData), NewProp_BossRoomID_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSnakeDungeonLayout_Statics::NewProp_GenerationTime = { "GenerationTime", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeDungeonLayout, GenerationTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GenerationTime_MetaData), NewProp_GenerationTime_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSnakeDungeonLayout_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeDungeonLayout_Statics::NewProp_StageNumber,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeDungeonLayout_Statics::NewProp_StageType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeDungeonLayout_Statics::NewProp_StageType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeDungeonLayout_Statics::NewProp_Rooms_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeDungeonLayout_Statics::NewProp_Rooms_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeDungeonLayout_Statics::NewProp_Rooms,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeDungeonLayout_Statics::NewProp_Hallways_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeDungeonLayout_Statics::NewProp_Hallways,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeDungeonLayout_Statics::NewProp_MainPathRoomOrder_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeDungeonLayout_Statics::NewProp_MainPathRoomOrder,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeDungeonLayout_Statics::NewProp_FillerCubes_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeDungeonLayout_Statics::NewProp_FillerCubes_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeDungeonLayout_Statics::NewProp_FillerCubes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeDungeonLayout_Statics::NewProp_GridBounds,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeDungeonLayout_Statics::NewProp_StartRoomID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeDungeonLayout_Statics::NewProp_EndRoomID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeDungeonLayout_Statics::NewProp_EliteRoomID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeDungeonLayout_Statics::NewProp_BossRoomID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeDungeonLayout_Statics::NewProp_GenerationTime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSnakeDungeonLayout_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSnakeDungeonLayout_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_EternalDescent,
	nullptr,
	&NewStructOps,
	"SnakeDungeonLayout",
	Z_Construct_UScriptStruct_FSnakeDungeonLayout_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSnakeDungeonLayout_Statics::PropPointers),
	sizeof(FSnakeDungeonLayout),
	alignof(FSnakeDungeonLayout),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSnakeDungeonLayout_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSnakeDungeonLayout_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FSnakeDungeonLayout()
{
	if (!Z_Registration_Info_UScriptStruct_SnakeDungeonLayout.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SnakeDungeonLayout.InnerSingleton, Z_Construct_UScriptStruct_FSnakeDungeonLayout_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_SnakeDungeonLayout.InnerSingleton;
}
// End ScriptStruct FSnakeDungeonLayout

// Begin Class ASnakeDungeonGenerator Function GenerateSnakeDungeon
struct Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateSnakeDungeon_Statics
{
	struct SnakeDungeonGenerator_eventGenerateSnakeDungeon_Parms
	{
		int32 StageNumber;
		FSnakeDungeonLayout ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Snake Dungeon" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Main generation function\n" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Main generation function" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_StageNumber;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateSnakeDungeon_Statics::NewProp_StageNumber = { "StageNumber", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SnakeDungeonGenerator_eventGenerateSnakeDungeon_Parms, StageNumber), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateSnakeDungeon_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SnakeDungeonGenerator_eventGenerateSnakeDungeon_Parms, ReturnValue), Z_Construct_UScriptStruct_FSnakeDungeonLayout, METADATA_PARAMS(0, nullptr) }; // 1605971985
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateSnakeDungeon_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateSnakeDungeon_Statics::NewProp_StageNumber,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateSnakeDungeon_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateSnakeDungeon_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateSnakeDungeon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASnakeDungeonGenerator, nullptr, "GenerateSnakeDungeon", nullptr, nullptr, Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateSnakeDungeon_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateSnakeDungeon_Statics::PropPointers), sizeof(Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateSnakeDungeon_Statics::SnakeDungeonGenerator_eventGenerateSnakeDungeon_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateSnakeDungeon_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateSnakeDungeon_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateSnakeDungeon_Statics::SnakeDungeonGenerator_eventGenerateSnakeDungeon_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateSnakeDungeon()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateSnakeDungeon_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASnakeDungeonGenerator::execGenerateSnakeDungeon)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_StageNumber);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FSnakeDungeonLayout*)Z_Param__Result=P_THIS->GenerateSnakeDungeon(Z_Param_StageNumber);
	P_NATIVE_END;
}
// End Class ASnakeDungeonGenerator Function GenerateSnakeDungeon

// Begin Class ASnakeDungeonGenerator Function SetDifficulty
struct Z_Construct_UFunction_ASnakeDungeonGenerator_SetDifficulty_Statics
{
	struct SnakeDungeonGenerator_eventSetDifficulty_Parms
	{
		float Difficulty;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Snake Dungeon" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Configuration\n" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Configuration" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Difficulty;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASnakeDungeonGenerator_SetDifficulty_Statics::NewProp_Difficulty = { "Difficulty", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SnakeDungeonGenerator_eventSetDifficulty_Parms, Difficulty), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASnakeDungeonGenerator_SetDifficulty_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASnakeDungeonGenerator_SetDifficulty_Statics::NewProp_Difficulty,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_SetDifficulty_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASnakeDungeonGenerator_SetDifficulty_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASnakeDungeonGenerator, nullptr, "SetDifficulty", nullptr, nullptr, Z_Construct_UFunction_ASnakeDungeonGenerator_SetDifficulty_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_SetDifficulty_Statics::PropPointers), sizeof(Z_Construct_UFunction_ASnakeDungeonGenerator_SetDifficulty_Statics::SnakeDungeonGenerator_eventSetDifficulty_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_SetDifficulty_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASnakeDungeonGenerator_SetDifficulty_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ASnakeDungeonGenerator_SetDifficulty_Statics::SnakeDungeonGenerator_eventSetDifficulty_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ASnakeDungeonGenerator_SetDifficulty()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASnakeDungeonGenerator_SetDifficulty_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASnakeDungeonGenerator::execSetDifficulty)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Difficulty);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetDifficulty(Z_Param_Difficulty);
	P_NATIVE_END;
}
// End Class ASnakeDungeonGenerator Function SetDifficulty

// Begin Class ASnakeDungeonGenerator
void ASnakeDungeonGenerator::StaticRegisterNativesASnakeDungeonGenerator()
{
	UClass* Class = ASnakeDungeonGenerator::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GenerateSnakeDungeon", &ASnakeDungeonGenerator::execGenerateSnakeDungeon },
		{ "SetDifficulty", &ASnakeDungeonGenerator::execSetDifficulty },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASnakeDungeonGenerator);
UClass* Z_Construct_UClass_ASnakeDungeonGenerator_NoRegister()
{
	return ASnakeDungeonGenerator::StaticClass();
}
struct Z_Construct_UClass_ASnakeDungeonGenerator_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "SnakeDungeonGenerator.h" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinRoomsPerStage_MetaData[] = {
		{ "Category", "Generation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Generation parameters\n" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Generation parameters" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxRoomsPerStage_MetaData[] = {
		{ "Category", "Generation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// MINIMUM 15 rooms\n" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "MINIMUM 15 rooms" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinRoomSize_MetaData[] = {
		{ "Category", "Generation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// MAXIMUM 25 rooms\n" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "MAXIMUM 25 rooms" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxRoomSize_MetaData[] = {
		{ "Category", "Generation" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinHallwayLength_MetaData[] = {
		{ "Category", "Generation" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxHallwayLength_MetaData[] = {
		{ "Category", "Generation" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BranchingChance_MetaData[] = {
		{ "Category", "Generation" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DifficultyMultiplier_MetaData[] = {
		{ "Category", "Generation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// 30% chance for branching paths\n" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "30% chance for branching paths" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CubeSize_MetaData[] = {
		{ "Category", "Generation" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_MinRoomsPerStage;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxRoomsPerStage;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MinRoomSize;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxRoomSize;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MinHallwayLength;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxHallwayLength;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BranchingChance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DifficultyMultiplier;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CubeSize;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateSnakeDungeon, "GenerateSnakeDungeon" }, // 2361129809
		{ &Z_Construct_UFunction_ASnakeDungeonGenerator_SetDifficulty, "SetDifficulty" }, // 999539012
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASnakeDungeonGenerator>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ASnakeDungeonGenerator_Statics::NewProp_MinRoomsPerStage = { "MinRoomsPerStage", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakeDungeonGenerator, MinRoomsPerStage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinRoomsPerStage_MetaData), NewProp_MinRoomsPerStage_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ASnakeDungeonGenerator_Statics::NewProp_MaxRoomsPerStage = { "MaxRoomsPerStage", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakeDungeonGenerator, MaxRoomsPerStage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxRoomsPerStage_MetaData), NewProp_MaxRoomsPerStage_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ASnakeDungeonGenerator_Statics::NewProp_MinRoomSize = { "MinRoomSize", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakeDungeonGenerator, MinRoomSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinRoomSize_MetaData), NewProp_MinRoomSize_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ASnakeDungeonGenerator_Statics::NewProp_MaxRoomSize = { "MaxRoomSize", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakeDungeonGenerator, MaxRoomSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxRoomSize_MetaData), NewProp_MaxRoomSize_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ASnakeDungeonGenerator_Statics::NewProp_MinHallwayLength = { "MinHallwayLength", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakeDungeonGenerator, MinHallwayLength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinHallwayLength_MetaData), NewProp_MinHallwayLength_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ASnakeDungeonGenerator_Statics::NewProp_MaxHallwayLength = { "MaxHallwayLength", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakeDungeonGenerator, MaxHallwayLength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxHallwayLength_MetaData), NewProp_MaxHallwayLength_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASnakeDungeonGenerator_Statics::NewProp_BranchingChance = { "BranchingChance", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakeDungeonGenerator, BranchingChance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BranchingChance_MetaData), NewProp_BranchingChance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASnakeDungeonGenerator_Statics::NewProp_DifficultyMultiplier = { "DifficultyMultiplier", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakeDungeonGenerator, DifficultyMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DifficultyMultiplier_MetaData), NewProp_DifficultyMultiplier_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ASnakeDungeonGenerator_Statics::NewProp_CubeSize = { "CubeSize", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakeDungeonGenerator, CubeSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CubeSize_MetaData), NewProp_CubeSize_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASnakeDungeonGenerator_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakeDungeonGenerator_Statics::NewProp_MinRoomsPerStage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakeDungeonGenerator_Statics::NewProp_MaxRoomsPerStage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakeDungeonGenerator_Statics::NewProp_MinRoomSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakeDungeonGenerator_Statics::NewProp_MaxRoomSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakeDungeonGenerator_Statics::NewProp_MinHallwayLength,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakeDungeonGenerator_Statics::NewProp_MaxHallwayLength,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakeDungeonGenerator_Statics::NewProp_BranchingChance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakeDungeonGenerator_Statics::NewProp_DifficultyMultiplier,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakeDungeonGenerator_Statics::NewProp_CubeSize,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASnakeDungeonGenerator_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ASnakeDungeonGenerator_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_EternalDescent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASnakeDungeonGenerator_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ASnakeDungeonGenerator_Statics::ClassParams = {
	&ASnakeDungeonGenerator::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ASnakeDungeonGenerator_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ASnakeDungeonGenerator_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASnakeDungeonGenerator_Statics::Class_MetaDataParams), Z_Construct_UClass_ASnakeDungeonGenerator_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ASnakeDungeonGenerator()
{
	if (!Z_Registration_Info_UClass_ASnakeDungeonGenerator.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASnakeDungeonGenerator.OuterSingleton, Z_Construct_UClass_ASnakeDungeonGenerator_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ASnakeDungeonGenerator.OuterSingleton;
}
template<> ETERNALDESCENT_API UClass* StaticClass<ASnakeDungeonGenerator>()
{
	return ASnakeDungeonGenerator::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ASnakeDungeonGenerator);
ASnakeDungeonGenerator::~ASnakeDungeonGenerator() {}
// End Class ASnakeDungeonGenerator

// Begin Registration
struct Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonGenerator_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EStageType_StaticEnum, TEXT("EStageType"), &Z_Registration_Info_UEnum_EStageType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1048845958U) },
		{ EContentMarkerType_StaticEnum, TEXT("EContentMarkerType"), &Z_Registration_Info_UEnum_EContentMarkerType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 923544256U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FContentMarker::StaticStruct, Z_Construct_UScriptStruct_FContentMarker_Statics::NewStructOps, TEXT("ContentMarker"), &Z_Registration_Info_UScriptStruct_ContentMarker, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FContentMarker), 4001349238U) },
		{ FSnakeRoom::StaticStruct, Z_Construct_UScriptStruct_FSnakeRoom_Statics::NewStructOps, TEXT("SnakeRoom"), &Z_Registration_Info_UScriptStruct_SnakeRoom, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSnakeRoom), 3798690907U) },
		{ FHallwayConnection::StaticStruct, Z_Construct_UScriptStruct_FHallwayConnection_Statics::NewStructOps, TEXT("HallwayConnection"), &Z_Registration_Info_UScriptStruct_HallwayConnection, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FHallwayConnection), 3960234035U) },
		{ FSnakeDungeonLayout::StaticStruct, Z_Construct_UScriptStruct_FSnakeDungeonLayout_Statics::NewStructOps, TEXT("SnakeDungeonLayout"), &Z_Registration_Info_UScriptStruct_SnakeDungeonLayout, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSnakeDungeonLayout), 1605971985U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ASnakeDungeonGenerator, ASnakeDungeonGenerator::StaticClass, TEXT("ASnakeDungeonGenerator"), &Z_Registration_Info_UClass_ASnakeDungeonGenerator, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASnakeDungeonGenerator), 1428054597U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonGenerator_h_14806846(TEXT("/Script/EternalDescent"),
	Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonGenerator_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonGenerator_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonGenerator_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonGenerator_h_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonGenerator_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonGenerator_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
