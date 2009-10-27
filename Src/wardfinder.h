#ifndef WARDFINDER_H
#define WARDFINDER_H

#include "osteoporosisimage.h"
#include <QPoint>
#include <QList>

class WardFinder
{
private:
    OsteoporosisImage* paths;
    QList<QPoint>* path1, *path2;
    QPoint starterPoint1, starterPoint2;
    QPoint criticPoint;                 // punto en el que comienza la base del triangulo
    QLine minimumDistance;
    QPolygon wardTriangle;
    QPoint centerPoint;                 // punto centrado en el triangulo
    QLine edge;

    void checkOff(int x, int y, OsteoporosisImage* image, bool* path, QList<QPoint>* list);
    QList<QPoint> neighbords(int x, int y, OsteoporosisImage* image);

    void rotate(float x, float y, float *rx, float *ry, float angle);
public:
    WardFinder();

    void findPaths(OsteoporosisImage* image);
    void findPoints();
    QRect* findWardTraingle(int n);          // devuelve un cuadrado de nxn centrado en el triangulo
    OsteoporosisImage* getPaths();

};

#endif // WARDFINDER_H
