#include "hilditch.h"

Hilditch::Hilditch()
{
}

OsteoporosisImage* Hilditch::apply(OsteoporosisImage* im)
{
    bool cambios = true;
    this->image = im->clone();
    OsteoporosisImage* imagebuf = im->clone();

    while (cambios)
    {
        cambios = false;
        for (int y=0; y < image->getHeight(); y++)
            for (int x=0; x < image->getWidth(); x++)
                if (image->getColorAt(x,y) != 0)
                    if (((this->vecindad8(x,y) >= 2) && (this->vecindad8(x,y) <= 6)))
                        if ((this->trancisiones01(x,y) == 1))
                        {
                            int cond = image->getColorAt(x,y-1);
                            cond += image->getColorAt(x+1,y);
                            cond += image->getColorAt(x-1,y);
                            if (((cond <=510) || (this->trancisiones01(x,y-1) != 1)))
                            {
                                cond = image->getColorAt(x,y-1);
                                cond += image->getColorAt(x+1,y);
                                cond += image->getColorAt(x,y+1);
                                if (((cond <=510) || (this->trancisiones01(x+1,y) != 1)))
                                {
                                    imagebuf->setColorAt(x,y,0);
                                    cambios = true;
                                }
                            }
                        }
        delete (this->image);
        this->image = imagebuf->clone();
    }
    return this->image;
}
