/********************************************************************************
** Form generated from reading UI file 'contraste.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTRASTE_H
#define UI_CONTRASTE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Contraste
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QGridLayout *gridLayout;
    QSlider *horizontalSlider;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_5;
    QLabel *valtransparence;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *ok;
    QPushButton *cancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *Contraste)
    {
        if (Contraste->objectName().isEmpty())
            Contraste->setObjectName(QString::fromUtf8("Contraste"));
        Contraste->resize(250, 278);
        verticalLayout = new QVBoxLayout(Contraste);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(Contraste);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSlider = new QSlider(Contraste);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setMaximum(100);
        horizontalSlider->setValue(50);
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        valtransparence = new QLabel(Contraste);
        valtransparence->setObjectName(QString::fromUtf8("valtransparence"));

        horizontalLayout_2->addWidget(valtransparence);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        ok = new QPushButton(Contraste);
        ok->setObjectName(QString::fromUtf8("ok"));

        horizontalLayout->addWidget(ok);

        cancel = new QPushButton(Contraste);
        cancel->setObjectName(QString::fromUtf8("cancel"));

        horizontalLayout->addWidget(cancel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Contraste);
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), valtransparence, SLOT(setNum(int)));

        QMetaObject::connectSlotsByName(Contraste);
    } // setupUi

    void retranslateUi(QDialog *Contraste)
    {
        Contraste->setWindowTitle(QApplication::translate("Contraste", "Reglement du contraste", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Contraste", "Veuillez choisir le niveau de transparence", 0, QApplication::UnicodeUTF8));
        valtransparence->setText(QString());
        ok->setText(QApplication::translate("Contraste", "ok", 0, QApplication::UnicodeUTF8));
        cancel->setText(QApplication::translate("Contraste", "cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Contraste: public Ui_Contraste {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTRASTE_H
