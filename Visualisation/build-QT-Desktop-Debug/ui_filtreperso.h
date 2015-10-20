/********************************************************************************
** Form generated from reading UI file 'filtreperso.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTREPERSO_H
#define UI_FILTREPERSO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_FiltrePerso
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QRadioButton *radioButton3x3;
    QRadioButton *radioButton5x5;
    QRadioButton *radioButton7x7;
    QGridLayout *gridLayout;
    QDoubleSpinBox *c30;
    QDoubleSpinBox *c04;
    QDoubleSpinBox *c66;
    QDoubleSpinBox *c54;
    QDoubleSpinBox *c50;
    QDoubleSpinBox *c42;
    QDoubleSpinBox *c32;
    QDoubleSpinBox *c33;
    QDoubleSpinBox *c25;
    QDoubleSpinBox *c60;
    QDoubleSpinBox *c34;
    QDoubleSpinBox *c35;
    QDoubleSpinBox *c26;
    QDoubleSpinBox *c22;
    QDoubleSpinBox *c01;
    QDoubleSpinBox *c56;
    QDoubleSpinBox *c16;
    QDoubleSpinBox *c31;
    QDoubleSpinBox *c14;
    QDoubleSpinBox *c20;
    QDoubleSpinBox *c36;
    QDoubleSpinBox *c41;
    QDoubleSpinBox *c00;
    QDoubleSpinBox *c62;
    QDoubleSpinBox *c11;
    QDoubleSpinBox *c61;
    QDoubleSpinBox *c65;
    QDoubleSpinBox *c63;
    QDoubleSpinBox *c06;
    QDoubleSpinBox *c02;
    QDoubleSpinBox *c12;
    QDoubleSpinBox *c55;
    QDoubleSpinBox *c44;
    QDoubleSpinBox *c05;
    QDoubleSpinBox *c53;
    QDoubleSpinBox *c46;
    QDoubleSpinBox *c24;
    QDoubleSpinBox *c10;
    QDoubleSpinBox *c03;
    QDoubleSpinBox *c45;
    QDoubleSpinBox *c52;
    QDoubleSpinBox *c64;
    QDoubleSpinBox *c21;
    QDoubleSpinBox *c15;
    QDoubleSpinBox *c23;
    QDoubleSpinBox *c13;
    QDoubleSpinBox *c40;
    QDoubleSpinBox *c43;
    QDoubleSpinBox *c51;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *FiltrePerso)
    {
        if (FiltrePerso->objectName().isEmpty())
            FiltrePerso->setObjectName(QStringLiteral("FiltrePerso"));
        FiltrePerso->resize(779, 291);
        gridLayout_2 = new QGridLayout(FiltrePerso);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        groupBox = new QGroupBox(FiltrePerso);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        radioButton3x3 = new QRadioButton(groupBox);
        radioButton3x3->setObjectName(QStringLiteral("radioButton3x3"));
        radioButton3x3->setChecked(true);

        formLayout->setWidget(0, QFormLayout::LabelRole, radioButton3x3);

        radioButton5x5 = new QRadioButton(groupBox);
        radioButton5x5->setObjectName(QStringLiteral("radioButton5x5"));

        formLayout->setWidget(1, QFormLayout::LabelRole, radioButton5x5);

        radioButton7x7 = new QRadioButton(groupBox);
        radioButton7x7->setObjectName(QStringLiteral("radioButton7x7"));

        formLayout->setWidget(2, QFormLayout::LabelRole, radioButton7x7);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        c30 = new QDoubleSpinBox(FiltrePerso);
        c30->setObjectName(QStringLiteral("c30"));
        c30->setMinimum(-100);
        c30->setMaximum(100);
        c30->setSingleStep(0.1);

        gridLayout->addWidget(c30, 3, 0, 1, 1);

        c04 = new QDoubleSpinBox(FiltrePerso);
        c04->setObjectName(QStringLiteral("c04"));
        c04->setMinimum(-100);
        c04->setMaximum(100);
        c04->setSingleStep(0.1);

        gridLayout->addWidget(c04, 0, 4, 1, 1);

        c66 = new QDoubleSpinBox(FiltrePerso);
        c66->setObjectName(QStringLiteral("c66"));
        c66->setMinimum(-100);
        c66->setMaximum(100);
        c66->setSingleStep(0.1);

        gridLayout->addWidget(c66, 6, 6, 1, 1);

        c54 = new QDoubleSpinBox(FiltrePerso);
        c54->setObjectName(QStringLiteral("c54"));
        c54->setMinimum(-100);
        c54->setMaximum(100);
        c54->setSingleStep(0.1);

        gridLayout->addWidget(c54, 5, 4, 1, 1);

        c50 = new QDoubleSpinBox(FiltrePerso);
        c50->setObjectName(QStringLiteral("c50"));
        c50->setMinimum(-100);
        c50->setMaximum(100);
        c50->setSingleStep(0.1);

        gridLayout->addWidget(c50, 5, 0, 1, 1);

        c42 = new QDoubleSpinBox(FiltrePerso);
        c42->setObjectName(QStringLiteral("c42"));
        c42->setMinimum(-100);
        c42->setMaximum(100);
        c42->setSingleStep(0.1);

        gridLayout->addWidget(c42, 4, 2, 1, 1);

        c32 = new QDoubleSpinBox(FiltrePerso);
        c32->setObjectName(QStringLiteral("c32"));
        c32->setMinimum(-100);
        c32->setMaximum(100);
        c32->setSingleStep(0.1);

        gridLayout->addWidget(c32, 3, 2, 1, 1);

        c33 = new QDoubleSpinBox(FiltrePerso);
        c33->setObjectName(QStringLiteral("c33"));
        c33->setMinimum(-100);
        c33->setMaximum(100);
        c33->setSingleStep(0.1);

        gridLayout->addWidget(c33, 3, 3, 1, 1);

        c25 = new QDoubleSpinBox(FiltrePerso);
        c25->setObjectName(QStringLiteral("c25"));
        c25->setMinimum(-100);
        c25->setMaximum(100);
        c25->setSingleStep(0.1);

        gridLayout->addWidget(c25, 2, 5, 1, 1);

        c60 = new QDoubleSpinBox(FiltrePerso);
        c60->setObjectName(QStringLiteral("c60"));
        c60->setMinimum(-100);
        c60->setMaximum(100);
        c60->setSingleStep(0.1);

        gridLayout->addWidget(c60, 6, 0, 1, 1);

        c34 = new QDoubleSpinBox(FiltrePerso);
        c34->setObjectName(QStringLiteral("c34"));
        c34->setMinimum(-100);
        c34->setMaximum(100);
        c34->setSingleStep(0.1);

        gridLayout->addWidget(c34, 3, 4, 1, 1);

        c35 = new QDoubleSpinBox(FiltrePerso);
        c35->setObjectName(QStringLiteral("c35"));
        c35->setMinimum(-100);
        c35->setMaximum(100);
        c35->setSingleStep(0.1);

        gridLayout->addWidget(c35, 3, 5, 1, 1);

        c26 = new QDoubleSpinBox(FiltrePerso);
        c26->setObjectName(QStringLiteral("c26"));
        c26->setMinimum(-100);
        c26->setMaximum(100);
        c26->setSingleStep(0.1);

        gridLayout->addWidget(c26, 2, 6, 1, 1);

        c22 = new QDoubleSpinBox(FiltrePerso);
        c22->setObjectName(QStringLiteral("c22"));
        c22->setMinimum(-100);
        c22->setMaximum(100);
        c22->setSingleStep(0.1);

        gridLayout->addWidget(c22, 2, 2, 1, 1);

        c01 = new QDoubleSpinBox(FiltrePerso);
        c01->setObjectName(QStringLiteral("c01"));
        c01->setMinimum(-100);
        c01->setMaximum(100);
        c01->setSingleStep(0.1);

        gridLayout->addWidget(c01, 0, 1, 1, 1);

        c56 = new QDoubleSpinBox(FiltrePerso);
        c56->setObjectName(QStringLiteral("c56"));
        c56->setMinimum(-100);
        c56->setMaximum(100);
        c56->setSingleStep(0.1);

        gridLayout->addWidget(c56, 5, 6, 1, 1);

        c16 = new QDoubleSpinBox(FiltrePerso);
        c16->setObjectName(QStringLiteral("c16"));
        c16->setMinimum(-100);
        c16->setMaximum(100);
        c16->setSingleStep(0.1);

        gridLayout->addWidget(c16, 1, 6, 1, 1);

        c31 = new QDoubleSpinBox(FiltrePerso);
        c31->setObjectName(QStringLiteral("c31"));
        c31->setMinimum(-100);
        c31->setMaximum(100);
        c31->setSingleStep(0.1);

        gridLayout->addWidget(c31, 3, 1, 1, 1);

        c14 = new QDoubleSpinBox(FiltrePerso);
        c14->setObjectName(QStringLiteral("c14"));
        c14->setMinimum(-100);
        c14->setMaximum(100);
        c14->setSingleStep(0.1);

        gridLayout->addWidget(c14, 1, 4, 1, 1);

        c20 = new QDoubleSpinBox(FiltrePerso);
        c20->setObjectName(QStringLiteral("c20"));
        c20->setMinimum(-100);
        c20->setMaximum(100);
        c20->setSingleStep(0.1);

        gridLayout->addWidget(c20, 2, 0, 1, 1);

        c36 = new QDoubleSpinBox(FiltrePerso);
        c36->setObjectName(QStringLiteral("c36"));
        c36->setMinimum(-100);
        c36->setMaximum(100);
        c36->setSingleStep(0.1);

        gridLayout->addWidget(c36, 3, 6, 1, 1);

        c41 = new QDoubleSpinBox(FiltrePerso);
        c41->setObjectName(QStringLiteral("c41"));
        c41->setMinimum(-100);
        c41->setMaximum(100);
        c41->setSingleStep(0.1);

        gridLayout->addWidget(c41, 4, 1, 1, 1);

        c00 = new QDoubleSpinBox(FiltrePerso);
        c00->setObjectName(QStringLiteral("c00"));
        c00->setMinimum(-100);
        c00->setMaximum(100);
        c00->setSingleStep(0.1);

        gridLayout->addWidget(c00, 0, 0, 1, 1);

        c62 = new QDoubleSpinBox(FiltrePerso);
        c62->setObjectName(QStringLiteral("c62"));
        c62->setMinimum(-100);
        c62->setMaximum(100);
        c62->setSingleStep(0.1);

        gridLayout->addWidget(c62, 6, 2, 1, 1);

        c11 = new QDoubleSpinBox(FiltrePerso);
        c11->setObjectName(QStringLiteral("c11"));
        c11->setMinimum(-100);
        c11->setMaximum(100);
        c11->setSingleStep(0.1);

        gridLayout->addWidget(c11, 1, 1, 1, 1);

        c61 = new QDoubleSpinBox(FiltrePerso);
        c61->setObjectName(QStringLiteral("c61"));
        c61->setMinimum(-100);
        c61->setMaximum(100);
        c61->setSingleStep(0.1);

        gridLayout->addWidget(c61, 6, 1, 1, 1);

        c65 = new QDoubleSpinBox(FiltrePerso);
        c65->setObjectName(QStringLiteral("c65"));
        c65->setMinimum(-100);
        c65->setMaximum(100);
        c65->setSingleStep(0.1);

        gridLayout->addWidget(c65, 6, 5, 1, 1);

        c63 = new QDoubleSpinBox(FiltrePerso);
        c63->setObjectName(QStringLiteral("c63"));
        c63->setMinimum(-100);
        c63->setMaximum(100);
        c63->setSingleStep(0.1);

        gridLayout->addWidget(c63, 6, 3, 1, 1);

        c06 = new QDoubleSpinBox(FiltrePerso);
        c06->setObjectName(QStringLiteral("c06"));
        c06->setMinimum(-100);
        c06->setMaximum(100);
        c06->setSingleStep(0.1);

        gridLayout->addWidget(c06, 0, 6, 1, 1);

        c02 = new QDoubleSpinBox(FiltrePerso);
        c02->setObjectName(QStringLiteral("c02"));
        c02->setMinimum(-100);
        c02->setMaximum(100);
        c02->setSingleStep(0.1);

        gridLayout->addWidget(c02, 0, 2, 1, 1);

        c12 = new QDoubleSpinBox(FiltrePerso);
        c12->setObjectName(QStringLiteral("c12"));
        c12->setMinimum(-100);
        c12->setMaximum(100);
        c12->setSingleStep(0.1);

        gridLayout->addWidget(c12, 1, 2, 1, 1);

        c55 = new QDoubleSpinBox(FiltrePerso);
        c55->setObjectName(QStringLiteral("c55"));
        c55->setMinimum(-100);
        c55->setMaximum(100);
        c55->setSingleStep(0.1);

        gridLayout->addWidget(c55, 5, 5, 1, 1);

        c44 = new QDoubleSpinBox(FiltrePerso);
        c44->setObjectName(QStringLiteral("c44"));
        c44->setMinimum(-100);
        c44->setMaximum(100);
        c44->setSingleStep(0.1);

        gridLayout->addWidget(c44, 4, 4, 1, 1);

        c05 = new QDoubleSpinBox(FiltrePerso);
        c05->setObjectName(QStringLiteral("c05"));
        c05->setMinimum(-100);
        c05->setMaximum(100);
        c05->setSingleStep(0.1);

        gridLayout->addWidget(c05, 0, 5, 1, 1);

        c53 = new QDoubleSpinBox(FiltrePerso);
        c53->setObjectName(QStringLiteral("c53"));
        c53->setMinimum(-100);
        c53->setMaximum(100);
        c53->setSingleStep(0.1);

        gridLayout->addWidget(c53, 5, 3, 1, 1);

        c46 = new QDoubleSpinBox(FiltrePerso);
        c46->setObjectName(QStringLiteral("c46"));
        c46->setMinimum(-100);
        c46->setMaximum(100);
        c46->setSingleStep(0.1);

        gridLayout->addWidget(c46, 4, 6, 1, 1);

        c24 = new QDoubleSpinBox(FiltrePerso);
        c24->setObjectName(QStringLiteral("c24"));
        c24->setMinimum(-100);
        c24->setMaximum(100);
        c24->setSingleStep(0.1);

        gridLayout->addWidget(c24, 2, 4, 1, 1);

        c10 = new QDoubleSpinBox(FiltrePerso);
        c10->setObjectName(QStringLiteral("c10"));
        c10->setMinimum(-100);
        c10->setMaximum(100);
        c10->setSingleStep(0.1);

        gridLayout->addWidget(c10, 1, 0, 1, 1);

        c03 = new QDoubleSpinBox(FiltrePerso);
        c03->setObjectName(QStringLiteral("c03"));
        c03->setMinimum(-100);
        c03->setMaximum(100);
        c03->setSingleStep(0.1);

        gridLayout->addWidget(c03, 0, 3, 1, 1);

        c45 = new QDoubleSpinBox(FiltrePerso);
        c45->setObjectName(QStringLiteral("c45"));
        c45->setMinimum(-100);
        c45->setMaximum(100);
        c45->setSingleStep(0.1);

        gridLayout->addWidget(c45, 4, 5, 1, 1);

        c52 = new QDoubleSpinBox(FiltrePerso);
        c52->setObjectName(QStringLiteral("c52"));
        c52->setMinimum(-100);
        c52->setMaximum(100);
        c52->setSingleStep(0.1);

        gridLayout->addWidget(c52, 5, 2, 1, 1);

        c64 = new QDoubleSpinBox(FiltrePerso);
        c64->setObjectName(QStringLiteral("c64"));
        c64->setMinimum(-100);
        c64->setMaximum(100);
        c64->setSingleStep(0.1);

        gridLayout->addWidget(c64, 6, 4, 1, 1);

        c21 = new QDoubleSpinBox(FiltrePerso);
        c21->setObjectName(QStringLiteral("c21"));
        c21->setMinimum(-100);
        c21->setMaximum(100);
        c21->setSingleStep(0.1);

        gridLayout->addWidget(c21, 2, 1, 1, 1);

        c15 = new QDoubleSpinBox(FiltrePerso);
        c15->setObjectName(QStringLiteral("c15"));
        c15->setMinimum(-100);
        c15->setMaximum(100);
        c15->setSingleStep(0.1);

        gridLayout->addWidget(c15, 1, 5, 1, 1);

        c23 = new QDoubleSpinBox(FiltrePerso);
        c23->setObjectName(QStringLiteral("c23"));
        c23->setMinimum(-100);
        c23->setMaximum(100);
        c23->setSingleStep(0.1);

        gridLayout->addWidget(c23, 2, 3, 1, 1);

        c13 = new QDoubleSpinBox(FiltrePerso);
        c13->setObjectName(QStringLiteral("c13"));
        c13->setMinimum(-100);
        c13->setMaximum(100);
        c13->setSingleStep(0.1);

        gridLayout->addWidget(c13, 1, 3, 1, 1);

        c40 = new QDoubleSpinBox(FiltrePerso);
        c40->setObjectName(QStringLiteral("c40"));
        c40->setMinimum(-100);
        c40->setMaximum(100);
        c40->setSingleStep(0.1);

        gridLayout->addWidget(c40, 4, 0, 1, 1);

        c43 = new QDoubleSpinBox(FiltrePerso);
        c43->setObjectName(QStringLiteral("c43"));
        c43->setMinimum(-100);
        c43->setMaximum(100);
        c43->setSingleStep(0.1);

        gridLayout->addWidget(c43, 4, 3, 1, 1);

        c51 = new QDoubleSpinBox(FiltrePerso);
        c51->setObjectName(QStringLiteral("c51"));
        c51->setMinimum(-100);
        c51->setMaximum(100);
        c51->setSingleStep(0.1);

        gridLayout->addWidget(c51, 5, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 1, 1, 1);

        buttonBox = new QDialogButtonBox(FiltrePerso);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 1, 1, 1, 1);


        retranslateUi(FiltrePerso);

        QMetaObject::connectSlotsByName(FiltrePerso);
    } // setupUi

    void retranslateUi(QDialog *FiltrePerso)
    {
        FiltrePerso->setWindowTitle(QApplication::translate("FiltrePerso", "Filtre personnalis\303\251", 0));
        groupBox->setTitle(QApplication::translate("FiltrePerso", "Taille de la matrice", 0));
        radioButton3x3->setText(QApplication::translate("FiltrePerso", "3x3", 0));
        radioButton5x5->setText(QApplication::translate("FiltrePerso", "5x5", 0));
        radioButton7x7->setText(QApplication::translate("FiltrePerso", "7x7", 0));
    } // retranslateUi

};

namespace Ui {
    class FiltrePerso: public Ui_FiltrePerso {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTREPERSO_H
