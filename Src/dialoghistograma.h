#ifndef DIALOGHISTOGRAMA_H
#define DIALOGHISTOGRAMA_H
#include <QPainter>
#include <QPen>
#include <QColor>
#include <QtGui/QDialog>
#include "osteoporosisimage.h"


namespace Ui {
    class DialogHistograma;
}

class DialogHistograma : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(DialogHistograma)

 public:
    explicit DialogHistograma(QWidget *parent = 0);
    virtual ~DialogHistograma();
    long getcounterMax();

    void setImage(OsteoporosisImage* i);
    void getCount();


protected:
    void paintEvent(QPaintEvent *);
    virtual void changeEvent(QEvent *e);

private:
    long* counter;

    void initCount();
    Ui::DialogHistograma *m_ui;
    OsteoporosisImage* image;

};

#endif // DIALOGHISTOGRAMA_H
