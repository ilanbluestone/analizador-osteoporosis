#include "median.h"

MedianFilter::MedianFilter()
{
    this->values = new QVector<float>;
}

int MedianFilter::getPonderation(int i, int j, OsteoporosisImage* image)
{
    for (int y = -1; y < 2; y++)
        for (int x = -1; x < 2; x++)
        {
            float pixelColor = image->getColorAt(x+j,y+i);
            if (pixelColor >= 0)
            {
                if (this->values->size() == 0)
                    this->values->push_front(pixelColor);
                else
                {
                    int index;
                    for (index = 0; index < this->values->size() and this->values->at(index) < pixelColor; index++) ;
                    this->values->insert(index,pixelColor);
                }
            }
        }

    float color = this->values->at(this->values->size()/2);

    if (this->max < color) this->max = color;
    if (this->min > color) this->min = color;

    return color;
}
