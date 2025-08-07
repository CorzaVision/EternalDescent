// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EternalDescent/Public/DungeonVisualizer.h"
#include "EternalDescent/Public/Tests/DungeonTestTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDungeonVisualizer() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntPoint();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UInstancedStaticMeshComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
ETERNALDESCENT_API UClass* Z_Construct_UClass_AADASystem_NoRegister();
ETERNALDESCENT_API UClass* Z_Construct_UClass_ADungeonVisualizer();
ETERNALDESCENT_API UClass* Z_Construct_UClass_ADungeonVisualizer_NoRegister();
ETERNALDESCENT_API UEnum* Z_Construct_UEnum_EternalDescent_ERoomType();
ETERNALDESCENT_API UScriptStruct* Z_Construct_UScriptStruct_FDungeonLayout();
ETERNALDESCENT_API UScriptStruct* Z_Construct_UScriptStruct_FRoomData();
ETERNALDESCENT_API UScriptStruct* Z_Construct_UScriptStruct_FRoomMeshSet();
ETERNALDESCENT_API UScriptStruct* Z_Construct_UScriptStruct_FRoomVisualData();
UPackage* Z_Construct_UPackage__Script_EternalDescent();
// End Cross Module References

// Begin ScriptStruct FRoomMeshSet
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_RoomMeshSet;
class UScriptStruct* FRoomMeshSet::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_RoomMeshSet.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_RoomMeshSet.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FRoomMeshSet, (UObject*)Z_Construct_UPackage__Script_EternalDescent(), TEXT("RoomMeshSet"));
	}
	return Z_Registration_Info_UScriptStruct_RoomMeshSet.OuterSingleton;
}
template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<FRoomMeshSet>()
{
	return FRoomMeshSet::StaticStruct();
}
struct Z_Construct_UScriptStruct_FRoomMeshSet_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FloorMesh_MetaData[] = {
		{ "Category", "Meshes" },
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WallMesh_MetaData[] = {
		{ "Category", "Meshes" },
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CeilingMesh_MetaData[] = {
		{ "Category", "Meshes" },
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DoorFrameMesh_MetaData[] = {
		{ "Category", "Meshes" },
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PillarMesh_MetaData[] = {
		{ "Category", "Meshes" },
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FloorMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WallMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CeilingMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DoorFrameMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PillarMesh;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FRoomMeshSet>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FRoomMeshSet_Statics::NewProp_FloorMesh = { "FloorMesh", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRoomMeshSet, FloorMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FloorMesh_MetaData), NewProp_FloorMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FRoomMeshSet_Statics::NewProp_WallMesh = { "WallMesh", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRoomMeshSet, WallMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WallMesh_MetaData), NewProp_WallMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FRoomMeshSet_Statics::NewProp_CeilingMesh = { "CeilingMesh", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRoomMeshSet, CeilingMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CeilingMesh_MetaData), NewProp_CeilingMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FRoomMeshSet_Statics::NewProp_DoorFrameMesh = { "DoorFrameMesh", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRoomMeshSet, DoorFrameMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DoorFrameMesh_MetaData), NewProp_DoorFrameMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FRoomMeshSet_Statics::NewProp_PillarMesh = { "PillarMesh", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRoomMeshSet, PillarMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PillarMesh_MetaData), NewProp_PillarMesh_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FRoomMeshSet_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRoomMeshSet_Statics::NewProp_FloorMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRoomMeshSet_Statics::NewProp_WallMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRoomMeshSet_Statics::NewProp_CeilingMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRoomMeshSet_Statics::NewProp_DoorFrameMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRoomMeshSet_Statics::NewProp_PillarMesh,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRoomMeshSet_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FRoomMeshSet_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_EternalDescent,
	nullptr,
	&NewStructOps,
	"RoomMeshSet",
	Z_Construct_UScriptStruct_FRoomMeshSet_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRoomMeshSet_Statics::PropPointers),
	sizeof(FRoomMeshSet),
	alignof(FRoomMeshSet),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRoomMeshSet_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FRoomMeshSet_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FRoomMeshSet()
{
	if (!Z_Registration_Info_UScriptStruct_RoomMeshSet.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_RoomMeshSet.InnerSingleton, Z_Construct_UScriptStruct_FRoomMeshSet_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_RoomMeshSet.InnerSingleton;
}
// End ScriptStruct FRoomMeshSet

// Begin ScriptStruct FRoomVisualData
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_RoomVisualData;
class UScriptStruct* FRoomVisualData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_RoomVisualData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_RoomVisualData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FRoomVisualData, (UObject*)Z_Construct_UPackage__Script_EternalDescent(), TEXT("RoomVisualData"));
	}
	return Z_Registration_Info_UScriptStruct_RoomVisualData.OuterSingleton;
}
template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<FRoomVisualData>()
{
	return FRoomVisualData::StaticStruct();
}
struct Z_Construct_UScriptStruct_FRoomVisualData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoomID_MetaData[] = {
		{ "Category", "RoomVisualData" },
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldPosition_MetaData[] = {
		{ "Category", "RoomVisualData" },
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoomSize_MetaData[] = {
		{ "Category", "RoomVisualData" },
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoomType_MetaData[] = {
		{ "Category", "RoomVisualData" },
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnedActors_MetaData[] = {
		{ "Category", "RoomVisualData" },
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ConnectedRoomIDs_MetaData[] = {
		{ "Category", "RoomVisualData" },
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_RoomID;
	static const UECodeGen_Private::FStructPropertyParams NewProp_WorldPosition;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RoomSize;
	static const UECodeGen_Private::FBytePropertyParams NewProp_RoomType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_RoomType;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpawnedActors_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_SpawnedActors;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ConnectedRoomIDs_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ConnectedRoomIDs;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FRoomVisualData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FRoomVisualData_Statics::NewProp_RoomID = { "RoomID", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRoomVisualData, RoomID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoomID_MetaData), NewProp_RoomID_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FRoomVisualData_Statics::NewProp_WorldPosition = { "WorldPosition", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRoomVisualData, WorldPosition), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldPosition_MetaData), NewProp_WorldPosition_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FRoomVisualData_Statics::NewProp_RoomSize = { "RoomSize", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRoomVisualData, RoomSize), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoomSize_MetaData), NewProp_RoomSize_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FRoomVisualData_Statics::NewProp_RoomType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FRoomVisualData_Statics::NewProp_RoomType = { "RoomType", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRoomVisualData, RoomType), Z_Construct_UEnum_EternalDescent_ERoomType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoomType_MetaData), NewProp_RoomType_MetaData) }; // 1291513837
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FRoomVisualData_Statics::NewProp_SpawnedActors_Inner = { "SpawnedActors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FRoomVisualData_Statics::NewProp_SpawnedActors = { "SpawnedActors", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRoomVisualData, SpawnedActors), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnedActors_MetaData), NewProp_SpawnedActors_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FRoomVisualData_Statics::NewProp_ConnectedRoomIDs_Inner = { "ConnectedRoomIDs", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FRoomVisualData_Statics::NewProp_ConnectedRoomIDs = { "ConnectedRoomIDs", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRoomVisualData, ConnectedRoomIDs), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ConnectedRoomIDs_MetaData), NewProp_ConnectedRoomIDs_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FRoomVisualData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRoomVisualData_Statics::NewProp_RoomID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRoomVisualData_Statics::NewProp_WorldPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRoomVisualData_Statics::NewProp_RoomSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRoomVisualData_Statics::NewProp_RoomType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRoomVisualData_Statics::NewProp_RoomType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRoomVisualData_Statics::NewProp_SpawnedActors_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRoomVisualData_Statics::NewProp_SpawnedActors,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRoomVisualData_Statics::NewProp_ConnectedRoomIDs_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRoomVisualData_Statics::NewProp_ConnectedRoomIDs,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRoomVisualData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FRoomVisualData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_EternalDescent,
	nullptr,
	&NewStructOps,
	"RoomVisualData",
	Z_Construct_UScriptStruct_FRoomVisualData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRoomVisualData_Statics::PropPointers),
	sizeof(FRoomVisualData),
	alignof(FRoomVisualData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRoomVisualData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FRoomVisualData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FRoomVisualData()
{
	if (!Z_Registration_Info_UScriptStruct_RoomVisualData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_RoomVisualData.InnerSingleton, Z_Construct_UScriptStruct_FRoomVisualData_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_RoomVisualData.InnerSingleton;
}
// End ScriptStruct FRoomVisualData

// Begin Class ADungeonVisualizer Function ApplyLighting
struct Z_Construct_UFunction_ADungeonVisualizer_ApplyLighting_Statics
{
	struct DungeonVisualizer_eventApplyLighting_Parms
	{
		FRoomVisualData Room;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dungeon|Visuals" },
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Room_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Room;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ADungeonVisualizer_ApplyLighting_Statics::NewProp_Room = { "Room", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DungeonVisualizer_eventApplyLighting_Parms, Room), Z_Construct_UScriptStruct_FRoomVisualData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Room_MetaData), NewProp_Room_MetaData) }; // 601754977
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADungeonVisualizer_ApplyLighting_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADungeonVisualizer_ApplyLighting_Statics::NewProp_Room,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_ApplyLighting_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADungeonVisualizer_ApplyLighting_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADungeonVisualizer, nullptr, "ApplyLighting", nullptr, nullptr, Z_Construct_UFunction_ADungeonVisualizer_ApplyLighting_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_ApplyLighting_Statics::PropPointers), sizeof(Z_Construct_UFunction_ADungeonVisualizer_ApplyLighting_Statics::DungeonVisualizer_eventApplyLighting_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_ApplyLighting_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADungeonVisualizer_ApplyLighting_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ADungeonVisualizer_ApplyLighting_Statics::DungeonVisualizer_eventApplyLighting_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADungeonVisualizer_ApplyLighting()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADungeonVisualizer_ApplyLighting_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ADungeonVisualizer::execApplyLighting)
{
	P_GET_STRUCT_REF(FRoomVisualData,Z_Param_Out_Room);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ApplyLighting(Z_Param_Out_Room);
	P_NATIVE_END;
}
// End Class ADungeonVisualizer Function ApplyLighting

// Begin Class ADungeonVisualizer Function ClearDungeon
struct Z_Construct_UFunction_ADungeonVisualizer_ClearDungeon_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dungeon|Generation" },
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADungeonVisualizer_ClearDungeon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADungeonVisualizer, nullptr, "ClearDungeon", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_ClearDungeon_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADungeonVisualizer_ClearDungeon_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ADungeonVisualizer_ClearDungeon()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADungeonVisualizer_ClearDungeon_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ADungeonVisualizer::execClearDungeon)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClearDungeon();
	P_NATIVE_END;
}
// End Class ADungeonVisualizer Function ClearDungeon

// Begin Class ADungeonVisualizer Function CreateHallwayPath
struct Z_Construct_UFunction_ADungeonVisualizer_CreateHallwayPath_Statics
{
	struct DungeonVisualizer_eventCreateHallwayPath_Parms
	{
		FVector StartPos;
		FVector EndPos;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dungeon|Hallways" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Hallway Functions\n" },
#endif
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Hallway Functions" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_StartPos;
	static const UECodeGen_Private::FStructPropertyParams NewProp_EndPos;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ADungeonVisualizer_CreateHallwayPath_Statics::NewProp_StartPos = { "StartPos", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DungeonVisualizer_eventCreateHallwayPath_Parms, StartPos), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ADungeonVisualizer_CreateHallwayPath_Statics::NewProp_EndPos = { "EndPos", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DungeonVisualizer_eventCreateHallwayPath_Parms, EndPos), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADungeonVisualizer_CreateHallwayPath_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADungeonVisualizer_CreateHallwayPath_Statics::NewProp_StartPos,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADungeonVisualizer_CreateHallwayPath_Statics::NewProp_EndPos,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_CreateHallwayPath_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADungeonVisualizer_CreateHallwayPath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADungeonVisualizer, nullptr, "CreateHallwayPath", nullptr, nullptr, Z_Construct_UFunction_ADungeonVisualizer_CreateHallwayPath_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_CreateHallwayPath_Statics::PropPointers), sizeof(Z_Construct_UFunction_ADungeonVisualizer_CreateHallwayPath_Statics::DungeonVisualizer_eventCreateHallwayPath_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_CreateHallwayPath_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADungeonVisualizer_CreateHallwayPath_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ADungeonVisualizer_CreateHallwayPath_Statics::DungeonVisualizer_eventCreateHallwayPath_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADungeonVisualizer_CreateHallwayPath()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADungeonVisualizer_CreateHallwayPath_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ADungeonVisualizer::execCreateHallwayPath)
{
	P_GET_STRUCT(FVector,Z_Param_StartPos);
	P_GET_STRUCT(FVector,Z_Param_EndPos);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CreateHallwayPath(Z_Param_StartPos,Z_Param_EndPos);
	P_NATIVE_END;
}
// End Class ADungeonVisualizer Function CreateHallwayPath

// Begin Class ADungeonVisualizer Function GenerateAndVisualizeDungeon
struct Z_Construct_UFunction_ADungeonVisualizer_GenerateAndVisualizeDungeon_Statics
{
	struct DungeonVisualizer_eventGenerateAndVisualizeDungeon_Parms
	{
		int32 Seed;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dungeon|Generation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Core Generation Functions\n" },
#endif
		{ "CPP_Default_Seed", "-1" },
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Core Generation Functions" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_Seed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ADungeonVisualizer_GenerateAndVisualizeDungeon_Statics::NewProp_Seed = { "Seed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DungeonVisualizer_eventGenerateAndVisualizeDungeon_Parms, Seed), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADungeonVisualizer_GenerateAndVisualizeDungeon_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADungeonVisualizer_GenerateAndVisualizeDungeon_Statics::NewProp_Seed,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_GenerateAndVisualizeDungeon_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADungeonVisualizer_GenerateAndVisualizeDungeon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADungeonVisualizer, nullptr, "GenerateAndVisualizeDungeon", nullptr, nullptr, Z_Construct_UFunction_ADungeonVisualizer_GenerateAndVisualizeDungeon_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_GenerateAndVisualizeDungeon_Statics::PropPointers), sizeof(Z_Construct_UFunction_ADungeonVisualizer_GenerateAndVisualizeDungeon_Statics::DungeonVisualizer_eventGenerateAndVisualizeDungeon_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_GenerateAndVisualizeDungeon_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADungeonVisualizer_GenerateAndVisualizeDungeon_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ADungeonVisualizer_GenerateAndVisualizeDungeon_Statics::DungeonVisualizer_eventGenerateAndVisualizeDungeon_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADungeonVisualizer_GenerateAndVisualizeDungeon()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADungeonVisualizer_GenerateAndVisualizeDungeon_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ADungeonVisualizer::execGenerateAndVisualizeDungeon)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_Seed);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->GenerateAndVisualizeDungeon(Z_Param_Seed);
	P_NATIVE_END;
}
// End Class ADungeonVisualizer Function GenerateAndVisualizeDungeon

