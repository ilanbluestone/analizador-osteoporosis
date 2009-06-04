#include "osteoporosisimage.h"

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
    QImage* qimage = &(this->image->copy(QRect(begin,end)));
    OsteoporosisImage* image = new OsteoporosisImage();
    image->setImage(qimage);
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
    this->image = image;
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

void OsteoporosisImage::setPixelColorAt(int x, int y, QRgb color)
{
    this->image->setPixel(x,y,color);
}

OsteoporosisImage* OsteoporosisImage::clone()
{
    OsteoporosisImage* clon = new OsteoporosisImage();
    clon->setImage(this->getImage());
    clon->setImagePath(this->getImagePath());
    return clon;
}
