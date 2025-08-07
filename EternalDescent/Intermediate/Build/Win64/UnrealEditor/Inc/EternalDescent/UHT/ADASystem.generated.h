// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ADASystem.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EADAMood : uint8;
enum class EPlayerArchetype : uint8;
struct FADAMessage;
struct FLinearColor;
struct FPlayerBehaviorData;
#ifdef ETERNALDESCENT_ADASystem_generated_h
#error "ADASystem.generated.h already included, missing '#pragma once' in ADASystem.h"
#endif
#define ETERNALDESCENT_ADASystem_generated_h

#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_ADASystem_h_44_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FPlayerBehaviorData_Statics; \
	ETERNALDESCENT_API static class UScriptStruct* StaticStruct();


template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<struct FPlayerBehaviorData>();

#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_ADASystem_h_74_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FADAMessage_Statics; \
	ETERNALDESCENT_API static class UScriptStruct* StaticStruct();


template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<struct FADAMessage>();

#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_ADASystem_h_95_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FAdaptationData_Statics; \
	ETERNALDESCENT_API static class UScriptStruct* StaticStruct();


template<> ETERNALDESCENT_API UScriptStruct* StaticStruct<struct FAdaptationData>();

#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_ADASystem_h_121_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execUpdateMoodBasedOnPerformance); \
	DECLARE_FUNCTION(execGetPersonalityDescription); \
	DECLARE_FUNCTION(execGetMoodColor); \
	DECLARE_FUNCTION(execSelectEnemyTypes); \
	DECLARE_FUNCTION(execInjectPsychologicalElements); \
	DECLARE_FUNCTION(execModifyDungeonDifficulty); \
	DECLARE_FUNCTION(execLoadHistoricalData); \
	DECLARE_FUNCTION(execSaveRunData); \
	DECLARE_FUNCTION(execRecordPlayerAction); \
	DECLARE_FUNCTION(execCalculateAdaptationStrength); \
	DECLARE_FUNCTION(execGenerateCounterStrategies); \
	DECLARE_FUNCTION(execAdaptToPlayerStrategy); \
	DECLARE_FUNCTION(execGenerateContextualMessage); \
	DECLARE_FUNCTION(execSendMessage); \
	DECLARE_FUNCTION(execDeterminePlayerArchetype); \
	DECLARE_FUNCTION(execAnalyzePlayerBehavior); \
	DECLARE_FUNCTION(execUpdatePersonality); \
	DECLARE_FUNCTION(execInitializeADA);


#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_ADASystem_h_121_CALLBACK_WRAPPERS
#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_ADASystem_h_121_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAADASystem(); \
	friend struct Z_Construct_UClass_AADASystem_Statics; \
public: \
	DECLARE_CLASS(AADASystem, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/EternalDescent"), NO_API) \
	DECLARE_SERIALIZER(AADASystem)


#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_ADASystem_h_121_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AADASystem(AADASystem&&); \
	AADASystem(const AADASystem&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AADASystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AADASystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AADASystem) \
	NO_API virtual ~AADASystem();


#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_ADASystem_h_118_PROLOG
#define FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_ADASystem_h_121_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_ADASystem_h_121_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_ADASystem_h_121_CALLBACK_WRAPPERS \
	FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_ADASystem_h_121_INCLASS_NO_PURE_DECLS \
	FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_ADASystem_h_121_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ETERNALDESCENT_API UClass* StaticClass<class AADASystem>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_ADASystem_h


#define FOREACH_ENUM_EADAPERSONALITY(op) \
	op(EADAPersonality::Observer) \
	op(EADAPersonality::Tester) \
	op(EADAPersonality::Counter) \
	op(EADAPersonality::Dominator) \
	op(EADAPersonality::Experiment) 

enum class EADAPersonality : uint8;
template<> struct TIsUEnumClass<EADAPersonality> { enum { Value = true }; };
template<> ETERNALDESCENT_API UEnum* StaticEnum<EADAPersonality>();

#define FOREACH_ENUM_EADAMOOD(op) \
	op(EADAMood::Curious) \
	op(EADAMood::Amused) \
	op(EADAMood::Challenged) \
	op(EADAMood::Frustrated) \
	op(EADAMood::Impressed) 

enum class EADAMood : uint8;
template<> struct TIsUEnumClass<EADAMood> { enum { Value = true }; };
template<> ETERNALDESCENT_API UEnum* StaticEnum<EADAMood>();

#define FOREACH_ENUM_EPLAYERARCHETYPE(op) \
	op(EPlayerArchetype::Unknown) \
	op(EPlayerArchetype::Rusher) \
	op(EPlayerArchetype::Methodical) \
	op(EPlayerArchetype::Looter) \
	op(EPlayerArchetype::Fighter) \
	op(EPlayerArchetype::Explorer) \
	op(EPlayerArchetype::Speedrunner) 

enum class EPlayerArchetype : uint8;
template<> struct TIsUEnumClass<EPlayerArchetype> { enum { Value = true }; };
template<> ETERNALDESCENT_API UEnum* StaticEnum<EPlayerArchetype>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
