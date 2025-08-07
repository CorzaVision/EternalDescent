// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EternalDescent/Public/CubeDungeonTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCubeDungeonTypes() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntVector();
ETERNALDESCENT_API UEnum* Z_Construct_UEnum_EternalDescent_ECubeType();
ETERNALDESCENT_API UEnum* Z_Construct_UEnum_EternalDescent_EDungeonCubeFace();
ETERNALDESCENT_API UEnum* Z_Construct_UEnum_EternalDescent_EPlaneType();
ETERNALDESCENT_API UEnum* Z_Construct_UEnum_EternalDescent_ERoomType();
ETERNALDESCENT_API UScriptStruct* Z_Construct_UScriptStruct_FCubeDungeonLayout();
ETERNALDESCENT_API UScriptStruct* Z_Construct_UScriptStruct_FCubePlane();
ETERNALDESCENT_API UScriptStruct* Z_Construct_UScriptStruct_FCubeRoom();
ETERNALDESCENT_API UScriptStruct* Z_Construct_UScriptStruct_FDungeonCube();
UPackage* Z_Construct_UPackage__Script_EternalDescent();
// End Cross Module References

// Begin Enum EPlaneType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPlaneType;
static UEnum* EPlaneType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EPlaneType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EPlaneType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_EternalDescent_EPlaneType, (UObject*)Z_Construct_UPackage__Script_EternalDescent(), TEXT("EPlaneType"));
	}
	return Z_Registration_Info_UEnum_EPlaneType.OuterSingleton;
}
template<> ETERNALDESCENT_API UEnum* StaticEnum<EPlaneType>()
{
	return EPlaneType_StaticEnum();
}
struct Z_Construct_UEnum_EternalDescent_EPlaneType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Each face of a cube can be a plane type\n" },
#endif
		{ "Destructible.DisplayName", "Destructible" },
		{ "Destructible.Name", "EPlaneType::Destructible" },
		{ "Door.DisplayName", "Door" },
		{ "Door.Name", "EPlaneType::Door" },
		{ "ModuleRelativePath", "Public/CubeDungeonTypes.h" },
		{ "Open.DisplayName", "Open Space" },
		{ "Open.Name", "EPlaneType::Open" },
		{ "Solid.DisplayName", "Solid Wall" },
		{ "Solid.Name", "EPlaneType::Solid" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Each face of a cube can be a plane type" },
#endif
		{ "Transparent.DisplayName", "Transparent" },
		{ "Transparent.Name", "EPlaneType::Transparent" },
		{ "Window.DisplayName", "Window" },
		{ "Window.Name", "EPlaneType::Window" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EPlaneType::Solid", (int64)EPlaneType::Solid },
		{ "EPlaneType::Open", (int64)EPlaneType::Open },
		{ "EPlaneType::Door", (int64)EPlaneType::Door },
		{ "EPlaneType::Window", (int64)EPlaneType::Window },
		{ "EPlaneType::Transparent", (int64)EPlaneType::Transparent },
		{ "EPlaneType::Destructible", (int64)EPlaneType::Destructible },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_EternalDescent_EPlaneType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_EternalDescent,
	nullptr,
	"EPlaneType",
	"EPlaneType",
	Z_Construct_UEnum_EternalDescent_EPlaneType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_EternalDescent_EPlaneType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_EternalDescent_EPlaneType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_EternalDescent_EPlaneType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_EternalDescent_EPlaneType()
{
	if (!Z_Registration_Info_UEnum_EPlaneType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPlaneType.InnerSingleton, Z_Construct_UEnum_EternalDescent_EPlaneType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EPlaneType.InnerSingleton;
}
// End Enum EPlaneType

// Begin Enum ECubeType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ECubeType;
static UEnum* ECubeType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ECubeType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ECubeType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_EternalDescent_ECubeType, (UObject*)Z_Construct_UPackage__Script_EternalDescent(), TEXT("ECubeType"));
	}
	return Z_Registration_Info_UEnum_ECubeType.OuterSingleton;
}
template<> ETERNALDESCENT_API UEnum* StaticEnum<ECubeType>()
{
	return ECubeType_StaticEnum();
}
struct Z_Construct_UEnum_EternalDescent_ECubeType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Ceiling.DisplayName", "Ceiling" },
		{ "Ceiling.Name", "ECubeType::Ceiling" },
		{ "Empty.DisplayName", "Empty Space" },
		{ "Empty.Name", "ECubeType::Empty" },
		{ "Floor.DisplayName", "Floor" },
		{ "Floor.Name", "ECubeType::Floor" },
		{ "ModuleRelativePath", "Public/CubeDungeonTypes.h" },
		{ "Pillar.DisplayName", "Pillar" },
		{ "Pillar.Name", "ECubeType::Pillar" },
		{ "Solid.DisplayName", "Solid Block" },
		{ "Solid.Name", "ECubeType::Solid" },
		{ "Special.DisplayName", "Special" },
		{ "Special.Name", "ECubeType::Special" },
		{ "Stairs.DisplayName", "Stairs" },
		{ "Stairs.Name", "ECubeType::Stairs" },
		{ "Wall.DisplayName", "Wall" },
		{ "Wall.Name", "ECubeType::Wall" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ECubeType::Empty", (int64)ECubeType::Empty },
		{ "ECubeType::Solid", (int64)ECubeType::Solid },
		{ "ECubeType::Floor", (int64)ECubeType::Floor },
		{ "ECubeType::Wall", (int64)ECubeType::Wall },
		{ "ECubeType::Ceiling", (int64)ECubeType::Ceiling },
		{ "ECubeType::Pillar", (int64)ECubeType::Pillar },
		{ "ECubeType::Stairs", (int64)ECubeType::Stairs },
		{ "ECubeType::Special", (int64)ECubeType::Special },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_EternalDescent_ECubeType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_EternalDescent,
	nullptr,
	"ECubeType",
	"ECubeType",
	Z_Construct_UEnum_EternalDescent_ECubeType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_EternalDescent_ECubeType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_EternalDescent_ECubeType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_EternalDescent_ECubeType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_EternalDescent_ECubeType()
{
	if (!Z_Registration_Info_UEnum_ECubeType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ECubeType.InnerSingleton, Z_Construct_UEnum_EternalDescent_ECubeType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ECubeType.InnerSingleton;
}
// End Enum ECubeType

// Begin Enum EDungeonCubeFace
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EDungeonCubeFace;
static UEnum* EDungeonCubeFace_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EDungeonCubeFace.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EDungeonCubeFace.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_EternalDescent_EDungeonCubeFace, (UObject*)Z_Construct_UPackage__Script_EternalDescent(), TEXT("EDungeonCubeFace"));
	}
	return Z_Registration_Info_UEnum_EDungeonCubeFace.OuterSingleton;
}
template<> ETERNALDESCENT_API UEnum* StaticEnum<EDungeonCubeFace>()
{
	return EDungeonCubeFace_StaticEnum();
}
struct Z_Construct_UEnum_EternalDescent_EDungeonCubeFace_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Bottom.DisplayName", "Bottom -Z" },
		{ "Bottom.Name", "EDungeonCubeFace::Bottom" },
		{ "East.DisplayName", "East +X" },
		{ "East.Name", "EDungeonCubeFace::East" },
		{ "ModuleRelativePath", "Public/CubeDungeonTypes.h" },
		{ "North.DisplayName", "North +Y" },
		{ "North.Name", "EDungeonCubeFace::North" },
		{ "South.DisplayName", "South -Y" },
		{ "South.Name", "EDungeonCubeFace::South" },
		{ "Top.DisplayName", "Top +Z" },
		{ "Top.Name", "EDungeonCubeFace::Top" },
		{ "West.DisplayName", "West -X" },
		{ "West.Name", "EDungeonCubeFace::West" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EDungeonCubeFace::Top", (int64)EDungeonCubeFace::Top },
		{ "EDungeonCubeFace::Bottom", (int64)EDungeonCubeFace::Bottom },
		{ "EDungeonCubeFace::North", (int64)EDungeonCubeFace::North },
		{ "EDungeonCubeFace::South", (int64)EDungeonCubeFace::South },
		{ "EDungeonCubeFace::East", (int64)EDungeonCubeFace::East },
		{ "EDungeonCubeFace::West", (int64)EDungeonCubeFace::West },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_EternalDescent_EDungeonCubeFace_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_EternalDescent,
	nullptr,
	"EDungeonCubeFace",
	"EDungeonCubeFace",
	Z_Construct_UEnum_EternalDescent_EDungeonCubeFace_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_EternalDescent_EDungeonCubeFace_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_EternalDescent_EDungeonCubeFace_Statics::Enum_MetaDataParams), Z_Construct_UEnum_EternalDescent_EDungeonCubeFace_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_EternalDescent_EDungeonCubeFace()
{
	if (!Z_Registration_Info_UEnum_EDungeonCubeFace.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EDungeonCubeFace.InnerSingleton, Z_Construct_UEnum_EternalDescent_EDungeonCubeFace_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EDungeonCubeFace.InnerSingleton;
}
// End Enum EDungeonCubeFace

// Begin ScriptStruct FCubePlane
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_CubePlane;
class UScriptStruct* FCubePlane::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_CubePlane.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_CubePlane.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FCubePlane, (UObject*)Z_Construct_UPackage__Script_EternalDescent(), TEXT("CubePlane"));
	}
	return Z_Registration_Info_UScriptStruct_CubePlane.OuterSingleton;
}
template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<FCubePlane>()
{
	return FCubePlane::StaticStruct();
}
struct Z_Construct_UScriptStruct_FCubePlane_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Single plane definition on a cube face\n" },
#endif
		{ "ModuleRelativePath", "Public/CubeDungeonTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Single plane definition on a cube face" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Type_MetaData[] = {
		{ "Category", "CubePlane" },
		{ "ModuleRelativePath", "Public/CubeDungeonTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Face_MetaData[] = {
		{ "Category", "CubePlane" },
		{ "ModuleRelativePath", "Public/CubeDungeonTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaterialIndex_MetaData[] = {
		{ "Category", "CubePlane" },
		{ "ModuleRelativePath", "Public/CubeDungeonTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsRoomBoundary_MetaData[] = {
		{ "Category", "CubePlane" },
		{ "ModuleRelativePath", "Public/CubeDungeonTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoomID_MetaData[] = {
		{ "Category", "CubePlane" },
		{ "ModuleRelativePath", "Public/CubeDungeonTypes.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_Type_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Type;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Face_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Face;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaterialIndex;
	static void NewProp_bIsRoomBoundary_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsRoomBoundary;
	static const UECodeGen_Private::FIntPropertyParams NewProp_RoomID;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCubePlane>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FCubePlane_Statics::NewProp_Type_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FCubePlane_Statics::NewProp_Type = { "Type", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCubePlane, Type), Z_Construct_UEnum_EternalDescent_EPlaneType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Type_MetaData), NewProp_Type_MetaData) }; // 1784448784
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FCubePlane_Statics::NewProp_Face_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FCubePlane_Statics::NewProp_Face = { "Face", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCubePlane, Face), Z_Construct_UEnum_EternalDescent_EDungeonCubeFace, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Face_MetaData), NewProp_Face_MetaData) }; // 3069507833
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FCubePlane_Statics::NewProp_MaterialIndex = { "MaterialIndex", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCubePlane, MaterialIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaterialIndex_MetaData), NewProp_MaterialIndex_MetaData) };
void Z_Construct_UScriptStruct_FCubePlane_Statics::NewProp_bIsRoomBoundary_SetBit(void* Obj)
{
	((FCubePlane*)Obj)->bIsRoomBoundary = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FCubePlane_Statics::NewProp_bIsRoomBoundary = { "bIsRoomBoundary", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FCubePlane), &Z_Construct_UScriptStruct_FCubePlane_Statics::NewProp_bIsRoomBoundary_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsRoomBoundary_MetaData), NewProp_bIsRoomBoundary_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FCubePlane_Statics::NewProp_RoomID = { "RoomID", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCubePlane, RoomID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoomID_MetaData), NewProp_RoomID_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCubePlane_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCubePlane_Statics::NewProp_Type_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCubePlane_Statics::NewProp_Type,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCubePlane_Statics::NewProp_Face_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCubePlane_Statics::NewProp_Face,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCubePlane_Statics::NewProp_MaterialIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCubePlane_Statics::NewProp_bIsRoomBoundary,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCubePlane_Statics::NewProp_RoomID,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCubePlane_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCubePlane_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_EternalDescent,
	nullptr,
	&NewStructOps,
	"CubePlane",
	Z_Construct_UScriptStruct_FCubePlane_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCubePlane_Statics::PropPointers),
	sizeof(FCubePlane),
	alignof(FCubePlane),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCubePlane_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FCubePlane_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FCubePlane()
{
	if (!Z_Registration_Info_UScriptStruct_CubePlane.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_CubePlane.InnerSingleton, Z_Construct_UScriptStruct_FCubePlane_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_CubePlane.InnerSingleton;
}
// End ScriptStruct FCubePlane

// Begin ScriptStruct FDungeonCube
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_DungeonCube;
class UScriptStruct* FDungeonCube::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_DungeonCube.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_DungeonCube.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDungeonCube, (UObject*)Z_Construct_UPackage__Script_EternalDescent(), TEXT("DungeonCube"));
	}
	return Z_Registration_Info_UScriptStruct_DungeonCube.OuterSingleton;
}
template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<FDungeonCube>()
{
	return FDungeonCube::StaticStruct();
}
struct Z_Construct_UScriptStruct_FDungeonCube_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Single cube in the dungeon grid\n" },
#endif
		{ "ModuleRelativePath", "Public/CubeDungeonTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Single cube in the dungeon grid" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GridPosition_MetaData[] = {
		{ "Category", "DungeonCube" },
		{ "ModuleRelativePath", "Public/CubeDungeonTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Type_MetaData[] = {
		{ "Category", "DungeonCube" },
		{ "ModuleRelativePath", "Public/CubeDungeonTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Planes_MetaData[] = {
		{ "Category", "DungeonCube" },
		{ "ModuleRelativePath", "Public/CubeDungeonTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoomID_MetaData[] = {
		{ "Category", "DungeonCube" },
		{ "ModuleRelativePath", "Public/CubeDungeonTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsOccupied_MetaData[] = {
		{ "Category", "DungeonCube" },
		{ "ModuleRelativePath", "Public/CubeDungeonTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EntityInfluence_MetaData[] = {
		{ "Category", "DungeonCube" },
		{ "ModuleRelativePath", "Public/CubeDungeonTypes.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_GridPosition;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Type_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Type;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Planes_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Planes;
	static const UECodeGen_Private::FIntPropertyParams NewProp_RoomID;
	static void NewProp_bIsOccupied_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsOccupied;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_EntityInfluence;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDungeonCube>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FDungeonCube_Statics::NewProp_GridPosition = { "GridPosition", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDungeonCube, GridPosition), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GridPosition_MetaData), NewProp_GridPosition_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FDungeonCube_Statics::NewProp_Type_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FDungeonCube_Statics::NewProp_Type = { "Type", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDungeonCube, Type), Z_Construct_UEnum_EternalDescent_ECubeType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Type_MetaData), NewProp_Type_MetaData) }; // 3568086752
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FDungeonCube_Statics::NewProp_Planes_Inner = { "Planes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FCubePlane, METADATA_PARAMS(0, nullptr) }; // 2075123764
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FDungeonCube_Statics::NewProp_Planes = { "Planes", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDungeonCube, Planes), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Planes_MetaData), NewProp_Planes_MetaData) }; // 2075123764
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDungeonCube_Statics::NewProp_RoomID = { "RoomID", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDungeonCube, RoomID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoomID_MetaData), NewProp_RoomID_MetaData) };
void Z_Construct_UScriptStruct_FDungeonCube_Statics::NewProp_bIsOccupied_SetBit(void* Obj)
{
	((FDungeonCube*)Obj)->bIsOccupied = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FDungeonCube_Statics::NewProp_bIsOccupied = { "bIsOccupied", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FDungeonCube), &Z_Construct_UScriptStruct_FDungeonCube_Statics::NewProp_bIsOccupied_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsOccupied_MetaData), NewProp_bIsOccupied_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FDungeonCube_Statics::NewProp_EntityInfluence = { "EntityInfluence", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDungeonCube, EntityInfluence), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EntityInfluence_MetaData), NewProp_EntityInfluence_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDungeonCube_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDungeonCube_Statics::NewProp_GridPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDungeonCube_Statics::NewProp_Type_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDungeonCube_Statics::NewProp_Type,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDungeonCube_Statics::NewProp_Planes_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDungeonCube_Statics::NewProp_Planes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDungeonCube_Statics::NewProp_RoomID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDungeonCube_Statics::NewProp_bIsOccupied,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDungeonCube_Statics::NewProp_EntityInfluence,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDungeonCube_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDungeonCube_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_EternalDescent,
	nullptr,
	&NewStructOps,
	"DungeonCube",
	Z_Construct_UScriptStruct_FDungeonCube_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDungeonCube_Statics::PropPointers),
	sizeof(FDungeonCube),
	alignof(FDungeonCube),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDungeonCube_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDungeonCube_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FDungeonCube()
{
	if (!Z_Registration_Info_UScriptStruct_DungeonCube.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_DungeonCube.InnerSingleton, Z_Construct_UScriptStruct_FDungeonCube_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_DungeonCube.InnerSingleton;
}
// End ScriptStruct FDungeonCube

// Begin ScriptStruct FCubeRoom
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_CubeRoom;
class UScriptStruct* FCubeRoom::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_CubeRoom.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_CubeRoom.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FCubeRoom, (UObject*)Z_Construct_UPackage__Script_EternalDescent(), TEXT("CubeRoom"));
	}
	return Z_Registration_Info_UScriptStruct_CubeRoom.OuterSingleton;
}
template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<FCubeRoom>()
{
	return FCubeRoom::StaticStruct();
}
struct Z_Construct_UScriptStruct_FCubeRoom_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Collection of cubes forming a room\n" },
#endif
		{ "ModuleRelativePath", "Public/CubeDungeonTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Collection of cubes forming a room" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoomID_MetaData[] = {
		{ "Category", "CubeRoom" },
		{ "ModuleRelativePath", "Public/CubeDungeonTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CubePositions_MetaData[] = {
		{ "Category", "CubeRoom" },
		{ "ModuleRelativePath", "Public/CubeDungeonTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinBounds_MetaData[] = {
		{ "Category", "CubeRoom" },
		{ "ModuleRelativePath", "Public/CubeDungeonTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxBounds_MetaData[] = {
		{ "Category", "CubeRoom" },
		{ "ModuleRelativePath", "Public/CubeDungeonTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoomType_MetaData[] = {
		{ "Category", "CubeRoom" },
		{ "ModuleRelativePath", "Public/CubeDungeonTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ConnectedRoomIDs_MetaData[] = {
		{ "Category", "CubeRoom" },
		{ "ModuleRelativePath", "Public/CubeDungeonTypes.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_RoomID;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CubePositions_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_CubePositions;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MinBounds;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MaxBounds;
	static const UECodeGen_Private::FBytePropertyParams NewProp_RoomType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_RoomType;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ConnectedRoomIDs_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ConnectedRoomIDs;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCubeRoom>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FCubeRoom_Statics::NewProp_RoomID = { "RoomID", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCubeRoom, RoomID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoomID_MetaData), NewProp_RoomID_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCubeRoom_Statics::NewProp_CubePositions_Inner = { "CubePositions", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FCubeRoom_Statics::NewProp_CubePositions = { "CubePositions", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCubeRoom, CubePositions), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CubePositions_MetaData), NewProp_CubePositions_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCubeRoom_Statics::NewProp_MinBounds = { "MinBounds", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCubeRoom, MinBounds), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinBounds_MetaData), NewProp_MinBounds_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCubeRoom_Statics::NewProp_MaxBounds = { "MaxBounds", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCubeRoom, MaxBounds), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxBounds_MetaData), NewProp_MaxBounds_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FCubeRoom_Statics::NewProp_RoomType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FCubeRoom_Statics::NewProp_RoomType = { "RoomType", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCubeRoom, RoomType), Z_Construct_UEnum_EternalDescent_ERoomType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoomType_MetaData), NewProp_RoomType_MetaData) }; // 1291513837
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FCubeRoom_Statics::NewProp_ConnectedRoomIDs_Inner = { "ConnectedRoomIDs", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FCubeRoom_Statics::NewProp_ConnectedRoomIDs = { "ConnectedRoomIDs", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCubeRoom, ConnectedRoomIDs), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ConnectedRoomIDs_MetaData), NewProp_ConnectedRoomIDs_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCubeRoom_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCubeRoom_Statics::NewProp_RoomID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCubeRoom_Statics::NewProp_CubePositions_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCubeRoom_Statics::NewProp_CubePositions,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCubeRoom_Statics::NewProp_MinBounds,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCubeRoom_Statics::NewProp_MaxBounds,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCubeRoom_Statics::NewProp_RoomType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCubeRoom_Statics::NewProp_RoomType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCubeRoom_Statics::NewProp_ConnectedRoomIDs_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCubeRoom_Statics::NewProp_ConnectedRoomIDs,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCubeRoom_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCubeRoom_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_EternalDescent,
	nullptr,
	&NewStructOps,
	"CubeRoom",
	Z_Construct_UScriptStruct_FCubeRoom_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCubeRoom_Statics::PropPointers),
	sizeof(FCubeRoom),
	alignof(FCubeRoom),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCubeRoom_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FCubeRoom_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FCubeRoom()
{
	if (!Z_Registration_Info_UScriptStruct_CubeRoom.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_CubeRoom.InnerSingleton, Z_Construct_UScriptStruct_FCubeRoom_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_CubeRoom.InnerSingleton;
}
// End ScriptStruct FCubeRoom

// Begin ScriptStruct FCubeDungeonLayout
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_CubeDungeonLayout;
class UScriptStruct* FCubeDungeonLayout::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_CubeDungeonLayout.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_CubeDungeonLayout.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FCubeDungeonLayout, (UObject*)Z_Construct_UPackage__Script_EternalDescent(), TEXT("CubeDungeonLayout"));
	}
	return Z_Registration_Info_UScriptStruct_CubeDungeonLayout.OuterSingleton;
}
template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<FCubeDungeonLayout>()
{
	return FCubeDungeonLayout::StaticStruct();
}
struct Z_Construct_UScriptStruct_FCubeDungeonLayout_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Cube-based dungeon layout\n" },
#endif
		{ "ModuleRelativePath", "Public/CubeDungeonTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cube-based dungeon layout" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FloorNumber_MetaData[] = {
		{ "Category", "CubeDungeonLayout" },
		{ "ModuleRelativePath", "Public/CubeDungeonTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CubeGrid_MetaData[] = {
		{ "Category", "CubeDungeonLayout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// 3D grid of cubes\n" },
#endif
		{ "ModuleRelativePath", "Public/CubeDungeonTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "3D grid of cubes" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rooms_MetaData[] = {
		{ "Category", "CubeDungeonLayout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Rooms formed by adjacent cubes\n" },
#endif
		{ "ModuleRelativePath", "Public/CubeDungeonTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Rooms formed by adjacent cubes" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GridDimensions_MetaData[] = {
		{ "Category", "CubeDungeonLayout" },
		{ "ModuleRelativePath", "Public/CubeDungeonTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalCubes_MetaData[] = {
		{ "Category", "CubeDungeonLayout" },
		{ "ModuleRelativePath", "Public/CubeDungeonTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OccupiedCubes_MetaData[] = {
		{ "Category", "CubeDungeonLayout" },
		{ "ModuleRelativePath", "Public/CubeDungeonTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GenerationTime_MetaData[] = {
		{ "Category", "CubeDungeonLayout" },
		{ "ModuleRelativePath", "Public/CubeDungeonTypes.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_FloorNumber;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CubeGrid_ValueProp;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CubeGrid_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_CubeGrid;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Rooms_ValueProp;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Rooms_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_Rooms;
	static const UECodeGen_Private::FStructPropertyParams NewProp_GridDimensions;
	static const UECodeGen_Private::FIntPropertyParams NewProp_TotalCubes;
	static const UECodeGen_Private::FIntPropertyParams NewProp_OccupiedCubes;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GenerationTime;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCubeDungeonLayout>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FCubeDungeonLayout_Statics::NewProp_FloorNumber = { "FloorNumber", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCubeDungeonLayout, FloorNumber), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FloorNumber_MetaData), NewProp_FloorNumber_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCubeDungeonLayout_Statics::NewProp_CubeGrid_ValueProp = { "CubeGrid", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FDungeonCube, METADATA_PARAMS(0, nullptr) }; // 2403584286
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCubeDungeonLayout_Statics::NewProp_CubeGrid_Key_KeyProp = { "CubeGrid_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UScriptStruct_FCubeDungeonLayout_Statics::NewProp_CubeGrid = { "CubeGrid", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCubeDungeonLayout, CubeGrid), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CubeGrid_MetaData), NewProp_CubeGrid_MetaData) }; // 2403584286
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCubeDungeonLayout_Statics::NewProp_Rooms_ValueProp = { "Rooms", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FCubeRoom, METADATA_PARAMS(0, nullptr) }; // 659766181
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FCubeDungeonLayout_Statics::NewProp_Rooms_Key_KeyProp = { "Rooms_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UScriptStruct_FCubeDungeonLayout_Statics::NewProp_Rooms = { "Rooms", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCubeDungeonLayout, Rooms), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rooms_MetaData), NewProp_Rooms_MetaData) }; // 659766181
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCubeDungeonLayout_Statics::NewProp_GridDimensions = { "GridDimensions", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCubeDungeonLayout, GridDimensions), Z_Construct_UScriptStruct_FIntVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GridDimensions_MetaData), NewProp_GridDimensions_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FCubeDungeonLayout_Statics::NewProp_TotalCubes = { "TotalCubes", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCubeDungeonLayout, TotalCubes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalCubes_MetaData), NewProp_TotalCubes_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FCubeDungeonLayout_Statics::NewProp_OccupiedCubes = { "OccupiedCubes", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCubeDungeonLayout, OccupiedCubes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OccupiedCubes_MetaData), NewProp_OccupiedCubes_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCubeDungeonLayout_Statics::NewProp_GenerationTime = { "GenerationTime", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCubeDungeonLayout, GenerationTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GenerationTime_MetaData), NewProp_GenerationTime_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCubeDungeonLayout_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCubeDungeonLayout_Statics::NewProp_FloorNumber,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCubeDungeonLayout_Statics::NewProp_CubeGrid_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCubeDungeonLayout_Statics::NewProp_CubeGrid_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCubeDungeonLayout_Statics::NewProp_CubeGrid,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCubeDungeonLayout_Statics::NewProp_Rooms_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCubeDungeonLayout_Statics::NewProp_Rooms_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCubeDungeonLayout_Statics::NewProp_Rooms,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCubeDungeonLayout_Statics::NewProp_GridDimensions,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCubeDungeonLayout_Statics::NewProp_TotalCubes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCubeDungeonLayout_Statics::NewProp_OccupiedCubes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCubeDungeonLayout_Statics::NewProp_GenerationTime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCubeDungeonLayout_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCubeDungeonLayout_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_EternalDescent,
	nullptr,
	&NewStructOps,
	"CubeDungeonLayout",
	Z_Construct_UScriptStruct_FCubeDungeonLayout_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCubeDungeonLayout_Statics::PropPointers),
	sizeof(FCubeDungeonLayout),
	alignof(FCubeDungeonLayout),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCubeDungeonLayout_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FCubeDungeonLayout_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FCubeDungeonLayout()
{
	if (!Z_Registration_Info_UScriptStruct_CubeDungeonLayout.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_CubeDungeonLayout.InnerSingleton, Z_Construct_UScriptStruct_FCubeDungeonLayout_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_CubeDungeonLayout.InnerSingleton;
}
// End ScriptStruct FCubeDungeonLayout

// Begin Registration
struct Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_CubeDungeonTypes_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EPlaneType_StaticEnum, TEXT("EPlaneType"), &Z_Registration_Info_UEnum_EPlaneType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1784448784U) },
		{ ECubeType_StaticEnum, TEXT("ECubeType"), &Z_Registration_Info_UEnum_ECubeType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3568086752U) },
		{ EDungeonCubeFace_StaticEnum, TEXT("EDungeonCubeFace"), &Z_Registration_Info_UEnum_EDungeonCubeFace, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3069507833U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FCubePlane::StaticStruct, Z_Construct_UScriptStruct_FCubePlane_Statics::NewStructOps, TEXT("CubePlane"), &Z_Registration_Info_UScriptStruct_CubePlane, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FCubePlane), 2075123764U) },
		{ FDungeonCube::StaticStruct, Z_Construct_UScriptStruct_FDungeonCube_Statics::NewStructOps, TEXT("DungeonCube"), &Z_Registration_Info_UScriptStruct_DungeonCube, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDungeonCube), 2403584286U) },
		{ FCubeRoom::StaticStruct, Z_Construct_UScriptStruct_FCubeRoom_Statics::NewStructOps, TEXT("CubeRoom"), &Z_Registration_Info_UScriptStruct_CubeRoom, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FCubeRoom), 659766181U) },
		{ FCubeDungeonLayout::StaticStruct, Z_Construct_UScriptStruct_FCubeDungeonLayout_Statics::NewStructOps, TEXT("CubeDungeonLayout"), &Z_Registration_Info_UScriptStruct_CubeDungeonLayout, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FCubeDungeonLayout), 894533013U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_CubeDungeonTypes_h_1782101151(TEXT("/Script/EternalDescent"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_CubeDungeonTypes_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_CubeDungeonTypes_h_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_CubeDungeonTypes_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_CubeDungeonTypes_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
