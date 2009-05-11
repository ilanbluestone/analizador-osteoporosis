#clase creada por nosotros.

#ifndef FILTER_H
#define FILTER_H

#include "transformation.h"

class Filter : public Transformation
{
private:
    int window[3][3];
    int windowSize;

public:
    Filter();

    //OsteoporosisImage * aplicar(OsteoporosisImage * image);
};

#endif // FILTER_H
