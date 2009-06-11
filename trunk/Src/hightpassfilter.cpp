#include "hightpassfilter.h"

HightPassFilter::HightPassFilter()
{
    int a = -1;
    int b = 8;
    Matrix *matrix = new Matrix(3,3);
    matrix->set(0,0,a);matrix->set(0,1,a);matrix->set(0,2,a);
    matrix->set(1,0,a);matrix->set(1,1,b);matrix->set(1,2,a);
    matrix->set(2,0,a);matrix->set(2,1,a);matrix->set(2,2,a);
    mask.push_back(matrix);
}

HightPassFilter::~HightPassFilter()
{
}
