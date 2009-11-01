#include "noisefilter.h"

NoiseFilter::NoiseFilter()
{
}

OsteoporosisImage* NoiseFilter::apply(OsteoporosisImage* im)
{
    bool changes = true;
    this->image = im->clone();
    OsteoporosisImage* imagebuf = im->clone();

    while (changes)
    {
        changes = false;
        for (int y=3; y < image->getHeight()-4; y++)
            for (int x=3; x < image->getWidth()-4; x++)
                if (image->getColorAt(x,y) == 255)
                    if ((this->neighborhood8(x,y) <= 1)||((this->neighborhood8(x,y) == 2 && this->trancitions01(x,y)==1)))
                    {
                        imagebuf->setColorAt(x,y,0);
                        changes = true;
                    }
        delete (this->image);
        this->image = imagebuf->clone();
    }
    return this->image;
}
