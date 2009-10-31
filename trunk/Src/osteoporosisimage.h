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

    void setImagePath(QString path);

public:
    void load(QString path);
    void saveAs(QString path, char* type = 0);
    void save();
    void copyFrom(OsteoporosisImage* image);
    void setPixelColorAt(int x, int y, QRgb color);
    void setColorAt(int x, int y, int color);
    void setImage(QImage* image);
    int getWidth();
    int getHeight();
    int getColorAt(int x, int y);
    int getColorMax();
    int getColorMin();
    long getMax(long* counter);
    long getMin(long* counter);
    int getMedia();
    QSize getSize();
    QRgb getPixelColorAt(int x, int y);
    QString getImagePath();
    QImage* getImage();
    OsteoporosisImage* cut (QPoint begin, QPoint end);
    OsteoporosisImage* clone();
    OsteoporosisImage* transform(class Transformation* t);
    OsteoporosisImage* getHstogramImage();
    OsteoporosisImage();
    OsteoporosisImage(QSize size);
    OsteoporosisImage(QString path);
    long* getHistogram();
    OsteoporosisImage* normalize(int, int);
    int* normalize(long* counter);
    void fill(int color);
};

#endif // OSTEOPOROSISIMAGE_H
