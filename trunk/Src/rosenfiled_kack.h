#ifndef ROSENFILED_KACK_H
#define ROSENFILED_KACK_H

#include "edgethinning.h"

class Rosenfiled_Kack : public EdgeThinning
{
private:
    int cantVecinos;

protected:
    bool Norte4(int x, int y);
    bool Norte8(int x, int y);
    bool Sur4(int x, int y);
    bool Sur8(int x, int y);
    bool Este4(int x, int y);
    bool Este8(int x, int y);
    bool Oeste4(int x, int y);
    bool Oeste8(int x, int y);
    class OsteoporosisImage* apply4();
    class OsteoporosisImage* apply8();

public:
    Rosenfiled_Kack(int vecinos);

    class OsteoporosisImage* apply(class OsteoporosisImage* image);
};

#endif // ROSENFILED_KACK_H
