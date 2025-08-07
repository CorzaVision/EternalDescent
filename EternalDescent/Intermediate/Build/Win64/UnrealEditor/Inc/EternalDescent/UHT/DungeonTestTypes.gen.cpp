// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EternalDescent/Public/Tests/DungeonTestTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDungeonTestTypes() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntVector();
ETERNALDESCENT_API UEnum* Z_Construct_UEnum_EternalDescent_EDungeonZone();
ETERNALDESCENT_API UEnum* Z_Construct_UEnum_EternalDescent_EEntityPersonality();
ETERNALDESCENT_API UEnum* Z_Construct_UEnum_EternalDescent_ERoomType();
ETERNALDESCENT_API UScriptStruct* Z_Construct_UScriptStruct_FDungeonLayout();
ETERNALDESCENT_API UScriptStruct* Z_Construct_UScriptStruct_FEntityProfile();
ETERNALDESCENT_API UScriptStruct* Z_Construct_UScriptStruct_FRoomData();
UPackage* Z_Construct_UPackage__Script_EternalDescent();
// End Cross Module References

// Begin Enum EDungeonZone
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EDungeonZone;
static UEnum* EDungeonZone_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EDungeonZone.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EDungeonZone.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_EternalDescent_EDungeonZone, (UObject*)Z_Construct_UPackage__Script_EternalDescent(), TEXT("EDungeonZone"));
	}
	return Z_Registration_Info_UEnum_EDungeonZone.OuterSingleton;
}
template<> ETERNALDESCENT_API UEnum* StaticEnum<EDungeonZone>()
{
	return EDungeonZone_StaticEnum();
}
struct Z_Construct_UEnum_EternalDescent_EDungeonZone_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlightedForest.DisplayName", "Blighted Forest" },
		{ "BlightedForest.Name", "EDungeonZone::BlightedForest" },
		{ "BlueprintType", "true" },
		{ "FrozenFortress.DisplayName", "Frozen Fortress" },
		{ "FrozenFortress.Name", "EDungeonZone::FrozenFortress" },
		{ "ModuleRelativePath", "Public/Tests/DungeonTestTypes.h" },
		{ "None.DisplayName", "None" },
		{ "None.Name", "EDungeonZone::None" },
		{ "SunkenCrypt.DisplayName", "Sunken Crypt" },
		{ "SunkenCrypt.Name", "EDungeonZone::SunkenCrypt" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EDungeonZone::None", (int64)EDungeonZone::None },
		{ "EDungeonZone::SunkenCrypt", (int64)EDungeonZone::SunkenCrypt },
		{ "EDungeonZone::BlightedForest", (int64)EDungeonZone::BlightedForest },
		{ "EDungeonZone::FrozenFortress", (int64)EDungeonZone::FrozenFortress },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_EternalDescent_EDungeonZone_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_EternalDescent,
	nullptr,
	"EDungeonZone",
	"EDungeonZone",
	Z_Construct_UEnum_EternalDescent_EDungeonZone_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_EternalDescent_EDungeonZone_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_EternalDescent_EDungeonZone_Statics::Enum_MetaDataParams), Z_Construct_UEnum_EternalDescent_EDungeonZone_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_EternalDescent_EDungeonZone()
{
	if (!Z_Registration_Info_UEnum_EDungeonZone.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EDungeonZone.InnerSingleton, Z_Construct_UEnum_EternalDescent_EDungeonZone_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EDungeonZone.InnerSingleton;
}
// End Enum EDungeonZone

// Begin Enum ERoomType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ERoomType;
static UEnum* ERoomType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ERoomType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ERoomType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_EternalDescent_ERoomType, (UObject*)Z_Construct_UPackage__Script_EternalDescent(), TEXT("ERoomType"));
	}
	return Z_Registration_Info_UEnum_ERoomType.OuterSingleton;
}
template<> ETERNALDESCENT_API UEnum* StaticEnum<ERoomType>()
{
	return ERoomType_StaticEnum();
}
struct Z_Construct_UEnum_EternalDescent_ERoomType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Boss.DisplayName", "Boss" },
		{ "Boss.Name", "ERoomType::Boss" },
		{ "Combat.Comment", "// Basic combat room\n" },
		{ "Combat.DisplayName", "Combat" },
		{ "Combat.Name", "ERoomType::Combat" },
		{ "Combat.ToolTip", "Basic combat room" },
		{ "Elite.DisplayName", "Elite" },
		{ "Elite.Name", "ERoomType::Elite" },
		{ "Empty.DisplayName", "Empty" },
		{ "Empty.Name", "ERoomType::Empty" },
		{ "Exit.Comment", "// Explicitly marked start\n" },
		{ "Exit.DisplayName", "Exit Room" },
		{ "Exit.Name", "ERoomType::Exit" },
		{ "Exit.ToolTip", "Explicitly marked start" },
		{ "Extraction.Comment", "// Explicitly marked exit (extraction)\n" },
		{ "Extraction.DisplayName", "Extraction" },
		{ "Extraction.Name", "ERoomType::Extraction" },
		{ "Extraction.ToolTip", "Explicitly marked exit (extraction)" },
		{ "Hallway.Comment", "// Legacy support\n" },
		{ "Hallway.DisplayName", "Hallway" },
		{ "Hallway.Name", "ERoomType::Hallway" },
		{ "Hallway.ToolTip", "Legacy support" },
		{ "ModuleRelativePath", "Public/Tests/DungeonTestTypes.h" },
		{ "Puzzle.Comment", "// Merchant room\n" },
		{ "Puzzle.DisplayName", "Puzzle" },
		{ "Puzzle.Name", "ERoomType::Puzzle" },
		{ "Puzzle.ToolTip", "Merchant room" },
		{ "Rest.DisplayName", "Rest" },
		{ "Rest.Name", "ERoomType::Rest" },
		{ "Shop.DisplayName", "Shop" },
		{ "Shop.Name", "ERoomType::Shop" },
		{ "Standard.DisplayName", "Standard" },
		{ "Standard.Name", "ERoomType::Standard" },
		{ "Start.DisplayName", "Start Room" },
		{ "Start.Name", "ERoomType::Start" },
		{ "Treasure.Comment", "// Harder combat room\n" },
		{ "Treasure.DisplayName", "Treasure" },
		{ "Treasure.Name", "ERoomType::Treasure" },
		{ "Treasure.ToolTip", "Harder combat room" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ERoomType::Empty", (int64)ERoomType::Empty },
		{ "ERoomType::Standard", (int64)ERoomType::Standard },
		{ "ERoomType::Combat", (int64)ERoomType::Combat },
		{ "ERoomType::Elite", (int64)ERoomType::Elite },
		{ "ERoomType::Treasure", (int64)ERoomType::Treasure },
		{ "ERoomType::Shop", (int64)ERoomType::Shop },
		{ "ERoomType::Puzzle", (int64)ERoomType::Puzzle },
		{ "ERoomType::Rest", (int64)ERoomType::Rest },
		{ "ERoomType::Boss", (int64)ERoomType::Boss },
		{ "ERoomType::Start", (int64)ERoomType::Start },
		{ "ERoomType::Exit", (int64)ERoomType::Exit },
		{ "ERoomType::Extraction", (int64)ERoomType::Extraction },
		{ "ERoomType::Hallway", (int64)ERoomType::Hallway },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_EternalDescent_ERoomType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_EternalDescent,
	nullptr,
	"ERoomType",
	"ERoomType",
	Z_Construct_UEnum_EternalDescent_ERoomType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_EternalDescent_ERoomType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_EternalDescent_ERoomType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_EternalDescent_ERoomType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_EternalDescent_ERoomType()
{
	if (!Z_Registration_Info_UEnum_ERoomType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ERoomType.InnerSingleton, Z_Construct_UEnum_EternalDescent_ERoomType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ERoomType.InnerSingleton;
}
// End Enum ERoomType

// Begin Enum EEntityPersonality
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EEntityPersonality;
static UEnum* EEntityPersonality_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EEntityPersonality.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EEntityPersonality.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_EternalDescent_EEntityPersonality, (UObject*)Z_Construct_UPackage__Script_EternalDescent(), TEXT("EEntityPersonality"));
	}
	return Z_Registration_Info_UEnum_EEntityPersonality.OuterSingleton;
}
template<> ETERNALDESCENT_API UEnum* StaticEnum<EEntityPersonality>()
{
	return EEntityPersonality_StaticEnum();
}
struct Z_Construct_UEnum_EternalDescent_EEntityPersonality_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Architect.DisplayName", "The Architect" },
		{ "Architect.Name", "EEntityPersonality::Architect" },
		{ "BlueprintType", "true" },
		{ "Challenger.DisplayName", "The Challenger" },
		{ "Challenger.Name", "EEntityPersonality::Challenger" },
		{ "Counter.DisplayName", "The Counter" },
		{ "Counter.Name", "EEntityPersonality::Counter" },
		{ "Historian.DisplayName", "The Historian" },
		{ "Historian.Name", "EEntityPersonality::Historian" },
		{ "ModuleRelativePath", "Public/Tests/DungeonTestTypes.h" },
		{ "Observer.DisplayName", "The Observer" },
		{ "Observer.Name", "EEntityPersonality::Observer" },
		{ "Prophet.DisplayName", "The Prophet" },
		{ "Prophet.Name", "EEntityPersonality::Prophet" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EEntityPersonality::Observer", (int64)EEntityPersonality::Observer },
		{ "EEntityPersonality::Challenger", (int64)EEntityPersonality::Challenger },
		{ "EEntityPersonality::Counter", (int64)EEntityPersonality::Counter },
		{ "EEntityPersonality::Architect", (int64)EEntityPersonality::Architect },
		{ "EEntityPersonality::Historian", (int64)EEntityPersonality::Historian },
		{ "EEntityPersonality::Prophet", (int64)EEntityPersonality::Prophet },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_EternalDescent_EEntityPersonality_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_EternalDescent,
	nullptr,
	"EEntityPersonality",
	"EEntityPersonality",
	Z_Construct_UEnum_EternalDescent_EEntityPersonality_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_EternalDescent_EEntityPersonality_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_EternalDescent_EEntityPersonality_Statics::Enum_MetaDataParams), Z_Construct_UEnum_EternalDescent_EEntityPersonality_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_EternalDescent_EEntityPersonality()
{
	if (!Z_Registration_Info_UEnum_EEntityPersonality.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EEntityPersonality.InnerSingleton, Z_Construct_UEnum_EternalDescent_EEntityPersonality_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EEntityPersonality.InnerSingleton;
}
// End Enum EEntityPersonality

// Begin ScriptStruct FRoomData
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_RoomData;
class UScriptStruct* FRoomData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_RoomData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_RoomData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FRoomData, (UObject*)Z_Construct_UPackage__Script_EternalDescent(), TEXT("RoomData"));
	}
	return Z_Registration_Info_UScriptStruct_RoomData.OuterSingleton;
}
template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<FRoomData>()
{
	return FRoomData::StaticStruct();
}
struct Z_Construct_UScriptStruct_FRoomData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Tests/DungeonTestTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GridPosition_MetaData[] = {
		{ "Category", "RoomData" },
		{ "ModuleRelativePath", "Public/Tests/DungeonTestTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoomType_MetaData[] = {
		{ "Category", "RoomData" },
		{ "ModuleRelativePath", "Public/Tests/DungeonTestTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ZoneType_MetaData[] = {
		{ "Category", "RoomData" },
		{ "ModuleRelativePath", "Public/Tests/DungeonTestTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Connections_MetaData[] = {
		{ "Category", "RoomData" },
		{ "ModuleRelativePath", "Public/Tests/DungeonTestTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DifficultyModifier_MetaData[] = {
		{ "Category", "RoomData" },
		{ "ModuleRelativePath", "Public/Tests/DungeonTestTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EntityInfluence_MetaData[] = {
		{ "Category", "RoomData" },
		{ "ModuleRelativePath", "Public/Tests/DungeonTestTypes.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_GridPosition;
	static const UECodeGen_Private::FBytePropertyParams NewProp_RoomType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_RoomType;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ZoneType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ZoneType;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Connections_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Connections;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DifficultyModifier;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_EntityInfluence;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FRoomData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FRoomData_Statics::NewProp_GridPosition = { "GridPosition", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRoomData, GridPosition), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GridPosition_MetaData), NewProp_GridPosition_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FRoomData_Statics::NewProp_RoomType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FRoomData_Statics::NewProp_RoomType = { "RoomType", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRoomData, RoomType), Z_Construct_UEnum_EternalDescent_ERoomType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoomType_MetaData), NewProp_RoomType_MetaData) }; // 1291513837
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FRoomData_Statics::NewProp_ZoneType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FRoomData_Statics::NewProp_ZoneType = { "ZoneType", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRoomData, ZoneType), Z_Construct_UEnum_EternalDescent_EDungeonZone, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ZoneType_MetaData), NewProp_ZoneType_MetaData) }; // 1899664273
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FRoomData_Statics::NewProp_Connections_Inner = { "Connections", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FRoomData_Statics::NewProp_Connections = { "Connections", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRoomData, Connections), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Connections_MetaData), NewProp_Connections_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FRoomData_Statics::NewProp_DifficultyModifier = { "DifficultyModifier", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRoomData, DifficultyModifier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DifficultyModifier_MetaData), NewProp_DifficultyModifier_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FRoomData_Statics::NewProp_EntityInfluence = { "EntityInfluence", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRoomData, EntityInfluence), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EntityInfluence_MetaData), NewProp_EntityInfluence_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FRoomData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRoomData_Statics::NewProp_GridPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRoomData_Statics::NewProp_RoomType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRoomData_Statics::NewProp_RoomType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRoomData_Statics::NewProp_ZoneType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRoomData_Statics::NewProp_ZoneType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRoomData_Statics::NewProp_Connections_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRoomData_Statics::NewProp_Connections,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRoomData_Statics::NewProp_DifficultyModifier,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRoomData_Statics::NewProp_EntityInfluence,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRoomData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FRoomData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_EternalDescent,
	nullptr,
	&NewStructOps,
	"RoomData",
	Z_Construct_UScriptStruct_FRoomData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRoomData_Statics::PropPointers),
	sizeof(FRoomData),
	alignof(FRoomData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRoomData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FRoomData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FRoomData()
{
	if (!Z_Registration_Info_UScriptStruct_RoomData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_RoomData.InnerSingleton, Z_Construct_UScriptStruct_FRoomData_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_RoomData.InnerSingleton;
}
// End ScriptStruct FRoomData

// Begin ScriptStruct FDungeonLayout
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_DungeonLayout;
class UScriptStruct* FDungeonLayout::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_DungeonLayout.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_DungeonLayout.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDungeonLayout, (UObject*)Z_Construct_UPackage__Script_EternalDescent(), TEXT("DungeonLayout"));
	}
	return Z_Registration_Info_UScriptStruct_DungeonLayout.OuterSingleton;
}
template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<FDungeonLayout>()
{
	return FDungeonLayout::StaticStruct();
}
struct Z_Construct_UScriptStruct_FDungeonLayout_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Tests/DungeonTestTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FloorNumber_MetaData[] = {
		{ "Category", "DungeonLayout" },
		{ "ModuleRelativePath", "Public/Tests/DungeonTestTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rooms_MetaData[] = {
		{ "Category", "DungeonLayout" },
		{ "ModuleRelativePath", "Public/Tests/DungeonTestTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnRoom_MetaData[] = {
		{ "Category", "DungeonLayout" },
		{ "ModuleRelativePath", "Public/Tests/DungeonTestTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExtractionPoints_MetaData[] = {
		{ "Category", "DungeonLayout" },
		{ "ModuleRelativePath", "Public/Tests/DungeonTestTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentZone_MetaData[] = {
		{ "Category", "DungeonLayout" },
		{ "ModuleRelativePath", "Public/Tests/DungeonTestTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GenerationTime_MetaData[] = {
		{ "Category", "DungeonLayout" },
		{ "ModuleRelativePath", "Public/Tests/DungeonTestTypes.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_FloorNumber;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Rooms_ValueProp;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Rooms_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_Rooms;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpawnRoom;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ExtractionPoints_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ExtractionPoints;
	static const UECodeGen_Private::FBytePropertyParams NewProp_CurrentZone_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_CurrentZone;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GenerationTime;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDungeonLayout>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDungeonLayout_Statics::NewProp_FloorNumber = { "FloorNumber", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDungeonLayout, FloorNumber), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FloorNumber_MetaData), NewProp_FloorNumber_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FDungeonLayout_Statics::NewProp_Rooms_ValueProp = { "Rooms", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FRoomData, METADATA_PARAMS(0, nullptr) }; // 987753016
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FDungeonLayout_Statics::NewProp_Rooms_Key_KeyProp = { "Rooms_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UScriptStruct_FDungeonLayout_Statics::NewProp_Rooms = { "Rooms", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDungeonLayout, Rooms), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rooms_MetaData), NewProp_Rooms_MetaData) }; // 987753016
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FDungeonLayout_Statics::NewProp_SpawnRoom = { "SpawnRoom", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDungeonLayout, SpawnRoom), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnRoom_MetaData), NewProp_SpawnRoom_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FDungeonLayout_Statics::NewProp_ExtractionPoints_Inner = { "ExtractionPoints", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FDungeonLayout_Statics::NewProp_ExtractionPoints = { "ExtractionPoints", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDungeonLayout, ExtractionPoints), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExtractionPoints_MetaData), NewProp_ExtractionPoints_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FDungeonLayout_Statics::NewProp_CurrentZone_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FDungeonLayout_Statics::NewProp_CurrentZone = { "CurrentZone", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDungeonLayout, CurrentZone), Z_Construct_UEnum_EternalDescent_EDungeonZone, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentZone_MetaData), NewProp_CurrentZone_MetaData) }; // 1899664273
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FDungeonLayout_Statics::NewProp_GenerationTime = { "GenerationTime", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDungeonLayout, GenerationTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GenerationTime_MetaData), NewProp_GenerationTime_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDungeonLayout_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDungeonLayout_Statics::NewProp_FloorNumber,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDungeonLayout_Statics::NewProp_Rooms_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDungeonLayout_Statics::NewProp_Rooms_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDungeonLayout_Statics::NewProp_Rooms,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDungeonLayout_Statics::NewProp_SpawnRoom,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDungeonLayout_Statics::NewProp_ExtractionPoints_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDungeonLayout_Statics::NewProp_ExtractionPoints,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDungeonLayout_Statics::NewProp_CurrentZone_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDungeonLayout_Statics::NewProp_CurrentZone,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDungeonLayout_Statics::NewProp_GenerationTime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDungeonLayout_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDungeonLayout_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_EternalDescent,
	nullptr,
	&NewStructOps,
	"DungeonLayout",
	Z_Construct_UScriptStruct_FDungeonLayout_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDungeonLayout_Statics::PropPointers),
	sizeof(FDungeonLayout),
	alignof(FDungeonLayout),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDungeonLayout_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDungeonLayout_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FDungeonLayout()
{
	if (!Z_Registration_Info_UScriptStruct_DungeonLayout.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_DungeonLayout.InnerSingleton, Z_Construct_UScriptStruct_FDungeonLayout_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_DungeonLayout.InnerSingleton;
}
// End ScriptStruct FDungeonLayout

// Begin ScriptStruct FEntityProfile
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_EntityProfile;
class UScriptStruct* FEntityProfile::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_EntityProfile.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_EntityProfile.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FEntityProfile, (UObject*)Z_Construct_UPackage__Script_EternalDescent(), TEXT("EntityProfile"));
	}
	return Z_Registration_Info_UScriptStruct_EntityProfile.OuterSingleton;
}
template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<FEntityProfile>()
{
	return FEntityProfile::StaticStruct();
}
struct Z_Construct_UScriptStruct_FEntityProfile_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Tests/DungeonTestTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerPatterns_MetaData[] = {
		{ "Category", "EntityProfile" },
		{ "ModuleRelativePath", "Public/Tests/DungeonTestTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentMood_MetaData[] = {
		{ "Category", "EntityProfile" },
		{ "ModuleRelativePath", "Public/Tests/DungeonTestTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AdaptationLevel_MetaData[] = {
		{ "Category", "EntityProfile" },
		{ "ModuleRelativePath", "Public/Tests/DungeonTestTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RunCount_MetaData[] = {
		{ "Category", "EntityProfile" },
		{ "ModuleRelativePath", "Public/Tests/DungeonTestTypes.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlayerPatterns_ValueProp;
	static const UECodeGen_Private::FStrPropertyParams NewProp_PlayerPatterns_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_PlayerPatterns;
	static const UECodeGen_Private::FBytePropertyParams NewProp_CurrentMood_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_CurrentMood;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AdaptationLevel;
	static const UECodeGen_Private::FIntPropertyParams NewProp_RunCount;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FEntityProfile>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FEntityProfile_Statics::NewProp_PlayerPatterns_ValueProp = { "PlayerPatterns", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FEntityProfile_Statics::NewProp_PlayerPatterns_Key_KeyProp = { "PlayerPatterns_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UScriptStruct_FEntityProfile_Statics::NewProp_PlayerPatterns = { "PlayerPatterns", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEntityProfile, PlayerPatterns), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerPatterns_MetaData), NewProp_PlayerPatterns_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FEntityProfile_Statics::NewProp_CurrentMood_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FEntityProfile_Statics::NewProp_CurrentMood = { "CurrentMood", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEntityProfile, CurrentMood), Z_Construct_UEnum_EternalDescent_EEntityPersonality, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentMood_MetaData), NewProp_CurrentMood_MetaData) }; // 4264349834
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FEntityProfile_Statics::NewProp_AdaptationLevel = { "AdaptationLevel", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEntityProfile, AdaptationLevel), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AdaptationLevel_MetaData), NewProp_AdaptationLevel_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FEntityProfile_Statics::NewProp_RunCount = { "RunCount", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEntityProfile, RunCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RunCount_MetaData), NewProp_RunCount_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FEntityProfile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEntityProfile_Statics::NewProp_PlayerPatterns_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEntityProfile_Statics::NewProp_PlayerPatterns_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEntityProfile_Statics::NewProp_PlayerPatterns,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEntityProfile_Statics::NewProp_CurrentMood_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEntityProfile_Statics::NewProp_CurrentMood,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEntityProfile_Statics::NewProp_AdaptationLevel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEntityProfile_Statics::NewProp_RunCount,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEntityProfile_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FEntityProfile_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_EternalDescent,
	nullptr,
	&NewStructOps,
	"EntityProfile",
	Z_Construct_UScriptStruct_FEntityProfile_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEntityProfile_Statics::PropPointers),
	sizeof(FEntityProfile),
	alignof(FEntityProfile),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEntityProfile_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FEntityProfile_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FEntityProfile()
{
	if (!Z_Registration_Info_UScriptStruct_EntityProfile.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_EntityProfile.InnerSingleton, Z_Construct_UScriptStruct_FEntityProfile_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_EntityProfile.InnerSingleton;
}
// End ScriptStruct FEntityProfile

// Begin Registration
struct Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_Tests_DungeonTestTypes_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EDungeonZone_StaticEnum, TEXT("EDungeonZone"), &Z_Registration_Info_UEnum_EDungeonZone, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1899664273U) },
		{ ERoomType_StaticEnum, TEXT("ERoomType"), &Z_Registration_Info_UEnum_ERoomType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1291513837U) },
		{ EEntityPersonality_StaticEnum, TEXT("EEntityPersonality"), &Z_Registration_Info_UEnum_EEntityPersonality, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 4264349834U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FRoomData::StaticStruct, Z_Construct_UScriptStruct_FRoomData_Statics::NewStructOps, TEXT("RoomData"), &Z_Registration_Info_UScriptStruct_RoomData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FRoomData), 987753016U) },
		{ FDungeonLayout::StaticStruct, Z_Construct_UScriptStruct_FDungeonLayout_Statics::NewStructOps, TEXT("DungeonLayout"), &Z_Registration_Info_UScriptStruct_DungeonLayout, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDungeonLayout), 3903890264U) },
		{ FEntityProfile::StaticStruct, Z_Construct_UScriptStruct_FEntityProfile_Statics::NewStructOps, TEXT("EntityProfile"), &Z_Registration_Info_UScriptStruct_EntityProfile, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FEntityProfile), 2813654246U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_Tests_DungeonTestTypes_h_2612285083(TEXT("/Script/EternalDescent"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_Tests_DungeonTestTypes_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_Tests_DungeonTestTypes_h_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_Tests_DungeonTestTypes_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_Tests_DungeonTestTypes_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
