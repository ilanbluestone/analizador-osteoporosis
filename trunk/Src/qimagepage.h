#ifndef QIMAGEPAGE_H
#define QIMAGEPAGE_H

#include <QWidget>
#include "osteoporosisimage.h"


enum state {UNDEFINED, DRAWING, FINISHED};
enum action {NOTHING, SEL_REGION};

class MainWindow;

class QImagePage : public QWidget
{
    Q_OBJECT

protected:
    QList<QPoint> points;
    state currentState;
    action currentAction;

    void draw();
    void clearBoard();
    void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);

private:
    OsteoporosisImage* image;
    QImage* board;
    MainWindow* mainWindow;

public:
    QImagePage(MainWindow* mainWindow, QWidget* parent = 0);
    QImagePage(OsteoporosisImage* image, MainWindow* mainWindow, QWidget* parent = 0);

    OsteoporosisImage* getImage();
    void setAction(action a);

signals:
    void returnSelection(OsteoporosisImage*);

};

#endif // QIMAGEPAGE_H
