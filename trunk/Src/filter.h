#ifndef FILTER_H
#define FILTER_H

#include "transformation.h"
#include "matrix.h"
#include <QVector>

class Filter : public Transformation
{
private:
    int max, min;

    int getPonderation(int i, int j,OsteoporosisImage* image);
    class OsteoporosisImage* normalize(Matrix* values);

protected:

    //int matrix[3][3];
    QVector <Matrix *> mask;
    Matrix* getPonderationMatrix(OsteoporosisImage* );

public:

    Filter();
    ~Filter();

    class OsteoporosisImage* apply(class OsteoporosisImage* image);
};

#endif // FILTER_H
