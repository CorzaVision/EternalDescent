// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "RPGComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ETERNALDESCENT_RPGComponent_generated_h
#error "RPGComponent.generated.h already included, missing '#pragma once' in RPGComponent.h"
#endif
#define ETERNALDESCENT_RPGComponent_generated_h

#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_RPGComponent_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execInitializeRPG);


#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_RPGComponent_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesURPGComponent(); \
	friend struct Z_Construct_UClass_URPGComponent_Statics; \
public: \
	DECLARE_CLASS(URPGComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/EternalDescent"), NO_API) \
	DECLARE_SERIALIZER(URPGComponent) \
	virtual UObject* _getUObject() const override { return const_cast<URPGComponent*>(this); }


#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_RPGComponent_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	URPGComponent(URPGComponent&&); \
	URPGComponent(const URPGComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URPGComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URPGComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(URPGComponent) \
	NO_API virtual ~URPGComponent();


#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_RPGComponent_h_12_PROLOG
#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_RPGComponent_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_RPGComponent_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_RPGComponent_h_15_INCLASS_NO_PURE_DECLS \
	FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_RPGComponent_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ETERNALDESCENT_API UClass* StaticClass<class URPGComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_RPGComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
