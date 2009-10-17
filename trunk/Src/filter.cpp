#include "filter.h"

Filter::Filter()
{
    this->min = 32000;
    this->max = -32000;
}

Filter::~Filter()
{
}

OsteoporosisImage* Filter::apply(OsteoporosisImage* image)
{
    OsteoporosisImage* filteredImage;
    Matrix* aux;
    aux = getPonderationMatrix(image);
    filteredImage = normalize(aux);

    return filteredImage;
}

Matrix* Filter::getPonderationMatrix(OsteoporosisImage *image)
{
    Matrix* aux = new Matrix(image->getHeight()-2,image->getWidth()-2);

    for (int j=1; j < image->getWidth()-1; j++)
        for(int i=1; i < image->getHeight()-1; i++)
            aux->set(i-1,j-1,getPonderation(i,j,image));

    return aux;
}

int Filter::getPonderation(int i, int j, OsteoporosisImage* image)
{
    float colorTotal = 0.0f;
    float colormax = 0.0f;

    for(int k = 0; k < mask.size(); k++)
    {
        float color = 0.0f;
        for (int y = -1; y < 2; y++)
            for(int x = -1; x < 2; x++)
            {
                float pixelColor = image->getColorAt(x+j,y+i);
                if (pixelColor >= 0)
                    color += mask.at(k)->at(x+1,y+1) * pixelColor;
            }
        colormax += abs(color);
    }

    colorTotal = abs(colormax);

    if (colorTotal < 0) colorTotal = 0;
    if (colorTotal > 255) colorTotal = 255;

    if (this->max < colorTotal) this->max = colorTotal;
    if (this->min > colorTotal) this->min = colorTotal;

    return colorTotal;
}

OsteoporosisImage* Filter::normalize(Matrix *values)
{
    OsteoporosisImage* image = new OsteoporosisImage(QSize(values->getColumns(),values->getRows()));

    for (int j=0; j < image->getHeight(); j++)
        for(int i=0; i < image->getWidth(); i++)
        {
            float color = values->at(j,i);
            color = (((color - this->min)/(this->max - this->min))*255);
            image->setColorAt(i,j,color);
        }

    return image;
}
