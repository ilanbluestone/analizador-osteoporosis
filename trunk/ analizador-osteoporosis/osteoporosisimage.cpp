#include "osteoporosisimage.h"

OsteoporosisImage::OsteoporosisImage()
{
    this->image = null;
    this->imagePath = "";
}

OsteoporosisImage::OsteoporosisImage(QString path)
{
    this->load(path);
    this->imagePath = path;
}

void OsteoporosisImage::load(QString path)
{
    this->image->load(path);
    this->imagePath = path;
}

void OsteoporosisImage::save(QString path)
{
    this->image->save(path);
}

OsteoporosisImage *OsteoporosisImage::transform(Transformation *t)
{
    return t->apply(this);
}

QImage *OsteoporosisImage::getImage()
{
    QImage *image = new QImage(this->image);
    return image;
}

void OsteoporosisImage::setImage(QImage *image)
{
    this->image = image;
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
    return this->getWidth();
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

}
