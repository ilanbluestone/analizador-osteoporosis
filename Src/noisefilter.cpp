#include "noisefilter.h"

NoiseFilter::NoiseFilter()
{
}

OsteoporosisImage* NoiseFilter::apply(OsteoporosisImage* im)
{
    bool cambios = true;
    this->image = im->clone();
    OsteoporosisImage* imagebuf = im->clone();

    while (cambios)
    {
        cambios = false;
        for (int y=1; y < image->getHeight()-1; y++)
            for (int x=1; x < image->getWidth()-1; x++)
                if (image->getColorAt(x,y) == 255)
                    if ((this->vecindad8(x,y) <= 1)||((this->vecindad8(x,y) == 2 && this->trancisiones01(x,y)==1)))
                    {
                        imagebuf->setColorAt(x,y,0);
                        cambios = true;
                    }
        delete (this->image);
        this->image = imagebuf->clone();
    }
    return this->image;
}
