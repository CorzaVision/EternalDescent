// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "CubeDungeonTypes.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ETERNALDESCENT_CubeDungeonTypes_generated_h
#error "CubeDungeonTypes.generated.h already included, missing '#pragma once' in CubeDungeonTypes.h"
#endif
#define ETERNALDESCENT_CubeDungeonTypes_generated_h

#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_CubeDungeonTypes_h_50_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FCubePlane_Statics; \
	ETERNALDESCENT_API static class UScriptStruct* StaticStruct();


template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<struct FCubePlane>();

#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_CubeDungeonTypes_h_81_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FDungeonCube_Statics; \
	ETERNALDESCENT_API static class UScriptStruct* StaticStruct();


template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<struct FDungeonCube>();

#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_CubeDungeonTypes_h_137_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FCubeRoom_Statics; \
	ETERNALDESCENT_API static class UScriptStruct* StaticStruct();


template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<struct FCubeRoom>();

#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_CubeDungeonTypes_h_201_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FCubeDungeonLayout_Statics; \
	ETERNALDESCENT_API static class UScriptStruct* StaticStruct();


template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<struct FCubeDungeonLayout>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_CubeDungeonTypes_h


#define FOREACH_ENUM_EPLANETYPE(op) \
	op(EPlaneType::Solid) \
	op(EPlaneType::Open) \
	op(EPlaneType::Door) \
	op(EPlaneType::Window) \
	op(EPlaneType::Transparent) \
	op(EPlaneType::Destructible) 

enum class EPlaneType : uint8;
template<> struct TIsUEnumClass<EPlaneType> { enum { Value = true }; };
template<> ETERNALDESCENT_API UEnum* StaticEnum<EPlaneType>();

#define FOREACH_ENUM_ECUBETYPE(op) \
	op(ECubeType::Empty) \
	op(ECubeType::Solid) \
	op(ECubeType::Floor) \
	op(ECubeType::Wall) \
	op(ECubeType::Ceiling) \
	op(ECubeType::Pillar) \
	op(ECubeType::Stairs) \
	op(ECubeType::Special) 

enum class ECubeType : uint8;
template<> struct TIsUEnumClass<ECubeType> { enum { Value = true }; };
template<> ETERNALDESCENT_API UEnum* StaticEnum<ECubeType>();

#define FOREACH_ENUM_EDUNGEONCUBEFACE(op) \
	op(EDungeonCubeFace::Top) \
	op(EDungeonCubeFace::Bottom) \
	op(EDungeonCubeFace::North) \
	op(EDungeonCubeFace::South) \
	op(EDungeonCubeFace::East) \
	op(EDungeonCubeFace::West) 

enum class EDungeonCubeFace : uint8;
template<> struct TIsUEnumClass<EDungeonCubeFace> { enum { Value = true }; };
template<> ETERNALDESCENT_API UEnum* StaticEnum<EDungeonCubeFace>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
