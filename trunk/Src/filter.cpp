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
    //OsteoporosisImage* resul = filteredImage->normalize(image->getColorMin(),image->getColorMax());//esto lo modiique yp

    return filteredImage;
}

/*
OsteoporosisImage* Filter::apply(OsteoporosisImage* image)
{
    Matrix* acum = new Matrix(image->getHeight(),image->getWidth());
    Matrix* aux;
    int maximo = 0;
    for(int k=0; k<mask.size(); k++)
    {
        int max = -32000;
        int min = 32000;
        aux = new Matrix(image->getHeight(),image->getWidth());
        for (int j=1; j< image->getWidth()-1;j++)
            for(int i=1; i<image->getHeight()-1;i++)
            {
                int color = 0;
                for (int y= -1; y < 2; y++)
                    for(int x= -1; x < 2; x++)
                        color = color +mask.at(k)->at(x+1,y+1) * image->getColorAt(x+j,y+i);
                aux->set(i,j,color);
                if (max < color) max = color;
                if (min > color) min = color;
            }
        float valorUmbral = min + (max - min) * 0.4; // aca se realiza el porcen de umbralado
        for (int j=1; j< image->getWidth()-1;j++)
            for(int i=1; i<image->getHeight()-1;i++)
            {
                if (aux->at(i,j) < valorUmbral)
                    aux->set(i,j,0);
                else
                    aux->set(i,j,1);
            }
        for (int j=1; j< image->getWidth()-1;j++)
            for(int i=1; i<image->getHeight()-1;i++)
            {
                int valor = (acum->at(i,j) + aux->at(i,j));
                acum->set(i,j,valor);
                if (maximo < valor) maximo = valor;
            }
    }

    OsteoporosisImage* resul = new OsteoporosisImage(image->getSize());
    for (int j=1; j< image->getWidth()-1;j++)
        for(int i=1; i<image->getHeight()-1;i++)
        {
            resul->setColorAt(i,j,acum->at(i,j)*255/maximo);
        }
    return resul;
}
*/

Matrix* Filter::getPonderationMatrix(OsteoporosisImage *image)
{
    minc=image->getColorMin();
    maxc=image->getColorMax();
    int media= image->getMedia();

    Matrix* aux = new Matrix(image->getHeight(),image->getWidth());
    for (int j=1; j< image->getWidth()-1;j++)
        for(int i=1; i<image->getHeight()-1;i++)
             aux->set(i,j,this->getPonderation(i,j,image,minc,maxc,media));
    return aux;
}

int Filter::getPonderation(int i, int j, OsteoporosisImage* image,int minc,int maxc, int media)
{
    float colorTotal = 0.0f;
    float colormax=0.0f;
    for(int k=0;k<mask.size();k++)
    {
        float color = 0.0f;
        for (int y= -1; y < 2; y++)
            for(int x= -1; x < 2; x++)
                //color = color + mask.at(k)->at(x+1,y+1) * qGray(image->getPixelColorAt(x+j,y+i));
                color += mask.at(k)->at(x+1,y+1) * ((float) image->getColorAt(x+j,y+i));
        if (abs(color) > abs(colormax))
             colormax=abs(color);

        //if(color > colormax)
         //   colormax=color;
    }
    colorTotal =abs(colormax);
    //colorTotal=colormax;
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

    //if (colorTotal < 0) colorTotal = 0;
    //if (colorTotal > 255) colorTotal = 255;

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
            //color = (((color - this->min)/(this->max - this->min))*255);
            image->setColorAt(i,j,color);
        }
    //OsteoporosisImage* result= image->normalize(minc,maxc);// esto se modifico
    return image;
}
