/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

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
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1029, 572);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionMedian = new QAction(MainWindow);
        actionMedian->setObjectName(QStringLiteral("actionMedian"));
        actionLeger = new QAction(MainWindow);
        actionLeger->setObjectName(QStringLiteral("actionLeger"));
        actionMoyen = new QAction(MainWindow);
        actionMoyen->setObjectName(QStringLiteral("actionMoyen"));
        actionFort = new QAction(MainWindow);
        actionFort->setObjectName(QStringLiteral("actionFort"));
        actionPasse_Haut = new QAction(MainWindow);
        actionPasse_Haut->setObjectName(QStringLiteral("actionPasse_Haut"));
        actionRehaussment_Contours = new QAction(MainWindow);
        actionRehaussment_Contours->setObjectName(QStringLiteral("actionRehaussment_Contours"));
        actionX = new QAction(MainWindow);
        actionX->setObjectName(QStringLiteral("actionX"));
        actionY = new QAction(MainWindow);
        actionY->setObjectName(QStringLiteral("actionY"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 87, 481));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        buttonOpen = new QPushButton(gridLayoutWidget);
        buttonOpen->setObjectName(QStringLiteral("buttonOpen"));

        gridLayout->addWidget(buttonOpen, 0, 0, 1, 1);

        pushButton_5 = new QPushButton(gridLayoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 4, 0, 1, 1);

        buttonGaussien = new QPushButton(gridLayoutWidget);
        buttonGaussien->setObjectName(QStringLiteral("buttonGaussien"));

        gridLayout->addWidget(buttonGaussien, 2, 0, 1, 1);

        buttonMedian = new QPushButton(gridLayoutWidget);
        buttonMedian->setObjectName(QStringLiteral("buttonMedian"));

        gridLayout->addWidget(buttonMedian, 3, 0, 1, 1);

        buttonClose = new QPushButton(gridLayoutWidget);
        buttonClose->setObjectName(QStringLiteral("buttonClose"));

        gridLayout->addWidget(buttonClose, 1, 0, 1, 1);

        pushButton_6 = new QPushButton(gridLayoutWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 5, 0, 1, 1);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(105, 11, 911, 481));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1029, 27));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        menuFlou = new QMenu(menuBar);
        menuFlou->setObjectName(QStringLiteral("menuFlou"));
        menuGaussien = new QMenu(menuFlou);
        menuGaussien->setObjectName(QStringLiteral("menuGaussien"));
        menuGradient = new QMenu(menuFlou);
        menuGradient->setObjectName(QStringLiteral("menuGradient"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0));
        actionClose->setText(QApplication::translate("MainWindow", "Close", 0));
        actionMedian->setText(QApplication::translate("MainWindow", "Median", 0));
        actionLeger->setText(QApplication::translate("MainWindow", "Leger", 0));
        actionMoyen->setText(QApplication::translate("MainWindow", "Moyen", 0));
        actionFort->setText(QApplication::translate("MainWindow", "Fort", 0));
        actionPasse_Haut->setText(QApplication::translate("MainWindow", "Passe Haut", 0));
        actionRehaussment_Contours->setText(QApplication::translate("MainWindow", "Rehaussement Contours", 0));
        actionX->setText(QApplication::translate("MainWindow", "X", 0));
        actionY->setText(QApplication::translate("MainWindow", "Y", 0));
        buttonOpen->setText(QApplication::translate("MainWindow", "Open", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "PushButton", 0));
        buttonGaussien->setText(QApplication::translate("MainWindow", "Gaussien", 0));
        buttonMedian->setText(QApplication::translate("MainWindow", "Median", 0));
        buttonClose->setText(QApplication::translate("MainWindow", "Close", 0));
        pushButton_6->setText(QApplication::translate("MainWindow", "PushButton", 0));
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", 0));
        menuFlou->setTitle(QApplication::translate("MainWindow", "Filtres", 0));
        menuGaussien->setTitle(QApplication::translate("MainWindow", "Gaussien", 0));
        menuGradient->setTitle(QApplication::translate("MainWindow", "Gradient", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
