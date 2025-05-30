#include "IS_SlideshowStateUtils.h"


/**
 * Initialize the structure for a new slideshow with the specified images.
 */
void UIS_SlideshowStateUtils::InitState( FIS_SlideshowState & State, const TArray< FString > & Images, bool Shuffle )
{
	State.ImagesOriginal = Images;
	State.Images = Images;
	State.NextIndex = 0;
	State.Shuffle = Shuffle;
}


/**
 * Reset the structure to clean all previous data.
 */
void UIS_SlideshowStateUtils::ResetState( FIS_SlideshowState & State )
{
	State.Images.Empty();
	State.NextIndex = 0;
}


/**
 * Update the slideshow state structure after a configuration has changed.
 */
void UIS_SlideshowStateUtils::UpdateConfig( UPARAM( ref ) FIS_SlideshowState & State, bool Shuffle )
{
	// Change in the Shuffle flag?
	if ( State.Shuffle != Shuffle )
	{
		// If stopping shuffling, reset the Image array to use the original unshuffled images.
		if ( State.Shuffle )
		{
			State.Images = State.ImagesOriginal;
		}

		// Start the slideshow from the start, either to force a shuffle or to start in the original order.
		State.NextIndex = 0;

		// In any case, remember the new Shuffle flag.
		State.Shuffle = Shuffle;
	}
}


/**
 * Return the name of the image to show in the next tick.
 *
 * The State structure will be modified, and another call to NextImage will return a new image.
 */
FString UIS_SlideshowStateUtils::NextImage( UPARAM( ref ) FIS_SlideshowState & State )
{
	// If the next image is zero, we're starting a new run (or the very first run) through the whole array.
	// Shuffle the image list to get a random ordering.
	if ( State.Shuffle && ( State.NextIndex == 0 ) )
	{
		ShuffleImages( State.Images );
	}

	// Remember the name of the image to use now.
	FString Image = State.Images[ State.NextIndex ];

	// Advance the index.
	State.NextIndex++;
	if ( State.NextIndex >= State.Images.Num() )
	{
		State.NextIndex = 0;
	}

	// Return the image.
	return Image;
}


/**
 * Randomly shuffle elements in the array.
 *
 * Code inspired by UKismetArrayLibrary::GenericArray_Shuffle.
 */
void UIS_SlideshowStateUtils::ShuffleImages( TArray< FString > & Array )
{
	int32 LastIndex = Array.Num() - 1;
	for ( int32 i = 0; i <= LastIndex; i++ )
	{
		int32 Index = FMath::RandRange( i, LastIndex );
		if ( i != Index )
		{
			Array.Swap( i, Index );
		}
	}
}
