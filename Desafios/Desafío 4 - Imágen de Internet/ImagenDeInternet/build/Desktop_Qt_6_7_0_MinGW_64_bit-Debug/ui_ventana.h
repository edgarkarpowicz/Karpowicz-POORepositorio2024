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

QT_BEGIN_NAMESPACE

class Ui_Ventana
{
public:

    void setupUi(QWidget *Ventana)
    {
        if (Ventana->objectName().isEmpty())
            Ventana->setObjectName("Ventana");
        Ventana->resize(800, 600);

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
