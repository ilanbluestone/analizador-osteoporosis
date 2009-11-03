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
    //painter.drawLine(this->minimumDistance);
    //painter.drawLine(this->base);
    painter.drawPolygon(this->neckZone);
    painter.setPen(QPen(QColor(0,50,200), 1, Qt::DashLine));
    painter.drawLine(this->edge);
    painter.setPen(QColor(0,255,0));
    painter.drawRect(this->wardZone);
    painter.setPen(QColor(0,255,250));
    //painter.drawEllipse(this->centerPoint,3,3);
    //painter.drawEllipse(this->criticPoint,3,3);
    painter.drawEllipse(this->triangleCenter,3,3);
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
    this->centerPoint = QPointF(this->minimumDistance.x1() + ((float)this->minimumDistance.dx()/2.0f), this->minimumDistance.y1() + ((float)this->minimumDistance.dy()/2.0f));

    // calculo la pendiente de la recta de minima distancia
    float m = ((float)this->minimumDistance.y1() - (float)this->minimumDistance.y2())/((float)this->minimumDistance.x1() - (float)this->minimumDistance.x2());

    // invierto y cambio de signo para la recta perpendicular (eje de simetria)
    m = -1.0f/m;

    // calculo punto P1 para el eje (y,ANCHO-2) con la ecuacion de la recta
    double a = (this->image->getWidth()-2 - this->centerPoint.x());
    int y = m * a + this->centerPoint.y();
    this->edge.setP1(QPointF(this->image->getWidth()-2,y));

    // calculo punto P2 para el eje (y,50) con la ecuacion de la recta
    a = (50 - this->centerPoint.x());
    y = m * a + this->centerPoint.y();
    this->edge.setP2(QPointF(50,y));
}

void WardFinder::findCriticPoint()
{
    // calculo la pendiente de la recta de minima distancia
    float m = ((float)this->minimumDistance.y1() - (float)this->minimumDistance.y2())/((float)this->minimumDistance.x1() - (float)this->minimumDistance.x2());

    // calculo el angulo de rotacion de los puntos del camino superior
    // con el objetivo de calcular el cambio de signo de la pendiente con respecto al eje de simetria
    float angleRad = atan(m) + M_PI;

    // roto los puntos del borde superior...
    QList<QPointF> rotated;
    for (int i = 0; i < this->path1->size(); i++)
    {
        float rx,ry;
        this->rotate(this->path1->at(i).x(),this->path1->at(i).y(),&rx,&ry,angleRad);
        rotated.push_back(QPointF(rx,ry));
    }

    // comienzo con una pendiente negativa y busco el punto aproximado donde cambia a positiva
    float grade = -1;
    int index = this->path1->indexOf(this->minimumDistance.p1().toPoint(),0);
    bool exit = false;

    while(index < rotated.size()-5 and !exit)
    {
        QLineF tangent(rotated.at(index),rotated.at(index + 5));   // aproximamos tangentes con rectas de 5 pts de longitud
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
        this->base.setP2(QPointF(0,0));      // por si hay algun caso en que no funcione...
}

void WardFinder::defineWardTriangle()
{
    // punto medio de la recta del cuello
    this->wardTriangle.push_back(QPointF(this->centerPoint.x(),this->centerPoint.y()));

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
    QPointF p2 = QPointF(x,y);
    this->wardTriangle.push_back(p2);

    // calculo el segundo punto
    // a. es el mismo
    b = ((float)this->minimumDistance.y2() - (m2 * (float)this->minimumDistance.x2()));
    x = (b - a)/(m1 - m2);
    y = m1 * x + a;
    QPointF p3 = QPointF(x,y);
    this->wardTriangle.push_back(p3);

    // calculo el punto de intersecion entre la base y el eje de simetria
    b = ((float)this->centerPoint.y() - (m2 * (float)this->centerPoint.x()));
    x = (b - a)/(m1 - m2);
    y = m1 * x + a;

    // busco el punto medio del triangulo, es decir, la interseccion de las medianas (baricentro o centro de masa)
    // para eso busco los puntos medios de cada lado del triangulo y defino sus ecuaciones
    // uso la ecuacion del eje de simetria y busco la interseccion con alguna de las otras 2 medianas
    QPointF medianPoint(p2.x() + (this->centerPoint.x() - p2.x() )/2.0f, p2.y() + (this->centerPoint.y() - p2.y())/2.0f);

    // pendiente de la mediana
    float m3 = (medianPoint.y() - p3.y())/(medianPoint.x() - p3.x());

    // calculo la interseccion de las dos rectas
    a = ((float)p3.y() - (m3 * (float)p3.x()));
    b = ((float)this->centerPoint.y() - (m2 * (float)this->centerPoint.x()));
    x = (b - a)/(m3 - m2);
    y = m3 * x + a;

    this->triangleCenter = QPoint(x,y);
}

void WardFinder::defineRegions()
{
    // defino el area del cuello del femur
    int index = this->path2->indexOf(this->minimumDistance.p2().toPoint());
    int end = this->path2->indexOf(this->base.p2().toPoint());

    for (int i=index; i <= end; i++)
        this->neckZone.push_front(this->path2->at(i));

    index = this->path1->indexOf(this->minimumDistance.p1().toPoint());
    end = this->path1->indexOf(this->base.p1().toPoint());

    for (int i=index; i <= end; i++)
        this->neckZone.push_back(this->path1->at(i));

    // defino el cuadrado de dimension n centrado en el triangulo
    this->wardZone.setRect(this->triangleCenter.x() - n/2, this->triangleCenter.y() - n/2, n, n);
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
