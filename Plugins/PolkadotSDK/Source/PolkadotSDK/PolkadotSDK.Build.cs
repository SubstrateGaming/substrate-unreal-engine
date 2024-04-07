// Copyright Epic Games, Inc. All Rights Reserved.

using System;
using System.IO;
using UnrealBuildTool;

public class PolkadotSDK : ModuleRules
{
    public PolkadotSDK(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core"
			});


        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
				"Projects"
			});


        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            // Tell the system that we are going to load this library.
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Windows-x64", "lib", "substrate.lib"));
            PublicDelayLoadDLLs.AddRange(new string[] { "substrate.dll" });

            // Deploy the library to the correct location.
            RuntimeDependencies.Add("$(PluginDir)/Binaries/Win64/substrate.dll", Path.Combine(ModuleDirectory, "Windows-x64", "lib", "substrate.dll"));

            // Library consumers need to include certain things.
            PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Windows-x64", "include"));
        }
        else if (Target.Platform == UnrealTargetPlatform.Mac)
        { 
            throw new NotImplementedException("Mac support for Polkadot SDK not yet implemented!");
        }
        else if (Target.Platform == UnrealTargetPlatform.Linux)
        {
            throw new NotImplementedException("Linux support for Polkadot SDK not yet implemented!");
        }
    }
}
