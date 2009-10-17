#ifndef HILDITCH_H
#define HILDITCH_H

#include "edgethinning.h"

class Hilditch : public EdgeThinning
{
public:
    Hilditch();
    class OsteoporosisImage* apply(class OsteoporosisImage* image);
};

#endif // HILDITCH_H
