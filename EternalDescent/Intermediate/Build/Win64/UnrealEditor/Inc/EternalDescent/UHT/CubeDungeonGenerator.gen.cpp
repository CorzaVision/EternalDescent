// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EternalDescent/Public/CubeDungeonGenerator.h"
#include "EternalDescent/Public/CubeDungeonTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCubeDungeonGenerator() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntVector();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ETERNALDESCENT_API UClass* Z_Construct_UClass_ACubeDungeonGenerator();
ETERNALDESCENT_API UClass* Z_Construct_UClass_ACubeDungeonGenerator_NoRegister();
ETERNALDESCENT_API UScriptStruct* Z_Construct_UScriptStruct_FCubeDungeonLayout();
UPackage* Z_Construct_UPackage__Script_EternalDescent();
// End Cross Module References

// Begin Class ACubeDungeonGenerator Function GenerateCubeDungeon
struct Z_Construct_UFunction_ACubeDungeonGenerator_GenerateCubeDungeon_Statics
{
	struct CubeDungeonGenerator_eventGenerateCubeDungeon_Parms
	{
		int32 FloorNumber;
		FIntVector Dimensions;
		FCubeDungeonLayout ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cube Dungeon" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Core generation\n" },
#endif
		{ "ModuleRelativePath", "Public/CubeDungeonGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Core generation" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Dimensions_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_FloorNumber;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Dimensions;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ACubeDungeonGenerator_GenerateCubeDungeon_Statics::NewProp_FloorNumber = { "FloorNumber", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CubeDungeonGenerator_eventGenerateCubeDungeon_Parms, FloorNumber), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ACubeDungeonGenerator_GenerateCubeDungeon_Statics::NewProp_Dimensions = { "Dimensions", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CubeDungeonGenerator_eventGenerateCubeDungeon_Parms, Dimensions), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Dimensions_MetaData), NewProp_Dimensions_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ACubeDungeonGenerator_GenerateCubeDungeon_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CubeDungeonGenerator_eventGenerateCubeDungeon_Parms, ReturnValue), Z_Construct_UScriptStruct_FCubeDungeonLayout, METADATA_PARAMS(0, nullptr) }; // 894533013
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACubeDungeonGenerator_GenerateCubeDungeon_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACubeDungeonGenerator_GenerateCubeDungeon_Statics::NewProp_FloorNumber,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACubeDungeonGenerator_GenerateCubeDungeon_Statics::NewProp_Dimensions,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACubeDungeonGenerator_GenerateCubeDungeon_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACubeDungeonGenerator_GenerateCubeDungeon_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACubeDungeonGenerator_GenerateCubeDungeon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACubeDungeonGenerator, nullptr, "GenerateCubeDungeon", nullptr, nullptr, Z_Construct_UFunction_ACubeDungeonGenerator_GenerateCubeDungeon_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACubeDungeonGenerator_GenerateCubeDungeon_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACubeDungeonGenerator_GenerateCubeDungeon_Statics::CubeDungeonGenerator_eventGenerateCubeDungeon_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACubeDungeonGenerator_GenerateCubeDungeon_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACubeDungeonGenerator_GenerateCubeDungeon_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ACubeDungeonGenerator_GenerateCubeDungeon_Statics::CubeDungeonGenerator_eventGenerateCubeDungeon_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACubeDungeonGenerator_GenerateCubeDungeon()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACubeDungeonGenerator_GenerateCubeDungeon_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACubeDungeonGenerator::execGenerateCubeDungeon)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_FloorNumber);
	P_GET_STRUCT_REF(FIntVector,Z_Param_Out_Dimensions);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FCubeDungeonLayout*)Z_Param__Result=P_THIS->GenerateCubeDungeon(Z_Param_FloorNumber,Z_Param_Out_Dimensions);
	P_NATIVE_END;
}
// End Class ACubeDungeonGenerator Function GenerateCubeDungeon

