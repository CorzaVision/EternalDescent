// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Tests/DungeonTestTypes.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ETERNALDESCENT_DungeonTestTypes_generated_h
#error "DungeonTestTypes.generated.h already included, missing '#pragma once' in DungeonTestTypes.h"
#endif
#define ETERNALDESCENT_DungeonTestTypes_generated_h

#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_Tests_DungeonTestTypes_h_51_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FRoomData_Statics; \
	ETERNALDESCENT_API static class UScriptStruct* StaticStruct();


template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<struct FRoomData>();

#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_Tests_DungeonTestTypes_h_84_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FDungeonLayout_Statics; \
	ETERNALDESCENT_API static class UScriptStruct* StaticStruct();


template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<struct FDungeonLayout>();

#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_Tests_DungeonTestTypes_h_126_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FEntityProfile_Statics; \
	ETERNALDESCENT_API static class UScriptStruct* StaticStruct();


template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<struct FEntityProfile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_Tests_DungeonTestTypes_h


#define FOREACH_ENUM_EDUNGEONZONE(op) \
	op(EDungeonZone::None) \
	op(EDungeonZone::SunkenCrypt) \
	op(EDungeonZone::BlightedForest) \
	op(EDungeonZone::FrozenFortress) 

enum class EDungeonZone : uint8;
template<> struct TIsUEnumClass<EDungeonZone> { enum { Value = true }; };
template<> ETERNALDESCENT_API UEnum* StaticEnum<EDungeonZone>();

#define FOREACH_ENUM_EROOMTYPE(op) \
	op(ERoomType::Empty) \
	op(ERoomType::Standard) \
	op(ERoomType::Combat) \
	op(ERoomType::Elite) \
	op(ERoomType::Treasure) \
	op(ERoomType::Shop) \
	op(ERoomType::Puzzle) \
	op(ERoomType::Rest) \
	op(ERoomType::Boss) \
	op(ERoomType::Start) \
	op(ERoomType::Exit) \
	op(ERoomType::Extraction) \
	op(ERoomType::Hallway) 

enum class ERoomType : uint8;
template<> struct TIsUEnumClass<ERoomType> { enum { Value = true }; };
template<> ETERNALDESCENT_API UEnum* StaticEnum<ERoomType>();

#define FOREACH_ENUM_EENTITYPERSONALITY(op) \
	op(EEntityPersonality::Observer) \
	op(EEntityPersonality::Challenger) \
	op(EEntityPersonality::Counter) \
	op(EEntityPersonality::Architect) \
	op(EEntityPersonality::Historian) \
	op(EEntityPersonality::Prophet) 

enum class EEntityPersonality : uint8;
template<> struct TIsUEnumClass<EEntityPersonality> { enum { Value = true }; };
template<> ETERNALDESCENT_API UEnum* StaticEnum<EEntityPersonality>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
