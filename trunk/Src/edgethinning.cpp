#include "edgethinning.h"

EdgeThinning::EdgeThinning()
{
    this->vecinos = new int[8];
}

int EdgeThinning::vecindad8(int x, int y)
{
    //this->inicVecinos(x,y);
    int cant = 0;
    //for (int i=0; i<8; i++)
    //    if (this->vecinos[i] == 255) cant++;

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

int EdgeThinning::vecindad4(int x, int y)
{
    //this->inicVecinos(x,y);
    int cant = 0;

    //for (int i=0; i<4; i++)
    //    if (this->vecinos[2*i] == 255) cant++;

    if (this->image->getColorAt(x,y-1) == 255) cant++;
    if (this->image->getColorAt(x+1,y) == 255) cant++;
    if (this->image->getColorAt(x,y+1) == 255) cant++;
    if (this->image->getColorAt(x-1,y) == 255) cant++;

    return cant;
}

int EdgeThinning::trancisiones01(int x, int y)
{
    //this->inicVecinos(x,y);
    int cant = 0;
    //for (int i=0; i<8; i++)
    //    if ((this->vecinos[i] == 0) && (this->vecinos[(i+1)%8] == 255)) cant++;

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

void EdgeThinning::inicVecinos(int x, int y)
{
    /*this->vecinos[0] = this->image->getColorAt(x,y-1);
    this->vecinos[1] = this->image->getColorAt(x+1,y-1);
    this->vecinos[2] = this->image->getColorAt(x+1,y);
    this->vecinos[3] = this->image->getColorAt(x+1,y+1);
    this->vecinos[4] = this->image->getColorAt(x,y+1);
    this->vecinos[5] = this->image->getColorAt(x-1,y+1);
    this->vecinos[6] = this->image->getColorAt(x-1,y);
    this->vecinos[7] = this->image->getColorAt(x-1,y-1);*/
}
