#ifndef NOISEFILTER_H
#define NOISEFILTER_H

#include "neighborhood.h"

class NoiseFilter : public Neighborhood
{
public:
    NoiseFilter();
    class OsteoporosisImage* apply(class OsteoporosisImage* image);
};

#endif // NOISEFILTER_H
