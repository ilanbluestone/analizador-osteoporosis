#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "hightpassfilter.h"
#include "lowpassfilter.h"
#include "prewittfilter.h"
#include "robertsfilter.h"
#include "frei_chen.h"
#include "sobelfilter.h"
#include "southfilter.h"
#include "northfilter.h"
#include "northwestfilter.h"
#include "northeastfilter.h"
#include "eastfilter.h"
#include "westfilter.h"
#include "southwestfilter.h"
#include "southeastfilter.h"
#include "gaussianofilter.h"
#include "osteoporosisimage.h"
#include "dialoghistograma.h"
#include "tools.h"
#include "erosion.h"
#include "conditionalerosion.h"
#include "dilatation.h"
#include "rosenfiled_kack.h"
#include "hilditch.h"
#include "median.h"
#include "wardfinder.h"

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
    connect(this->ui->actionPaso_Alto,SIGNAL(triggered()),this,SLOT(hightpass()));
    connect(this->ui->actionPaso_Bajo,SIGNAL(triggered()),this,SLOT(lowpass()));
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
    connect(this->ui->actionGaussiano,SIGNAL(triggered()),this,SLOT(gaussiano()));
    connect(this->ui->actionErosion,SIGNAL(triggered()),this,SLOT(erosion()));
    connect(this->ui->actionErosi_n_condicional,SIGNAL(triggered()),this,SLOT(erosionCond()));
    connect(this->ui->actionEsqueletizacion,SIGNAL(triggered()),this,SLOT(skeleton()));
    connect(this->ui->actionDilatacion,SIGNAL(triggered()),this,SLOT(dilatation()));
    connect(this->ui->actionRoberts,SIGNAL(triggered()),this,SLOT(roberts()));
    connect(this->ui->actionFrei_Chen,SIGNAL(triggered()),this,SLOT(frei_chen()));
    connect(this->ui->tbSelectZone,SIGNAL(pressed()),this,SLOT(setAction_SelRegion()));
    connect(this->ui->tbSelectTWard,SIGNAL(pressed()),this,SLOT(setAction_SelTWard()));
    connect(this->ui->tbSelectCP,SIGNAL(pressed()),this,SLOT(setAction_SelCP()));
    connect(this->ui->actionBuscar_Ward,SIGNAL(triggered()),this,SLOT(ward()));
    connect(this->ui->treeWidget,SIGNAL(itemClicked(QTreeWidgetItem*,int)),this,SLOT(setCurrentPage(QTreeWidgetItem*)));
}

void MainWindow::north()
{
    Filter* f= new MedianFilter();
    this->applyFilter("mediana",f);

    //Filter* f= new NorthFilter();
    //this->applyFilter("Filtro Norte",f);
}

void MainWindow::tools(int tool){
    Tools* dialog = new Tools(this->imagePages.at(this->ui->stackedWidget->currentIndex()-1)->getImage(),tool, this);
    dialog->show();
}

