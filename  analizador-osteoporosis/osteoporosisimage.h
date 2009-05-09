#ifndef OSTEOPOROSISIMAGE_H
#define OSTEOPOROSISIMAGE_H

#include "transformation.h"
#include <QImage>

class OsteoporosisImage
{
private:
    QImage image;
public:
    void load(QString path);
    void save(QString path);
    OsteoporosisImage *transformation (Transformation t);

    OsteoporosisImage();
};

#endif // OSTEOPOROSISIMAGE_H
