// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DungeonGenerator.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EDungeonZone : uint8;
struct FDungeonLayout;
struct FEntityProfile;
#ifdef ETERNALDESCENT_DungeonGenerator_generated_h
#error "DungeonGenerator.generated.h already included, missing '#pragma once' in DungeonGenerator.h"
#endif
#define ETERNALDESCENT_DungeonGenerator_generated_h

#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_DungeonGenerator_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSetEntityProfile); \
	DECLARE_FUNCTION(execSetActiveZone); \
	DECLARE_FUNCTION(execGenerateFloor);


#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_DungeonGenerator_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesADungeonGenerator(); \
	friend struct Z_Construct_UClass_ADungeonGenerator_Statics; \
public: \
	DECLARE_CLASS(ADungeonGenerator, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/EternalDescent"), NO_API) \
	DECLARE_SERIALIZER(ADungeonGenerator)


#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_DungeonGenerator_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ADungeonGenerator(ADungeonGenerator&&); \
	ADungeonGenerator(const ADungeonGenerator&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADungeonGenerator); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADungeonGenerator); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ADungeonGenerator) \
	NO_API virtual ~ADungeonGenerator();


#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_DungeonGenerator_h_10_PROLOG
#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_DungeonGenerator_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_DungeonGenerator_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_DungeonGenerator_h_13_INCLASS_NO_PURE_DECLS \
	FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_DungeonGenerator_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ETERNALDESCENT_API UClass* StaticClass<class ADungeonGenerator>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_DungeonGenerator_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
