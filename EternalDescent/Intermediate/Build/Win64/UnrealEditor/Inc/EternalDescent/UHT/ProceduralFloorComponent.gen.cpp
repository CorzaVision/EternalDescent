// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EternalDescent/Public/Generation/ProceduralFloorComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeProceduralFloorComponent() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
ETERNALDESCENT_API UClass* Z_Construct_UClass_UProceduralFloorComponent();
ETERNALDESCENT_API UClass* Z_Construct_UClass_UProceduralFloorComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_EternalDescent();
// End Cross Module References

// Begin Class UProceduralFloorComponent
void UProceduralFloorComponent::StaticRegisterNativesUProceduralFloorComponent()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UProceduralFloorComponent);
UClass* Z_Construct_UClass_UProceduralFloorComponent_NoRegister()
{
	return UProceduralFloorComponent::StaticClass();
}
struct Z_Construct_UClass_UProceduralFloorComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "Generation/ProceduralFloorComponent.h" },
		{ "ModuleRelativePath", "Public/Generation/ProceduralFloorComponent.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UProceduralFloorComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UProceduralFloorComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_EternalDescent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UProceduralFloorComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UProceduralFloorComponent_Statics::ClassParams = {
	&UProceduralFloorComponent::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UProceduralFloorComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UProceduralFloorComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UProceduralFloorComponent()
{
	if (!Z_Registration_Info_UClass_UProceduralFloorComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UProceduralFloorComponent.OuterSingleton, Z_Construct_UClass_UProceduralFloorComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UProceduralFloorComponent.OuterSingleton;
}
template<> ETERNALDESCENT_API UClass* StaticClass<UProceduralFloorComponent>()
{
	return UProceduralFloorComponent::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UProceduralFloorComponent);
UProceduralFloorComponent::~UProceduralFloorComponent() {}
// End Class UProceduralFloorComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_Generation_ProceduralFloorComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UProceduralFloorComponent, UProceduralFloorComponent::StaticClass, TEXT("UProceduralFloorComponent"), &Z_Registration_Info_UClass_UProceduralFloorComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UProceduralFloorComponent), 722645685U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_Generation_ProceduralFloorComponent_h_2203095549(TEXT("/Script/EternalDescent"),
	Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_Generation_ProceduralFloorComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_Generation_ProceduralFloorComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
