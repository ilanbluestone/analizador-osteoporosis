#include "matrix.h"

Matrix::Matrix(int rows, int columns)
{
    this->rows = rows;
    this->columns = columns;
    this->values = new float*[rows];
    for (int i=0; i < rows; i++)
    {
        this->values[i] = new float[columns];
        for (int j=0; j < columns; j++)
            this->values[i][j] = 0;
    }
}

int Matrix::at(int r, int c)
{
   return this->values[r][c];
}

void Matrix::set(int r, int c, float value)
{
    this->values[r][c] = value;
}

int Matrix::getRows()
{
    return this->rows;
}

int Matrix::getColumns()
{
    return this->columns;
}
