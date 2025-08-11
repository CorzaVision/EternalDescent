// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EternalDescent/Public/SnakePathGenerator.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSnakePathGenerator() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntPoint();
ETERNALDESCENT_API UClass* Z_Construct_UClass_USnakePathGenerator();
ETERNALDESCENT_API UClass* Z_Construct_UClass_USnakePathGenerator_NoRegister();
ETERNALDESCENT_API UEnum* Z_Construct_UEnum_EternalDescent_ESnakeRoomSize();
ETERNALDESCENT_API UScriptStruct* Z_Construct_UScriptStruct_FSnakeGenerationConfig();
ETERNALDESCENT_API UScriptStruct* Z_Construct_UScriptStruct_FSnakeGenerationResult();
ETERNALDESCENT_API UScriptStruct* Z_Construct_UScriptStruct_FSnakeRoomData();
UPackage* Z_Construct_UPackage__Script_EternalDescent();
// End Cross Module References

// Begin Enum ESnakeRoomSize
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ESnakeRoomSize;
static UEnum* ESnakeRoomSize_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ESnakeRoomSize.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ESnakeRoomSize.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_EternalDescent_ESnakeRoomSize, (UObject*)Z_Construct_UPackage__Script_EternalDescent(), TEXT("ESnakeRoomSize"));
	}
	return Z_Registration_Info_UEnum_ESnakeRoomSize.OuterSingleton;
}
template<> ETERNALDESCENT_API UEnum* StaticEnum<ESnakeRoomSize>()
{
	return ESnakeRoomSize_StaticEnum();
}
struct Z_Construct_UEnum_EternalDescent_ESnakeRoomSize_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/SnakePathGenerator.h" },
		{ "None.DisplayName", "None" },
		{ "None.Name", "ESnakeRoomSize::None" },
		{ "Small_2x2.DisplayName", "2x2 Room" },
		{ "Small_2x2.Name", "ESnakeRoomSize::Small_2x2" },
		{ "Standard_3x3.DisplayName", "3x3 Room" },
		{ "Standard_3x3.Name", "ESnakeRoomSize::Standard_3x3" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ESnakeRoomSize::None", (int64)ESnakeRoomSize::None },
		{ "ESnakeRoomSize::Small_2x2", (int64)ESnakeRoomSize::Small_2x2 },
		{ "ESnakeRoomSize::Standard_3x3", (int64)ESnakeRoomSize::Standard_3x3 },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_EternalDescent_ESnakeRoomSize_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_EternalDescent,
	nullptr,
	"ESnakeRoomSize",
	"ESnakeRoomSize",
	Z_Construct_UEnum_EternalDescent_ESnakeRoomSize_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_EternalDescent_ESnakeRoomSize_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_EternalDescent_ESnakeRoomSize_Statics::Enum_MetaDataParams), Z_Construct_UEnum_EternalDescent_ESnakeRoomSize_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_EternalDescent_ESnakeRoomSize()
{
	if (!Z_Registration_Info_UEnum_ESnakeRoomSize.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ESnakeRoomSize.InnerSingleton, Z_Construct_UEnum_EternalDescent_ESnakeRoomSize_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ESnakeRoomSize.InnerSingleton;
}
// End Enum ESnakeRoomSize

// Begin ScriptStruct FSnakeRoomData
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SnakeRoomData;
class UScriptStruct* FSnakeRoomData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SnakeRoomData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SnakeRoomData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSnakeRoomData, (UObject*)Z_Construct_UPackage__Script_EternalDescent(), TEXT("SnakeRoomData"));
	}
	return Z_Registration_Info_UScriptStruct_SnakeRoomData.OuterSingleton;
}
template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<FSnakeRoomData>()
{
	return FSnakeRoomData::StaticStruct();
}
struct Z_Construct_UScriptStruct_FSnakeRoomData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/SnakePathGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Center_MetaData[] = {
		{ "Category", "SnakeRoomData" },
		{ "ModuleRelativePath", "Public/SnakePathGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoomSize_MetaData[] = {
		{ "Category", "SnakeRoomData" },
		{ "ModuleRelativePath", "Public/SnakePathGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsStartRoom_MetaData[] = {
		{ "Category", "SnakeRoomData" },
		{ "ModuleRelativePath", "Public/SnakePathGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsEndRoom_MetaData[] = {
		{ "Category", "SnakeRoomData" },
		{ "ModuleRelativePath", "Public/SnakePathGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PathIndex_MetaData[] = {
		{ "Category", "SnakeRoomData" },
		{ "ModuleRelativePath", "Public/SnakePathGenerator.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Center;
	static const UECodeGen_Private::FBytePropertyParams NewProp_RoomSize_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_RoomSize;
	static void NewProp_bIsStartRoom_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsStartRoom;
	static void NewProp_bIsEndRoom_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsEndRoom;
	static const UECodeGen_Private::FIntPropertyParams NewProp_PathIndex;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSnakeRoomData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSnakeRoomData_Statics::NewProp_Center = { "Center", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeRoomData, Center), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Center_MetaData), NewProp_Center_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FSnakeRoomData_Statics::NewProp_RoomSize_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FSnakeRoomData_Statics::NewProp_RoomSize = { "RoomSize", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeRoomData, RoomSize), Z_Construct_UEnum_EternalDescent_ESnakeRoomSize, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoomSize_MetaData), NewProp_RoomSize_MetaData) }; // 1759129366
void Z_Construct_UScriptStruct_FSnakeRoomData_Statics::NewProp_bIsStartRoom_SetBit(void* Obj)
{
	((FSnakeRoomData*)Obj)->bIsStartRoom = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSnakeRoomData_Statics::NewProp_bIsStartRoom = { "bIsStartRoom", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FSnakeRoomData), &Z_Construct_UScriptStruct_FSnakeRoomData_Statics::NewProp_bIsStartRoom_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsStartRoom_MetaData), NewProp_bIsStartRoom_MetaData) };
