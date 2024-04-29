/********************************************************************************
** Form generated from reading UI file 'ventana.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANA_H
#define UI_VENTANA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ventana
{
public:
    QGridLayout *gridLayout;
    QLabel *lSaludo;

    void setupUi(QWidget *Ventana)
    {
        if (Ventana->objectName().isEmpty())
            Ventana->setObjectName("Ventana");
        Ventana->resize(400, 200);
        Ventana->setMaximumSize(QSize(400, 200));
        gridLayout = new QGridLayout(Ventana);
        gridLayout->setObjectName("gridLayout");
        lSaludo = new QLabel(Ventana);
        lSaludo->setObjectName("lSaludo");
        QFont font;
        font.setPointSize(24);
        font.setBold(true);
        lSaludo->setFont(font);

        gridLayout->addWidget(lSaludo, 0, 0, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);


        retranslateUi(Ventana);

        QMetaObject::connectSlotsByName(Ventana);
    } // setupUi

    void retranslateUi(QWidget *Ventana)
    {
        Ventana->setWindowTitle(QCoreApplication::translate("Ventana", "Form", nullptr));
        lSaludo->setText(QCoreApplication::translate("Ventana", "Hola,", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ventana: public Ui_Ventana {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANA_H
