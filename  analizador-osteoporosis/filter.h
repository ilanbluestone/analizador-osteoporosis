#ifndef FILTER_H
#define FILTER_H

#include "transformation.h"

class Filter : public Transformation
{
private:
    int *window;

public:
    Filter();
};

#endif // FILTER_H
