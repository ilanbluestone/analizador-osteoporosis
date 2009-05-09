#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include <QImage>

class Transformation
{
public:
    Transformation();

    void aplicar(QImage * image);
};

#endif // TRANSFORMATION_H
