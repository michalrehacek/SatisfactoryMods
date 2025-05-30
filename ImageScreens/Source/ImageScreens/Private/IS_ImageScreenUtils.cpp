#include "IS_ImageScreenUtils.h"


/**
 * Is the specified URL valid, i.e. is this even an URL?
 */
bool UIS_ImageScreenUtils::IsValidURL( const FString & URL )
{
	return
		URL.StartsWith( TEXT( "http:" ) ) ||
		URL.StartsWith( TEXT( "https:" ) );
}


/**
 * Does the specified URL contain a text file?
 */
bool UIS_ImageScreenUtils::IsTextURL( const FString & URL )
{
	return
		IsValidURL( URL ) &&
		URL.EndsWith( TEXT( ".txt" ), ESearchCase::IgnoreCase );
}


/**
 * Does the specified screen specification refer to a text file?
 */
bool UIS_ImageScreenUtils::IsTextSpec( const FIS_ImageScreenSpec & Spec )
{
	return IsTextURL( Spec.URL );
}


/**
 * Does the specified URL contain an image file?
 *
 * A non-empty URL that isn't Text URL is considered to be an image by default.
 */
bool UIS_ImageScreenUtils::IsImageURL( const FString & URL )
{
	return
		IsValidURL( URL ) &&
		! IsTextURL( URL );
}


/**
 * Does the specified screen specification refer to an image file?
 *
 * A non-empty URL that isn't Text URL is considered to be an image by default.
 */
bool UIS_ImageScreenUtils::IsImageSpec( const FIS_ImageScreenSpec & Spec )
{
	return IsImageURL( Spec.URL );
}


/**
* Reset the structure to clean all previous data.
*/
void UIS_ImageScreenUtils::ResetJoinData( FIS_JoinData & JoinData )
{
	JoinData.ServerError = FText::GetEmpty();
	JoinData.CurrentSlideshowURL.Empty();
}


/**
 * Return the net mode the world is running in.
 */
ENetMode UIS_ImageScreenUtils::GetNetMode( AActor * WorldContextObject )
{
	return WorldContextObject->GetNetMode();
}


/**
 * Return debug-mode textual representation of the net mode.
 *
 * The function should only be used for logging, not for displaying the text to the user.
 * The returned text is not localizable.
 */
FString UIS_ImageScreenUtils::GetNetModeString( AActor * WorldContextObject )
{
	ENetMode mode = GetNetMode( WorldContextObject );
	switch ( mode )
	{
		case NM_DedicatedServer:	return TEXT( "NM_DedicatedServer" );
		case NM_Standalone:			return TEXT( "NM_Standalone" );
		case NM_ListenServer:		return TEXT( "NM_ListenServer" );
		case NM_Client:				return TEXT( "NM_Client" );
		default:					return TEXT( "Invalid ENetMode" );
	}
}


/**
* Is the game running on a machine which has a local player that can see what's happening?
*/
bool UIS_ImageScreenUtils::HasRendering( AActor * WorldContextObject )
{
	ENetMode mode = GetNetMode( WorldContextObject );
	switch ( mode )
	{
		case NM_DedicatedServer:	// Dedicated server
		{
			return false;
		}
		case NM_Standalone:			// Singleplayer game
		case NM_ListenServer:		// Host in a MP game
		case NM_Client:				// Client in a MP game
		default:
		{
			return true;
		}
	}
}
