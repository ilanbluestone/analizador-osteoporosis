#ifndef DIALOGHISTOGRAMA_H
#define DIALOGHISTOGRAMA_H
#include <QPainter>
#include <QPen>
#include <QColor>
#include <QtGui/QDialog>

namespace Ui {
    class DialogHistograma;
}

class DialogHistograma : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(DialogHistograma)
public:
    explicit DialogHistograma(QWidget *parent = 0);
    virtual ~DialogHistograma();
    void setAvgs(float *);
    float getAvgsMax();

protected:
    void paintEvent(QPaintEvent *);

protected:
    virtual void changeEvent(QEvent *e);

private:
    Ui::DialogHistograma *m_ui;
    float * avgs;
};

#endif // DIALOGHISTOGRAMA_H
