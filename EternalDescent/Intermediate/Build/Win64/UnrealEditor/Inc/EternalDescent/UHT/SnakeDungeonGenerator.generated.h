// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SnakeDungeonGenerator.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FSnakeDungeonLayout;
#ifdef ETERNALDESCENT_SnakeDungeonGenerator_generated_h
#error "SnakeDungeonGenerator.generated.h already included, missing '#pragma once' in SnakeDungeonGenerator.h"
#endif
#define ETERNALDESCENT_SnakeDungeonGenerator_generated_h

#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonGenerator_h_36_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FContentMarker_Statics; \
	ETERNALDESCENT_API static class UScriptStruct* StaticStruct();


template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<struct FContentMarker>();

#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonGenerator_h_70_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSnakeRoom_Statics; \
	ETERNALDESCENT_API static class UScriptStruct* StaticStruct();


template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<struct FSnakeRoom>();

#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonGenerator_h_146_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FHallwayConnection_Statics; \
	ETERNALDESCENT_API static class UScriptStruct* StaticStruct();


template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<struct FHallwayConnection>();

#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonGenerator_h_175_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSnakeDungeonLayout_Statics; \
	ETERNALDESCENT_API static class UScriptStruct* StaticStruct();


template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<struct FSnakeDungeonLayout>();

#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonGenerator_h_231_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSetDifficulty); \
	DECLARE_FUNCTION(execGenerateSnakeDungeon);


#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonGenerator_h_231_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASnakeDungeonGenerator(); \
	friend struct Z_Construct_UClass_ASnakeDungeonGenerator_Statics; \
public: \
	DECLARE_CLASS(ASnakeDungeonGenerator, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/EternalDescent"), NO_API) \
	DECLARE_SERIALIZER(ASnakeDungeonGenerator)


#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonGenerator_h_231_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ASnakeDungeonGenerator(ASnakeDungeonGenerator&&); \
	ASnakeDungeonGenerator(const ASnakeDungeonGenerator&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASnakeDungeonGenerator); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASnakeDungeonGenerator); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASnakeDungeonGenerator) \
	NO_API virtual ~ASnakeDungeonGenerator();


#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonGenerator_h_228_PROLOG
#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonGenerator_h_231_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonGenerator_h_231_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonGenerator_h_231_INCLASS_NO_PURE_DECLS \
	FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonGenerator_h_231_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ETERNALDESCENT_API UClass* StaticClass<class ASnakeDungeonGenerator>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonGenerator_h


#define FOREACH_ENUM_ESTAGETYPE(op) \
	op(EStageType::Normal) \
	op(EStageType::Elite) \
	op(EStageType::Boss) \
	op(EStageType::SafeZone) 

enum class EStageType : uint8;
template<> struct TIsUEnumClass<EStageType> { enum { Value = true }; };
template<> ETERNALDESCENT_API UEnum* StaticEnum<EStageType>();

#define FOREACH_ENUM_ECONTENTMARKERTYPE(op) \
	op(EContentMarkerType::Enemy) \
	op(EContentMarkerType::Chest) \
	op(EContentMarkerType::Puzzle) \
	op(EContentMarkerType::Interactable) \
	op(EContentMarkerType::Elite) \
	op(EContentMarkerType::Boss) 

enum class EContentMarkerType : uint8;
template<> struct TIsUEnumClass<EContentMarkerType> { enum { Value = true }; };
template<> ETERNALDESCENT_API UEnum* StaticEnum<EContentMarkerType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
