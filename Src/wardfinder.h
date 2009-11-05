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
    QList<QPoint> *path1, *path2;           // bordes del hueso femoral (caminos a recorrer)
    QLineF minimumDistance;                 // recta de distancia minima del cuello femoral
    QPointF centerPoint;                    // punto centrado en la recta de minima distancia
    QLineF edge;                            // eje de simetria del cuello femoral
    QPointF criticPoint;                    // punto en el que comienza la base del triangulo
    QLineF base;                            // base del triangulo de ward
    QPolygonF wardTriangle;                 // triangulo de ward
    QPolygonF neckZone;                     // region del cuello
    QPolygonF interTroch;                   // region intertrochanteric
    QPolygonF troch;                        // region trochanteric
    QRect wardZone;                         // cuadrado de dimension n
    QPointF triangleCenter;                 // centro del triangulo de Ward
    int n;                                  // dimension del cuadrado centrado en el triangulo
    bool sTWard, sRWard, sEdge, sNeck;      // opciones

    void checkOff(int x, int y, OsteoporosisImage* image, bool* path, QList<QPoint>* list);
    QList<QPoint> neighbords(int x, int y, QList<QPoint>* visited);
    void rotate(float x, float y, float *rx, float *ry, float angle);
    void findPaths();
    void findEdges();
    void findCriticPoint();
    void defineRegions();
    void defineWardTriangle();

public:
    WardFinder(int n);

    void setOptions(bool sTWard, bool sRWard, bool sEdge, bool sNeck);

    QRect getWardZone();
    QPolygonF getWardTriangle();
    QPolygonF getNeckZone();
    QPolygonF getTrochZone();
    QPolygonF getInterTrochZone();
    QPolygonF getSimetricEdge();

    class OsteoporosisImage* apply(class OsteoporosisImage* image);

};

#endif // WARDFINDER_H
