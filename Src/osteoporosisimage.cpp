#include "osteoporosisimage.h"
#include <QColor>
OsteoporosisImage::OsteoporosisImage()
{
    this->image=NULL;
    this->imagePath = "";
}

OsteoporosisImage::OsteoporosisImage(QSize size)
{
    this->image= new QImage(size,QImage::Format_RGB32);
    this->image->fill(qRgb(0,0,0));
    this->imagePath = "";
}

OsteoporosisImage* OsteoporosisImage::cut(QPoint begin, QPoint end)
{
    QImage qimage;
     if(begin.x() < end.x())
         qimage = this->image->copy(QRect(begin,end));
    else
         qimage = this->image->copy(QRect(end,begin));
    OsteoporosisImage* image = new OsteoporosisImage();
    image->setImage(&qimage);
    return image;
}

OsteoporosisImage::OsteoporosisImage(QString path)
{
    this->image = new QImage();
    this->image->load(path);
    this->imagePath = path;
}

void OsteoporosisImage::load(QString path)
{
    this->image->load(path);
    this->imagePath = path;
}

void OsteoporosisImage::save()
{
    this->image->save(this->imagePath);
}

void OsteoporosisImage::saveAs(QString path)
{
    this->image->save(path);
}

OsteoporosisImage *OsteoporosisImage::transform(Transformation *t)
{
    return t->apply(this);
}

QImage *OsteoporosisImage::getImage()
{
    QImage *image = new QImage(*this->image);
    return image;
}

void OsteoporosisImage::setImage(QImage *image)
{
    this->image = new QImage(*image);
}

void OsteoporosisImage::setImagePath(QString path)
{
    this->imagePath = path;
}

QString OsteoporosisImage::getImagePath()
{
    return this->imagePath;
}

void OsteoporosisImage::copyFrom(OsteoporosisImage *image)
{
    this->image = image->getImage();
    this->imagePath = image->getImagePath();
}

int OsteoporosisImage::getHeight()
{
    return this->image->height();
}

int OsteoporosisImage::getWidth()
{
    return this->image->width();
}

QSize OsteoporosisImage::getSize()
{
    return this->image->size();
}

QRgb OsteoporosisImage::getPixelColorAt(int x, int y)
{
    return this->image->pixel(x,y);
}

int OsteoporosisImage::getColorAt(int x, int y)
{
    QColor c=this->image->pixel(x,y);
    return qGray(c.rgb());
}

void OsteoporosisImage::setPixelColorAt(int x, int y, QRgb color)
{
    this->image->setPixel(x,y,color);
}

void OsteoporosisImage::setColorAt(int x, int y, int color)
{
    this->image->setPixel(x,y,qRgb(color,color,color));
}

OsteoporosisImage* OsteoporosisImage::clone()
{
    OsteoporosisImage* clon = new OsteoporosisImage();
    clon->setImage(this->getImage());
    clon->setImagePath(this->getImagePath());
    return clon;
}

int OsteoporosisImage::getColorMax()
{
    int max;
    max = getColorAt(0,0);
    for (int j=0; j < this->image->height(); j++)
        for (int i=0; i < this->image->width(); i++)
        {
            //int color= qGray(this->image->pixel(i,j));
            int color=getColorAt(i,j);
            if (max < color) max = color;
        }
    return max;
}
int OsteoporosisImage::getColorMin()
{
    int min;
    min =getColorAt(0,0);
    for (int j=0; j < this->image->height(); j++)
        for (int i=0; i < this->image->width(); i++)
        {
            //int color= qGray(this->image->pixel(i,j));
            int color=getColorAt(i,j);
            if (min > color) min = color;
        }
    return min;
}


int* OsteoporosisImage::normalize(long* counter)
{
    long min, max;
    min = getMin(counter);
    max = getMax(counter);
    int* result = new int[256];
    for (int i=0; i<256;i++)
    {
        float valor = counter[i];
        valor = ((float((valor - min)/(max - min))*255));
        result[i]=(int)valor;
    }
    return result;
}

OsteoporosisImage* OsteoporosisImage::normalize(int min, int max)
{
    OsteoporosisImage *result = new OsteoporosisImage(image->size());
    for (int i=0; i<image->width();i++)
        for(int j=0;j<image->height();j++)
        {
           float valor = this->getColorAt(i,j);
           valor = ((float((valor - min)/(max - min))*255));
           result->setColorAt(i,j,valor);
        }
    return result;
}

long OsteoporosisImage::getMax(long* counter)
{
    long max;
    max =counter[0];
    for (int i=1; i < 256; i++)
    {
        long aux=counter[i];
        if (max < aux) max = aux;
    }
    return max;
}
long OsteoporosisImage::getMin(long* counter)
{
    long min;
    min =counter[0];
    for (int i=1; i < 256; i++)
    {
        long aux=counter[i];
        if (min > aux) min = aux;
    }
    return min;
}

long* OsteoporosisImage::getHistogram()
{
    long* counter = new long[256];
    for (int i=0; i<256;i++)
         counter[i]=0;
    for (int i=1; i <this->getWidth()-1;i++)
        for(int j=1; j<this->getHeight()-1;j++)
            counter[this->getColorAt(i,j)]+=1;
    return counter;
}

OsteoporosisImage* OsteoporosisImage::getHstogramImage()
{
    long* counter=this->getHistogram();
    int* counterNormalize= this->normalize(counter);
    OsteoporosisImage *iHist=new OsteoporosisImage(QSize(256,256));
    for (int i=0; i < iHist->getWidth(); i++){
        long j;
        for (j=iHist->getHeight()-1; j > iHist->getHeight()-1 - (counterNormalize[i]) && j>0  ; j--)
            iHist->setPixelColorAt(i,j,qRgb(100,100,200));
        for (long k=j; k > 0  ; k--)
            iHist->setPixelColorAt(i,k,qRgb(255,255,255));
    }
    return iHist;
}

int OsteoporosisImage::getMedia()
{
    long* histo = this->getHistogram();
    double cont = ((this->getWidth()-1) * (this->getHeight()-1)) / 2;
    bool exit = false;
    int i;
    for (i=0;( i < 256 && !exit); i++){
        cont =cont- histo[i];
        if (cont < 0) exit = true;
    }
    return i-1;
}
