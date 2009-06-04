#include "lowpassfilter.h"

LowPassFilter::LowPassFilter()
{
    Matrix *matrix = new Matrix(3,3);
    matrix->set(0,0,0);matrix->set(0,1,0);matrix->set(0,2,0);
    matrix->set(1,0,0);matrix->set(1,1,0);matrix->set(1,2,0);
    matrix->set(2,0,0);matrix->set(2,1,0);matrix->set(2,2,0);
    mask.push_back(matrix);

}
LowPassFilter::~LowPassFilter()
{
}
