#pragma once


#include "CoreMinimal.h"
#include "Engine/EngineBaseTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "IS_ImageScreenSpec.h"
#include "IS_ReplaceRule.h"
#include "IS_Replacement.h"
#include "IS_JoinData.h"
#include "IS_ImageScreenUtils.generated.h"


/**
 * Utility functions for Image Screen blueprints.
 */
UCLASS()
class IMAGESCREENS_API UIS_ImageScreenUtils : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	// Helpers for working with URLs

	UFUNCTION( BlueprintPure, meta = ( Category = "Image Screens", ReturnDisplayName = "Is Valid" ) )
	static bool IsValidURL( const FString & URL );

	UFUNCTION( BlueprintPure, meta = ( Category = "Image Screens", ReturnDisplayName = "Is Text URL" ) )
	static bool IsTextURL( const FString & URL );

	UFUNCTION( BlueprintPure, meta = ( Category = "Image Screens", ReturnDisplayName = "Is Text Spec" ) )
	static bool IsTextSpec( const FIS_ImageScreenSpec & Spec );

	UFUNCTION( BlueprintPure, meta = ( Category = "Image Screens", ReturnDisplayName = "Is Image URL" ) )
	static bool IsImageURL( const FString & URL );

	UFUNCTION( BlueprintPure, meta = ( Category = "Image Screens", ReturnDisplayName = "Is Image Spec" ) )
	static bool IsImageSpec( const FIS_ImageScreenSpec & Spec );

	// Helpers for processing URL replacements

	UFUNCTION( BlueprintPure, meta = ( Category = "Image Screens", ReturnDisplayName = "Parsed Replacements" ) )
	static FIS_Replacement ParseReplacement( const FString & Text );

	static bool ApplyReplaceRule( const FIS_ReplaceRule & Rule, FIS_ImageScreenSpec & Spec );

	UFUNCTION( BlueprintCallable, meta = ( Category = "Image Screens", ReturnDisplayName = "Spec Changed" ) )
	static bool ApplyReplacement( const FIS_Replacement & Replacement, UPARAM( ref ) FIS_ImageScreenSpec & Spec );

	// Join data helpers

	UFUNCTION( BlueprintCallable, meta = ( ScriptMethod = "true", Category = "Image Screens", ReturnDisplayName = "JoinData" ) )
	static void ResetJoinData( UPARAM( ref ) FIS_JoinData & JoinData );

	// Networking and DS helpers

	static ENetMode GetNetMode( AActor * WorldContextObject );

	UFUNCTION( BlueprintPure, meta = ( Category = "Image Screens", ReturnDisplayName = "Net Mode", WorldContext = "WorldContextObject" ) )
	static FString GetNetModeString( AActor * WorldContextObject );

	UFUNCTION( BlueprintPure, meta = ( Category = "Image Screens", ReturnDisplayName = "Rendering", WorldContext = "WorldContextObject" ) )
	static bool HasRendering( AActor * WorldContextObject );

}; // class UIS_ImageScreenUtils
