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
ETERNALDESCENT_API UClass* Z_Construct_UClass_URoomGraphBuilder_NoRegister();
ETERNALDESCENT_API UClass* Z_Construct_UClass_UWallEnvironmentBuilder_NoRegister();
UPackage* Z_Construct_UPackage__Script_EternalDescent();
// End Cross Module References

// Begin Class UProceduralFloorComponent Function ClearGenerate
struct Z_Construct_UFunction_UProceduralFloorComponent_ClearGenerate_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generation|Actions" },
		{ "ModuleRelativePath", "Public/Generation/ProceduralFloorComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UProceduralFloorComponent_ClearGenerate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UProceduralFloorComponent, nullptr, "ClearGenerate", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UProceduralFloorComponent_ClearGenerate_Statics::Function_MetaDataParams), Z_Construct_UFunction_UProceduralFloorComponent_ClearGenerate_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UProceduralFloorComponent_ClearGenerate()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UProceduralFloorComponent_ClearGenerate_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UProceduralFloorComponent::execClearGenerate)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClearGenerate();
	P_NATIVE_END;
}
// End Class UProceduralFloorComponent Function ClearGenerate

// Begin Class UProceduralFloorComponent Function GenerateFloor
struct Z_Construct_UFunction_UProceduralFloorComponent_GenerateFloor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generation|Actions" },
		{ "ModuleRelativePath", "Public/Generation/ProceduralFloorComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UProceduralFloorComponent_GenerateFloor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UProceduralFloorComponent, nullptr, "GenerateFloor", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UProceduralFloorComponent_GenerateFloor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UProceduralFloorComponent_GenerateFloor_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UProceduralFloorComponent_GenerateFloor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UProceduralFloorComponent_GenerateFloor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UProceduralFloorComponent::execGenerateFloor)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->GenerateFloor();
	P_NATIVE_END;
}
// End Class UProceduralFloorComponent Function GenerateFloor

// Begin Class UProceduralFloorComponent
void UProceduralFloorComponent::StaticRegisterNativesUProceduralFloorComponent()
{
	UClass* Class = UProceduralFloorComponent::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ClearGenerate", &UProceduralFloorComponent::execClearGenerate },
		{ "GenerateFloor", &UProceduralFloorComponent::execGenerateFloor },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GridWidth_MetaData[] = {
		{ "Category", "Generation|Config" },
		{ "ClampMax", "64" },
		{ "ClampMin", "5" },
		{ "ModuleRelativePath", "Public/Generation/ProceduralFloorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GridHeight_MetaData[] = {
		{ "Category", "Generation|Config" },
		{ "ClampMax", "64" },
		{ "ClampMin", "5" },
		{ "ModuleRelativePath", "Public/Generation/ProceduralFloorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CellSize_MetaData[] = {
		{ "Category", "Generation|Config" },
		{ "ClampMin", "10.0" },
		{ "ModuleRelativePath", "Public/Generation/ProceduralFloorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoomCount_MetaData[] = {
		{ "Category", "Generation|Config" },
		{ "ClampMax", "64" },
		{ "ClampMin", "1" },
		{ "ModuleRelativePath", "Public/Generation/ProceduralFloorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GraphBuilder_MetaData[] = {
		{ "ModuleRelativePath", "Public/Generation/ProceduralFloorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WallBuilder_MetaData[] = {
		{ "ModuleRelativePath", "Public/Generation/ProceduralFloorComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_GridWidth;
	static const UECodeGen_Private::FIntPropertyParams NewProp_GridHeight;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CellSize;
	static const UECodeGen_Private::FIntPropertyParams NewProp_RoomCount;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_GraphBuilder;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WallBuilder;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UProceduralFloorComponent_ClearGenerate, "ClearGenerate" }, // 1544878000
		{ &Z_Construct_UFunction_UProceduralFloorComponent_GenerateFloor, "GenerateFloor" }, // 2629684759
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UProceduralFloorComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UProceduralFloorComponent_Statics::NewProp_GridWidth = { "GridWidth", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UProceduralFloorComponent, GridWidth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GridWidth_MetaData), NewProp_GridWidth_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UProceduralFloorComponent_Statics::NewProp_GridHeight = { "GridHeight", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UProceduralFloorComponent, GridHeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GridHeight_MetaData), NewProp_GridHeight_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UProceduralFloorComponent_Statics::NewProp_CellSize = { "CellSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UProceduralFloorComponent, CellSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CellSize_MetaData), NewProp_CellSize_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UProceduralFloorComponent_Statics::NewProp_RoomCount = { "RoomCount", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UProceduralFloorComponent, RoomCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoomCount_MetaData), NewProp_RoomCount_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UProceduralFloorComponent_Statics::NewProp_GraphBuilder = { "GraphBuilder", nullptr, (EPropertyFlags)0x0144000000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UProceduralFloorComponent, GraphBuilder), Z_Construct_UClass_URoomGraphBuilder_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GraphBuilder_MetaData), NewProp_GraphBuilder_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UProceduralFloorComponent_Statics::NewProp_WallBuilder = { "WallBuilder", nullptr, (EPropertyFlags)0x0144000000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UProceduralFloorComponent, WallBuilder), Z_Construct_UClass_UWallEnvironmentBuilder_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WallBuilder_MetaData), NewProp_WallBuilder_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UProceduralFloorComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UProceduralFloorComponent_Statics::NewProp_GridWidth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UProceduralFloorComponent_Statics::NewProp_GridHeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UProceduralFloorComponent_Statics::NewProp_CellSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UProceduralFloorComponent_Statics::NewProp_RoomCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UProceduralFloorComponent_Statics::NewProp_GraphBuilder,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UProceduralFloorComponent_Statics::NewProp_WallBuilder,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UProceduralFloorComponent_Statics::PropPointers) < 2048);
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
	FuncInfo,
	Z_Construct_UClass_UProceduralFloorComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UProceduralFloorComponent_Statics::PropPointers),
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
		{ Z_Construct_UClass_UProceduralFloorComponent, UProceduralFloorComponent::StaticClass, TEXT("UProceduralFloorComponent"), &Z_Registration_Info_UClass_UProceduralFloorComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UProceduralFloorComponent), 2689050875U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_Generation_ProceduralFloorComponent_h_1368244078(TEXT("/Script/EternalDescent"),
	Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_Generation_ProceduralFloorComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_Generation_ProceduralFloorComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
