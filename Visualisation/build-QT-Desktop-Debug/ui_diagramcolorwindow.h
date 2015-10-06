/********************************************************************************
** Form generated from reading UI file 'diagramcolorwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIAGRAMCOLORWINDOW_H
#define UI_DIAGRAMCOLORWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QGraphicsView>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DiagramColorWindow
{
public:
    QGridLayout *gridLayout;
    QGroupBox *histoGroupBox;
    QGridLayout *gridLayout_2;
    QGraphicsView *graphicsView;
    QVBoxLayout *checkBoxLayout;
    QCheckBox *checkBoxR;
    QCheckBox *checkBoxG;
    QCheckBox *checkBoxB;
    QCheckBox *checkBoxY;
    QCheckBox *checkBoxCb;
    QCheckBox *checkBoxCr;
    QCheckBox *checkBoxCumu;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *fermer;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_5;

    void setupUi(QDialog *DiagramColorWindow)
    {
        if (DiagramColorWindow->objectName().isEmpty())
            DiagramColorWindow->setObjectName(QString::fromUtf8("DiagramColorWindow"));
        DiagramColorWindow->resize(423, 251);
        gridLayout = new QGridLayout(DiagramColorWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        histoGroupBox = new QGroupBox(DiagramColorWindow);
        histoGroupBox->setObjectName(QString::fromUtf8("histoGroupBox"));
        gridLayout_2 = new QGridLayout(histoGroupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        graphicsView = new QGraphicsView(histoGroupBox);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setFrameShadow(QFrame::Sunken);
        graphicsView->setLineWidth(0);
        graphicsView->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);

        gridLayout_2->addWidget(graphicsView, 0, 0, 1, 1);

        checkBoxLayout = new QVBoxLayout();
        checkBoxLayout->setObjectName(QString::fromUtf8("checkBoxLayout"));
        checkBoxR = new QCheckBox(histoGroupBox);
        checkBoxR->setObjectName(QString::fromUtf8("checkBoxR"));
        checkBoxR->setChecked(true);

        checkBoxLayout->addWidget(checkBoxR);

        checkBoxG = new QCheckBox(histoGroupBox);
        checkBoxG->setObjectName(QString::fromUtf8("checkBoxG"));
        checkBoxG->setChecked(true);

        checkBoxLayout->addWidget(checkBoxG);

        checkBoxB = new QCheckBox(histoGroupBox);
        checkBoxB->setObjectName(QString::fromUtf8("checkBoxB"));
        checkBoxB->setChecked(true);

        checkBoxLayout->addWidget(checkBoxB);

        checkBoxY = new QCheckBox(histoGroupBox);
        checkBoxY->setObjectName(QString::fromUtf8("checkBoxY"));

        checkBoxLayout->addWidget(checkBoxY);

        checkBoxCb = new QCheckBox(histoGroupBox);
        checkBoxCb->setObjectName(QString::fromUtf8("checkBoxCb"));

        checkBoxLayout->addWidget(checkBoxCb);

        checkBoxCr = new QCheckBox(histoGroupBox);
        checkBoxCr->setObjectName(QString::fromUtf8("checkBoxCr"));

        checkBoxLayout->addWidget(checkBoxCr);

        checkBoxCumu = new QCheckBox(histoGroupBox);
        checkBoxCumu->setObjectName(QString::fromUtf8("checkBoxCumu"));

        checkBoxLayout->addWidget(checkBoxCumu);


        gridLayout_2->addLayout(checkBoxLayout, 0, 1, 1, 1);


        gridLayout->addWidget(histoGroupBox, 0, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        fermer = new QPushButton(DiagramColorWindow);
        fermer->setObjectName(QString::fromUtf8("fermer"));

        gridLayout_3->addWidget(fermer, 0, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 0, 5, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_5, 0, 1, 1, 1);


        gridLayout->addLayout(gridLayout_3, 1, 0, 1, 1);


        retranslateUi(DiagramColorWindow);

        QMetaObject::connectSlotsByName(DiagramColorWindow);
    } // setupUi

    void retranslateUi(QDialog *DiagramColorWindow)
    {
        DiagramColorWindow->setWindowTitle(QApplication::translate("DiagramColorWindow", "Histogrammes", 0, QApplication::UnicodeUTF8));
        histoGroupBox->setTitle(QApplication::translate("DiagramColorWindow", "Diagrammes des couleurs", 0, QApplication::UnicodeUTF8));
        checkBoxR->setText(QApplication::translate("DiagramColorWindow", "R", 0, QApplication::UnicodeUTF8));
        checkBoxG->setText(QApplication::translate("DiagramColorWindow", "G", 0, QApplication::UnicodeUTF8));
        checkBoxB->setText(QApplication::translate("DiagramColorWindow", "B", 0, QApplication::UnicodeUTF8));
        checkBoxY->setText(QApplication::translate("DiagramColorWindow", "Y", 0, QApplication::UnicodeUTF8));
        checkBoxCb->setText(QApplication::translate("DiagramColorWindow", "Cb", 0, QApplication::UnicodeUTF8));
        checkBoxCr->setText(QApplication::translate("DiagramColorWindow", "Cr", 0, QApplication::UnicodeUTF8));
        checkBoxCumu->setText(QApplication::translate("DiagramColorWindow", "Cumu", 0, QApplication::UnicodeUTF8));
        fermer->setText(QApplication::translate("DiagramColorWindow", "Fermer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DiagramColorWindow: public Ui_DiagramColorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIAGRAMCOLORWINDOW_H
