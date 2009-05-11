#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include "osteoporosisimage.h"

class Transformation
{
public:
    Transformation();

    virtual class OsteoporosisImage * aplicar(class OsteoporosisImage * image) = 0;
};

#endif // TRANSFORMATION_H
