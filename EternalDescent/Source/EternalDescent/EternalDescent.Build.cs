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
		
		// UE 5.5 Module optimizations
		OptimizeCode = CodeOptimization.InShippingBuildsOnly;
		bEnableExceptions = false;
		bEnableObjCExceptions = false;
		
		// UE 5.5 new features
		bLegacyPublicIncludePaths = false;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_5;
		
		// Performance optimizations (UE 5.5 compatible)
		MinFilesUsingPrecompiledHeaderOverride = 1;
		
		// Runtime performance optimizations
		if (Target.Configuration == UnrealTargetConfiguration.Shipping)
		{
			PublicDefinitions.Add("WITH_PERFCOUNTERS=0");
			PublicDefinitions.Add("UE_BUILD_SHIPPING_WITH_EDITOR=0");
		}
		else if (Target.Configuration == UnrealTargetConfiguration.Development)
		{
			PublicDefinitions.Add("WITH_PERFCOUNTERS=1");
		}
		
		// UE 5.5 Nanite and Lumen support
		PublicDefinitions.Add("NANITE_ENABLE=1");
		PublicDefinitions.Add("RHI_RAYTRACING=1");
		
		// UE 5.5 HISM optimizations for dungeon generation
		PublicDefinitions.Add("USE_HISM_POOLING=1");
		PublicDefinitions.Add("HISM_BATCH_SIZE=256");

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
			"PhysicsCore",
			"Foliage", // UE 5.5 HISM support
			"Landscape", // UE 5.5 World Partition support
			"Chaos" // UE 5.5 Physics
		});
		
		// Private dependencies
		PrivateDependencyModuleNames.AddRange(new string[] {
			"DeveloperSettings",
			"RenderCore",
			"RHI",
			"Projects",
			"EngineSettings",
			"ApplicationCore",
			"Renderer", // UE 5.5 rendering features
			"MeshDescription", // UE 5.5 mesh handling
			"StaticMeshDescription", // UE 5.5 static mesh
			"SkeletalMeshDescription" // UE 5.5 skeletal mesh
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
			UndefinedIdentifierWarningLevel = WarningLevel.Off;
		}
		
		// UE 5.5 World Partition support
		if (Target.bBuildEditor)
		{
			PrivateDependencyModuleNames.Add("WorldPartitionEditor");
		}
	}
}
