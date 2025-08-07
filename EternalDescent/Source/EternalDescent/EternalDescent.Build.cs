// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class EternalDescent : ModuleRules
{
	public EternalDescent(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { 
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"EnhancedInput"
		});
		
		// Add test dependencies for automation
		if (Target.Configuration != UnrealTargetConfiguration.Shipping)
		{
			PrivateDependencyModuleNames.AddRange(new string[] {
				"UnrealEd",
				"AutomationController"
			});
		}
	}
}
