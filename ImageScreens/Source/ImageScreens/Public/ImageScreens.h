// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"


// Declare the log category, using the mod reference, i.e. shared with the blueprint logging helpers.
DECLARE_LOG_CATEGORY_EXTERN( LogImageScreens, Verbose, All );


class FImageScreensModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
