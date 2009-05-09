/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Sat May 9 15:44:23 2009
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
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStackedWidget>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *actionAbrir_imagen;
    QAction *actionGuardar_resultados;
    QAction *actionSalir;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QHBoxLayout *horizontalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QToolButton *toolButton;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QLabel *label_5;
    QToolButton *toolButton_2;
    QWidget *tab_2;
    QMenuBar *menuBar;
    QMenu *menu_Archivo;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QString::fromUtf8("MainWindowClass"));
        MainWindowClass->resize(691, 418);
        MainWindowClass->setMinimumSize(QSize(691, 418));
        actionAbrir_imagen = new QAction(MainWindowClass);
        actionAbrir_imagen->setObjectName(QString::fromUtf8("actionAbrir_imagen"));
        actionGuardar_resultados = new QAction(MainWindowClass);
        actionGuardar_resultados->setObjectName(QString::fromUtf8("actionGuardar_resultados"));
        actionSalir = new QAction(MainWindowClass);
        actionSalir->setObjectName(QString::fromUtf8("actionSalir"));
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setMargin(11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setMinimumSize(QSize(447, 0));
        stackedWidget->setFrameShape(QFrame::StyledPanel);
        stackedWidget->setFrameShadow(QFrame::Plain);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(page->sizePolicy().hasHeightForWidth());
        page->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(page);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setMargin(11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        stackedWidget->addWidget(page);

        horizontalLayout->addWidget(stackedWidget);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setMinimumSize(QSize(220, 0));
        tabWidget->setMaximumSize(QSize(220, 16777215));
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setUsesScrollButtons(false);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        toolButton = new QToolButton(tab);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(180, 30, 26, 25));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 30, 81, 21));
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(100, 30, 71, 26));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 10, 161, 21));
        lineEdit_2 = new QLineEdit(tab);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(80, 110, 71, 26));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 70, 161, 41));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 110, 51, 21));
        lineEdit_3 = new QLineEdit(tab);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(80, 140, 71, 26));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 140, 51, 21));
        toolButton_2 = new QToolButton(tab);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setGeometry(QRect(170, 120, 26, 31));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());

        horizontalLayout->addWidget(tabWidget);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 691, 29));
        menu_Archivo = new QMenu(menuBar);
        menu_Archivo->setObjectName(QString::fromUtf8("menu_Archivo"));
        MainWindowClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindowClass->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindowClass);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindowClass->addToolBar(Qt::TopToolBarArea, toolBar);
        QWidget::setTabOrder(tabWidget, toolButton);
        QWidget::setTabOrder(toolButton, lineEdit);
        QWidget::setTabOrder(lineEdit, toolButton_2);
        QWidget::setTabOrder(toolButton_2, lineEdit_2);
        QWidget::setTabOrder(lineEdit_2, lineEdit_3);

        menuBar->addAction(menu_Archivo->menuAction());
        menu_Archivo->addAction(actionAbrir_imagen);
        menu_Archivo->addAction(actionGuardar_resultados);
        menu_Archivo->addSeparator();
        menu_Archivo->addAction(actionSalir);

        retranslateUi(MainWindowClass);

        stackedWidget->setCurrentIndex(0);
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
        stackedWidget->setStyleSheet(QString());
        toolButton->setText(QApplication::translate("MainWindowClass", "...", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindowClass", "Coordenada:", 0, QApplication::UnicodeUTF8));
        lineEdit->setInputMask(QApplication::translate("MainWindowClass", "(009,009);0", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QApplication::translate("MainWindowClass", "(,)", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindowClass", "Selecci\303\263n de cuadrante:", 0, QApplication::UnicodeUTF8));
        lineEdit_2->setInputMask(QApplication::translate("MainWindowClass", "(009,009);0", 0, QApplication::UnicodeUTF8));
        lineEdit_2->setText(QApplication::translate("MainWindowClass", "(,)", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindowClass", "Selecci\303\263n de \303\201rea de \n"
"Inter\303\251s:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindowClass", "Inicio:", 0, QApplication::UnicodeUTF8));
        lineEdit_3->setInputMask(QApplication::translate("MainWindowClass", "(009,009);0", 0, QApplication::UnicodeUTF8));
        lineEdit_3->setText(QApplication::translate("MainWindowClass", "(,)", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindowClass", "Fin:", 0, QApplication::UnicodeUTF8));
        toolButton_2->setText(QApplication::translate("MainWindowClass", "...", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindowClass", "Manual", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindowClass", "Autom\303\241tico", 0, QApplication::UnicodeUTF8));
        menu_Archivo->setTitle(QApplication::translate("MainWindowClass", "&Archivo", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindowClass", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
