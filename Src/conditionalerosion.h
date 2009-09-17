#ifndef CONDITIONALEROSION_H
#define CONDITIONALEROSION_H

#include "transformation.h"

class ConditionalErosion : public Transformation
{
public:
    ConditionalErosion();

    class OsteoporosisImage* apply(class OsteoporosisImage* image);
    bool condition(int x, int y, OsteoporosisImage* image);
};

#endif // CONDITIONALEROSION_H
