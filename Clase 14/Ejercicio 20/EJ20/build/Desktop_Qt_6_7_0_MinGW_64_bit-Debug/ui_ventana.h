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
#include <QtWidgets/QWidget>
#include "boton.h"

QT_BEGIN_NAMESPACE

class Ui_Ventana
{
public:
    Boton *WidgetOne;
    Boton *WidgetTwo;
    Boton *WidgetThree;
    Boton *WidgetFour;
    Boton *WidgetFive;

    void setupUi(QWidget *Ventana)
    {
        if (Ventana->objectName().isEmpty())
            Ventana->setObjectName("Ventana");
        Ventana->resize(460, 262);
        Ventana->setMinimumSize(QSize(460, 262));
        Ventana->setMaximumSize(QSize(460, 262));
        WidgetOne = new Boton(Ventana);
        WidgetOne->setObjectName("WidgetOne");
        WidgetOne->setGeometry(QRect(60, 10, 341, 41));
        WidgetOne->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 9pt \"Segoe Script\";"));
        WidgetTwo = new Boton(Ventana);
        WidgetTwo->setObjectName("WidgetTwo");
        WidgetTwo->setGeometry(QRect(60, 60, 341, 41));
        WidgetTwo->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 9pt \"Segoe Script\";"));
        WidgetThree = new Boton(Ventana);
        WidgetThree->setObjectName("WidgetThree");
        WidgetThree->setGeometry(QRect(60, 110, 341, 41));
        WidgetThree->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 9pt \"Segoe Script\";"));
        WidgetFour = new Boton(Ventana);
        WidgetFour->setObjectName("WidgetFour");
        WidgetFour->setGeometry(QRect(60, 160, 341, 41));
        WidgetFour->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 9pt \"Segoe Script\";"));
        WidgetFive = new Boton(Ventana);
        WidgetFive->setObjectName("WidgetFive");
        WidgetFive->setGeometry(QRect(60, 210, 341, 41));
        WidgetFive->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 9pt \"Segoe Script\";"));

        retranslateUi(Ventana);

        QMetaObject::connectSlotsByName(Ventana);
    } // setupUi

    void retranslateUi(QWidget *Ventana)
    {
        Ventana->setWindowTitle(QCoreApplication::translate("Ventana", "Ventana", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ventana: public Ui_Ventana {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANA_H
