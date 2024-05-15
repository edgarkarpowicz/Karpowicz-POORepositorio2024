/********************************************************************************
** Form generated from reading UI file 'registro.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRO_H
#define UI_REGISTRO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Registro
{
public:
    QGridLayout *gridLayout;
    QLabel *lUsuario;
    QLineEdit *leUsuario;
    QLabel *lClave;
    QLineEdit *leClave;
    QLabel *lNombre;
    QLineEdit *leNombre;
    QLabel *lApellido;
    QLineEdit *leApellido;
    QLabel *lCorreo;
    QLineEdit *leCorreo;
    QPushButton *pbVolver;
    QPushButton *pbRegistrarse;

    void setupUi(QWidget *Registro)
    {
        if (Registro->objectName().isEmpty())
            Registro->setObjectName("Registro");
        Registro->resize(400, 300);
        gridLayout = new QGridLayout(Registro);
        gridLayout->setObjectName("gridLayout");
        lUsuario = new QLabel(Registro);
        lUsuario->setObjectName("lUsuario");

        gridLayout->addWidget(lUsuario, 0, 0, 1, 1);

        leUsuario = new QLineEdit(Registro);
        leUsuario->setObjectName("leUsuario");

        gridLayout->addWidget(leUsuario, 0, 1, 1, 1);

        lClave = new QLabel(Registro);
        lClave->setObjectName("lClave");

        gridLayout->addWidget(lClave, 1, 0, 1, 1);

        leClave = new QLineEdit(Registro);
        leClave->setObjectName("leClave");
        leClave->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(leClave, 1, 1, 1, 1);

        lNombre = new QLabel(Registro);
        lNombre->setObjectName("lNombre");

        gridLayout->addWidget(lNombre, 2, 0, 1, 1);

        leNombre = new QLineEdit(Registro);
        leNombre->setObjectName("leNombre");

        gridLayout->addWidget(leNombre, 2, 1, 1, 1);

        lApellido = new QLabel(Registro);
        lApellido->setObjectName("lApellido");

        gridLayout->addWidget(lApellido, 3, 0, 1, 1);

        leApellido = new QLineEdit(Registro);
        leApellido->setObjectName("leApellido");

        gridLayout->addWidget(leApellido, 3, 1, 1, 1);

        lCorreo = new QLabel(Registro);
        lCorreo->setObjectName("lCorreo");

        gridLayout->addWidget(lCorreo, 4, 0, 1, 1);

        leCorreo = new QLineEdit(Registro);
        leCorreo->setObjectName("leCorreo");

        gridLayout->addWidget(leCorreo, 4, 1, 1, 1);

        pbVolver = new QPushButton(Registro);
        pbVolver->setObjectName("pbVolver");

        gridLayout->addWidget(pbVolver, 5, 0, 1, 1);

        pbRegistrarse = new QPushButton(Registro);
        pbRegistrarse->setObjectName("pbRegistrarse");

        gridLayout->addWidget(pbRegistrarse, 5, 1, 1, 1);


        retranslateUi(Registro);

        QMetaObject::connectSlotsByName(Registro);
    } // setupUi

    void retranslateUi(QWidget *Registro)
    {
        Registro->setWindowTitle(QCoreApplication::translate("Registro", "Form", nullptr));
        lUsuario->setText(QCoreApplication::translate("Registro", "Usuario:", nullptr));
        lClave->setText(QCoreApplication::translate("Registro", "Clave:", nullptr));
        lNombre->setText(QCoreApplication::translate("Registro", "Nombre:", nullptr));
        lApellido->setText(QCoreApplication::translate("Registro", "Apellido:", nullptr));
        lCorreo->setText(QCoreApplication::translate("Registro", "Correo:", nullptr));
        pbVolver->setText(QCoreApplication::translate("Registro", "Volver", nullptr));
        pbRegistrarse->setText(QCoreApplication::translate("Registro", "Registrarse", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Registro: public Ui_Registro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRO_H
