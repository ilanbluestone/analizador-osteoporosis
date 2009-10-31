#ifndef COMBINEDTRANSFORMATIONS_H
#define COMBINEDTRANSFORMATIONS_H

#include "transformation.h"

class CombinedTransformations : public Transformation
{
private:
    Transformation *t1;
    Transformation *t2;

public:
    CombinedTransformations(Transformation *first, Transformation *second);
    OsteoporosisImage *apply(OsteoporosisImage *image);
};

#endif // COMBINEDTRANSFORMATIONS_H
