#include "umbral.h"

Umbral::Umbral(int value)
{
    this->value = value;
}

void Umbral::setUmbral(int value)
{
    this->value = value;
}

int Umbral::getUmbral()
{
    return this->value;
}

OsteoporosisImage* Umbral::apply(OsteoporosisImage* image)
{
    OsteoporosisImage* result = new OsteoporosisImage(image->getSize());
    for (int c = 0; c < image->getWidth(); c++)
        for (int f = 0; f < image->getHeight(); f++)
            if (image->getColorAt(c,f) <= this->value)
                result->setColorAt(c,f,0);
            else
                result->setColorAt(c,f,255);
    return result;
}
