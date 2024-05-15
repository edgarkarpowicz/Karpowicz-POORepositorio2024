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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QGridLayout *gridLayout;
    QLabel *lUsuario;
    QLabel *lClave;
    QPushButton *pbRegistrarse;
    QLineEdit *leClave;
    QLineEdit *leUsuario;
    QPushButton *pbIngresar;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(438, 286);
        gridLayout = new QGridLayout(Login);
        gridLayout->setObjectName("gridLayout");
        lUsuario = new QLabel(Login);
        lUsuario->setObjectName("lUsuario");

        gridLayout->addWidget(lUsuario, 0, 0, 1, 1);

        lClave = new QLabel(Login);
        lClave->setObjectName("lClave");

        gridLayout->addWidget(lClave, 1, 0, 1, 1);

        pbRegistrarse = new QPushButton(Login);
        pbRegistrarse->setObjectName("pbRegistrarse");

        gridLayout->addWidget(pbRegistrarse, 2, 2, 1, 1);

        leClave = new QLineEdit(Login);
        leClave->setObjectName("leClave");
        leClave->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(leClave, 1, 1, 1, 2);

        leUsuario = new QLineEdit(Login);
        leUsuario->setObjectName("leUsuario");
        leUsuario->setEchoMode(QLineEdit::Normal);

        gridLayout->addWidget(leUsuario, 0, 1, 1, 2);

        pbIngresar = new QPushButton(Login);
        pbIngresar->setObjectName("pbIngresar");

        gridLayout->addWidget(pbIngresar, 2, 0, 1, 2);


        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Login", nullptr));
        lUsuario->setText(QCoreApplication::translate("Login", "Usuario:", nullptr));
        lClave->setText(QCoreApplication::translate("Login", "Clave:", nullptr));
        pbRegistrarse->setText(QCoreApplication::translate("Login", "Registrarse", nullptr));
        pbIngresar->setText(QCoreApplication::translate("Login", "Ingresar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
