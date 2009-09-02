#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
private:
    int rows;
    int columns;
    float** values;

public:
    Matrix(int rows, int columns);
    float at(int r, int c);
    void set(int r, int c, float value);
    int getRows();
    int getColumns();
};

#endif // MATRIX_H
