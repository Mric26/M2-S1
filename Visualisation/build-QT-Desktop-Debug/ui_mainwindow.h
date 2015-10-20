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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
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
    QAction *actionInversion_Histo;
    QAction *actionComposante_connexe;
    QAction *actionBord_objets;
    QAction *actionModule_gradient;
    QAction *actionPoint_d_interets;
    QAction *actionSeuillage;
    QAction *actionNegatif;
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
    QMenu *menuTP3;
    QMenu *menuTP2;
    QMenu *menuTP4;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(688, 552);
        QIcon icon;
        icon.addFile(QStringLiteral(":/res/Logo 01.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionEnregistrer = new QAction(MainWindow);
        actionEnregistrer->setObjectName(QStringLiteral("actionEnregistrer"));
        actionFermer = new QAction(MainWindow);
        actionFermer->setObjectName(QStringLiteral("actionFermer"));
        actionEnregistrer_sous = new QAction(MainWindow);
        actionEnregistrer_sous->setObjectName(QStringLiteral("actionEnregistrer_sous"));
        actionOuvrir_2 = new QAction(MainWindow);
        actionOuvrir_2->setObjectName(QStringLiteral("actionOuvrir_2"));
        actionHistogramme = new QAction(MainWindow);
        actionHistogramme->setObjectName(QStringLiteral("actionHistogramme"));
        actionNiveau_de_gris = new QAction(MainWindow);
        actionNiveau_de_gris->setObjectName(QStringLiteral("actionNiveau_de_gris"));
        actionFusion = new QAction(MainWindow);
        actionFusion->setObjectName(QStringLiteral("actionFusion"));
        actionFlouGaussLeger = new QAction(MainWindow);
        actionFlouGaussLeger->setObjectName(QStringLiteral("actionFlouGaussLeger"));
        actionFlouGaussMoyen = new QAction(MainWindow);
        actionFlouGaussMoyen->setObjectName(QStringLiteral("actionFlouGaussMoyen"));
        actionFlouGaussFort = new QAction(MainWindow);
        actionFlouGaussFort->setObjectName(QStringLiteral("actionFlouGaussFort"));
        actionPasse_haut = new QAction(MainWindow);
        actionPasse_haut->setObjectName(QStringLiteral("actionPasse_haut"));
        actionFlouMoyLeger = new QAction(MainWindow);
        actionFlouMoyLeger->setObjectName(QStringLiteral("actionFlouMoyLeger"));
        actionFlouMoyMoyen = new QAction(MainWindow);
        actionFlouMoyMoyen->setObjectName(QStringLiteral("actionFlouMoyMoyen"));
        actionFlouMoyFort = new QAction(MainWindow);
        actionFlouMoyFort->setObjectName(QStringLiteral("actionFlouMoyFort"));
        actionRehaussement = new QAction(MainWindow);
        actionRehaussement->setObjectName(QStringLiteral("actionRehaussement"));
        actionGradientX = new QAction(MainWindow);
        actionGradientX->setObjectName(QStringLiteral("actionGradientX"));
        actionGradientY = new QAction(MainWindow);
        actionGradientY->setObjectName(QStringLiteral("actionGradientY"));
        actionDetectionContours = new QAction(MainWindow);
        actionDetectionContours->setObjectName(QStringLiteral("actionDetectionContours"));
        actionMedian = new QAction(MainWindow);
        actionMedian->setObjectName(QStringLiteral("actionMedian"));
        actionEtalement = new QAction(MainWindow);
        actionEtalement->setObjectName(QStringLiteral("actionEtalement"));
        actionEgalisation = new QAction(MainWindow);
        actionEgalisation->setObjectName(QStringLiteral("actionEgalisation"));
        actionAnnuler = new QAction(MainWindow);
        actionAnnuler->setObjectName(QStringLiteral("actionAnnuler"));
        actionRefaire_2 = new QAction(MainWindow);
        actionRefaire_2->setObjectName(QStringLiteral("actionRefaire_2"));
        actionPersonnaliser = new QAction(MainWindow);
        actionPersonnaliser->setObjectName(QStringLiteral("actionPersonnaliser"));
        actionEspace_RGB = new QAction(MainWindow);
        actionEspace_RGB->setObjectName(QStringLiteral("actionEspace_RGB"));
        actionEspace_YUV = new QAction(MainWindow);
        actionEspace_YUV->setObjectName(QStringLiteral("actionEspace_YUV"));
        actionRedimensionner = new QAction(MainWindow);
        actionRedimensionner->setObjectName(QStringLiteral("actionRedimensionner"));
        actionFusionner = new QAction(MainWindow);
        actionFusionner->setObjectName(QStringLiteral("actionFusionner"));
        actionFiltre_adaptatif = new QAction(MainWindow);
        actionFiltre_adaptatif->setObjectName(QStringLiteral("actionFiltre_adaptatif"));
        actionInversion_Histo = new QAction(MainWindow);
        actionInversion_Histo->setObjectName(QStringLiteral("actionInversion_Histo"));
        actionComposante_connexe = new QAction(MainWindow);
        actionComposante_connexe->setObjectName(QStringLiteral("actionComposante_connexe"));
        actionBord_objets = new QAction(MainWindow);
        actionBord_objets->setObjectName(QStringLiteral("actionBord_objets"));
        actionModule_gradient = new QAction(MainWindow);
        actionModule_gradient->setObjectName(QStringLiteral("actionModule_gradient"));
        actionPoint_d_interets = new QAction(MainWindow);
        actionPoint_d_interets->setObjectName(QStringLiteral("actionPoint_d_interets"));
        actionSeuillage = new QAction(MainWindow);
        actionSeuillage->setObjectName(QStringLiteral("actionSeuillage"));
        actionNegatif = new QAction(MainWindow);
        actionNegatif->setObjectName(QStringLiteral("actionNegatif"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetNoConstraint);
        gridLayout_2->setContentsMargins(-1, 40, 0, 40);
        enregistrer = new QPushButton(centralWidget);
        enregistrer->setObjectName(QStringLiteral("enregistrer"));
        enregistrer->setAutoFillBackground(false);
        enregistrer->setAutoDefault(false);
        enregistrer->setDefault(false);
        enregistrer->setFlat(false);

        gridLayout_2->addWidget(enregistrer, 3, 0, 1, 1);

        refaire = new QPushButton(centralWidget);
        refaire->setObjectName(QStringLiteral("refaire"));

        gridLayout_2->addWidget(refaire, 6, 0, 1, 1);

        flou = new QPushButton(centralWidget);
        flou->setObjectName(QStringLiteral("flou"));
        flou->setAutoFillBackground(false);
        flou->setAutoDefault(false);
        flou->setDefault(false);
        flou->setFlat(false);

        gridLayout_2->addWidget(flou, 14, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 20, 0, 1, 1);

        selection = new QPushButton(centralWidget);
        selection->setObjectName(QStringLiteral("selection"));

        gridLayout_2->addWidget(selection, 8, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_2->addItem(verticalSpacer_3, 4, 0, 1, 1);

        couper = new QPushButton(centralWidget);
        couper->setObjectName(QStringLiteral("couper"));
        couper->setAutoFillBackground(false);
        couper->setCheckable(false);
        couper->setAutoDefault(false);
        couper->setDefault(false);
        couper->setFlat(false);

        gridLayout_2->addWidget(couper, 9, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 0, 0, 1, 1);

        pipette = new QPushButton(centralWidget);
        pipette->setObjectName(QStringLiteral("pipette"));
        pipette->setAutoFillBackground(false);
        pipette->setAutoDefault(false);
        pipette->setDefault(false);
        pipette->setFlat(false);

        gridLayout_2->addWidget(pipette, 12, 0, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_2->addItem(verticalSpacer_6, 11, 0, 1, 1);

        ouvrir = new QPushButton(centralWidget);
        ouvrir->setObjectName(QStringLiteral("ouvrir"));
        ouvrir->setAutoFillBackground(false);
        ouvrir->setAutoDefault(false);
        ouvrir->setDefault(false);
        ouvrir->setFlat(false);

        gridLayout_2->addWidget(ouvrir, 1, 0, 1, 1);

        histogramme = new QPushButton(centralWidget);
        histogramme->setObjectName(QStringLiteral("histogramme"));
        histogramme->setAutoFillBackground(false);
        histogramme->setAutoDefault(false);
        histogramme->setDefault(false);
        histogramme->setFlat(false);

        gridLayout_2->addWidget(histogramme, 18, 0, 1, 1);

        rogner = new QPushButton(centralWidget);
        rogner->setObjectName(QStringLiteral("rogner"));

        gridLayout_2->addWidget(rogner, 10, 0, 1, 1);

        gris = new QPushButton(centralWidget);
        gris->setObjectName(QStringLiteral("gris"));
        gris->setAutoFillBackground(false);
        gris->setAutoDefault(false);
        gris->setDefault(false);
        gris->setFlat(false);

        gridLayout_2->addWidget(gris, 13, 0, 1, 1);

        annuler = new QPushButton(centralWidget);
        annuler->setObjectName(QStringLiteral("annuler"));

        gridLayout_2->addWidget(annuler, 5, 0, 1, 1);

        fusion = new QPushButton(centralWidget);
        fusion->setObjectName(QStringLiteral("fusion"));
        fusion->setAutoFillBackground(false);
        fusion->setAutoDefault(false);
        fusion->setDefault(false);
        fusion->setFlat(false);

        gridLayout_2->addWidget(fusion, 15, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_2->addItem(verticalSpacer_4, 7, 0, 1, 1);


        gridLayout->addLayout(gridLayout_2, 0, 0, 1, 1);

        graphicsView = new MyGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(graphicsView, 0, 1, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 688, 27));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        menu_dition = new QMenu(menuBar);
        menu_dition->setObjectName(QStringLiteral("menu_dition"));
        menuFiltres = new QMenu(menu_dition);
        menuFiltres->setObjectName(QStringLiteral("menuFiltres"));
        menuFlou_2 = new QMenu(menuFiltres);
        menuFlou_2->setObjectName(QStringLiteral("menuFlou_2"));
        menuGaussien = new QMenu(menuFlou_2);
        menuGaussien->setObjectName(QStringLiteral("menuGaussien"));
        menuMoyenneur = new QMenu(menuFlou_2);
        menuMoyenneur->setObjectName(QStringLiteral("menuMoyenneur"));
        menuGradients = new QMenu(menuFiltres);
        menuGradients->setObjectName(QStringLiteral("menuGradients"));
        menuPipette = new QMenu(menu_dition);
        menuPipette->setObjectName(QStringLiteral("menuPipette"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        menuCalques = new QMenu(menuBar);
        menuCalques->setObjectName(QStringLiteral("menuCalques"));
        menuTP1bis = new QMenu(menuBar);
        menuTP1bis->setObjectName(QStringLiteral("menuTP1bis"));
        menuTP3 = new QMenu(menuBar);
        menuTP3->setObjectName(QStringLiteral("menuTP3"));
        menuTP2 = new QMenu(menuBar);
        menuTP2->setObjectName(QStringLiteral("menuTP2"));
        menuTP4 = new QMenu(menuBar);
        menuTP4->setObjectName(QStringLiteral("menuTP4"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menu_dition->menuAction());
        menuBar->addAction(menuCalques->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuBar->addAction(menuTP1bis->menuAction());
        menuBar->addAction(menuTP2->menuAction());
        menuBar->addAction(menuTP3->menuAction());
        menuBar->addAction(menuTP4->menuAction());
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
        menuTP1bis->addAction(actionInversion_Histo);
        menuTP3->addAction(actionPoint_d_interets);
        menuTP2->addAction(actionModule_gradient);
        menuTP4->addAction(actionSeuillage);
        menuTP4->addAction(actionNegatif);
        menuTP4->addAction(actionComposante_connexe);
        menuTP4->addAction(actionBord_objets);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Shotophop 1", 0));
        actionEnregistrer->setText(QApplication::translate("MainWindow", "enregistrer", 0));
        actionFermer->setText(QApplication::translate("MainWindow", "fermer", 0));
        actionEnregistrer_sous->setText(QApplication::translate("MainWindow", "enregistrer sous", 0));
        actionOuvrir_2->setText(QApplication::translate("MainWindow", "ouvrir", 0));
        actionHistogramme->setText(QApplication::translate("MainWindow", "Histogramme", 0));
        actionNiveau_de_gris->setText(QApplication::translate("MainWindow", "Niveau de gris", 0));
        actionFusion->setText(QApplication::translate("MainWindow", "Fusion", 0));
        actionFlouGaussLeger->setText(QApplication::translate("MainWindow", "L\303\251ger", 0));
        actionFlouGaussMoyen->setText(QApplication::translate("MainWindow", "moyen", 0));
        actionFlouGaussFort->setText(QApplication::translate("MainWindow", "Fort", 0));
        actionPasse_haut->setText(QApplication::translate("MainWindow", "Passe haut", 0));
        actionFlouMoyLeger->setText(QApplication::translate("MainWindow", "L\303\251ger", 0));
        actionFlouMoyMoyen->setText(QApplication::translate("MainWindow", "Moyen", 0));
        actionFlouMoyFort->setText(QApplication::translate("MainWindow", "Fort", 0));
        actionRehaussement->setText(QApplication::translate("MainWindow", "R\303\251haussement", 0));
        actionGradientX->setText(QApplication::translate("MainWindow", "X", 0));
        actionGradientY->setText(QApplication::translate("MainWindow", "Y", 0));
        actionDetectionContours->setText(QApplication::translate("MainWindow", "D\303\251tection de contours", 0));
        actionMedian->setText(QApplication::translate("MainWindow", "M\303\251dian", 0));
        actionEtalement->setText(QApplication::translate("MainWindow", "Etalement", 0));
        actionEgalisation->setText(QApplication::translate("MainWindow", "Egalisation", 0));
        actionAnnuler->setText(QApplication::translate("MainWindow", "Annuler", 0));
        actionRefaire_2->setText(QApplication::translate("MainWindow", "Refaire", 0));
        actionPersonnaliser->setText(QApplication::translate("MainWindow", "Personnaliser...", 0));
        actionEspace_RGB->setText(QApplication::translate("MainWindow", "Espace RGB", 0));
        actionEspace_YUV->setText(QApplication::translate("MainWindow", "Espace YUV", 0));
        actionRedimensionner->setText(QApplication::translate("MainWindow", "Redimensionner", 0));
        actionFusionner->setText(QApplication::translate("MainWindow", "Fusionner", 0));
        actionFiltre_adaptatif->setText(QApplication::translate("MainWindow", "Filtre adaptatif", 0));
        actionInversion_Histo->setText(QApplication::translate("MainWindow", "Inversion Histo", 0));
        actionComposante_connexe->setText(QApplication::translate("MainWindow", "Composante connexe", 0));
        actionBord_objets->setText(QApplication::translate("MainWindow", "Bord objets", 0));
        actionModule_gradient->setText(QApplication::translate("MainWindow", "Module gradient", 0));
        actionPoint_d_interets->setText(QApplication::translate("MainWindow", "Point d'interets", 0));
        actionSeuillage->setText(QApplication::translate("MainWindow", "Seuillage", 0));
        actionNegatif->setText(QApplication::translate("MainWindow", "Negatif", 0));
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
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", 0));
        menu_dition->setTitle(QApplication::translate("MainWindow", "Edition", 0));
        menuFiltres->setTitle(QApplication::translate("MainWindow", "Filtres", 0));
        menuFlou_2->setTitle(QApplication::translate("MainWindow", "Flou", 0));
        menuGaussien->setTitle(QApplication::translate("MainWindow", "Gaussien", 0));
        menuMoyenneur->setTitle(QApplication::translate("MainWindow", "Moyenneur", 0));
        menuGradients->setTitle(QApplication::translate("MainWindow", "Gradients", 0));
        menuPipette->setTitle(QApplication::translate("MainWindow", "Pipette", 0));
        menuAbout->setTitle(QApplication::translate("MainWindow", "About", 0));
        menuCalques->setTitle(QApplication::translate("MainWindow", "Calques", 0));
        menuTP1bis->setTitle(QApplication::translate("MainWindow", "TP1bis", 0));
        menuTP3->setTitle(QApplication::translate("MainWindow", "TP3", 0));
        menuTP2->setTitle(QApplication::translate("MainWindow", "TP2", 0));
        menuTP4->setTitle(QApplication::translate("MainWindow", "TP4", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
