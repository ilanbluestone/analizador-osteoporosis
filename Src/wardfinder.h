#ifndef WARDFINDER_H
#define WARDFINDER_H

#include "osteoporosisimage.h"
#include "transformation.h"
#include <QPoint>
#include <QList>

class WardFinder : public Transformation
{
private:
    OsteoporosisImage* image;               // imagen binarizada y mejorada de los bordes del hueso
    QList<QPoint>* path1, *path2;           // bordes del hueso femoral (caminos a recorrer)
    QPoint starterPoint1, starterPoint2;    // puntos donde comienzan los dos bordes del hueso
    QLine minimumDistance;                  // recta de distancia minima del cuello femoral
    QPoint centerPoint;                     // punto centrado en la recta de minima distancia
    QLine edge;                             // eje de simetria del cuello femoral
    QPoint criticPoint;                     // punto en el que comienza la base del triangulo
    QLine base;                             // base del triangulo de ward
    QPolygon wardTriangle;                  // triangulo de ward
    QPoint triangleCenter;                  // centro del triangulo de Ward
    int n;                                  // dimension del cuadrado centrado en el triangulo

    void checkOff(int x, int y, OsteoporosisImage* image, bool* path, QList<QPoint>* list);
    QList<QPoint> neighbords(int x, int y, QList<QPoint>* visited);
    void rotate(float x, float y, float *rx, float *ry, float angle);
    void findPaths();
    void findEdges();
    void findCriticPoint();
    void defineRegions();
    void defineWardTriangle();              // busca un cuadrado de nxn centrado en el triangulo

public:
    WardFinder(int n);
    class OsteoporosisImage* apply(class OsteoporosisImage* image);

};

#endif // WARDFINDER_H
