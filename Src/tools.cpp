#include "tools.h"
#include "ui_tools.h"
#include "mainwindow.h"

#include <QPainter>

Tools::Tools(OsteoporosisImage* image,int tab, QWidget *parent) : QMainWindow(parent), m_ui(new Ui::Tools)
{
    m_ui->setupUi(this);
    this->image = image;
    this->result = NULL;
    this->m_ui->tabWidget->setCurrentIndex(tab);
    this->mainWindow = (MainWindow*) parent;
    this->m_ui->lbOriginal->setPixmap(QPixmap::fromImage(image->getImage()->scaled(QSize(217,187),Qt::KeepAspectRatio)));
    OsteoporosisImage *imageHisto=image->getHstogramImage();
    this->m_ui->lbHistOrig->setPixmap(QPixmap::fromImage(imageHisto->getImage()->scaled(QSize(217,187),Qt::IgnoreAspectRatio)));
    connect(this->m_ui->horizontalSlider, SIGNAL(valueChanged(int)),this,SLOT(drawFunction(int)));
    connect(this->m_ui->pbAplicarNormalizacion,SIGNAL(clicked()),this,SLOT(functionNormalize()));
    connect(this->m_ui->pbCancelar, SIGNAL(clicked()),this,SLOT(close()));
    connect(this, SIGNAL(returnImage(OsteoporosisImage*,QString)),this->mainWindow,SLOT(addModifiedImage(OsteoporosisImage*, QString)));
    this->m_ui->sb_minValue->setValue(image->getColorMin());
    this->m_ui->sb_maxValue->setValue(image->getColorMax());
    this->m_ui->spinBox->setValue(image->getMedia());

}

Tools::~Tools()
{
    delete m_ui;
}

void Tools::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void Tools::on_pbAplicarUmbral_clicked()
{
    Umbral* u = new Umbral(this->m_ui->spinBox->value());
    this->result = u->apply(this->image);
    this->descrip = new QString("Umbral " + QVariant(this->m_ui->spinBox->value()).toString());
    OsteoporosisImage* imageHis= this->result->getHstogramImage();
    this->m_ui->lbResultado->setPixmap(QPixmap::fromImage(result->getImage()->scaled(QSize(217,187),Qt::KeepAspectRatio)));
    this->m_ui->lbHistoResul->setPixmap(QPixmap::fromImage(imageHis->getImage()->scaled(QSize(217,187),Qt::IgnoreAspectRatio)));
}

void Tools::drawFunction(int umbral)
{
    QImage* image = new QImage(256,256,QImage::Format_ARGB32);
    image->fill(qRgb(255,255,255));
    QPainter* painter = new QPainter(image);
    QVector<QPoint> puntos;
    painter->setPen(QPen(QColor(0,0,200,170), 1.5, Qt::SolidLine, Qt::RoundCap));
    puntos << QPoint(0,255) << QPoint(umbral,255) << QPoint(umbral,0) << QPoint(umbral,255) << QPoint(umbral,0) << QPoint(255,0);
    painter->drawLines(puntos);
    this->m_ui->lbFuncion->setPixmap(QPixmap::fromImage(*image));
}
void Tools::functionNormalize()
{
 this->result =this->image->normalize(this->m_ui->sb_minValue->value(),this->m_ui->sb_maxValue->value());
 OsteoporosisImage* imageHis= this->result->getHstogramImage();
 this->descrip = new QString("Normalizado ");
 this->m_ui->lbResultado->setPixmap(QPixmap::fromImage(result->getImage()->scaled(QSize(217,187),Qt::KeepAspectRatio)));
 this->m_ui->lbHistoResul->setPixmap(QPixmap::fromImage(imageHis->getImage()->scaled(QSize(217,187),Qt::IgnoreAspectRatio)));
}

void Tools::on_pbAceptar_clicked()
{
    emit this->returnImage(this->result, QString(*this->descrip));
    this->close();
}
