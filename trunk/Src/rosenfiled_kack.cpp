#include "rosenfiled_kack.h"

Rosenfiled_Kack::Rosenfiled_Kack(int vecinos) : EdgeThinning()
{
    this->cantVecinos = vecinos;
}

bool Rosenfiled_Kack::Norte4(int x, int y)
{
    bool resul;
    this->inicVecinos(x,y);
    resul = vecinos[2] && !vecinos[4] && vecinos[6];
    resul = resul || (vecinos[4] && !vecinos[5] && vecinos[6]);
    resul = resul || (vecinos[2] && !vecinos[3] && vecinos[4]);
    return resul;
}

bool Rosenfiled_Kack::Norte8(int x, int y)
{
    bool resul;
    this->inicVecinos(x,y);
    resul = vecinos[2] && !vecinos[4] && vecinos[6];
    resul = resul || (!vecinos[0] && vecinos[1] && !vecinos[2]);
    resul = resul || (!vecinos[2] && vecinos[3] && !vecinos[4]);
    resul = resul || (!vecinos[4] && vecinos[5] && !vecinos[6]);
    resul = resul || (!vecinos[6] && vecinos[7] && !vecinos[8]);
    return resul;
}

bool Rosenfiled_Kack::Sur4(int x, int y)
{
    bool resul;
    this->inicVecinos(x,y);
    resul = vecinos[2] && !vecinos[0] && vecinos[6];
    resul = resul || (vecinos[0] && !vecinos[1] && vecinos[2]);
    resul = resul || (vecinos[6] && !vecinos[7] && vecinos[0]);
    return resul;
}

bool Rosenfiled_Kack::Sur8(int x, int y)
{
    bool resul;
    this->inicVecinos(x,y);
    resul = vecinos[2] && !vecinos[0] && vecinos[6];
    resul = resul || (!vecinos[0] && vecinos[1] && !vecinos[2]);
    resul = resul || (!vecinos[2] && vecinos[3] && !vecinos[4]);
    resul = resul || (!vecinos[4] && vecinos[5] && !vecinos[6]);
    resul = resul || (!vecinos[6] && vecinos[7] && !vecinos[8]);
    return resul;
}

bool Rosenfiled_Kack::Este4(int x, int y)
{
    bool resul;
    this->inicVecinos(x,y);
    resul = vecinos[0] && !vecinos[6] && vecinos[4];
    resul = resul || (vecinos[4] && !vecinos[5] && vecinos[6]);
    resul = resul || (vecinos[6] && !vecinos[7] && vecinos[0]);
    return resul;
}

bool Rosenfiled_Kack::Este8(int x, int y)
{
    bool resul;
    this->inicVecinos(x,y);
    resul = vecinos[0] && !vecinos[6] && vecinos[4];
    resul = resul || (!vecinos[0] && vecinos[1] && !vecinos[2]);
    resul = resul || (!vecinos[2] && vecinos[3] && !vecinos[4]);
    resul = resul || (!vecinos[4] && vecinos[5] && !vecinos[6]);
    resul = resul || (!vecinos[6] && vecinos[7] && !vecinos[8]);
    return resul;
}

bool Rosenfiled_Kack::Oeste4(int x, int y)
{
    bool resul;
    this->inicVecinos(x,y);
    resul = vecinos[0] && !vecinos[2] && vecinos[4];
    resul = resul || (vecinos[0] && !vecinos[1] && vecinos[2]);
    resul = resul || (vecinos[2] && !vecinos[3] && vecinos[4]);
    return resul;
}

bool Rosenfiled_Kack::Oeste8(int x, int y)
{
    bool resul;
    this->inicVecinos(x,y);
    resul = vecinos[0] && !vecinos[2] && vecinos[4];
    resul = resul || (!vecinos[0] && vecinos[1] && !vecinos[2]);
    resul = resul || (!vecinos[2] && vecinos[3] && !vecinos[4]);
    resul = resul || (!vecinos[4] && vecinos[5] && !vecinos[6]);
    resul = resul || (!vecinos[6] && vecinos[7] && !vecinos[8]);
    return resul;
}

OsteoporosisImage* Rosenfiled_Kack::apply(OsteoporosisImage* image)
{
   this->image = image;
   if (this->cantVecinos == 4)
       return this->apply4();
   else
       return this->apply8();
}

OsteoporosisImage* Rosenfiled_Kack::apply4()
{
    bool modifique = true;
    int aux = 50;
    while (aux > 0){
        modifique = false;
        aux--;
        OsteoporosisImage* tempNorte = new OsteoporosisImage(image->getSize());
        for (int x=1; x<this->image->getWidth()-1; x++)
            for (int y=1; y<this->image->getHeight()-1; y++)
                if ((image->getColorAt(x,y-1) == 0) && (vecindad4(x,y) > 1) && (!Norte4(x,y)))
                {
                    tempNorte->setColorAt(x,y,0);
                    modifique = true;
                }else
                    tempNorte->setColorAt(x,y,image->getColorAt(x,y));
        OsteoporosisImage* tempSur = new OsteoporosisImage(image->getSize());
        for (int x=1; x<this->image->getWidth()-1; x++)
            for (int y=1; y<this->image->getHeight()-1; y++)
                if ((tempNorte->getColorAt(x,y+1) == 0) && (vecindad4(x,y) > 1) && (!Sur4(x,y)))
                {
                    tempSur->setColorAt(x,y,0);
                    modifique = true;
                }else
                    tempSur->setColorAt(x,y,tempNorte->getColorAt(x,y));
        OsteoporosisImage* tempEste = new OsteoporosisImage(image->getSize());
        for (int x=1; x<this->image->getWidth()-1; x++)
            for (int y=1; y<this->image->getHeight()-1; y++)
                if ((tempSur->getColorAt(x+1,y) == 0) && (vecindad4(x,y) > 1) && (!Este4(x,y)))
                {
                    tempEste->setColorAt(x,y,0);
                    modifique = true;
                }else
                    tempEste->setColorAt(x,y,tempSur->getColorAt(x,y));
        OsteoporosisImage* tempOeste = new OsteoporosisImage(image->getSize());
        for (int x=1; x<this->image->getWidth()-1; x++)
            for (int y=1; y<this->image->getHeight()-1; y++)
                if ((tempEste->getColorAt(x-1,y) == 0) && (vecindad4(x,y) > 1) && (!Oeste4(x,y)))
                {
                    tempOeste->setColorAt(x,y,0);
                    modifique = true;
                }else
                    tempOeste->setColorAt(x,y,tempEste->getColorAt(x,y));
        image = tempOeste;
    }
    return image;
}

OsteoporosisImage* Rosenfiled_Kack::apply8()
{
    return image;
}
