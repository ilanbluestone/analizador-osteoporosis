#ifndef HILDITCH_H
#define HILDITCH_H

#include "neighborhood.h"

class Hilditch : public Neighborhood
{
public:
    Hilditch();
    class OsteoporosisImage* apply(class OsteoporosisImage* image);
};

#endif // HILDITCH_H
