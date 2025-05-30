#pragma once

#include "CoreMinimal.h"
#include "IS_AspectRatio.generated.h"


/**
 * Aspect ratio of an image screen
 */
UENUM( BlueprintType )
enum class EIS_AspectRatio : uint8
{
	Unknown			UMETA( DisplayName = "Unknown" ),
	Ratio_3_to_2	UMETA( DisplayName = "3:2" ),
	Ratio_2_to_3	UMETA( DisplayName = "2:3" ),
}; // enum class EIS_AspectRatio
