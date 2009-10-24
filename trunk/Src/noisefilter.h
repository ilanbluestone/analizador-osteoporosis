#ifndef NOISEFILTER_H
#define NOISEFILTER_H
#include "edgethinning.h"

class NoiseFilter : public EdgeThinning
{
public:
    NoiseFilter();
    class OsteoporosisImage* apply(class OsteoporosisImage* image);
};

#endif // NOISEFILTER_H
