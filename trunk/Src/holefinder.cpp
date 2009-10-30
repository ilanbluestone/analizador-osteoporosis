#include "holefinder.h"
#include "dilatation.h"

HoleFinder::HoleFinder()
{
}

OsteoporosisImage* HoleFinder::apply(OsteoporosisImage* image)
{
    OsteoporosisImage* negative = image->clone();

    for (int x = 0; x < negative->getWidth(); x++)
        for (int y = 0; y < negative->getHeight(); y++)
            if (negative->getColorAt(x,y) == 255)
                negative->setColorAt(x,y,0);
            else
                negative->setColorAt(x,y,255);

    Dilatation d;
    OsteoporosisImage* borders = d.apply(image);

    for (int x = 0; x < borders->getWidth(); x++)
        for (int y = 0; y < borders->getHeight(); y++)
            if (image->getColorAt(x,y) == 255)
                borders->setColorAt(x,y,0);

    return borders;
}
