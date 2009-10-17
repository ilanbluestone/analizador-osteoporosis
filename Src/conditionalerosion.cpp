#include "conditionalerosion.h"

ConditionalErosion::ConditionalErosion()
{
}

OsteoporosisImage* ConditionalErosion::apply(OsteoporosisImage* image)
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
            if ((min != image->getColorAt(x,y)) && (condition(x,y,image)))
                resul->setColorAt(x,y,min);
            else
                resul->setColorAt(x,y,image->getColorAt(x,y));
        }
    return resul;
}

bool ConditionalErosion::condition(int x, int y, OsteoporosisImage* image)
{
    bool A,B,C,D,E,F,G,H,M;
    M = image->getColorAt(x,y);
    A = image->getColorAt(x-1,y);
    B = image->getColorAt(x+1,y);
    C = image->getColorAt(x,y-1);
    D = image->getColorAt(x,y+1);
    E = image->getColorAt(x-1,y-1);
    F = image->getColorAt(x+1,y-1);
    G = image->getColorAt(x-1,y+1);
    H = image->getColorAt(x+1,y+1);

    return  ((A && B && !G && !D && !H)
            || (A && B && !E && !F && !C)
            || (C && D && !F && !B && !H)
            || (C && D && !E && !A && !G)
            || (C && B && !F)
            || (C && A && !E)
            || (D && A && !G)
            || (B && D && !H)
            || (G && D && C && !A && !E && !F && !B && !H)
            || (E && D && C && !A && !G && !F && !B && !H)
            || (G && A && B && !D && !E && !F && !C && !H)
            || (E && A && B && !C && !D && !F && !G && !H)
            || (H && D && C && !A && !E && !F && !B && !G)
            || (H && B && A && !C && !E && !F && !D && !G)
            || (F && B && A && !C && !E && !H && !D && !G)
            || (F && D && C && !A && !E && !G && !B && !H)
            );
}
