// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UE5Lab : ModuleRules
{
	public UE5Lab(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