// Begin Class ADungeonVisualizer Function GetRoomVisualData
struct Z_Construct_UFunction_ADungeonVisualizer_GetRoomVisualData_Statics
{
	struct DungeonVisualizer_eventGetRoomVisualData_Parms
	{
		int32 RoomID;
		FRoomVisualData ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dungeon|Utility" },
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_RoomID;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ADungeonVisualizer_GetRoomVisualData_Statics::NewProp_RoomID = { "RoomID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DungeonVisualizer_eventGetRoomVisualData_Parms, RoomID), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ADungeonVisualizer_GetRoomVisualData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DungeonVisualizer_eventGetRoomVisualData_Parms, ReturnValue), Z_Construct_UScriptStruct_FRoomVisualData, METADATA_PARAMS(0, nullptr) }; // 601754977
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADungeonVisualizer_GetRoomVisualData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADungeonVisualizer_GetRoomVisualData_Statics::NewProp_RoomID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADungeonVisualizer_GetRoomVisualData_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_GetRoomVisualData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADungeonVisualizer_GetRoomVisualData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADungeonVisualizer, nullptr, "GetRoomVisualData", nullptr, nullptr, Z_Construct_UFunction_ADungeonVisualizer_GetRoomVisualData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_GetRoomVisualData_Statics::PropPointers), sizeof(Z_Construct_UFunction_ADungeonVisualizer_GetRoomVisualData_Statics::DungeonVisualizer_eventGetRoomVisualData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_GetRoomVisualData_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADungeonVisualizer_GetRoomVisualData_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ADungeonVisualizer_GetRoomVisualData_Statics::DungeonVisualizer_eventGetRoomVisualData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADungeonVisualizer_GetRoomVisualData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADungeonVisualizer_GetRoomVisualData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ADungeonVisualizer::execGetRoomVisualData)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_RoomID);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FRoomVisualData*)Z_Param__Result=P_THIS->GetRoomVisualData(Z_Param_RoomID);
	P_NATIVE_END;
}
// End Class ADungeonVisualizer Function GetRoomVisualData