// Begin Class ACubeDungeonGenerator Function GetCubeSize
struct Z_Construct_UFunction_ACubeDungeonGenerator_GetCubeSize_Statics
{
	struct CubeDungeonGenerator_eventGetCubeSize_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cube Dungeon" },
		{ "ModuleRelativePath", "Public/CubeDungeonGenerator.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ACubeDungeonGenerator_GetCubeSize_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CubeDungeonGenerator_eventGetCubeSize_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACubeDungeonGenerator_GetCubeSize_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACubeDungeonGenerator_GetCubeSize_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACubeDungeonGenerator_GetCubeSize_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACubeDungeonGenerator_GetCubeSize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACubeDungeonGenerator, nullptr, "GetCubeSize", nullptr, nullptr, Z_Construct_UFunction_ACubeDungeonGenerator_GetCubeSize_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACubeDungeonGenerator_GetCubeSize_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACubeDungeonGenerator_GetCubeSize_Statics::CubeDungeonGenerator_eventGetCubeSize_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACubeDungeonGenerator_GetCubeSize_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACubeDungeonGenerator_GetCubeSize_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ACubeDungeonGenerator_GetCubeSize_Statics::CubeDungeonGenerator_eventGetCubeSize_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACubeDungeonGenerator_GetCubeSize()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACubeDungeonGenerator_GetCubeSize_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACubeDungeonGenerator::execGetCubeSize)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetCubeSize();
	P_NATIVE_END;
}
// End Class ACubeDungeonGenerator Function GetCubeSize

// Begin Class ACubeDungeonGenerator Function SetCubeSize
struct Z_Construct_UFunction_ACubeDungeonGenerator_SetCubeSize_Statics
{
	struct CubeDungeonGenerator_eventSetCubeSize_Parms
	{
		float Size;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cube Dungeon" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Configuration\n" },
#endif
		{ "ModuleRelativePath", "Public/CubeDungeonGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Configuration" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Size;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ACubeDungeonGenerator_SetCubeSize_Statics::NewProp_Size = { "Size", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CubeDungeonGenerator_eventSetCubeSize_Parms, Size), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACubeDungeonGenerator_SetCubeSize_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACubeDungeonGenerator_SetCubeSize_Statics::NewProp_Size,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACubeDungeonGenerator_SetCubeSize_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACubeDungeonGenerator_SetCubeSize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACubeDungeonGenerator, nullptr, "SetCubeSize", nullptr, nullptr, Z_Construct_UFunction_ACubeDungeonGenerator_SetCubeSize_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACubeDungeonGenerator_SetCubeSize_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACubeDungeonGenerator_SetCubeSize_Statics::CubeDungeonGenerator_eventSetCubeSize_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACubeDungeonGenerator_SetCubeSize_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACubeDungeonGenerator_SetCubeSize_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ACubeDungeonGenerator_SetCubeSize_Statics::CubeDungeonGenerator_eventSetCubeSize_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACubeDungeonGenerator_SetCubeSize()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACubeDungeonGenerator_SetCubeSize_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACubeDungeonGenerator::execSetCubeSize)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Size);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetCubeSize(Z_Param_Size);
	P_NATIVE_END;
}
// End Class ACubeDungeonGenerator Function SetCubeSize

// Begin Class ACubeDungeonGenerator
void ACubeDungeonGenerator::StaticRegisterNativesACubeDungeonGenerator()
{
	UClass* Class = ACubeDungeonGenerator::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GenerateCubeDungeon", &ACubeDungeonGenerator::execGenerateCubeDungeon },
		{ "GetCubeSize", &ACubeDungeonGenerator::execGetCubeSize },
		{ "SetCubeSize", &ACubeDungeonGenerator::execSetCubeSize },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACubeDungeonGenerator);