void Z_Construct_UScriptStruct_FSnakeRoomData_Statics::NewProp_bIsEndRoom_SetBit(void* Obj)
{
	((FSnakeRoomData*)Obj)->bIsEndRoom = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSnakeRoomData_Statics::NewProp_bIsEndRoom = { "bIsEndRoom", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FSnakeRoomData), &Z_Construct_UScriptStruct_FSnakeRoomData_Statics::NewProp_bIsEndRoom_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsEndRoom_MetaData), NewProp_bIsEndRoom_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSnakeRoomData_Statics::NewProp_PathIndex = { "PathIndex", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeRoomData, PathIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PathIndex_MetaData), NewProp_PathIndex_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSnakeRoomData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeRoomData_Statics::NewProp_Center,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeRoomData_Statics::NewProp_RoomSize_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeRoomData_Statics::NewProp_RoomSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeRoomData_Statics::NewProp_bIsStartRoom,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeRoomData_Statics::NewProp_bIsEndRoom,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeRoomData_Statics::NewProp_PathIndex,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSnakeRoomData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSnakeRoomData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_EternalDescent,
	nullptr,
	&NewStructOps,
	"SnakeRoomData",
	Z_Construct_UScriptStruct_FSnakeRoomData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSnakeRoomData_Statics::PropPointers),
	sizeof(FSnakeRoomData),
	alignof(FSnakeRoomData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSnakeRoomData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSnakeRoomData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FSnakeRoomData()
{
	if (!Z_Registration_Info_UScriptStruct_SnakeRoomData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SnakeRoomData.InnerSingleton, Z_Construct_UScriptStruct_FSnakeRoomData_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_SnakeRoomData.InnerSingleton;
}
// End ScriptStruct FSnakeRoomData

// Begin ScriptStruct FSnakeGenerationResult
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SnakeGenerationResult;
class UScriptStruct* FSnakeGenerationResult::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SnakeGenerationResult.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SnakeGenerationResult.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSnakeGenerationResult, (UObject*)Z_Construct_UPackage__Script_EternalDescent(), TEXT("SnakeGenerationResult"));
	}
	return Z_Registration_Info_UScriptStruct_SnakeGenerationResult.OuterSingleton;
}
template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<FSnakeGenerationResult>()
{
	return FSnakeGenerationResult::StaticStruct();
}
struct Z_Construct_UScriptStruct_FSnakeGenerationResult_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/SnakePathGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rooms_MetaData[] = {
		{ "Category", "SnakeGenerationResult" },
		{ "ModuleRelativePath", "Public/SnakePathGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PathSequence_MetaData[] = {
		{ "Category", "SnakeGenerationResult" },
		{ "ModuleRelativePath", "Public/SnakePathGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bGenerationSuccessful_MetaData[] = {
		{ "Category", "SnakeGenerationResult" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Room centers in path order\n" },
#endif
		{ "ModuleRelativePath", "Public/SnakePathGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Room centers in path order" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GenerationTimeMs_MetaData[] = {
		{ "Category", "SnakeGenerationResult" },
		{ "ModuleRelativePath", "Public/SnakePathGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RetryCount_MetaData[] = {
		{ "Category", "SnakeGenerationResult" },
		{ "ModuleRelativePath", "Public/SnakePathGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BacktrackCount_MetaData[] = {
		{ "Category", "SnakeGenerationResult" },
		{ "ModuleRelativePath", "Public/SnakePathGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FailureReason_MetaData[] = {
		{ "Category", "SnakeGenerationResult" },
		{ "ModuleRelativePath", "Public/SnakePathGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GridSizeX_MetaData[] = {
		{ "Category", "SnakeGenerationResult" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Grid dimensions used for generation\n" },
#endif
		{ "ModuleRelativePath", "Public/SnakePathGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Grid dimensions used for generation" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GridSizeY_MetaData[] = {
		{ "Category", "SnakeGenerationResult" },
		{ "ModuleRelativePath", "Public/SnakePathGenerator.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Rooms_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Rooms;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PathSequence_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_PathSequence;
	static void NewProp_bGenerationSuccessful_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bGenerationSuccessful;
	static const UECodeGen_Private::FIntPropertyParams NewProp_GenerationTimeMs;
	static const UECodeGen_Private::FIntPropertyParams NewProp_RetryCount;
	static const UECodeGen_Private::FIntPropertyParams NewProp_BacktrackCount;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FailureReason;
	static const UECodeGen_Private::FIntPropertyParams NewProp_GridSizeX;
	static const UECodeGen_Private::FIntPropertyParams NewProp_GridSizeY;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSnakeGenerationResult>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSnakeGenerationResult_Statics::NewProp_Rooms_Inner = { "Rooms", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FSnakeRoomData, METADATA_PARAMS(0, nullptr) }; // 572990405
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FSnakeGenerationResult_Statics::NewProp_Rooms = { "Rooms", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeGenerationResult, Rooms), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rooms_MetaData), NewProp_Rooms_MetaData) }; // 572990405
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSnakeGenerationResult_Statics::NewProp_PathSequence_Inner = { "PathSequence", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FSnakeGenerationResult_Statics::NewProp_PathSequence = { "PathSequence", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeGenerationResult, PathSequence), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PathSequence_MetaData), NewProp_PathSequence_MetaData) };
void Z_Construct_UScriptStruct_FSnakeGenerationResult_Statics::NewProp_bGenerationSuccessful_SetBit(void* Obj)
{
	((FSnakeGenerationResult*)Obj)->bGenerationSuccessful = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSnakeGenerationResult_Statics::NewProp_bGenerationSuccessful = { "bGenerationSuccessful", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FSnakeGenerationResult), &Z_Construct_UScriptStruct_FSnakeGenerationResult_Statics::NewProp_bGenerationSuccessful_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bGenerationSuccessful_MetaData), NewProp_bGenerationSuccessful_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSnakeGenerationResult_Statics::NewProp_GenerationTimeMs = { "GenerationTimeMs", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeGenerationResult, GenerationTimeMs), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GenerationTimeMs_MetaData), NewProp_GenerationTimeMs_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSnakeGenerationResult_Statics::NewProp_RetryCount = { "RetryCount", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeGenerationResult, RetryCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RetryCount_MetaData), NewProp_RetryCount_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSnakeGenerationResult_Statics::NewProp_BacktrackCount = { "BacktrackCount", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeGenerationResult, BacktrackCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BacktrackCount_MetaData), NewProp_BacktrackCount_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSnakeGenerationResult_Statics::NewProp_FailureReason = { "FailureReason", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeGenerationResult, FailureReason), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FailureReason_MetaData), NewProp_FailureReason_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSnakeGenerationResult_Statics::NewProp_GridSizeX = { "GridSizeX", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeGenerationResult, GridSizeX), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GridSizeX_MetaData), NewProp_GridSizeX_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSnakeGenerationResult_Statics::NewProp_GridSizeY = { "GridSizeY", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeGenerationResult, GridSizeY), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GridSizeY_MetaData), NewProp_GridSizeY_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSnakeGenerationResult_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeGenerationResult_Statics::NewProp_Rooms_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeGenerationResult_Statics::NewProp_Rooms,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeGenerationResult_Statics::NewProp_PathSequence_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeGenerationResult_Statics::NewProp_PathSequence,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeGenerationResult_Statics::NewProp_bGenerationSuccessful,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeGenerationResult_Statics::NewProp_GenerationTimeMs,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeGenerationResult_Statics::NewProp_RetryCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeGenerationResult_Statics::NewProp_BacktrackCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeGenerationResult_Statics::NewProp_FailureReason,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeGenerationResult_Statics::NewProp_GridSizeX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeGenerationResult_Statics::NewProp_GridSizeY,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSnakeGenerationResult_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSnakeGenerationResult_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_EternalDescent,
	nullptr,
	&NewStructOps,
	"SnakeGenerationResult",
	Z_Construct_UScriptStruct_FSnakeGenerationResult_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSnakeGenerationResult_Statics::PropPointers),
	sizeof(FSnakeGenerationResult),
	alignof(FSnakeGenerationResult),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSnakeGenerationResult_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSnakeGenerationResult_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FSnakeGenerationResult()
{
	if (!Z_Registration_Info_UScriptStruct_SnakeGenerationResult.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SnakeGenerationResult.InnerSingleton, Z_Construct_UScriptStruct_FSnakeGenerationResult_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_SnakeGenerationResult.InnerSingleton;
}
// End ScriptStruct FSnakeGenerationResult

// Begin ScriptStruct FSnakeGenerationConfig
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SnakeGenerationConfig;
class UScriptStruct* FSnakeGenerationConfig::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SnakeGenerationConfig.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SnakeGenerationConfig.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSnakeGenerationConfig, (UObject*)Z_Construct_UPackage__Script_EternalDescent(), TEXT("SnakeGenerationConfig"));
	}
	return Z_Registration_Info_UScriptStruct_SnakeGenerationConfig.OuterSingleton;
}
template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<FSnakeGenerationConfig>()
{
	return FSnakeGenerationConfig::StaticStruct();
}
struct Z_Construct_UScriptStruct_FSnakeGenerationConfig_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/SnakePathGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RequiredRoomCount_MetaData[] = {
		{ "Category", "SnakeGenerationConfig" },
		{ "ClampMax", "1000" },
		{ "ClampMin", "25" },
		{ "ModuleRelativePath", "Public/SnakePathGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GridSizeX_MetaData[] = {
		{ "Category", "SnakeGenerationConfig" },
		{ "ClampMax", "1000" },
		{ "ClampMin", "30" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Default 25 rooms, configurable for limits testing\n" },
#endif
		{ "ModuleRelativePath", "Public/SnakePathGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Default 25 rooms, configurable for limits testing" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GridSizeY_MetaData[] = {
		{ "Category", "SnakeGenerationConfig" },
		{ "ClampMax", "1000" },
		{ "ClampMin", "30" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Grid width\n" },
#endif
		{ "ModuleRelativePath", "Public/SnakePathGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Grid width" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoomGap_MetaData[] = {
		{ "Category", "SnakeGenerationConfig" },
		{ "ClampMax", "1" },
		{ "ClampMin", "1" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Grid height\n" },
#endif
		{ "ModuleRelativePath", "Public/SnakePathGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Grid height" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxRetries_MetaData[] = {
		{ "Category", "SnakeGenerationConfig" },
		{ "ClampMax", "5000" },
		{ "ClampMin", "100" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Exactly 1 cell gap between rooms\n" },
#endif
		{ "ModuleRelativePath", "Public/SnakePathGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Exactly 1 cell gap between rooms" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxBacktrackDepth_MetaData[] = {
		{ "Category", "SnakeGenerationConfig" },
		{ "ClampMax", "20" },
		{ "ClampMin", "1" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Maximum generation attempts\n" },
#endif
		{ "ModuleRelativePath", "Public/SnakePathGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum generation attempts" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutoCalculateGridSize_MetaData[] = {
		{ "Category", "SnakeGenerationConfig" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Maximum consecutive backtracks before restart\n" },
#endif
		{ "ModuleRelativePath", "Public/SnakePathGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum consecutive backtracks before restart" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bVerboseLogging_MetaData[] = {
		{ "Category", "SnakeGenerationConfig" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Auto-size grid based on room count\n" },
#endif
		{ "ModuleRelativePath", "Public/SnakePathGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Auto-size grid based on room count" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_RequiredRoomCount;
	static const UECodeGen_Private::FIntPropertyParams NewProp_GridSizeX;
	static const UECodeGen_Private::FIntPropertyParams NewProp_GridSizeY;
	static const UECodeGen_Private::FIntPropertyParams NewProp_RoomGap;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxRetries;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxBacktrackDepth;
	static void NewProp_bAutoCalculateGridSize_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoCalculateGridSize;
	static void NewProp_bVerboseLogging_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bVerboseLogging;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSnakeGenerationConfig>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSnakeGenerationConfig_Statics::NewProp_RequiredRoomCount = { "RequiredRoomCount", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeGenerationConfig, RequiredRoomCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RequiredRoomCount_MetaData), NewProp_RequiredRoomCount_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSnakeGenerationConfig_Statics::NewProp_GridSizeX = { "GridSizeX", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeGenerationConfig, GridSizeX), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GridSizeX_MetaData), NewProp_GridSizeX_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSnakeGenerationConfig_Statics::NewProp_GridSizeY = { "GridSizeY", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeGenerationConfig, GridSizeY), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GridSizeY_MetaData), NewProp_GridSizeY_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSnakeGenerationConfig_Statics::NewProp_RoomGap = { "RoomGap", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeGenerationConfig, RoomGap), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoomGap_MetaData), NewProp_RoomGap_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSnakeGenerationConfig_Statics::NewProp_MaxRetries = { "MaxRetries", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeGenerationConfig, MaxRetries), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxRetries_MetaData), NewProp_MaxRetries_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSnakeGenerationConfig_Statics::NewProp_MaxBacktrackDepth = { "MaxBacktrackDepth", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSnakeGenerationConfig, MaxBacktrackDepth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxBacktrackDepth_MetaData), NewProp_MaxBacktrackDepth_MetaData) };
void Z_Construct_UScriptStruct_FSnakeGenerationConfig_Statics::NewProp_bAutoCalculateGridSize_SetBit(void* Obj)
{
	((FSnakeGenerationConfig*)Obj)->bAutoCalculateGridSize = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSnakeGenerationConfig_Statics::NewProp_bAutoCalculateGridSize = { "bAutoCalculateGridSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FSnakeGenerationConfig), &Z_Construct_UScriptStruct_FSnakeGenerationConfig_Statics::NewProp_bAutoCalculateGridSize_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutoCalculateGridSize_MetaData), NewProp_bAutoCalculateGridSize_MetaData) };
void Z_Construct_UScriptStruct_FSnakeGenerationConfig_Statics::NewProp_bVerboseLogging_SetBit(void* Obj)
{
	((FSnakeGenerationConfig*)Obj)->bVerboseLogging = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSnakeGenerationConfig_Statics::NewProp_bVerboseLogging = { "bVerboseLogging", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FSnakeGenerationConfig), &Z_Construct_UScriptStruct_FSnakeGenerationConfig_Statics::NewProp_bVerboseLogging_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bVerboseLogging_MetaData), NewProp_bVerboseLogging_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSnakeGenerationConfig_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeGenerationConfig_Statics::NewProp_RequiredRoomCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeGenerationConfig_Statics::NewProp_GridSizeX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeGenerationConfig_Statics::NewProp_GridSizeY,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeGenerationConfig_Statics::NewProp_RoomGap,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeGenerationConfig_Statics::NewProp_MaxRetries,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeGenerationConfig_Statics::NewProp_MaxBacktrackDepth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeGenerationConfig_Statics::NewProp_bAutoCalculateGridSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSnakeGenerationConfig_Statics::NewProp_bVerboseLogging,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSnakeGenerationConfig_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSnakeGenerationConfig_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_EternalDescent,
	nullptr,
	&NewStructOps,
	"SnakeGenerationConfig",
	Z_Construct_UScriptStruct_FSnakeGenerationConfig_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSnakeGenerationConfig_Statics::PropPointers),
	sizeof(FSnakeGenerationConfig),
	alignof(FSnakeGenerationConfig),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSnakeGenerationConfig_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSnakeGenerationConfig_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FSnakeGenerationConfig()
{
	if (!Z_Registration_Info_UScriptStruct_SnakeGenerationConfig.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SnakeGenerationConfig.InnerSingleton, Z_Construct_UScriptStruct_FSnakeGenerationConfig_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_SnakeGenerationConfig.InnerSingleton;
}
// End ScriptStruct FSnakeGenerationConfig

// Begin Class USnakePathGenerator Function CalculateOptimalGridSize
struct Z_Construct_UFunction_USnakePathGenerator_CalculateOptimalGridSize_Statics
{
	struct SnakePathGenerator_eventCalculateOptimalGridSize_Parms
	{
		int32 RoomCount;
		FIntPoint ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Snake Generation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Calculate optimal grid size for the given room count\n     * @param RoomCount - Number of rooms to fit\n     * @return Optimal grid dimensions as FIntPoint\n     */" },
#endif
		{ "ModuleRelativePath", "Public/SnakePathGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Calculate optimal grid size for the given room count\n@param RoomCount - Number of rooms to fit\n@return Optimal grid dimensions as FIntPoint" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_RoomCount;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USnakePathGenerator_CalculateOptimalGridSize_Statics::NewProp_RoomCount = { "RoomCount", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SnakePathGenerator_eventCalculateOptimalGridSize_Parms, RoomCount), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USnakePathGenerator_CalculateOptimalGridSize_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SnakePathGenerator_eventCalculateOptimalGridSize_Parms, ReturnValue), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USnakePathGenerator_CalculateOptimalGridSize_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USnakePathGenerator_CalculateOptimalGridSize_Statics::NewProp_RoomCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USnakePathGenerator_CalculateOptimalGridSize_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USnakePathGenerator_CalculateOptimalGridSize_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USnakePathGenerator_CalculateOptimalGridSize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USnakePathGenerator, nullptr, "CalculateOptimalGridSize", nullptr, nullptr, Z_Construct_UFunction_USnakePathGenerator_CalculateOptimalGridSize_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USnakePathGenerator_CalculateOptimalGridSize_Statics::PropPointers), sizeof(Z_Construct_UFunction_USnakePathGenerator_CalculateOptimalGridSize_Statics::SnakePathGenerator_eventCalculateOptimalGridSize_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USnakePathGenerator_CalculateOptimalGridSize_Statics::Function_MetaDataParams), Z_Construct_UFunction_USnakePathGenerator_CalculateOptimalGridSize_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_USnakePathGenerator_CalculateOptimalGridSize_Statics::SnakePathGenerator_eventCalculateOptimalGridSize_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USnakePathGenerator_CalculateOptimalGridSize()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USnakePathGenerator_CalculateOptimalGridSize_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USnakePathGenerator::execCalculateOptimalGridSize)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_RoomCount);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FIntPoint*)Z_Param__Result=P_THIS->CalculateOptimalGridSize(Z_Param_RoomCount);
	P_NATIVE_END;
}
// End Class USnakePathGenerator Function CalculateOptimalGridSize

// Begin Class USnakePathGenerator Function GenerateSnakePath
struct Z_Construct_UFunction_USnakePathGenerator_GenerateSnakePath_Statics
{
	struct SnakePathGenerator_eventGenerateSnakePath_Parms
	{
		FSnakeGenerationConfig Config;
		int32 Seed;
		FSnakeGenerationResult ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Snake Generation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Generate a complete snake path with exactly 25 rooms\n     * @param Config - Generation configuration parameters\n     * @param Seed - Random seed (-1 for random seed)\n     * @return Complete generation result with room data and statistics\n     */" },
#endif
		{ "CPP_Default_Seed", "-1" },
		{ "ModuleRelativePath", "Public/SnakePathGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Generate a complete snake path with exactly 25 rooms\n@param Config - Generation configuration parameters\n@param Seed - Random seed (-1 for random seed)\n@return Complete generation result with room data and statistics" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Config_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Config;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Seed;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USnakePathGenerator_GenerateSnakePath_Statics::NewProp_Config = { "Config", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SnakePathGenerator_eventGenerateSnakePath_Parms, Config), Z_Construct_UScriptStruct_FSnakeGenerationConfig, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Config_MetaData), NewProp_Config_MetaData) }; // 1253517341
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USnakePathGenerator_GenerateSnakePath_Statics::NewProp_Seed = { "Seed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SnakePathGenerator_eventGenerateSnakePath_Parms, Seed), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USnakePathGenerator_GenerateSnakePath_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SnakePathGenerator_eventGenerateSnakePath_Parms, ReturnValue), Z_Construct_UScriptStruct_FSnakeGenerationResult, METADATA_PARAMS(0, nullptr) }; // 2380905576
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USnakePathGenerator_GenerateSnakePath_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USnakePathGenerator_GenerateSnakePath_Statics::NewProp_Config,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USnakePathGenerator_GenerateSnakePath_Statics::NewProp_Seed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USnakePathGenerator_GenerateSnakePath_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USnakePathGenerator_GenerateSnakePath_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USnakePathGenerator_GenerateSnakePath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USnakePathGenerator, nullptr, "GenerateSnakePath", nullptr, nullptr, Z_Construct_UFunction_USnakePathGenerator_GenerateSnakePath_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USnakePathGenerator_GenerateSnakePath_Statics::PropPointers), sizeof(Z_Construct_UFunction_USnakePathGenerator_GenerateSnakePath_Statics::SnakePathGenerator_eventGenerateSnakePath_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USnakePathGenerator_GenerateSnakePath_Statics::Function_MetaDataParams), Z_Construct_UFunction_USnakePathGenerator_GenerateSnakePath_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_USnakePathGenerator_GenerateSnakePath_Statics::SnakePathGenerator_eventGenerateSnakePath_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USnakePathGenerator_GenerateSnakePath()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USnakePathGenerator_GenerateSnakePath_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USnakePathGenerator::execGenerateSnakePath)
{
	P_GET_STRUCT_REF(FSnakeGenerationConfig,Z_Param_Out_Config);
	P_GET_PROPERTY(FIntProperty,Z_Param_Seed);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FSnakeGenerationResult*)Z_Param__Result=P_THIS->GenerateSnakePath(Z_Param_Out_Config,Z_Param_Seed);
	P_NATIVE_END;
}
// End Class USnakePathGenerator Function GenerateSnakePath

// Begin Class USnakePathGenerator Function ValidateRoomConfiguration
struct Z_Construct_UFunction_USnakePathGenerator_ValidateRoomConfiguration_Statics
{
	struct SnakePathGenerator_eventValidateRoomConfiguration_Parms
	{
		TArray<FSnakeRoomData> Rooms;
		int32 GridSizeX;
		int32 GridSizeY;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Snake Generation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Validate that a room configuration is valid\n     * @param Rooms - Array of room data to validate\n     * @param GridSizeX - Grid width\n     * @param GridSizeY - Grid height\n     * @return True if configuration is valid, false otherwise\n     */" },
#endif
		{ "ModuleRelativePath", "Public/SnakePathGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Validate that a room configuration is valid\n@param Rooms - Array of room data to validate\n@param GridSizeX - Grid width\n@param GridSizeY - Grid height\n@return True if configuration is valid, false otherwise" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rooms_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Rooms_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Rooms;
	static const UECodeGen_Private::FIntPropertyParams NewProp_GridSizeX;
	static const UECodeGen_Private::FIntPropertyParams NewProp_GridSizeY;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USnakePathGenerator_ValidateRoomConfiguration_Statics::NewProp_Rooms_Inner = { "Rooms", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FSnakeRoomData, METADATA_PARAMS(0, nullptr) }; // 572990405
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_USnakePathGenerator_ValidateRoomConfiguration_Statics::NewProp_Rooms = { "Rooms", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SnakePathGenerator_eventValidateRoomConfiguration_Parms, Rooms), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rooms_MetaData), NewProp_Rooms_MetaData) }; // 572990405
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USnakePathGenerator_ValidateRoomConfiguration_Statics::NewProp_GridSizeX = { "GridSizeX", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SnakePathGenerator_eventValidateRoomConfiguration_Parms, GridSizeX), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USnakePathGenerator_ValidateRoomConfiguration_Statics::NewProp_GridSizeY = { "GridSizeY", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SnakePathGenerator_eventValidateRoomConfiguration_Parms, GridSizeY), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_USnakePathGenerator_ValidateRoomConfiguration_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((SnakePathGenerator_eventValidateRoomConfiguration_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USnakePathGenerator_ValidateRoomConfiguration_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(SnakePathGenerator_eventValidateRoomConfiguration_Parms), &Z_Construct_UFunction_USnakePathGenerator_ValidateRoomConfiguration_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USnakePathGenerator_ValidateRoomConfiguration_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USnakePathGenerator_ValidateRoomConfiguration_Statics::NewProp_Rooms_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USnakePathGenerator_ValidateRoomConfiguration_Statics::NewProp_Rooms,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USnakePathGenerator_ValidateRoomConfiguration_Statics::NewProp_GridSizeX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USnakePathGenerator_ValidateRoomConfiguration_Statics::NewProp_GridSizeY,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USnakePathGenerator_ValidateRoomConfiguration_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USnakePathGenerator_ValidateRoomConfiguration_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USnakePathGenerator_ValidateRoomConfiguration_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USnakePathGenerator, nullptr, "ValidateRoomConfiguration", nullptr, nullptr, Z_Construct_UFunction_USnakePathGenerator_ValidateRoomConfiguration_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USnakePathGenerator_ValidateRoomConfiguration_Statics::PropPointers), sizeof(Z_Construct_UFunction_USnakePathGenerator_ValidateRoomConfiguration_Statics::SnakePathGenerator_eventValidateRoomConfiguration_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USnakePathGenerator_ValidateRoomConfiguration_Statics::Function_MetaDataParams), Z_Construct_UFunction_USnakePathGenerator_ValidateRoomConfiguration_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_USnakePathGenerator_ValidateRoomConfiguration_Statics::SnakePathGenerator_eventValidateRoomConfiguration_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USnakePathGenerator_ValidateRoomConfiguration()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USnakePathGenerator_ValidateRoomConfiguration_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USnakePathGenerator::execValidateRoomConfiguration)
{
	P_GET_TARRAY_REF(FSnakeRoomData,Z_Param_Out_Rooms);
	P_GET_PROPERTY(FIntProperty,Z_Param_GridSizeX);
	P_GET_PROPERTY(FIntProperty,Z_Param_GridSizeY);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ValidateRoomConfiguration(Z_Param_Out_Rooms,Z_Param_GridSizeX,Z_Param_GridSizeY);
	P_NATIVE_END;
}
// End Class USnakePathGenerator Function ValidateRoomConfiguration

// Begin Class USnakePathGenerator
void USnakePathGenerator::StaticRegisterNativesUSnakePathGenerator()
{
	UClass* Class = USnakePathGenerator::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "CalculateOptimalGridSize", &USnakePathGenerator::execCalculateOptimalGridSize },
		{ "GenerateSnakePath", &USnakePathGenerator::execGenerateSnakePath },
		{ "ValidateRoomConfiguration", &USnakePathGenerator::execValidateRoomConfiguration },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USnakePathGenerator);
UClass* Z_Construct_UClass_USnakePathGenerator_NoRegister()
{
	return USnakePathGenerator::StaticClass();
}
struct Z_Construct_UClass_USnakePathGenerator_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Standalone snake path generation algorithm for dungeon generation.\n * \n * This class contains ONLY the generation logic with no visual dependencies.\n * It generates exactly 25 rooms with proper spacing:\n * - START room: 2x2 at position (2,2)\n * - END room: 2x2 at final path position\n * - Regular rooms: 3x3 for all middle rooms\n * - Spacing: Exactly 1 cell gap between all rooms\n * \n * Performance Target: 16ms per floor generation\n * \n * Key Features:\n * - Pure algorithm with no Unreal visual components\n * - Robust backtracking and recovery logic\n * - Deadlock detection and prevention\n * - Configurable generation parameters\n * - Detailed generation statistics and failure reporting\n */" },
#endif
		{ "IncludePath", "SnakePathGenerator.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/SnakePathGenerator.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Standalone snake path generation algorithm for dungeon generation.\n\nThis class contains ONLY the generation logic with no visual dependencies.\nIt generates exactly 25 rooms with proper spacing:\n- START room: 2x2 at position (2,2)\n- END room: 2x2 at final path position\n- Regular rooms: 3x3 for all middle rooms\n- Spacing: Exactly 1 cell gap between all rooms\n\nPerformance Target: 16ms per floor generation\n\nKey Features:\n- Pure algorithm with no Unreal visual components\n- Robust backtracking and recovery logic\n- Deadlock detection and prevention\n- Configurable generation parameters\n- Detailed generation statistics and failure reporting" },
#endif
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_USnakePathGenerator_CalculateOptimalGridSize, "CalculateOptimalGridSize" }, // 2159742636
		{ &Z_Construct_UFunction_USnakePathGenerator_GenerateSnakePath, "GenerateSnakePath" }, // 4148894075
		{ &Z_Construct_UFunction_USnakePathGenerator_ValidateRoomConfiguration, "ValidateRoomConfiguration" }, // 3721282568
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USnakePathGenerator>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_USnakePathGenerator_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_EternalDescent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USnakePathGenerator_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USnakePathGenerator_Statics::ClassParams = {
	&USnakePathGenerator::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USnakePathGenerator_Statics::Class_MetaDataParams), Z_Construct_UClass_USnakePathGenerator_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_USnakePathGenerator()
{
	if (!Z_Registration_Info_UClass_USnakePathGenerator.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USnakePathGenerator.OuterSingleton, Z_Construct_UClass_USnakePathGenerator_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USnakePathGenerator.OuterSingleton;
}
template<> ETERNALDESCENT_API UClass* StaticClass<USnakePathGenerator>()
{
	return USnakePathGenerator::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(USnakePathGenerator);
USnakePathGenerator::~USnakePathGenerator() {}
// End Class USnakePathGenerator

// Begin Registration
struct Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakePathGenerator_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ ESnakeRoomSize_StaticEnum, TEXT("ESnakeRoomSize"), &Z_Registration_Info_UEnum_ESnakeRoomSize, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1759129366U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FSnakeRoomData::StaticStruct, Z_Construct_UScriptStruct_FSnakeRoomData_Statics::NewStructOps, TEXT("SnakeRoomData"), &Z_Registration_Info_UScriptStruct_SnakeRoomData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSnakeRoomData), 572990405U) },
		{ FSnakeGenerationResult::StaticStruct, Z_Construct_UScriptStruct_FSnakeGenerationResult_Statics::NewStructOps, TEXT("SnakeGenerationResult"), &Z_Registration_Info_UScriptStruct_SnakeGenerationResult, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSnakeGenerationResult), 2380905576U) },
		{ FSnakeGenerationConfig::StaticStruct, Z_Construct_UScriptStruct_FSnakeGenerationConfig_Statics::NewStructOps, TEXT("SnakeGenerationConfig"), &Z_Registration_Info_UScriptStruct_SnakeGenerationConfig, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSnakeGenerationConfig), 1253517341U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_USnakePathGenerator, USnakePathGenerator::StaticClass, TEXT("USnakePathGenerator"), &Z_Registration_Info_UClass_USnakePathGenerator, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USnakePathGenerator), 3446899166U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakePathGenerator_h_230736836(TEXT("/Script/EternalDescent"),
	Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakePathGenerator_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakePathGenerator_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakePathGenerator_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakePathGenerator_h_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakePathGenerator_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakePathGenerator_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
