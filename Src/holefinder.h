#ifndef HOLEFINDER_H
#define HOLEFINDER_H

#include "transformation.h"

class HoleFinder : public Transformation
{
public:
    HoleFinder();

    class OsteoporosisImage* apply(class OsteoporosisImage* image);
};

#endif // HOLEFINDER_H
