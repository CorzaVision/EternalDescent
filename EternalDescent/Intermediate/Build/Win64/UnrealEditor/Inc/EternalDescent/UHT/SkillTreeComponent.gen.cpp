// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EternalDescent/Public/SkillTreeComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSkillTreeComponent() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
ETERNALDESCENT_API UClass* Z_Construct_UClass_USkillTreeComponent();
ETERNALDESCENT_API UClass* Z_Construct_UClass_USkillTreeComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_EternalDescent();
// End Cross Module References

// Begin Class USkillTreeComponent
void USkillTreeComponent::StaticRegisterNativesUSkillTreeComponent()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USkillTreeComponent);
UClass* Z_Construct_UClass_USkillTreeComponent_NoRegister()
{
	return USkillTreeComponent::StaticClass();
}
struct Z_Construct_UClass_USkillTreeComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "SkillTreeComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/SkillTreeComponent.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USkillTreeComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_USkillTreeComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_EternalDescent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USkillTreeComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USkillTreeComponent_Statics::ClassParams = {
	&USkillTreeComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USkillTreeComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_USkillTreeComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_USkillTreeComponent()
{
	if (!Z_Registration_Info_UClass_USkillTreeComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USkillTreeComponent.OuterSingleton, Z_Construct_UClass_USkillTreeComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USkillTreeComponent.OuterSingleton;
}
template<> ETERNALDESCENT_API UClass* StaticClass<USkillTreeComponent>()
{
	return USkillTreeComponent::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(USkillTreeComponent);
USkillTreeComponent::~USkillTreeComponent() {}
// End Class USkillTreeComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SkillTreeComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_USkillTreeComponent, USkillTreeComponent::StaticClass, TEXT("USkillTreeComponent"), &Z_Registration_Info_UClass_USkillTreeComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USkillTreeComponent), 1642245412U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SkillTreeComponent_h_2834532191(TEXT("/Script/EternalDescent"),
	Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SkillTreeComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SkillTreeComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
