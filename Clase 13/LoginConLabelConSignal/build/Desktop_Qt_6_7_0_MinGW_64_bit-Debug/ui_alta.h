/********************************************************************************
** Form generated from reading UI file 'alta.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALTA_H
#define UI_ALTA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Alta
{
public:
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QLabel *label_2;

    void setupUi(QWidget *Alta)
    {
        if (Alta->objectName().isEmpty())
            Alta->setObjectName("Alta");
        Alta->resize(487, 234);
        gridLayout = new QGridLayout(Alta);
        gridLayout->setObjectName("gridLayout");
        label_3 = new QLabel(Alta);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lineEdit_3 = new QLineEdit(Alta);
        lineEdit_3->setObjectName("lineEdit_3");

        gridLayout->addWidget(lineEdit_3, 2, 1, 1, 2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 2, 1, 1);

        label = new QLabel(Alta);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(Alta);
        lineEdit->setObjectName("lineEdit");

        gridLayout->addWidget(lineEdit, 0, 1, 1, 2);

        lineEdit_2 = new QLineEdit(Alta);
        lineEdit_2->setObjectName("lineEdit_2");

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 2);

        pushButton = new QPushButton(Alta);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 3, 1, 1, 1);

        label_2 = new QLabel(Alta);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);


        retranslateUi(Alta);

        QMetaObject::connectSlotsByName(Alta);
    } // setupUi

    void retranslateUi(QWidget *Alta)
    {
        Alta->setWindowTitle(QCoreApplication::translate("Alta", "Form", nullptr));
        label_3->setText(QCoreApplication::translate("Alta", "DNI", nullptr));
        label->setText(QCoreApplication::translate("Alta", "Nombre", nullptr));
        pushButton->setText(QCoreApplication::translate("Alta", "Registrarse", nullptr));
        label_2->setText(QCoreApplication::translate("Alta", "Apellido", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Alta: public Ui_Alta {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALTA_H
