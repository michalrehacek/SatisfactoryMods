#include "ImageScreens.h"


#define LOCTEXT_NAMESPACE "ImageScreens"


// Define the log category for the module.
DEFINE_LOG_CATEGORY( LogImageScreens );


/**
 * Module startup callback.
 */
void FImageScreensModule::StartupModule()
{
	UE_LOG( LogImageScreens, Verbose, TEXT( "StartupModule" ) );
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}


/**
 * Module shutdown callback.
 */
void FImageScreensModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}


#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE( FImageScreensModule, ImageScreens )
