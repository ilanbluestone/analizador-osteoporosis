#include "conditionalerosion.h"

ConditionalErosion::ConditionalErosion()
{
}

OsteoporosisImage* ConditionalErosion::apply(OsteoporosisImage* image)
{
    this->image = image->clone();
    OsteoporosisImage* resul = image->clone();

    for (int x = 1; x < image->getWidth()-1; x++)
        for (int y = 1; y < image->getHeight()-1; y++)
        {
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
                                resul->setColorAt(x,y,0);
                            }
                        }
                    }
        }

    return resul;
}
