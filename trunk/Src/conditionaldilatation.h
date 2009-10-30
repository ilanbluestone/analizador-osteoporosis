#ifndef CONDITIONALDILATATION_H
#define CONDITIONALDILATATION_H

#include "neighborhood.h"

class ConditionalDilatation : public Neighborhood
{
public:
    ConditionalDilatation();

    class OsteoporosisImage* apply(class OsteoporosisImage* image);
};

#endif // CONDITIONALDILATATION_H
