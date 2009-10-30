#include "neighborhood.h"

Neighborhood::Neighborhood()
{
}

int Neighborhood::neighborhood8(int x, int y)
{
    int cant = 0;

    if (this->image->getColorAt(x,y-1) == 255)cant++;
    if (this->image->getColorAt(x+1,y-1) == 255)cant++;
    if (this->image->getColorAt(x+1,y) == 255)cant++;
    if (this->image->getColorAt(x+1,y+1) == 255)cant++;
    if (this->image->getColorAt(x,y+1) == 255)cant++;
    if (this->image->getColorAt(x-1,y+1) == 255) cant++;
    if (this->image->getColorAt(x-1,y) == 255) cant++;
    if (this->image->getColorAt(x-1,y-1) == 255) cant++;

    return cant;
}

int Neighborhood::neighborhood4(int x, int y)
{
    int cant = 0;

    if (this->image->getColorAt(x,y-1) == 255) cant++;
    if (this->image->getColorAt(x+1,y) == 255) cant++;
    if (this->image->getColorAt(x,y+1) == 255) cant++;
    if (this->image->getColorAt(x-1,y) == 255) cant++;

    return cant;
}

int Neighborhood::trancitions01(int x, int y)
{
    int cant = 0;

    if ((this->image->getColorAt(x,y-1) == 0) && (this->image->getColorAt(x+1,y-1) == 255)) cant++;
    if ((this->image->getColorAt(x+1,y-1) == 0) && (this->image->getColorAt(x+1,y) == 255)) cant++;
    if ((this->image->getColorAt(x+1,y) == 0) && (this->image->getColorAt(x+1,y+1) == 255)) cant++;
    if ((this->image->getColorAt(x+1,y+1) == 0) && (this->image->getColorAt(x,y+1) == 255)) cant++;
    if ((this->image->getColorAt(x,y+1) == 0) && (this->image->getColorAt(x-1,y+1) == 255)) cant++;
    if ((this->image->getColorAt(x-1,y+1) == 0) && (this->image->getColorAt(x-1,y) == 255)) cant++;
    if ((this->image->getColorAt(x-1,y) == 0) && (this->image->getColorAt(x-1,y-1) == 255)) cant++;
    if ((this->image->getColorAt(x-1,y-1) == 0) && (this->image->getColorAt(x,y-1) == 255)) cant++;

    return cant;
}
