#ifndef DILATATION_H
#define DILATATION_H

#include "transformation.h"

class Dilatation : public Transformation
{
public:
    Dilatation();

    class OsteoporosisImage* apply(class OsteoporosisImage* image);
};

#endif // DILATATION_H
