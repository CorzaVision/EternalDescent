// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class EternalDescent : ModuleRules
{
	public EternalDescent(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
