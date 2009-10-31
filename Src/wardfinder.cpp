#include "wardfinder.h"
#include <QPainter>
#include </usr/include/math.h>
#include <QDebug>

WardFinder::WardFinder(int n)
{
    this->path1 = new QList<QPoint>;
    this->path2 = new QList<QPoint>;
    this->n = n;
}

OsteoporosisImage* WardFinder::apply(OsteoporosisImage* image)
{
    this->image = image;

    this->findPaths();
    this->findEdges();
    this->findCriticPoint();
    this->defineWardTriangle();
    this->defineRegions();

    OsteoporosisImage* resul = new OsteoporosisImage(this->image->getSize());
    resul->fill(0);

    for (int i=0; i < this->path1->size(); i++)
        resul->setColorAt(this->path1->at(i).x(),this->path1->at(i).y(),255);
    for (int i=0; i < this->path2->size(); i++)
        resul->setColorAt(this->path2->at(i).x(),this->path2->at(i).y(),255);

    QImage *i = resul->getImage();
    QPainter painter(i);
    painter.setPen(QColor(255,0,0));
    painter.drawLine(this->minimumDistance);
    painter.drawLine(this->base);
    painter.setPen(QPen(QColor(0,50,200), 1, Qt::DashLine));
    painter.drawLine(this->edge);
    painter.setPen(QColor(0,255,0));
    painter.drawEllipse(this->centerPoint,3,3);
    painter.drawEllipse(this->criticPoint,3,3);
    painter.drawPolygon(this->wardTriangle, Qt::WindingFill);
    resul->setImage(i);
    return resul;
}

void WardFinder::findPaths()
{
    // recorro el marco superior y busco los puntos en los que podria llegar a comenzar el primer borde
    int x = image->getWidth();
    int y = -1;
    bool find = false;
    while ((!find) and (x >= 0))
    {
        x--;
        if (image->getColorAt(x,0) == 255)
        {
            bool f = false;
            this->checkOff(x,0,image,&f,this->path1);
            find = f;
        }
    }

    // recorro el marco derecho y busco los puntos en los que podria llegar a comenzar el segundo borde
    find = false;
    while ((!find) and (y < image->getHeight()))
    {
        y++;
        if (image->getColorAt(image->getWidth()-1,y) == 255)
        {
            bool f = false;
            this->checkOff(image->getWidth()-1,y,image,&f,this->path2);
            find = f;
        }
    }

}

void WardFinder::findEdges()
{
    // busco la recta de minima distancia entre las primeras mitades de puntos de cada borde
    QLine aux;
    float distance = INFINITY;
    for (int i=0; i < this->path1->size()/2; i++)
        for (int j=0; j < this->path2->size()/2; j++)
        {
            aux = QLine(this->path1->at(i),this->path2->at(j));
            float distanceAux = sqrt((aux.dx()*aux.dx()) + (aux.dy()*aux.dy()));
            if (distance > distanceAux)
            {
                distance = distanceAux;
                this->minimumDistance = aux;
            }
        }

    // calculo el punto medio de la recta de minima distancia
    this->centerPoint = QPoint(this->minimumDistance.x1() + (this->minimumDistance.dx()/2), this->minimumDistance.y1() + (this->minimumDistance.dy()/2));

    // calculo la pendiente de la recta de minima distancia
    float m = ((float)this->minimumDistance.y1() - (float)this->minimumDistance.y2())/((float)this->minimumDistance.x1() - (float)this->minimumDistance.x2());

    // invierto y cambio de signo para la recta perpendicular (eje de simetria)
    m = -1.0f/m;

    // calculo punto P1 para el eje (y,ANCHO-2) con la ecuacion de la recta
    double a = (this->image->getWidth()-2 - this->centerPoint.x());
    int y = m * a + this->centerPoint.y();
    this->edge.setP1(QPoint(this->image->getWidth()-2,y));

    // calculo punto P2 para el eje (y,50) con la ecuacion de la recta
    a = (50 - this->centerPoint.x());
    y = m * a + this->centerPoint.y();
    this->edge.setP2(QPoint(50,y));
}