// Begin Class ADungeonVisualizer Function GetStartRoomPosition
struct Z_Construct_UFunction_ADungeonVisualizer_GetStartRoomPosition_Statics
{
	struct DungeonVisualizer_eventGetStartRoomPosition_Parms
	{
		FVector ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dungeon|Player" },
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ADungeonVisualizer_GetStartRoomPosition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DungeonVisualizer_eventGetStartRoomPosition_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADungeonVisualizer_GetStartRoomPosition_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADungeonVisualizer_GetStartRoomPosition_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_GetStartRoomPosition_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADungeonVisualizer_GetStartRoomPosition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADungeonVisualizer, nullptr, "GetStartRoomPosition", nullptr, nullptr, Z_Construct_UFunction_ADungeonVisualizer_GetStartRoomPosition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_GetStartRoomPosition_Statics::PropPointers), sizeof(Z_Construct_UFunction_ADungeonVisualizer_GetStartRoomPosition_Statics::DungeonVisualizer_eventGetStartRoomPosition_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_GetStartRoomPosition_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADungeonVisualizer_GetStartRoomPosition_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ADungeonVisualizer_GetStartRoomPosition_Statics::DungeonVisualizer_eventGetStartRoomPosition_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADungeonVisualizer_GetStartRoomPosition()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADungeonVisualizer_GetStartRoomPosition_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ADungeonVisualizer::execGetStartRoomPosition)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FVector*)Z_Param__Result=P_THIS->GetStartRoomPosition();
	P_NATIVE_END;
}
// End Class ADungeonVisualizer Function GetStartRoomPosition

// Begin Class ADungeonVisualizer Function GridToWorldPosition
struct Z_Construct_UFunction_ADungeonVisualizer_GridToWorldPosition_Statics
{
	struct DungeonVisualizer_eventGridToWorldPosition_Parms
	{
		FIntPoint GridPos;
		FVector ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dungeon|Utility" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Helper Functions\n" },
#endif
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Helper Functions" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_GridPos;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ADungeonVisualizer_GridToWorldPosition_Statics::NewProp_GridPos = { "GridPos", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DungeonVisualizer_eventGridToWorldPosition_Parms, GridPos), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ADungeonVisualizer_GridToWorldPosition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DungeonVisualizer_eventGridToWorldPosition_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADungeonVisualizer_GridToWorldPosition_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADungeonVisualizer_GridToWorldPosition_Statics::NewProp_GridPos,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADungeonVisualizer_GridToWorldPosition_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_GridToWorldPosition_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADungeonVisualizer_GridToWorldPosition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADungeonVisualizer, nullptr, "GridToWorldPosition", nullptr, nullptr, Z_Construct_UFunction_ADungeonVisualizer_GridToWorldPosition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_GridToWorldPosition_Statics::PropPointers), sizeof(Z_Construct_UFunction_ADungeonVisualizer_GridToWorldPosition_Statics::DungeonVisualizer_eventGridToWorldPosition_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_GridToWorldPosition_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADungeonVisualizer_GridToWorldPosition_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ADungeonVisualizer_GridToWorldPosition_Statics::DungeonVisualizer_eventGridToWorldPosition_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADungeonVisualizer_GridToWorldPosition()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADungeonVisualizer_GridToWorldPosition_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ADungeonVisualizer::execGridToWorldPosition)
{
	P_GET_STRUCT(FIntPoint,Z_Param_GridPos);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FVector*)Z_Param__Result=P_THIS->GridToWorldPosition(Z_Param_GridPos);
	P_NATIVE_END;
}
// End Class ADungeonVisualizer Function GridToWorldPosition

// Begin Class ADungeonVisualizer Function OnDoorSpawned
struct DungeonVisualizer_eventOnDoorSpawned_Parms
{
	FVector Position;
	bool bIsLocked;
};
static const FName NAME_ADungeonVisualizer_OnDoorSpawned = FName(TEXT("OnDoorSpawned"));
void ADungeonVisualizer::OnDoorSpawned(FVector Position, bool bIsLocked)
{
	DungeonVisualizer_eventOnDoorSpawned_Parms Parms;
	Parms.Position=Position;
	Parms.bIsLocked=bIsLocked ? true : false;
	UFunction* Func = FindFunctionChecked(NAME_ADungeonVisualizer_OnDoorSpawned);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_ADungeonVisualizer_OnDoorSpawned_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dungeon|Doors" },
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Position;
	static void NewProp_bIsLocked_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsLocked;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ADungeonVisualizer_OnDoorSpawned_Statics::NewProp_Position = { "Position", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DungeonVisualizer_eventOnDoorSpawned_Parms, Position), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_ADungeonVisualizer_OnDoorSpawned_Statics::NewProp_bIsLocked_SetBit(void* Obj)
{
	((DungeonVisualizer_eventOnDoorSpawned_Parms*)Obj)->bIsLocked = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ADungeonVisualizer_OnDoorSpawned_Statics::NewProp_bIsLocked = { "bIsLocked", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DungeonVisualizer_eventOnDoorSpawned_Parms), &Z_Construct_UFunction_ADungeonVisualizer_OnDoorSpawned_Statics::NewProp_bIsLocked_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADungeonVisualizer_OnDoorSpawned_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADungeonVisualizer_OnDoorSpawned_Statics::NewProp_Position,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADungeonVisualizer_OnDoorSpawned_Statics::NewProp_bIsLocked,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_OnDoorSpawned_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADungeonVisualizer_OnDoorSpawned_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADungeonVisualizer, nullptr, "OnDoorSpawned", nullptr, nullptr, Z_Construct_UFunction_ADungeonVisualizer_OnDoorSpawned_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_OnDoorSpawned_Statics::PropPointers), sizeof(DungeonVisualizer_eventOnDoorSpawned_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08820800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_OnDoorSpawned_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADungeonVisualizer_OnDoorSpawned_Statics::Function_MetaDataParams) };
static_assert(sizeof(DungeonVisualizer_eventOnDoorSpawned_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADungeonVisualizer_OnDoorSpawned()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADungeonVisualizer_OnDoorSpawned_Statics::FuncParams);
	}
	return ReturnFunction;
}
// End Class ADungeonVisualizer Function OnDoorSpawned

