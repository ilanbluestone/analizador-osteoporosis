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
    void setImagePath(QString path);

public:
    void load(QString path);
    void saveAs(QString path);
    void save();
    void copyFrom(OsteoporosisImage* image);
    int getWidth();
    int getHeight();
    QSize getSize();
    QRgb getPixelColorAt(int x, int y);
    void setPixelColorAt(int x, int y, QRgb color);
    QString getImagePath();
    QImage* getImage();
    OsteoporosisImage* cut (QPoint begin, QPoint end);
    OsteoporosisImage* clone();
    OsteoporosisImage* transform(class Transformation* t);
    OsteoporosisImage();
    OsteoporosisImage(QSize size);
    OsteoporosisImage(QString path);


};

#endif // OSTEOPOROSISIMAGE_H
