#ifndef MEDIAN_H
#define MEDIAN_H
#include "filter.h"

#include <QVector>

class MedianFilter : public Filter
{
private:
    QVector<float> *values;

protected:
    int getPonderation(int i, int j, OsteoporosisImage* image);

public:
    MedianFilter();

};

#endif // MEDIAN_H
