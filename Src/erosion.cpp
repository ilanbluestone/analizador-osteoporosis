#include "erosion.h"

Erosion::Erosion()
{
}

OsteoporosisImage* Erosion::apply(OsteoporosisImage* image)
{
    OsteoporosisImage* resul = new OsteoporosisImage(image->getSize());
    int min;

    for (int x = 1; x < image->getWidth()-1; x++)
        for (int y = 1; y < image->getHeight()-1; y++)
        {
            min = 255;
            for (int f = -1; f < 2; f++)
                for (int c = -1; c < 2; c++)
                    if (image->getColorAt(x+c,y+f) < min)
                        min = image->getColorAt(x+c,y+f);
            resul->setColorAt(x,y,min);
        }
    return resul;
}
