// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EternalDescent/Public/SnakeDungeonGenerator.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSnakeDungeonGenerator() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntVector();
ETERNALDESCENT_API UClass* Z_Construct_UClass_ADungeonVisualizer();
ETERNALDESCENT_API UClass* Z_Construct_UClass_ASnakeDungeonGenerator();
ETERNALDESCENT_API UClass* Z_Construct_UClass_ASnakeDungeonGenerator_NoRegister();
ETERNALDESCENT_API UEnum* Z_Construct_UEnum_EternalDescent_ERoomType();
ETERNALDESCENT_API UEnum* Z_Construct_UEnum_EternalDescent_ESnakeDirection();
ETERNALDESCENT_API UScriptStruct* Z_Construct_UScriptStruct_FSnakeGenerationSettings();
ETERNALDESCENT_API UScriptStruct* Z_Construct_UScriptStruct_FSnakeGenerationStats();
ETERNALDESCENT_API UScriptStruct* Z_Construct_UScriptStruct_FSnakePathNode();
UPackage* Z_Construct_UPackage__Script_EternalDescent();
// End Cross Module References

// Begin Enum ESnakeDirection
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ESnakeDirection;
static UEnum* ESnakeDirection_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ESnakeDirection.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ESnakeDirection.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_EternalDescent_ESnakeDirection, (UObject*)Z_Construct_UPackage__Script_EternalDescent(), TEXT("ESnakeDirection"));
	}
	return Z_Registration_Info_UEnum_ESnakeDirection.OuterSingleton;
}
template<> ETERNALDESCENT_API UEnum* StaticEnum<ESnakeDirection>()
{
	return ESnakeDirection_StaticEnum();
}
struct Z_Construct_UEnum_EternalDescent_ESnakeDirection_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "East.DisplayName", "East" },
		{ "East.Name", "ESnakeDirection::East" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
		{ "North.DisplayName", "North" },
		{ "North.Name", "ESnakeDirection::North" },
		{ "South.DisplayName", "South" },
		{ "South.Name", "ESnakeDirection::South" },
		{ "West.DisplayName", "West" },
		{ "West.Name", "ESnakeDirection::West" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ESnakeDirection::North", (int64)ESnakeDirection::North },
		{ "ESnakeDirection::South", (int64)ESnakeDirection::South },
		{ "ESnakeDirection::East", (int64)ESnakeDirection::East },
		{ "ESnakeDirection::West", (int64)ESnakeDirection::West },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_EternalDescent_ESnakeDirection_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_EternalDescent,
	nullptr,
	"ESnakeDirection",
	"ESnakeDirection",
	Z_Construct_UEnum_EternalDescent_ESnakeDirection_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_EternalDescent_ESnakeDirection_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_EternalDescent_ESnakeDirection_Statics::Enum_MetaDataParams), Z_Construct_UEnum_EternalDescent_ESnakeDirection_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_EternalDescent_ESnakeDirection()
{
	if (!Z_Registration_Info_UEnum_ESnakeDirection.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ESnakeDirection.InnerSingleton, Z_Construct_UEnum_EternalDescent_ESnakeDirection_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ESnakeDirection.InnerSingleton;
}
// End Enum ESnakeDirection

// Begin ScriptStruct FSnakePathNode
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SnakePathNode;
class UScriptStruct* FSnakePathNode::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SnakePathNode.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SnakePathNode.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSnakePathNode, (UObject*)Z_Construct_UPackage__Script_EternalDescent(), TEXT("SnakePathNode"));
	}
	return Z_Registration_Info_UScriptStruct_SnakePathNode.OuterSingleton;
}
template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<FSnakePathNode>()
{
	return FSnakePathNode::StaticStruct();
}
struct Z_Construct_UScriptStruct_FSnakePathNode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Position_MetaData[] = {
		{ "Category", "SnakePathNode" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoomType_MetaData[] = {
		{ "Category", "SnakePathNode" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ConnectedTo_MetaData[] = {
		{ "Category", "SnakePathNode" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsMainPath_MetaData[] = {
		{ "Category", "SnakePathNode" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Position;
	static const UECodeGen_Private::FBytePropertyParams NewProp_RoomType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_RoomType;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ConnectedTo_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ConnectedTo;
	static void NewProp_bIsMainPath_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsMainPath;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSnakePathNode>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSnakePathNode_Statics::NewProp_Position = { "Position", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakePathNode, Position), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Position_MetaData), NewProp_Position_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FSnakePathNode_Statics::NewProp_RoomType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FSnakePathNode_Statics::NewProp_RoomType = { "RoomType", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakePathNode, RoomType), Z_Construct_UEnum_EternalDescent_ERoomType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoomType_MetaData), NewProp_RoomType_MetaData) }; // 1291513837
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSnakePathNode_Statics::NewProp_ConnectedTo_Inner = { "ConnectedTo", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FSnakePathNode_Statics::NewProp_ConnectedTo = { "ConnectedTo", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakePathNode, ConnectedTo), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ConnectedTo_MetaData), NewProp_ConnectedTo_MetaData) };
void Z_Construct_UScriptStruct_FSnakePathNode_Statics::NewProp_bIsMainPath_SetBit(void* Obj)
{
	((FSnakePathNode*)Obj)->bIsMainPath = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSnakePathNode_Statics::NewProp_bIsMainPath = { "bIsMainPath", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FSnakePathNode), &Z_Construct_UScriptStruct_FSnakePathNode_Statics::NewProp_bIsMainPath_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsMainPath_MetaData), NewProp_bIsMainPath_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSnakePathNode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakePathNode_Statics::NewProp_Position,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakePathNode_Statics::NewProp_RoomType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakePathNode_Statics::NewProp_RoomType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakePathNode_Statics::NewProp_ConnectedTo_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakePathNode_Statics::NewProp_ConnectedTo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakePathNode_Statics::NewProp_bIsMainPath,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSnakePathNode_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSnakePathNode_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_EternalDescent,
	nullptr,
	&NewStructOps,
	"SnakePathNode",
	Z_Construct_UScriptStruct_FSnakePathNode_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSnakePathNode_Statics::PropPointers),
	sizeof(FSnakePathNode),
	alignof(FSnakePathNode),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSnakePathNode_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSnakePathNode_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FSnakePathNode()
{
	if (!Z_Registration_Info_UScriptStruct_SnakePathNode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SnakePathNode.InnerSingleton, Z_Construct_UScriptStruct_FSnakePathNode_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_SnakePathNode.InnerSingleton;
}
// End ScriptStruct FSnakePathNode

// Begin ScriptStruct FSnakeGenerationSettings
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SnakeGenerationSettings;
class UScriptStruct* FSnakeGenerationSettings::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SnakeGenerationSettings.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SnakeGenerationSettings.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSnakeGenerationSettings, (UObject*)Z_Construct_UPackage__Script_EternalDescent(), TEXT("SnakeGenerationSettings"));
	}
	return Z_Registration_Info_UScriptStruct_SnakeGenerationSettings.OuterSingleton;
}
template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<FSnakeGenerationSettings>()
{
	return FSnakeGenerationSettings::StaticStruct();
}
struct Z_Construct_UScriptStruct_FSnakeGenerationSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GridSizeX_MetaData[] = {
		{ "Category", "Snake Generation" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GridSizeY_MetaData[] = {
		{ "Category", "Snake Generation" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetRooms_MetaData[] = {
		{ "Category", "Snake Generation" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WindingFactor_MetaData[] = {
		{ "Category", "Snake Generation" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxBacktrackAttempts_MetaData[] = {
		{ "Category", "Snake Generation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// 0.0 = straight line, 1.0 = maximum winding\n" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "0.0 = straight line, 1.0 = maximum winding" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bGuaranteeConnection_MetaData[] = {
		{ "Category", "Snake Generation" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BranchProbability_MetaData[] = {
		{ "Category", "Snake Generation" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_GridSizeX;
	static const UECodeGen_Private::FIntPropertyParams NewProp_GridSizeY;
	static const UECodeGen_Private::FIntPropertyParams NewProp_TargetRooms;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WindingFactor;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxBacktrackAttempts;
	static void NewProp_bGuaranteeConnection_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bGuaranteeConnection;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BranchProbability;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSnakeGenerationSettings>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSnakeGenerationSettings_Statics::NewProp_GridSizeX = { "GridSizeX", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeGenerationSettings, GridSizeX), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GridSizeX_MetaData), NewProp_GridSizeX_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSnakeGenerationSettings_Statics::NewProp_GridSizeY = { "GridSizeY", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeGenerationSettings, GridSizeY), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GridSizeY_MetaData), NewProp_GridSizeY_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSnakeGenerationSettings_Statics::NewProp_TargetRooms = { "TargetRooms", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeGenerationSettings, TargetRooms), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetRooms_MetaData), NewProp_TargetRooms_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSnakeGenerationSettings_Statics::NewProp_WindingFactor = { "WindingFactor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeGenerationSettings, WindingFactor), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WindingFactor_MetaData), NewProp_WindingFactor_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSnakeGenerationSettings_Statics::NewProp_MaxBacktrackAttempts = { "MaxBacktrackAttempts", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeGenerationSettings, MaxBacktrackAttempts), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxBacktrackAttempts_MetaData), NewProp_MaxBacktrackAttempts_MetaData) };
void Z_Construct_UScriptStruct_FSnakeGenerationSettings_Statics::NewProp_bGuaranteeConnection_SetBit(void* Obj)
{
	((FSnakeGenerationSettings*)Obj)->bGuaranteeConnection = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSnakeGenerationSettings_Statics::NewProp_bGuaranteeConnection = { "bGuaranteeConnection", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FSnakeGenerationSettings), &Z_Construct_UScriptStruct_FSnakeGenerationSettings_Statics::NewProp_bGuaranteeConnection_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bGuaranteeConnection_MetaData), NewProp_bGuaranteeConnection_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSnakeGenerationSettings_Statics::NewProp_BranchProbability = { "BranchProbability", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeGenerationSettings, BranchProbability), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BranchProbability_MetaData), NewProp_BranchProbability_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSnakeGenerationSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeGenerationSettings_Statics::NewProp_GridSizeX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeGenerationSettings_Statics::NewProp_GridSizeY,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeGenerationSettings_Statics::NewProp_TargetRooms,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeGenerationSettings_Statics::NewProp_WindingFactor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeGenerationSettings_Statics::NewProp_MaxBacktrackAttempts,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeGenerationSettings_Statics::NewProp_bGuaranteeConnection,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeGenerationSettings_Statics::NewProp_BranchProbability,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSnakeGenerationSettings_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSnakeGenerationSettings_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_EternalDescent,
	nullptr,
	&NewStructOps,
	"SnakeGenerationSettings",
	Z_Construct_UScriptStruct_FSnakeGenerationSettings_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSnakeGenerationSettings_Statics::PropPointers),
	sizeof(FSnakeGenerationSettings),
	alignof(FSnakeGenerationSettings),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSnakeGenerationSettings_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSnakeGenerationSettings_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FSnakeGenerationSettings()
{
	if (!Z_Registration_Info_UScriptStruct_SnakeGenerationSettings.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SnakeGenerationSettings.InnerSingleton, Z_Construct_UScriptStruct_FSnakeGenerationSettings_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_SnakeGenerationSettings.InnerSingleton;
}
// End ScriptStruct FSnakeGenerationSettings

// Begin ScriptStruct FSnakeGenerationStats
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SnakeGenerationStats;
class UScriptStruct* FSnakeGenerationStats::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SnakeGenerationStats.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SnakeGenerationStats.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSnakeGenerationStats, (UObject*)Z_Construct_UPackage__Script_EternalDescent(), TEXT("SnakeGenerationStats"));
	}
	return Z_Registration_Info_UScriptStruct_SnakeGenerationStats.OuterSingleton;
}
template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<FSnakeGenerationStats>()
{
	return FSnakeGenerationStats::StaticStruct();
}
struct Z_Construct_UScriptStruct_FSnakeGenerationStats_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GenerationTimeMs_MetaData[] = {
		{ "Category", "SnakeGenerationStats" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoomsGenerated_MetaData[] = {
		{ "Category", "SnakeGenerationStats" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PathLength_MetaData[] = {
		{ "Category", "SnakeGenerationStats" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BacktrackCount_MetaData[] = {
		{ "Category", "SnakeGenerationStats" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bPathConnected_MetaData[] = {
		{ "Category", "SnakeGenerationStats" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PathEfficiency_MetaData[] = {
		{ "Category", "SnakeGenerationStats" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GenerationTimeMs;
	static const UECodeGen_Private::FIntPropertyParams NewProp_RoomsGenerated;
	static const UECodeGen_Private::FIntPropertyParams NewProp_PathLength;
	static const UECodeGen_Private::FIntPropertyParams NewProp_BacktrackCount;
	static void NewProp_bPathConnected_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bPathConnected;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PathEfficiency;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSnakeGenerationStats>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSnakeGenerationStats_Statics::NewProp_GenerationTimeMs = { "GenerationTimeMs", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeGenerationStats, GenerationTimeMs), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GenerationTimeMs_MetaData), NewProp_GenerationTimeMs_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSnakeGenerationStats_Statics::NewProp_RoomsGenerated = { "RoomsGenerated", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeGenerationStats, RoomsGenerated), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoomsGenerated_MetaData), NewProp_RoomsGenerated_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSnakeGenerationStats_Statics::NewProp_PathLength = { "PathLength", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeGenerationStats, PathLength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PathLength_MetaData), NewProp_PathLength_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSnakeGenerationStats_Statics::NewProp_BacktrackCount = { "BacktrackCount", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeGenerationStats, BacktrackCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BacktrackCount_MetaData), NewProp_BacktrackCount_MetaData) };
void Z_Construct_UScriptStruct_FSnakeGenerationStats_Statics::NewProp_bPathConnected_SetBit(void* Obj)
{
	((FSnakeGenerationStats*)Obj)->bPathConnected = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSnakeGenerationStats_Statics::NewProp_bPathConnected = { "bPathConnected", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FSnakeGenerationStats), &Z_Construct_UScriptStruct_FSnakeGenerationStats_Statics::NewProp_bPathConnected_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bPathConnected_MetaData), NewProp_bPathConnected_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSnakeGenerationStats_Statics::NewProp_PathEfficiency = { "PathEfficiency", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeGenerationStats, PathEfficiency), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PathEfficiency_MetaData), NewProp_PathEfficiency_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSnakeGenerationStats_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeGenerationStats_Statics::NewProp_GenerationTimeMs,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeGenerationStats_Statics::NewProp_RoomsGenerated,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeGenerationStats_Statics::NewProp_PathLength,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeGenerationStats_Statics::NewProp_BacktrackCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeGenerationStats_Statics::NewProp_bPathConnected,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeGenerationStats_Statics::NewProp_PathEfficiency,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSnakeGenerationStats_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSnakeGenerationStats_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_EternalDescent,
	nullptr,
	&NewStructOps,
	"SnakeGenerationStats",
	Z_Construct_UScriptStruct_FSnakeGenerationStats_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSnakeGenerationStats_Statics::PropPointers),
	sizeof(FSnakeGenerationStats),
	alignof(FSnakeGenerationStats),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSnakeGenerationStats_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSnakeGenerationStats_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FSnakeGenerationStats()
{
	if (!Z_Registration_Info_UScriptStruct_SnakeGenerationStats.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SnakeGenerationStats.InnerSingleton, Z_Construct_UScriptStruct_FSnakeGenerationStats_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_SnakeGenerationStats.InnerSingleton;
}
// End ScriptStruct FSnakeGenerationStats

// Begin Class ASnakeDungeonGenerator Function ApplyADAInfluence
struct Z_Construct_UFunction_ASnakeDungeonGenerator_ApplyADAInfluence_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Snake Generation|ADA" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ADA Integration\n" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "ADA Integration" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASnakeDungeonGenerator_ApplyADAInfluence_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASnakeDungeonGenerator, nullptr, "ApplyADAInfluence", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_ApplyADAInfluence_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASnakeDungeonGenerator_ApplyADAInfluence_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ASnakeDungeonGenerator_ApplyADAInfluence()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASnakeDungeonGenerator_ApplyADAInfluence_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASnakeDungeonGenerator::execApplyADAInfluence)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ApplyADAInfluence();
	P_NATIVE_END;
}
// End Class ASnakeDungeonGenerator Function ApplyADAInfluence

// Begin Class ASnakeDungeonGenerator Function AssignRoomTypes
struct Z_Construct_UFunction_ASnakeDungeonGenerator_AssignRoomTypes_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Snake Generation|Rooms" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Room Assignment Functions\n" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Room Assignment Functions" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASnakeDungeonGenerator_AssignRoomTypes_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASnakeDungeonGenerator, nullptr, "AssignRoomTypes", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_AssignRoomTypes_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASnakeDungeonGenerator_AssignRoomTypes_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ASnakeDungeonGenerator_AssignRoomTypes()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASnakeDungeonGenerator_AssignRoomTypes_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASnakeDungeonGenerator::execAssignRoomTypes)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AssignRoomTypes();
	P_NATIVE_END;
}
// End Class ASnakeDungeonGenerator Function AssignRoomTypes

// Begin Class ASnakeDungeonGenerator Function AttemptBranchFromPosition
struct Z_Construct_UFunction_ASnakeDungeonGenerator_AttemptBranchFromPosition_Statics
{
	struct SnakeDungeonGenerator_eventAttemptBranchFromPosition_Parms
	{
		FIntVector Position;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Snake Generation|Branching" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Position;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASnakeDungeonGenerator_AttemptBranchFromPosition_Statics::NewProp_Position = { "Position", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SnakeDungeonGenerator_eventAttemptBranchFromPosition_Parms, Position), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_ASnakeDungeonGenerator_AttemptBranchFromPosition_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((SnakeDungeonGenerator_eventAttemptBranchFromPosition_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASnakeDungeonGenerator_AttemptBranchFromPosition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(SnakeDungeonGenerator_eventAttemptBranchFromPosition_Parms), &Z_Construct_UFunction_ASnakeDungeonGenerator_AttemptBranchFromPosition_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASnakeDungeonGenerator_AttemptBranchFromPosition_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASnakeDungeonGenerator_AttemptBranchFromPosition_Statics::NewProp_Position,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASnakeDungeonGenerator_AttemptBranchFromPosition_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_AttemptBranchFromPosition_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASnakeDungeonGenerator_AttemptBranchFromPosition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASnakeDungeonGenerator, nullptr, "AttemptBranchFromPosition", nullptr, nullptr, Z_Construct_UFunction_ASnakeDungeonGenerator_AttemptBranchFromPosition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_AttemptBranchFromPosition_Statics::PropPointers), sizeof(Z_Construct_UFunction_ASnakeDungeonGenerator_AttemptBranchFromPosition_Statics::SnakeDungeonGenerator_eventAttemptBranchFromPosition_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_AttemptBranchFromPosition_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASnakeDungeonGenerator_AttemptBranchFromPosition_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ASnakeDungeonGenerator_AttemptBranchFromPosition_Statics::SnakeDungeonGenerator_eventAttemptBranchFromPosition_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ASnakeDungeonGenerator_AttemptBranchFromPosition()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASnakeDungeonGenerator_AttemptBranchFromPosition_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASnakeDungeonGenerator::execAttemptBranchFromPosition)
{
	P_GET_STRUCT(FIntVector,Z_Param_Position);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->AttemptBranchFromPosition(Z_Param_Position);
	P_NATIVE_END;
}
// End Class ASnakeDungeonGenerator Function AttemptBranchFromPosition

// Begin Class ASnakeDungeonGenerator Function CalculateManhattanDistance
struct Z_Construct_UFunction_ASnakeDungeonGenerator_CalculateManhattanDistance_Statics
{
	struct SnakeDungeonGenerator_eventCalculateManhattanDistance_Parms
	{
		FIntVector A;
		FIntVector B;
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Snake Generation|Utility" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_A;
	static const UECodeGen_Private::FStructPropertyParams NewProp_B;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASnakeDungeonGenerator_CalculateManhattanDistance_Statics::NewProp_A = { "A", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SnakeDungeonGenerator_eventCalculateManhattanDistance_Parms, A), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASnakeDungeonGenerator_CalculateManhattanDistance_Statics::NewProp_B = { "B", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SnakeDungeonGenerator_eventCalculateManhattanDistance_Parms, B), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASnakeDungeonGenerator_CalculateManhattanDistance_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SnakeDungeonGenerator_eventCalculateManhattanDistance_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASnakeDungeonGenerator_CalculateManhattanDistance_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASnakeDungeonGenerator_CalculateManhattanDistance_Statics::NewProp_A,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASnakeDungeonGenerator_CalculateManhattanDistance_Statics::NewProp_B,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASnakeDungeonGenerator_CalculateManhattanDistance_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_CalculateManhattanDistance_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASnakeDungeonGenerator_CalculateManhattanDistance_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASnakeDungeonGenerator, nullptr, "CalculateManhattanDistance", nullptr, nullptr, Z_Construct_UFunction_ASnakeDungeonGenerator_CalculateManhattanDistance_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_CalculateManhattanDistance_Statics::PropPointers), sizeof(Z_Construct_UFunction_ASnakeDungeonGenerator_CalculateManhattanDistance_Statics::SnakeDungeonGenerator_eventCalculateManhattanDistance_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_CalculateManhattanDistance_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASnakeDungeonGenerator_CalculateManhattanDistance_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ASnakeDungeonGenerator_CalculateManhattanDistance_Statics::SnakeDungeonGenerator_eventCalculateManhattanDistance_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ASnakeDungeonGenerator_CalculateManhattanDistance()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASnakeDungeonGenerator_CalculateManhattanDistance_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASnakeDungeonGenerator::execCalculateManhattanDistance)
{
	P_GET_STRUCT(FIntVector,Z_Param_A);
	P_GET_STRUCT(FIntVector,Z_Param_B);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->CalculateManhattanDistance(Z_Param_A,Z_Param_B);
	P_NATIVE_END;
}
// End Class ASnakeDungeonGenerator Function CalculateManhattanDistance

// Begin Class ASnakeDungeonGenerator Function CreateSnakePathFromStartToExit
struct Z_Construct_UFunction_ASnakeDungeonGenerator_CreateSnakePathFromStartToExit_Statics
{
	struct SnakeDungeonGenerator_eventCreateSnakePathFromStartToExit_Parms
	{
		FIntVector StartPos;
		FIntVector ExitPos;
		TArray<FIntVector> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Snake Generation|Path" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Path Generation Functions\n" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Path Generation Functions" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_StartPos;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ExitPos;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASnakeDungeonGenerator_CreateSnakePathFromStartToExit_Statics::NewProp_StartPos = { "StartPos", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SnakeDungeonGenerator_eventCreateSnakePathFromStartToExit_Parms, StartPos), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASnakeDungeonGenerator_CreateSnakePathFromStartToExit_Statics::NewProp_ExitPos = { "ExitPos", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SnakeDungeonGenerator_eventCreateSnakePathFromStartToExit_Parms, ExitPos), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASnakeDungeonGenerator_CreateSnakePathFromStartToExit_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ASnakeDungeonGenerator_CreateSnakePathFromStartToExit_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SnakeDungeonGenerator_eventCreateSnakePathFromStartToExit_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASnakeDungeonGenerator_CreateSnakePathFromStartToExit_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASnakeDungeonGenerator_CreateSnakePathFromStartToExit_Statics::NewProp_StartPos,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASnakeDungeonGenerator_CreateSnakePathFromStartToExit_Statics::NewProp_ExitPos,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASnakeDungeonGenerator_CreateSnakePathFromStartToExit_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASnakeDungeonGenerator_CreateSnakePathFromStartToExit_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_CreateSnakePathFromStartToExit_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASnakeDungeonGenerator_CreateSnakePathFromStartToExit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASnakeDungeonGenerator, nullptr, "CreateSnakePathFromStartToExit", nullptr, nullptr, Z_Construct_UFunction_ASnakeDungeonGenerator_CreateSnakePathFromStartToExit_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_CreateSnakePathFromStartToExit_Statics::PropPointers), sizeof(Z_Construct_UFunction_ASnakeDungeonGenerator_CreateSnakePathFromStartToExit_Statics::SnakeDungeonGenerator_eventCreateSnakePathFromStartToExit_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_CreateSnakePathFromStartToExit_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASnakeDungeonGenerator_CreateSnakePathFromStartToExit_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ASnakeDungeonGenerator_CreateSnakePathFromStartToExit_Statics::SnakeDungeonGenerator_eventCreateSnakePathFromStartToExit_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ASnakeDungeonGenerator_CreateSnakePathFromStartToExit()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASnakeDungeonGenerator_CreateSnakePathFromStartToExit_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASnakeDungeonGenerator::execCreateSnakePathFromStartToExit)
{
	P_GET_STRUCT(FIntVector,Z_Param_StartPos);
	P_GET_STRUCT(FIntVector,Z_Param_ExitPos);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FIntVector>*)Z_Param__Result=P_THIS->CreateSnakePathFromStartToExit(Z_Param_StartPos,Z_Param_ExitPos);
	P_NATIVE_END;
}
// End Class ASnakeDungeonGenerator Function CreateSnakePathFromStartToExit

// Begin Class ASnakeDungeonGenerator Function DetermineRoomTypeForPosition
struct Z_Construct_UFunction_ASnakeDungeonGenerator_DetermineRoomTypeForPosition_Statics
{
	struct SnakeDungeonGenerator_eventDetermineRoomTypeForPosition_Parms
	{
		int32 PathIndex;
		int32 TotalPathLength;
		ERoomType ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Snake Generation|Rooms" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_PathIndex;
	static const UECodeGen_Private::FIntPropertyParams NewProp_TotalPathLength;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ASnakeDungeonGenerator_DetermineRoomTypeForPosition_Statics::NewProp_PathIndex = { "PathIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SnakeDungeonGenerator_eventDetermineRoomTypeForPosition_Parms, PathIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ASnakeDungeonGenerator_DetermineRoomTypeForPosition_Statics::NewProp_TotalPathLength = { "TotalPathLength", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SnakeDungeonGenerator_eventDetermineRoomTypeForPosition_Parms, TotalPathLength), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_ASnakeDungeonGenerator_DetermineRoomTypeForPosition_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_ASnakeDungeonGenerator_DetermineRoomTypeForPosition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SnakeDungeonGenerator_eventDetermineRoomTypeForPosition_Parms, ReturnValue), Z_Construct_UEnum_EternalDescent_ERoomType, METADATA_PARAMS(0, nullptr) }; // 1291513837
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASnakeDungeonGenerator_DetermineRoomTypeForPosition_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASnakeDungeonGenerator_DetermineRoomTypeForPosition_Statics::NewProp_PathIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASnakeDungeonGenerator_DetermineRoomTypeForPosition_Statics::NewProp_TotalPathLength,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASnakeDungeonGenerator_DetermineRoomTypeForPosition_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASnakeDungeonGenerator_DetermineRoomTypeForPosition_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_DetermineRoomTypeForPosition_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASnakeDungeonGenerator_DetermineRoomTypeForPosition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASnakeDungeonGenerator, nullptr, "DetermineRoomTypeForPosition", nullptr, nullptr, Z_Construct_UFunction_ASnakeDungeonGenerator_DetermineRoomTypeForPosition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_DetermineRoomTypeForPosition_Statics::PropPointers), sizeof(Z_Construct_UFunction_ASnakeDungeonGenerator_DetermineRoomTypeForPosition_Statics::SnakeDungeonGenerator_eventDetermineRoomTypeForPosition_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_DetermineRoomTypeForPosition_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASnakeDungeonGenerator_DetermineRoomTypeForPosition_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ASnakeDungeonGenerator_DetermineRoomTypeForPosition_Statics::SnakeDungeonGenerator_eventDetermineRoomTypeForPosition_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ASnakeDungeonGenerator_DetermineRoomTypeForPosition()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASnakeDungeonGenerator_DetermineRoomTypeForPosition_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASnakeDungeonGenerator::execDetermineRoomTypeForPosition)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_PathIndex);
	P_GET_PROPERTY(FIntProperty,Z_Param_TotalPathLength);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(ERoomType*)Z_Param__Result=P_THIS->DetermineRoomTypeForPosition(Z_Param_PathIndex,Z_Param_TotalPathLength);
	P_NATIVE_END;
}
// End Class ASnakeDungeonGenerator Function DetermineRoomTypeForPosition

// Begin Class ASnakeDungeonGenerator Function DrawDebugSnakePath
struct Z_Construct_UFunction_ASnakeDungeonGenerator_DrawDebugSnakePath_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Snake Generation|Debug" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Debug and Testing Functions\n" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Debug and Testing Functions" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASnakeDungeonGenerator_DrawDebugSnakePath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASnakeDungeonGenerator, nullptr, "DrawDebugSnakePath", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_DrawDebugSnakePath_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASnakeDungeonGenerator_DrawDebugSnakePath_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ASnakeDungeonGenerator_DrawDebugSnakePath()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASnakeDungeonGenerator_DrawDebugSnakePath_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASnakeDungeonGenerator::execDrawDebugSnakePath)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DrawDebugSnakePath();
	P_NATIVE_END;
}
// End Class ASnakeDungeonGenerator Function DrawDebugSnakePath

// Begin Class ASnakeDungeonGenerator Function GenerateAndVisualizeSnakeDungeon
struct Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateAndVisualizeSnakeDungeon_Statics
{
	struct SnakeDungeonGenerator_eventGenerateAndVisualizeSnakeDungeon_Parms
	{
		int32 Seed;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Snake Generation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Combined function for complete generation */" },
#endif
		{ "CPP_Default_Seed", "-1" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Combined function for complete generation" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_Seed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateAndVisualizeSnakeDungeon_Statics::NewProp_Seed = { "Seed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SnakeDungeonGenerator_eventGenerateAndVisualizeSnakeDungeon_Parms, Seed), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateAndVisualizeSnakeDungeon_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateAndVisualizeSnakeDungeon_Statics::NewProp_Seed,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateAndVisualizeSnakeDungeon_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateAndVisualizeSnakeDungeon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASnakeDungeonGenerator, nullptr, "GenerateAndVisualizeSnakeDungeon", nullptr, nullptr, Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateAndVisualizeSnakeDungeon_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateAndVisualizeSnakeDungeon_Statics::PropPointers), sizeof(Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateAndVisualizeSnakeDungeon_Statics::SnakeDungeonGenerator_eventGenerateAndVisualizeSnakeDungeon_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateAndVisualizeSnakeDungeon_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateAndVisualizeSnakeDungeon_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateAndVisualizeSnakeDungeon_Statics::SnakeDungeonGenerator_eventGenerateAndVisualizeSnakeDungeon_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateAndVisualizeSnakeDungeon()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateAndVisualizeSnakeDungeon_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASnakeDungeonGenerator::execGenerateAndVisualizeSnakeDungeon)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_Seed);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->GenerateAndVisualizeSnakeDungeon(Z_Param_Seed);
	P_NATIVE_END;
}
// End Class ASnakeDungeonGenerator Function GenerateAndVisualizeSnakeDungeon

// Begin Class ASnakeDungeonGenerator Function GenerateBranches
struct Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateBranches_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Snake Generation|Branching" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Branching Functions\n" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Branching Functions" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateBranches_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASnakeDungeonGenerator, nullptr, "GenerateBranches", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateBranches_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateBranches_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateBranches()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateBranches_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASnakeDungeonGenerator::execGenerateBranches)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->GenerateBranches();
	P_NATIVE_END;
}
// End Class ASnakeDungeonGenerator Function GenerateBranches

// Begin Class ASnakeDungeonGenerator Function GenerateSnakePath
struct Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateSnakePath_Statics
{
	struct SnakeDungeonGenerator_eventGenerateSnakePath_Parms
	{
		int32 Seed;
		FSnakeGenerationStats ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Snake Generation|Loop 1" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** LOOP 1: Room Placement - Generate snake path and place rooms */" },
#endif
		{ "CPP_Default_Seed", "-1" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "LOOP 1: Room Placement - Generate snake path and place rooms" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_Seed;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateSnakePath_Statics::NewProp_Seed = { "Seed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SnakeDungeonGenerator_eventGenerateSnakePath_Parms, Seed), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateSnakePath_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SnakeDungeonGenerator_eventGenerateSnakePath_Parms, ReturnValue), Z_Construct_UScriptStruct_FSnakeGenerationStats, METADATA_PARAMS(0, nullptr) }; // 1500988238
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateSnakePath_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateSnakePath_Statics::NewProp_Seed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateSnakePath_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateSnakePath_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateSnakePath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASnakeDungeonGenerator, nullptr, "GenerateSnakePath", nullptr, nullptr, Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateSnakePath_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateSnakePath_Statics::PropPointers), sizeof(Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateSnakePath_Statics::SnakeDungeonGenerator_eventGenerateSnakePath_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateSnakePath_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateSnakePath_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateSnakePath_Statics::SnakeDungeonGenerator_eventGenerateSnakePath_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateSnakePath()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateSnakePath_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASnakeDungeonGenerator::execGenerateSnakePath)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_Seed);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FSnakeGenerationStats*)Z_Param__Result=P_THIS->GenerateSnakePath(Z_Param_Seed);
	P_NATIVE_END;
}
// End Class ASnakeDungeonGenerator Function GenerateSnakePath

// Begin Class ASnakeDungeonGenerator Function GetADADifficultyModifier
struct Z_Construct_UFunction_ASnakeDungeonGenerator_GetADADifficultyModifier_Statics
{
	struct SnakeDungeonGenerator_eventGetADADifficultyModifier_Parms
	{
		int32 PathIndex;
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Snake Generation|ADA" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_PathIndex;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ASnakeDungeonGenerator_GetADADifficultyModifier_Statics::NewProp_PathIndex = { "PathIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SnakeDungeonGenerator_eventGetADADifficultyModifier_Parms, PathIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASnakeDungeonGenerator_GetADADifficultyModifier_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SnakeDungeonGenerator_eventGetADADifficultyModifier_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASnakeDungeonGenerator_GetADADifficultyModifier_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASnakeDungeonGenerator_GetADADifficultyModifier_Statics::NewProp_PathIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASnakeDungeonGenerator_GetADADifficultyModifier_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_GetADADifficultyModifier_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASnakeDungeonGenerator_GetADADifficultyModifier_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASnakeDungeonGenerator, nullptr, "GetADADifficultyModifier", nullptr, nullptr, Z_Construct_UFunction_ASnakeDungeonGenerator_GetADADifficultyModifier_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_GetADADifficultyModifier_Statics::PropPointers), sizeof(Z_Construct_UFunction_ASnakeDungeonGenerator_GetADADifficultyModifier_Statics::SnakeDungeonGenerator_eventGetADADifficultyModifier_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_GetADADifficultyModifier_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASnakeDungeonGenerator_GetADADifficultyModifier_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ASnakeDungeonGenerator_GetADADifficultyModifier_Statics::SnakeDungeonGenerator_eventGetADADifficultyModifier_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ASnakeDungeonGenerator_GetADADifficultyModifier()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASnakeDungeonGenerator_GetADADifficultyModifier_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASnakeDungeonGenerator::execGetADADifficultyModifier)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_PathIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetADADifficultyModifier(Z_Param_PathIndex);
	P_NATIVE_END;
}
// End Class ASnakeDungeonGenerator Function GetADADifficultyModifier

// Begin Class ASnakeDungeonGenerator Function GetDirectionToNeighbor
struct Z_Construct_UFunction_ASnakeDungeonGenerator_GetDirectionToNeighbor_Statics
{
	struct SnakeDungeonGenerator_eventGetDirectionToNeighbor_Parms
	{
		FIntVector From;
		FIntVector To;
		ESnakeDirection ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Snake Generation|Utility" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_From;
	static const UECodeGen_Private::FStructPropertyParams NewProp_To;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASnakeDungeonGenerator_GetDirectionToNeighbor_Statics::NewProp_From = { "From", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SnakeDungeonGenerator_eventGetDirectionToNeighbor_Parms, From), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASnakeDungeonGenerator_GetDirectionToNeighbor_Statics::NewProp_To = { "To", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SnakeDungeonGenerator_eventGetDirectionToNeighbor_Parms, To), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_ASnakeDungeonGenerator_GetDirectionToNeighbor_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_ASnakeDungeonGenerator_GetDirectionToNeighbor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SnakeDungeonGenerator_eventGetDirectionToNeighbor_Parms, ReturnValue), Z_Construct_UEnum_EternalDescent_ESnakeDirection, METADATA_PARAMS(0, nullptr) }; // 3595573372
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASnakeDungeonGenerator_GetDirectionToNeighbor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASnakeDungeonGenerator_GetDirectionToNeighbor_Statics::NewProp_From,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASnakeDungeonGenerator_GetDirectionToNeighbor_Statics::NewProp_To,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASnakeDungeonGenerator_GetDirectionToNeighbor_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASnakeDungeonGenerator_GetDirectionToNeighbor_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_GetDirectionToNeighbor_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASnakeDungeonGenerator_GetDirectionToNeighbor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASnakeDungeonGenerator, nullptr, "GetDirectionToNeighbor", nullptr, nullptr, Z_Construct_UFunction_ASnakeDungeonGenerator_GetDirectionToNeighbor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_GetDirectionToNeighbor_Statics::PropPointers), sizeof(Z_Construct_UFunction_ASnakeDungeonGenerator_GetDirectionToNeighbor_Statics::SnakeDungeonGenerator_eventGetDirectionToNeighbor_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_GetDirectionToNeighbor_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASnakeDungeonGenerator_GetDirectionToNeighbor_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ASnakeDungeonGenerator_GetDirectionToNeighbor_Statics::SnakeDungeonGenerator_eventGetDirectionToNeighbor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ASnakeDungeonGenerator_GetDirectionToNeighbor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASnakeDungeonGenerator_GetDirectionToNeighbor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASnakeDungeonGenerator::execGetDirectionToNeighbor)
{
	P_GET_STRUCT(FIntVector,Z_Param_From);
	P_GET_STRUCT(FIntVector,Z_Param_To);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(ESnakeDirection*)Z_Param__Result=P_THIS->GetDirectionToNeighbor(Z_Param_From,Z_Param_To);
	P_NATIVE_END;
}
// End Class ASnakeDungeonGenerator Function GetDirectionToNeighbor

// Begin Class ASnakeDungeonGenerator Function GetLastGenerationStats
struct Z_Construct_UFunction_ASnakeDungeonGenerator_GetLastGenerationStats_Statics
{
	struct SnakeDungeonGenerator_eventGetLastGenerationStats_Parms
	{
		FSnakeGenerationStats ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Snake Generation|Debug" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASnakeDungeonGenerator_GetLastGenerationStats_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SnakeDungeonGenerator_eventGetLastGenerationStats_Parms, ReturnValue), Z_Construct_UScriptStruct_FSnakeGenerationStats, METADATA_PARAMS(0, nullptr) }; // 1500988238
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASnakeDungeonGenerator_GetLastGenerationStats_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASnakeDungeonGenerator_GetLastGenerationStats_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_GetLastGenerationStats_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASnakeDungeonGenerator_GetLastGenerationStats_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASnakeDungeonGenerator, nullptr, "GetLastGenerationStats", nullptr, nullptr, Z_Construct_UFunction_ASnakeDungeonGenerator_GetLastGenerationStats_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_GetLastGenerationStats_Statics::PropPointers), sizeof(Z_Construct_UFunction_ASnakeDungeonGenerator_GetLastGenerationStats_Statics::SnakeDungeonGenerator_eventGetLastGenerationStats_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_GetLastGenerationStats_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASnakeDungeonGenerator_GetLastGenerationStats_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ASnakeDungeonGenerator_GetLastGenerationStats_Statics::SnakeDungeonGenerator_eventGetLastGenerationStats_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ASnakeDungeonGenerator_GetLastGenerationStats()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASnakeDungeonGenerator_GetLastGenerationStats_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASnakeDungeonGenerator::execGetLastGenerationStats)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FSnakeGenerationStats*)Z_Param__Result=P_THIS->GetLastGenerationStats();
	P_NATIVE_END;
}
// End Class ASnakeDungeonGenerator Function GetLastGenerationStats

// Begin Class ASnakeDungeonGenerator Function GetShortestPath
struct Z_Construct_UFunction_ASnakeDungeonGenerator_GetShortestPath_Statics
{
	struct SnakeDungeonGenerator_eventGetShortestPath_Parms
	{
		FIntVector Start;
		FIntVector End;
		TArray<FIntVector> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Snake Generation|Path" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Start;
	static const UECodeGen_Private::FStructPropertyParams NewProp_End;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASnakeDungeonGenerator_GetShortestPath_Statics::NewProp_Start = { "Start", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SnakeDungeonGenerator_eventGetShortestPath_Parms, Start), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASnakeDungeonGenerator_GetShortestPath_Statics::NewProp_End = { "End", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SnakeDungeonGenerator_eventGetShortestPath_Parms, End), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASnakeDungeonGenerator_GetShortestPath_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ASnakeDungeonGenerator_GetShortestPath_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SnakeDungeonGenerator_eventGetShortestPath_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASnakeDungeonGenerator_GetShortestPath_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASnakeDungeonGenerator_GetShortestPath_Statics::NewProp_Start,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASnakeDungeonGenerator_GetShortestPath_Statics::NewProp_End,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASnakeDungeonGenerator_GetShortestPath_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASnakeDungeonGenerator_GetShortestPath_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_GetShortestPath_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASnakeDungeonGenerator_GetShortestPath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASnakeDungeonGenerator, nullptr, "GetShortestPath", nullptr, nullptr, Z_Construct_UFunction_ASnakeDungeonGenerator_GetShortestPath_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_GetShortestPath_Statics::PropPointers), sizeof(Z_Construct_UFunction_ASnakeDungeonGenerator_GetShortestPath_Statics::SnakeDungeonGenerator_eventGetShortestPath_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_GetShortestPath_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASnakeDungeonGenerator_GetShortestPath_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ASnakeDungeonGenerator_GetShortestPath_Statics::SnakeDungeonGenerator_eventGetShortestPath_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ASnakeDungeonGenerator_GetShortestPath()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASnakeDungeonGenerator_GetShortestPath_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASnakeDungeonGenerator::execGetShortestPath)
{
	P_GET_STRUCT(FIntVector,Z_Param_Start);
	P_GET_STRUCT(FIntVector,Z_Param_End);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FIntVector>*)Z_Param__Result=P_THIS->GetShortestPath(Z_Param_Start,Z_Param_End);
	P_NATIVE_END;
}
// End Class ASnakeDungeonGenerator Function GetShortestPath

// Begin Class ASnakeDungeonGenerator Function GetValidNeighbors
struct Z_Construct_UFunction_ASnakeDungeonGenerator_GetValidNeighbors_Statics
{
	struct SnakeDungeonGenerator_eventGetValidNeighbors_Parms
	{
		FIntVector Position;
		TArray<FIntVector> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Snake Generation|Utility" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Position;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASnakeDungeonGenerator_GetValidNeighbors_Statics::NewProp_Position = { "Position", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SnakeDungeonGenerator_eventGetValidNeighbors_Parms, Position), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASnakeDungeonGenerator_GetValidNeighbors_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ASnakeDungeonGenerator_GetValidNeighbors_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SnakeDungeonGenerator_eventGetValidNeighbors_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASnakeDungeonGenerator_GetValidNeighbors_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASnakeDungeonGenerator_GetValidNeighbors_Statics::NewProp_Position,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASnakeDungeonGenerator_GetValidNeighbors_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASnakeDungeonGenerator_GetValidNeighbors_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_GetValidNeighbors_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASnakeDungeonGenerator_GetValidNeighbors_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASnakeDungeonGenerator, nullptr, "GetValidNeighbors", nullptr, nullptr, Z_Construct_UFunction_ASnakeDungeonGenerator_GetValidNeighbors_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_GetValidNeighbors_Statics::PropPointers), sizeof(Z_Construct_UFunction_ASnakeDungeonGenerator_GetValidNeighbors_Statics::SnakeDungeonGenerator_eventGetValidNeighbors_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_GetValidNeighbors_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASnakeDungeonGenerator_GetValidNeighbors_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ASnakeDungeonGenerator_GetValidNeighbors_Statics::SnakeDungeonGenerator_eventGetValidNeighbors_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ASnakeDungeonGenerator_GetValidNeighbors()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASnakeDungeonGenerator_GetValidNeighbors_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASnakeDungeonGenerator::execGetValidNeighbors)
{
	P_GET_STRUCT(FIntVector,Z_Param_Position);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FIntVector>*)Z_Param__Result=P_THIS->GetValidNeighbors(Z_Param_Position);
	P_NATIVE_END;
}
// End Class ASnakeDungeonGenerator Function GetValidNeighbors

// Begin Class ASnakeDungeonGenerator Function IsValidSnakePosition
struct Z_Construct_UFunction_ASnakeDungeonGenerator_IsValidSnakePosition_Statics
{
	struct SnakeDungeonGenerator_eventIsValidSnakePosition_Parms
	{
		FIntVector Position;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Snake Generation|Utility" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Utility Functions\n" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Utility Functions" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Position;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASnakeDungeonGenerator_IsValidSnakePosition_Statics::NewProp_Position = { "Position", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SnakeDungeonGenerator_eventIsValidSnakePosition_Parms, Position), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_ASnakeDungeonGenerator_IsValidSnakePosition_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((SnakeDungeonGenerator_eventIsValidSnakePosition_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASnakeDungeonGenerator_IsValidSnakePosition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(SnakeDungeonGenerator_eventIsValidSnakePosition_Parms), &Z_Construct_UFunction_ASnakeDungeonGenerator_IsValidSnakePosition_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASnakeDungeonGenerator_IsValidSnakePosition_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASnakeDungeonGenerator_IsValidSnakePosition_Statics::NewProp_Position,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASnakeDungeonGenerator_IsValidSnakePosition_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_IsValidSnakePosition_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASnakeDungeonGenerator_IsValidSnakePosition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASnakeDungeonGenerator, nullptr, "IsValidSnakePosition", nullptr, nullptr, Z_Construct_UFunction_ASnakeDungeonGenerator_IsValidSnakePosition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_IsValidSnakePosition_Statics::PropPointers), sizeof(Z_Construct_UFunction_ASnakeDungeonGenerator_IsValidSnakePosition_Statics::SnakeDungeonGenerator_eventIsValidSnakePosition_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_IsValidSnakePosition_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASnakeDungeonGenerator_IsValidSnakePosition_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ASnakeDungeonGenerator_IsValidSnakePosition_Statics::SnakeDungeonGenerator_eventIsValidSnakePosition_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ASnakeDungeonGenerator_IsValidSnakePosition()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASnakeDungeonGenerator_IsValidSnakePosition_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASnakeDungeonGenerator::execIsValidSnakePosition)
{
	P_GET_STRUCT(FIntVector,Z_Param_Position);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsValidSnakePosition(Z_Param_Position);
	P_NATIVE_END;
}
// End Class ASnakeDungeonGenerator Function IsValidSnakePosition

// Begin Class ASnakeDungeonGenerator Function OnPathValidationFailed
struct SnakeDungeonGenerator_eventOnPathValidationFailed_Parms
{
	FString Reason;
};
static const FName NAME_ASnakeDungeonGenerator_OnPathValidationFailed = FName(TEXT("OnPathValidationFailed"));
void ASnakeDungeonGenerator::OnPathValidationFailed(const FString& Reason)
{
	SnakeDungeonGenerator_eventOnPathValidationFailed_Parms Parms;
	Parms.Reason=Reason;
	UFunction* Func = FindFunctionChecked(NAME_ASnakeDungeonGenerator_OnPathValidationFailed);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_ASnakeDungeonGenerator_OnPathValidationFailed_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Snake Generation|Events" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Reason_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_Reason;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASnakeDungeonGenerator_OnPathValidationFailed_Statics::NewProp_Reason = { "Reason", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SnakeDungeonGenerator_eventOnPathValidationFailed_Parms, Reason), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Reason_MetaData), NewProp_Reason_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASnakeDungeonGenerator_OnPathValidationFailed_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASnakeDungeonGenerator_OnPathValidationFailed_Statics::NewProp_Reason,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_OnPathValidationFailed_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASnakeDungeonGenerator_OnPathValidationFailed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASnakeDungeonGenerator, nullptr, "OnPathValidationFailed", nullptr, nullptr, Z_Construct_UFunction_ASnakeDungeonGenerator_OnPathValidationFailed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_OnPathValidationFailed_Statics::PropPointers), sizeof(SnakeDungeonGenerator_eventOnPathValidationFailed_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_OnPathValidationFailed_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASnakeDungeonGenerator_OnPathValidationFailed_Statics::Function_MetaDataParams) };
static_assert(sizeof(SnakeDungeonGenerator_eventOnPathValidationFailed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ASnakeDungeonGenerator_OnPathValidationFailed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASnakeDungeonGenerator_OnPathValidationFailed_Statics::FuncParams);
	}
	return ReturnFunction;
}
// End Class ASnakeDungeonGenerator Function OnPathValidationFailed

// Begin Class ASnakeDungeonGenerator Function OnSnakePathGenerated
struct SnakeDungeonGenerator_eventOnSnakePathGenerated_Parms
{
	FSnakeGenerationStats Stats;
};
static const FName NAME_ASnakeDungeonGenerator_OnSnakePathGenerated = FName(TEXT("OnSnakePathGenerated"));
void ASnakeDungeonGenerator::OnSnakePathGenerated(FSnakeGenerationStats const& Stats)
{
	SnakeDungeonGenerator_eventOnSnakePathGenerated_Parms Parms;
	Parms.Stats=Stats;
	UFunction* Func = FindFunctionChecked(NAME_ASnakeDungeonGenerator_OnSnakePathGenerated);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_ASnakeDungeonGenerator_OnSnakePathGenerated_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Snake Generation|Events" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Blueprint Events\n" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Blueprint Events" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Stats_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Stats;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASnakeDungeonGenerator_OnSnakePathGenerated_Statics::NewProp_Stats = { "Stats", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SnakeDungeonGenerator_eventOnSnakePathGenerated_Parms, Stats), Z_Construct_UScriptStruct_FSnakeGenerationStats, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Stats_MetaData), NewProp_Stats_MetaData) }; // 1500988238
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASnakeDungeonGenerator_OnSnakePathGenerated_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASnakeDungeonGenerator_OnSnakePathGenerated_Statics::NewProp_Stats,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_OnSnakePathGenerated_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASnakeDungeonGenerator_OnSnakePathGenerated_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASnakeDungeonGenerator, nullptr, "OnSnakePathGenerated", nullptr, nullptr, Z_Construct_UFunction_ASnakeDungeonGenerator_OnSnakePathGenerated_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_OnSnakePathGenerated_Statics::PropPointers), sizeof(SnakeDungeonGenerator_eventOnSnakePathGenerated_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_OnSnakePathGenerated_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASnakeDungeonGenerator_OnSnakePathGenerated_Statics::Function_MetaDataParams) };
static_assert(sizeof(SnakeDungeonGenerator_eventOnSnakePathGenerated_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ASnakeDungeonGenerator_OnSnakePathGenerated()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASnakeDungeonGenerator_OnSnakePathGenerated_Statics::FuncParams);
	}
	return ReturnFunction;
}
// End Class ASnakeDungeonGenerator Function OnSnakePathGenerated

// Begin Class ASnakeDungeonGenerator Function OnSnakeVisualizationComplete
static const FName NAME_ASnakeDungeonGenerator_OnSnakeVisualizationComplete = FName(TEXT("OnSnakeVisualizationComplete"));
void ASnakeDungeonGenerator::OnSnakeVisualizationComplete()
{
	UFunction* Func = FindFunctionChecked(NAME_ASnakeDungeonGenerator_OnSnakeVisualizationComplete);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_ASnakeDungeonGenerator_OnSnakeVisualizationComplete_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Snake Generation|Events" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASnakeDungeonGenerator_OnSnakeVisualizationComplete_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASnakeDungeonGenerator, nullptr, "OnSnakeVisualizationComplete", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_OnSnakeVisualizationComplete_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASnakeDungeonGenerator_OnSnakeVisualizationComplete_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ASnakeDungeonGenerator_OnSnakeVisualizationComplete()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASnakeDungeonGenerator_OnSnakeVisualizationComplete_Statics::FuncParams);
	}
	return ReturnFunction;
}
// End Class ASnakeDungeonGenerator Function OnSnakeVisualizationComplete

// Begin Class ASnakeDungeonGenerator Function SpawnConnectionHallways
struct Z_Construct_UFunction_ASnakeDungeonGenerator_SpawnConnectionHallways_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Snake Generation|Visualization" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASnakeDungeonGenerator_SpawnConnectionHallways_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASnakeDungeonGenerator, nullptr, "SpawnConnectionHallways", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_SpawnConnectionHallways_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASnakeDungeonGenerator_SpawnConnectionHallways_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ASnakeDungeonGenerator_SpawnConnectionHallways()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASnakeDungeonGenerator_SpawnConnectionHallways_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASnakeDungeonGenerator::execSpawnConnectionHallways)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SpawnConnectionHallways();
	P_NATIVE_END;
}
// End Class ASnakeDungeonGenerator Function SpawnConnectionHallways

// Begin Class ASnakeDungeonGenerator Function SpawnRoomMeshesForSnake
struct Z_Construct_UFunction_ASnakeDungeonGenerator_SpawnRoomMeshesForSnake_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Snake Generation|Visualization" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Visualization Functions\n" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Visualization Functions" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASnakeDungeonGenerator_SpawnRoomMeshesForSnake_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASnakeDungeonGenerator, nullptr, "SpawnRoomMeshesForSnake", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_SpawnRoomMeshesForSnake_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASnakeDungeonGenerator_SpawnRoomMeshesForSnake_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ASnakeDungeonGenerator_SpawnRoomMeshesForSnake()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASnakeDungeonGenerator_SpawnRoomMeshesForSnake_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASnakeDungeonGenerator::execSpawnRoomMeshesForSnake)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SpawnRoomMeshesForSnake();
	P_NATIVE_END;
}
// End Class ASnakeDungeonGenerator Function SpawnRoomMeshesForSnake

// Begin Class ASnakeDungeonGenerator Function SpawnSnakeVisualization
struct Z_Construct_UFunction_ASnakeDungeonGenerator_SpawnSnakeVisualization_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Snake Generation|Loop 2" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** LOOP 2: Mesh and Cube Spawning - Visualize the generated layout */" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "LOOP 2: Mesh and Cube Spawning - Visualize the generated layout" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASnakeDungeonGenerator_SpawnSnakeVisualization_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASnakeDungeonGenerator, nullptr, "SpawnSnakeVisualization", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_SpawnSnakeVisualization_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASnakeDungeonGenerator_SpawnSnakeVisualization_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ASnakeDungeonGenerator_SpawnSnakeVisualization()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASnakeDungeonGenerator_SpawnSnakeVisualization_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASnakeDungeonGenerator::execSpawnSnakeVisualization)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SpawnSnakeVisualization();
	P_NATIVE_END;
}
// End Class ASnakeDungeonGenerator Function SpawnSnakeVisualization

// Begin Class ASnakeDungeonGenerator Function SpawnWallCubesBetweenRooms
struct Z_Construct_UFunction_ASnakeDungeonGenerator_SpawnWallCubesBetweenRooms_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Snake Generation|Visualization" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASnakeDungeonGenerator_SpawnWallCubesBetweenRooms_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASnakeDungeonGenerator, nullptr, "SpawnWallCubesBetweenRooms", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_SpawnWallCubesBetweenRooms_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASnakeDungeonGenerator_SpawnWallCubesBetweenRooms_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ASnakeDungeonGenerator_SpawnWallCubesBetweenRooms()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASnakeDungeonGenerator_SpawnWallCubesBetweenRooms_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASnakeDungeonGenerator::execSpawnWallCubesBetweenRooms)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SpawnWallCubesBetweenRooms();
	P_NATIVE_END;
}
// End Class ASnakeDungeonGenerator Function SpawnWallCubesBetweenRooms

// Begin Class ASnakeDungeonGenerator Function ValidatePathConnectivity
struct Z_Construct_UFunction_ASnakeDungeonGenerator_ValidatePathConnectivity_Statics
{
	struct SnakeDungeonGenerator_eventValidatePathConnectivity_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Snake Generation|Path" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_ASnakeDungeonGenerator_ValidatePathConnectivity_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((SnakeDungeonGenerator_eventValidatePathConnectivity_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASnakeDungeonGenerator_ValidatePathConnectivity_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(SnakeDungeonGenerator_eventValidatePathConnectivity_Parms), &Z_Construct_UFunction_ASnakeDungeonGenerator_ValidatePathConnectivity_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASnakeDungeonGenerator_ValidatePathConnectivity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASnakeDungeonGenerator_ValidatePathConnectivity_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_ValidatePathConnectivity_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASnakeDungeonGenerator_ValidatePathConnectivity_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASnakeDungeonGenerator, nullptr, "ValidatePathConnectivity", nullptr, nullptr, Z_Construct_UFunction_ASnakeDungeonGenerator_ValidatePathConnectivity_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_ValidatePathConnectivity_Statics::PropPointers), sizeof(Z_Construct_UFunction_ASnakeDungeonGenerator_ValidatePathConnectivity_Statics::SnakeDungeonGenerator_eventValidatePathConnectivity_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_ValidatePathConnectivity_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASnakeDungeonGenerator_ValidatePathConnectivity_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ASnakeDungeonGenerator_ValidatePathConnectivity_Statics::SnakeDungeonGenerator_eventValidatePathConnectivity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ASnakeDungeonGenerator_ValidatePathConnectivity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASnakeDungeonGenerator_ValidatePathConnectivity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASnakeDungeonGenerator::execValidatePathConnectivity)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ValidatePathConnectivity();
	P_NATIVE_END;
}
// End Class ASnakeDungeonGenerator Function ValidatePathConnectivity

// Begin Class ASnakeDungeonGenerator Function ValidateSnakeGeneration
struct Z_Construct_UFunction_ASnakeDungeonGenerator_ValidateSnakeGeneration_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Snake Generation|Debug" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASnakeDungeonGenerator_ValidateSnakeGeneration_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASnakeDungeonGenerator, nullptr, "ValidateSnakeGeneration", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakeDungeonGenerator_ValidateSnakeGeneration_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASnakeDungeonGenerator_ValidateSnakeGeneration_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ASnakeDungeonGenerator_ValidateSnakeGeneration()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASnakeDungeonGenerator_ValidateSnakeGeneration_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASnakeDungeonGenerator::execValidateSnakeGeneration)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ValidateSnakeGeneration();
	P_NATIVE_END;
}
// End Class ASnakeDungeonGenerator Function ValidateSnakeGeneration

// Begin Class ASnakeDungeonGenerator
void ASnakeDungeonGenerator::StaticRegisterNativesASnakeDungeonGenerator()
{
	UClass* Class = ASnakeDungeonGenerator::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ApplyADAInfluence", &ASnakeDungeonGenerator::execApplyADAInfluence },
		{ "AssignRoomTypes", &ASnakeDungeonGenerator::execAssignRoomTypes },
		{ "AttemptBranchFromPosition", &ASnakeDungeonGenerator::execAttemptBranchFromPosition },
		{ "CalculateManhattanDistance", &ASnakeDungeonGenerator::execCalculateManhattanDistance },
		{ "CreateSnakePathFromStartToExit", &ASnakeDungeonGenerator::execCreateSnakePathFromStartToExit },
		{ "DetermineRoomTypeForPosition", &ASnakeDungeonGenerator::execDetermineRoomTypeForPosition },
		{ "DrawDebugSnakePath", &ASnakeDungeonGenerator::execDrawDebugSnakePath },
		{ "GenerateAndVisualizeSnakeDungeon", &ASnakeDungeonGenerator::execGenerateAndVisualizeSnakeDungeon },
		{ "GenerateBranches", &ASnakeDungeonGenerator::execGenerateBranches },
		{ "GenerateSnakePath", &ASnakeDungeonGenerator::execGenerateSnakePath },
		{ "GetADADifficultyModifier", &ASnakeDungeonGenerator::execGetADADifficultyModifier },
		{ "GetDirectionToNeighbor", &ASnakeDungeonGenerator::execGetDirectionToNeighbor },
		{ "GetLastGenerationStats", &ASnakeDungeonGenerator::execGetLastGenerationStats },
		{ "GetShortestPath", &ASnakeDungeonGenerator::execGetShortestPath },
		{ "GetValidNeighbors", &ASnakeDungeonGenerator::execGetValidNeighbors },
		{ "IsValidSnakePosition", &ASnakeDungeonGenerator::execIsValidSnakePosition },
		{ "SpawnConnectionHallways", &ASnakeDungeonGenerator::execSpawnConnectionHallways },
		{ "SpawnRoomMeshesForSnake", &ASnakeDungeonGenerator::execSpawnRoomMeshesForSnake },
		{ "SpawnSnakeVisualization", &ASnakeDungeonGenerator::execSpawnSnakeVisualization },
		{ "SpawnWallCubesBetweenRooms", &ASnakeDungeonGenerator::execSpawnWallCubesBetweenRooms },
		{ "ValidatePathConnectivity", &ASnakeDungeonGenerator::execValidatePathConnectivity },
		{ "ValidateSnakeGeneration", &ASnakeDungeonGenerator::execValidateSnakeGeneration },
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
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * SnakeDungeonGenerator - High-performance snake-path dungeon generator\n * \n * Features:\n * - Two-loop generation: Room Placement -> Mesh Spawning\n * - Guaranteed START to EXIT connectivity\n * - Configurable winding patterns for exploration\n * - Performance target: <16ms total generation time\n * - ADA System integration for entity influence\n * - Uses HISM for optimal rendering performance\n */" },
#endif
		{ "IncludePath", "SnakeDungeonGenerator.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "SnakeDungeonGenerator - High-performance snake-path dungeon generator\n\nFeatures:\n- Two-loop generation: Room Placement -> Mesh Spawning\n- Guaranteed START to EXIT connectivity\n- Configurable winding patterns for exploration\n- Performance target: <16ms total generation time\n- ADA System integration for entity influence\n- Uses HISM for optimal rendering performance" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GenerationSettings_MetaData[] = {
		{ "Category", "Snake Generation|Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Settings and Properties\n" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Settings and Properties" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableDebugVisualization_MetaData[] = {
		{ "Category", "Snake Generation|Settings" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bUseBatchedSpawning_MetaData[] = {
		{ "Category", "Snake Generation|Performance" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxInstancesPerBatch_MetaData[] = {
		{ "Category", "Snake Generation|Performance" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SnakePath_MetaData[] = {
		{ "Category", "Snake Generation|Runtime" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Runtime Data\n" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Runtime Data" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StartRoomPosition_MetaData[] = {
		{ "Category", "Snake Generation|Runtime" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExitRoomPosition_MetaData[] = {
		{ "Category", "Snake Generation|Runtime" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LastGenerationStats_MetaData[] = {
		{ "Category", "Snake Generation|Runtime" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoomLookup_MetaData[] = {
		{ "Category", "Snake Generation|Runtime" },
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GenerationTimes_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Performance tracking\n" },
#endif
		{ "ModuleRelativePath", "Public/SnakeDungeonGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Performance tracking" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_GenerationSettings;
	static void NewProp_bEnableDebugVisualization_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableDebugVisualization;
	static void NewProp_bUseBatchedSpawning_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseBatchedSpawning;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxInstancesPerBatch;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SnakePath_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_SnakePath;
	static const UECodeGen_Private::FStructPropertyParams NewProp_StartRoomPosition;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ExitRoomPosition;
	static const UECodeGen_Private::FStructPropertyParams NewProp_LastGenerationStats;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RoomLookup_ValueProp;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RoomLookup_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_RoomLookup;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GenerationTimes_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_GenerationTimes;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ASnakeDungeonGenerator_ApplyADAInfluence, "ApplyADAInfluence" }, // 1318208435
		{ &Z_Construct_UFunction_ASnakeDungeonGenerator_AssignRoomTypes, "AssignRoomTypes" }, // 3707631420
		{ &Z_Construct_UFunction_ASnakeDungeonGenerator_AttemptBranchFromPosition, "AttemptBranchFromPosition" }, // 1586109032
		{ &Z_Construct_UFunction_ASnakeDungeonGenerator_CalculateManhattanDistance, "CalculateManhattanDistance" }, // 2840906975
		{ &Z_Construct_UFunction_ASnakeDungeonGenerator_CreateSnakePathFromStartToExit, "CreateSnakePathFromStartToExit" }, // 1468762227
		{ &Z_Construct_UFunction_ASnakeDungeonGenerator_DetermineRoomTypeForPosition, "DetermineRoomTypeForPosition" }, // 385916192
		{ &Z_Construct_UFunction_ASnakeDungeonGenerator_DrawDebugSnakePath, "DrawDebugSnakePath" }, // 3496163148
		{ &Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateAndVisualizeSnakeDungeon, "GenerateAndVisualizeSnakeDungeon" }, // 1792235843
		{ &Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateBranches, "GenerateBranches" }, // 2964370364
		{ &Z_Construct_UFunction_ASnakeDungeonGenerator_GenerateSnakePath, "GenerateSnakePath" }, // 3305126798
		{ &Z_Construct_UFunction_ASnakeDungeonGenerator_GetADADifficultyModifier, "GetADADifficultyModifier" }, // 3531853480
		{ &Z_Construct_UFunction_ASnakeDungeonGenerator_GetDirectionToNeighbor, "GetDirectionToNeighbor" }, // 2998347412
		{ &Z_Construct_UFunction_ASnakeDungeonGenerator_GetLastGenerationStats, "GetLastGenerationStats" }, // 1095007464
		{ &Z_Construct_UFunction_ASnakeDungeonGenerator_GetShortestPath, "GetShortestPath" }, // 513071781
		{ &Z_Construct_UFunction_ASnakeDungeonGenerator_GetValidNeighbors, "GetValidNeighbors" }, // 2385431630
		{ &Z_Construct_UFunction_ASnakeDungeonGenerator_IsValidSnakePosition, "IsValidSnakePosition" }, // 2046428334
		{ &Z_Construct_UFunction_ASnakeDungeonGenerator_OnPathValidationFailed, "OnPathValidationFailed" }, // 850657659
		{ &Z_Construct_UFunction_ASnakeDungeonGenerator_OnSnakePathGenerated, "OnSnakePathGenerated" }, // 2772489091
		{ &Z_Construct_UFunction_ASnakeDungeonGenerator_OnSnakeVisualizationComplete, "OnSnakeVisualizationComplete" }, // 777768787
		{ &Z_Construct_UFunction_ASnakeDungeonGenerator_SpawnConnectionHallways, "SpawnConnectionHallways" }, // 3933777678
		{ &Z_Construct_UFunction_ASnakeDungeonGenerator_SpawnRoomMeshesForSnake, "SpawnRoomMeshesForSnake" }, // 3022757658
		{ &Z_Construct_UFunction_ASnakeDungeonGenerator_SpawnSnakeVisualization, "SpawnSnakeVisualization" }, // 2785840230
		{ &Z_Construct_UFunction_ASnakeDungeonGenerator_SpawnWallCubesBetweenRooms, "SpawnWallCubesBetweenRooms" }, // 2891580174
		{ &Z_Construct_UFunction_ASnakeDungeonGenerator_ValidatePathConnectivity, "ValidatePathConnectivity" }, // 2961998760
		{ &Z_Construct_UFunction_ASnakeDungeonGenerator_ValidateSnakeGeneration, "ValidateSnakeGeneration" }, // 1173340613
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASnakeDungeonGenerator>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ASnakeDungeonGenerator_Statics::NewProp_GenerationSettings = { "GenerationSettings", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakeDungeonGenerator, GenerationSettings), Z_Construct_UScriptStruct_FSnakeGenerationSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GenerationSettings_MetaData), NewProp_GenerationSettings_MetaData) }; // 4058937916
void Z_Construct_UClass_ASnakeDungeonGenerator_Statics::NewProp_bEnableDebugVisualization_SetBit(void* Obj)
{
	((ASnakeDungeonGenerator*)Obj)->bEnableDebugVisualization = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASnakeDungeonGenerator_Statics::NewProp_bEnableDebugVisualization = { "bEnableDebugVisualization", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ASnakeDungeonGenerator), &Z_Construct_UClass_ASnakeDungeonGenerator_Statics::NewProp_bEnableDebugVisualization_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableDebugVisualization_MetaData), NewProp_bEnableDebugVisualization_MetaData) };
void Z_Construct_UClass_ASnakeDungeonGenerator_Statics::NewProp_bUseBatchedSpawning_SetBit(void* Obj)
{
	((ASnakeDungeonGenerator*)Obj)->bUseBatchedSpawning = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASnakeDungeonGenerator_Statics::NewProp_bUseBatchedSpawning = { "bUseBatchedSpawning", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ASnakeDungeonGenerator), &Z_Construct_UClass_ASnakeDungeonGenerator_Statics::NewProp_bUseBatchedSpawning_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bUseBatchedSpawning_MetaData), NewProp_bUseBatchedSpawning_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ASnakeDungeonGenerator_Statics::NewProp_MaxInstancesPerBatch = { "MaxInstancesPerBatch", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakeDungeonGenerator, MaxInstancesPerBatch), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxInstancesPerBatch_MetaData), NewProp_MaxInstancesPerBatch_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ASnakeDungeonGenerator_Statics::NewProp_SnakePath_Inner = { "SnakePath", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FSnakePathNode, METADATA_PARAMS(0, nullptr) }; // 3692884444
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ASnakeDungeonGenerator_Statics::NewProp_SnakePath = { "SnakePath", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakeDungeonGenerator, SnakePath), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SnakePath_MetaData), NewProp_SnakePath_MetaData) }; // 3692884444
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ASnakeDungeonGenerator_Statics::NewProp_StartRoomPosition = { "StartRoomPosition", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakeDungeonGenerator, StartRoomPosition), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StartRoomPosition_MetaData), NewProp_StartRoomPosition_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ASnakeDungeonGenerator_Statics::NewProp_ExitRoomPosition = { "ExitRoomPosition", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakeDungeonGenerator, ExitRoomPosition), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExitRoomPosition_MetaData), NewProp_ExitRoomPosition_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ASnakeDungeonGenerator_Statics::NewProp_LastGenerationStats = { "LastGenerationStats", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakeDungeonGenerator, LastGenerationStats), Z_Construct_UScriptStruct_FSnakeGenerationStats, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LastGenerationStats_MetaData), NewProp_LastGenerationStats_MetaData) }; // 1500988238
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ASnakeDungeonGenerator_Statics::NewProp_RoomLookup_ValueProp = { "RoomLookup", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FSnakePathNode, METADATA_PARAMS(0, nullptr) }; // 3692884444
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ASnakeDungeonGenerator_Statics::NewProp_RoomLookup_Key_KeyProp = { "RoomLookup_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_ASnakeDungeonGenerator_Statics::NewProp_RoomLookup = { "RoomLookup", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakeDungeonGenerator, RoomLookup), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoomLookup_MetaData), NewProp_RoomLookup_MetaData) }; // 3692884444
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASnakeDungeonGenerator_Statics::NewProp_GenerationTimes_Inner = { "GenerationTimes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ASnakeDungeonGenerator_Statics::NewProp_GenerationTimes = { "GenerationTimes", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakeDungeonGenerator, GenerationTimes), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GenerationTimes_MetaData), NewProp_GenerationTimes_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASnakeDungeonGenerator_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakeDungeonGenerator_Statics::NewProp_GenerationSettings,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakeDungeonGenerator_Statics::NewProp_bEnableDebugVisualization,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakeDungeonGenerator_Statics::NewProp_bUseBatchedSpawning,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakeDungeonGenerator_Statics::NewProp_MaxInstancesPerBatch,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakeDungeonGenerator_Statics::NewProp_SnakePath_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakeDungeonGenerator_Statics::NewProp_SnakePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakeDungeonGenerator_Statics::NewProp_StartRoomPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakeDungeonGenerator_Statics::NewProp_ExitRoomPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakeDungeonGenerator_Statics::NewProp_LastGenerationStats,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakeDungeonGenerator_Statics::NewProp_RoomLookup_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakeDungeonGenerator_Statics::NewProp_RoomLookup_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakeDungeonGenerator_Statics::NewProp_RoomLookup,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakeDungeonGenerator_Statics::NewProp_GenerationTimes_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakeDungeonGenerator_Statics::NewProp_GenerationTimes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASnakeDungeonGenerator_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ASnakeDungeonGenerator_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ADungeonVisualizer,
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
		{ ESnakeDirection_StaticEnum, TEXT("ESnakeDirection"), &Z_Registration_Info_UEnum_ESnakeDirection, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3595573372U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FSnakePathNode::StaticStruct, Z_Construct_UScriptStruct_FSnakePathNode_Statics::NewStructOps, TEXT("SnakePathNode"), &Z_Registration_Info_UScriptStruct_SnakePathNode, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSnakePathNode), 3692884444U) },
		{ FSnakeGenerationSettings::StaticStruct, Z_Construct_UScriptStruct_FSnakeGenerationSettings_Statics::NewStructOps, TEXT("SnakeGenerationSettings"), &Z_Registration_Info_UScriptStruct_SnakeGenerationSettings, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSnakeGenerationSettings), 4058937916U) },
		{ FSnakeGenerationStats::StaticStruct, Z_Construct_UScriptStruct_FSnakeGenerationStats_Statics::NewStructOps, TEXT("SnakeGenerationStats"), &Z_Registration_Info_UScriptStruct_SnakeGenerationStats, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSnakeGenerationStats), 1500988238U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ASnakeDungeonGenerator, ASnakeDungeonGenerator::StaticClass, TEXT("ASnakeDungeonGenerator"), &Z_Registration_Info_UClass_ASnakeDungeonGenerator, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASnakeDungeonGenerator), 1284902686U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonGenerator_h_1819756535(TEXT("/Script/EternalDescent"),
	Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonGenerator_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonGenerator_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonGenerator_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonGenerator_h_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonGenerator_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonGenerator_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
