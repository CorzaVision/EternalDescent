// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EternalDescent/Public/DungeonGenerator.h"
#include "EternalDescent/Public/Tests/DungeonTestTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDungeonGenerator() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
ETERNALDESCENT_API UClass* Z_Construct_UClass_ADungeonGenerator();
ETERNALDESCENT_API UClass* Z_Construct_UClass_ADungeonGenerator_NoRegister();
ETERNALDESCENT_API UEnum* Z_Construct_UEnum_EternalDescent_EDungeonZone();
ETERNALDESCENT_API UScriptStruct* Z_Construct_UScriptStruct_FDungeonLayout();
ETERNALDESCENT_API UScriptStruct* Z_Construct_UScriptStruct_FEntityProfile();
UPackage* Z_Construct_UPackage__Script_EternalDescent();
// End Cross Module References

// Begin Class ADungeonGenerator Function GenerateFloor
struct Z_Construct_UFunction_ADungeonGenerator_GenerateFloor_Statics
{
	struct DungeonGenerator_eventGenerateFloor_Parms
	{
		int32 FloorNumber;
		FDungeonLayout ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dungeon Generation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Core generation functions\n" },
#endif
		{ "ModuleRelativePath", "Public/DungeonGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Core generation functions" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_FloorNumber;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ADungeonGenerator_GenerateFloor_Statics::NewProp_FloorNumber = { "FloorNumber", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DungeonGenerator_eventGenerateFloor_Parms, FloorNumber), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ADungeonGenerator_GenerateFloor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DungeonGenerator_eventGenerateFloor_Parms, ReturnValue), Z_Construct_UScriptStruct_FDungeonLayout, METADATA_PARAMS(0, nullptr) }; // 3903890264
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADungeonGenerator_GenerateFloor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADungeonGenerator_GenerateFloor_Statics::NewProp_FloorNumber,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADungeonGenerator_GenerateFloor_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonGenerator_GenerateFloor_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADungeonGenerator_GenerateFloor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADungeonGenerator, nullptr, "GenerateFloor", nullptr, nullptr, Z_Construct_UFunction_ADungeonGenerator_GenerateFloor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonGenerator_GenerateFloor_Statics::PropPointers), sizeof(Z_Construct_UFunction_ADungeonGenerator_GenerateFloor_Statics::DungeonGenerator_eventGenerateFloor_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonGenerator_GenerateFloor_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADungeonGenerator_GenerateFloor_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ADungeonGenerator_GenerateFloor_Statics::DungeonGenerator_eventGenerateFloor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADungeonGenerator_GenerateFloor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADungeonGenerator_GenerateFloor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ADungeonGenerator::execGenerateFloor)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_FloorNumber);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FDungeonLayout*)Z_Param__Result=P_THIS->GenerateFloor(Z_Param_FloorNumber);
	P_NATIVE_END;
}
// End Class ADungeonGenerator Function GenerateFloor

