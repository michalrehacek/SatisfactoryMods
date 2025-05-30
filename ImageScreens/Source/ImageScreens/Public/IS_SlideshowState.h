#pragma once

#include "CoreMinimal.h"
#include "IS_SlideshowState.generated.h"


/**
 * State of a running slideshow.
 *
 * The slideshow is ticked from Blueprint code.
 * This structure holds the state, including the list of images (downloaded from an index file)
 * and the progress in the slideshow.
 */
USTRUCT( BlueprintType )
struct IMAGESCREENS_API FIS_SlideshowState
{
	GENERATED_BODY()

public:
	/**
	 * List of all images that the slideshow is showing,
	 * in the original, unshuffled order.
	 *
	 * The property exists to be able to change the Shuffle configuration property
	 * from Shuffled to Unshuffled while a slideshow is running.
	 */
	UPROPERTY()
	TArray< FString > ImagesOriginal;

	/**
	 * List of all images that the slideshow is showing,
	 * in the order we're showing them.
	 */
	UPROPERTY()
	TArray< FString > Images;

	/**
	 * Index of the next image in the Images array that will be shown on the next tick.
	 */
	UPROPERTY()
	int NextIndex = 0;

	/**
	 * Should the order if images be shuffled?
	 */
	UPROPERTY()
	bool Shuffle = true;

}; // class FIS_SlideshowState
