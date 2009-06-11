#ifndef MAINWINDOW_H

#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QTreeWidgetItem>
#include <QList>
#include "osteoporosisimage.h"
#include "qimagepage.h"
#include <QMouseEvent>

//esto agregue yo
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
    QList<QTreeWidgetItem*> pages;
    QList<OsteoporosisImage*> images;
    //esto agregue yo
    void applyFilter (QString name, Filter* f);
    void addImagePage(OsteoporosisImage* image, QString name, QString description, QTreeWidgetItem* treeElement, QIcon* icon = 0);

    void initControls();

protected:
    void mousePressEvent(QMouseEvent *);

private slots:
    void openImage();
    void saveResult();
    void setCurrentPage(QTreeWidgetItem*);
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
    void complete();
    void hightpass();
    void lowpass();
    void roberts();
    void frei_chen();
};

#endif // MAINWINDOW_H
