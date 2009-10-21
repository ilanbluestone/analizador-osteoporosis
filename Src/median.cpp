#include "median.h"

Median::Median()
{
    float a = 1.0f;
    float b = 2.0f;

    Matrix *matrix = new Matrix(3,3);
    matrix->set(0,0,-a);matrix->set(0,1,0);matrix->set(0,2,a);
    matrix->set(1,0,-b);matrix->set(1,1,0);matrix->set(1,2,b);
    matrix->set(2,0,-a);matrix->set(2,1,0);matrix->set(2,2,a);
    mask.push_back(matrix);

    //filtro noreste
    matrix = new Matrix(3,3);
    matrix->set(0,0,-a);matrix->set(0,1,-b);matrix->set(0,2,-a);
    matrix->set(1,0,0);matrix->set(1,1,0);matrix->set(1,2,0);
    matrix->set(2,0,a);matrix->set(2,1,b);matrix->set(2,2,a);
    mask.push_back(matrix);

    //filtro sur
    matrix = new Matrix(3,3);
    matrix->set(0,0,a);matrix->set(0,1,0);matrix->set(0,2,-a);
    matrix->set(1,0,b);matrix->set(1,1,0);matrix->set(1,2,-b);
    matrix->set(2,0,a);matrix->set(2,1,0);matrix->set(2,2,-a);
    mask.push_back(matrix);

    //filtro este
    matrix = new Matrix(3,3);
    matrix->set(0,0,a);matrix->set(0,1,b);matrix->set(0,2,a);
    matrix->set(1,0,0);matrix->set(1,1,0);matrix->set(1,2,0);
    matrix->set(2,0,-a);matrix->set(2,1,-b);matrix->set(2,2,-a);
    mask.push_back(matrix);

    //filtro oeste
    matrix = new Matrix(3,3);
    matrix->set(0,0,-b);matrix->set(0,1,-a);matrix->set(0,2,0);
    matrix->set(1,0,-a);matrix->set(1,1,0);matrix->set(1,2,a);
    matrix->set(2,0,0);matrix->set(2,1,a);matrix->set(2,2,b);
    mask.push_back(matrix);

    //filtro sureste
    matrix = new Matrix(3,3);
    matrix->set(0,0,b);matrix->set(0,1,a);matrix->set(0,2,0);
    matrix->set(1,0,a);matrix->set(1,1,0);matrix->set(1,2,-a);
    matrix->set(2,0,0);matrix->set(2,1,-a);matrix->set(2,2,-b);
    mask.push_back(matrix);

    //filtro suroeste
    matrix = new Matrix(3,3);
    matrix->set(0,0,0);matrix->set(0,1,a);matrix->set(0,2,b);
    matrix->set(1,0,-a);matrix->set(1,1,0);matrix->set(1,2,a);
    matrix->set(2,0,-b);matrix->set(2,1,-a);matrix->set(2,2,0);
    mask.push_back(matrix);

    matrix = new Matrix(3,3);
    matrix->set(0,0,0);matrix->set(0,1,-a);matrix->set(0,2,-b);
    matrix->set(1,0,a);matrix->set(1,1,0);matrix->set(1,2,-a);
    matrix->set(2,0,b);matrix->set(2,1,a);matrix->set(2,2,0);
    mask.push_back(matrix);
}


