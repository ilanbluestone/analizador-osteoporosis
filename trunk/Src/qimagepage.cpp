#include "qimagepage.h"
#include <QPainter>
#include <QVariant>
#include <QMouseEvent>
#include <QDebug>
#include "mainwindow.h"

QImagePage::QImagePage(MainWindow* mainWindow, QWidget* parent) : QWidget(parent)
{
    this->image = new OsteoporosisImage(QSize(500,500));
    this->board = new QImage(500,500,QImage::Format_ARGB32);
    this->board->fill(qRgba(0,0,0,0));
    this->setMinimumSize(500,500);
    this->currentAction = NOTHING;
    this->currentState = UNDEFINED;
    this->mainWindow = mainWindow;
    connect(this,SIGNAL(returnSelection(OsteoporosisImage*)),this->mainWindow,SLOT(addUserSelection(OsteoporosisImage*)));
}

QImagePage::QImagePage(OsteoporosisImage* image, MainWindow* mainWindow, QWidget* parent) : QWidget(parent)
{
    this->image = image;
    this->setMinimumSize(image->getWidth(),image->getHeight());
    this->board = new QImage(image->getWidth(),image->getHeight(),QImage::Format_ARGB32);
    this->board->fill(qRgba(0,0,0,0));
    this->currentAction = NOTHING;
    this->currentState = UNDEFINED;
    this->mainWindow = mainWindow;
    connect(this,SIGNAL(returnSelection(OsteoporosisImage*)),this->mainWindow,SLOT(addUserSelection(OsteoporosisImage*)));
}

void QImagePage::paintEvent(QPaintEvent* )
{
    QPainter painter(this);
    painter.drawImage(QPoint(0,0),*(this->image->getImage()));
    painter.drawImage(QPoint(0,0),*(this->board));
}

void QImagePage::mousePressEvent(QMouseEvent* event)
{
    switch (this->currentAction)
    {
        case NOTHING: break;
        case SEL_REGION:{
                        if (this->currentState == UNDEFINED){
                            this->points.push_back(event->pos());
                            this->points.push_back(event->pos());
                            this->currentState = DRAWING;
                        }
                    } break;
        case SEL_TWARD: break;
        case SEL_CP: break;
    }
}

void QImagePage::mouseMoveEvent(QMouseEvent* event)
{
    switch (this->currentAction)
    {
        case NOTHING: break;
        case SEL_REGION:{
                        if (this->currentState == DRAWING){
                            this->points.pop_back();
                            this->points.push_back(event->pos());
                            this->draw();
                        }
                    } break;
        case SEL_TWARD: break;
        case SEL_CP: break;
    }
    update();
}

void QImagePage::mouseReleaseEvent(QMouseEvent* )
{
    switch (this->currentAction)
    {
        case NOTHING: break;
        case SEL_REGION:{
                        OsteoporosisImage* selection = this->image->cut(this->points.first(),this->points.last());
                        this->clearBoard();
                        this->points.clear();
                        this->currentState = UNDEFINED;
                        emit this->returnSelection(selection);
                    } break;
        case SEL_TWARD: break;
        case SEL_CP: break;
    }
}

OsteoporosisImage* QImagePage::getImage()
{
    return this->image;
}

void QImagePage::setAction(action a)
{
    this->currentAction = a;
}

void QImagePage::draw()
{
    switch (this->currentAction)
    {
        case NOTHING: break;
        case SEL_REGION:{
                        this->board->fill(qRgba(0,0,0,0));
                        QPainter painter(board);
                        painter.setBrush(QBrush(Qt::red, Qt::BDiagPattern));
                        painter.setPen(QPen(Qt::red, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
                        painter.drawRect(QRect(this->points.first(),this->points.last()));
                    } break;
        case SEL_TWARD: break;
        case SEL_CP: break;
    }
}

void QImagePage::clearBoard()
{
    this->board->fill(qRgba(0,0,0,0));
}