void MainWindow::ward()
{
    if (!this->imagePages.empty()){
        QTreeWidgetItem* father = this->pageLinks.at(this->ui->stackedWidget->currentIndex()-1);
        QTreeWidgetItem* newElement = new QTreeWidgetItem(father);
        OsteoporosisImage* image = this->imagePages.at(this->ui->stackedWidget->currentIndex()-1)->getImage();
        WardFinder* w= new WardFinder();
        w->findPaths(image);
        OsteoporosisImage* newImage = w->getPaths();
        this->addImagePage(newImage, "caminos", newElement);
    }

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

void MainWindow::hightpass()
{
    Filter* f= new HightPassFilter();
    this->applyFilter("Filtro Paso Alto",f);
}

void MainWindow::lowpass()
{
    Filter* f= new LowPassFilter();
    this->applyFilter("Filtro Paso Bajo",f);
}

void MainWindow::gaussiano()
{
    Filter* f= new GaussianoFilter();
    this->applyFilter("Filtro Gaussiano",f);
}

void MainWindow::frei_chen()
{
    Filter* f= new Frei_ChenFilter();
    this->applyFilter("Filtro Frei-Chen",f);
}

void MainWindow::roberts()
{
    Filter* f= new RobertsFilter();
    this->applyFilter("Filtro Roberts",f);
}

void MainWindow::erosion()
{
    Transformation* t= new Erosion();
    this->applyTransformation("Erosion",t);
}

void MainWindow::erosionCond()
{
    Transformation* t= new ConditionalErosion();
    this->applyTransformation("Erosion",t);
}

void MainWindow::skeleton()
{
    Transformation* t= new Hilditch();//new Rosenfiled_Kack(4);
    this->applyTransformation("Esqueleto",t);
}

void MainWindow::dilatation()
{
    Transformation* t= new Dilatation();
    this->applyTransformation("Dilatación",t);
}

void MainWindow::saveResult()
{
    int position = this->pageLinks.indexOf(this->ui->treeWidget->currentItem());
    OsteoporosisImage* image = this->imagePages.at(position)->getImage();
    QString fileName = QFileDialog::getSaveFileName(this,tr("Guardar imagen..."),tr("/home"),tr("Imágenes (*.png *.bmp *.jpg)"));
    if (!fileName.isEmpty()) image->saveAs(fileName);
}

void MainWindow::applyFilter (QString name,Filter* f)
{
    if (!this->imagePages.empty()){
        QTreeWidgetItem* father = this->pageLinks.at(this->ui->stackedWidget->currentIndex()-1);
        QTreeWidgetItem* newElement = new QTreeWidgetItem(father);
        OsteoporosisImage* image = this->imagePages.at(this->ui->stackedWidget->currentIndex()-1)->getImage();
        OsteoporosisImage* newImage = image->transform(f);
        this->addImagePage(newImage, name, newElement);
    }
}

void MainWindow::applyTransformation (QString name, Transformation* t)
{
    if (!this->imagePages.empty()){
        QTreeWidgetItem* father = this->pageLinks.at(this->ui->stackedWidget->currentIndex()-1);
        QTreeWidgetItem* newElement = new QTreeWidgetItem(father);
        OsteoporosisImage* image = this->imagePages.at(this->ui->stackedWidget->currentIndex()-1)->getImage();
        OsteoporosisImage* newImage = image->transform(t);
        this->addImagePage(newImage, name, newElement);
    }
}

void MainWindow::openImage()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Abrir imagen..."),tr("/home"),tr("Imágenes (*.png *.bmp *.jpg)"));
    if (!fileName.isEmpty()){
        OsteoporosisImage* image = new OsteoporosisImage(fileName);
        QIcon* icon = new QIcon(fileName);
        QTreeWidgetItem* treeElement = new QTreeWidgetItem(this->ui->treeWidget);
        this->addImagePage(image, fileName, treeElement, icon);
    }
}

void MainWindow::addUserSelection(OsteoporosisImage* selection)
{
    QTreeWidgetItem* father = this->pageLinks.at(this->ui->stackedWidget->currentIndex()-1);
    QTreeWidgetItem* newElement = new QTreeWidgetItem(father);
    this->addImagePage(selection,"Recorte", newElement);
}

void MainWindow::addModifiedImage(OsteoporosisImage* image, QString name)
{
    QTreeWidgetItem* father = this->pageLinks.at(this->ui->stackedWidget->currentIndex()-1);
    QTreeWidgetItem* newElement = new QTreeWidgetItem(father);
    this->addImagePage(image, name, newElement);
}

void MainWindow::addImagePage(OsteoporosisImage *image, QString name, QTreeWidgetItem* treeElement, QIcon* icon)
{
    QScrollArea* scrollArea = new QScrollArea(this->ui->stackedWidget);
    QImagePage* page = new QImagePage(image,this,scrollArea);
    scrollArea->setWidget(page);
    this->imagePages.push_back(page);
    this->ui->stackedWidget->addWidget(scrollArea);
    this->ui->stackedWidget->setCurrentWidget(scrollArea);
    this->pageLinks.push_back(treeElement);
    treeElement->setText(0,QString().fromLocal8Bit(name.toLatin1().data()));
    if (icon) treeElement->setIcon(0,*icon);
    this->ui->treeWidget->setCurrentItem(treeElement);
}

void MainWindow::setCurrentPage(QTreeWidgetItem *item)
{
    int position = this->pageLinks.indexOf(item);
    if (position != -1) this->ui->stackedWidget->setCurrentIndex(position+1);
}

void MainWindow::setAction_SelRegion()
{
    int position = this->pageLinks.indexOf(this->ui->treeWidget->currentItem());
    if (position != -1){
        QImagePage* page = this->imagePages.at(position);
        page->setAction(SEL_REGION);
    }
}

void MainWindow::setAction_SelTWard()
{
    int position = this->pageLinks.indexOf(this->ui->treeWidget->currentItem());
    if (position != -1){
        QImagePage* page = this->imagePages.at(position);
        page->setAction(SEL_TWARD);
    }
}

void MainWindow::setAction_SelCP()
{
    int position = this->pageLinks.indexOf(this->ui->treeWidget->currentItem());
    if (position != -1){
        QImagePage* page = this->imagePages.at(position);
        page->setAction(SEL_CP);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_tbDiagnosticate_clicked()
{
}

void MainWindow::on_actionUmbral_triggered()
{
    this->tools(0);
}

void MainWindow::on_actionNormalizacion_triggered()
{
    this->tools(1);
}

void MainWindow::on_actionEcualizacion_triggered()
{
    this->tools(3);
}
