// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EternalDescent/Public/Generation/RoomGraphBuilder.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRoomGraphBuilder() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
ETERNALDESCENT_API UClass* Z_Construct_UClass_URoomGraphBuilder();
ETERNALDESCENT_API UClass* Z_Construct_UClass_URoomGraphBuilder_NoRegister();
UPackage* Z_Construct_UPackage__Script_EternalDescent();
// End Cross Module References

// Begin Class URoomGraphBuilder
void URoomGraphBuilder::StaticRegisterNativesURoomGraphBuilder()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(URoomGraphBuilder);
UClass* Z_Construct_UClass_URoomGraphBuilder_NoRegister()
{
	return URoomGraphBuilder::StaticClass();
}
struct Z_Construct_UClass_URoomGraphBuilder_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Generation/RoomGraphBuilder.h" },
		{ "ModuleRelativePath", "Public/Generation/RoomGraphBuilder.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<URoomGraphBuilder>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_URoomGraphBuilder_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_EternalDescent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_URoomGraphBuilder_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_URoomGraphBuilder_Statics::ClassParams = {
	&URoomGraphBuilder::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_URoomGraphBuilder_Statics::Class_MetaDataParams), Z_Construct_UClass_URoomGraphBuilder_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_URoomGraphBuilder()
{
	if (!Z_Registration_Info_UClass_URoomGraphBuilder.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_URoomGraphBuilder.OuterSingleton, Z_Construct_UClass_URoomGraphBuilder_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_URoomGraphBuilder.OuterSingleton;
}
template<> ETERNALDESCENT_API UClass* StaticClass<URoomGraphBuilder>()
{
	return URoomGraphBuilder::StaticClass();
}
URoomGraphBuilder::URoomGraphBuilder(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(URoomGraphBuilder);
URoomGraphBuilder::~URoomGraphBuilder() {}
// End Class URoomGraphBuilder

// Begin Registration
struct Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_Generation_RoomGraphBuilder_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_URoomGraphBuilder, URoomGraphBuilder::StaticClass, TEXT("URoomGraphBuilder"), &Z_Registration_Info_UClass_URoomGraphBuilder, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(URoomGraphBuilder), 3449894136U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_Generation_RoomGraphBuilder_h_752458720(TEXT("/Script/EternalDescent"),
	Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_Generation_RoomGraphBuilder_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_Generation_RoomGraphBuilder_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
