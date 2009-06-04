#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
private:
    int rows;
    int columns;
    int** values;

public:
    Matrix(int rows, int columns);
    int at(int r, int c);
    void set(int r, int c, int value);
    int getRows();
    int getColumns();
};

#endif // MATRIX_H