UClass* Z_Construct_UClass_ACubeDungeonGenerator_NoRegister()
{
	return ACubeDungeonGenerator::StaticClass();
}
struct Z_Construct_UClass_ACubeDungeonGenerator_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "CubeDungeonGenerator.h" },
		{ "ModuleRelativePath", "Public/CubeDungeonGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CubeSize_MetaData[] = {
		{ "Category", "Cube Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Generation parameters\n" },
#endif
		{ "ModuleRelativePath", "Public/CubeDungeonGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Generation parameters" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoomDensity_MetaData[] = {
		{ "Category", "Generation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Size of each cube in world units\n" },
#endif
		{ "ModuleRelativePath", "Public/CubeDungeonGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Size of each cube in world units" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinRoomSize_MetaData[] = {
		{ "Category", "Generation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Percentage of grid to fill with rooms\n" },
#endif
		{ "ModuleRelativePath", "Public/CubeDungeonGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Percentage of grid to fill with rooms" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxRoomSize_MetaData[] = {
		{ "Category", "Generation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Minimum cubes per room dimension\n" },
#endif
		{ "ModuleRelativePath", "Public/CubeDungeonGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Minimum cubes per room dimension" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CubeSize;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RoomDensity;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MinRoomSize;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxRoomSize;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ACubeDungeonGenerator_GenerateCubeDungeon, "GenerateCubeDungeon" }, // 3561378009
		{ &Z_Construct_UFunction_ACubeDungeonGenerator_GetCubeSize, "GetCubeSize" }, // 937329570
		{ &Z_Construct_UFunction_ACubeDungeonGenerator_SetCubeSize, "SetCubeSize" }, // 3068493610
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACubeDungeonGenerator>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACubeDungeonGenerator_Statics::NewProp_CubeSize = { "CubeSize", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACubeDungeonGenerator, CubeSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CubeSize_MetaData), NewProp_CubeSize_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACubeDungeonGenerator_Statics::NewProp_RoomDensity = { "RoomDensity", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACubeDungeonGenerator, RoomDensity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoomDensity_MetaData), NewProp_RoomDensity_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ACubeDungeonGenerator_Statics::NewProp_MinRoomSize = { "MinRoomSize", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACubeDungeonGenerator, MinRoomSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinRoomSize_MetaData), NewProp_MinRoomSize_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ACubeDungeonGenerator_Statics::NewProp_MaxRoomSize = { "MaxRoomSize", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACubeDungeonGenerator, MaxRoomSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxRoomSize_MetaData), NewProp_MaxRoomSize_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACubeDungeonGenerator_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACubeDungeonGenerator_Statics::NewProp_CubeSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACubeDungeonGenerator_Statics::NewProp_RoomDensity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACubeDungeonGenerator_Statics::NewProp_MinRoomSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACubeDungeonGenerator_Statics::NewProp_MaxRoomSize,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACubeDungeonGenerator_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ACubeDungeonGenerator_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_EternalDescent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACubeDungeonGenerator_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ACubeDungeonGenerator_Statics::ClassParams = {
	&ACubeDungeonGenerator::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ACubeDungeonGenerator_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ACubeDungeonGenerator_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACubeDungeonGenerator_Statics::Class_MetaDataParams), Z_Construct_UClass_ACubeDungeonGenerator_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ACubeDungeonGenerator()
{
	if (!Z_Registration_Info_UClass_ACubeDungeonGenerator.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACubeDungeonGenerator.OuterSingleton, Z_Construct_UClass_ACubeDungeonGenerator_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ACubeDungeonGenerator.OuterSingleton;
}
template<> ETERNALDESCENT_API UClass* StaticClass<ACubeDungeonGenerator>()
{
	return ACubeDungeonGenerator::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ACubeDungeonGenerator);
ACubeDungeonGenerator::~ACubeDungeonGenerator() {}
// End Class ACubeDungeonGenerator

// Begin Registration
struct Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_CubeDungeonGenerator_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ACubeDungeonGenerator, ACubeDungeonGenerator::StaticClass, TEXT("ACubeDungeonGenerator"), &Z_Registration_Info_UClass_ACubeDungeonGenerator, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACubeDungeonGenerator), 989138055U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_CubeDungeonGenerator_h_2057414079(TEXT("/Script/EternalDescent"),
	Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_CubeDungeonGenerator_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_CubeDungeonGenerator_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
