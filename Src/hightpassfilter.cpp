#include "hightpassfilter.h"
#include "matrix.h"

HightPassFilter::HightPassFilter()
{
    int a = -1;
    int b = 9;
    Matrix *matrix = new Matrix(3,3);
    matrix->set(0,0,a);matrix->set(0,1,a);matrix->set(0,2,a);
    matrix->set(1,0,a);matrix->set(1,1,b);matrix->set(1,2,a);
    matrix->set(2,0,a);matrix->set(2,1,a);matrix->set(2,2,a);
    mask.push_back(matrix);
}

/*
OsteoporosisImage* HightPassFilter::apply(OsteoporosisImage* image)
{
    OsteoporosisImage* filteredImage;
    Matrix* aux;
    aux= getPonderationMatrix(image);
    filteredImage = normalize(aux);
    return filteredImage;
}

Matrix* HightPassFilter::getPonderationMatrix(OsteoporosisImage *image)
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

int HightPassFilter::getPonderation(int i, int j, OsteoporosisImage* image,int minc,int maxc, int media)
{
    int color = 0;
    int colorTotal = 0;
    for(int k=0;k<mask.size();k++)
    {
        for (int y= -1; y < 2; y++)
            for(int x= -1; x < 2; x++)
                //color = color + mask.at(k)->at(x+1,y+1) * qGray(image->getPixelColorAt(x+j,y+i));
                color = color + mask.at(k)->at(x+1,y+1) * image->getColorAt(x+j,y+i);
        colorTotal+=color;
    }


    if (max < colorTotal) max = colorTotal;
    if (min > colorTotal) min = colorTotal;
    return colorTotal;
}




*/

HightPassFilter::~HightPassFilter()
{
}
