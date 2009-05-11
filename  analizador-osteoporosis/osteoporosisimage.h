#ifndef OSTEOPOROSISIMAGE_H
#define OSTEOPOROSISIMAGE_H

#include "transformation.h"

#include <QString>
#include <QImage>

class OsteoporosisImage
{
private:
    QImage image;
public:
    void load(QString path);
    void save(QString path);

    OsteoporosisImage *transform(class Transformation* t);

    OsteoporosisImage();
};

#endif // OSTEOPOROSISIMAGE_H
