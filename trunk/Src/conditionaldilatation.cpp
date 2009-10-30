#include "conditionaldilatation.h"

ConditionalDilatation::ConditionalDilatation()
{
}

OsteoporosisImage* ConditionalDilatation::apply(OsteoporosisImage* image)
{
    this->image = image->clone();

    for (int x = 0; x < this->image->getWidth(); x++)
        for (int y = 0; y < this->image->getHeight(); y++)
            if (this->image->getColorAt(x,y) == 0)
                this->image->setColorAt(x,y,255);
            else
                this->image->setColorAt(x,y,0);

    OsteoporosisImage* resul = this->image->clone();

    for (int x = 1; x < this->image->getWidth()-1; x++)
        for (int y = 1; y < this->image->getHeight()-1; y++)
        {
            if (this->image->getColorAt(x,y) != 0)
                if (((this->neighborhood8(x,y) >= 2) && (this->neighborhood8(x,y) <= 6)))
                    if ((this->trancitions01(x,y) == 1))
                    {
                        int cond = this->image->getColorAt(x,y-1);
                        cond += this->image->getColorAt(x+1,y);
                        cond += this->image->getColorAt(x-1,y);
                        if (((cond <=510) || (this->trancitions01(x,y-1) != 1)))
                        {
                            cond = this->image->getColorAt(x,y-1);
                            cond += this->image->getColorAt(x+1,y);
                            cond += this->image->getColorAt(x,y+1);
                            if (((cond <=510) || (this->trancitions01(x+1,y) != 1)))
                            {
                                resul->setColorAt(x,y,0);
                            }
                        }
                    }
        }

    for (int x = 0; x < resul->getWidth(); x++)
        for (int y = 0; y < resul->getHeight(); y++)
            if (resul->getColorAt(x,y) == 0)
                resul->setColorAt(x,y,255);
            else
                resul->setColorAt(x,y,0);

    return resul;
}
