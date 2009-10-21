#include "wardfinder.h"

WardFinder::WardFinder()
{
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
            this->checkOff(x,0,image,&f);
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
            this->checkOff(image->getWidth()-1,y,image,&f);
            find = f;
        }
    }

}

OsteoporosisImage* WardFinder::getPaths()
{
    return this->paths->clone();
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

void WardFinder::checkOff(int x, int y, OsteoporosisImage* image, bool* path)
{
    if (y == image->getHeight()-1)
    {
        this->paths->setColorAt(x,y,255);
        *path = true;
    }
    else
    {
        this->paths->setColorAt(x,y,255);
        QList<QPoint> neighbord = this->neighbords(x,y,image);
        for (int i = 0; i < neighbord.size() and !(*path); i++)
        {
                checkOff(((QPoint) neighbord.at(i)).x(), ((QPoint) neighbord.at(i)).y(), image, path);
        }
        if (!(*path)) this->paths->setColorAt(x,y,0);
    }
}
