#ifndef EROSION_H
#define EROSION_H

#include "transformation.h"

class Erosion : public Transformation
{
public:
    Erosion();

    class OsteoporosisImage* apply(class OsteoporosisImage* image);
};

#endif // EROSION_H
