#ifndef OSTEOPOROSISIMAGE_H
#define OSTEOPOROSISIMAGE_H

#include "transformation.h"
#include <QImage>
#include <QString>

class OsteoporosisImage
{
private:
    QImage* image;
    QString imagePath;

    void setImage(QImage* image);
    QImage* getImage();

public:
    void load(QString path);
    void save(QString path);
    void copyFrom(OsteoporosisImage* image);
    int getWidth();
    int getHeight();
    QSize getSize();
    QRgb getPixelColorAt(int x, int y);
    void setPixelColorAt(int x, int y, QRgb color);
    QString getImagePath();
    OsteoporosisImage *clone();
    OsteoporosisImage *transform(class Transformation *t);
    OsteoporosisImage();
    OsteoporosisImage(QString path);

};

#endif // OSTEOPOROSISIMAGE_H
