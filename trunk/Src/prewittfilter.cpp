#include "prewittfilter.h"

PrewittFilter::PrewittFilter()  //:NorthFilter(),NorthEastFilter(),NorthWestFilter(), SouthFilter(),SouthEastFilter(),SouthWestFilter(),WestFilter(),EastFilter()
{   //filtro norte
    Matrix *matrix = new Matrix(3,3);
    matrix->set(0,0,-1);matrix->set(0,1,-1);matrix->set(0,2,-1);
    matrix->set(1,0,1);matrix->set(1,1,-2);matrix->set(1,2,1);
    matrix->set(2,0,1);matrix->set(2,1,1);matrix->set(2,2,1);
    mask.push_back(matrix);

    //filtro noreste
    matrix = new Matrix(3,3);
    matrix->set(0,0,1);matrix->set(0,1,-1);matrix->set(0,2,-1);
    matrix->set(1,0,1);matrix->set(1,1,-2);matrix->set(1,2,-1);
    matrix->set(2,0,1);matrix->set(2,1,1);matrix->set(2,2,1);
    mask.push_back(matrix);

    //filtro sur
    matrix = new Matrix(3,3);
    matrix->set(0,0,1);matrix->set(0,1,1);matrix->set(0,2,1);
    matrix->set(1,0,1);matrix->set(1,1,-2);matrix->set(1,2,1);
    matrix->set(2,0,-1);matrix->set(2,1,-1);matrix->set(2,2,-1);
    mask.push_back(matrix);

    //filtro este
    matrix = new Matrix(3,3);
    matrix->set(0,0,1);matrix->set(0,1,1);matrix->set(0,2,-1);
    matrix->set(1,0,1);matrix->set(1,1,-2);matrix->set(1,2,-1);
    matrix->set(2,0,1);matrix->set(2,1,1);matrix->set(2,2,-1);
    mask.push_back(matrix);

    //filtro oeste
    matrix = new Matrix(3,3);
    matrix->set(0,0,-1);matrix->set(0,1,1);matrix->set(0,2,1);
    matrix->set(1,0,-1);matrix->set(1,1,-2);matrix->set(1,2,1);
    matrix->set(2,0,-1);matrix->set(2,1,1);matrix->set(2,2,1);
    mask.push_back(matrix);

    //filtro sureste
    matrix = new Matrix(3,3);
    matrix->set(0,0,1);matrix->set(0,1,1);matrix->set(0,2,1);
    matrix->set(1,0,1);matrix->set(1,1,-2);matrix->set(1,2,-1);
    matrix->set(2,0,1);matrix->set(2,1,-1);matrix->set(2,2,-1);
    mask.push_back(matrix);

    //filtro suroeste
    matrix = new Matrix(3,3);
    matrix->set(0,0,1);matrix->set(0,1,1);matrix->set(0,2,1);
    matrix->set(1,0,-1);matrix->set(1,1,-2);matrix->set(1,2,1);
    matrix->set(2,0,-1);matrix->set(2,1,-1);matrix->set(2,2,1);
    mask.push_back(matrix);
}
