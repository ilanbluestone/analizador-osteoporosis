#ifndef UMBRAL_H
#define UMBRAL_H

#include <QImage>

class Umbral
{
private:
    int nivel;

public:
    Umbral();
    Umbral(int valor);

    QImage* aplicar(QImage* imagen);
};

#endif // UMBRAL_H
