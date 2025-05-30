#pragma once

#include "CoreMinimal.h"
#include "IS_ImageScreenSpec.generated.h"


/**
 * Parameters defining what the user wants to be shown on a screen and how.
 *
 * This is the data that is persisted for existing screen objects.
 * More detailed state, in particular errors and progress inside a slideshow,
 * is not persisted in saves.
 */
USTRUCT( BlueprintType )
struct IMAGESCREENS_API FIS_ImageScreenSpec
{
	GENERATED_BODY()

public:

	/**
	 * URL to download from.
	 *
	 * This can be either an image or an index text file.
	 */
	UPROPERTY( BlueprintReadWrite, EditAnywhere, SaveGame )
	FString URL;

}; // class FIS_ImageScreenSpec
