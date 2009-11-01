#include "holefinder.h"
#include "dilatation.h"

HoleFinder::HoleFinder()
{
}

OsteoporosisImage* HoleFinder::apply(OsteoporosisImage* image)
{
    OsteoporosisImage* background = image->clone();

    for (int y = 0; y < image->getHeight(); y++)
    {
        bool border = false;
        for (int x = 0; x < image->getWidth() and !border; x++)
            if (image->getColorAt(x,y) == 0)
                background->setColorAt(x,y,128);
            else
                border = true;
    }

    for (int x = 0; x < image->getWidth(); x++)
    {
        bool border = false;
        for (int y = 0; y < image->getHeight() and !border; y++)
            if (image->getColorAt(x,y) == 0)
                background->setColorAt(x,y,128);
            else
                border = true;
    }

    for (int y = image->getHeight()-1; y >= 0 ; y--)
    {
        bool border = false;
        for (int x = image->getWidth()-1; x >= 0  and !border; x--)
            if (image->getColorAt(x,y) == 0)
                background->setColorAt(x,y,128);
            else
                border = true;
    }

    for (int x = image->getWidth()-1; x >= 0; x--)
    {
        bool border = false;
        for (int y = image->getHeight()-1; y >= 0  and !border; y--)
            if (image->getColorAt(x,y) == 0)
                background->setColorAt(x,y,128);
            else
                border = true;
    }

    // refinado...

    for (int y = 0; y < image->getHeight()-1; y++)
    {
        for (int x = 0; x < image->getWidth()-1; x++)
            if (background->getColorAt(x,y) == 128)
            {
                if (background->getColorAt(x-1,y) == 0) background->setColorAt(x-1,y,128);
                if (background->getColorAt(x,y-1) == 0) background->setColorAt(x,y-1,128);
                if (background->getColorAt(x+1,y) == 0) background->setColorAt(x+1,y,128);
                if (background->getColorAt(x,y+1) == 0) background->setColorAt(x,y+1,128);
            }
    }

    for (int y = image->getHeight()-1; y > 0 ; y--)
    {
        for (int x = image->getWidth()-1; x > 0; x--)
            if (background->getColorAt(x,y) == 128)
            {
                if (background->getColorAt(x-1,y) == 0) background->setColorAt(x-1,y,128);
                if (background->getColorAt(x,y-1) == 0) background->setColorAt(x,y-1,128);
                if (background->getColorAt(x+1,y) == 0) background->setColorAt(x+1,y,128);
                if (background->getColorAt(x,y+1) == 0) background->setColorAt(x,y+1,128);
            }
    }

    for (int y = 0; y < image->getHeight()-1; y++)
    {
        for (int x = image->getWidth()-1; x > 0; x--)
            if (background->getColorAt(x,y) == 128)
            {
                if (background->getColorAt(x-1,y) == 0) background->setColorAt(x-1,y,128);
                if (background->getColorAt(x,y-1) == 0) background->setColorAt(x,y-1,128);
                if (background->getColorAt(x+1,y) == 0) background->setColorAt(x+1,y,128);
                if (background->getColorAt(x,y+1) == 0) background->setColorAt(x,y+1,128);
            }
    }

    for (int y = image->getHeight()-1; y > 0 ; y--)
    {
        for (int x = 0; x < image->getWidth()-1; x++)
            if (background->getColorAt(x,y) == 128)
            {
                if (background->getColorAt(x-1,y) == 0) background->setColorAt(x-1,y,128);
                if (background->getColorAt(x,y-1) == 0) background->setColorAt(x,y-1,128);
                if (background->getColorAt(x+1,y) == 0) background->setColorAt(x+1,y,128);
                if (background->getColorAt(x,y+1) == 0) background->setColorAt(x,y+1,128);
            }
    }

    for (int x = 0; x < image->getWidth(); x++)
        for (int y = 0; y < image->getHeight(); y++)
            if (background->getColorAt(x,y) == 128)
                background->setColorAt(x,y,0);
            else
                background->setColorAt(x,y,255);

    return background;
}