// Begin Class ADungeonVisualizer Function OnEnemySpawned
struct DungeonVisualizer_eventOnEnemySpawned_Parms
{
	FVector Position;
	FString EnemyType;
};
static const FName NAME_ADungeonVisualizer_OnEnemySpawned = FName(TEXT("OnEnemySpawned"));
void ADungeonVisualizer::OnEnemySpawned(FVector Position, const FString& EnemyType)
{
	DungeonVisualizer_eventOnEnemySpawned_Parms Parms;
	Parms.Position=Position;
	Parms.EnemyType=EnemyType;
	UFunction* Func = FindFunctionChecked(NAME_ADungeonVisualizer_OnEnemySpawned);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_ADungeonVisualizer_OnEnemySpawned_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dungeon|Enemies" },
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EnemyType_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Position;
	static const UECodeGen_Private::FStrPropertyParams NewProp_EnemyType;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ADungeonVisualizer_OnEnemySpawned_Statics::NewProp_Position = { "Position", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DungeonVisualizer_eventOnEnemySpawned_Parms, Position), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ADungeonVisualizer_OnEnemySpawned_Statics::NewProp_EnemyType = { "EnemyType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DungeonVisualizer_eventOnEnemySpawned_Parms, EnemyType), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EnemyType_MetaData), NewProp_EnemyType_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADungeonVisualizer_OnEnemySpawned_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADungeonVisualizer_OnEnemySpawned_Statics::NewProp_Position,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADungeonVisualizer_OnEnemySpawned_Statics::NewProp_EnemyType,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_OnEnemySpawned_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADungeonVisualizer_OnEnemySpawned_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADungeonVisualizer, nullptr, "OnEnemySpawned", nullptr, nullptr, Z_Construct_UFunction_ADungeonVisualizer_OnEnemySpawned_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_OnEnemySpawned_Statics::PropPointers), sizeof(DungeonVisualizer_eventOnEnemySpawned_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08820800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_OnEnemySpawned_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADungeonVisualizer_OnEnemySpawned_Statics::Function_MetaDataParams) };
static_assert(sizeof(DungeonVisualizer_eventOnEnemySpawned_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADungeonVisualizer_OnEnemySpawned()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADungeonVisualizer_OnEnemySpawned_Statics::FuncParams);
	}
	return ReturnFunction;
}
// End Class ADungeonVisualizer Function OnEnemySpawned

// Begin Class ADungeonVisualizer Function OnLootSpawned
struct DungeonVisualizer_eventOnLootSpawned_Parms
{
	FVector Position;
	FString LootType;
};
static const FName NAME_ADungeonVisualizer_OnLootSpawned = FName(TEXT("OnLootSpawned"));
void ADungeonVisualizer::OnLootSpawned(FVector Position, const FString& LootType)
{
	DungeonVisualizer_eventOnLootSpawned_Parms Parms;
	Parms.Position=Position;
	Parms.LootType=LootType;
	UFunction* Func = FindFunctionChecked(NAME_ADungeonVisualizer_OnLootSpawned);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_ADungeonVisualizer_OnLootSpawned_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dungeon|Loot" },
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LootType_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Position;
	static const UECodeGen_Private::FStrPropertyParams NewProp_LootType;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ADungeonVisualizer_OnLootSpawned_Statics::NewProp_Position = { "Position", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DungeonVisualizer_eventOnLootSpawned_Parms, Position), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ADungeonVisualizer_OnLootSpawned_Statics::NewProp_LootType = { "LootType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DungeonVisualizer_eventOnLootSpawned_Parms, LootType), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LootType_MetaData), NewProp_LootType_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADungeonVisualizer_OnLootSpawned_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADungeonVisualizer_OnLootSpawned_Statics::NewProp_Position,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADungeonVisualizer_OnLootSpawned_Statics::NewProp_LootType,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_OnLootSpawned_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADungeonVisualizer_OnLootSpawned_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADungeonVisualizer, nullptr, "OnLootSpawned", nullptr, nullptr, Z_Construct_UFunction_ADungeonVisualizer_OnLootSpawned_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_OnLootSpawned_Statics::PropPointers), sizeof(DungeonVisualizer_eventOnLootSpawned_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08820800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_OnLootSpawned_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADungeonVisualizer_OnLootSpawned_Statics::Function_MetaDataParams) };
static_assert(sizeof(DungeonVisualizer_eventOnLootSpawned_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADungeonVisualizer_OnLootSpawned()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADungeonVisualizer_OnLootSpawned_Statics::FuncParams);
	}
	return ReturnFunction;
}
// End Class ADungeonVisualizer Function OnLootSpawned

// Begin Class ADungeonVisualizer Function OnPlayerSpawned
struct DungeonVisualizer_eventOnPlayerSpawned_Parms
{
	FVector SpawnPosition;
};
static const FName NAME_ADungeonVisualizer_OnPlayerSpawned = FName(TEXT("OnPlayerSpawned"));
void ADungeonVisualizer::OnPlayerSpawned(FVector SpawnPosition)
{
	DungeonVisualizer_eventOnPlayerSpawned_Parms Parms;
	Parms.SpawnPosition=SpawnPosition;
	UFunction* Func = FindFunctionChecked(NAME_ADungeonVisualizer_OnPlayerSpawned);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_ADungeonVisualizer_OnPlayerSpawned_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dungeon|Player" },
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpawnPosition;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ADungeonVisualizer_OnPlayerSpawned_Statics::NewProp_SpawnPosition = { "SpawnPosition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DungeonVisualizer_eventOnPlayerSpawned_Parms, SpawnPosition), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADungeonVisualizer_OnPlayerSpawned_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADungeonVisualizer_OnPlayerSpawned_Statics::NewProp_SpawnPosition,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_OnPlayerSpawned_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADungeonVisualizer_OnPlayerSpawned_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADungeonVisualizer, nullptr, "OnPlayerSpawned", nullptr, nullptr, Z_Construct_UFunction_ADungeonVisualizer_OnPlayerSpawned_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_OnPlayerSpawned_Statics::PropPointers), sizeof(DungeonVisualizer_eventOnPlayerSpawned_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08820800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_OnPlayerSpawned_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADungeonVisualizer_OnPlayerSpawned_Statics::Function_MetaDataParams) };
static_assert(sizeof(DungeonVisualizer_eventOnPlayerSpawned_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADungeonVisualizer_OnPlayerSpawned()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADungeonVisualizer_OnPlayerSpawned_Statics::FuncParams);
	}
	return ReturnFunction;
}
// End Class ADungeonVisualizer Function OnPlayerSpawned

// Begin Class ADungeonVisualizer Function OnRoomSpawned
struct DungeonVisualizer_eventOnRoomSpawned_Parms
{
	FRoomVisualData RoomData;
};
static const FName NAME_ADungeonVisualizer_OnRoomSpawned = FName(TEXT("OnRoomSpawned"));
void ADungeonVisualizer::OnRoomSpawned(FRoomVisualData const& RoomData)
{
	DungeonVisualizer_eventOnRoomSpawned_Parms Parms;
	Parms.RoomData=RoomData;
	UFunction* Func = FindFunctionChecked(NAME_ADungeonVisualizer_OnRoomSpawned);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_ADungeonVisualizer_OnRoomSpawned_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dungeon|Rooms" },
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoomData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_RoomData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ADungeonVisualizer_OnRoomSpawned_Statics::NewProp_RoomData = { "RoomData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DungeonVisualizer_eventOnRoomSpawned_Parms, RoomData), Z_Construct_UScriptStruct_FRoomVisualData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoomData_MetaData), NewProp_RoomData_MetaData) }; // 601754977
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADungeonVisualizer_OnRoomSpawned_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADungeonVisualizer_OnRoomSpawned_Statics::NewProp_RoomData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_OnRoomSpawned_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADungeonVisualizer_OnRoomSpawned_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADungeonVisualizer, nullptr, "OnRoomSpawned", nullptr, nullptr, Z_Construct_UFunction_ADungeonVisualizer_OnRoomSpawned_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_OnRoomSpawned_Statics::PropPointers), sizeof(DungeonVisualizer_eventOnRoomSpawned_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_OnRoomSpawned_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADungeonVisualizer_OnRoomSpawned_Statics::Function_MetaDataParams) };
static_assert(sizeof(DungeonVisualizer_eventOnRoomSpawned_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADungeonVisualizer_OnRoomSpawned()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADungeonVisualizer_OnRoomSpawned_Statics::FuncParams);
	}
	return ReturnFunction;
}
// End Class ADungeonVisualizer Function OnRoomSpawned

// Begin Class ADungeonVisualizer Function SetRoomTheme
struct Z_Construct_UFunction_ADungeonVisualizer_SetRoomTheme_Statics
{
	struct DungeonVisualizer_eventSetRoomTheme_Parms
	{
		int32 FloorNumber;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dungeon|Visuals" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Visual Settings\n" },
#endif
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Visual Settings" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_FloorNumber;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ADungeonVisualizer_SetRoomTheme_Statics::NewProp_FloorNumber = { "FloorNumber", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DungeonVisualizer_eventSetRoomTheme_Parms, FloorNumber), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADungeonVisualizer_SetRoomTheme_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADungeonVisualizer_SetRoomTheme_Statics::NewProp_FloorNumber,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_SetRoomTheme_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADungeonVisualizer_SetRoomTheme_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADungeonVisualizer, nullptr, "SetRoomTheme", nullptr, nullptr, Z_Construct_UFunction_ADungeonVisualizer_SetRoomTheme_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_SetRoomTheme_Statics::PropPointers), sizeof(Z_Construct_UFunction_ADungeonVisualizer_SetRoomTheme_Statics::DungeonVisualizer_eventSetRoomTheme_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_SetRoomTheme_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADungeonVisualizer_SetRoomTheme_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ADungeonVisualizer_SetRoomTheme_Statics::DungeonVisualizer_eventSetRoomTheme_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADungeonVisualizer_SetRoomTheme()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADungeonVisualizer_SetRoomTheme_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ADungeonVisualizer::execSetRoomTheme)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_FloorNumber);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetRoomTheme(Z_Param_FloorNumber);
	P_NATIVE_END;
}
// End Class ADungeonVisualizer Function SetRoomTheme

// Begin Class ADungeonVisualizer Function SpawnDoor
struct Z_Construct_UFunction_ADungeonVisualizer_SpawnDoor_Statics
{
	struct DungeonVisualizer_eventSpawnDoor_Parms
	{
		FVector Position;
		FRotator Rotation;
		bool bIsLocked;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dungeon|Doors" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Door System\n" },
#endif
		{ "CPP_Default_bIsLocked", "false" },
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Door System" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Position;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Rotation;
	static void NewProp_bIsLocked_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsLocked;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ADungeonVisualizer_SpawnDoor_Statics::NewProp_Position = { "Position", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DungeonVisualizer_eventSpawnDoor_Parms, Position), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ADungeonVisualizer_SpawnDoor_Statics::NewProp_Rotation = { "Rotation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DungeonVisualizer_eventSpawnDoor_Parms, Rotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_ADungeonVisualizer_SpawnDoor_Statics::NewProp_bIsLocked_SetBit(void* Obj)
{
	((DungeonVisualizer_eventSpawnDoor_Parms*)Obj)->bIsLocked = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ADungeonVisualizer_SpawnDoor_Statics::NewProp_bIsLocked = { "bIsLocked", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DungeonVisualizer_eventSpawnDoor_Parms), &Z_Construct_UFunction_ADungeonVisualizer_SpawnDoor_Statics::NewProp_bIsLocked_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADungeonVisualizer_SpawnDoor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADungeonVisualizer_SpawnDoor_Statics::NewProp_Position,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADungeonVisualizer_SpawnDoor_Statics::NewProp_Rotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADungeonVisualizer_SpawnDoor_Statics::NewProp_bIsLocked,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_SpawnDoor_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADungeonVisualizer_SpawnDoor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADungeonVisualizer, nullptr, "SpawnDoor", nullptr, nullptr, Z_Construct_UFunction_ADungeonVisualizer_SpawnDoor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_SpawnDoor_Statics::PropPointers), sizeof(Z_Construct_UFunction_ADungeonVisualizer_SpawnDoor_Statics::DungeonVisualizer_eventSpawnDoor_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_SpawnDoor_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADungeonVisualizer_SpawnDoor_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ADungeonVisualizer_SpawnDoor_Statics::DungeonVisualizer_eventSpawnDoor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADungeonVisualizer_SpawnDoor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADungeonVisualizer_SpawnDoor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ADungeonVisualizer::execSpawnDoor)
{
	P_GET_STRUCT(FVector,Z_Param_Position);
	P_GET_STRUCT(FRotator,Z_Param_Rotation);
	P_GET_UBOOL(Z_Param_bIsLocked);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SpawnDoor(Z_Param_Position,Z_Param_Rotation,Z_Param_bIsLocked);
	P_NATIVE_END;
}
// End Class ADungeonVisualizer Function SpawnDoor

// Begin Class ADungeonVisualizer Function SpawnEnemiesInRoom
struct Z_Construct_UFunction_ADungeonVisualizer_SpawnEnemiesInRoom_Statics
{
	struct DungeonVisualizer_eventSpawnEnemiesInRoom_Parms
	{
		FRoomVisualData Room;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dungeon|Enemies" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Enemy Spawning\n" },
#endif
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Enemy Spawning" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Room_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Room;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ADungeonVisualizer_SpawnEnemiesInRoom_Statics::NewProp_Room = { "Room", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DungeonVisualizer_eventSpawnEnemiesInRoom_Parms, Room), Z_Construct_UScriptStruct_FRoomVisualData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Room_MetaData), NewProp_Room_MetaData) }; // 601754977
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADungeonVisualizer_SpawnEnemiesInRoom_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADungeonVisualizer_SpawnEnemiesInRoom_Statics::NewProp_Room,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_SpawnEnemiesInRoom_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADungeonVisualizer_SpawnEnemiesInRoom_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADungeonVisualizer, nullptr, "SpawnEnemiesInRoom", nullptr, nullptr, Z_Construct_UFunction_ADungeonVisualizer_SpawnEnemiesInRoom_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_SpawnEnemiesInRoom_Statics::PropPointers), sizeof(Z_Construct_UFunction_ADungeonVisualizer_SpawnEnemiesInRoom_Statics::DungeonVisualizer_eventSpawnEnemiesInRoom_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_SpawnEnemiesInRoom_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADungeonVisualizer_SpawnEnemiesInRoom_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ADungeonVisualizer_SpawnEnemiesInRoom_Statics::DungeonVisualizer_eventSpawnEnemiesInRoom_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADungeonVisualizer_SpawnEnemiesInRoom()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADungeonVisualizer_SpawnEnemiesInRoom_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ADungeonVisualizer::execSpawnEnemiesInRoom)
{
	P_GET_STRUCT_REF(FRoomVisualData,Z_Param_Out_Room);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SpawnEnemiesInRoom(Z_Param_Out_Room);
	P_NATIVE_END;
}
// End Class ADungeonVisualizer Function SpawnEnemiesInRoom

// Begin Class ADungeonVisualizer Function SpawnLootInRoom
struct Z_Construct_UFunction_ADungeonVisualizer_SpawnLootInRoom_Statics
{
	struct DungeonVisualizer_eventSpawnLootInRoom_Parms
	{
		FRoomVisualData Room;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dungeon|Loot" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Loot & Items\n" },
#endif
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Loot & Items" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Room_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Room;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ADungeonVisualizer_SpawnLootInRoom_Statics::NewProp_Room = { "Room", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DungeonVisualizer_eventSpawnLootInRoom_Parms, Room), Z_Construct_UScriptStruct_FRoomVisualData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Room_MetaData), NewProp_Room_MetaData) }; // 601754977
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADungeonVisualizer_SpawnLootInRoom_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADungeonVisualizer_SpawnLootInRoom_Statics::NewProp_Room,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_SpawnLootInRoom_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADungeonVisualizer_SpawnLootInRoom_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADungeonVisualizer, nullptr, "SpawnLootInRoom", nullptr, nullptr, Z_Construct_UFunction_ADungeonVisualizer_SpawnLootInRoom_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_SpawnLootInRoom_Statics::PropPointers), sizeof(Z_Construct_UFunction_ADungeonVisualizer_SpawnLootInRoom_Statics::DungeonVisualizer_eventSpawnLootInRoom_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_SpawnLootInRoom_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADungeonVisualizer_SpawnLootInRoom_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ADungeonVisualizer_SpawnLootInRoom_Statics::DungeonVisualizer_eventSpawnLootInRoom_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADungeonVisualizer_SpawnLootInRoom()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADungeonVisualizer_SpawnLootInRoom_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ADungeonVisualizer::execSpawnLootInRoom)
{
	P_GET_STRUCT_REF(FRoomVisualData,Z_Param_Out_Room);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SpawnLootInRoom(Z_Param_Out_Room);
	P_NATIVE_END;
}
// End Class ADungeonVisualizer Function SpawnLootInRoom

// Begin Class ADungeonVisualizer Function SpawnPlayerAtStart
struct Z_Construct_UFunction_ADungeonVisualizer_SpawnPlayerAtStart_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dungeon|Player" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Player Functions\n" },
#endif
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Player Functions" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADungeonVisualizer_SpawnPlayerAtStart_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADungeonVisualizer, nullptr, "SpawnPlayerAtStart", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_SpawnPlayerAtStart_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADungeonVisualizer_SpawnPlayerAtStart_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ADungeonVisualizer_SpawnPlayerAtStart()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADungeonVisualizer_SpawnPlayerAtStart_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ADungeonVisualizer::execSpawnPlayerAtStart)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SpawnPlayerAtStart();
	P_NATIVE_END;
}
// End Class ADungeonVisualizer Function SpawnPlayerAtStart

// Begin Class ADungeonVisualizer Function SpawnRoom
struct Z_Construct_UFunction_ADungeonVisualizer_SpawnRoom_Statics
{
	struct DungeonVisualizer_eventSpawnRoom_Parms
	{
		FRoomData RoomData;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dungeon|Rooms" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Room Spawning Functions\n" },
#endif
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Room Spawning Functions" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoomData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_RoomData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ADungeonVisualizer_SpawnRoom_Statics::NewProp_RoomData = { "RoomData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DungeonVisualizer_eventSpawnRoom_Parms, RoomData), Z_Construct_UScriptStruct_FRoomData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoomData_MetaData), NewProp_RoomData_MetaData) }; // 987753016
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADungeonVisualizer_SpawnRoom_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADungeonVisualizer_SpawnRoom_Statics::NewProp_RoomData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_SpawnRoom_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADungeonVisualizer_SpawnRoom_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADungeonVisualizer, nullptr, "SpawnRoom", nullptr, nullptr, Z_Construct_UFunction_ADungeonVisualizer_SpawnRoom_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_SpawnRoom_Statics::PropPointers), sizeof(Z_Construct_UFunction_ADungeonVisualizer_SpawnRoom_Statics::DungeonVisualizer_eventSpawnRoom_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_SpawnRoom_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADungeonVisualizer_SpawnRoom_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ADungeonVisualizer_SpawnRoom_Statics::DungeonVisualizer_eventSpawnRoom_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADungeonVisualizer_SpawnRoom()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADungeonVisualizer_SpawnRoom_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ADungeonVisualizer::execSpawnRoom)
{
	P_GET_STRUCT_REF(FRoomData,Z_Param_Out_RoomData);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SpawnRoom(Z_Param_Out_RoomData);
	P_NATIVE_END;
}
// End Class ADungeonVisualizer Function SpawnRoom

