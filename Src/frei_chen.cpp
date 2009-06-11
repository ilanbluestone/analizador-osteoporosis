#include "frei_chen.h"

Frei_ChenFilter::Frei_ChenFilter()
{
    Matrix *matrix = new Matrix(3,3);
    matrix->set(0,0,1);matrix->set(0,1,1.41);matrix->set(0,2,1);
    matrix->set(1,0,0);matrix->set(1,1,0);matrix->set(1,2,0);
    matrix->set(2,0,-1);matrix->set(2,1,-1.41);matrix->set(2,2,-1);
    mask.push_back(matrix);
    Matrix *matrix2 = new Matrix(3,3);
    matrix2->set(0,0,1);matrix2->set(0,1,0);matrix2->set(0,2,-1);
    matrix2->set(1,0,1.41);matrix2->set(1,1,0);matrix2->set(1,2,-1.41);
    matrix2->set(2,0,1);matrix2->set(2,1,0);matrix2->set(2,2,-1);
    mask.push_back(matrix2);
}
