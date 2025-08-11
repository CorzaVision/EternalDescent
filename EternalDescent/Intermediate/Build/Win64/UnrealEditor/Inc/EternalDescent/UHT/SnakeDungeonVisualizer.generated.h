// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SnakeDungeonVisualizer.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FSnakeGenerationResult;
#ifdef ETERNALDESCENT_SnakeDungeonVisualizer_generated_h
#error "SnakeDungeonVisualizer.generated.h already included, missing '#pragma once' in SnakeDungeonVisualizer.h"
#endif
#define ETERNALDESCENT_SnakeDungeonVisualizer_generated_h

#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonVisualizer_h_37_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetCurrentResult); \
	DECLARE_FUNCTION(execRegenerateWithNewSeed); \
	DECLARE_FUNCTION(execClearVisualization); \
	DECLARE_FUNCTION(execGenerateAndVisualize);


#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonVisualizer_h_37_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASnakeDungeonVisualizer(); \
	friend struct Z_Construct_UClass_ASnakeDungeonVisualizer_Statics; \
public: \
	DECLARE_CLASS(ASnakeDungeonVisualizer, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/EternalDescent"), NO_API) \
	DECLARE_SERIALIZER(ASnakeDungeonVisualizer)


#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonVisualizer_h_37_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ASnakeDungeonVisualizer(ASnakeDungeonVisualizer&&); \
	ASnakeDungeonVisualizer(const ASnakeDungeonVisualizer&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASnakeDungeonVisualizer); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASnakeDungeonVisualizer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASnakeDungeonVisualizer) \
	NO_API virtual ~ASnakeDungeonVisualizer();


#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonVisualizer_h_34_PROLOG
#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonVisualizer_h_37_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonVisualizer_h_37_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonVisualizer_h_37_INCLASS_NO_PURE_DECLS \
	FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonVisualizer_h_37_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ETERNALDESCENT_API UClass* StaticClass<class ASnakeDungeonVisualizer>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakeDungeonVisualizer_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
