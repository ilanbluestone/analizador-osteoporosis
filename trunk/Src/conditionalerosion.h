#ifndef CONDITIONALEROSION_H
#define CONDITIONALEROSION_H

#include "neighborhood.h"

class ConditionalErosion : public Neighborhood
{
public:
    ConditionalErosion();

    class OsteoporosisImage* apply(class OsteoporosisImage* image);
};

#endif // CONDITIONALEROSION_H
