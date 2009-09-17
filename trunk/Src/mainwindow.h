#ifndef MAINWINDOW_H

#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QTreeWidgetItem>
#include <QList>
#include "osteoporosisimage.h"
#include "qimagepage.h"

#include "filter.h"

namespace Ui
{
    class MainWindowClass;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindowClass *ui;
    QList<QTreeWidgetItem*> pageLinks;
    QList<QImagePage*> imagePages;

    void applyFilter (QString name, Filter* f);
    void applyTransformation (QString name, Transformation* t);
    void addImagePage(OsteoporosisImage* image, QString name, QTreeWidgetItem* treeElement, QIcon* icon = 0);
    void initControls();

private slots:

    void on_tbDiagnosticate_clicked();
    void on_actionUmbral_triggered();
    void on_actionEcualizacion_triggered();
    void on_actionNormalizacion_triggered();
    void openImage();
    void saveResult();
    void setCurrentPage(QTreeWidgetItem*);
    void setAction_SelRegion();
    void setAction_SelTWard();
    void setAction_SelCP();
    void addUserSelection(OsteoporosisImage*);
    void addModifiedImage(OsteoporosisImage* , QString);
    void northWest();
    void north();
    void northEast();
    void east();
    void west();
    void south();
    void southWest();
    void southEast();
    void sobel();
    void prewitt();
    void hightpass();
    void lowpass();
    void gaussiano();
    void roberts();
    void frei_chen();
    void tools(int tool);
    void erosion();
    void erosionCond();
    void dilatation();
};

#endif // MAINWINDOW_H
