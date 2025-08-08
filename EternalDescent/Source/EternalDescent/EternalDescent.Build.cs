// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class EternalDescent : ModuleRules
{
	public EternalDescent(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		
		// UE 5.5 specific settings
		bUseUnity = false;
		CppStandard = CppStandardVersion.Cpp20;
		
		// Performance optimizations (UE 5.5 compatible)
		MinFilesUsingPrecompiledHeaderOverride = 1;
		
		// Runtime performance optimizations
		if (Target.Configuration == UnrealTargetConfiguration.Shipping ||
		    Target.Configuration == UnrealTargetConfiguration.Development)
		{
			PublicDefinitions.Add("WITH_PERFCOUNTERS=1");
		}

		PublicDependencyModuleNames.AddRange(new string[] { 
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"EnhancedInput",
			"UMG",
			"Slate",
			"SlateCore",
			"AIModule",
			"NavigationSystem",
			"GameplayTags",
			"GameplayTasks",
			"GameplayAbilities",
			"PCG",
			"GeometryCore",
			"ProceduralMeshComponent",
			"Niagara",
			"NetCore",
			"PhysicsCore"
		});
		
		// Private dependencies
		PrivateDependencyModuleNames.AddRange(new string[] {
			"DeveloperSettings",
			"RenderCore",
			"RHI",
			"Projects",
			"EngineSettings",
			"ApplicationCore"
		});
		
		// Note: Include paths are handled automatically by UE 5.5 module dependencies
		
		// Add test dependencies for automation
		if (Target.Configuration != UnrealTargetConfiguration.Shipping)
		{
			PrivateDependencyModuleNames.AddRange(new string[] {
				"UnrealEd",
				"AutomationController",
				"EditorSubsystem",
				"ToolMenus",
				"FunctionalTesting"
			});
		}
		
		// Enable RTTI for better debugging in development builds
		if (Target.Configuration == UnrealTargetConfiguration.Debug || 
		    Target.Configuration == UnrealTargetConfiguration.Development)
		{
			bUseRTTI = true;
		}
	}
}
