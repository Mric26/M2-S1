/********************************************************************************
** Form generated from reading UI file 'redimensionnement.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REDIMENSIONNEMENT_H
#define UI_REDIMENSIONNEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Redimensionnement
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpinBox *coordonneesX;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QSpinBox *coordonneesY;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *ok;
    QPushButton *cancel;

    void setupUi(QDialog *Redimensionnement)
    {
        if (Redimensionnement->objectName().isEmpty())
            Redimensionnement->setObjectName(QStringLiteral("Redimensionnement"));
        Redimensionnement->resize(372, 248);
        verticalLayoutWidget = new QWidget(Redimensionnement);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(60, 40, 241, 121));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        coordonneesX = new QSpinBox(verticalLayoutWidget);
        coordonneesX->setObjectName(QStringLiteral("coordonneesX"));

        horizontalLayout->addWidget(coordonneesX);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        coordonneesY = new QSpinBox(verticalLayoutWidget);
        coordonneesY->setObjectName(QStringLiteral("coordonneesY"));

        horizontalLayout_2->addWidget(coordonneesY);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayoutWidget_3 = new QWidget(Redimensionnement);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(200, 200, 168, 41));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        ok = new QPushButton(horizontalLayoutWidget_3);
        ok->setObjectName(QStringLiteral("ok"));

        horizontalLayout_3->addWidget(ok);

        cancel = new QPushButton(horizontalLayoutWidget_3);
        cancel->setObjectName(QStringLiteral("cancel"));

        horizontalLayout_3->addWidget(cancel);


        retranslateUi(Redimensionnement);

        QMetaObject::connectSlotsByName(Redimensionnement);
    } // setupUi

    void retranslateUi(QDialog *Redimensionnement)
    {
        Redimensionnement->setWindowTitle(QApplication::translate("Redimensionnement", "Dialog", 0));
        label->setText(QApplication::translate("Redimensionnement", "veuillez selectionner la nouvelle taille", 0));
        label_2->setText(QApplication::translate("Redimensionnement", "coordonn\303\251es x:", 0));
        label_3->setText(QApplication::translate("Redimensionnement", "coordonn\303\251es y:", 0));
        ok->setText(QApplication::translate("Redimensionnement", "ok", 0));
        cancel->setText(QApplication::translate("Redimensionnement", "cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class Redimensionnement: public Ui_Redimensionnement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REDIMENSIONNEMENT_H
