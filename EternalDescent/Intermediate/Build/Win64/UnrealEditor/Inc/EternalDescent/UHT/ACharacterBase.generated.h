// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "RPGClasses/ACharacterBase.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FInputActionValue;
#ifdef ETERNALDESCENT_ACharacterBase_generated_h
#error "ACharacterBase.generated.h already included, missing '#pragma once' in ACharacterBase.h"
#endif
#define ETERNALDESCENT_ACharacterBase_generated_h

#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_RPGClasses_ACharacterBase_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execMenu); \
	DECLARE_FUNCTION(execSkills); \
	DECLARE_FUNCTION(execInventory); \
	DECLARE_FUNCTION(execInteract); \
	DECLARE_FUNCTION(execDodge); \
	DECLARE_FUNCTION(execSpecial); \
	DECLARE_FUNCTION(execSecondaryAttack); \
	DECLARE_FUNCTION(execBlock); \
	DECLARE_FUNCTION(execAttack);


#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_RPGClasses_ACharacterBase_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAACharacterBase(); \
	friend struct Z_Construct_UClass_AACharacterBase_Statics; \
public: \
	DECLARE_CLASS(AACharacterBase, AEternalDescentCharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/EternalDescent"), NO_API) \
	DECLARE_SERIALIZER(AACharacterBase)


#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_RPGClasses_ACharacterBase_h_17_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AACharacterBase(AACharacterBase&&); \
	AACharacterBase(const AACharacterBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AACharacterBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AACharacterBase); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AACharacterBase) \
	NO_API virtual ~AACharacterBase();


#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_RPGClasses_ACharacterBase_h_14_PROLOG
#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_RPGClasses_ACharacterBase_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_RPGClasses_ACharacterBase_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_RPGClasses_ACharacterBase_h_17_INCLASS_NO_PURE_DECLS \
	FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_RPGClasses_ACharacterBase_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ETERNALDESCENT_API UClass* StaticClass<class AACharacterBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_RPGClasses_ACharacterBase_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
