#include "hilditch.h"

Hilditch::Hilditch()
{
}

OsteoporosisImage* Hilditch::apply(OsteoporosisImage* im)
{
    bool changes = true;
    this->image = im->clone();
    OsteoporosisImage* imagebuf = im->clone();

    while (changes)
    {
        changes = false;
        for (int y=0; y < image->getHeight(); y++)
            for (int x=0; x < image->getWidth(); x++)
                if (image->getColorAt(x,y) != 0)
                    if (((this->neighborhood8(x,y) >= 2) && (this->neighborhood8(x,y) <= 6)))
                        if ((this->trancitions01(x,y) == 1))
                        {
                            int cond = image->getColorAt(x,y-1);
                            cond += image->getColorAt(x+1,y);
                            cond += image->getColorAt(x-1,y);
                            if (((cond <=510) || (this->trancitions01(x,y-1) != 1)))
                            {
                                cond = image->getColorAt(x,y-1);
                                cond += image->getColorAt(x+1,y);
                                cond += image->getColorAt(x,y+1);
                                if (((cond <=510) || (this->trancitions01(x+1,y) != 1)))
                                {
                                    imagebuf->setColorAt(x,y,0);
                                    changes = true;
                                }
                            }
                        }
        delete (this->image);
        this->image = imagebuf->clone();
    }
    return this->image;
}
