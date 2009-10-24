#include "wardfinder.h"
#include <QPainter>
#include </usr/include/math.h>

WardFinder::WardFinder()
{
    this->path1 = new QList<QPoint>;
    this->path2 = new QList<QPoint>;
}

void WardFinder::findPaths(OsteoporosisImage* image)
{
    this->paths = new OsteoporosisImage(image->getSize());
    paths->fill(0);
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

OsteoporosisImage* WardFinder::getPaths()
{
    OsteoporosisImage* resul = new OsteoporosisImage(this->paths->getSize());
    resul->fill(0);
    for (int i=0; i < this->path1->size(); i++)
        resul->setColorAt(this->path1->at(i).x(),this->path1->at(i).y(),255);
    for (int i=0; i < this->path2->size(); i++)
        resul->setColorAt(this->path2->at(i).x(),this->path2->at(i).y(),255);
    QImage *i = resul->getImage();
    QPainter painter(i);
    painter.setPen(QColor(255,0,0));
    painter.drawLine(this->minimumDistance);
    painter.setPen(QColor(0,255,0));
    painter.drawEllipse(this->centerPoint,3,3);
    resul->setImage(i);
    return resul;
}

QList<QPoint> WardFinder::neighbords(int x, int y, OsteoporosisImage* image)
{
    QList<QPoint> points;
    if ((image->getColorAt(x,y-1) == 255) and (this->paths->getColorAt(x,y-1) != 255))
        points.push_front(QPoint(x,y-1));
    if ((image->getColorAt(x+1,y-1) == 255) and (this->paths->getColorAt(x+1,y-1) != 255))
        points.push_front(QPoint(x+1,y-1));
    if ((image->getColorAt(x+1,y) == 255) and (this->paths->getColorAt(x+1,y) != 255))
        points.push_front(QPoint(x+1,y));
    if ((image->getColorAt(x+1,y+1) == 255) and (this->paths->getColorAt(x+1,y+1) != 255))
        points.push_front(QPoint(x+1,y+1));
    if ((image->getColorAt(x,y+1) == 255) and (this->paths->getColorAt(x,y+1) != 255))
        points.push_front(QPoint(x,y+1));
    if ((image->getColorAt(x-1,y+1) == 255) and (this->paths->getColorAt(x-1,y+1) != 255))
        points.push_front(QPoint(x-1,y+1));
    if ((image->getColorAt(x-1,y) == 255) and (this->paths->getColorAt(x-1,y) != 255))
        points.push_front(QPoint(x-1,y));
    if ((image->getColorAt(x-1,y-1) == 255) and (this->paths->getColorAt(x-1,y-1) != 255))
        points.push_front(QPoint(x-1,y-1));
    return points;
}

void WardFinder::checkOff(int x, int y, OsteoporosisImage* image, bool* path, QList<QPoint> *list)
{
    if (y == image->getHeight()-1)
    {
        list->push_back(QPoint(x,y));
        this->paths->setColorAt(x,y,255);
        *path = true;
    }
    else
    {
        list->push_back(QPoint(x,y));
        this->paths->setColorAt(x,y,255);
        QList<QPoint> neighbord = this->neighbords(x,y,image);
        for (int i = 0; i < neighbord.size() and !(*path); i++)
        {
                checkOff(((QPoint) neighbord.at(i)).x(), ((QPoint) neighbord.at(i)).y(), image, path, list);
        }
        if (!(*path))
        {
            list->pop_back();
            this->paths->setColorAt(x,y,0);
        }
    }
}

void WardFinder::findPoints()
{
    QLine aux;
    float distance = 8888888;
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
    //this->wardTriangle.push_back(
    this->centerPoint = QPoint(this->minimumDistance.x1() + (this->minimumDistance.dx()/2), this->minimumDistance.y1() + (this->minimumDistance.dy()/2));
}
