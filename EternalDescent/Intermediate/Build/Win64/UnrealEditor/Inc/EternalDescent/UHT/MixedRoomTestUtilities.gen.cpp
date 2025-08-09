// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EternalDescent/Private/Tests/MixedRoomTestUtilities.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMixedRoomTestUtilities() {}

// Begin Cross Module References
ETERNALDESCENT_API UScriptStruct* Z_Construct_UScriptStruct_FMixedRoomAnalysis();
UPackage* Z_Construct_UPackage__Script_EternalDescent();
// End Cross Module References

// Begin ScriptStruct FMixedRoomAnalysis
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_MixedRoomAnalysis;
class UScriptStruct* FMixedRoomAnalysis::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_MixedRoomAnalysis.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_MixedRoomAnalysis.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FMixedRoomAnalysis, (UObject*)Z_Construct_UPackage__Script_EternalDescent(), TEXT("MixedRoomAnalysis"));
	}
	return Z_Registration_Info_UScriptStruct_MixedRoomAnalysis.OuterSingleton;
}
template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<FMixedRoomAnalysis>()
{
	return FMixedRoomAnalysis::StaticStruct();
}
struct Z_Construct_UScriptStruct_FMixedRoomAnalysis_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Analysis structure for mixed room size generation - MUST be outside preprocessor blocks\n" },
#endif
		{ "ModuleRelativePath", "Private/Tests/MixedRoomTestUtilities.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Analysis structure for mixed room size generation - MUST be outside preprocessor blocks" },
#endif
	};
#endif // WITH_METADATA
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMixedRoomAnalysis>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMixedRoomAnalysis_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_EternalDescent,
	nullptr,
	&NewStructOps,
	"MixedRoomAnalysis",
	nullptr,
	0,
	sizeof(FMixedRoomAnalysis),
	alignof(FMixedRoomAnalysis),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMixedRoomAnalysis_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FMixedRoomAnalysis_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FMixedRoomAnalysis()
{
	if (!Z_Registration_Info_UScriptStruct_MixedRoomAnalysis.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_MixedRoomAnalysis.InnerSingleton, Z_Construct_UScriptStruct_FMixedRoomAnalysis_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_MixedRoomAnalysis.InnerSingleton;
}
// End ScriptStruct FMixedRoomAnalysis

// Begin Registration
struct Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Private_Tests_MixedRoomTestUtilities_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FMixedRoomAnalysis::StaticStruct, Z_Construct_UScriptStruct_FMixedRoomAnalysis_Statics::NewStructOps, TEXT("MixedRoomAnalysis"), &Z_Registration_Info_UScriptStruct_MixedRoomAnalysis, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FMixedRoomAnalysis), 636889938U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Private_Tests_MixedRoomTestUtilities_h_2333258868(TEXT("/Script/EternalDescent"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Private_Tests_MixedRoomTestUtilities_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Private_Tests_MixedRoomTestUtilities_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
