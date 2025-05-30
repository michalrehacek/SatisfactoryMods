#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "IS_SlideshowState.h"
#include "IS_SlideshowStateUtils.generated.h"

/**
 * Blueprint utilities for manipulating FSlideshowState.
 *
 * These functions are implemented in C++ because especially the NextImage
 * implementation would be very awkward in Blueprints.
 */
UCLASS()
class IMAGESCREENS_API UIS_SlideshowStateUtils : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION( BlueprintCallable, meta = ( ScriptMethod = "true", Category = "Image Screens", ReturnDisplayName = "State" ) )
	static void InitState( UPARAM( ref ) FIS_SlideshowState & State, const TArray< FString > & Images, bool Shuffle );

	UFUNCTION( BlueprintCallable, meta = ( ScriptMethod = "true", Category = "Image Screens", ReturnDisplayName = "State" ) )
	static void UpdateConfig( UPARAM( ref ) FIS_SlideshowState & State, bool Shuffle );

	UFUNCTION( BlueprintCallable, meta = ( ScriptMethod = "true", Category = "Image Screens", ReturnDisplayName = "State" ) )
	static void ResetState( UPARAM( ref ) FIS_SlideshowState & State );

	UFUNCTION( BlueprintCallable, meta = ( ScriptMethod = "true", Category = "Image Screens", ReturnDisplayName = "Image URL" ) )
	static FString NextImage( UPARAM( ref ) FIS_SlideshowState & State );

private:

	static void ShuffleImages( TArray< FString > & Array );

}; // class UIS_SlideshowStateUtils
