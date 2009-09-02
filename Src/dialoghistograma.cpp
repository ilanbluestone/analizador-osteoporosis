#include "dialoghistograma.h"
#include <QDebug>
#include "ui_dialoghistograma.h"

DialogHistograma::DialogHistograma(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::DialogHistograma)
{
    m_ui->setupUi(this);
}


DialogHistograma::~DialogHistograma()
{
    delete m_ui;
}

void DialogHistograma::setImage(OsteoporosisImage* i)
{
    image=i;
}

void DialogHistograma::getCount()
{
    this->counter = image->getHistogram();
}

void DialogHistograma::initCount()
{
    counter= new long[256];
    for (int i=0; i<256;i++)
         counter[i]=0;
}

long DialogHistograma::getcounterMax()
{
    long max;
    max =counter[0];

        for (int i=1; i < 256; i++)
        {
            long aux=counter[i];
            if (max < aux) max = aux;
        }
    return max;
}


void DialogHistograma::paintEvent(QPaintEvent *)
{
   QPainter painter(this);

    //Preparo el fondo
    painter.fillRect(15,15,672,462,QColor(255,255,255));
    painter.drawText(20,33,"# Colores");
    painter.drawText(550,472,"x=valor del pixel");

        //Eje X
    QLine xAxis(20,450,670,450);
    painter.drawLine(xAxis);

    //Eje Y
    QLine yAxis(110,470,110,20);
    painter.drawLine(yAxis);
    //Punto 1
    int x1=40;
    //Punto 2
    int x2=670;
    int  y=450;
    //Largo X
    //int  x_size=630;
    //Largo Y
    int y_size=450;


    //Factor de Separacion
    int space = 40;

    //Obtengo el maximo para escalar
    this->getCount();
    long maximo = getcounterMax();
    //eso es una prueba
    int maximoColor=image->getColorMax();
    int minimoColor=image->getColorMin();
    int media=image->getMedia();
    painter.drawText(222,472,QString::number(maximoColor));
    painter.drawText(111,472,QString::number(minimoColor));
    painter.drawText(333,472,QString::number(media));
    //Factor de Escala
    float etiqEscala = ((float) maximo / (y_size / space));
    float factor = 0;

    //Grafico las lineas de escala con el factor space correspondiente
    while(y_size >= 0)
    {
        if(y_size - space >= 0)
        {
            painter.drawText(20,y_size,QString::number(factor));
            factor+=etiqEscala;
        }

        QLine line(QPoint(x1,y_size),QPoint(x2,y_size));
        painter.drawLine(line);
        y_size -= space;

    }

    //Grafico los valores escala de x
    int color = 0;
    int i = 111;
   while(color <= 255)
    {
        painter.drawText(i,y+10,QString::number(color));
        color+=15;
        i +=30;
    }

    //Grafico el Histograma

    QPen pen(QColor(100,100,255));
    painter.setPen(pen);
    int sep = 2;
    int j = 0;
    for(int i = 0; i < 256; i++)
    {
        for(int x=0;x<sep;x++){
            painter.drawLine(j+x+111,y,j+x+111,450 - ( counter[i] * 420 / maximo));

        }
         j +=sep;
    }
}





void DialogHistograma::changeEvent(QEvent *e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
