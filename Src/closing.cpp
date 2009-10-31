#include "closing.h"

#include "dilatation.h"
#include "conditionalerosion.h"

Closing::Closing() : CombinedTransformations(new Dilatation(), new ConditionalErosion())
{
}
