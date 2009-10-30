#ifndef NEIGHBORHOOD_H
#define NEIGHBORHOOD_H

#include "transformation.h"

class Neighborhood : public Transformation
{
public:
    Neighborhood();
    virtual class OsteoporosisImage* apply(class OsteoporosisImage* image) = 0;

protected:
    OsteoporosisImage* image;
    int neighborhood8(int x, int y);
    int neighborhood4(int x, int y);
    int trancitions01(int x, int y);
};

#endif // NEIGHBORHOOD_H
