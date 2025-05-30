#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Interfaces/IHttpRequest.h"
#include "IS_DownloadIndex.generated.h"


/**
 * Callback invoked when the download completes succesfully.
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam( FOnDownloadIndexSuccess, const TArray< FString > &, Images );


/**
 * Callback invoked when the download fails.
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE( FOnDownloadIndexFailure );


/**
 * Async blueprint action that will download an index file from a specified URL.
 *
 * The index file contains names of images that will eventually be used for a slideshow in the screen.
 * This action will perform the HTTP request and will parse the response.
 * The output will be an array of URLs that blueprints can use.
 *
 * For safety reasons (i.e. not being able to spam HTTP requests to servers not provided by the player),
 * the text file needs to contain file names that will be taken relative to the server path
 * that the index itself is in.
 */
UCLASS()
class IMAGESCREENS_API UImageScreens_DownloadIndex : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:

	virtual void Activate() override;

	UFUNCTION( BlueprintCallable, meta = ( BlueprintInternalUseOnly = "true", DisplayName = "Download Index", Category = "Image Screens", WorldContext = "WorldContextObject" ) )
	static UImageScreens_DownloadIndex * AsyncDownloadIndex( UObject * WorldContextObject, FString URL );

public:

	/**
	 * Callback invoked when the download succeeds.
	 */
	UPROPERTY( BlueprintAssignable )
	FOnDownloadIndexSuccess OnSuccess;

	/**
	 * Callback invoked when the download fails.
	 */
	UPROPERTY( BlueprintAssignable )
	FOnDownloadIndexFailure OnFailure;

private:

	/**
	 * URL to download the index file from.
	 */
	FString URL;

private:

	void RequestCompleted( FHttpResponsePtr Response, bool Success );
	FString GetURLPrefix( void ) const;
	void InvokeOnSuccess( const TArray< FString > & Images );
	void InvokeOnFailure( void );

}; // class UImageScreens_DownloadIndex
