#include "combinedtransformations.h"

CombinedTransformations::CombinedTransformations(Transformation *first, Transformation *second)
{
    this->t1 = first;
    this->t2 = second;
}

OsteoporosisImage* CombinedTransformations::apply(OsteoporosisImage *image)
{
    return this->t2->apply(this->t1->apply(image));
}
