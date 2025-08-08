// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class EternalDescentEditorTarget : TargetRules
{
	public EternalDescentEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_5;
		ExtraModuleNames.Add("EternalDescent");
		
		// Enable faster compile times for development (UE 5.5 compatible)
		bUseFastPDBLinking = true;
		
		// Enable hot reload for development
		bAllowHotReload = true;
		
		// Enable automation tests
		bWithLiveCoding = true;
		
		// Enable additional debugging features
		bBuildWithEditorOnlyData = true;
	}
}
