#include "filter.h"

#include <QDate>
#include <QDebug>

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
    aux= getPonderationMatrix(image);
    filteredImage = normalize(aux);
    return filteredImage;
}


Matrix* Filter::getPonderationMatrix(OsteoporosisImage *image)
{
    int minc=image->getColorMin();
    int maxc=image->getColorMax();
    int media= image->getMedia();

    Matrix* aux = new Matrix(image->getHeight(),image->getWidth());
    for (int j=1; j< image->getWidth()-1;j++)
        for(int i=1; i<image->getHeight()-1;i++)
             aux->set(i,j,this->getPonderation(i,j,image,minc,maxc,media));
    return aux;
}

int Filter::getPonderation(int i, int j, OsteoporosisImage* image,int minc,int maxc, int media)
{
    int color = 0;
    int colorTotal = 0;
    for(int k=0;k<mask.size();k++)
    {
        for (int y= -1; y < 2; y++)
            for(int x= -1; x < 2; x++)
                //color = color + mask.at(k)->at(x+1,y+1) * qGray(image->getPixelColorAt(x+j,y+i));
                color = color +mask.at(k)->at(x+1,y+1) * image->getColorAt(x+j,y+i);
        colorTotal+=color;
    }
    //con esto se logra que la imgen quede en negros y blancos en vez de utilizar escala de grises
    /*if (colorTotal < 0)
        colorTotal=0;
    else
         if (colorTotal > 255)
             colorTotal=255;
        else
            if (colorTotal < media)
                colorTotal=100;
             else
                if (colorTotal > media)
                    colorTotal=170;
    */

    if (this->max < colorTotal) this->max = colorTotal;
    if (this->min > colorTotal) this->min = colorTotal;
    return colorTotal;
}

OsteoporosisImage* Filter::normalize(Matrix *values)
{
    OsteoporosisImage* image = new OsteoporosisImage(QSize(values->getColumns(),values->getRows()));
    for (int j=1; j< image->getHeight()-1;j++)
        for(int i=1; i<image->getWidth()-1;i++)
        {
            float color = values->at(j,i);
            color = (((color - this->min)/(this->max - this->min))*255);
            image->setColorAt(i,j,color);
        }
    return image;
}
