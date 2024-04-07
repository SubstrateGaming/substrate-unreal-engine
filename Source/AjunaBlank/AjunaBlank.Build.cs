// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class AjunaBlank : ModuleRules
{
    public AjunaBlank(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

        PrivateDependencyModuleNames.AddRange(new string[] { "PolkadotSDK" });

        // Library exposed headers.
        //
        // Integrating Polkadot SDK requires providing an include path to the following libraries:
        // - wide-integer
        // - nlohmann/json
        //
        // TODO: Use default from module in example app.
        PublicSystemIncludePaths.AddRange(
            new string[]
            {
                Path.Combine("C:\\Users\\svnscha\\.conan2\\p\\wide-eff4dd222652b\\p\\include"),
                Path.Combine("C:\\Users\\svnscha\\.conan2\\p\\nlohm0567ffc90cfc1\\p\\include")
            });

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
}