// Begin Class ADungeonVisualizer Function SpawnRoomMeshes
struct Z_Construct_UFunction_ADungeonVisualizer_SpawnRoomMeshes_Statics
{
	struct DungeonVisualizer_eventSpawnRoomMeshes_Parms
	{
		FRoomVisualData RoomVisual;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dungeon|Rooms" },
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoomVisual_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_RoomVisual;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ADungeonVisualizer_SpawnRoomMeshes_Statics::NewProp_RoomVisual = { "RoomVisual", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DungeonVisualizer_eventSpawnRoomMeshes_Parms, RoomVisual), Z_Construct_UScriptStruct_FRoomVisualData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoomVisual_MetaData), NewProp_RoomVisual_MetaData) }; // 601754977
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADungeonVisualizer_SpawnRoomMeshes_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADungeonVisualizer_SpawnRoomMeshes_Statics::NewProp_RoomVisual,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_SpawnRoomMeshes_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADungeonVisualizer_SpawnRoomMeshes_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADungeonVisualizer, nullptr, "SpawnRoomMeshes", nullptr, nullptr, Z_Construct_UFunction_ADungeonVisualizer_SpawnRoomMeshes_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_SpawnRoomMeshes_Statics::PropPointers), sizeof(Z_Construct_UFunction_ADungeonVisualizer_SpawnRoomMeshes_Statics::DungeonVisualizer_eventSpawnRoomMeshes_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_SpawnRoomMeshes_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADungeonVisualizer_SpawnRoomMeshes_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ADungeonVisualizer_SpawnRoomMeshes_Statics::DungeonVisualizer_eventSpawnRoomMeshes_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADungeonVisualizer_SpawnRoomMeshes()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADungeonVisualizer_SpawnRoomMeshes_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ADungeonVisualizer::execSpawnRoomMeshes)
{
	P_GET_STRUCT_REF(FRoomVisualData,Z_Param_Out_RoomVisual);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SpawnRoomMeshes(Z_Param_Out_RoomVisual);
	P_NATIVE_END;
}
// End Class ADungeonVisualizer Function SpawnRoomMeshes

