#include "qimagepage.h"
#include <QPainter>
#include <QVariant>
#include <QMouseEvent>
#include <QDebug>

QImagePage::QImagePage(QWidget* parent) : QWidget(parent)
{
    this->image = new QImage(500,500,QImage::Format_RGB32);
    this->image->fill(qRgb(255,255,255));
    this->setMinimumSize(500,500);
    this->mainWindow = parent;
}

QImagePage::QImagePage(QImage* image, QWidget* parent) : QWidget(parent)
{
    this->image = image;
    this->setMinimumSize(image->width(),image->height());
    this->mainWindow = parent;
}

void QImagePage::paintEvent(QPaintEvent* )
{
    QPainter painter(this);
    painter.drawImage(QPoint(0,0),*this->image);
}

void QImagePage::mousePressEvent(QMouseEvent* event)
{
    //this->mainWindow->mousePressEvent(event)
}

