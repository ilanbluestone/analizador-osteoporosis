#ifndef TOOLS_H
#define TOOLS_H

#include <QtGui/QMainWindow>
#include "umbral.h"

namespace Ui {
    class Tools;
}

class MainWindow;

class Tools : public QMainWindow {
    Q_OBJECT
    Q_DISABLE_COPY(Tools)
public:
    explicit Tools(OsteoporosisImage* image, int tab, QWidget *parent = 0);
    virtual ~Tools();

protected:
    virtual void changeEvent(QEvent *e);

private:
    Ui::Tools *m_ui;
    OsteoporosisImage* image;
    OsteoporosisImage* result;
    QString* descrip;
    MainWindow* mainWindow;

private slots:
    void on_pbAceptar_clicked();
    void on_pbAplicarUmbral_clicked();
    void drawFunction(int umbral);
    void functionNormalize();

signals:
    void returnImage(OsteoporosisImage*, QString);
};

#endif // TOOLS_H
