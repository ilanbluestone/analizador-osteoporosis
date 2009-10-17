#ifndef MEDIAN_H
#define MEDIAN_H
#include "transformation.h"
#include "matrix.h"
#include <QVector>

class Median : public Transformation
{
private:
    QVector<float> value;
    QVector <Matrix *> mask;
public:
    Median();
    class OsteoporosisImage* apply(class OsteoporosisImage* image);

};

#endif // MEDIAN_H
