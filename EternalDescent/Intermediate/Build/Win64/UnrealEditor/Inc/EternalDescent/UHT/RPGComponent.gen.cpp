// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EternalDescent/Public/RPGComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRPGComponent() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
ETERNALDESCENT_API UClass* Z_Construct_UClass_URPGComponent();
ETERNALDESCENT_API UClass* Z_Construct_UClass_URPGComponent_NoRegister();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAbilitySystemComponent_NoRegister();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAbilitySystemInterface_NoRegister();
UPackage* Z_Construct_UPackage__Script_EternalDescent();
// End Cross Module References

// Begin Class URPGComponent Function InitializeRPG
struct Z_Construct_UFunction_URPGComponent_InitializeRPG_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "RPG" },
		{ "ModuleRelativePath", "Public/RPGComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_URPGComponent_InitializeRPG_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_URPGComponent, nullptr, "InitializeRPG", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_URPGComponent_InitializeRPG_Statics::Function_MetaDataParams), Z_Construct_UFunction_URPGComponent_InitializeRPG_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_URPGComponent_InitializeRPG()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_URPGComponent_InitializeRPG_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(URPGComponent::execInitializeRPG)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitializeRPG();
	P_NATIVE_END;
}
// End Class URPGComponent Function InitializeRPG

// Begin Class URPGComponent
void URPGComponent::StaticRegisterNativesURPGComponent()
{
	UClass* Class = URPGComponent::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "InitializeRPG", &URPGComponent::execInitializeRPG },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(URPGComponent);
