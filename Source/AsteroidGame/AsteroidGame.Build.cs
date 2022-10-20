// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AsteroidGame : ModuleRules
{
	public AsteroidGame(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] 
		{ 
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore",
			"UMG",
			"Niagara",
			"GameplayTasks",
			"NavigationSystem"
		});

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		PublicIncludePaths.AddRange(new string[] {
			"AsteroidGame/Public/Player",
			"AsteroidGame/Public/Components",
			"AsteroidGame/Public/Asteroid",
			"AsteroidGame/Public/ShipWeapon",
			"AsteroidGame/Public/UI",
			"AsteroidGame/Public/UI/PlayerHUD",
			"AsteroidGame/Public/UI/ButtonsWidgets",
			"AsteroidGame/Public/UI/Menu",
			"AsteroidGame/Public/UI/Menu/UI",
			"AsteroidGame/Public/UI/Pause",
			"AsteroidGame/Public/AI",
			"AsteroidGame/Public/AI/Decorators",
			"AsteroidGame/Public/AI/EQS",
			"AsteroidGame/Public/AI/Services",
			"AsteroidGame/Public/AI/Task"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
