/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Thu Jun 4 13:01:28 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStackedWidget>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QToolButton>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *actionAbrir_imagen;
    QAction *actionGuardar_resultados;
    QAction *actionSalir;
    QAction *actionPaso_Alto;
    QAction *actionPaso_Bajo;
    QAction *actionEste;
    QAction *actionOeste;
    QAction *actionNorte;
    QAction *actionSur;
    QAction *actionSuroeste;
    QAction *actionSureste;
    QAction *actionNoroeste;
    QAction *actionNoreste;
    QAction *actionRoberts;
    QAction *actionSobel;
    QAction *actionPrewitt;
    QAction *actionFrei_Chen;
    QAction *actionCompleto;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    QWidget *stackedWidgetPage1;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tabWidgetPage1;
    QFormLayout *formLayout;
    QLabel *label_2;
    QToolButton *tbSelectCu;
    QLabel *label_3;
    QToolButton *tbSelectZone;
    QToolButton *tbApplyFilter;
    QToolButton *tbDetectBorders;
    QLabel *lbFiltroPA;
    QLabel *lbBordes;
    QToolButton *tbSelectTWard;
    QLabel *label;
    QLabel *label_4;
    QToolButton *tbSelectCP;
    QToolButton *tbDiagnosticate;
    QLabel *label_5;
    QWidget *tabWidgetPage2;
    QTreeWidget *treeWidget;
    QMenuBar *menuBar;
    QMenu *menu_Archivo;
    QMenu *menuFiltros;
    QMenu *menuDeteccion_de_bordes;
    QMenu *menuDireccionales;
    QMenu *menuBasadas_en_gradiente;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QString::fromUtf8("MainWindowClass"));
        MainWindowClass->resize(800, 600);
        MainWindowClass->setMinimumSize(QSize(691, 418));
        actionAbrir_imagen = new QAction(MainWindowClass);
        actionAbrir_imagen->setObjectName(QString::fromUtf8("actionAbrir_imagen"));
        actionGuardar_resultados = new QAction(MainWindowClass);
        actionGuardar_resultados->setObjectName(QString::fromUtf8("actionGuardar_resultados"));
        actionSalir = new QAction(MainWindowClass);
        actionSalir->setObjectName(QString::fromUtf8("actionSalir"));
        actionPaso_Alto = new QAction(MainWindowClass);
        actionPaso_Alto->setObjectName(QString::fromUtf8("actionPaso_Alto"));
        actionPaso_Bajo = new QAction(MainWindowClass);
        actionPaso_Bajo->setObjectName(QString::fromUtf8("actionPaso_Bajo"));
        actionEste = new QAction(MainWindowClass);
        actionEste->setObjectName(QString::fromUtf8("actionEste"));
        actionOeste = new QAction(MainWindowClass);
        actionOeste->setObjectName(QString::fromUtf8("actionOeste"));
        actionNorte = new QAction(MainWindowClass);
        actionNorte->setObjectName(QString::fromUtf8("actionNorte"));
        actionSur = new QAction(MainWindowClass);
        actionSur->setObjectName(QString::fromUtf8("actionSur"));
        actionSuroeste = new QAction(MainWindowClass);
        actionSuroeste->setObjectName(QString::fromUtf8("actionSuroeste"));
        actionSureste = new QAction(MainWindowClass);
        actionSureste->setObjectName(QString::fromUtf8("actionSureste"));
        actionNoroeste = new QAction(MainWindowClass);
        actionNoroeste->setObjectName(QString::fromUtf8("actionNoroeste"));
        actionNoreste = new QAction(MainWindowClass);
        actionNoreste->setObjectName(QString::fromUtf8("actionNoreste"));
        actionRoberts = new QAction(MainWindowClass);
        actionRoberts->setObjectName(QString::fromUtf8("actionRoberts"));
        actionSobel = new QAction(MainWindowClass);
        actionSobel->setObjectName(QString::fromUtf8("actionSobel"));
        actionPrewitt = new QAction(MainWindowClass);
        actionPrewitt->setObjectName(QString::fromUtf8("actionPrewitt"));
        actionFrei_Chen = new QAction(MainWindowClass);
        actionFrei_Chen->setObjectName(QString::fromUtf8("actionFrei_Chen"));
        actionCompleto = new QAction(MainWindowClass);
        actionCompleto->setObjectName(QString::fromUtf8("actionCompleto"));
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setMargin(11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setFrameShape(QFrame::NoFrame);
        stackedWidgetPage1 = new QWidget();
        stackedWidgetPage1->setObjectName(QString::fromUtf8("stackedWidgetPage1"));
        verticalLayout = new QVBoxLayout(stackedWidgetPage1);
        verticalLayout->setSpacing(6);
        verticalLayout->setMargin(11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        stackedWidget->addWidget(stackedWidgetPage1);

        horizontalLayout->addWidget(stackedWidget);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(220, 0));
        widget->setMaximumSize(QSize(240, 16777215));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setMargin(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetNoConstraint);
        tabWidget = new QTabWidget(widget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setMinimumSize(QSize(240, 0));
        tabWidget->setMaximumSize(QSize(16777215, 16777215));
        tabWidgetPage1 = new QWidget();
        tabWidgetPage1->setObjectName(QString::fromUtf8("tabWidgetPage1"));
        formLayout = new QFormLayout(tabWidgetPage1);
        formLayout->setSpacing(6);
        formLayout->setMargin(9);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setHorizontalSpacing(9);
        formLayout->setVerticalSpacing(6);
        label_2 = new QLabel(tabWidgetPage1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        tbSelectCu = new QToolButton(tabWidgetPage1);
        tbSelectCu->setObjectName(QString::fromUtf8("tbSelectCu"));

        formLayout->setWidget(1, QFormLayout::FieldRole, tbSelectCu);

        label_3 = new QLabel(tabWidgetPage1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        tbSelectZone = new QToolButton(tabWidgetPage1);
        tbSelectZone->setObjectName(QString::fromUtf8("tbSelectZone"));

        formLayout->setWidget(2, QFormLayout::FieldRole, tbSelectZone);

        tbApplyFilter = new QToolButton(tabWidgetPage1);
        tbApplyFilter->setObjectName(QString::fromUtf8("tbApplyFilter"));

        formLayout->setWidget(3, QFormLayout::FieldRole, tbApplyFilter);

        tbDetectBorders = new QToolButton(tabWidgetPage1);
        tbDetectBorders->setObjectName(QString::fromUtf8("tbDetectBorders"));

        formLayout->setWidget(4, QFormLayout::FieldRole, tbDetectBorders);

        lbFiltroPA = new QLabel(tabWidgetPage1);
        lbFiltroPA->setObjectName(QString::fromUtf8("lbFiltroPA"));

        formLayout->setWidget(3, QFormLayout::LabelRole, lbFiltroPA);

        lbBordes = new QLabel(tabWidgetPage1);
        lbBordes->setObjectName(QString::fromUtf8("lbBordes"));

        formLayout->setWidget(4, QFormLayout::LabelRole, lbBordes);

        tbSelectTWard = new QToolButton(tabWidgetPage1);
        tbSelectTWard->setObjectName(QString::fromUtf8("tbSelectTWard"));

        formLayout->setWidget(5, QFormLayout::FieldRole, tbSelectTWard);

        label = new QLabel(tabWidgetPage1);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label);

        label_4 = new QLabel(tabWidgetPage1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_4);

        tbSelectCP = new QToolButton(tabWidgetPage1);
        tbSelectCP->setObjectName(QString::fromUtf8("tbSelectCP"));

        formLayout->setWidget(6, QFormLayout::FieldRole, tbSelectCP);

        tbDiagnosticate = new QToolButton(tabWidgetPage1);
        tbDiagnosticate->setObjectName(QString::fromUtf8("tbDiagnosticate"));

        formLayout->setWidget(7, QFormLayout::FieldRole, tbDiagnosticate);

        label_5 = new QLabel(tabWidgetPage1);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_5);

        tabWidget->addTab(tabWidgetPage1, QString());
        tabWidgetPage2 = new QWidget();
        tabWidgetPage2->setObjectName(QString::fromUtf8("tabWidgetPage2"));
        tabWidget->addTab(tabWidgetPage2, QString());

        verticalLayout_2->addWidget(tabWidget);

        treeWidget = new QTreeWidget(widget);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setFrameShape(QFrame::StyledPanel);
        treeWidget->setFrameShadow(QFrame::Sunken);
        treeWidget->setAutoScroll(true);
        treeWidget->setAutoScrollMargin(10);
        treeWidget->setAlternatingRowColors(true);
        treeWidget->setRootIsDecorated(true);
        treeWidget->setItemsExpandable(true);
        treeWidget->setAnimated(true);
        treeWidget->header()->setVisible(true);

        verticalLayout_2->addWidget(treeWidget);


        horizontalLayout->addWidget(widget);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 29));
        menu_Archivo = new QMenu(menuBar);
        menu_Archivo->setObjectName(QString::fromUtf8("menu_Archivo"));
        menuFiltros = new QMenu(menuBar);
        menuFiltros->setObjectName(QString::fromUtf8("menuFiltros"));
        menuDeteccion_de_bordes = new QMenu(menuFiltros);
        menuDeteccion_de_bordes->setObjectName(QString::fromUtf8("menuDeteccion_de_bordes"));
        menuDireccionales = new QMenu(menuDeteccion_de_bordes);
        menuDireccionales->setObjectName(QString::fromUtf8("menuDireccionales"));
        menuBasadas_en_gradiente = new QMenu(menuDeteccion_de_bordes);
        menuBasadas_en_gradiente->setObjectName(QString::fromUtf8("menuBasadas_en_gradiente"));
        MainWindowClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindowClass->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindowClass);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setMovable(false);
        MainWindowClass->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menu_Archivo->menuAction());
        menuBar->addAction(menuFiltros->menuAction());
        menu_Archivo->addAction(actionAbrir_imagen);
        menu_Archivo->addAction(actionGuardar_resultados);
        menu_Archivo->addSeparator();
        menu_Archivo->addAction(actionSalir);
        menuFiltros->addAction(actionPaso_Alto);
        menuFiltros->addAction(actionPaso_Bajo);
        menuFiltros->addAction(menuDeteccion_de_bordes->menuAction());
        menuDeteccion_de_bordes->addAction(menuDireccionales->menuAction());
        menuDeteccion_de_bordes->addAction(menuBasadas_en_gradiente->menuAction());
        menuDireccionales->addAction(actionEste);
        menuDireccionales->addAction(actionOeste);
        menuDireccionales->addAction(actionNorte);
        menuDireccionales->addAction(actionSur);
        menuDireccionales->addAction(actionSuroeste);
        menuDireccionales->addAction(actionSureste);
        menuDireccionales->addAction(actionNoroeste);
        menuDireccionales->addAction(actionNoreste);
        menuDireccionales->addAction(actionCompleto);
        menuBasadas_en_gradiente->addSeparator();
        menuBasadas_en_gradiente->addAction(actionRoberts);
        menuBasadas_en_gradiente->addAction(actionSobel);
        menuBasadas_en_gradiente->addAction(actionPrewitt);
        menuBasadas_en_gradiente->addAction(actionFrei_Chen);

        retranslateUi(MainWindowClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionAbrir_imagen->setText(QApplication::translate("MainWindowClass", "Abrir imagen", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionAbrir_imagen->setToolTip(QApplication::translate("MainWindowClass", "Abrir imagen para analizar.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionAbrir_imagen->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+A", 0, QApplication::UnicodeUTF8));
        actionGuardar_resultados->setText(QApplication::translate("MainWindowClass", "Guardar resultados", 0, QApplication::UnicodeUTF8));
        actionGuardar_resultados->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+G", 0, QApplication::UnicodeUTF8));
        actionSalir->setText(QApplication::translate("MainWindowClass", "Salir", 0, QApplication::UnicodeUTF8));
        actionSalir->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionPaso_Alto->setText(QApplication::translate("MainWindowClass", "Paso Alto", 0, QApplication::UnicodeUTF8));
        actionPaso_Bajo->setText(QApplication::translate("MainWindowClass", "Paso Bajo", 0, QApplication::UnicodeUTF8));
        actionEste->setText(QApplication::translate("MainWindowClass", "Este", 0, QApplication::UnicodeUTF8));
        actionOeste->setText(QApplication::translate("MainWindowClass", "Oeste", 0, QApplication::UnicodeUTF8));
        actionNorte->setText(QApplication::translate("MainWindowClass", "Norte", 0, QApplication::UnicodeUTF8));
        actionSur->setText(QApplication::translate("MainWindowClass", "Sur", 0, QApplication::UnicodeUTF8));
        actionSuroeste->setText(QApplication::translate("MainWindowClass", "Suroeste", 0, QApplication::UnicodeUTF8));
        actionSureste->setText(QApplication::translate("MainWindowClass", "Sureste", 0, QApplication::UnicodeUTF8));
        actionNoroeste->setText(QApplication::translate("MainWindowClass", "Noroeste", 0, QApplication::UnicodeUTF8));
        actionNoreste->setText(QApplication::translate("MainWindowClass", "Noreste", 0, QApplication::UnicodeUTF8));
        actionRoberts->setText(QApplication::translate("MainWindowClass", "Roberts", 0, QApplication::UnicodeUTF8));
        actionSobel->setText(QApplication::translate("MainWindowClass", "Sobel", 0, QApplication::UnicodeUTF8));
        actionPrewitt->setText(QApplication::translate("MainWindowClass", "Prewitt", 0, QApplication::UnicodeUTF8));
        actionFrei_Chen->setText(QApplication::translate("MainWindowClass", "Frei-Chen", 0, QApplication::UnicodeUTF8));
        actionCompleto->setText(QApplication::translate("MainWindowClass", "Completo", 0, QApplication::UnicodeUTF8));
        stackedWidget->setStyleSheet(QString());
        label_2->setText(QApplication::translate("MainWindowClass", "Seleccionar cuadrante:", 0, QApplication::UnicodeUTF8));
        tbSelectCu->setText(QApplication::translate("MainWindowClass", "...", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindowClass", "Seleccionar \303\241rea de Inter\303\251s:", 0, QApplication::UnicodeUTF8));
        tbSelectZone->setText(QApplication::translate("MainWindowClass", "...", 0, QApplication::UnicodeUTF8));
        tbApplyFilter->setText(QApplication::translate("MainWindowClass", "...", 0, QApplication::UnicodeUTF8));
        tbDetectBorders->setText(QApplication::translate("MainWindowClass", "...", 0, QApplication::UnicodeUTF8));
        lbFiltroPA->setText(QApplication::translate("MainWindowClass", "Aplicar filtro paso alto:", 0, QApplication::UnicodeUTF8));
        lbBordes->setText(QApplication::translate("MainWindowClass", "Detectar bordes:", 0, QApplication::UnicodeUTF8));
        tbSelectTWard->setText(QApplication::translate("MainWindowClass", "...", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindowClass", "Marcar Tri\303\241ngulo de Ward:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindowClass", "Marcar Compresivo Principal:", 0, QApplication::UnicodeUTF8));
        tbSelectCP->setText(QApplication::translate("MainWindowClass", "...", 0, QApplication::UnicodeUTF8));
        tbDiagnosticate->setText(QApplication::translate("MainWindowClass", "...", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindowClass", "Determinar diagn\303\263stico:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabWidgetPage1), QApplication::translate("MainWindowClass", "Manual", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabWidgetPage2), QApplication::translate("MainWindowClass", "Autom\303\241tico", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("MainWindowClass", "Descripci\303\263n", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindowClass", "Imagen", 0, QApplication::UnicodeUTF8));
        menu_Archivo->setTitle(QApplication::translate("MainWindowClass", "&Archivo", 0, QApplication::UnicodeUTF8));
        menuFiltros->setTitle(QApplication::translate("MainWindowClass", "Filtros", 0, QApplication::UnicodeUTF8));
        menuDeteccion_de_bordes->setTitle(QApplication::translate("MainWindowClass", "Deteccion de bordes", 0, QApplication::UnicodeUTF8));
        menuDireccionales->setTitle(QApplication::translate("MainWindowClass", "Direccionales", 0, QApplication::UnicodeUTF8));
        menuBasadas_en_gradiente->setTitle(QApplication::translate("MainWindowClass", "Basadas en gradiente", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindowClass", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
