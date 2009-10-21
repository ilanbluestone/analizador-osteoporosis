#ifndef WARDFINDER_H
#define WARDFINDER_H

#include "osteoporosisimage.h"
#include <QPoint>
#include <QList>

class WardFinder
{
private:
    OsteoporosisImage* paths;

    void checkOff(int x, int y, OsteoporosisImage* image, bool* path);
    QList<QPoint> neighbords(int x, int y, OsteoporosisImage* image);

public:
    WardFinder();

    void findPaths(OsteoporosisImage* image);
    OsteoporosisImage* getPaths();

};

#endif // WARDFINDER_H
