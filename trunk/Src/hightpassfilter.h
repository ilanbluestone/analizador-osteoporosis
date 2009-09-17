#ifndef HIGHTPASSFILTER_H
#define HIGHTPASSFILTER_H

#include "filter.h"


class HightPassFilter : public Filter
{
private:

    Matrix* getPonderationMatrix(OsteoporosisImage *image);
    int getPonderation(int i, int j,OsteoporosisImage* image,int minc, int maxc,int media);
   // class OsteoporosisImage* normalize(Matrix* values);

protected:



public:
    HightPassFilter();
    ~HightPassFilter();
     class OsteoporosisImage* apply(class OsteoporosisImage* image);


};

#endif // HIGHTPASSFILTER_H
