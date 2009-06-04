#ifndef QIMAGEPAGE_H
#define QIMAGEPAGE_H

#include <QWidget>

class QImagePage : public QWidget
{

private:
    QImage* image;
    QWidget* mainWindow;

public:
    QImagePage(QWidget* parent = 0);
    QImagePage(QImage* image, QWidget* parent = 0);

protected:
    void paintEvent(QPaintEvent*);
    //void resizeEvent(QResizeEvent*);
    void mousePressEvent(QMouseEvent*);
    //void mouseMoveEvent(QMouseEvent*);
    //void mouseReleaseEvent(QMouseEvent*);

signals:
    void moussePressed(QMouseEvent*);

};

#endif // QIMAGEPAGE_H