// Begin Class ADungeonGenerator Function SetActiveZone
struct Z_Construct_UFunction_ADungeonGenerator_SetActiveZone_Statics
{
	struct DungeonGenerator_eventSetActiveZone_Parms
	{
		EDungeonZone Zone;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dungeon Generation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Configuration\n" },
#endif
		{ "ModuleRelativePath", "Public/DungeonGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Configuration" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_Zone_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Zone;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_ADungeonGenerator_SetActiveZone_Statics::NewProp_Zone_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_ADungeonGenerator_SetActiveZone_Statics::NewProp_Zone = { "Zone", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DungeonGenerator_eventSetActiveZone_Parms, Zone), Z_Construct_UEnum_EternalDescent_EDungeonZone, METADATA_PARAMS(0, nullptr) }; // 1899664273
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADungeonGenerator_SetActiveZone_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADungeonGenerator_SetActiveZone_Statics::NewProp_Zone_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADungeonGenerator_SetActiveZone_Statics::NewProp_Zone,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonGenerator_SetActiveZone_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADungeonGenerator_SetActiveZone_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADungeonGenerator, nullptr, "SetActiveZone", nullptr, nullptr, Z_Construct_UFunction_ADungeonGenerator_SetActiveZone_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonGenerator_SetActiveZone_Statics::PropPointers), sizeof(Z_Construct_UFunction_ADungeonGenerator_SetActiveZone_Statics::DungeonGenerator_eventSetActiveZone_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonGenerator_SetActiveZone_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADungeonGenerator_SetActiveZone_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ADungeonGenerator_SetActiveZone_Statics::DungeonGenerator_eventSetActiveZone_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADungeonGenerator_SetActiveZone()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADungeonGenerator_SetActiveZone_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ADungeonGenerator::execSetActiveZone)
{
	P_GET_ENUM(EDungeonZone,Z_Param_Zone);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetActiveZone(EDungeonZone(Z_Param_Zone));
	P_NATIVE_END;
}
// End Class ADungeonGenerator Function SetActiveZone

// Begin Class ADungeonGenerator Function SetEntityProfile
struct Z_Construct_UFunction_ADungeonGenerator_SetEntityProfile_Statics
{
	struct DungeonGenerator_eventSetEntityProfile_Parms
	{
		FEntityProfile Profile;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dungeon Generation" },
		{ "ModuleRelativePath", "Public/DungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Profile_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Profile;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ADungeonGenerator_SetEntityProfile_Statics::NewProp_Profile = { "Profile", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DungeonGenerator_eventSetEntityProfile_Parms, Profile), Z_Construct_UScriptStruct_FEntityProfile, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Profile_MetaData), NewProp_Profile_MetaData) }; // 2813654246
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADungeonGenerator_SetEntityProfile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADungeonGenerator_SetEntityProfile_Statics::NewProp_Profile,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonGenerator_SetEntityProfile_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADungeonGenerator_SetEntityProfile_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADungeonGenerator, nullptr, "SetEntityProfile", nullptr, nullptr, Z_Construct_UFunction_ADungeonGenerator_SetEntityProfile_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonGenerator_SetEntityProfile_Statics::PropPointers), sizeof(Z_Construct_UFunction_ADungeonGenerator_SetEntityProfile_Statics::DungeonGenerator_eventSetEntityProfile_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonGenerator_SetEntityProfile_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADungeonGenerator_SetEntityProfile_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ADungeonGenerator_SetEntityProfile_Statics::DungeonGenerator_eventSetEntityProfile_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADungeonGenerator_SetEntityProfile()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADungeonGenerator_SetEntityProfile_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ADungeonGenerator::execSetEntityProfile)
{
	P_GET_STRUCT_REF(FEntityProfile,Z_Param_Out_Profile);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetEntityProfile(Z_Param_Out_Profile);
	P_NATIVE_END;
}
// End Class ADungeonGenerator Function SetEntityProfile

// Begin Class ADungeonGenerator
void ADungeonGenerator::StaticRegisterNativesADungeonGenerator()
{
	UClass* Class = ADungeonGenerator::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GenerateFloor", &ADungeonGenerator::execGenerateFloor },
		{ "SetActiveZone", &ADungeonGenerator::execSetActiveZone },
		{ "SetEntityProfile", &ADungeonGenerator::execSetEntityProfile },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ADungeonGenerator);
UClass* Z_Construct_UClass_ADungeonGenerator_NoRegister()
{
	return ADungeonGenerator::StaticClass();
}
struct Z_Construct_UClass_ADungeonGenerator_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "DungeonGenerator.h" },
		{ "ModuleRelativePath", "Public/DungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentZone_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Current configuration\n" },
#endif
		{ "ModuleRelativePath", "Public/DungeonGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current configuration" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EntityProfile_MetaData[] = {
		{ "ModuleRelativePath", "Public/DungeonGenerator.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_CurrentZone_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_CurrentZone;
	static const UECodeGen_Private::FStructPropertyParams NewProp_EntityProfile;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ADungeonGenerator_GenerateFloor, "GenerateFloor" }, // 745434727
		{ &Z_Construct_UFunction_ADungeonGenerator_SetActiveZone, "SetActiveZone" }, // 2433911117
		{ &Z_Construct_UFunction_ADungeonGenerator_SetEntityProfile, "SetEntityProfile" }, // 772888234
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADungeonGenerator>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_ADungeonGenerator_Statics::NewProp_CurrentZone_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_ADungeonGenerator_Statics::NewProp_CurrentZone = { "CurrentZone", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADungeonGenerator, CurrentZone), Z_Construct_UEnum_EternalDescent_EDungeonZone, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentZone_MetaData), NewProp_CurrentZone_MetaData) }; // 1899664273
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ADungeonGenerator_Statics::NewProp_EntityProfile = { "EntityProfile", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADungeonGenerator, EntityProfile), Z_Construct_UScriptStruct_FEntityProfile, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EntityProfile_MetaData), NewProp_EntityProfile_MetaData) }; // 2813654246
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ADungeonGenerator_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADungeonGenerator_Statics::NewProp_CurrentZone_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADungeonGenerator_Statics::NewProp_CurrentZone,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADungeonGenerator_Statics::NewProp_EntityProfile,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ADungeonGenerator_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ADungeonGenerator_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_EternalDescent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ADungeonGenerator_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ADungeonGenerator_Statics::ClassParams = {
	&ADungeonGenerator::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ADungeonGenerator_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ADungeonGenerator_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ADungeonGenerator_Statics::Class_MetaDataParams), Z_Construct_UClass_ADungeonGenerator_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ADungeonGenerator()
{
	if (!Z_Registration_Info_UClass_ADungeonGenerator.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADungeonGenerator.OuterSingleton, Z_Construct_UClass_ADungeonGenerator_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ADungeonGenerator.OuterSingleton;
}
template<> ETERNALDESCENT_API UClass* StaticClass<ADungeonGenerator>()
{
	return ADungeonGenerator::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ADungeonGenerator);
ADungeonGenerator::~ADungeonGenerator() {}
// End Class ADungeonGenerator

// Begin Registration
struct Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_DungeonGenerator_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ADungeonGenerator, ADungeonGenerator::StaticClass, TEXT("ADungeonGenerator"), &Z_Registration_Info_UClass_ADungeonGenerator, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADungeonGenerator), 358511169U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_DungeonGenerator_h_681496230(TEXT("/Script/EternalDescent"),
	Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_DungeonGenerator_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_DungeonGenerator_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