// Begin Class ADungeonVisualizer Function VisualizeDungeonLayout
struct Z_Construct_UFunction_ADungeonVisualizer_VisualizeDungeonLayout_Statics
{
	struct DungeonVisualizer_eventVisualizeDungeonLayout_Parms
	{
		FDungeonLayout Layout;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dungeon|Generation" },
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Layout_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Layout;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ADungeonVisualizer_VisualizeDungeonLayout_Statics::NewProp_Layout = { "Layout", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DungeonVisualizer_eventVisualizeDungeonLayout_Parms, Layout), Z_Construct_UScriptStruct_FDungeonLayout, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Layout_MetaData), NewProp_Layout_MetaData) }; // 3903890264
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADungeonVisualizer_VisualizeDungeonLayout_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADungeonVisualizer_VisualizeDungeonLayout_Statics::NewProp_Layout,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_VisualizeDungeonLayout_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADungeonVisualizer_VisualizeDungeonLayout_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADungeonVisualizer, nullptr, "VisualizeDungeonLayout", nullptr, nullptr, Z_Construct_UFunction_ADungeonVisualizer_VisualizeDungeonLayout_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_VisualizeDungeonLayout_Statics::PropPointers), sizeof(Z_Construct_UFunction_ADungeonVisualizer_VisualizeDungeonLayout_Statics::DungeonVisualizer_eventVisualizeDungeonLayout_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_VisualizeDungeonLayout_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADungeonVisualizer_VisualizeDungeonLayout_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ADungeonVisualizer_VisualizeDungeonLayout_Statics::DungeonVisualizer_eventVisualizeDungeonLayout_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADungeonVisualizer_VisualizeDungeonLayout()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADungeonVisualizer_VisualizeDungeonLayout_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ADungeonVisualizer::execVisualizeDungeonLayout)
{
	P_GET_STRUCT_REF(FDungeonLayout,Z_Param_Out_Layout);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->VisualizeDungeonLayout(Z_Param_Out_Layout);
	P_NATIVE_END;
}
// End Class ADungeonVisualizer Function VisualizeDungeonLayout

// Begin Class ADungeonVisualizer Function WorldToGridPosition
struct Z_Construct_UFunction_ADungeonVisualizer_WorldToGridPosition_Statics
{
	struct DungeonVisualizer_eventWorldToGridPosition_Parms
	{
		FVector WorldPos;
		FIntPoint ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dungeon|Utility" },
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_WorldPos;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ADungeonVisualizer_WorldToGridPosition_Statics::NewProp_WorldPos = { "WorldPos", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DungeonVisualizer_eventWorldToGridPosition_Parms, WorldPos), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ADungeonVisualizer_WorldToGridPosition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DungeonVisualizer_eventWorldToGridPosition_Parms, ReturnValue), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADungeonVisualizer_WorldToGridPosition_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADungeonVisualizer_WorldToGridPosition_Statics::NewProp_WorldPos,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADungeonVisualizer_WorldToGridPosition_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_WorldToGridPosition_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADungeonVisualizer_WorldToGridPosition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADungeonVisualizer, nullptr, "WorldToGridPosition", nullptr, nullptr, Z_Construct_UFunction_ADungeonVisualizer_WorldToGridPosition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_WorldToGridPosition_Statics::PropPointers), sizeof(Z_Construct_UFunction_ADungeonVisualizer_WorldToGridPosition_Statics::DungeonVisualizer_eventWorldToGridPosition_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADungeonVisualizer_WorldToGridPosition_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADungeonVisualizer_WorldToGridPosition_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ADungeonVisualizer_WorldToGridPosition_Statics::DungeonVisualizer_eventWorldToGridPosition_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADungeonVisualizer_WorldToGridPosition()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADungeonVisualizer_WorldToGridPosition_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ADungeonVisualizer::execWorldToGridPosition)
{
	P_GET_STRUCT(FVector,Z_Param_WorldPos);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FIntPoint*)Z_Param__Result=P_THIS->WorldToGridPosition(Z_Param_WorldPos);
	P_NATIVE_END;
}
// End Class ADungeonVisualizer Function WorldToGridPosition

