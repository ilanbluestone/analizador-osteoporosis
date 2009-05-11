#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindowClass)
{
    ui->setupUi(this);
       this->initControls();
}

void MainWindow::initControls()
{
    connect(this->ui->actionAbrir_imagen,SIGNAL(triggered()),this,SLOT(openImage()));
    connect(this->ui->actionGuardar_resultados,SIGNAL(triggered()),this,SLOT(saveResult()));
    connect(this->ui->actionSalir,SIGNAL(triggered()),this,SLOT(close()));
}

void MainWindow::saveResult(){

}

void MainWindow::openImage(){
}

MainWindow::~MainWindow()
{
    delete ui;
}
