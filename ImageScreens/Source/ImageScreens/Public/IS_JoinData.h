#pragma once

#include "CoreMinimal.h"
#include "IS_JoinData.generated.h"


/**
 * Extra state (related to the active slideshow, if any)
 * that a client needs when joining to a game in progress.
 *
 * This structure only contains data not present in the FIS_SlideshowState structure,
 * because that one is replicated in all cases.
 * The join data only contains transient data that is normally replicated using events.
 * This includes the last server-side error and the current image displayed by a running slideshow.
 */
USTRUCT( BlueprintType )
struct IMAGESCREENS_API FIS_JoinData
{
	GENERATED_BODY()

public:

	/**
	 * Server-side error.
	 */
	UPROPERTY( BlueprintReadWrite )
	FText ServerError;

	/**
	 * URL of the current slideshow image, if showing a slideshow.
	 */
	UPROPERTY( BlueprintReadWrite )
	FString CurrentSlideshowURL;

}; // class FIS_JoinData
