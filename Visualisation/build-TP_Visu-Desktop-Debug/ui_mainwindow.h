/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionClose;
    QAction *actionMedian;
    QAction *actionLeger;
    QAction *actionMoyen;
    QAction *actionFort;
    QAction *actionPasse_Haut;
    QAction *actionRehaussment_Contours;
    QAction *actionX;
    QAction *actionY;
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *buttonOpen;
    QPushButton *pushButton_5;
    QPushButton *buttonGaussien;
    QPushButton *buttonMedian;
    QPushButton *buttonClose;
    QPushButton *pushButton_6;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuFlou;
    QMenu *menuGaussien;
    QMenu *menuGradient;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1029, 572);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionMedian = new QAction(MainWindow);
        actionMedian->setObjectName(QString::fromUtf8("actionMedian"));
        actionLeger = new QAction(MainWindow);
        actionLeger->setObjectName(QString::fromUtf8("actionLeger"));
        actionMoyen = new QAction(MainWindow);
        actionMoyen->setObjectName(QString::fromUtf8("actionMoyen"));
        actionFort = new QAction(MainWindow);
        actionFort->setObjectName(QString::fromUtf8("actionFort"));
        actionPasse_Haut = new QAction(MainWindow);
        actionPasse_Haut->setObjectName(QString::fromUtf8("actionPasse_Haut"));
        actionRehaussment_Contours = new QAction(MainWindow);
        actionRehaussment_Contours->setObjectName(QString::fromUtf8("actionRehaussment_Contours"));
        actionX = new QAction(MainWindow);
        actionX->setObjectName(QString::fromUtf8("actionX"));
        actionY = new QAction(MainWindow);
        actionY->setObjectName(QString::fromUtf8("actionY"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 87, 481));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        buttonOpen = new QPushButton(gridLayoutWidget);
        buttonOpen->setObjectName(QString::fromUtf8("buttonOpen"));

        gridLayout->addWidget(buttonOpen, 0, 0, 1, 1);

        pushButton_5 = new QPushButton(gridLayoutWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 4, 0, 1, 1);

        buttonGaussien = new QPushButton(gridLayoutWidget);
        buttonGaussien->setObjectName(QString::fromUtf8("buttonGaussien"));

        gridLayout->addWidget(buttonGaussien, 2, 0, 1, 1);

        buttonMedian = new QPushButton(gridLayoutWidget);
        buttonMedian->setObjectName(QString::fromUtf8("buttonMedian"));

        gridLayout->addWidget(buttonMedian, 3, 0, 1, 1);

        buttonClose = new QPushButton(gridLayoutWidget);
        buttonClose->setObjectName(QString::fromUtf8("buttonClose"));

        gridLayout->addWidget(buttonClose, 1, 0, 1, 1);

        pushButton_6 = new QPushButton(gridLayoutWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 5, 0, 1, 1);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(105, 11, 911, 481));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1029, 27));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menuFlou = new QMenu(menuBar);
        menuFlou->setObjectName(QString::fromUtf8("menuFlou"));
        menuGaussien = new QMenu(menuFlou);
        menuGaussien->setObjectName(QString::fromUtf8("menuGaussien"));
        menuGradient = new QMenu(menuFlou);
        menuGradient->setObjectName(QString::fromUtf8("menuGradient"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menuFlou->menuAction());
        menuFichier->addAction(actionOpen);
        menuFichier->addAction(actionClose);
        menuFlou->addAction(menuGaussien->menuAction());
        menuFlou->addAction(actionMedian);
        menuFlou->addAction(actionPasse_Haut);
        menuFlou->addAction(actionRehaussment_Contours);
        menuFlou->addAction(menuGradient->menuAction());
        menuGaussien->addAction(actionLeger);
        menuGaussien->addAction(actionMoyen);
        menuGaussien->addAction(actionFort);
        menuGradient->addAction(actionX);
        menuGradient->addAction(actionY);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
        actionClose->setText(QApplication::translate("MainWindow", "Close", 0, QApplication::UnicodeUTF8));
        actionMedian->setText(QApplication::translate("MainWindow", "Median", 0, QApplication::UnicodeUTF8));
        actionLeger->setText(QApplication::translate("MainWindow", "Leger", 0, QApplication::UnicodeUTF8));
        actionMoyen->setText(QApplication::translate("MainWindow", "Moyen", 0, QApplication::UnicodeUTF8));
        actionFort->setText(QApplication::translate("MainWindow", "Fort", 0, QApplication::UnicodeUTF8));
        actionPasse_Haut->setText(QApplication::translate("MainWindow", "Passe Haut", 0, QApplication::UnicodeUTF8));
        actionRehaussment_Contours->setText(QApplication::translate("MainWindow", "Rehaussement Contours", 0, QApplication::UnicodeUTF8));
        actionX->setText(QApplication::translate("MainWindow", "X", 0, QApplication::UnicodeUTF8));
        actionY->setText(QApplication::translate("MainWindow", "Y", 0, QApplication::UnicodeUTF8));
        buttonOpen->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("MainWindow", "PushButton", 0, QApplication::UnicodeUTF8));
        buttonGaussien->setText(QApplication::translate("MainWindow", "Gaussien", 0, QApplication::UnicodeUTF8));
        buttonMedian->setText(QApplication::translate("MainWindow", "Median", 0, QApplication::UnicodeUTF8));
        buttonClose->setText(QApplication::translate("MainWindow", "Close", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("MainWindow", "PushButton", 0, QApplication::UnicodeUTF8));
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", 0, QApplication::UnicodeUTF8));
        menuFlou->setTitle(QApplication::translate("MainWindow", "Filtres", 0, QApplication::UnicodeUTF8));
        menuGaussien->setTitle(QApplication::translate("MainWindow", "Gaussien", 0, QApplication::UnicodeUTF8));
        menuGradient->setTitle(QApplication::translate("MainWindow", "Gradient", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
