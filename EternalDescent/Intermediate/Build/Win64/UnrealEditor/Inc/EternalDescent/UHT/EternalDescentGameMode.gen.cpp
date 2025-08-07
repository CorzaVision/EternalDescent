// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EternalDescent/EternalDescentGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEternalDescentGameMode() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
ETERNALDESCENT_API UClass* Z_Construct_UClass_AEternalDescentGameMode();
ETERNALDESCENT_API UClass* Z_Construct_UClass_AEternalDescentGameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_EternalDescent();
// End Cross Module References

// Begin Class AEternalDescentGameMode
void AEternalDescentGameMode::StaticRegisterNativesAEternalDescentGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AEternalDescentGameMode);
UClass* Z_Construct_UClass_AEternalDescentGameMode_NoRegister()
{
	return AEternalDescentGameMode::StaticClass();
}
struct Z_Construct_UClass_AEternalDescentGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "EternalDescentGameMode.h" },
		{ "ModuleRelativePath", "EternalDescentGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEternalDescentGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AEternalDescentGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_EternalDescent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEternalDescentGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AEternalDescentGameMode_Statics::ClassParams = {
	&AEternalDescentGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008802ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AEternalDescentGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AEternalDescentGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AEternalDescentGameMode()
{
	if (!Z_Registration_Info_UClass_AEternalDescentGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AEternalDescentGameMode.OuterSingleton, Z_Construct_UClass_AEternalDescentGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AEternalDescentGameMode.OuterSingleton;
}
template<> ETERNALDESCENT_API UClass* StaticClass<AEternalDescentGameMode>()
{
	return AEternalDescentGameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AEternalDescentGameMode);
AEternalDescentGameMode::~AEternalDescentGameMode() {}
// End Class AEternalDescentGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_EternalDescentGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AEternalDescentGameMode, AEternalDescentGameMode::StaticClass, TEXT("AEternalDescentGameMode"), &Z_Registration_Info_UClass_AEternalDescentGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AEternalDescentGameMode), 2363631948U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_EternalDescentGameMode_h_4145157102(TEXT("/Script/EternalDescent"),
	Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_EternalDescentGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_EternalDescentGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
