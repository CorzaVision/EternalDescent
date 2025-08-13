// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EternalDescent/Public/RPGClasses/ACharacterBase.h"
#include "EnhancedInput/Public/InputActionValue.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeACharacterBase() {}

// Begin Cross Module References
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UEnhancedInputComponent_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
ENHANCEDINPUT_API UScriptStruct* Z_Construct_UScriptStruct_FInputActionValue();
ETERNALDESCENT_API UClass* Z_Construct_UClass_AACharacterBase();
ETERNALDESCENT_API UClass* Z_Construct_UClass_AACharacterBase_NoRegister();
ETERNALDESCENT_API UClass* Z_Construct_UClass_AEternalDescentCharacter();
UPackage* Z_Construct_UPackage__Script_EternalDescent();
// End Cross Module References

// Begin Class AACharacterBase Function Attack
struct Z_Construct_UFunction_AACharacterBase_Attack_Statics
{
	struct ACharacterBase_eventAttack_Parms
	{
		FInputActionValue Value;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Combat" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Combat Functions\n" },
#endif
		{ "ModuleRelativePath", "Public/RPGClasses/ACharacterBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Combat Functions" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AACharacterBase_Attack_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACharacterBase_eventAttack_Parms, Value), Z_Construct_UScriptStruct_FInputActionValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) }; // 494646648
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AACharacterBase_Attack_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AACharacterBase_Attack_Statics::NewProp_Value,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AACharacterBase_Attack_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AACharacterBase_Attack_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AACharacterBase, nullptr, "Attack", nullptr, nullptr, Z_Construct_UFunction_AACharacterBase_Attack_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AACharacterBase_Attack_Statics::PropPointers), sizeof(Z_Construct_UFunction_AACharacterBase_Attack_Statics::ACharacterBase_eventAttack_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AACharacterBase_Attack_Statics::Function_MetaDataParams), Z_Construct_UFunction_AACharacterBase_Attack_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AACharacterBase_Attack_Statics::ACharacterBase_eventAttack_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AACharacterBase_Attack()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AACharacterBase_Attack_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AACharacterBase::execAttack)
{
	P_GET_STRUCT_REF(FInputActionValue,Z_Param_Out_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Attack(Z_Param_Out_Value);
	P_NATIVE_END;
}
// End Class AACharacterBase Function Attack

// Begin Class AACharacterBase Function Block
struct Z_Construct_UFunction_AACharacterBase_Block_Statics
{
	struct ACharacterBase_eventBlock_Parms
	{
		FInputActionValue Value;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/RPGClasses/ACharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AACharacterBase_Block_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACharacterBase_eventBlock_Parms, Value), Z_Construct_UScriptStruct_FInputActionValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) }; // 494646648
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AACharacterBase_Block_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AACharacterBase_Block_Statics::NewProp_Value,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AACharacterBase_Block_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AACharacterBase_Block_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AACharacterBase, nullptr, "Block", nullptr, nullptr, Z_Construct_UFunction_AACharacterBase_Block_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AACharacterBase_Block_Statics::PropPointers), sizeof(Z_Construct_UFunction_AACharacterBase_Block_Statics::ACharacterBase_eventBlock_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AACharacterBase_Block_Statics::Function_MetaDataParams), Z_Construct_UFunction_AACharacterBase_Block_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AACharacterBase_Block_Statics::ACharacterBase_eventBlock_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AACharacterBase_Block()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AACharacterBase_Block_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AACharacterBase::execBlock)
{
	P_GET_STRUCT_REF(FInputActionValue,Z_Param_Out_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Block(Z_Param_Out_Value);
	P_NATIVE_END;
}
// End Class AACharacterBase Function Block

// Begin Class AACharacterBase Function Dodge
struct Z_Construct_UFunction_AACharacterBase_Dodge_Statics
{
	struct ACharacterBase_eventDodge_Parms
	{
		FInputActionValue Value;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/RPGClasses/ACharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AACharacterBase_Dodge_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACharacterBase_eventDodge_Parms, Value), Z_Construct_UScriptStruct_FInputActionValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) }; // 494646648
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AACharacterBase_Dodge_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AACharacterBase_Dodge_Statics::NewProp_Value,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AACharacterBase_Dodge_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AACharacterBase_Dodge_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AACharacterBase, nullptr, "Dodge", nullptr, nullptr, Z_Construct_UFunction_AACharacterBase_Dodge_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AACharacterBase_Dodge_Statics::PropPointers), sizeof(Z_Construct_UFunction_AACharacterBase_Dodge_Statics::ACharacterBase_eventDodge_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AACharacterBase_Dodge_Statics::Function_MetaDataParams), Z_Construct_UFunction_AACharacterBase_Dodge_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AACharacterBase_Dodge_Statics::ACharacterBase_eventDodge_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AACharacterBase_Dodge()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AACharacterBase_Dodge_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AACharacterBase::execDodge)
{
	P_GET_STRUCT_REF(FInputActionValue,Z_Param_Out_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Dodge(Z_Param_Out_Value);
	P_NATIVE_END;
}
// End Class AACharacterBase Function Dodge

// Begin Class AACharacterBase Function Interact
struct Z_Construct_UFunction_AACharacterBase_Interact_Statics
{
	struct ACharacterBase_eventInteract_Parms
	{
		FInputActionValue Value;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Gameplay" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Gameplay Functions\n" },
#endif
		{ "ModuleRelativePath", "Public/RPGClasses/ACharacterBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Gameplay Functions" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AACharacterBase_Interact_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACharacterBase_eventInteract_Parms, Value), Z_Construct_UScriptStruct_FInputActionValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) }; // 494646648
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AACharacterBase_Interact_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AACharacterBase_Interact_Statics::NewProp_Value,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AACharacterBase_Interact_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AACharacterBase_Interact_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AACharacterBase, nullptr, "Interact", nullptr, nullptr, Z_Construct_UFunction_AACharacterBase_Interact_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AACharacterBase_Interact_Statics::PropPointers), sizeof(Z_Construct_UFunction_AACharacterBase_Interact_Statics::ACharacterBase_eventInteract_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AACharacterBase_Interact_Statics::Function_MetaDataParams), Z_Construct_UFunction_AACharacterBase_Interact_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AACharacterBase_Interact_Statics::ACharacterBase_eventInteract_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AACharacterBase_Interact()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AACharacterBase_Interact_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AACharacterBase::execInteract)
{
	P_GET_STRUCT_REF(FInputActionValue,Z_Param_Out_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Interact(Z_Param_Out_Value);
	P_NATIVE_END;
}
// End Class AACharacterBase Function Interact

// Begin Class AACharacterBase Function Inventory
struct Z_Construct_UFunction_AACharacterBase_Inventory_Statics
{
	struct ACharacterBase_eventInventory_Parms
	{
		FInputActionValue Value;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Gameplay" },
		{ "ModuleRelativePath", "Public/RPGClasses/ACharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AACharacterBase_Inventory_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACharacterBase_eventInventory_Parms, Value), Z_Construct_UScriptStruct_FInputActionValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) }; // 494646648
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AACharacterBase_Inventory_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AACharacterBase_Inventory_Statics::NewProp_Value,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AACharacterBase_Inventory_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AACharacterBase_Inventory_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AACharacterBase, nullptr, "Inventory", nullptr, nullptr, Z_Construct_UFunction_AACharacterBase_Inventory_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AACharacterBase_Inventory_Statics::PropPointers), sizeof(Z_Construct_UFunction_AACharacterBase_Inventory_Statics::ACharacterBase_eventInventory_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AACharacterBase_Inventory_Statics::Function_MetaDataParams), Z_Construct_UFunction_AACharacterBase_Inventory_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AACharacterBase_Inventory_Statics::ACharacterBase_eventInventory_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AACharacterBase_Inventory()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AACharacterBase_Inventory_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AACharacterBase::execInventory)
{
	P_GET_STRUCT_REF(FInputActionValue,Z_Param_Out_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Inventory(Z_Param_Out_Value);
	P_NATIVE_END;
}
// End Class AACharacterBase Function Inventory

// Begin Class AACharacterBase Function Menu
struct Z_Construct_UFunction_AACharacterBase_Menu_Statics
{
	struct ACharacterBase_eventMenu_Parms
	{
		FInputActionValue Value;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Gameplay" },
		{ "ModuleRelativePath", "Public/RPGClasses/ACharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AACharacterBase_Menu_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACharacterBase_eventMenu_Parms, Value), Z_Construct_UScriptStruct_FInputActionValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) }; // 494646648
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AACharacterBase_Menu_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AACharacterBase_Menu_Statics::NewProp_Value,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AACharacterBase_Menu_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AACharacterBase_Menu_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AACharacterBase, nullptr, "Menu", nullptr, nullptr, Z_Construct_UFunction_AACharacterBase_Menu_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AACharacterBase_Menu_Statics::PropPointers), sizeof(Z_Construct_UFunction_AACharacterBase_Menu_Statics::ACharacterBase_eventMenu_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AACharacterBase_Menu_Statics::Function_MetaDataParams), Z_Construct_UFunction_AACharacterBase_Menu_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AACharacterBase_Menu_Statics::ACharacterBase_eventMenu_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AACharacterBase_Menu()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AACharacterBase_Menu_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AACharacterBase::execMenu)
{
	P_GET_STRUCT_REF(FInputActionValue,Z_Param_Out_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Menu(Z_Param_Out_Value);
	P_NATIVE_END;
}
// End Class AACharacterBase Function Menu

// Begin Class AACharacterBase Function SecondaryAttack
struct Z_Construct_UFunction_AACharacterBase_SecondaryAttack_Statics
{
	struct ACharacterBase_eventSecondaryAttack_Parms
	{
		FInputActionValue Value;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/RPGClasses/ACharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AACharacterBase_SecondaryAttack_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACharacterBase_eventSecondaryAttack_Parms, Value), Z_Construct_UScriptStruct_FInputActionValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) }; // 494646648
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AACharacterBase_SecondaryAttack_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AACharacterBase_SecondaryAttack_Statics::NewProp_Value,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AACharacterBase_SecondaryAttack_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AACharacterBase_SecondaryAttack_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AACharacterBase, nullptr, "SecondaryAttack", nullptr, nullptr, Z_Construct_UFunction_AACharacterBase_SecondaryAttack_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AACharacterBase_SecondaryAttack_Statics::PropPointers), sizeof(Z_Construct_UFunction_AACharacterBase_SecondaryAttack_Statics::ACharacterBase_eventSecondaryAttack_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AACharacterBase_SecondaryAttack_Statics::Function_MetaDataParams), Z_Construct_UFunction_AACharacterBase_SecondaryAttack_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AACharacterBase_SecondaryAttack_Statics::ACharacterBase_eventSecondaryAttack_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AACharacterBase_SecondaryAttack()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AACharacterBase_SecondaryAttack_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AACharacterBase::execSecondaryAttack)
{
	P_GET_STRUCT_REF(FInputActionValue,Z_Param_Out_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SecondaryAttack(Z_Param_Out_Value);
	P_NATIVE_END;
}
// End Class AACharacterBase Function SecondaryAttack

// Begin Class AACharacterBase Function Skills
struct Z_Construct_UFunction_AACharacterBase_Skills_Statics
{
	struct ACharacterBase_eventSkills_Parms
	{
		FInputActionValue Value;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Gameplay" },
		{ "ModuleRelativePath", "Public/RPGClasses/ACharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AACharacterBase_Skills_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACharacterBase_eventSkills_Parms, Value), Z_Construct_UScriptStruct_FInputActionValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) }; // 494646648
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AACharacterBase_Skills_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AACharacterBase_Skills_Statics::NewProp_Value,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AACharacterBase_Skills_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AACharacterBase_Skills_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AACharacterBase, nullptr, "Skills", nullptr, nullptr, Z_Construct_UFunction_AACharacterBase_Skills_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AACharacterBase_Skills_Statics::PropPointers), sizeof(Z_Construct_UFunction_AACharacterBase_Skills_Statics::ACharacterBase_eventSkills_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AACharacterBase_Skills_Statics::Function_MetaDataParams), Z_Construct_UFunction_AACharacterBase_Skills_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AACharacterBase_Skills_Statics::ACharacterBase_eventSkills_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AACharacterBase_Skills()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AACharacterBase_Skills_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AACharacterBase::execSkills)
{
	P_GET_STRUCT_REF(FInputActionValue,Z_Param_Out_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Skills(Z_Param_Out_Value);
	P_NATIVE_END;
}
// End Class AACharacterBase Function Skills

// Begin Class AACharacterBase Function Special
struct Z_Construct_UFunction_AACharacterBase_Special_Statics
{
	struct ACharacterBase_eventSpecial_Parms
	{
		FInputActionValue Value;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/RPGClasses/ACharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AACharacterBase_Special_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACharacterBase_eventSpecial_Parms, Value), Z_Construct_UScriptStruct_FInputActionValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) }; // 494646648
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AACharacterBase_Special_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AACharacterBase_Special_Statics::NewProp_Value,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AACharacterBase_Special_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AACharacterBase_Special_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AACharacterBase, nullptr, "Special", nullptr, nullptr, Z_Construct_UFunction_AACharacterBase_Special_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AACharacterBase_Special_Statics::PropPointers), sizeof(Z_Construct_UFunction_AACharacterBase_Special_Statics::ACharacterBase_eventSpecial_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AACharacterBase_Special_Statics::Function_MetaDataParams), Z_Construct_UFunction_AACharacterBase_Special_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AACharacterBase_Special_Statics::ACharacterBase_eventSpecial_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AACharacterBase_Special()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AACharacterBase_Special_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AACharacterBase::execSpecial)
{
	P_GET_STRUCT_REF(FInputActionValue,Z_Param_Out_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Special(Z_Param_Out_Value);
	P_NATIVE_END;
}
// End Class AACharacterBase Function Special

// Begin Class AACharacterBase
void AACharacterBase::StaticRegisterNativesAACharacterBase()
{
	UClass* Class = AACharacterBase::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "Attack", &AACharacterBase::execAttack },
		{ "Block", &AACharacterBase::execBlock },
		{ "Dodge", &AACharacterBase::execDodge },
		{ "Interact", &AACharacterBase::execInteract },
		{ "Inventory", &AACharacterBase::execInventory },
		{ "Menu", &AACharacterBase::execMenu },
		{ "SecondaryAttack", &AACharacterBase::execSecondaryAttack },
		{ "Skills", &AACharacterBase::execSkills },
		{ "Special", &AACharacterBase::execSpecial },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AACharacterBase);
UClass* Z_Construct_UClass_AACharacterBase_NoRegister()
{
	return AACharacterBase::StaticClass();
}
struct Z_Construct_UClass_AACharacterBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "RPGClasses/ACharacterBase.h" },
		{ "ModuleRelativePath", "Public/RPGClasses/ACharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DodgeAction_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Combat Input Actions\n" },
#endif
		{ "ModuleRelativePath", "Public/RPGClasses/ACharacterBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Combat Input Actions" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/RPGClasses/ACharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BlockAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/RPGClasses/ACharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SecondaryAttackAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/RPGClasses/ACharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpecialAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/RPGClasses/ACharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractAction_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Gameplay Input Actions\n" },
#endif
		{ "ModuleRelativePath", "Public/RPGClasses/ACharacterBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Gameplay Input Actions" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InventoryAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/RPGClasses/ACharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SkillsAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/RPGClasses/ACharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MenuAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/RPGClasses/ACharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EnhancedInputComponent_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Enhanced Input Component\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/RPGClasses/ACharacterBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Enhanced Input Component" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InputMappingContext_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Input Mapping Context\n" },
#endif
		{ "ModuleRelativePath", "Public/RPGClasses/ACharacterBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Input Mapping Context" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DodgeAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AttackAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BlockAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SecondaryAttackAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpecialAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InteractAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InventoryAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SkillsAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MenuAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_EnhancedInputComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InputMappingContext;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AACharacterBase_Attack, "Attack" }, // 2211494628
		{ &Z_Construct_UFunction_AACharacterBase_Block, "Block" }, // 2743955321
		{ &Z_Construct_UFunction_AACharacterBase_Dodge, "Dodge" }, // 2231873576
		{ &Z_Construct_UFunction_AACharacterBase_Interact, "Interact" }, // 1801897429
		{ &Z_Construct_UFunction_AACharacterBase_Inventory, "Inventory" }, // 2057087885
		{ &Z_Construct_UFunction_AACharacterBase_Menu, "Menu" }, // 1243823868
		{ &Z_Construct_UFunction_AACharacterBase_SecondaryAttack, "SecondaryAttack" }, // 3880025528
		{ &Z_Construct_UFunction_AACharacterBase_Skills, "Skills" }, // 3307376243
		{ &Z_Construct_UFunction_AACharacterBase_Special, "Special" }, // 4015479732
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AACharacterBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AACharacterBase_Statics::NewProp_DodgeAction = { "DodgeAction", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AACharacterBase, DodgeAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DodgeAction_MetaData), NewProp_DodgeAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AACharacterBase_Statics::NewProp_AttackAction = { "AttackAction", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AACharacterBase, AttackAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackAction_MetaData), NewProp_AttackAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AACharacterBase_Statics::NewProp_BlockAction = { "BlockAction", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AACharacterBase, BlockAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BlockAction_MetaData), NewProp_BlockAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AACharacterBase_Statics::NewProp_SecondaryAttackAction = { "SecondaryAttackAction", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AACharacterBase, SecondaryAttackAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SecondaryAttackAction_MetaData), NewProp_SecondaryAttackAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AACharacterBase_Statics::NewProp_SpecialAction = { "SpecialAction", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AACharacterBase, SpecialAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpecialAction_MetaData), NewProp_SpecialAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AACharacterBase_Statics::NewProp_InteractAction = { "InteractAction", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AACharacterBase, InteractAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractAction_MetaData), NewProp_InteractAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AACharacterBase_Statics::NewProp_InventoryAction = { "InventoryAction", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AACharacterBase, InventoryAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InventoryAction_MetaData), NewProp_InventoryAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AACharacterBase_Statics::NewProp_SkillsAction = { "SkillsAction", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AACharacterBase, SkillsAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SkillsAction_MetaData), NewProp_SkillsAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AACharacterBase_Statics::NewProp_MenuAction = { "MenuAction", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AACharacterBase, MenuAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MenuAction_MetaData), NewProp_MenuAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AACharacterBase_Statics::NewProp_EnhancedInputComponent = { "EnhancedInputComponent", nullptr, (EPropertyFlags)0x00200800000a000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AACharacterBase, EnhancedInputComponent), Z_Construct_UClass_UEnhancedInputComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EnhancedInputComponent_MetaData), NewProp_EnhancedInputComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AACharacterBase_Statics::NewProp_InputMappingContext = { "InputMappingContext", nullptr, (EPropertyFlags)0x0020080000020005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AACharacterBase, InputMappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InputMappingContext_MetaData), NewProp_InputMappingContext_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AACharacterBase_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AACharacterBase_Statics::NewProp_DodgeAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AACharacterBase_Statics::NewProp_AttackAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AACharacterBase_Statics::NewProp_BlockAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AACharacterBase_Statics::NewProp_SecondaryAttackAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AACharacterBase_Statics::NewProp_SpecialAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AACharacterBase_Statics::NewProp_InteractAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AACharacterBase_Statics::NewProp_InventoryAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AACharacterBase_Statics::NewProp_SkillsAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AACharacterBase_Statics::NewProp_MenuAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AACharacterBase_Statics::NewProp_EnhancedInputComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AACharacterBase_Statics::NewProp_InputMappingContext,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AACharacterBase_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AACharacterBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AEternalDescentCharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_EternalDescent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AACharacterBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AACharacterBase_Statics::ClassParams = {
	&AACharacterBase::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AACharacterBase_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AACharacterBase_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AACharacterBase_Statics::Class_MetaDataParams), Z_Construct_UClass_AACharacterBase_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AACharacterBase()
{
	if (!Z_Registration_Info_UClass_AACharacterBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AACharacterBase.OuterSingleton, Z_Construct_UClass_AACharacterBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AACharacterBase.OuterSingleton;
}
template<> ETERNALDESCENT_API UClass* StaticClass<AACharacterBase>()
{
	return AACharacterBase::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AACharacterBase);
AACharacterBase::~AACharacterBase() {}
// End Class AACharacterBase

// Begin Registration
struct Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_RPGClasses_ACharacterBase_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AACharacterBase, AACharacterBase::StaticClass, TEXT("AACharacterBase"), &Z_Registration_Info_UClass_AACharacterBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AACharacterBase), 3724765867U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_RPGClasses_ACharacterBase_h_3075762343(TEXT("/Script/EternalDescent"),
	Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_RPGClasses_ACharacterBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_Self_Projects_EternalDescent_EternalDescent_Source_EternalDescent_Public_RPGClasses_ACharacterBase_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
