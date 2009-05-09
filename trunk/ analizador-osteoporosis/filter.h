#ifndef FILTER_H
#define FILTER_H

#include "osteoporosisimage.h"

class Filter
{
private:
    int window[3][3];
    int windowSize;

public:
    Filter();

   void aplicar(OsteoporosisImage* image);
};

#endif // FILTER_H
