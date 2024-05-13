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
    QLabel *lClave;
    QLineEdit *leUsuario;
    QLineEdit *leClave;
    QPushButton *pbEsconder;
    QLineEdit *leTemperatura;
    QLineEdit *leURL;
    QPushButton *pbIngresar;
    QLabel *lUsuario;
    QLabel *lTemperatura;
    QPushButton *pbRegistro;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(698, 241);
        gridLayout = new QGridLayout(Login);
        gridLayout->setObjectName("gridLayout");
        lClave = new QLabel(Login);
        lClave->setObjectName("lClave");

        gridLayout->addWidget(lClave, 2, 0, 1, 1);

        leUsuario = new QLineEdit(Login);
        leUsuario->setObjectName("leUsuario");

        gridLayout->addWidget(leUsuario, 1, 1, 1, 1);

        leClave = new QLineEdit(Login);
        leClave->setObjectName("leClave");
        leClave->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(leClave, 2, 1, 1, 1);

        pbEsconder = new QPushButton(Login);
        pbEsconder->setObjectName("pbEsconder");

        gridLayout->addWidget(pbEsconder, 3, 0, 1, 1);

        leTemperatura = new QLineEdit(Login);
        leTemperatura->setObjectName("leTemperatura");
        leTemperatura->setReadOnly(true);

        gridLayout->addWidget(leTemperatura, 0, 1, 1, 1);

        leURL = new QLineEdit(Login);
        leURL->setObjectName("leURL");
        QFont font;
        font.setBold(true);
        leURL->setFont(font);
        leURL->setReadOnly(true);

        gridLayout->addWidget(leURL, 5, 0, 1, 2);

        pbIngresar = new QPushButton(Login);
        pbIngresar->setObjectName("pbIngresar");

        gridLayout->addWidget(pbIngresar, 3, 1, 1, 1);

        lUsuario = new QLabel(Login);
        lUsuario->setObjectName("lUsuario");

        gridLayout->addWidget(lUsuario, 1, 0, 1, 1);

        lTemperatura = new QLabel(Login);
        lTemperatura->setObjectName("lTemperatura");

        gridLayout->addWidget(lTemperatura, 0, 0, 1, 1);

        pbRegistro = new QPushButton(Login);
        pbRegistro->setObjectName("pbRegistro");

        gridLayout->addWidget(pbRegistro, 4, 0, 1, 2);


        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Login", nullptr));
        lClave->setText(QCoreApplication::translate("Login", "Clave:", nullptr));
        pbEsconder->setText(QCoreApplication::translate("Login", "Esconder Temperatura", nullptr));
        pbIngresar->setText(QCoreApplication::translate("Login", "Ingresar", nullptr));
        lUsuario->setText(QCoreApplication::translate("Login", "Usuario:", nullptr));
        lTemperatura->setText(QCoreApplication::translate("Login", "Temperatura (C\303\263rdoba):", nullptr));
        pbRegistro->setText(QCoreApplication::translate("Login", "Registrar una nueva Cuenta", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
