// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EternalDescent/Public/ADASystem.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeADASystem() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ETERNALDESCENT_API UClass* Z_Construct_UClass_AADASystem();
ETERNALDESCENT_API UClass* Z_Construct_UClass_AADASystem_NoRegister();
ETERNALDESCENT_API UEnum* Z_Construct_UEnum_EternalDescent_EADAMood();
ETERNALDESCENT_API UEnum* Z_Construct_UEnum_EternalDescent_EADAPersonality();
ETERNALDESCENT_API UEnum* Z_Construct_UEnum_EternalDescent_EPlayerArchetype();
ETERNALDESCENT_API UScriptStruct* Z_Construct_UScriptStruct_FADAMessage();
ETERNALDESCENT_API UScriptStruct* Z_Construct_UScriptStruct_FAdaptationData();
ETERNALDESCENT_API UScriptStruct* Z_Construct_UScriptStruct_FPlayerBehaviorData();
UPackage* Z_Construct_UPackage__Script_EternalDescent();
// End Cross Module References

// Begin Enum EADAPersonality
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EADAPersonality;
static UEnum* EADAPersonality_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EADAPersonality.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EADAPersonality.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_EternalDescent_EADAPersonality, (UObject*)Z_Construct_UPackage__Script_EternalDescent(), TEXT("EADAPersonality"));
	}
	return Z_Registration_Info_UEnum_EADAPersonality.OuterSingleton;
}
template<> ETERNALDESCENT_API UEnum* StaticEnum<EADAPersonality>()
{
	return EADAPersonality_StaticEnum();
}
struct Z_Construct_UEnum_EternalDescent_EADAPersonality_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Counter.Comment", "// Testing player limits\n" },
		{ "Counter.DisplayName", "Counter" },
		{ "Counter.Name", "EADAPersonality::Counter" },
		{ "Counter.ToolTip", "Testing player limits" },
		{ "Dominator.Comment", "// Countering strategies\n" },
		{ "Dominator.DisplayName", "Dominator" },
		{ "Dominator.Name", "EADAPersonality::Dominator" },
		{ "Dominator.ToolTip", "Countering strategies" },
		{ "Experiment.Comment", "// Full adaptive mode\n" },
		{ "Experiment.DisplayName", "Experimenter" },
		{ "Experiment.Name", "EADAPersonality::Experiment" },
		{ "Experiment.ToolTip", "Full adaptive mode" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
		{ "Observer.DisplayName", "Observer" },
		{ "Observer.Name", "EADAPersonality::Observer" },
		{ "Tester.Comment", "// Learning phase\n" },
		{ "Tester.DisplayName", "Tester" },
		{ "Tester.Name", "EADAPersonality::Tester" },
		{ "Tester.ToolTip", "Learning phase" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EADAPersonality::Observer", (int64)EADAPersonality::Observer },
		{ "EADAPersonality::Tester", (int64)EADAPersonality::Tester },
		{ "EADAPersonality::Counter", (int64)EADAPersonality::Counter },
		{ "EADAPersonality::Dominator", (int64)EADAPersonality::Dominator },
		{ "EADAPersonality::Experiment", (int64)EADAPersonality::Experiment },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_EternalDescent_EADAPersonality_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_EternalDescent,
	nullptr,
	"EADAPersonality",
	"EADAPersonality",
	Z_Construct_UEnum_EternalDescent_EADAPersonality_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_EternalDescent_EADAPersonality_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_EternalDescent_EADAPersonality_Statics::Enum_MetaDataParams), Z_Construct_UEnum_EternalDescent_EADAPersonality_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_EternalDescent_EADAPersonality()
{
	if (!Z_Registration_Info_UEnum_EADAPersonality.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EADAPersonality.InnerSingleton, Z_Construct_UEnum_EternalDescent_EADAPersonality_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EADAPersonality.InnerSingleton;
}
// End Enum EADAPersonality

// Begin Enum EADAMood
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EADAMood;
static UEnum* EADAMood_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EADAMood.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EADAMood.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_EternalDescent_EADAMood, (UObject*)Z_Construct_UPackage__Script_EternalDescent(), TEXT("EADAMood"));
	}
	return Z_Registration_Info_UEnum_EADAMood.OuterSingleton;
}
template<> ETERNALDESCENT_API UEnum* StaticEnum<EADAMood>()
{
	return EADAMood_StaticEnum();
}
struct Z_Construct_UEnum_EternalDescent_EADAMood_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Amused.Comment", "// Interested in player\n" },
		{ "Amused.DisplayName", "Amused" },
		{ "Amused.Name", "EADAMood::Amused" },
		{ "Amused.ToolTip", "Interested in player" },
		{ "BlueprintType", "true" },
		{ "Challenged.Comment", "// Finding player entertaining\n" },
		{ "Challenged.DisplayName", "Challenged" },
		{ "Challenged.Name", "EADAMood::Challenged" },
		{ "Challenged.ToolTip", "Finding player entertaining" },
		{ "Curious.DisplayName", "Curious" },
		{ "Curious.Name", "EADAMood::Curious" },
		{ "Frustrated.Comment", "// Player is a worthy opponent\n" },
		{ "Frustrated.DisplayName", "Frustrated" },
		{ "Frustrated.Name", "EADAMood::Frustrated" },
		{ "Frustrated.ToolTip", "Player is a worthy opponent" },
		{ "Impressed.Comment", "// Player is too predictable\n" },
		{ "Impressed.DisplayName", "Impressed" },
		{ "Impressed.Name", "EADAMood::Impressed" },
		{ "Impressed.ToolTip", "Player is too predictable" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EADAMood::Curious", (int64)EADAMood::Curious },
		{ "EADAMood::Amused", (int64)EADAMood::Amused },
		{ "EADAMood::Challenged", (int64)EADAMood::Challenged },
		{ "EADAMood::Frustrated", (int64)EADAMood::Frustrated },
		{ "EADAMood::Impressed", (int64)EADAMood::Impressed },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_EternalDescent_EADAMood_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_EternalDescent,
	nullptr,
	"EADAMood",
	"EADAMood",
	Z_Construct_UEnum_EternalDescent_EADAMood_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_EternalDescent_EADAMood_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_EternalDescent_EADAMood_Statics::Enum_MetaDataParams), Z_Construct_UEnum_EternalDescent_EADAMood_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_EternalDescent_EADAMood()
{
	if (!Z_Registration_Info_UEnum_EADAMood.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EADAMood.InnerSingleton, Z_Construct_UEnum_EternalDescent_EADAMood_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EADAMood.InnerSingleton;
}
// End Enum EADAMood

// Begin Enum EPlayerArchetype
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPlayerArchetype;
static UEnum* EPlayerArchetype_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EPlayerArchetype.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EPlayerArchetype.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_EternalDescent_EPlayerArchetype, (UObject*)Z_Construct_UPackage__Script_EternalDescent(), TEXT("EPlayerArchetype"));
	}
	return Z_Registration_Info_UEnum_EPlayerArchetype.OuterSingleton;
}
template<> ETERNALDESCENT_API UEnum* StaticEnum<EPlayerArchetype>()
{
	return EPlayerArchetype_StaticEnum();
}
struct Z_Construct_UEnum_EternalDescent_EPlayerArchetype_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Explorer.Comment", "// Seeks combat encounters\n" },
		{ "Explorer.DisplayName", "Explorer" },
		{ "Explorer.Name", "EPlayerArchetype::Explorer" },
		{ "Explorer.ToolTip", "Seeks combat encounters" },
		{ "Fighter.Comment", "// Focuses on collecting items\n" },
		{ "Fighter.DisplayName", "Fighter" },
		{ "Fighter.Name", "EPlayerArchetype::Fighter" },
		{ "Fighter.ToolTip", "Focuses on collecting items" },
		{ "Looter.Comment", "// Slow, careful exploration\n" },
		{ "Looter.DisplayName", "Looter" },
		{ "Looter.Name", "EPlayerArchetype::Looter" },
		{ "Looter.ToolTip", "Slow, careful exploration" },
		{ "Methodical.Comment", "// Fast, aggressive playstyle\n" },
		{ "Methodical.DisplayName", "Methodical" },
		{ "Methodical.Name", "EPlayerArchetype::Methodical" },
		{ "Methodical.ToolTip", "Fast, aggressive playstyle" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
		{ "Rusher.DisplayName", "Rusher" },
		{ "Rusher.Name", "EPlayerArchetype::Rusher" },
		{ "Speedrunner.Comment", "// Explores every corner\n" },
		{ "Speedrunner.DisplayName", "Speedrunner" },
		{ "Speedrunner.Name", "EPlayerArchetype::Speedrunner" },
		{ "Speedrunner.ToolTip", "Explores every corner" },
		{ "Unknown.DisplayName", "Unknown" },
		{ "Unknown.Name", "EPlayerArchetype::Unknown" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EPlayerArchetype::Unknown", (int64)EPlayerArchetype::Unknown },
		{ "EPlayerArchetype::Rusher", (int64)EPlayerArchetype::Rusher },
		{ "EPlayerArchetype::Methodical", (int64)EPlayerArchetype::Methodical },
		{ "EPlayerArchetype::Looter", (int64)EPlayerArchetype::Looter },
		{ "EPlayerArchetype::Fighter", (int64)EPlayerArchetype::Fighter },
		{ "EPlayerArchetype::Explorer", (int64)EPlayerArchetype::Explorer },
		{ "EPlayerArchetype::Speedrunner", (int64)EPlayerArchetype::Speedrunner },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_EternalDescent_EPlayerArchetype_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_EternalDescent,
	nullptr,
	"EPlayerArchetype",
	"EPlayerArchetype",
	Z_Construct_UEnum_EternalDescent_EPlayerArchetype_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_EternalDescent_EPlayerArchetype_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_EternalDescent_EPlayerArchetype_Statics::Enum_MetaDataParams), Z_Construct_UEnum_EternalDescent_EPlayerArchetype_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_EternalDescent_EPlayerArchetype()
{
	if (!Z_Registration_Info_UEnum_EPlayerArchetype.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPlayerArchetype.InnerSingleton, Z_Construct_UEnum_EternalDescent_EPlayerArchetype_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EPlayerArchetype.InnerSingleton;
}
// End Enum EPlayerArchetype

// Begin ScriptStruct FPlayerBehaviorData
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_PlayerBehaviorData;
class UScriptStruct* FPlayerBehaviorData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_PlayerBehaviorData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_PlayerBehaviorData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPlayerBehaviorData, (UObject*)Z_Construct_UPackage__Script_EternalDescent(), TEXT("PlayerBehaviorData"));
	}
	return Z_Registration_Info_UScriptStruct_PlayerBehaviorData.OuterSingleton;
}
template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<FPlayerBehaviorData>()
{
	return FPlayerBehaviorData::StaticStruct();
}
struct Z_Construct_UScriptStruct_FPlayerBehaviorData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AverageRoomClearTime_MetaData[] = {
		{ "Category", "PlayerBehaviorData" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CombatEngagementRate_MetaData[] = {
		{ "Category", "PlayerBehaviorData" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExplorationRate_MetaData[] = {
		{ "Category", "PlayerBehaviorData" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemCollectionRate_MetaData[] = {
		{ "Category", "PlayerBehaviorData" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DeathCount_MetaData[] = {
		{ "Category", "PlayerBehaviorData" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExtractionsCompleted_MetaData[] = {
		{ "Category", "PlayerBehaviorData" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreferredWeapons_MetaData[] = {
		{ "Category", "PlayerBehaviorData" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AvoidedEnemyTypes_MetaData[] = {
		{ "Category", "PlayerBehaviorData" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AverageRoomClearTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CombatEngagementRate;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ExplorationRate;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ItemCollectionRate;
	static const UECodeGen_Private::FIntPropertyParams NewProp_DeathCount;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ExtractionsCompleted;
	static const UECodeGen_Private::FStrPropertyParams NewProp_PreferredWeapons_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_PreferredWeapons;
	static const UECodeGen_Private::FStrPropertyParams NewProp_AvoidedEnemyTypes_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_AvoidedEnemyTypes;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPlayerBehaviorData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPlayerBehaviorData_Statics::NewProp_AverageRoomClearTime = { "AverageRoomClearTime", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlayerBehaviorData, AverageRoomClearTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AverageRoomClearTime_MetaData), NewProp_AverageRoomClearTime_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPlayerBehaviorData_Statics::NewProp_CombatEngagementRate = { "CombatEngagementRate", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlayerBehaviorData, CombatEngagementRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CombatEngagementRate_MetaData), NewProp_CombatEngagementRate_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPlayerBehaviorData_Statics::NewProp_ExplorationRate = { "ExplorationRate", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlayerBehaviorData, ExplorationRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExplorationRate_MetaData), NewProp_ExplorationRate_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPlayerBehaviorData_Statics::NewProp_ItemCollectionRate = { "ItemCollectionRate", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlayerBehaviorData, ItemCollectionRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemCollectionRate_MetaData), NewProp_ItemCollectionRate_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FPlayerBehaviorData_Statics::NewProp_DeathCount = { "DeathCount", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlayerBehaviorData, DeathCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DeathCount_MetaData), NewProp_DeathCount_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FPlayerBehaviorData_Statics::NewProp_ExtractionsCompleted = { "ExtractionsCompleted", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlayerBehaviorData, ExtractionsCompleted), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExtractionsCompleted_MetaData), NewProp_ExtractionsCompleted_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPlayerBehaviorData_Statics::NewProp_PreferredWeapons_Inner = { "PreferredWeapons", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FPlayerBehaviorData_Statics::NewProp_PreferredWeapons = { "PreferredWeapons", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlayerBehaviorData, PreferredWeapons), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreferredWeapons_MetaData), NewProp_PreferredWeapons_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPlayerBehaviorData_Statics::NewProp_AvoidedEnemyTypes_Inner = { "AvoidedEnemyTypes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FPlayerBehaviorData_Statics::NewProp_AvoidedEnemyTypes = { "AvoidedEnemyTypes", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlayerBehaviorData, AvoidedEnemyTypes), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AvoidedEnemyTypes_MetaData), NewProp_AvoidedEnemyTypes_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPlayerBehaviorData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlayerBehaviorData_Statics::NewProp_AverageRoomClearTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlayerBehaviorData_Statics::NewProp_CombatEngagementRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlayerBehaviorData_Statics::NewProp_ExplorationRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlayerBehaviorData_Statics::NewProp_ItemCollectionRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlayerBehaviorData_Statics::NewProp_DeathCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlayerBehaviorData_Statics::NewProp_ExtractionsCompleted,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlayerBehaviorData_Statics::NewProp_PreferredWeapons_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlayerBehaviorData_Statics::NewProp_PreferredWeapons,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlayerBehaviorData_Statics::NewProp_AvoidedEnemyTypes_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlayerBehaviorData_Statics::NewProp_AvoidedEnemyTypes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPlayerBehaviorData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPlayerBehaviorData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_EternalDescent,
	nullptr,
	&NewStructOps,
	"PlayerBehaviorData",
	Z_Construct_UScriptStruct_FPlayerBehaviorData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPlayerBehaviorData_Statics::PropPointers),
	sizeof(FPlayerBehaviorData),
	alignof(FPlayerBehaviorData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPlayerBehaviorData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPlayerBehaviorData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FPlayerBehaviorData()
{
	if (!Z_Registration_Info_UScriptStruct_PlayerBehaviorData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_PlayerBehaviorData.InnerSingleton, Z_Construct_UScriptStruct_FPlayerBehaviorData_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_PlayerBehaviorData.InnerSingleton;
}
// End ScriptStruct FPlayerBehaviorData

// Begin ScriptStruct FADAMessage
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_ADAMessage;
class UScriptStruct* FADAMessage::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_ADAMessage.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_ADAMessage.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FADAMessage, (UObject*)Z_Construct_UPackage__Script_EternalDescent(), TEXT("ADAMessage"));
	}
	return Z_Registration_Info_UScriptStruct_ADAMessage.OuterSingleton;
}
template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<FADAMessage>()
{
	return FADAMessage::StaticStruct();
}
struct Z_Construct_UScriptStruct_FADAMessage_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MessageText_MetaData[] = {
		{ "Category", "ADAMessage" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Mood_MetaData[] = {
		{ "Category", "ADAMessage" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DisplayDuration_MetaData[] = {
		{ "Category", "ADAMessage" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MessageColor_MetaData[] = {
		{ "Category", "ADAMessage" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsImportant_MetaData[] = {
		{ "Category", "ADAMessage" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_MessageText;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Mood_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Mood;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DisplayDuration;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MessageColor;
	static void NewProp_bIsImportant_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsImportant;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FADAMessage>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FADAMessage_Statics::NewProp_MessageText = { "MessageText", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FADAMessage, MessageText), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MessageText_MetaData), NewProp_MessageText_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FADAMessage_Statics::NewProp_Mood_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FADAMessage_Statics::NewProp_Mood = { "Mood", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FADAMessage, Mood), Z_Construct_UEnum_EternalDescent_EADAMood, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Mood_MetaData), NewProp_Mood_MetaData) }; // 3689353100
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FADAMessage_Statics::NewProp_DisplayDuration = { "DisplayDuration", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FADAMessage, DisplayDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DisplayDuration_MetaData), NewProp_DisplayDuration_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FADAMessage_Statics::NewProp_MessageColor = { "MessageColor", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FADAMessage, MessageColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MessageColor_MetaData), NewProp_MessageColor_MetaData) };
void Z_Construct_UScriptStruct_FADAMessage_Statics::NewProp_bIsImportant_SetBit(void* Obj)
{
	((FADAMessage*)Obj)->bIsImportant = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FADAMessage_Statics::NewProp_bIsImportant = { "bIsImportant", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FADAMessage), &Z_Construct_UScriptStruct_FADAMessage_Statics::NewProp_bIsImportant_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsImportant_MetaData), NewProp_bIsImportant_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FADAMessage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FADAMessage_Statics::NewProp_MessageText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FADAMessage_Statics::NewProp_Mood_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FADAMessage_Statics::NewProp_Mood,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FADAMessage_Statics::NewProp_DisplayDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FADAMessage_Statics::NewProp_MessageColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FADAMessage_Statics::NewProp_bIsImportant,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FADAMessage_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FADAMessage_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_EternalDescent,
	nullptr,
	&NewStructOps,
	"ADAMessage",
	Z_Construct_UScriptStruct_FADAMessage_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FADAMessage_Statics::PropPointers),
	sizeof(FADAMessage),
	alignof(FADAMessage),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FADAMessage_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FADAMessage_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FADAMessage()
{
	if (!Z_Registration_Info_UScriptStruct_ADAMessage.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_ADAMessage.InnerSingleton, Z_Construct_UScriptStruct_FADAMessage_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_ADAMessage.InnerSingleton;
}
// End ScriptStruct FADAMessage

// Begin ScriptStruct FAdaptationData
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_AdaptationData;
class UScriptStruct* FAdaptationData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_AdaptationData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_AdaptationData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAdaptationData, (UObject*)Z_Construct_UPackage__Script_EternalDescent(), TEXT("AdaptationData"));
	}
	return Z_Registration_Info_UScriptStruct_AdaptationData.OuterSingleton;
}
template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<FAdaptationData>()
{
	return FAdaptationData::StaticStruct();
}
struct Z_Construct_UScriptStruct_FAdaptationData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentFloor_MetaData[] = {
		{ "Category", "AdaptationData" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Within-run adaptation\n" },
#endif
		{ "ModuleRelativePath", "Public/ADASystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Within-run adaptation" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AdaptationStrength_MetaData[] = {
		{ "Category", "AdaptationData" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerStrategyCounters_MetaData[] = {
		{ "Category", "AdaptationData" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// 0-1, increases with floors\n" },
#endif
		{ "ModuleRelativePath", "Public/ADASystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "0-1, increases with floors" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalRunsAnalyzed_MetaData[] = {
		{ "Category", "AdaptationData" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Cross-run adaptation\n" },
#endif
		{ "ModuleRelativePath", "Public/ADASystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cross-run adaptation" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IdentifiedArchetype_MetaData[] = {
		{ "Category", "AdaptationData" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PatternHistory_MetaData[] = {
		{ "Category", "AdaptationData" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentFloor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AdaptationStrength;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlayerStrategyCounters_ValueProp;
	static const UECodeGen_Private::FStrPropertyParams NewProp_PlayerStrategyCounters_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_PlayerStrategyCounters;
	static const UECodeGen_Private::FIntPropertyParams NewProp_TotalRunsAnalyzed;
	static const UECodeGen_Private::FBytePropertyParams NewProp_IdentifiedArchetype_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_IdentifiedArchetype;
	static const UECodeGen_Private::FIntPropertyParams NewProp_PatternHistory_ValueProp;
	static const UECodeGen_Private::FStrPropertyParams NewProp_PatternHistory_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_PatternHistory;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAdaptationData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAdaptationData_Statics::NewProp_CurrentFloor = { "CurrentFloor", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAdaptationData, CurrentFloor), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentFloor_MetaData), NewProp_CurrentFloor_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAdaptationData_Statics::NewProp_AdaptationStrength = { "AdaptationStrength", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAdaptationData, AdaptationStrength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AdaptationStrength_MetaData), NewProp_AdaptationStrength_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAdaptationData_Statics::NewProp_PlayerStrategyCounters_ValueProp = { "PlayerStrategyCounters", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAdaptationData_Statics::NewProp_PlayerStrategyCounters_Key_KeyProp = { "PlayerStrategyCounters_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UScriptStruct_FAdaptationData_Statics::NewProp_PlayerStrategyCounters = { "PlayerStrategyCounters", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAdaptationData, PlayerStrategyCounters), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerStrategyCounters_MetaData), NewProp_PlayerStrategyCounters_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAdaptationData_Statics::NewProp_TotalRunsAnalyzed = { "TotalRunsAnalyzed", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAdaptationData, TotalRunsAnalyzed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalRunsAnalyzed_MetaData), NewProp_TotalRunsAnalyzed_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FAdaptationData_Statics::NewProp_IdentifiedArchetype_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FAdaptationData_Statics::NewProp_IdentifiedArchetype = { "IdentifiedArchetype", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAdaptationData, IdentifiedArchetype), Z_Construct_UEnum_EternalDescent_EPlayerArchetype, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IdentifiedArchetype_MetaData), NewProp_IdentifiedArchetype_MetaData) }; // 1287807750
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAdaptationData_Statics::NewProp_PatternHistory_ValueProp = { "PatternHistory", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAdaptationData_Statics::NewProp_PatternHistory_Key_KeyProp = { "PatternHistory_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UScriptStruct_FAdaptationData_Statics::NewProp_PatternHistory = { "PatternHistory", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAdaptationData, PatternHistory), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PatternHistory_MetaData), NewProp_PatternHistory_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAdaptationData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdaptationData_Statics::NewProp_CurrentFloor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdaptationData_Statics::NewProp_AdaptationStrength,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdaptationData_Statics::NewProp_PlayerStrategyCounters_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdaptationData_Statics::NewProp_PlayerStrategyCounters_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdaptationData_Statics::NewProp_PlayerStrategyCounters,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdaptationData_Statics::NewProp_TotalRunsAnalyzed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdaptationData_Statics::NewProp_IdentifiedArchetype_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdaptationData_Statics::NewProp_IdentifiedArchetype,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdaptationData_Statics::NewProp_PatternHistory_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdaptationData_Statics::NewProp_PatternHistory_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAdaptationData_Statics::NewProp_PatternHistory,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAdaptationData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAdaptationData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_EternalDescent,
	nullptr,
	&NewStructOps,
	"AdaptationData",
	Z_Construct_UScriptStruct_FAdaptationData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAdaptationData_Statics::PropPointers),
	sizeof(FAdaptationData),
	alignof(FAdaptationData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAdaptationData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FAdaptationData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FAdaptationData()
{
	if (!Z_Registration_Info_UScriptStruct_AdaptationData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_AdaptationData.InnerSingleton, Z_Construct_UScriptStruct_FAdaptationData_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_AdaptationData.InnerSingleton;
}
// End ScriptStruct FAdaptationData

// Begin Class AADASystem Function AdaptToPlayerStrategy
struct Z_Construct_UFunction_AADASystem_AdaptToPlayerStrategy_Statics
{
	struct ADASystem_eventAdaptToPlayerStrategy_Parms
	{
		FString StrategyName;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ADA|Adaptation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Adaptation Functions\n" },
#endif
		{ "ModuleRelativePath", "Public/ADASystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Adaptation Functions" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StrategyName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_StrategyName;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AADASystem_AdaptToPlayerStrategy_Statics::NewProp_StrategyName = { "StrategyName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADASystem_eventAdaptToPlayerStrategy_Parms, StrategyName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StrategyName_MetaData), NewProp_StrategyName_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AADASystem_AdaptToPlayerStrategy_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AADASystem_AdaptToPlayerStrategy_Statics::NewProp_StrategyName,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_AdaptToPlayerStrategy_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AADASystem_AdaptToPlayerStrategy_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AADASystem, nullptr, "AdaptToPlayerStrategy", nullptr, nullptr, Z_Construct_UFunction_AADASystem_AdaptToPlayerStrategy_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_AdaptToPlayerStrategy_Statics::PropPointers), sizeof(Z_Construct_UFunction_AADASystem_AdaptToPlayerStrategy_Statics::ADASystem_eventAdaptToPlayerStrategy_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_AdaptToPlayerStrategy_Statics::Function_MetaDataParams), Z_Construct_UFunction_AADASystem_AdaptToPlayerStrategy_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AADASystem_AdaptToPlayerStrategy_Statics::ADASystem_eventAdaptToPlayerStrategy_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AADASystem_AdaptToPlayerStrategy()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AADASystem_AdaptToPlayerStrategy_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AADASystem::execAdaptToPlayerStrategy)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_StrategyName);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AdaptToPlayerStrategy(Z_Param_StrategyName);
	P_NATIVE_END;
}
// End Class AADASystem Function AdaptToPlayerStrategy

// Begin Class AADASystem Function AnalyzePlayerBehavior
struct Z_Construct_UFunction_AADASystem_AnalyzePlayerBehavior_Statics
{
	struct ADASystem_eventAnalyzePlayerBehavior_Parms
	{
		FPlayerBehaviorData BehaviorData;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ADA" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BehaviorData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_BehaviorData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AADASystem_AnalyzePlayerBehavior_Statics::NewProp_BehaviorData = { "BehaviorData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADASystem_eventAnalyzePlayerBehavior_Parms, BehaviorData), Z_Construct_UScriptStruct_FPlayerBehaviorData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BehaviorData_MetaData), NewProp_BehaviorData_MetaData) }; // 1618455651
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AADASystem_AnalyzePlayerBehavior_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AADASystem_AnalyzePlayerBehavior_Statics::NewProp_BehaviorData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_AnalyzePlayerBehavior_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AADASystem_AnalyzePlayerBehavior_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AADASystem, nullptr, "AnalyzePlayerBehavior", nullptr, nullptr, Z_Construct_UFunction_AADASystem_AnalyzePlayerBehavior_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_AnalyzePlayerBehavior_Statics::PropPointers), sizeof(Z_Construct_UFunction_AADASystem_AnalyzePlayerBehavior_Statics::ADASystem_eventAnalyzePlayerBehavior_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_AnalyzePlayerBehavior_Statics::Function_MetaDataParams), Z_Construct_UFunction_AADASystem_AnalyzePlayerBehavior_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AADASystem_AnalyzePlayerBehavior_Statics::ADASystem_eventAnalyzePlayerBehavior_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AADASystem_AnalyzePlayerBehavior()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AADASystem_AnalyzePlayerBehavior_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AADASystem::execAnalyzePlayerBehavior)
{
	P_GET_STRUCT_REF(FPlayerBehaviorData,Z_Param_Out_BehaviorData);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AnalyzePlayerBehavior(Z_Param_Out_BehaviorData);
	P_NATIVE_END;
}
// End Class AADASystem Function AnalyzePlayerBehavior

// Begin Class AADASystem Function CalculateAdaptationStrength
struct Z_Construct_UFunction_AADASystem_CalculateAdaptationStrength_Statics
{
	struct ADASystem_eventCalculateAdaptationStrength_Parms
	{
		int32 FloorNumber;
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ADA|Adaptation" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_FloorNumber;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AADASystem_CalculateAdaptationStrength_Statics::NewProp_FloorNumber = { "FloorNumber", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADASystem_eventCalculateAdaptationStrength_Parms, FloorNumber), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AADASystem_CalculateAdaptationStrength_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADASystem_eventCalculateAdaptationStrength_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AADASystem_CalculateAdaptationStrength_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AADASystem_CalculateAdaptationStrength_Statics::NewProp_FloorNumber,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AADASystem_CalculateAdaptationStrength_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_CalculateAdaptationStrength_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AADASystem_CalculateAdaptationStrength_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AADASystem, nullptr, "CalculateAdaptationStrength", nullptr, nullptr, Z_Construct_UFunction_AADASystem_CalculateAdaptationStrength_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_CalculateAdaptationStrength_Statics::PropPointers), sizeof(Z_Construct_UFunction_AADASystem_CalculateAdaptationStrength_Statics::ADASystem_eventCalculateAdaptationStrength_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_CalculateAdaptationStrength_Statics::Function_MetaDataParams), Z_Construct_UFunction_AADASystem_CalculateAdaptationStrength_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AADASystem_CalculateAdaptationStrength_Statics::ADASystem_eventCalculateAdaptationStrength_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AADASystem_CalculateAdaptationStrength()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AADASystem_CalculateAdaptationStrength_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AADASystem::execCalculateAdaptationStrength)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_FloorNumber);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->CalculateAdaptationStrength(Z_Param_FloorNumber);
	P_NATIVE_END;
}
// End Class AADASystem Function CalculateAdaptationStrength

// Begin Class AADASystem Function DeterminePlayerArchetype
struct Z_Construct_UFunction_AADASystem_DeterminePlayerArchetype_Statics
{
	struct ADASystem_eventDeterminePlayerArchetype_Parms
	{
		EPlayerArchetype ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ADA" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_AADASystem_DeterminePlayerArchetype_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_AADASystem_DeterminePlayerArchetype_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADASystem_eventDeterminePlayerArchetype_Parms, ReturnValue), Z_Construct_UEnum_EternalDescent_EPlayerArchetype, METADATA_PARAMS(0, nullptr) }; // 1287807750
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AADASystem_DeterminePlayerArchetype_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AADASystem_DeterminePlayerArchetype_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AADASystem_DeterminePlayerArchetype_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_DeterminePlayerArchetype_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AADASystem_DeterminePlayerArchetype_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AADASystem, nullptr, "DeterminePlayerArchetype", nullptr, nullptr, Z_Construct_UFunction_AADASystem_DeterminePlayerArchetype_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_DeterminePlayerArchetype_Statics::PropPointers), sizeof(Z_Construct_UFunction_AADASystem_DeterminePlayerArchetype_Statics::ADASystem_eventDeterminePlayerArchetype_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_DeterminePlayerArchetype_Statics::Function_MetaDataParams), Z_Construct_UFunction_AADASystem_DeterminePlayerArchetype_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AADASystem_DeterminePlayerArchetype_Statics::ADASystem_eventDeterminePlayerArchetype_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AADASystem_DeterminePlayerArchetype()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AADASystem_DeterminePlayerArchetype_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AADASystem::execDeterminePlayerArchetype)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EPlayerArchetype*)Z_Param__Result=P_THIS->DeterminePlayerArchetype();
	P_NATIVE_END;
}
// End Class AADASystem Function DeterminePlayerArchetype

// Begin Class AADASystem Function GenerateContextualMessage
struct Z_Construct_UFunction_AADASystem_GenerateContextualMessage_Statics
{
	struct ADASystem_eventGenerateContextualMessage_Parms
	{
		FString Context;
		FADAMessage ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ADA|Communication" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Context_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_Context;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AADASystem_GenerateContextualMessage_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADASystem_eventGenerateContextualMessage_Parms, Context), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Context_MetaData), NewProp_Context_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AADASystem_GenerateContextualMessage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADASystem_eventGenerateContextualMessage_Parms, ReturnValue), Z_Construct_UScriptStruct_FADAMessage, METADATA_PARAMS(0, nullptr) }; // 1893948183
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AADASystem_GenerateContextualMessage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AADASystem_GenerateContextualMessage_Statics::NewProp_Context,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AADASystem_GenerateContextualMessage_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_GenerateContextualMessage_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AADASystem_GenerateContextualMessage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AADASystem, nullptr, "GenerateContextualMessage", nullptr, nullptr, Z_Construct_UFunction_AADASystem_GenerateContextualMessage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_GenerateContextualMessage_Statics::PropPointers), sizeof(Z_Construct_UFunction_AADASystem_GenerateContextualMessage_Statics::ADASystem_eventGenerateContextualMessage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_GenerateContextualMessage_Statics::Function_MetaDataParams), Z_Construct_UFunction_AADASystem_GenerateContextualMessage_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AADASystem_GenerateContextualMessage_Statics::ADASystem_eventGenerateContextualMessage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AADASystem_GenerateContextualMessage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AADASystem_GenerateContextualMessage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AADASystem::execGenerateContextualMessage)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Context);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FADAMessage*)Z_Param__Result=P_THIS->GenerateContextualMessage(Z_Param_Context);
	P_NATIVE_END;
}
// End Class AADASystem Function GenerateContextualMessage

// Begin Class AADASystem Function GenerateCounterStrategies
struct Z_Construct_UFunction_AADASystem_GenerateCounterStrategies_Statics
{
	struct ADASystem_eventGenerateCounterStrategies_Parms
	{
		TArray<FString> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ADA|Adaptation" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AADASystem_GenerateCounterStrategies_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AADASystem_GenerateCounterStrategies_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADASystem_eventGenerateCounterStrategies_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AADASystem_GenerateCounterStrategies_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AADASystem_GenerateCounterStrategies_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AADASystem_GenerateCounterStrategies_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_GenerateCounterStrategies_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AADASystem_GenerateCounterStrategies_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AADASystem, nullptr, "GenerateCounterStrategies", nullptr, nullptr, Z_Construct_UFunction_AADASystem_GenerateCounterStrategies_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_GenerateCounterStrategies_Statics::PropPointers), sizeof(Z_Construct_UFunction_AADASystem_GenerateCounterStrategies_Statics::ADASystem_eventGenerateCounterStrategies_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_GenerateCounterStrategies_Statics::Function_MetaDataParams), Z_Construct_UFunction_AADASystem_GenerateCounterStrategies_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AADASystem_GenerateCounterStrategies_Statics::ADASystem_eventGenerateCounterStrategies_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AADASystem_GenerateCounterStrategies()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AADASystem_GenerateCounterStrategies_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AADASystem::execGenerateCounterStrategies)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FString>*)Z_Param__Result=P_THIS->GenerateCounterStrategies();
	P_NATIVE_END;
}
// End Class AADASystem Function GenerateCounterStrategies

// Begin Class AADASystem Function GetMoodColor
struct Z_Construct_UFunction_AADASystem_GetMoodColor_Statics
{
	struct ADASystem_eventGetMoodColor_Parms
	{
		EADAMood Mood;
		FLinearColor ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ADA|Personality" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Entity Personality Functions\n" },
#endif
		{ "ModuleRelativePath", "Public/ADASystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Entity Personality Functions" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_Mood_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Mood;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_AADASystem_GetMoodColor_Statics::NewProp_Mood_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_AADASystem_GetMoodColor_Statics::NewProp_Mood = { "Mood", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADASystem_eventGetMoodColor_Parms, Mood), Z_Construct_UEnum_EternalDescent_EADAMood, METADATA_PARAMS(0, nullptr) }; // 3689353100
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AADASystem_GetMoodColor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADASystem_eventGetMoodColor_Parms, ReturnValue), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AADASystem_GetMoodColor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AADASystem_GetMoodColor_Statics::NewProp_Mood_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AADASystem_GetMoodColor_Statics::NewProp_Mood,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AADASystem_GetMoodColor_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_GetMoodColor_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AADASystem_GetMoodColor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AADASystem, nullptr, "GetMoodColor", nullptr, nullptr, Z_Construct_UFunction_AADASystem_GetMoodColor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_GetMoodColor_Statics::PropPointers), sizeof(Z_Construct_UFunction_AADASystem_GetMoodColor_Statics::ADASystem_eventGetMoodColor_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_GetMoodColor_Statics::Function_MetaDataParams), Z_Construct_UFunction_AADASystem_GetMoodColor_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AADASystem_GetMoodColor_Statics::ADASystem_eventGetMoodColor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AADASystem_GetMoodColor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AADASystem_GetMoodColor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AADASystem::execGetMoodColor)
{
	P_GET_ENUM(EADAMood,Z_Param_Mood);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FLinearColor*)Z_Param__Result=P_THIS->GetMoodColor(EADAMood(Z_Param_Mood));
	P_NATIVE_END;
}
// End Class AADASystem Function GetMoodColor

// Begin Class AADASystem Function GetPersonalityDescription
struct Z_Construct_UFunction_AADASystem_GetPersonalityDescription_Statics
{
	struct ADASystem_eventGetPersonalityDescription_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ADA|Personality" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AADASystem_GetPersonalityDescription_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADASystem_eventGetPersonalityDescription_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AADASystem_GetPersonalityDescription_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AADASystem_GetPersonalityDescription_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_GetPersonalityDescription_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AADASystem_GetPersonalityDescription_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AADASystem, nullptr, "GetPersonalityDescription", nullptr, nullptr, Z_Construct_UFunction_AADASystem_GetPersonalityDescription_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_GetPersonalityDescription_Statics::PropPointers), sizeof(Z_Construct_UFunction_AADASystem_GetPersonalityDescription_Statics::ADASystem_eventGetPersonalityDescription_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_GetPersonalityDescription_Statics::Function_MetaDataParams), Z_Construct_UFunction_AADASystem_GetPersonalityDescription_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AADASystem_GetPersonalityDescription_Statics::ADASystem_eventGetPersonalityDescription_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AADASystem_GetPersonalityDescription()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AADASystem_GetPersonalityDescription_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AADASystem::execGetPersonalityDescription)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->GetPersonalityDescription();
	P_NATIVE_END;
}
// End Class AADASystem Function GetPersonalityDescription

// Begin Class AADASystem Function InitializeADA
struct Z_Construct_UFunction_AADASystem_InitializeADA_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ADA" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Core ADA Functions\n" },
#endif
		{ "ModuleRelativePath", "Public/ADASystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Core ADA Functions" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AADASystem_InitializeADA_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AADASystem, nullptr, "InitializeADA", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_InitializeADA_Statics::Function_MetaDataParams), Z_Construct_UFunction_AADASystem_InitializeADA_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AADASystem_InitializeADA()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AADASystem_InitializeADA_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AADASystem::execInitializeADA)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitializeADA();
	P_NATIVE_END;
}
// End Class AADASystem Function InitializeADA

// Begin Class AADASystem Function InjectPsychologicalElements
struct Z_Construct_UFunction_AADASystem_InjectPsychologicalElements_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ADA|Dungeon" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AADASystem_InjectPsychologicalElements_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AADASystem, nullptr, "InjectPsychologicalElements", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_InjectPsychologicalElements_Statics::Function_MetaDataParams), Z_Construct_UFunction_AADASystem_InjectPsychologicalElements_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AADASystem_InjectPsychologicalElements()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AADASystem_InjectPsychologicalElements_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AADASystem::execInjectPsychologicalElements)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InjectPsychologicalElements();
	P_NATIVE_END;
}
// End Class AADASystem Function InjectPsychologicalElements

// Begin Class AADASystem Function LoadHistoricalData
struct Z_Construct_UFunction_AADASystem_LoadHistoricalData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ADA|Learning" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AADASystem_LoadHistoricalData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AADASystem, nullptr, "LoadHistoricalData", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_LoadHistoricalData_Statics::Function_MetaDataParams), Z_Construct_UFunction_AADASystem_LoadHistoricalData_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AADASystem_LoadHistoricalData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AADASystem_LoadHistoricalData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AADASystem::execLoadHistoricalData)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->LoadHistoricalData();
	P_NATIVE_END;
}
// End Class AADASystem Function LoadHistoricalData

// Begin Class AADASystem Function ModifyDungeonDifficulty
struct Z_Construct_UFunction_AADASystem_ModifyDungeonDifficulty_Statics
{
	struct ADASystem_eventModifyDungeonDifficulty_Parms
	{
		float DifficultyMultiplier;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ADA|Dungeon" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Dungeon Modification Functions\n" },
#endif
		{ "ModuleRelativePath", "Public/ADASystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Dungeon Modification Functions" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DifficultyMultiplier;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AADASystem_ModifyDungeonDifficulty_Statics::NewProp_DifficultyMultiplier = { "DifficultyMultiplier", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADASystem_eventModifyDungeonDifficulty_Parms, DifficultyMultiplier), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AADASystem_ModifyDungeonDifficulty_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AADASystem_ModifyDungeonDifficulty_Statics::NewProp_DifficultyMultiplier,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_ModifyDungeonDifficulty_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AADASystem_ModifyDungeonDifficulty_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AADASystem, nullptr, "ModifyDungeonDifficulty", nullptr, nullptr, Z_Construct_UFunction_AADASystem_ModifyDungeonDifficulty_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_ModifyDungeonDifficulty_Statics::PropPointers), sizeof(Z_Construct_UFunction_AADASystem_ModifyDungeonDifficulty_Statics::ADASystem_eventModifyDungeonDifficulty_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_ModifyDungeonDifficulty_Statics::Function_MetaDataParams), Z_Construct_UFunction_AADASystem_ModifyDungeonDifficulty_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AADASystem_ModifyDungeonDifficulty_Statics::ADASystem_eventModifyDungeonDifficulty_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AADASystem_ModifyDungeonDifficulty()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AADASystem_ModifyDungeonDifficulty_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AADASystem::execModifyDungeonDifficulty)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_DifficultyMultiplier);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ModifyDungeonDifficulty(Z_Param_DifficultyMultiplier);
	P_NATIVE_END;
}
// End Class AADASystem Function ModifyDungeonDifficulty

// Begin Class AADASystem Function OnMessageSent
struct ADASystem_eventOnMessageSent_Parms
{
	FADAMessage Message;
};
static const FName NAME_AADASystem_OnMessageSent = FName(TEXT("OnMessageSent"));
void AADASystem::OnMessageSent(FADAMessage const& Message)
{
	ADASystem_eventOnMessageSent_Parms Parms;
	Parms.Message=Message;
	UFunction* Func = FindFunctionChecked(NAME_AADASystem_OnMessageSent);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AADASystem_OnMessageSent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ADA|Communication" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Message;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AADASystem_OnMessageSent_Statics::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADASystem_eventOnMessageSent_Parms, Message), Z_Construct_UScriptStruct_FADAMessage, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Message_MetaData), NewProp_Message_MetaData) }; // 1893948183
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AADASystem_OnMessageSent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AADASystem_OnMessageSent_Statics::NewProp_Message,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_OnMessageSent_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AADASystem_OnMessageSent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AADASystem, nullptr, "OnMessageSent", nullptr, nullptr, Z_Construct_UFunction_AADASystem_OnMessageSent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_OnMessageSent_Statics::PropPointers), sizeof(ADASystem_eventOnMessageSent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_OnMessageSent_Statics::Function_MetaDataParams), Z_Construct_UFunction_AADASystem_OnMessageSent_Statics::Function_MetaDataParams) };
static_assert(sizeof(ADASystem_eventOnMessageSent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AADASystem_OnMessageSent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AADASystem_OnMessageSent_Statics::FuncParams);
	}
	return ReturnFunction;
}
// End Class AADASystem Function OnMessageSent

// Begin Class AADASystem Function ReactToPlayerAction
struct Z_Construct_UFunction_AADASystem_ReactToPlayerAction_Statics
{
	struct ADASystem_eventReactToPlayerAction_Parms
	{
		FString Action;
		bool bWasSuccessful;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ADA|Whimsy" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Action_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_Action;
	static void NewProp_bWasSuccessful_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bWasSuccessful;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AADASystem_ReactToPlayerAction_Statics::NewProp_Action = { "Action", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADASystem_eventReactToPlayerAction_Parms, Action), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Action_MetaData), NewProp_Action_MetaData) };
void Z_Construct_UFunction_AADASystem_ReactToPlayerAction_Statics::NewProp_bWasSuccessful_SetBit(void* Obj)
{
	((ADASystem_eventReactToPlayerAction_Parms*)Obj)->bWasSuccessful = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AADASystem_ReactToPlayerAction_Statics::NewProp_bWasSuccessful = { "bWasSuccessful", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ADASystem_eventReactToPlayerAction_Parms), &Z_Construct_UFunction_AADASystem_ReactToPlayerAction_Statics::NewProp_bWasSuccessful_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AADASystem_ReactToPlayerAction_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AADASystem_ReactToPlayerAction_Statics::NewProp_Action,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AADASystem_ReactToPlayerAction_Statics::NewProp_bWasSuccessful,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_ReactToPlayerAction_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AADASystem_ReactToPlayerAction_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AADASystem, nullptr, "ReactToPlayerAction", nullptr, nullptr, Z_Construct_UFunction_AADASystem_ReactToPlayerAction_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_ReactToPlayerAction_Statics::PropPointers), sizeof(Z_Construct_UFunction_AADASystem_ReactToPlayerAction_Statics::ADASystem_eventReactToPlayerAction_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_ReactToPlayerAction_Statics::Function_MetaDataParams), Z_Construct_UFunction_AADASystem_ReactToPlayerAction_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AADASystem_ReactToPlayerAction_Statics::ADASystem_eventReactToPlayerAction_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AADASystem_ReactToPlayerAction()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AADASystem_ReactToPlayerAction_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AADASystem::execReactToPlayerAction)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Action);
	P_GET_UBOOL(Z_Param_bWasSuccessful);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ReactToPlayerAction(Z_Param_Action,Z_Param_bWasSuccessful);
	P_NATIVE_END;
}
// End Class AADASystem Function ReactToPlayerAction

// Begin Class AADASystem Function RecordPlayerAction
struct Z_Construct_UFunction_AADASystem_RecordPlayerAction_Statics
{
	struct ADASystem_eventRecordPlayerAction_Parms
	{
		FString ActionType;
		float Value;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ADA|Learning" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Learning Functions\n" },
#endif
		{ "ModuleRelativePath", "Public/ADASystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Learning Functions" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActionType_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ActionType;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AADASystem_RecordPlayerAction_Statics::NewProp_ActionType = { "ActionType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADASystem_eventRecordPlayerAction_Parms, ActionType), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActionType_MetaData), NewProp_ActionType_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AADASystem_RecordPlayerAction_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADASystem_eventRecordPlayerAction_Parms, Value), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AADASystem_RecordPlayerAction_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AADASystem_RecordPlayerAction_Statics::NewProp_ActionType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AADASystem_RecordPlayerAction_Statics::NewProp_Value,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_RecordPlayerAction_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AADASystem_RecordPlayerAction_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AADASystem, nullptr, "RecordPlayerAction", nullptr, nullptr, Z_Construct_UFunction_AADASystem_RecordPlayerAction_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_RecordPlayerAction_Statics::PropPointers), sizeof(Z_Construct_UFunction_AADASystem_RecordPlayerAction_Statics::ADASystem_eventRecordPlayerAction_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_RecordPlayerAction_Statics::Function_MetaDataParams), Z_Construct_UFunction_AADASystem_RecordPlayerAction_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AADASystem_RecordPlayerAction_Statics::ADASystem_eventRecordPlayerAction_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AADASystem_RecordPlayerAction()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AADASystem_RecordPlayerAction_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AADASystem::execRecordPlayerAction)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_ActionType);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RecordPlayerAction(Z_Param_ActionType,Z_Param_Value);
	P_NATIVE_END;
}
// End Class AADASystem Function RecordPlayerAction

// Begin Class AADASystem Function SaveRunData
struct Z_Construct_UFunction_AADASystem_SaveRunData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ADA|Learning" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AADASystem_SaveRunData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AADASystem, nullptr, "SaveRunData", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_SaveRunData_Statics::Function_MetaDataParams), Z_Construct_UFunction_AADASystem_SaveRunData_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AADASystem_SaveRunData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AADASystem_SaveRunData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AADASystem::execSaveRunData)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SaveRunData();
	P_NATIVE_END;
}
// End Class AADASystem Function SaveRunData

// Begin Class AADASystem Function SelectEnemyTypes
struct Z_Construct_UFunction_AADASystem_SelectEnemyTypes_Statics
{
	struct ADASystem_eventSelectEnemyTypes_Parms
	{
		int32 FloorNumber;
		TArray<FString> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ADA|Dungeon" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_FloorNumber;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AADASystem_SelectEnemyTypes_Statics::NewProp_FloorNumber = { "FloorNumber", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADASystem_eventSelectEnemyTypes_Parms, FloorNumber), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AADASystem_SelectEnemyTypes_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AADASystem_SelectEnemyTypes_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADASystem_eventSelectEnemyTypes_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AADASystem_SelectEnemyTypes_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AADASystem_SelectEnemyTypes_Statics::NewProp_FloorNumber,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AADASystem_SelectEnemyTypes_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AADASystem_SelectEnemyTypes_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_SelectEnemyTypes_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AADASystem_SelectEnemyTypes_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AADASystem, nullptr, "SelectEnemyTypes", nullptr, nullptr, Z_Construct_UFunction_AADASystem_SelectEnemyTypes_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_SelectEnemyTypes_Statics::PropPointers), sizeof(Z_Construct_UFunction_AADASystem_SelectEnemyTypes_Statics::ADASystem_eventSelectEnemyTypes_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_SelectEnemyTypes_Statics::Function_MetaDataParams), Z_Construct_UFunction_AADASystem_SelectEnemyTypes_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AADASystem_SelectEnemyTypes_Statics::ADASystem_eventSelectEnemyTypes_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AADASystem_SelectEnemyTypes()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AADASystem_SelectEnemyTypes_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AADASystem::execSelectEnemyTypes)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_FloorNumber);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FString>*)Z_Param__Result=P_THIS->SelectEnemyTypes(Z_Param_FloorNumber);
	P_NATIVE_END;
}
// End Class AADASystem Function SelectEnemyTypes

// Begin Class AADASystem Function SendDeathMessage
struct Z_Construct_UFunction_AADASystem_SendDeathMessage_Statics
{
	struct ADASystem_eventSendDeathMessage_Parms
	{
		bool bWasCloseCall;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ADA|Whimsy" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Whimsical Features\n" },
#endif
		{ "CPP_Default_bWasCloseCall", "false" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whimsical Features" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_bWasCloseCall_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bWasCloseCall;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_AADASystem_SendDeathMessage_Statics::NewProp_bWasCloseCall_SetBit(void* Obj)
{
	((ADASystem_eventSendDeathMessage_Parms*)Obj)->bWasCloseCall = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AADASystem_SendDeathMessage_Statics::NewProp_bWasCloseCall = { "bWasCloseCall", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ADASystem_eventSendDeathMessage_Parms), &Z_Construct_UFunction_AADASystem_SendDeathMessage_Statics::NewProp_bWasCloseCall_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AADASystem_SendDeathMessage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AADASystem_SendDeathMessage_Statics::NewProp_bWasCloseCall,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_SendDeathMessage_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AADASystem_SendDeathMessage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AADASystem, nullptr, "SendDeathMessage", nullptr, nullptr, Z_Construct_UFunction_AADASystem_SendDeathMessage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_SendDeathMessage_Statics::PropPointers), sizeof(Z_Construct_UFunction_AADASystem_SendDeathMessage_Statics::ADASystem_eventSendDeathMessage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_SendDeathMessage_Statics::Function_MetaDataParams), Z_Construct_UFunction_AADASystem_SendDeathMessage_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AADASystem_SendDeathMessage_Statics::ADASystem_eventSendDeathMessage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AADASystem_SendDeathMessage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AADASystem_SendDeathMessage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AADASystem::execSendDeathMessage)
{
	P_GET_UBOOL(Z_Param_bWasCloseCall);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SendDeathMessage(Z_Param_bWasCloseCall);
	P_NATIVE_END;
}
// End Class AADASystem Function SendDeathMessage

// Begin Class AADASystem Function SendEncouragementMessage
struct Z_Construct_UFunction_AADASystem_SendEncouragementMessage_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ADA|Whimsy" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AADASystem_SendEncouragementMessage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AADASystem, nullptr, "SendEncouragementMessage", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_SendEncouragementMessage_Statics::Function_MetaDataParams), Z_Construct_UFunction_AADASystem_SendEncouragementMessage_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AADASystem_SendEncouragementMessage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AADASystem_SendEncouragementMessage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AADASystem::execSendEncouragementMessage)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SendEncouragementMessage();
	P_NATIVE_END;
}
// End Class AADASystem Function SendEncouragementMessage

// Begin Class AADASystem Function SendMemeMeMessage
struct Z_Construct_UFunction_AADASystem_SendMemeMeMessage_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ADA|EasterEggs" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AADASystem_SendMemeMeMessage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AADASystem, nullptr, "SendMemeMeMessage", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_SendMemeMeMessage_Statics::Function_MetaDataParams), Z_Construct_UFunction_AADASystem_SendMemeMeMessage_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AADASystem_SendMemeMeMessage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AADASystem_SendMemeMeMessage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AADASystem::execSendMemeMeMessage)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SendMemeMeMessage();
	P_NATIVE_END;
}
// End Class AADASystem Function SendMemeMeMessage

// Begin Class AADASystem Function SendMessage
struct Z_Construct_UFunction_AADASystem_SendMessage_Statics
{
	struct ADASystem_eventSendMessage_Parms
	{
		FString Message;
		EADAMood Mood;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ADA|Communication" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Communication Functions\n" },
#endif
		{ "CPP_Default_Mood", "Curious" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Communication Functions" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_Message;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Mood_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Mood;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AADASystem_SendMessage_Statics::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADASystem_eventSendMessage_Parms, Message), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Message_MetaData), NewProp_Message_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_AADASystem_SendMessage_Statics::NewProp_Mood_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_AADASystem_SendMessage_Statics::NewProp_Mood = { "Mood", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADASystem_eventSendMessage_Parms, Mood), Z_Construct_UEnum_EternalDescent_EADAMood, METADATA_PARAMS(0, nullptr) }; // 3689353100
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AADASystem_SendMessage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AADASystem_SendMessage_Statics::NewProp_Message,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AADASystem_SendMessage_Statics::NewProp_Mood_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AADASystem_SendMessage_Statics::NewProp_Mood,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_SendMessage_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AADASystem_SendMessage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AADASystem, nullptr, "SendMessage", nullptr, nullptr, Z_Construct_UFunction_AADASystem_SendMessage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_SendMessage_Statics::PropPointers), sizeof(Z_Construct_UFunction_AADASystem_SendMessage_Statics::ADASystem_eventSendMessage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_SendMessage_Statics::Function_MetaDataParams), Z_Construct_UFunction_AADASystem_SendMessage_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AADASystem_SendMessage_Statics::ADASystem_eventSendMessage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AADASystem_SendMessage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AADASystem_SendMessage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AADASystem::execSendMessage)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Message);
	P_GET_ENUM(EADAMood,Z_Param_Mood);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SendMessage(Z_Param_Message,EADAMood(Z_Param_Mood));
	P_NATIVE_END;
}
// End Class AADASystem Function SendMessage

// Begin Class AADASystem Function SendSuccessMessage
struct Z_Construct_UFunction_AADASystem_SendSuccessMessage_Statics
{
	struct ADASystem_eventSendSuccessMessage_Parms
	{
		bool bWasImpressive;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ADA|Whimsy" },
		{ "CPP_Default_bWasImpressive", "false" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bWasImpressive_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bWasImpressive;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_AADASystem_SendSuccessMessage_Statics::NewProp_bWasImpressive_SetBit(void* Obj)
{
	((ADASystem_eventSendSuccessMessage_Parms*)Obj)->bWasImpressive = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AADASystem_SendSuccessMessage_Statics::NewProp_bWasImpressive = { "bWasImpressive", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ADASystem_eventSendSuccessMessage_Parms), &Z_Construct_UFunction_AADASystem_SendSuccessMessage_Statics::NewProp_bWasImpressive_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AADASystem_SendSuccessMessage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AADASystem_SendSuccessMessage_Statics::NewProp_bWasImpressive,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_SendSuccessMessage_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AADASystem_SendSuccessMessage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AADASystem, nullptr, "SendSuccessMessage", nullptr, nullptr, Z_Construct_UFunction_AADASystem_SendSuccessMessage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_SendSuccessMessage_Statics::PropPointers), sizeof(Z_Construct_UFunction_AADASystem_SendSuccessMessage_Statics::ADASystem_eventSendSuccessMessage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_SendSuccessMessage_Statics::Function_MetaDataParams), Z_Construct_UFunction_AADASystem_SendSuccessMessage_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AADASystem_SendSuccessMessage_Statics::ADASystem_eventSendSuccessMessage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AADASystem_SendSuccessMessage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AADASystem_SendSuccessMessage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AADASystem::execSendSuccessMessage)
{
	P_GET_UBOOL(Z_Param_bWasImpressive);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SendSuccessMessage(Z_Param_bWasImpressive);
	P_NATIVE_END;
}
// End Class AADASystem Function SendSuccessMessage

// Begin Class AADASystem Function ShouldTriggerEasterEgg
struct Z_Construct_UFunction_AADASystem_ShouldTriggerEasterEgg_Statics
{
	struct ADASystem_eventShouldTriggerEasterEgg_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ADA|EasterEggs" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_AADASystem_ShouldTriggerEasterEgg_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ADASystem_eventShouldTriggerEasterEgg_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AADASystem_ShouldTriggerEasterEgg_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ADASystem_eventShouldTriggerEasterEgg_Parms), &Z_Construct_UFunction_AADASystem_ShouldTriggerEasterEgg_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AADASystem_ShouldTriggerEasterEgg_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AADASystem_ShouldTriggerEasterEgg_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_ShouldTriggerEasterEgg_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AADASystem_ShouldTriggerEasterEgg_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AADASystem, nullptr, "ShouldTriggerEasterEgg", nullptr, nullptr, Z_Construct_UFunction_AADASystem_ShouldTriggerEasterEgg_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_ShouldTriggerEasterEgg_Statics::PropPointers), sizeof(Z_Construct_UFunction_AADASystem_ShouldTriggerEasterEgg_Statics::ADASystem_eventShouldTriggerEasterEgg_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_ShouldTriggerEasterEgg_Statics::Function_MetaDataParams), Z_Construct_UFunction_AADASystem_ShouldTriggerEasterEgg_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AADASystem_ShouldTriggerEasterEgg_Statics::ADASystem_eventShouldTriggerEasterEgg_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AADASystem_ShouldTriggerEasterEgg()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AADASystem_ShouldTriggerEasterEgg_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AADASystem::execShouldTriggerEasterEgg)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ShouldTriggerEasterEgg();
	P_NATIVE_END;
}
// End Class AADASystem Function ShouldTriggerEasterEgg

// Begin Class AADASystem Function SpawnSurpriseRoom
struct Z_Construct_UFunction_AADASystem_SpawnSurpriseRoom_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ADA|EasterEggs" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AADASystem_SpawnSurpriseRoom_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AADASystem, nullptr, "SpawnSurpriseRoom", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_SpawnSurpriseRoom_Statics::Function_MetaDataParams), Z_Construct_UFunction_AADASystem_SpawnSurpriseRoom_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AADASystem_SpawnSurpriseRoom()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AADASystem_SpawnSurpriseRoom_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AADASystem::execSpawnSurpriseRoom)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SpawnSurpriseRoom();
	P_NATIVE_END;
}
// End Class AADASystem Function SpawnSurpriseRoom

// Begin Class AADASystem Function StartEncouragingPlayer
struct Z_Construct_UFunction_AADASystem_StartEncouragingPlayer_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ADA|Whimsy" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AADASystem_StartEncouragingPlayer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AADASystem, nullptr, "StartEncouragingPlayer", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_StartEncouragingPlayer_Statics::Function_MetaDataParams), Z_Construct_UFunction_AADASystem_StartEncouragingPlayer_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AADASystem_StartEncouragingPlayer()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AADASystem_StartEncouragingPlayer_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AADASystem::execStartEncouragingPlayer)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StartEncouragingPlayer();
	P_NATIVE_END;
}
// End Class AADASystem Function StartEncouragingPlayer

// Begin Class AADASystem Function TriggerRandomEasterEgg
struct Z_Construct_UFunction_AADASystem_TriggerRandomEasterEgg_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ADA|EasterEggs" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Whimsical Easter Egg Functions\n" },
#endif
		{ "ModuleRelativePath", "Public/ADASystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whimsical Easter Egg Functions" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AADASystem_TriggerRandomEasterEgg_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AADASystem, nullptr, "TriggerRandomEasterEgg", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_TriggerRandomEasterEgg_Statics::Function_MetaDataParams), Z_Construct_UFunction_AADASystem_TriggerRandomEasterEgg_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AADASystem_TriggerRandomEasterEgg()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AADASystem_TriggerRandomEasterEgg_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AADASystem::execTriggerRandomEasterEgg)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->TriggerRandomEasterEgg();
	P_NATIVE_END;
}
// End Class AADASystem Function TriggerRandomEasterEgg

// Begin Class AADASystem Function UpdateMoodBasedOnPerformance
struct Z_Construct_UFunction_AADASystem_UpdateMoodBasedOnPerformance_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ADA|Personality" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AADASystem_UpdateMoodBasedOnPerformance_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AADASystem, nullptr, "UpdateMoodBasedOnPerformance", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_UpdateMoodBasedOnPerformance_Statics::Function_MetaDataParams), Z_Construct_UFunction_AADASystem_UpdateMoodBasedOnPerformance_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AADASystem_UpdateMoodBasedOnPerformance()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AADASystem_UpdateMoodBasedOnPerformance_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AADASystem::execUpdateMoodBasedOnPerformance)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UpdateMoodBasedOnPerformance();
	P_NATIVE_END;
}
// End Class AADASystem Function UpdateMoodBasedOnPerformance

// Begin Class AADASystem Function UpdatePersonality
struct Z_Construct_UFunction_AADASystem_UpdatePersonality_Statics
{
	struct ADASystem_eventUpdatePersonality_Parms
	{
		int32 FloorNumber;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ADA" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_FloorNumber;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AADASystem_UpdatePersonality_Statics::NewProp_FloorNumber = { "FloorNumber", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADASystem_eventUpdatePersonality_Parms, FloorNumber), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AADASystem_UpdatePersonality_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AADASystem_UpdatePersonality_Statics::NewProp_FloorNumber,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_UpdatePersonality_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AADASystem_UpdatePersonality_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AADASystem, nullptr, "UpdatePersonality", nullptr, nullptr, Z_Construct_UFunction_AADASystem_UpdatePersonality_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_UpdatePersonality_Statics::PropPointers), sizeof(Z_Construct_UFunction_AADASystem_UpdatePersonality_Statics::ADASystem_eventUpdatePersonality_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AADASystem_UpdatePersonality_Statics::Function_MetaDataParams), Z_Construct_UFunction_AADASystem_UpdatePersonality_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AADASystem_UpdatePersonality_Statics::ADASystem_eventUpdatePersonality_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AADASystem_UpdatePersonality()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AADASystem_UpdatePersonality_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AADASystem::execUpdatePersonality)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_FloorNumber);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UpdatePersonality(Z_Param_FloorNumber);
	P_NATIVE_END;
}
// End Class AADASystem Function UpdatePersonality

// Begin Class AADASystem
void AADASystem::StaticRegisterNativesAADASystem()
{
	UClass* Class = AADASystem::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "AdaptToPlayerStrategy", &AADASystem::execAdaptToPlayerStrategy },
		{ "AnalyzePlayerBehavior", &AADASystem::execAnalyzePlayerBehavior },
		{ "CalculateAdaptationStrength", &AADASystem::execCalculateAdaptationStrength },
		{ "DeterminePlayerArchetype", &AADASystem::execDeterminePlayerArchetype },
		{ "GenerateContextualMessage", &AADASystem::execGenerateContextualMessage },
		{ "GenerateCounterStrategies", &AADASystem::execGenerateCounterStrategies },
		{ "GetMoodColor", &AADASystem::execGetMoodColor },
		{ "GetPersonalityDescription", &AADASystem::execGetPersonalityDescription },
		{ "InitializeADA", &AADASystem::execInitializeADA },
		{ "InjectPsychologicalElements", &AADASystem::execInjectPsychologicalElements },
		{ "LoadHistoricalData", &AADASystem::execLoadHistoricalData },
		{ "ModifyDungeonDifficulty", &AADASystem::execModifyDungeonDifficulty },
		{ "ReactToPlayerAction", &AADASystem::execReactToPlayerAction },
		{ "RecordPlayerAction", &AADASystem::execRecordPlayerAction },
		{ "SaveRunData", &AADASystem::execSaveRunData },
		{ "SelectEnemyTypes", &AADASystem::execSelectEnemyTypes },
		{ "SendDeathMessage", &AADASystem::execSendDeathMessage },
		{ "SendEncouragementMessage", &AADASystem::execSendEncouragementMessage },
		{ "SendMemeMeMessage", &AADASystem::execSendMemeMeMessage },
		{ "SendMessage", &AADASystem::execSendMessage },
		{ "SendSuccessMessage", &AADASystem::execSendSuccessMessage },
		{ "ShouldTriggerEasterEgg", &AADASystem::execShouldTriggerEasterEgg },
		{ "SpawnSurpriseRoom", &AADASystem::execSpawnSurpriseRoom },
		{ "StartEncouragingPlayer", &AADASystem::execStartEncouragingPlayer },
		{ "TriggerRandomEasterEgg", &AADASystem::execTriggerRandomEasterEgg },
		{ "UpdateMoodBasedOnPerformance", &AADASystem::execUpdateMoodBasedOnPerformance },
		{ "UpdatePersonality", &AADASystem::execUpdatePersonality },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AADASystem);
UClass* Z_Construct_UClass_AADASystem_NoRegister()
{
	return AADASystem::StaticClass();
}
struct Z_Construct_UClass_AADASystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "ADASystem.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentPersonality_MetaData[] = {
		{ "Category", "ADA" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Properties\n" },
#endif
		{ "ModuleRelativePath", "Public/ADASystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Properties" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentMood_MetaData[] = {
		{ "Category", "ADA" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentPlayerBehavior_MetaData[] = {
		{ "Category", "ADA" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AdaptationData_MetaData[] = {
		{ "Category", "ADA" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ObserverMessages_MetaData[] = {
		{ "Category", "ADA|Messages" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TesterMessages_MetaData[] = {
		{ "Category", "ADA|Messages" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CounterMessages_MetaData[] = {
		{ "Category", "ADA|Messages" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DominatorMessages_MetaData[] = {
		{ "Category", "ADA|Messages" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DeathMessages_MetaData[] = {
		{ "Category", "ADA|Messages" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NearDeathMessages_MetaData[] = {
		{ "Category", "ADA|Messages" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SuccessMessages_MetaData[] = {
		{ "Category", "ADA|Messages" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EncouragementMessages_MetaData[] = {
		{ "Category", "ADA|Messages" },
		{ "ModuleRelativePath", "Public/ADASystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_CurrentPersonality_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_CurrentPersonality;
	static const UECodeGen_Private::FBytePropertyParams NewProp_CurrentMood_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_CurrentMood;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CurrentPlayerBehavior;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AdaptationData;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ObserverMessages_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ObserverMessages;
	static const UECodeGen_Private::FStrPropertyParams NewProp_TesterMessages_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_TesterMessages;
	static const UECodeGen_Private::FStrPropertyParams NewProp_CounterMessages_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_CounterMessages;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DominatorMessages_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_DominatorMessages;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DeathMessages_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_DeathMessages;
	static const UECodeGen_Private::FStrPropertyParams NewProp_NearDeathMessages_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_NearDeathMessages;
	static const UECodeGen_Private::FStrPropertyParams NewProp_SuccessMessages_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_SuccessMessages;
	static const UECodeGen_Private::FStrPropertyParams NewProp_EncouragementMessages_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_EncouragementMessages;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AADASystem_AdaptToPlayerStrategy, "AdaptToPlayerStrategy" }, // 1845974128
		{ &Z_Construct_UFunction_AADASystem_AnalyzePlayerBehavior, "AnalyzePlayerBehavior" }, // 3549804220
		{ &Z_Construct_UFunction_AADASystem_CalculateAdaptationStrength, "CalculateAdaptationStrength" }, // 1658607322
		{ &Z_Construct_UFunction_AADASystem_DeterminePlayerArchetype, "DeterminePlayerArchetype" }, // 2355189109
		{ &Z_Construct_UFunction_AADASystem_GenerateContextualMessage, "GenerateContextualMessage" }, // 995891203
		{ &Z_Construct_UFunction_AADASystem_GenerateCounterStrategies, "GenerateCounterStrategies" }, // 3285641365
		{ &Z_Construct_UFunction_AADASystem_GetMoodColor, "GetMoodColor" }, // 747130151
		{ &Z_Construct_UFunction_AADASystem_GetPersonalityDescription, "GetPersonalityDescription" }, // 3673627347
		{ &Z_Construct_UFunction_AADASystem_InitializeADA, "InitializeADA" }, // 4205417788
		{ &Z_Construct_UFunction_AADASystem_InjectPsychologicalElements, "InjectPsychologicalElements" }, // 3766110289
		{ &Z_Construct_UFunction_AADASystem_LoadHistoricalData, "LoadHistoricalData" }, // 4081047698
		{ &Z_Construct_UFunction_AADASystem_ModifyDungeonDifficulty, "ModifyDungeonDifficulty" }, // 3540333334
		{ &Z_Construct_UFunction_AADASystem_OnMessageSent, "OnMessageSent" }, // 1654335888
		{ &Z_Construct_UFunction_AADASystem_ReactToPlayerAction, "ReactToPlayerAction" }, // 2678191886
		{ &Z_Construct_UFunction_AADASystem_RecordPlayerAction, "RecordPlayerAction" }, // 1381428216
		{ &Z_Construct_UFunction_AADASystem_SaveRunData, "SaveRunData" }, // 962634794
		{ &Z_Construct_UFunction_AADASystem_SelectEnemyTypes, "SelectEnemyTypes" }, // 650347073
		{ &Z_Construct_UFunction_AADASystem_SendDeathMessage, "SendDeathMessage" }, // 3494378651
		{ &Z_Construct_UFunction_AADASystem_SendEncouragementMessage, "SendEncouragementMessage" }, // 1935385047
		{ &Z_Construct_UFunction_AADASystem_SendMemeMeMessage, "SendMemeMeMessage" }, // 1367635839
		{ &Z_Construct_UFunction_AADASystem_SendMessage, "SendMessage" }, // 686393597
		{ &Z_Construct_UFunction_AADASystem_SendSuccessMessage, "SendSuccessMessage" }, // 2351069195
		{ &Z_Construct_UFunction_AADASystem_ShouldTriggerEasterEgg, "ShouldTriggerEasterEgg" }, // 4063608325
		{ &Z_Construct_UFunction_AADASystem_SpawnSurpriseRoom, "SpawnSurpriseRoom" }, // 3799334361
		{ &Z_Construct_UFunction_AADASystem_StartEncouragingPlayer, "StartEncouragingPlayer" }, // 1255260157
		{ &Z_Construct_UFunction_AADASystem_TriggerRandomEasterEgg, "TriggerRandomEasterEgg" }, // 4068450556
		{ &Z_Construct_UFunction_AADASystem_UpdateMoodBasedOnPerformance, "UpdateMoodBasedOnPerformance" }, // 1770280144
		{ &Z_Construct_UFunction_AADASystem_UpdatePersonality, "UpdatePersonality" }, // 1851693599
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AADASystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_AADASystem_Statics::NewProp_CurrentPersonality_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AADASystem_Statics::NewProp_CurrentPersonality = { "CurrentPersonality", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AADASystem, CurrentPersonality), Z_Construct_UEnum_EternalDescent_EADAPersonality, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentPersonality_MetaData), NewProp_CurrentPersonality_MetaData) }; // 3950714747
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_AADASystem_Statics::NewProp_CurrentMood_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AADASystem_Statics::NewProp_CurrentMood = { "CurrentMood", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AADASystem, CurrentMood), Z_Construct_UEnum_EternalDescent_EADAMood, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentMood_MetaData), NewProp_CurrentMood_MetaData) }; // 3689353100
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AADASystem_Statics::NewProp_CurrentPlayerBehavior = { "CurrentPlayerBehavior", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AADASystem, CurrentPlayerBehavior), Z_Construct_UScriptStruct_FPlayerBehaviorData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentPlayerBehavior_MetaData), NewProp_CurrentPlayerBehavior_MetaData) }; // 1618455651
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AADASystem_Statics::NewProp_AdaptationData = { "AdaptationData", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AADASystem, AdaptationData), Z_Construct_UScriptStruct_FAdaptationData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AdaptationData_MetaData), NewProp_AdaptationData_MetaData) }; // 134822572
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_AADASystem_Statics::NewProp_ObserverMessages_Inner = { "ObserverMessages", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AADASystem_Statics::NewProp_ObserverMessages = { "ObserverMessages", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AADASystem, ObserverMessages), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ObserverMessages_MetaData), NewProp_ObserverMessages_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_AADASystem_Statics::NewProp_TesterMessages_Inner = { "TesterMessages", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AADASystem_Statics::NewProp_TesterMessages = { "TesterMessages", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AADASystem, TesterMessages), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TesterMessages_MetaData), NewProp_TesterMessages_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_AADASystem_Statics::NewProp_CounterMessages_Inner = { "CounterMessages", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AADASystem_Statics::NewProp_CounterMessages = { "CounterMessages", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AADASystem, CounterMessages), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CounterMessages_MetaData), NewProp_CounterMessages_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_AADASystem_Statics::NewProp_DominatorMessages_Inner = { "DominatorMessages", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AADASystem_Statics::NewProp_DominatorMessages = { "DominatorMessages", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AADASystem, DominatorMessages), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DominatorMessages_MetaData), NewProp_DominatorMessages_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_AADASystem_Statics::NewProp_DeathMessages_Inner = { "DeathMessages", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AADASystem_Statics::NewProp_DeathMessages = { "DeathMessages", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AADASystem, DeathMessages), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DeathMessages_MetaData), NewProp_DeathMessages_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_AADASystem_Statics::NewProp_NearDeathMessages_Inner = { "NearDeathMessages", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AADASystem_Statics::NewProp_NearDeathMessages = { "NearDeathMessages", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AADASystem, NearDeathMessages), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NearDeathMessages_MetaData), NewProp_NearDeathMessages_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_AADASystem_Statics::NewProp_SuccessMessages_Inner = { "SuccessMessages", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AADASystem_Statics::NewProp_SuccessMessages = { "SuccessMessages", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AADASystem, SuccessMessages), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SuccessMessages_MetaData), NewProp_SuccessMessages_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_AADASystem_Statics::NewProp_EncouragementMessages_Inner = { "EncouragementMessages", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AADASystem_Statics::NewProp_EncouragementMessages = { "EncouragementMessages", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AADASystem, EncouragementMessages), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EncouragementMessages_MetaData), NewProp_EncouragementMessages_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AADASystem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AADASystem_Statics::NewProp_CurrentPersonality_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AADASystem_Statics::NewProp_CurrentPersonality,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AADASystem_Statics::NewProp_CurrentMood_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AADASystem_Statics::NewProp_CurrentMood,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AADASystem_Statics::NewProp_CurrentPlayerBehavior,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AADASystem_Statics::NewProp_AdaptationData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AADASystem_Statics::NewProp_ObserverMessages_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AADASystem_Statics::NewProp_ObserverMessages,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AADASystem_Statics::NewProp_TesterMessages_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AADASystem_Statics::NewProp_TesterMessages,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AADASystem_Statics::NewProp_CounterMessages_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AADASystem_Statics::NewProp_CounterMessages,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AADASystem_Statics::NewProp_DominatorMessages_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AADASystem_Statics::NewProp_DominatorMessages,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AADASystem_Statics::NewProp_DeathMessages_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AADASystem_Statics::NewProp_DeathMessages,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AADASystem_Statics::NewProp_NearDeathMessages_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AADASystem_Statics::NewProp_NearDeathMessages,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AADASystem_Statics::NewProp_SuccessMessages_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AADASystem_Statics::NewProp_SuccessMessages,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AADASystem_Statics::NewProp_EncouragementMessages_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AADASystem_Statics::NewProp_EncouragementMessages,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AADASystem_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AADASystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_EternalDescent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AADASystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AADASystem_Statics::ClassParams = {
	&AADASystem::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AADASystem_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AADASystem_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AADASystem_Statics::Class_MetaDataParams), Z_Construct_UClass_AADASystem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AADASystem()
{
	if (!Z_Registration_Info_UClass_AADASystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AADASystem.OuterSingleton, Z_Construct_UClass_AADASystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AADASystem.OuterSingleton;
}
template<> ETERNALDESCENT_API UClass* StaticClass<AADASystem>()
{
	return AADASystem::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AADASystem);
AADASystem::~AADASystem() {}
// End Class AADASystem

// Begin Registration
struct Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_ADASystem_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EADAPersonality_StaticEnum, TEXT("EADAPersonality"), &Z_Registration_Info_UEnum_EADAPersonality, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3950714747U) },
		{ EADAMood_StaticEnum, TEXT("EADAMood"), &Z_Registration_Info_UEnum_EADAMood, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3689353100U) },
		{ EPlayerArchetype_StaticEnum, TEXT("EPlayerArchetype"), &Z_Registration_Info_UEnum_EPlayerArchetype, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1287807750U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FPlayerBehaviorData::StaticStruct, Z_Construct_UScriptStruct_FPlayerBehaviorData_Statics::NewStructOps, TEXT("PlayerBehaviorData"), &Z_Registration_Info_UScriptStruct_PlayerBehaviorData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPlayerBehaviorData), 1618455651U) },
		{ FADAMessage::StaticStruct, Z_Construct_UScriptStruct_FADAMessage_Statics::NewStructOps, TEXT("ADAMessage"), &Z_Registration_Info_UScriptStruct_ADAMessage, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FADAMessage), 1893948183U) },
		{ FAdaptationData::StaticStruct, Z_Construct_UScriptStruct_FAdaptationData_Statics::NewStructOps, TEXT("AdaptationData"), &Z_Registration_Info_UScriptStruct_AdaptationData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAdaptationData), 134822572U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AADASystem, AADASystem::StaticClass, TEXT("AADASystem"), &Z_Registration_Info_UClass_AADASystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AADASystem), 2143415200U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_ADASystem_h_1955550723(TEXT("/Script/EternalDescent"),
	Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_ADASystem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_ADASystem_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_ADASystem_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_ADASystem_h_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_ADASystem_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_ADASystem_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
