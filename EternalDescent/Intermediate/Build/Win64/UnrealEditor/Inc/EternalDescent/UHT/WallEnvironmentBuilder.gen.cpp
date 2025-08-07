// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EternalDescent/Public/Generation/WallEnvironmentBuilder.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWallEnvironmentBuilder() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
ETERNALDESCENT_API UClass* Z_Construct_UClass_UWallEnvironmentBuilder();
ETERNALDESCENT_API UClass* Z_Construct_UClass_UWallEnvironmentBuilder_NoRegister();
UPackage* Z_Construct_UPackage__Script_EternalDescent();
// End Cross Module References

// Begin Class UWallEnvironmentBuilder
void UWallEnvironmentBuilder::StaticRegisterNativesUWallEnvironmentBuilder()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UWallEnvironmentBuilder);
UClass* Z_Construct_UClass_UWallEnvironmentBuilder_NoRegister()
{
	return UWallEnvironmentBuilder::StaticClass();
}
struct Z_Construct_UClass_UWallEnvironmentBuilder_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Generation/WallEnvironmentBuilder.h" },
		{ "ModuleRelativePath", "Public/Generation/WallEnvironmentBuilder.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UWallEnvironmentBuilder>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UWallEnvironmentBuilder_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_EternalDescent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UWallEnvironmentBuilder_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UWallEnvironmentBuilder_Statics::ClassParams = {
	&UWallEnvironmentBuilder::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UWallEnvironmentBuilder_Statics::Class_MetaDataParams), Z_Construct_UClass_UWallEnvironmentBuilder_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UWallEnvironmentBuilder()
{
	if (!Z_Registration_Info_UClass_UWallEnvironmentBuilder.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UWallEnvironmentBuilder.OuterSingleton, Z_Construct_UClass_UWallEnvironmentBuilder_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UWallEnvironmentBuilder.OuterSingleton;
}
template<> ETERNALDESCENT_API UClass* StaticClass<UWallEnvironmentBuilder>()
{
	return UWallEnvironmentBuilder::StaticClass();
}
UWallEnvironmentBuilder::UWallEnvironmentBuilder(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UWallEnvironmentBuilder);
UWallEnvironmentBuilder::~UWallEnvironmentBuilder() {}
// End Class UWallEnvironmentBuilder

// Begin Registration
struct Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_Generation_WallEnvironmentBuilder_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UWallEnvironmentBuilder, UWallEnvironmentBuilder::StaticClass, TEXT("UWallEnvironmentBuilder"), &Z_Registration_Info_UClass_UWallEnvironmentBuilder, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UWallEnvironmentBuilder), 2931521223U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_Generation_WallEnvironmentBuilder_h_3296862383(TEXT("/Script/EternalDescent"),
	Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_Generation_WallEnvironmentBuilder_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_Generation_WallEnvironmentBuilder_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
