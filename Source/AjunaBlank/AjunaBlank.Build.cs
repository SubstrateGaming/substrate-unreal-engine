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
   }
}
