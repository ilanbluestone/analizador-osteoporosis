#include "opening.h"

#include "conditionaldilatation.h"
#include "erosion.h"

Opening::Opening() : CombinedTransformations(new Erosion(), new ConditionalDilatation())
{
}