// Begin Class ADungeonVisualizer
void ADungeonVisualizer::StaticRegisterNativesADungeonVisualizer()
{
	UClass* Class = ADungeonVisualizer::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ApplyLighting", &ADungeonVisualizer::execApplyLighting },
		{ "ClearDungeon", &ADungeonVisualizer::execClearDungeon },
		{ "CreateHallwayPath", &ADungeonVisualizer::execCreateHallwayPath },
		{ "GenerateAndVisualizeDungeon", &ADungeonVisualizer::execGenerateAndVisualizeDungeon },
		{ "GetRoomVisualData", &ADungeonVisualizer::execGetRoomVisualData },
		{ "GetStartRoomPosition", &ADungeonVisualizer::execGetStartRoomPosition },
		{ "GridToWorldPosition", &ADungeonVisualizer::execGridToWorldPosition },
		{ "SetRoomTheme", &ADungeonVisualizer::execSetRoomTheme },
		{ "SpawnDoor", &ADungeonVisualizer::execSpawnDoor },
		{ "SpawnEnemiesInRoom", &ADungeonVisualizer::execSpawnEnemiesInRoom },
		{ "SpawnLootInRoom", &ADungeonVisualizer::execSpawnLootInRoom },
		{ "SpawnPlayerAtStart", &ADungeonVisualizer::execSpawnPlayerAtStart },
		{ "SpawnRoom", &ADungeonVisualizer::execSpawnRoom },
		{ "SpawnRoomMeshes", &ADungeonVisualizer::execSpawnRoomMeshes },
		{ "VisualizeDungeonLayout", &ADungeonVisualizer::execVisualizeDungeonLayout },
		{ "WorldToGridPosition", &ADungeonVisualizer::execWorldToGridPosition },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ADungeonVisualizer);
UClass* Z_Construct_UClass_ADungeonVisualizer_NoRegister()
{
	return ADungeonVisualizer::StaticClass();
}
struct Z_Construct_UClass_ADungeonVisualizer_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "DungeonVisualizer.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CellSize_MetaData[] = {
		{ "Category", "Dungeon|Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Properties\n" },
#endif
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Properties" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WallHeight_MetaData[] = {
		{ "Category", "Dungeon|Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Size of one grid cell in world units\n" },
