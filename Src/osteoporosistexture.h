#ifndef OSTEOPOROSISTEXTURE_H
#define OSTEOPOROSISTEXTURE_H
#include "osteoporosisimage.h"
#include<QVector>

class OsteoporosisTexture
{
private:
        OsteoporosisImage* image;
        QVector<float> horizontal;
        QVector<float> vertical;
        OsteoporosisImage* binarizeImage;

public:
    OsteoporosisTexture(OsteoporosisImage* i);
    // saca el promedio de gris de la imagen para poder binarizarla
    float grayAverage();
    // Binariza la imagen dado el promedio de gris
    void binarize();
    //Crea el arreglo horizantal con los cosenos de las filas
    void createHorArray();
    //Crea el arreglo vertical con los cosenos de las columnas
    void createVerArray();
    //Calcula el coseno de una fila
    float calculateCosHor(int i);
    //Calcua el coseno de una columna
    float calculateCosVer(int j);
    //saca el promedio de los cosenos
    float cosAverage(QVector<float>);
    //Calcuala el indice de osteoporosis
    float indexCalculate();

};

#endif // OSTEOPOROSISTEXTURE_H
