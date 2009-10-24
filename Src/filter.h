#ifndef FILTER_H
#define FILTER_H

#include "transformation.h"
#include "matrix.h"
#include <QVector>

#define maxim 5678

class Filter : public Transformation
{
protected:
    int max, min, minc, maxc;
    QVector <Matrix *> mask;

    virtual int getPonderation(int i, int j,OsteoporosisImage* image);
    Matrix* getPonderationMatrix(OsteoporosisImage* );
    class OsteoporosisImage* normalize(Matrix* values);

public:

    Filter();
    ~Filter();

    class OsteoporosisImage* apply(class OsteoporosisImage* image);
};

#endif // FILTER_H