#endif
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Size of one grid cell in world units" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HallwayWidth_MetaData[] = {
		{ "Category", "Dungeon|Settings" },
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutoGenerateOnBeginPlay_MetaData[] = {
		{ "Category", "Dungeon|Settings" },
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentFloor_MetaData[] = {
		{ "Category", "Dungeon|Settings" },
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StandardRoomMeshes_MetaData[] = {
		{ "Category", "Dungeon|Meshes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Mesh Sets for Different Room Types\n" },
#endif
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Mesh Sets for Different Room Types" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TreasureRoomMeshes_MetaData[] = {
		{ "Category", "Dungeon|Meshes" },
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShopRoomMeshes_MetaData[] = {
		{ "Category", "Dungeon|Meshes" },
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BossRoomMeshes_MetaData[] = {
		{ "Category", "Dungeon|Meshes" },
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HallwayFloorMesh_MetaData[] = {
		{ "Category", "Dungeon|Meshes" },
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HallwayWallMesh_MetaData[] = {
		{ "Category", "Dungeon|Meshes" },
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DoorActorClass_MetaData[] = {
		{ "Category", "Dungeon|Classes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Blueprint Actor Classes\n" },
#endif
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Blueprint Actor Classes" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ChestActorClass_MetaData[] = {
		{ "Category", "Dungeon|Classes" },
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EnemySpawnerClass_MetaData[] = {
		{ "Category", "Dungeon|Classes" },
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractableClass_MetaData[] = {
		{ "Category", "Dungeon|Classes" },
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EnemyClasses_MetaData[] = {
		{ "Category", "Dungeon|Enemies" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Enemy Types per Floor\n" },
#endif
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Enemy Types per Floor" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ADASystem_MetaData[] = {
		{ "Category", "Dungeon|References" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// References\n" },
#endif
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "References" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VisualizedRooms_MetaData[] = {
		{ "Category", "Dungeon|Runtime" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Runtime Data\n" },
#endif
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Runtime Data" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentLayout_MetaData[] = {
		{ "Category", "Dungeon|Runtime" },
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnedDungeonActors_MetaData[] = {
		{ "Category", "Dungeon|Runtime" },
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FloorInstancedMesh_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Instanced Mesh Components for Performance\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Instanced Mesh Components for Performance" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WallInstancedMesh_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CeilingInstancedMesh_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DungeonVisualizer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CellSize;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WallHeight;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_HallwayWidth;
	static void NewProp_bAutoGenerateOnBeginPlay_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoGenerateOnBeginPlay;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentFloor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_StandardRoomMeshes;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TreasureRoomMeshes;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ShopRoomMeshes;
	static const UECodeGen_Private::FStructPropertyParams NewProp_BossRoomMeshes;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HallwayFloorMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HallwayWallMesh;
	static const UECodeGen_Private::FClassPropertyParams NewProp_DoorActorClass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_ChestActorClass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_EnemySpawnerClass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_InteractableClass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_EnemyClasses_ValueProp;
	static const UECodeGen_Private::FStrPropertyParams NewProp_EnemyClasses_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_EnemyClasses;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ADASystem;
	static const UECodeGen_Private::FStructPropertyParams NewProp_VisualizedRooms_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_VisualizedRooms;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CurrentLayout;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpawnedDungeonActors_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_SpawnedDungeonActors;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FloorInstancedMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WallInstancedMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CeilingInstancedMesh;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ADungeonVisualizer_ApplyLighting, "ApplyLighting" }, // 3774925289
		{ &Z_Construct_UFunction_ADungeonVisualizer_ClearDungeon, "ClearDungeon" }, // 2070201691
		{ &Z_Construct_UFunction_ADungeonVisualizer_CreateHallwayPath, "CreateHallwayPath" }, // 2055306638
		{ &Z_Construct_UFunction_ADungeonVisualizer_GenerateAndVisualizeDungeon, "GenerateAndVisualizeDungeon" }, // 3152475245
		{ &Z_Construct_UFunction_ADungeonVisualizer_GetRoomVisualData, "GetRoomVisualData" }, // 2072705174
		{ &Z_Construct_UFunction_ADungeonVisualizer_GetStartRoomPosition, "GetStartRoomPosition" }, // 2146309652
		{ &Z_Construct_UFunction_ADungeonVisualizer_GridToWorldPosition, "GridToWorldPosition" }, // 3388806092
		{ &Z_Construct_UFunction_ADungeonVisualizer_OnDoorSpawned, "OnDoorSpawned" }, // 1044066962
		{ &Z_Construct_UFunction_ADungeonVisualizer_OnEnemySpawned, "OnEnemySpawned" }, // 3505090813
		{ &Z_Construct_UFunction_ADungeonVisualizer_OnLootSpawned, "OnLootSpawned" }, // 4069033319
		{ &Z_Construct_UFunction_ADungeonVisualizer_OnPlayerSpawned, "OnPlayerSpawned" }, // 372145438
		{ &Z_Construct_UFunction_ADungeonVisualizer_OnRoomSpawned, "OnRoomSpawned" }, // 3057081904
		{ &Z_Construct_UFunction_ADungeonVisualizer_SetRoomTheme, "SetRoomTheme" }, // 4282964135
		{ &Z_Construct_UFunction_ADungeonVisualizer_SpawnDoor, "SpawnDoor" }, // 1096063293
		{ &Z_Construct_UFunction_ADungeonVisualizer_SpawnEnemiesInRoom, "SpawnEnemiesInRoom" }, // 1506123137
		{ &Z_Construct_UFunction_ADungeonVisualizer_SpawnLootInRoom, "SpawnLootInRoom" }, // 4113897296
		{ &Z_Construct_UFunction_ADungeonVisualizer_SpawnPlayerAtStart, "SpawnPlayerAtStart" }, // 703170664
		{ &Z_Construct_UFunction_ADungeonVisualizer_SpawnRoom, "SpawnRoom" }, // 3078387467
		{ &Z_Construct_UFunction_ADungeonVisualizer_SpawnRoomMeshes, "SpawnRoomMeshes" }, // 4164767222
		{ &Z_Construct_UFunction_ADungeonVisualizer_VisualizeDungeonLayout, "VisualizeDungeonLayout" }, // 4110668091
		{ &Z_Construct_UFunction_ADungeonVisualizer_WorldToGridPosition, "WorldToGridPosition" }, // 2093479669
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADungeonVisualizer>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_CellSize = { "CellSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADungeonVisualizer, CellSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CellSize_MetaData), NewProp_CellSize_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_WallHeight = { "WallHeight", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADungeonVisualizer, WallHeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WallHeight_MetaData), NewProp_WallHeight_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_HallwayWidth = { "HallwayWidth", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADungeonVisualizer, HallwayWidth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HallwayWidth_MetaData), NewProp_HallwayWidth_MetaData) };
void Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_bAutoGenerateOnBeginPlay_SetBit(void* Obj)
{
	((ADungeonVisualizer*)Obj)->bAutoGenerateOnBeginPlay = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_bAutoGenerateOnBeginPlay = { "bAutoGenerateOnBeginPlay", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ADungeonVisualizer), &Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_bAutoGenerateOnBeginPlay_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutoGenerateOnBeginPlay_MetaData), NewProp_bAutoGenerateOnBeginPlay_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_CurrentFloor = { "CurrentFloor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADungeonVisualizer, CurrentFloor), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentFloor_MetaData), NewProp_CurrentFloor_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_StandardRoomMeshes = { "StandardRoomMeshes", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADungeonVisualizer, StandardRoomMeshes), Z_Construct_UScriptStruct_FRoomMeshSet, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StandardRoomMeshes_MetaData), NewProp_StandardRoomMeshes_MetaData) }; // 1686522190
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_TreasureRoomMeshes = { "TreasureRoomMeshes", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADungeonVisualizer, TreasureRoomMeshes), Z_Construct_UScriptStruct_FRoomMeshSet, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TreasureRoomMeshes_MetaData), NewProp_TreasureRoomMeshes_MetaData) }; // 1686522190
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_ShopRoomMeshes = { "ShopRoomMeshes", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADungeonVisualizer, ShopRoomMeshes), Z_Construct_UScriptStruct_FRoomMeshSet, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShopRoomMeshes_MetaData), NewProp_ShopRoomMeshes_MetaData) }; // 1686522190
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_BossRoomMeshes = { "BossRoomMeshes", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADungeonVisualizer, BossRoomMeshes), Z_Construct_UScriptStruct_FRoomMeshSet, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BossRoomMeshes_MetaData), NewProp_BossRoomMeshes_MetaData) }; // 1686522190
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_HallwayFloorMesh = { "HallwayFloorMesh", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADungeonVisualizer, HallwayFloorMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HallwayFloorMesh_MetaData), NewProp_HallwayFloorMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_HallwayWallMesh = { "HallwayWallMesh", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADungeonVisualizer, HallwayWallMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HallwayWallMesh_MetaData), NewProp_HallwayWallMesh_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_DoorActorClass = { "DoorActorClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADungeonVisualizer, DoorActorClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DoorActorClass_MetaData), NewProp_DoorActorClass_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_ChestActorClass = { "ChestActorClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADungeonVisualizer, ChestActorClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChestActorClass_MetaData), NewProp_ChestActorClass_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_EnemySpawnerClass = { "EnemySpawnerClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADungeonVisualizer, EnemySpawnerClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EnemySpawnerClass_MetaData), NewProp_EnemySpawnerClass_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_InteractableClass = { "InteractableClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADungeonVisualizer, InteractableClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractableClass_MetaData), NewProp_InteractableClass_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_EnemyClasses_ValueProp = { "EnemyClasses", nullptr, (EPropertyFlags)0x0004000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_UClass, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_EnemyClasses_Key_KeyProp = { "EnemyClasses_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_EnemyClasses = { "EnemyClasses", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADungeonVisualizer, EnemyClasses), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EnemyClasses_MetaData), NewProp_EnemyClasses_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_ADASystem = { "ADASystem", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADungeonVisualizer, ADASystem), Z_Construct_UClass_AADASystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ADASystem_MetaData), NewProp_ADASystem_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_VisualizedRooms_Inner = { "VisualizedRooms", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FRoomVisualData, METADATA_PARAMS(0, nullptr) }; // 601754977
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_VisualizedRooms = { "VisualizedRooms", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADungeonVisualizer, VisualizedRooms), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VisualizedRooms_MetaData), NewProp_VisualizedRooms_MetaData) }; // 601754977
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_CurrentLayout = { "CurrentLayout", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADungeonVisualizer, CurrentLayout), Z_Construct_UScriptStruct_FDungeonLayout, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentLayout_MetaData), NewProp_CurrentLayout_MetaData) }; // 3903890264
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_SpawnedDungeonActors_Inner = { "SpawnedDungeonActors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_SpawnedDungeonActors = { "SpawnedDungeonActors", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADungeonVisualizer, SpawnedDungeonActors), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnedDungeonActors_MetaData), NewProp_SpawnedDungeonActors_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_FloorInstancedMesh = { "FloorInstancedMesh", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADungeonVisualizer, FloorInstancedMesh), Z_Construct_UClass_UInstancedStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FloorInstancedMesh_MetaData), NewProp_FloorInstancedMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_WallInstancedMesh = { "WallInstancedMesh", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADungeonVisualizer, WallInstancedMesh), Z_Construct_UClass_UInstancedStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WallInstancedMesh_MetaData), NewProp_WallInstancedMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_CeilingInstancedMesh = { "CeilingInstancedMesh", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADungeonVisualizer, CeilingInstancedMesh), Z_Construct_UClass_UInstancedStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CeilingInstancedMesh_MetaData), NewProp_CeilingInstancedMesh_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ADungeonVisualizer_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_CellSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_WallHeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_HallwayWidth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_bAutoGenerateOnBeginPlay,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_CurrentFloor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_StandardRoomMeshes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_TreasureRoomMeshes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_ShopRoomMeshes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_BossRoomMeshes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_HallwayFloorMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_HallwayWallMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_DoorActorClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_ChestActorClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_EnemySpawnerClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_InteractableClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_EnemyClasses_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_EnemyClasses_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_EnemyClasses,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_ADASystem,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_VisualizedRooms_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_VisualizedRooms,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_CurrentLayout,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_SpawnedDungeonActors_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_SpawnedDungeonActors,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_FloorInstancedMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_WallInstancedMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADungeonVisualizer_Statics::NewProp_CeilingInstancedMesh,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ADungeonVisualizer_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ADungeonVisualizer_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_EternalDescent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ADungeonVisualizer_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ADungeonVisualizer_Statics::ClassParams = {
	&ADungeonVisualizer::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ADungeonVisualizer_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ADungeonVisualizer_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ADungeonVisualizer_Statics::Class_MetaDataParams), Z_Construct_UClass_ADungeonVisualizer_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ADungeonVisualizer()
{
	if (!Z_Registration_Info_UClass_ADungeonVisualizer.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADungeonVisualizer.OuterSingleton, Z_Construct_UClass_ADungeonVisualizer_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ADungeonVisualizer.OuterSingleton;
}
template<> ETERNALDESCENT_API UClass* StaticClass<ADungeonVisualizer>()
{
	return ADungeonVisualizer::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ADungeonVisualizer);
ADungeonVisualizer::~ADungeonVisualizer() {}
// End Class ADungeonVisualizer

// Begin Registration
struct Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_DungeonVisualizer_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FRoomMeshSet::StaticStruct, Z_Construct_UScriptStruct_FRoomMeshSet_Statics::NewStructOps, TEXT("RoomMeshSet"), &Z_Registration_Info_UScriptStruct_RoomMeshSet, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FRoomMeshSet), 1686522190U) },
		{ FRoomVisualData::StaticStruct, Z_Construct_UScriptStruct_FRoomVisualData_Statics::NewStructOps, TEXT("RoomVisualData"), &Z_Registration_Info_UScriptStruct_RoomVisualData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FRoomVisualData), 601754977U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ADungeonVisualizer, ADungeonVisualizer::StaticClass, TEXT("ADungeonVisualizer"), &Z_Registration_Info_UClass_ADungeonVisualizer, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADungeonVisualizer), 2784128444U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_DungeonVisualizer_h_4095331785(TEXT("/Script/EternalDescent"),
	Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_DungeonVisualizer_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_DungeonVisualizer_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_DungeonVisualizer_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_DungeonVisualizer_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
