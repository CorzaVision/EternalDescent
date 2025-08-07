// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "CubeDungeonGenerator.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FCubeDungeonLayout;
#ifdef ETERNALDESCENT_CubeDungeonGenerator_generated_h
#error "CubeDungeonGenerator.generated.h already included, missing '#pragma once' in CubeDungeonGenerator.h"
#endif
#define ETERNALDESCENT_CubeDungeonGenerator_generated_h

#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_CubeDungeonGenerator_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetCubeSize); \
	DECLARE_FUNCTION(execSetCubeSize); \
	DECLARE_FUNCTION(execGenerateCubeDungeon);


#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_CubeDungeonGenerator_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACubeDungeonGenerator(); \
	friend struct Z_Construct_UClass_ACubeDungeonGenerator_Statics; \
public: \
	DECLARE_CLASS(ACubeDungeonGenerator, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/EternalDescent"), NO_API) \
	DECLARE_SERIALIZER(ACubeDungeonGenerator)


#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_CubeDungeonGenerator_h_17_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ACubeDungeonGenerator(ACubeDungeonGenerator&&); \
	ACubeDungeonGenerator(const ACubeDungeonGenerator&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACubeDungeonGenerator); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACubeDungeonGenerator); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACubeDungeonGenerator) \
	NO_API virtual ~ACubeDungeonGenerator();


#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_CubeDungeonGenerator_h_14_PROLOG
#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_CubeDungeonGenerator_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_CubeDungeonGenerator_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_CubeDungeonGenerator_h_17_INCLASS_NO_PURE_DECLS \
	FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_CubeDungeonGenerator_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ETERNALDESCENT_API UClass* StaticClass<class ACubeDungeonGenerator>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_CubeDungeonGenerator_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
