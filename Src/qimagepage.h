#ifndef QIMAGEPAGE_H
#define QIMAGEPAGE_H

#include <QWidget>
#include "osteoporosisimage.h"

enum state {UNDEFINED, DRAWING, FINISHED};
enum action {NOTHING, SEL_REGION, SEL_TWARD, SEL_CP};

class QImagePage : public QWidget
{
protected:
    QList<QPoint> points;
    state currentState;
    action currentAction;

    void draw();
    void clearBoard();

private:
    OsteoporosisImage* image;
    QImage* board;
    QWidget* mainWindow;

public:
    QImagePage(QWidget* parent = 0);
    QImagePage(OsteoporosisImage* image, QWidget* parent = 0);

    OsteoporosisImage* getImage();
    void setAction(action a);

protected:
    void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);

};

#endif // QIMAGEPAGE_H
