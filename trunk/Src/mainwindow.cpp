#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "hightpassfilter.h"
#include "prewittfilter.h"
#include "sobelfilter.h"
#include "southfilter.h"
#include "northfilter.h"
#include "northwestfilter.h"
#include "northeastfilter.h"
#include "eastfilter.h"
#include "westfilter.h"
#include "southwestfilter.h"
#include "southeastfilter.h"
#include "osteoporosisimage.h"

#include <QFileDialog>
#include <QString>
#include <QScrollArea>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindowClass)
{
    this->ui->setupUi(this);
    this->initControls();
}

void MainWindow::initControls()
{
    connect(this->ui->actionAbrir_imagen,SIGNAL(triggered()),this,SLOT(openImage()));
    connect(this->ui->actionGuardar_resultados,SIGNAL(triggered()),this,SLOT(saveResult()));
    connect(this->ui->actionSalir,SIGNAL(triggered()),this,SLOT(close()));
    connect(this->ui->treeWidget,SIGNAL(itemClicked(QTreeWidgetItem*,int)),this,SLOT(setCurrentPage(QTreeWidgetItem*)));
    //aca modifique yo

    connect(this->ui->actionNoroeste,SIGNAL(triggered()),this,SLOT(northWest()));
    connect(this->ui->actionNoreste,SIGNAL(triggered()),this,SLOT(northEast()));
    connect(this->ui->actionNorte,SIGNAL(triggered()),this,SLOT(north()));
    connect(this->ui->actionSur,SIGNAL(triggered()),this,SLOT(south()));
    connect(this->ui->actionSureste,SIGNAL(triggered()),this,SLOT(southWest()));
    connect(this->ui->actionSuroeste,SIGNAL(triggered()),this,SLOT(southEast()));
    connect(this->ui->actionEste,SIGNAL(triggered()),this,SLOT(east()));
    connect(this->ui->actionOeste,SIGNAL(triggered()),this,SLOT(west()));
    connect(this->ui->actionPrewitt,SIGNAL(triggered()),this,SLOT(prewitt()));
    connect(this->ui->actionSobel,SIGNAL(triggered()),this,SLOT(sobel()));
    connect(this->ui->actionCompleto,SIGNAL(triggered()),this,SLOT(complete()));
}

//esto lo agregue yo
void MainWindow::north()
{
    Filter* f= new NorthFilter();
    this->applyFilter("Filtro Norte",f);
}
void MainWindow::south()
{
    Filter* f= new SouthFilter();
    this->applyFilter("Filtro Sur",f);
}
void MainWindow::southEast()
{
    Filter* f= new SouthEastFilter();
    this->applyFilter("Filtro Sureste",f);
}
void MainWindow::southWest()
{
    Filter* f= new SouthWestFilter();
    this->applyFilter("Filtro Suroeste",f);
}
void MainWindow::northEast()
{
    Filter* f= new NorthEastFilter();
    this->applyFilter("Filtro Noreste",f);
}
void MainWindow::northWest()
{
    Filter* f= new NorthWestFilter();
    this->applyFilter("Filtro Noroeste",f);
}

void MainWindow::complete()
{

}
void MainWindow::east()
{
    Filter* f= new EastFilter();
    this->applyFilter("Filtro Este",f);
}
void MainWindow::west()
{
    Filter* f= new WestFilter();
    this->applyFilter("Filtro Oeste",f);
}
void MainWindow::sobel()
{
    Filter* f= new SobelFilter();
    this->applyFilter("Filtro Sobel",f);
}
void MainWindow::prewitt()
{
    Filter* f= new PrewittFilter();
    this->applyFilter("Filtro Prewitt",f);
}

void MainWindow::saveResult()
{ /*
    QTreeWidgetItem* padre = this->pages.at(this->ui->stackedWidget->currentIndex()-1);
    QTreeWidgetItem* nuevo = new QTreeWidgetItem(padre);
    //name
    nuevo->setText(1,"Aplicado filtro paso alto");

    nuevo->setText(0,padre->text(0)+tr(" + filtro"));
    HightPassFilter* transformation = new HightPassFilter();
    OsteoporosisImage* image = this->images.at(this->ui->stackedWidget->currentIndex()-1);
    OsteoporosisImage* newImage = image->transform(new HightPassFilter());
    this->images.push_back(newImage);
    QScrollArea* scrollArea = new QScrollArea(this->ui->stackedWidget);
    QImagePage* page = new QImagePage(newImage->getImage(),scrollArea);
    scrollArea->setWidget(page);
    this->ui->stackedWidget->addWidget(scrollArea);
    this->ui->stackedWidget->setCurrentWidget(scrollArea);
    this->pages.push_back(nuevo);*/

    //nuevo->setIcon(0,QIcon(QPixmap(image->getImage()->));
}

//esto agregue yo
void MainWindow::applyFilter (QString name,Filter* f)
{
    QTreeWidgetItem* father = this->pages.at(this->ui->stackedWidget->currentIndex()-1);
    QTreeWidgetItem* newElement = new QTreeWidgetItem(father);
    OsteoporosisImage* image = this->images.at(this->ui->stackedWidget->currentIndex()-1);
    OsteoporosisImage* newImage = image->transform(f);
    this->images.push_back(newImage);
    this->addImagePage(newImage, name, "Imagen con filtro aplicado", newElement);
}

void MainWindow::openImage()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Abrir imagen..."),"/home",tr("Images (*.png *.bmp *.jpg)"));
    if (!fileName.isEmpty()){
        OsteoporosisImage* image = new OsteoporosisImage(fileName);
        this->images.push_back(image);
        QIcon* icon = new QIcon(fileName);
        QTreeWidgetItem* treeElement = new QTreeWidgetItem(this->ui->treeWidget);
        this->addImagePage(image, fileName, "Versión original de la imagen", treeElement, icon);
    }
}

void MainWindow::addImagePage(OsteoporosisImage *image, QString name, QString description, QTreeWidgetItem* treeElement, QIcon* icon)
{
    QScrollArea* scrollArea = new QScrollArea(this->ui->stackedWidget);
    QImagePage* page = new QImagePage(image->getImage(),scrollArea);
    scrollArea->setWidget(page);
    this->ui->stackedWidget->addWidget(scrollArea);
    this->ui->stackedWidget->setCurrentWidget(scrollArea);
    this->pages.push_back(treeElement);
    treeElement->setText(0,name);
    if (icon) treeElement->setIcon(0,*icon);
    treeElement->setText(1,QString().fromLocal8Bit(description.toLatin1().data()));

}

void MainWindow::setCurrentPage(QTreeWidgetItem* item)
{
    int position = this->pages.indexOf(item) + 1;
    if (position != 0) this->ui->stackedWidget->setCurrentIndex(position);
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    QPoint p(e->x(),e->y());
    qDebug() << p;

}

MainWindow::~MainWindow()
{
    delete ui;
}

