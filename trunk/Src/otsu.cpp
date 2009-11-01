#include "otsu.h"

Otsu::Otsu()
{
}

int Otsu::getOptimalValue(long* frequencyVector)
{
    float probabilityVector[256];
    long N = 0;

    for (int i = 0; i < 256; i++)
        N += frequencyVector[i];

    for (int i = 0; i < 256; i++)
        probabilityVector[i] = (float)frequencyVector[i] / (float)N;

    int tMax = 0;
    float vMax = -1;

    for (int t = 0; t < 255; t++)
    {
        float u1, u2, v, w1, w2, uT;

        u1 = u2 = w1 = w2 = 0;

        // calculo la suma de los (i * Pi) del primer grupo y su w1(t)
        for (int i = 0; i <= t; i++)
        {
            u1 += (i+1) * probabilityVector[i];
            w1 += probabilityVector[i];
        }

        // calculo uT parcialmente y calculo la media (u1) del primer grupo
        uT = u1;
        u1 = u1/w1;

        // calculo la suma de los (i * Pi) del segundo grupo y su w2(t)
        for (int i = t+1; i < 256; i++)
        {
            u2 += (i+1) * probabilityVector[i];
            w2 += probabilityVector[i];
        }

        // calculo uT y calculo la media (u2) del segundo grupo
        uT += u2;
        u2 = u2/w2;

        // calculo la varianza definida por Otsu
        v = w1 * (u1 - uT) * (u1 - uT) + w2 * (u2 - uT) * (u2 - uT);

        // me quedo con la varianza mas grande y su nivel de gris correspondiente
        if (v >= vMax)
        {
            vMax = v;
            tMax = t;
        }
    }

    return tMax;
}
