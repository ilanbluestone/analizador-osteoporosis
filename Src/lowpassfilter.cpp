#include "lowpassfilter.h"

LowPassFilter::LowPassFilter()
{
    Matrix *matrix = new Matrix(3,3);
    matrix->set(0,0,1);matrix->set(0,1,2);matrix->set(0,2,1);
    matrix->set(1,0,2);matrix->set(1,1,4);matrix->set(1,2,2);
    matrix->set(2,0,1);matrix->set(2,1,2);matrix->set(2,2,1);
    mask.push_back(matrix);
}

LowPassFilter::~LowPassFilter()
{
}
