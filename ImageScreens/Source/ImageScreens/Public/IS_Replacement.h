#pragma once

#include "CoreMinimal.h"
#include "IS_ReplaceRule.h"
#include "IS_Replacement.generated.h"

/**
 *
 */
USTRUCT( BlueprintType )
struct IMAGESCREENS_API FIS_Replacement
{
	GENERATED_BODY()

public:

	/**
	 * List of all rules to process.
	 */
	UPROPERTY( BlueprintReadWrite )
	TArray< FIS_ReplaceRule > Rules;

}; // struct FIS_Replacement
