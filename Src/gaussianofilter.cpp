#include "gaussianofilter.h"

GaussianoFilter::GaussianoFilter()
{
    float a = 1.0f / 16.0f;
    float b = 2.0f / 16.0f;
    float c = 4.0f / 16.0f;
    Matrix *matrix = new Matrix(3,3);
    matrix->set(0,0,a);matrix->set(0,1,b);matrix->set(0,2,a);
    matrix->set(1,0,b);matrix->set(1,1,c);matrix->set(1,2,b);
    matrix->set(2,0,a);matrix->set(2,1,b);matrix->set(2,2,a);
    mask.push_back(matrix);
}
