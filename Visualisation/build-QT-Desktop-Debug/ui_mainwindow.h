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
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>
#include "mygraphicsview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionEnregistrer;
    QAction *actionFermer;
    QAction *actionEnregistrer_sous;
    QAction *actionOuvrir_2;
    QAction *actionHistogramme;
    QAction *actionNiveau_de_gris;
    QAction *actionFusion;
    QAction *actionFlouGaussLeger;
    QAction *actionFlouGaussMoyen;
    QAction *actionFlouGaussFort;
    QAction *actionPasse_haut;
    QAction *actionFlouMoyLeger;
    QAction *actionFlouMoyMoyen;
    QAction *actionFlouMoyFort;
    QAction *actionRehaussement;
    QAction *actionGradientX;
    QAction *actionGradientY;
    QAction *actionDetectionContours;
    QAction *actionMedian;
    QAction *actionEtalement;
    QAction *actionEgalisation;
    QAction *actionAnnuler;
    QAction *actionRefaire_2;
    QAction *actionPersonnaliser;
    QAction *actionEspace_RGB;
    QAction *actionEspace_YUV;
    QAction *actionRedimensionner;
    QAction *actionFusionner;
    QAction *actionFiltre_adaptatif;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QPushButton *enregistrer;
    QPushButton *refaire;
    QPushButton *flou;
    QSpacerItem *verticalSpacer;
    QPushButton *selection;
    QSpacerItem *verticalSpacer_3;
    QPushButton *couper;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pipette;
    QSpacerItem *verticalSpacer_6;
    QPushButton *ouvrir;
    QPushButton *histogramme;
    QPushButton *rogner;
    QPushButton *gris;
    QPushButton *annuler;
    QPushButton *fusion;
    QSpacerItem *verticalSpacer_4;
    MyGraphicsView *graphicsView;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menu_dition;
    QMenu *menuFiltres;
    QMenu *menuFlou_2;
    QMenu *menuGaussien;
    QMenu *menuMoyenneur;
    QMenu *menuGradients;
    QMenu *menuPipette;
    QMenu *menuAbout;
    QMenu *menuCalques;
    QMenu *menuTP1bis;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(688, 552);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/Logo 01.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionEnregistrer = new QAction(MainWindow);
        actionEnregistrer->setObjectName(QString::fromUtf8("actionEnregistrer"));
        actionFermer = new QAction(MainWindow);
        actionFermer->setObjectName(QString::fromUtf8("actionFermer"));
        actionEnregistrer_sous = new QAction(MainWindow);
        actionEnregistrer_sous->setObjectName(QString::fromUtf8("actionEnregistrer_sous"));
        actionOuvrir_2 = new QAction(MainWindow);
        actionOuvrir_2->setObjectName(QString::fromUtf8("actionOuvrir_2"));
        actionHistogramme = new QAction(MainWindow);
        actionHistogramme->setObjectName(QString::fromUtf8("actionHistogramme"));
        actionNiveau_de_gris = new QAction(MainWindow);
        actionNiveau_de_gris->setObjectName(QString::fromUtf8("actionNiveau_de_gris"));
        actionFusion = new QAction(MainWindow);
        actionFusion->setObjectName(QString::fromUtf8("actionFusion"));
        actionFlouGaussLeger = new QAction(MainWindow);
        actionFlouGaussLeger->setObjectName(QString::fromUtf8("actionFlouGaussLeger"));
        actionFlouGaussMoyen = new QAction(MainWindow);
        actionFlouGaussMoyen->setObjectName(QString::fromUtf8("actionFlouGaussMoyen"));
        actionFlouGaussFort = new QAction(MainWindow);
        actionFlouGaussFort->setObjectName(QString::fromUtf8("actionFlouGaussFort"));
        actionPasse_haut = new QAction(MainWindow);
        actionPasse_haut->setObjectName(QString::fromUtf8("actionPasse_haut"));
        actionFlouMoyLeger = new QAction(MainWindow);
        actionFlouMoyLeger->setObjectName(QString::fromUtf8("actionFlouMoyLeger"));
        actionFlouMoyMoyen = new QAction(MainWindow);
        actionFlouMoyMoyen->setObjectName(QString::fromUtf8("actionFlouMoyMoyen"));
        actionFlouMoyFort = new QAction(MainWindow);
        actionFlouMoyFort->setObjectName(QString::fromUtf8("actionFlouMoyFort"));
        actionRehaussement = new QAction(MainWindow);
        actionRehaussement->setObjectName(QString::fromUtf8("actionRehaussement"));
        actionGradientX = new QAction(MainWindow);
        actionGradientX->setObjectName(QString::fromUtf8("actionGradientX"));
        actionGradientY = new QAction(MainWindow);
        actionGradientY->setObjectName(QString::fromUtf8("actionGradientY"));
        actionDetectionContours = new QAction(MainWindow);
        actionDetectionContours->setObjectName(QString::fromUtf8("actionDetectionContours"));
        actionMedian = new QAction(MainWindow);
        actionMedian->setObjectName(QString::fromUtf8("actionMedian"));
        actionEtalement = new QAction(MainWindow);
        actionEtalement->setObjectName(QString::fromUtf8("actionEtalement"));
        actionEgalisation = new QAction(MainWindow);
        actionEgalisation->setObjectName(QString::fromUtf8("actionEgalisation"));
        actionAnnuler = new QAction(MainWindow);
        actionAnnuler->setObjectName(QString::fromUtf8("actionAnnuler"));
        actionRefaire_2 = new QAction(MainWindow);
        actionRefaire_2->setObjectName(QString::fromUtf8("actionRefaire_2"));
        actionPersonnaliser = new QAction(MainWindow);
        actionPersonnaliser->setObjectName(QString::fromUtf8("actionPersonnaliser"));
        actionEspace_RGB = new QAction(MainWindow);
        actionEspace_RGB->setObjectName(QString::fromUtf8("actionEspace_RGB"));
        actionEspace_YUV = new QAction(MainWindow);
        actionEspace_YUV->setObjectName(QString::fromUtf8("actionEspace_YUV"));
        actionRedimensionner = new QAction(MainWindow);
        actionRedimensionner->setObjectName(QString::fromUtf8("actionRedimensionner"));
        actionFusionner = new QAction(MainWindow);
        actionFusionner->setObjectName(QString::fromUtf8("actionFusionner"));
        actionFiltre_adaptatif = new QAction(MainWindow);
        actionFiltre_adaptatif->setObjectName(QString::fromUtf8("actionFiltre_adaptatif"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetNoConstraint);
        gridLayout_2->setContentsMargins(-1, 40, 0, 40);
        enregistrer = new QPushButton(centralWidget);
        enregistrer->setObjectName(QString::fromUtf8("enregistrer"));
        enregistrer->setAutoFillBackground(false);
        enregistrer->setAutoDefault(false);
        enregistrer->setDefault(false);
        enregistrer->setFlat(false);

        gridLayout_2->addWidget(enregistrer, 3, 0, 1, 1);

        refaire = new QPushButton(centralWidget);
        refaire->setObjectName(QString::fromUtf8("refaire"));

        gridLayout_2->addWidget(refaire, 6, 0, 1, 1);

        flou = new QPushButton(centralWidget);
        flou->setObjectName(QString::fromUtf8("flou"));
        flou->setAutoFillBackground(false);
        flou->setAutoDefault(false);
        flou->setDefault(false);
        flou->setFlat(false);

        gridLayout_2->addWidget(flou, 14, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 20, 0, 1, 1);

        selection = new QPushButton(centralWidget);
        selection->setObjectName(QString::fromUtf8("selection"));

        gridLayout_2->addWidget(selection, 8, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_2->addItem(verticalSpacer_3, 4, 0, 1, 1);

        couper = new QPushButton(centralWidget);
        couper->setObjectName(QString::fromUtf8("couper"));
        couper->setAutoFillBackground(false);
        couper->setCheckable(false);
        couper->setAutoDefault(false);
        couper->setDefault(false);
        couper->setFlat(false);

        gridLayout_2->addWidget(couper, 9, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 0, 0, 1, 1);

        pipette = new QPushButton(centralWidget);
        pipette->setObjectName(QString::fromUtf8("pipette"));
        pipette->setAutoFillBackground(false);
        pipette->setAutoDefault(false);
        pipette->setDefault(false);
        pipette->setFlat(false);

        gridLayout_2->addWidget(pipette, 12, 0, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_2->addItem(verticalSpacer_6, 11, 0, 1, 1);

        ouvrir = new QPushButton(centralWidget);
        ouvrir->setObjectName(QString::fromUtf8("ouvrir"));
        ouvrir->setAutoFillBackground(false);
        ouvrir->setAutoDefault(false);
        ouvrir->setDefault(false);
        ouvrir->setFlat(false);

        gridLayout_2->addWidget(ouvrir, 1, 0, 1, 1);

        histogramme = new QPushButton(centralWidget);
        histogramme->setObjectName(QString::fromUtf8("histogramme"));
        histogramme->setAutoFillBackground(false);
        histogramme->setAutoDefault(false);
        histogramme->setDefault(false);
        histogramme->setFlat(false);

        gridLayout_2->addWidget(histogramme, 18, 0, 1, 1);

        rogner = new QPushButton(centralWidget);
        rogner->setObjectName(QString::fromUtf8("rogner"));

        gridLayout_2->addWidget(rogner, 10, 0, 1, 1);

        gris = new QPushButton(centralWidget);
        gris->setObjectName(QString::fromUtf8("gris"));
        gris->setAutoFillBackground(false);
        gris->setAutoDefault(false);
        gris->setDefault(false);
        gris->setFlat(false);

        gridLayout_2->addWidget(gris, 13, 0, 1, 1);

        annuler = new QPushButton(centralWidget);
        annuler->setObjectName(QString::fromUtf8("annuler"));

        gridLayout_2->addWidget(annuler, 5, 0, 1, 1);

        fusion = new QPushButton(centralWidget);
        fusion->setObjectName(QString::fromUtf8("fusion"));
        fusion->setAutoFillBackground(false);
        fusion->setAutoDefault(false);
        fusion->setDefault(false);
        fusion->setFlat(false);

        gridLayout_2->addWidget(fusion, 15, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_2->addItem(verticalSpacer_4, 7, 0, 1, 1);


        gridLayout->addLayout(gridLayout_2, 0, 0, 1, 1);

        graphicsView = new MyGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(graphicsView, 0, 1, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 688, 27));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menu_dition = new QMenu(menuBar);
        menu_dition->setObjectName(QString::fromUtf8("menu_dition"));
        menuFiltres = new QMenu(menu_dition);
        menuFiltres->setObjectName(QString::fromUtf8("menuFiltres"));
        menuFlou_2 = new QMenu(menuFiltres);
        menuFlou_2->setObjectName(QString::fromUtf8("menuFlou_2"));
        menuGaussien = new QMenu(menuFlou_2);
        menuGaussien->setObjectName(QString::fromUtf8("menuGaussien"));
        menuMoyenneur = new QMenu(menuFlou_2);
        menuMoyenneur->setObjectName(QString::fromUtf8("menuMoyenneur"));
        menuGradients = new QMenu(menuFiltres);
        menuGradients->setObjectName(QString::fromUtf8("menuGradients"));
        menuPipette = new QMenu(menu_dition);
        menuPipette->setObjectName(QString::fromUtf8("menuPipette"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        menuCalques = new QMenu(menuBar);
        menuCalques->setObjectName(QString::fromUtf8("menuCalques"));
        menuTP1bis = new QMenu(menuBar);
        menuTP1bis->setObjectName(QString::fromUtf8("menuTP1bis"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menu_dition->menuAction());
        menuBar->addAction(menuCalques->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuBar->addAction(menuTP1bis->menuAction());
        menuFichier->addAction(actionOuvrir_2);
        menuFichier->addAction(actionEnregistrer);
        menuFichier->addAction(actionEnregistrer_sous);
        menuFichier->addAction(actionFermer);
        menuFichier->addSeparator();
        menu_dition->addAction(actionAnnuler);
        menu_dition->addAction(actionRefaire_2);
        menu_dition->addSeparator();
        menu_dition->addAction(actionNiveau_de_gris);
        menu_dition->addAction(menuPipette->menuAction());
        menu_dition->addAction(menuFiltres->menuAction());
        menu_dition->addAction(actionFusion);
        menu_dition->addSeparator();
        menu_dition->addAction(actionHistogramme);
        menu_dition->addAction(actionEtalement);
        menu_dition->addAction(actionEgalisation);
        menu_dition->addSeparator();
        menu_dition->addAction(actionRedimensionner);
        menuFiltres->addAction(actionPasse_haut);
        menuFiltres->addAction(actionRehaussement);
        menuFiltres->addAction(menuFlou_2->menuAction());
        menuFiltres->addAction(menuGradients->menuAction());
        menuFiltres->addAction(actionMedian);
        menuFiltres->addAction(actionPersonnaliser);
        menuFlou_2->addAction(menuGaussien->menuAction());
        menuFlou_2->addAction(menuMoyenneur->menuAction());
        menuGaussien->addAction(actionFlouGaussLeger);
        menuGaussien->addAction(actionFlouGaussMoyen);
        menuGaussien->addAction(actionFlouGaussFort);
        menuMoyenneur->addAction(actionFlouMoyLeger);
        menuMoyenneur->addAction(actionFlouMoyMoyen);
        menuMoyenneur->addAction(actionFlouMoyFort);
        menuGradients->addAction(actionGradientX);
        menuGradients->addAction(actionGradientY);
        menuGradients->addAction(actionDetectionContours);
        menuPipette->addAction(actionEspace_RGB);
        menuPipette->addAction(actionEspace_YUV);
        menuCalques->addAction(actionFusionner);
        menuTP1bis->addAction(actionFiltre_adaptatif);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Shotophop 1", 0, QApplication::UnicodeUTF8));
        actionEnregistrer->setText(QApplication::translate("MainWindow", "enregistrer", 0, QApplication::UnicodeUTF8));
        actionFermer->setText(QApplication::translate("MainWindow", "fermer", 0, QApplication::UnicodeUTF8));
        actionEnregistrer_sous->setText(QApplication::translate("MainWindow", "enregistrer sous", 0, QApplication::UnicodeUTF8));
        actionOuvrir_2->setText(QApplication::translate("MainWindow", "ouvrir", 0, QApplication::UnicodeUTF8));
        actionHistogramme->setText(QApplication::translate("MainWindow", "Histogramme", 0, QApplication::UnicodeUTF8));
        actionNiveau_de_gris->setText(QApplication::translate("MainWindow", "Niveau de gris", 0, QApplication::UnicodeUTF8));
        actionFusion->setText(QApplication::translate("MainWindow", "Fusion", 0, QApplication::UnicodeUTF8));
        actionFlouGaussLeger->setText(QApplication::translate("MainWindow", "L\303\251ger", 0, QApplication::UnicodeUTF8));
        actionFlouGaussMoyen->setText(QApplication::translate("MainWindow", "moyen", 0, QApplication::UnicodeUTF8));
        actionFlouGaussFort->setText(QApplication::translate("MainWindow", "Fort", 0, QApplication::UnicodeUTF8));
        actionPasse_haut->setText(QApplication::translate("MainWindow", "Passe haut", 0, QApplication::UnicodeUTF8));
        actionFlouMoyLeger->setText(QApplication::translate("MainWindow", "L\303\251ger", 0, QApplication::UnicodeUTF8));
        actionFlouMoyMoyen->setText(QApplication::translate("MainWindow", "Moyen", 0, QApplication::UnicodeUTF8));
        actionFlouMoyFort->setText(QApplication::translate("MainWindow", "Fort", 0, QApplication::UnicodeUTF8));
        actionRehaussement->setText(QApplication::translate("MainWindow", "R\303\251haussement", 0, QApplication::UnicodeUTF8));
        actionGradientX->setText(QApplication::translate("MainWindow", "X", 0, QApplication::UnicodeUTF8));
        actionGradientY->setText(QApplication::translate("MainWindow", "Y", 0, QApplication::UnicodeUTF8));
        actionDetectionContours->setText(QApplication::translate("MainWindow", "D\303\251tection de contours", 0, QApplication::UnicodeUTF8));
        actionMedian->setText(QApplication::translate("MainWindow", "M\303\251dian", 0, QApplication::UnicodeUTF8));
        actionEtalement->setText(QApplication::translate("MainWindow", "Etalement", 0, QApplication::UnicodeUTF8));
        actionEgalisation->setText(QApplication::translate("MainWindow", "Egalisation", 0, QApplication::UnicodeUTF8));
        actionAnnuler->setText(QApplication::translate("MainWindow", "Annuler", 0, QApplication::UnicodeUTF8));
        actionRefaire_2->setText(QApplication::translate("MainWindow", "Refaire", 0, QApplication::UnicodeUTF8));
        actionPersonnaliser->setText(QApplication::translate("MainWindow", "Personnaliser...", 0, QApplication::UnicodeUTF8));
        actionEspace_RGB->setText(QApplication::translate("MainWindow", "Espace RGB", 0, QApplication::UnicodeUTF8));
        actionEspace_YUV->setText(QApplication::translate("MainWindow", "Espace YUV", 0, QApplication::UnicodeUTF8));
        actionRedimensionner->setText(QApplication::translate("MainWindow", "Redimensionner", 0, QApplication::UnicodeUTF8));
        actionFusionner->setText(QApplication::translate("MainWindow", "Fusionner", 0, QApplication::UnicodeUTF8));
        actionFiltre_adaptatif->setText(QApplication::translate("MainWindow", "Filtre adaptatif", 0, QApplication::UnicodeUTF8));
        enregistrer->setText(QString());
        refaire->setText(QString());
        flou->setText(QString());
        selection->setText(QString());
        couper->setText(QString());
        pipette->setText(QString());
        ouvrir->setText(QString());
        histogramme->setText(QString());
        rogner->setText(QString());
        gris->setText(QString());
        annuler->setText(QString());
        fusion->setText(QString());
        label->setText(QString());
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", 0, QApplication::UnicodeUTF8));
        menu_dition->setTitle(QApplication::translate("MainWindow", "Edition", 0, QApplication::UnicodeUTF8));
        menuFiltres->setTitle(QApplication::translate("MainWindow", "Filtres", 0, QApplication::UnicodeUTF8));
        menuFlou_2->setTitle(QApplication::translate("MainWindow", "Flou", 0, QApplication::UnicodeUTF8));
        menuGaussien->setTitle(QApplication::translate("MainWindow", "Gaussien", 0, QApplication::UnicodeUTF8));
        menuMoyenneur->setTitle(QApplication::translate("MainWindow", "Moyenneur", 0, QApplication::UnicodeUTF8));
        menuGradients->setTitle(QApplication::translate("MainWindow", "Gradients", 0, QApplication::UnicodeUTF8));
        menuPipette->setTitle(QApplication::translate("MainWindow", "Pipette", 0, QApplication::UnicodeUTF8));
        menuAbout->setTitle(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        menuCalques->setTitle(QApplication::translate("MainWindow", "Calques", 0, QApplication::UnicodeUTF8));
        menuTP1bis->setTitle(QApplication::translate("MainWindow", "TP1bis", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
