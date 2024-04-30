/********************************************************************************
** Form generated from reading UI file 'painter.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAINTER_H
#define UI_PAINTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Painter
{
public:

    void setupUi(QWidget *Painter)
    {
        if (Painter->objectName().isEmpty())
            Painter->setObjectName("Painter");
        Painter->resize(600, 512);
        Painter->setMinimumSize(QSize(600, 512));
        Painter->setMaximumSize(QSize(600, 512));

        retranslateUi(Painter);

        QMetaObject::connectSlotsByName(Painter);
    } // setupUi

    void retranslateUi(QWidget *Painter)
    {
        Painter->setWindowTitle(QCoreApplication::translate("Painter", "Painter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Painter: public Ui_Painter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAINTER_H
