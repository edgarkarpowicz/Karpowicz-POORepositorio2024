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

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QGridLayout *gridLayout;
    QPushButton *pbValidar;
    QLabel *lClave;
    QLabel *lUsuario;
    QSpacerItem *horizontalSpacer;
    QLineEdit *leClave;
    QLineEdit *leUsuario;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(312, 134);
        gridLayout = new QGridLayout(Login);
        gridLayout->setObjectName("gridLayout");
        pbValidar = new QPushButton(Login);
        pbValidar->setObjectName("pbValidar");
        pbValidar->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pbValidar, 4, 1, 1, 1);

        lClave = new QLabel(Login);
        lClave->setObjectName("lClave");

        gridLayout->addWidget(lClave, 3, 0, 1, 1);

        lUsuario = new QLabel(Login);
        lUsuario->setObjectName("lUsuario");

        gridLayout->addWidget(lUsuario, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 2, 1, 1);

        leClave = new QLineEdit(Login);
        leClave->setObjectName("leClave");
        leClave->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(leClave, 3, 1, 1, 2);

        leUsuario = new QLineEdit(Login);
        leUsuario->setObjectName("leUsuario");

        gridLayout->addWidget(leUsuario, 1, 1, 1, 2);


        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Login", nullptr));
        pbValidar->setText(QCoreApplication::translate("Login", "Validar", nullptr));
        lClave->setText(QCoreApplication::translate("Login", "Clave", nullptr));
        lUsuario->setText(QCoreApplication::translate("Login", "Usuario", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
