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
		
		// Optimize for faster iteration
		MinFilesUsingPrecompiledHeaderOverride = 1;
		bUsePrecompiledHeadersFromMemory = true;

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
		
		// UE 5.5 requires explicit inclusion of these for instanced mesh components
		PublicIncludePaths.AddRange(new string[] {
			"Runtime/Engine/Classes",
			"Runtime/Engine/Public"
		});
		
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
