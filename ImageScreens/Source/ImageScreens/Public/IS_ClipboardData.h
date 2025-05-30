#pragma once

#include "CoreMinimal.h"
#include "FGFactoryClipboard.h"
#include "IS_AspectRatio.h"
#include "IS_ImageScreenSpec.h"
#include "IS_ClipboardData.generated.h"

/**
 * Clipboard data containing information about an existing image screen.
 */
UCLASS( BlueprintType )
class IMAGESCREENS_API UIS_ClipboardData : public UFGFactoryClipboardSettings
{
	GENERATED_BODY()

public:

	/**
	 * Aspect ratio of the screen that we copied from.
	 */
	UPROPERTY( BlueprintReadWrite, Meta = ( ExposeOnSpawn = "true" ) )
	EIS_AspectRatio AspectRatio = EIS_AspectRatio::Unknown;

	/**
	 * Specification data about what to display on the screen.
	 */
	UPROPERTY( BlueprintReadWrite, Meta = ( ExposeOnSpawn = "true" ) )
	FIS_ImageScreenSpec Spec;

}; // class UIS_ClipboardData
