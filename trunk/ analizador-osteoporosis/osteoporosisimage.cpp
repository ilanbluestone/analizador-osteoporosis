#include "osteoporosisimage.h"

void OsteoporosisImage::load(QString s){
    image.load(s);
}

void OsteoporosisImage::save(QString s){
    image.save(s);
}

OsteoporosisImage *OsteoporosisImage::transform(Transformation* t){
    return t->aplicar(this);
}

OsteoporosisImage::OsteoporosisImage(){
}
