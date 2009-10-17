/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Sat Oct 10 11:35:11 2009
**      by: Qt User Interface Compiler version 4.5.2
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
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStackedWidget>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
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
    QAction *actionGaussiano;
    QAction *actionDilatacion;
    QAction *actionErosion;
    QAction *actionErosi_n_condicional;
    QAction *actionUmbralado;
    QAction *actionNormalizaci_n;
    QAction *actionUmbral;
    QAction *actionNormalizacion;
    QAction *actionEcualizacion;
    QAction *actionEsqueletizacion;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    QWidget *stackedWidgetPage1;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tabWidgetPage1;
    QFormLayout *formLayout;
    QLabel *label_3;
    QToolButton *tbSelectZone;
    QLabel *label;
    QToolButton *tbSelectTWard;
    QLabel *label_4;
    QToolButton *tbSelectCP;
    QLabel *label_5;
    QToolButton *tbDiagnosticate;
    QWidget *tabWidgetPage2;
    QFormLayout *formLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTreeWidget *treeWidget;
    QMenuBar *menuBar;
    QMenu *menu_Archivo;
    QMenu *menuFiltros;
    QMenu *menuDeteccion_de_bordes;
    QMenu *menuDireccionales;
    QMenu *menuBasadas_en_gradiente;
    QMenu *menuRealce;
    QMenu *menuOtros;
    QMenu *menuHerramientas;
    QMenu *menuHistograma;
    QMenu *menuTransformaciones;
    QStatusBar *statusBar;

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
        actionGaussiano = new QAction(MainWindowClass);
        actionGaussiano->setObjectName(QString::fromUtf8("actionGaussiano"));
        actionDilatacion = new QAction(MainWindowClass);
        actionDilatacion->setObjectName(QString::fromUtf8("actionDilatacion"));
        actionErosion = new QAction(MainWindowClass);
        actionErosion->setObjectName(QString::fromUtf8("actionErosion"));
        actionErosi_n_condicional = new QAction(MainWindowClass);
        actionErosi_n_condicional->setObjectName(QString::fromUtf8("actionErosi_n_condicional"));
        actionUmbralado = new QAction(MainWindowClass);
        actionUmbralado->setObjectName(QString::fromUtf8("actionUmbralado"));
        actionNormalizaci_n = new QAction(MainWindowClass);
        actionNormalizaci_n->setObjectName(QString::fromUtf8("actionNormalizaci_n"));
        actionUmbral = new QAction(MainWindowClass);
        actionUmbral->setObjectName(QString::fromUtf8("actionUmbral"));
        actionNormalizacion = new QAction(MainWindowClass);
        actionNormalizacion->setObjectName(QString::fromUtf8("actionNormalizacion"));
        actionEcualizacion = new QAction(MainWindowClass);
        actionEcualizacion->setObjectName(QString::fromUtf8("actionEcualizacion"));
        actionEsqueletizacion = new QAction(MainWindowClass);
        actionEsqueletizacion->setObjectName(QString::fromUtf8("actionEsqueletizacion"));
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
        stackedWidgetPage1->setEnabled(false);
        verticalLayout = new QVBoxLayout(stackedWidgetPage1);
        verticalLayout->setSpacing(6);
        verticalLayout->setMargin(11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        stackedWidget->addWidget(stackedWidgetPage1);

        horizontalLayout->addWidget(stackedWidget);

        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(240, 0));
        frame->setMaximumSize(QSize(240, 16777215));
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setMargin(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetNoConstraint);
        tabWidget = new QTabWidget(frame);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setMinimumSize(QSize(240, 0));
        tabWidget->setMaximumSize(QSize(16777215, 220));
        tabWidgetPage1 = new QWidget();
        tabWidgetPage1->setObjectName(QString::fromUtf8("tabWidgetPage1"));
        formLayout = new QFormLayout(tabWidgetPage1);
        formLayout->setSpacing(6);
        formLayout->setMargin(9);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setHorizontalSpacing(9);
        formLayout->setVerticalSpacing(14);
        label_3 = new QLabel(tabWidgetPage1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        tbSelectZone = new QToolButton(tabWidgetPage1);
        tbSelectZone->setObjectName(QString::fromUtf8("tbSelectZone"));

        formLayout->setWidget(1, QFormLayout::FieldRole, tbSelectZone);

        label = new QLabel(tabWidgetPage1);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label);

        tbSelectTWard = new QToolButton(tabWidgetPage1);
        tbSelectTWard->setObjectName(QString::fromUtf8("tbSelectTWard"));

        formLayout->setWidget(2, QFormLayout::FieldRole, tbSelectTWard);

        label_4 = new QLabel(tabWidgetPage1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        tbSelectCP = new QToolButton(tabWidgetPage1);
        tbSelectCP->setObjectName(QString::fromUtf8("tbSelectCP"));

        formLayout->setWidget(3, QFormLayout::FieldRole, tbSelectCP);

        label_5 = new QLabel(tabWidgetPage1);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        tbDiagnosticate = new QToolButton(tabWidgetPage1);
        tbDiagnosticate->setObjectName(QString::fromUtf8("tbDiagnosticate"));

        formLayout->setWidget(4, QFormLayout::FieldRole, tbDiagnosticate);

        tabWidget->addTab(tabWidgetPage1, QString());
        tabWidgetPage2 = new QWidget();
        tabWidgetPage2->setObjectName(QString::fromUtf8("tabWidgetPage2"));
        formLayout_2 = new QFormLayout(tabWidgetPage2);
        formLayout_2->setSpacing(6);
        formLayout_2->setMargin(11);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        pushButton = new QPushButton(tabWidgetPage2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        formLayout_2->setWidget(0, QFormLayout::SpanningRole, pushButton);

        pushButton_2 = new QPushButton(tabWidgetPage2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        formLayout_2->setWidget(1, QFormLayout::SpanningRole, pushButton_2);

        tabWidget->addTab(tabWidgetPage2, QString());

        verticalLayout_2->addWidget(tabWidget);

        treeWidget = new QTreeWidget(frame);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setFrameShape(QFrame::StyledPanel);
        treeWidget->setFrameShadow(QFrame::Sunken);
        treeWidget->setAutoScroll(true);
        treeWidget->setAutoScrollMargin(10);
        treeWidget->setAlternatingRowColors(true);
        treeWidget->setRootIsDecorated(true);
        treeWidget->setItemsExpandable(true);
        treeWidget->setAnimated(true);
        treeWidget->setColumnCount(1);
        treeWidget->header()->setVisible(false);

        verticalLayout_2->addWidget(treeWidget);


        horizontalLayout->addWidget(frame);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 25));
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
        menuRealce = new QMenu(menuFiltros);
        menuRealce->setObjectName(QString::fromUtf8("menuRealce"));
        menuOtros = new QMenu(menuFiltros);
        menuOtros->setObjectName(QString::fromUtf8("menuOtros"));
        menuHerramientas = new QMenu(menuBar);
        menuHerramientas->setObjectName(QString::fromUtf8("menuHerramientas"));
        menuHistograma = new QMenu(menuHerramientas);
        menuHistograma->setObjectName(QString::fromUtf8("menuHistograma"));
        menuTransformaciones = new QMenu(menuBar);
        menuTransformaciones->setObjectName(QString::fromUtf8("menuTransformaciones"));
        MainWindowClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindowClass->setStatusBar(statusBar);
        QWidget::setTabOrder(tabWidget, tbSelectZone);
        QWidget::setTabOrder(tbSelectZone, tbSelectTWard);
        QWidget::setTabOrder(tbSelectTWard, tbSelectCP);
        QWidget::setTabOrder(tbSelectCP, tbDiagnosticate);
        QWidget::setTabOrder(tbDiagnosticate, treeWidget);

        menuBar->addAction(menu_Archivo->menuAction());
        menuBar->addAction(menuFiltros->menuAction());
        menuBar->addAction(menuTransformaciones->menuAction());
        menuBar->addAction(menuHerramientas->menuAction());
        menu_Archivo->addAction(actionAbrir_imagen);
        menu_Archivo->addAction(actionGuardar_resultados);
        menu_Archivo->addSeparator();
        menu_Archivo->addAction(actionSalir);
        menuFiltros->addAction(menuRealce->menuAction());
        menuFiltros->addAction(menuOtros->menuAction());
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
        menuBasadas_en_gradiente->addAction(actionRoberts);
        menuBasadas_en_gradiente->addAction(actionSobel);
        menuBasadas_en_gradiente->addAction(actionPrewitt);
        menuBasadas_en_gradiente->addAction(actionFrei_Chen);
        menuRealce->addAction(actionPaso_Alto);
        menuOtros->addAction(actionPaso_Bajo);
        menuOtros->addAction(actionGaussiano);
        menuHerramientas->addAction(menuHistograma->menuAction());
        menuHistograma->addAction(actionUmbral);
        menuHistograma->addAction(actionNormalizacion);
        menuHistograma->addAction(actionEcualizacion);
        menuTransformaciones->addAction(actionDilatacion);
        menuTransformaciones->addAction(actionErosion);
        menuTransformaciones->addAction(actionErosi_n_condicional);
        menuTransformaciones->addSeparator();
        menuTransformaciones->addAction(actionEsqueletizacion);

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
        actionGaussiano->setText(QApplication::translate("MainWindowClass", "Gaussiano", 0, QApplication::UnicodeUTF8));
        actionDilatacion->setText(QApplication::translate("MainWindowClass", "Dilataci\303\263n", 0, QApplication::UnicodeUTF8));
        actionErosion->setText(QApplication::translate("MainWindowClass", "Erosi\303\263n", 0, QApplication::UnicodeUTF8));
        actionErosi_n_condicional->setText(QApplication::translate("MainWindowClass", "Erosi\303\263n condicional", 0, QApplication::UnicodeUTF8));
        actionUmbralado->setText(QApplication::translate("MainWindowClass", "Umbralado", 0, QApplication::UnicodeUTF8));
        actionNormalizaci_n->setText(QApplication::translate("MainWindowClass", "Normalizaci\303\263n", 0, QApplication::UnicodeUTF8));
        actionUmbral->setText(QApplication::translate("MainWindowClass", "Umbralado", 0, QApplication::UnicodeUTF8));
        actionNormalizacion->setText(QApplication::translate("MainWindowClass", "Normalizaci\303\263n", 0, QApplication::UnicodeUTF8));
        actionEcualizacion->setText(QApplication::translate("MainWindowClass", "Ecualizaci\303\263n", 0, QApplication::UnicodeUTF8));
        actionEsqueletizacion->setText(QApplication::translate("MainWindowClass", "Esqueletizacion", 0, QApplication::UnicodeUTF8));
        stackedWidget->setStyleSheet(QString());
        label_3->setText(QApplication::translate("MainWindowClass", "Seleccionar \303\241rea de Inter\303\251s:", 0, QApplication::UnicodeUTF8));
        tbSelectZone->setText(QApplication::translate("MainWindowClass", "...", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindowClass", "Marcar Tri\303\241ngulo de Ward:", 0, QApplication::UnicodeUTF8));
        tbSelectTWard->setText(QApplication::translate("MainWindowClass", "...", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindowClass", "Marcar Compresivo Principal:", 0, QApplication::UnicodeUTF8));
        tbSelectCP->setText(QApplication::translate("MainWindowClass", "...", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindowClass", "Determinar diagn\303\263stico:", 0, QApplication::UnicodeUTF8));
        tbDiagnosticate->setText(QApplication::translate("MainWindowClass", "...", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabWidgetPage1), QApplication::translate("MainWindowClass", "Manual", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindowClass", "PushButton", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindowClass", "PushButton", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabWidgetPage2), QApplication::translate("MainWindowClass", "Autom\303\241tico", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindowClass", "Im\303\241genes", 0, QApplication::UnicodeUTF8));
        menu_Archivo->setTitle(QApplication::translate("MainWindowClass", "&Archivo", 0, QApplication::UnicodeUTF8));
        menuFiltros->setTitle(QApplication::translate("MainWindowClass", "Filtros", 0, QApplication::UnicodeUTF8));
        menuDeteccion_de_bordes->setTitle(QApplication::translate("MainWindowClass", "Deteccion de bordes", 0, QApplication::UnicodeUTF8));
        menuDireccionales->setTitle(QApplication::translate("MainWindowClass", "Direccionales", 0, QApplication::UnicodeUTF8));
        menuBasadas_en_gradiente->setTitle(QApplication::translate("MainWindowClass", "Basadas en gradiente", 0, QApplication::UnicodeUTF8));
        menuRealce->setTitle(QApplication::translate("MainWindowClass", "Realce", 0, QApplication::UnicodeUTF8));
        menuOtros->setTitle(QApplication::translate("MainWindowClass", "Suavizado", 0, QApplication::UnicodeUTF8));
        menuHerramientas->setTitle(QApplication::translate("MainWindowClass", "Herramientas", 0, QApplication::UnicodeUTF8));
        menuHistograma->setTitle(QApplication::translate("MainWindowClass", "Histograma", 0, QApplication::UnicodeUTF8));
        menuTransformaciones->setTitle(QApplication::translate("MainWindowClass", "Transformaciones", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
