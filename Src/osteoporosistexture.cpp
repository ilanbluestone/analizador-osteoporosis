#include "osteoporosistexture.h"
#include "math.h"

OsteoporosisTexture::OsteoporosisTexture(OsteoporosisImage* i)
{
        image=i;
}

void OsteoporosisTexture::binarize()
{
    binarizeImage=new OsteoporosisImage(this->image->getSize());
    int gray=this->grayAverage();
    for (int i=0; i<this->image->getWidth();i++)
        for(int j=0; j<this->image->getHeight();i++)
            if (this->image->getColorAt(i,j)< gray)
                binarizeImage->setColorAt(i,j,0);
            else
                binarizeImage->setColorAt(i,j,1);
}

float OsteoporosisTexture::calculateCosHor(int i)
{
    float result=0;
    for (int j=0;j<this->binarizeImage->getWidth();j++)
        result+=this->binarizeImage->getColorAt(i,j);
    return (result/(sqrt(result)*sqrt(this->image->getWidth())));
}

float OsteoporosisTexture::calculateCosVer(int j)
{
    float result=0;
    for (int i=0;j<this->binarizeImage->getHeight();i++)
        result+=this->binarizeImage->getColorAt(i,j);
    return (result/(sqrt(result)*sqrt(this->image->getWidth())));
}

float OsteoporosisTexture::cosAverage(QVector<float> a)
{
    float result=0;
    for (int i=0; i< a.size();i++)
        result+=a.at(i);
    return (result/a.size());
}

void OsteoporosisTexture::createHorArray()
{
    for (int i=0;i<this->image->getHeight();i++)
        this->horizontal.push_front(this->calculateCosHor(i));
}

void OsteoporosisTexture::createVerArray()
{
      for (int j=0;j<this->image->getWidth();j++)
        this->vertical.push_front(calculateCosVer(j));
}

float OsteoporosisTexture::grayAverage()
{
    float result=0;
    for(int i=0; i<this->image->getWidth();i++)
        for (int j=0; j<this->image->getHeight();j++)
            result+=this->image->getColorAt(i,j);
    return (result/(this->image->getWidth()*this->image->getHeight()));
}

float OsteoporosisTexture::indexCalculate()
{
    this->binarize();
    this->createHorArray();
    this->createVerArray();
    return ((this->cosAverage(this->horizontal) + this->cosAverage(this->vertical))/2);
}