void WardFinder::findCriticPoint()
{
    // calculo la pendiente de la recta de minima distancia
    float m = ((float)this->minimumDistance.y1() - (float)this->minimumDistance.y2())/((float)this->minimumDistance.x1() - (float)this->minimumDistance.x2());

    // calculo el angulo de rotacion de los puntos del camino superior
    // con el objetivo de calcular el cambio de signo de la pendiente con respecto al eje de simetria
    float angleRad = atan(m) + M_PI;

    // roto los puntos del borde superior...
    QList<QPoint> rotated;
    for (int i = 0; i < this->path1->size(); i++)
    {
        float rx,ry;
        this->rotate(this->path1->at(i).x(),this->path1->at(i).y(),&rx,&ry,angleRad);
        rotated.push_back(QPoint(rx,ry));
    }

    // comienzo con una pendiente negativa y busco el punto aproximado donde cambia a positiva
    float grade = -1;
    int index = this->path1->indexOf(this->minimumDistance.p1(),0);
    bool exit = false;

    while(index < rotated.size()-5 and !exit)
    {
        QLine tangent(rotated.at(index),rotated.at(index + 5));
        grade = ((float)tangent.y2() - (float)tangent.y1()) / ((float)tangent.x2() - (float)tangent.x1());
        if (grade >= 0.0f) index++;
        else exit = true;
    }

    this->criticPoint = this->path1->at(index);

    // busco la recta perpendicular al eje, que pasa por el punto critico (base)
    this->base.setP1(this->criticPoint);
    exit = false;
    for (int i=0; i < this->path2->size() and !exit; i++)
    {
        int x = this->path2->at(i).x();
        double a = (x - this->criticPoint.x());
        float y = m * a + this->criticPoint.y();

        if (abs((float)(this->path2->at(i).y() - y)) <= 1.0f)
        {
            exit = true;
            this->base.setP2(this->path2->at(i));
        }
    }
    if (!exit)
        this->base.setP2(QPoint(0,0));      // por si hay algun caso en que no funcione...
}

void WardFinder::defineWardTriangle()
{
    // punto medio de la recta del cuello
    this->wardTriangle.push_back(QPoint(this->centerPoint.x(),this->centerPoint.y()));

    // busco los puntos interseccion entre la recta base y las rectas perpendiculares
    // que pasan por los extremos superior e inferior de la recta del cuello...
    // la idea es formar una caja...

    // defino la primer pendiente:
    float m1 = ((float)this->minimumDistance.y1() - (float)this->minimumDistance.y2())/((float)this->minimumDistance.x1() - (float)this->minimumDistance.x2());

    // la segunda pendiente:
    float m2 = -1.0f/m1;

    // calculo el primer punto
    // busco la interseccion entre "y = m1*x + a" y "y = m2*x + b"
    float a,b;
    a = ((float)this->criticPoint.y() - (m1 * (float)this->criticPoint.x()));
    b = ((float)this->minimumDistance.y1() - (m2 * (float)this->minimumDistance.x1()));
    float x,y;
    x = (b - a)/(m1 - m2);
    y = m1 * x + a;
    QPoint p2 = QPoint(x,y);
    this->wardTriangle.push_back(p2);

    // calculo el segundo punto
    // a. es el mismo
    b = ((float)this->minimumDistance.y2() - (m2 * (float)this->minimumDistance.x2()));
    x = (b - a)/(m1 - m2);
    y = m1 * x + a;
    QPoint p3 = QPoint(x,y);
    this->wardTriangle.push_back(p3);
}

void WardFinder::defineRegions()
{
    // para definir, si hay tiempo, el neck, troch e inter-troch
}

QList<QPoint> WardFinder::neighbords(int x, int y, QList<QPoint>* visited)
{
    QList<QPoint> points;
    if ((image->getColorAt(x,y-1) == 255) and (!visited->contains(QPoint(x,y-1))))
        points.push_front(QPoint(x,y-1));
    if ((image->getColorAt(x+1,y-1) == 255) and (!visited->contains(QPoint(x+1,y-1))))
        points.push_front(QPoint(x+1,y-1));
    if ((image->getColorAt(x+1,y) == 255) and (!visited->contains(QPoint(x+1,y))))
        points.push_front(QPoint(x+1,y));
    if ((image->getColorAt(x+1,y+1) == 255) and (!visited->contains(QPoint(x+1,y+1))))
        points.push_front(QPoint(x+1,y+1));
    if ((image->getColorAt(x,y+1) == 255) and (!visited->contains(QPoint(x,y+1))))
        points.push_front(QPoint(x,y+1));
    if ((image->getColorAt(x-1,y+1) == 255) and (!visited->contains(QPoint(x-1,y+1))))
        points.push_front(QPoint(x-1,y+1));
    if ((image->getColorAt(x-1,y) == 255) and (!visited->contains(QPoint(x-1,y))))
        points.push_front(QPoint(x-1,y));
    if ((image->getColorAt(x-1,y-1) == 255) and (!visited->contains(QPoint(x-1,y-1))))
        points.push_front(QPoint(x-1,y-1));
    return points;
}

void WardFinder::checkOff(int x, int y, OsteoporosisImage* image, bool* path, QList<QPoint> *list)
{
    if (y == image->getHeight()-1)
    {
        list->push_back(QPoint(x,y));
        *path = true;
    }
    else
    {
        list->push_back(QPoint(x,y));
        QList<QPoint> neighbord = this->neighbords(x,y,list);
        for (int i = 0; i < neighbord.size() and !(*path); i++)
            checkOff(((QPoint) neighbord.at(i)).x(), ((QPoint) neighbord.at(i)).y(), image, path, list);
        if (!(*path))
            list->pop_back();
    }
}

void WardFinder::rotate(float x, float y, float *rx, float *ry, float angle)
{
    *rx = x * cos(angle) - y * sin(angle);
    *ry = x * sin(angle) + y * cos(angle);
}
