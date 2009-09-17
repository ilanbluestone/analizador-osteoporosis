#ifndef EDGETHINNING_H
#define EDGETHINNING_H

#include "transformation.h"

class EdgeThinning : public Transformation
{
public:
    EdgeThinning();
    virtual class OsteoporosisImage* apply(class OsteoporosisImage* image) = 0;

protected:
    int* vecinos;
    OsteoporosisImage* image;
    int vecindad8(int x, int y);
    int vecindad4(int x, int y);
    int trancisiones01(int x, int y);
    void inicVecinos(int x, int y);
};

#endif // EDGETHINNING_H
