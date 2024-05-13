/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "milabel.h"

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QGridLayout *gridLayout;
    QPushButton *pbIngresar;
    QLabel *lClave;
    QLabel *lUsuario;
    QSpacerItem *horizontalSpacer;
    MiLabel *lRegistrarse;
    QLineEdit *leClave;
    QLineEdit *leUsuario;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(493, 196);
        gridLayout = new QGridLayout(Login);
        gridLayout->setObjectName("gridLayout");
        pbIngresar = new QPushButton(Login);
        pbIngresar->setObjectName("pbIngresar");

        gridLayout->addWidget(pbIngresar, 2, 1, 1, 1);

        lClave = new QLabel(Login);
        lClave->setObjectName("lClave");

        gridLayout->addWidget(lClave, 1, 0, 1, 1);

        lUsuario = new QLabel(Login);
        lUsuario->setObjectName("lUsuario");

        gridLayout->addWidget(lUsuario, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 2, 1, 1);

        lRegistrarse = new MiLabel(Login);
        lRegistrarse->setObjectName("lRegistrarse");

        gridLayout->addWidget(lRegistrarse, 2, 3, 1, 1);

        leClave = new QLineEdit(Login);
        leClave->setObjectName("leClave");

        gridLayout->addWidget(leClave, 1, 1, 1, 3);

        leUsuario = new QLineEdit(Login);
        leUsuario->setObjectName("leUsuario");

        gridLayout->addWidget(leUsuario, 0, 1, 1, 3);


        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Login", nullptr));
        pbIngresar->setText(QCoreApplication::translate("Login", "ingresar", nullptr));
        lClave->setText(QCoreApplication::translate("Login", "Clave", nullptr));
        lUsuario->setText(QCoreApplication::translate("Login", "Usuario", nullptr));
        lRegistrarse->setText(QCoreApplication::translate("Login", "Registrarse", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
