#pragma once

#include "CoreMinimal.h"
#include "IS_ReplaceRule.generated.h"

/**
 * Specification of a single replacement in an image URL.
 *
 * Each URL will have all occurrences of ReplaceFrom replaced with ReplaceTo.
 * The replacement is case sensitive.
 */
USTRUCT( BlueprintType )
struct IMAGESCREENS_API FIS_ReplaceRule
{
	GENERATED_BODY()

public:

	/**
	 * The source substring to replace.
	 */
	UPROPERTY( BlueprintReadWrite )
	FString ReplaceFrom;

	/**
	 * The substring to replace with.
	 */
	UPROPERTY( BlueprintReadWrite )
	FString ReplaceTo;

}; // class FIS_RReplaceRule
