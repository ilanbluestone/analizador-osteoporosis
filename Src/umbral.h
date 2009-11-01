#include "transformation.h"

#ifndef UMBRAL_H
#define UMBRAL_H

class Umbral : public Transformation
{
private:
    int value;


public:
    Umbral(int value);

    void setUmbral(int value);
    int getUmbral();
    class OsteoporosisImage* apply(class OsteoporosisImage* image);
};

#endif // UMBRAL_H
