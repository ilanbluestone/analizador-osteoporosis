#include "northwestfilter.h"

NorthWestFilter::NorthWestFilter()
{
    Matrix *matrix = new Matrix(3,3);
    matrix->set(0,0,-1);matrix->set(0,1,-1);matrix->set(0,2,1);
    matrix->set(1,0,-1);matrix->set(1,1,-2);matrix->set(1,2,1);
    matrix->set(2,0,1);matrix->set(2,1,1);matrix->set(2,2,1);
    mask.push_back(matrix);
}
