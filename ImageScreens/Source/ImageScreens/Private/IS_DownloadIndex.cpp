#include "IS_DownloadIndex.h"
#include "Runtime/Online/HTTP/Public/HttpModule.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"


/**
 * Construct the async Blueprint action object.
 */
UImageScreens_DownloadIndex * UImageScreens_DownloadIndex::AsyncDownloadIndex( UObject * WorldContextObject, FString URL )
{
	// Create and initialize instance.
	UImageScreens_DownloadIndex * Action = NewObject< UImageScreens_DownloadIndex >();
	Action->URL = URL;

	// The action is async, so we need to keep a reference to it until the async request is complete.
	// We will call SetReadyToDestroy in the completion handler.
	Action->RegisterWithGameInstance( WorldContextObject );
	return Action;
}


/**
 * Activate the blueprint action.
 */
void UImageScreens_DownloadIndex::Activate()
{
	// Create and set up the HTTP request.
	TSharedRef< IHttpRequest, ESPMode::ThreadSafe > Request = FHttpModule::Get().CreateRequest();
	Request->SetVerb( "GET" );
	Request->SetURL( URL );

	// Set up the completion callback.
	Request->OnProcessRequestComplete().BindLambda(
		[this] ( FHttpRequestPtr Request, FHttpResponsePtr Response, bool Success )
		{
			this->RequestCompleted( Response, Success );
			this->SetReadyToDestroy();
		} );

	// Start processing the request.
	Request->ProcessRequest();
}


/**
 * Handle the response from the HTTP server.
 *
 * This will trigger either the OnFailure or OnSuccess callback.
 */
void UImageScreens_DownloadIndex::RequestCompleted( FHttpResponsePtr Response, bool Success )
{
	// If we failed, just fire the failure callback and m
	if ( ! Success )
	{
		UE_LOG( LogImageScreens, Verbose, TEXT( "Slideshow index download error: HTTP request failed" ) );
		InvokeOnFailure();
		return;
	}

	// We expect 2xx response codes.
	int Code = Response->GetResponseCode();
	if ( ( Code < 200 ) || ( Code > 299 ) )
	{
		UE_LOG( LogImageScreens, Verbose, TEXT( "Slideshow index download error: Response code is %d" ), Code );
		InvokeOnFailure();
		return;
	}

	// If the content type isn't text, don't parse the response.
	FString ContentType = Response->GetContentType();
	if ( ! ContentType.StartsWith( "text/" ) )
	{
		UE_LOG( LogImageScreens, Verbose, TEXT( "Slideshow index download error: ContentType of response is %s" ), *ContentType );
		InvokeOnFailure();
		return;
	}

	// Retrieve the string response and split it into lines.
	FString Text = Response->GetContentAsString();
	TArray< FString > Lines;
	Text.ParseIntoArrayLines( Lines );

	// If the index is empty, there's no slideshow.
	if ( Lines.IsEmpty() )
	{
		UE_LOG( LogImageScreens, Verbose, TEXT( "Slideshow index download error: index file is empty" ) );
		InvokeOnFailure();
		return;
	}

	// Find the prefix of the URL, so that we can build an URL relative to the path where the index file was from.
	FString URLPrefix = GetURLPrefix();

	// Process each line.
	int Count = Lines.Num();
	for ( int i = 0; i < Count; i++ )
	{
		FString & Line = Lines[ i ];
		Line = URLPrefix + Line.TrimStartAndEnd();
	}

	// Trigger the success callback.
	UE_LOG( LogImageScreens, Verbose, TEXT( "Slideshow index download success, got %d files" ), Count );
	InvokeOnSuccess( Lines );
}


/**
 * Return the prefix of the URL path, i.e. the directory that the index file was downloaded from.
 */
FString UImageScreens_DownloadIndex::GetURLPrefix( void ) const
{
	int LastSlash;
	if ( URL.FindLastChar( '/', LastSlash ) )
	{
		// Get the string up to and including the last slash.
		return URL.Left( LastSlash + 1 );
	}
	else
	{
		// No slash found in the URL, which is a really weird URL.
		// Just return the original URL with a slash, to make it look like a directory...
		return URL + "/";
	}
}


/**
 * Invole the OnSuccess callback.
 */
void UImageScreens_DownloadIndex::InvokeOnSuccess( const TArray< FString > & Images )
{
	if ( OnSuccess.IsBound() )
	{
		OnSuccess.Broadcast( Images );
	}
}


/**
 * Invoke the OnFailure callback.
 */
void UImageScreens_DownloadIndex::InvokeOnFailure( void )
{
	if ( OnFailure.IsBound() )
	{
		OnFailure.Broadcast();
	}
}
