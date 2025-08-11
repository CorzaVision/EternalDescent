// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SnakePathGenerator.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FSnakeGenerationConfig;
struct FSnakeGenerationResult;
struct FSnakeRoomData;
#ifdef ETERNALDESCENT_SnakePathGenerator_generated_h
#error "SnakePathGenerator.generated.h already included, missing '#pragma once' in SnakePathGenerator.h"
#endif
#define ETERNALDESCENT_SnakePathGenerator_generated_h

#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakePathGenerator_h_20_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSnakeRoomData_Statics; \
	ETERNALDESCENT_API static class UScriptStruct* StaticStruct();


template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<struct FSnakeRoomData>();

#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakePathGenerator_h_55_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSnakeGenerationResult_Statics; \
	ETERNALDESCENT_API static class UScriptStruct* StaticStruct();


template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<struct FSnakeGenerationResult>();

#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakePathGenerator_h_102_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSnakeGenerationConfig_Statics; \
	ETERNALDESCENT_API static class UScriptStruct* StaticStruct();


template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<struct FSnakeGenerationConfig>();

#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakePathGenerator_h_163_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execValidateRoomConfiguration); \
	DECLARE_FUNCTION(execCalculateOptimalGridSize); \
	DECLARE_FUNCTION(execGenerateSnakePath);


#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakePathGenerator_h_163_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSnakePathGenerator(); \
	friend struct Z_Construct_UClass_USnakePathGenerator_Statics; \
public: \
	DECLARE_CLASS(USnakePathGenerator, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/EternalDescent"), NO_API) \
	DECLARE_SERIALIZER(USnakePathGenerator)


#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakePathGenerator_h_163_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	USnakePathGenerator(USnakePathGenerator&&); \
	USnakePathGenerator(const USnakePathGenerator&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USnakePathGenerator); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USnakePathGenerator); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USnakePathGenerator) \
	NO_API virtual ~USnakePathGenerator();


#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakePathGenerator_h_160_PROLOG
#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakePathGenerator_h_163_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakePathGenerator_h_163_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakePathGenerator_h_163_INCLASS_NO_PURE_DECLS \
	FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakePathGenerator_h_163_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ETERNALDESCENT_API UClass* StaticClass<class USnakePathGenerator>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_SnakePathGenerator_h


#define FOREACH_ENUM_ESNAKEROOMSIZE(op) \
	op(ESnakeRoomSize::None) \
	op(ESnakeRoomSize::Small_2x2) \
	op(ESnakeRoomSize::Standard_3x3) 

enum class ESnakeRoomSize : uint8;
template<> struct TIsUEnumClass<ESnakeRoomSize> { enum { Value = true }; };
template<> ETERNALDESCENT_API UEnum* StaticEnum<ESnakeRoomSize>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
