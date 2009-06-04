#ifndef PREWITTFILTER_H
#define PREWITTFILTER_H
#include "filter.h"

/*
#include "northeastfilter.h"
#include "northfilter.h"
#include "eastfilter.h"                               todo esto es y sera una prueba
#include "westfilter.h"
#include "southfilter.h"
#include "southwestfilter.h"
#include "southeastfilter.h"
#include "northwestfilter.h"
  */

class PrewittFilter :public Filter//public NorthEastFilter, public NorthFilter, public NorthWestFilter, public SouthEastFilter, public SouthFilter, public SouthWestFilter, public EastFilter, public WestFilter
{
public:
    PrewittFilter();

};

#endif // PREWITTFILTER_H