UClass* Z_Construct_UClass_URPGComponent_NoRegister()
{
	return URPGComponent::StaticClass();
}
struct Z_Construct_UClass_URPGComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "RPG" },
		{ "IncludePath", "RPGComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/RPGComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Health_MetaData[] = {
		{ "Category", "RPG|Runtime" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Runtime values (initialized from Base* in BeginPlay)\n" },
#endif
		{ "ModuleRelativePath", "Public/RPGComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Runtime values (initialized from Base* in BeginPlay)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Mana_MetaData[] = {
		{ "Category", "RPG|Runtime" },
		{ "ModuleRelativePath", "Public/RPGComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Stamina_MetaData[] = {
		{ "Category", "RPG|Runtime" },
		{ "ModuleRelativePath", "Public/RPGComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Damage_MetaData[] = {
		{ "Category", "RPG|Runtime" },
		{ "ModuleRelativePath", "Public/RPGComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Armor_MetaData[] = {
		{ "Category", "RPG|Runtime" },
		{ "ModuleRelativePath", "Public/RPGComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BaseHealth_MetaData[] = {
		{ "Category", "RPG|Defaults" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Designer defaults (set in Blueprint)\n" },
#endif
		{ "ModuleRelativePath", "Public/RPGComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Designer defaults (set in Blueprint)" },
#endif
		{ "UIMin", "0.0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BaseMana_MetaData[] = {
		{ "Category", "RPG|Defaults" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/RPGComponent.h" },
		{ "UIMin", "0.0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BaseStamina_MetaData[] = {
		{ "Category", "RPG|Defaults" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/RPGComponent.h" },
		{ "UIMin", "0.0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BaseDamage_MetaData[] = {
		{ "Category", "RPG|Defaults" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/RPGComponent.h" },
		{ "UIMin", "0.0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BaseArmor_MetaData[] = {
		{ "Category", "RPG|Defaults" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/RPGComponent.h" },
		{ "UIMin", "0.0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxHealth_MetaData[] = {
		{ "Category", "RPG|Runtime" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Runtime max values (calculated from Base values)\n" },
#endif
		{ "ModuleRelativePath", "Public/RPGComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Runtime max values (calculated from Base values)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxMana_MetaData[] = {
		{ "Category", "RPG|Runtime" },
		{ "ModuleRelativePath", "Public/RPGComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxStamina_MetaData[] = {
		{ "Category", "RPG|Runtime" },
		{ "ModuleRelativePath", "Public/RPGComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AbilitySystem_MetaData[] = {
		{ "Category", "RPG|GAS" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Ability System\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/RPGComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Ability System" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Health;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Mana;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Stamina;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Damage;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Armor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BaseHealth;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BaseMana;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BaseStamina;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BaseDamage;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BaseArmor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxHealth;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxMana;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxStamina;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AbilitySystem;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_URPGComponent_InitializeRPG, "InitializeRPG" }, // 596171425
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<URPGComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_URPGComponent_Statics::NewProp_Health = { "Health", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(URPGComponent, Health), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Health_MetaData), NewProp_Health_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_URPGComponent_Statics::NewProp_Mana = { "Mana", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(URPGComponent, Mana), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Mana_MetaData), NewProp_Mana_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_URPGComponent_Statics::NewProp_Stamina = { "Stamina", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(URPGComponent, Stamina), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Stamina_MetaData), NewProp_Stamina_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_URPGComponent_Statics::NewProp_Damage = { "Damage", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(URPGComponent, Damage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Damage_MetaData), NewProp_Damage_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_URPGComponent_Statics::NewProp_Armor = { "Armor", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(URPGComponent, Armor), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Armor_MetaData), NewProp_Armor_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_URPGComponent_Statics::NewProp_BaseHealth = { "BaseHealth", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(URPGComponent, BaseHealth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BaseHealth_MetaData), NewProp_BaseHealth_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_URPGComponent_Statics::NewProp_BaseMana = { "BaseMana", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(URPGComponent, BaseMana), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BaseMana_MetaData), NewProp_BaseMana_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_URPGComponent_Statics::NewProp_BaseStamina = { "BaseStamina", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(URPGComponent, BaseStamina), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BaseStamina_MetaData), NewProp_BaseStamina_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_URPGComponent_Statics::NewProp_BaseDamage = { "BaseDamage", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(URPGComponent, BaseDamage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BaseDamage_MetaData), NewProp_BaseDamage_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_URPGComponent_Statics::NewProp_BaseArmor = { "BaseArmor", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(URPGComponent, BaseArmor), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BaseArmor_MetaData), NewProp_BaseArmor_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_URPGComponent_Statics::NewProp_MaxHealth = { "MaxHealth", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(URPGComponent, MaxHealth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxHealth_MetaData), NewProp_MaxHealth_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_URPGComponent_Statics::NewProp_MaxMana = { "MaxMana", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(URPGComponent, MaxMana), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxMana_MetaData), NewProp_MaxMana_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_URPGComponent_Statics::NewProp_MaxStamina = { "MaxStamina", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(URPGComponent, MaxStamina), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxStamina_MetaData), NewProp_MaxStamina_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_URPGComponent_Statics::NewProp_AbilitySystem = { "AbilitySystem", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(URPGComponent, AbilitySystem), Z_Construct_UClass_UAbilitySystemComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AbilitySystem_MetaData), NewProp_AbilitySystem_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_URPGComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URPGComponent_Statics::NewProp_Health,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URPGComponent_Statics::NewProp_Mana,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URPGComponent_Statics::NewProp_Stamina,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URPGComponent_Statics::NewProp_Damage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URPGComponent_Statics::NewProp_Armor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URPGComponent_Statics::NewProp_BaseHealth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URPGComponent_Statics::NewProp_BaseMana,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URPGComponent_Statics::NewProp_BaseStamina,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URPGComponent_Statics::NewProp_BaseDamage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URPGComponent_Statics::NewProp_BaseArmor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URPGComponent_Statics::NewProp_MaxHealth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URPGComponent_Statics::NewProp_MaxMana,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URPGComponent_Statics::NewProp_MaxStamina,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URPGComponent_Statics::NewProp_AbilitySystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_URPGComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_URPGComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_EternalDescent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_URPGComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_URPGComponent_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UAbilitySystemInterface_NoRegister, (int32)VTABLE_OFFSET(URPGComponent, IAbilitySystemInterface), false },  // 2272790346
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_URPGComponent_Statics::ClassParams = {
	&URPGComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_URPGComponent_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_URPGComponent_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_URPGComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_URPGComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_URPGComponent()
{
	if (!Z_Registration_Info_UClass_URPGComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_URPGComponent.OuterSingleton, Z_Construct_UClass_URPGComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_URPGComponent.OuterSingleton;
}
template<> ETERNALDESCENT_API UClass* StaticClass<URPGComponent>()
{
	return URPGComponent::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(URPGComponent);
URPGComponent::~URPGComponent() {}
// End Class URPGComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_RPGComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_URPGComponent, URPGComponent::StaticClass, TEXT("URPGComponent"), &Z_Registration_Info_UClass_URPGComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(URPGComponent), 3918006823U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_RPGComponent_h_1730076680(TEXT("/Script/EternalDescent"),
	Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_RPGComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_RPGComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
