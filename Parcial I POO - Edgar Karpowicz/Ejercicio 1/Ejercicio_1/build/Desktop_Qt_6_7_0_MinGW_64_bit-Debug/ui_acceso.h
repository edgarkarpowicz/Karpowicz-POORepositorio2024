/********************************************************************************
** Form generated from reading UI file 'acceso.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCESO_H
#define UI_ACCESO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Acceso
{
public:
    QGridLayout *gridLayout;
    QPushButton *pbIngresar;
    QLabel *lClave;
    QLabel *lUsuario;
    QSpacerItem *horizontalSpacer;
    QLineEdit *leClave;
    QLineEdit *leUsuario;

    void setupUi(QWidget *Acceso)
    {
        if (Acceso->objectName().isEmpty())
            Acceso->setObjectName("Acceso");
        Acceso->resize(400, 200);
        Acceso->setMaximumSize(QSize(400, 200));
        gridLayout = new QGridLayout(Acceso);
        gridLayout->setObjectName("gridLayout");
        pbIngresar = new QPushButton(Acceso);
        pbIngresar->setObjectName("pbIngresar");
        pbIngresar->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pbIngresar, 4, 1, 1, 1);

        lClave = new QLabel(Acceso);
        lClave->setObjectName("lClave");

        gridLayout->addWidget(lClave, 3, 0, 1, 1);

        lUsuario = new QLabel(Acceso);
        lUsuario->setObjectName("lUsuario");

        gridLayout->addWidget(lUsuario, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 2, 1, 1);

        leClave = new QLineEdit(Acceso);
        leClave->setObjectName("leClave");
        leClave->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(leClave, 3, 1, 1, 2);

        leUsuario = new QLineEdit(Acceso);
        leUsuario->setObjectName("leUsuario");

        gridLayout->addWidget(leUsuario, 1, 1, 1, 2);


        retranslateUi(Acceso);

        QMetaObject::connectSlotsByName(Acceso);
    } // setupUi

    void retranslateUi(QWidget *Acceso)
    {
        Acceso->setWindowTitle(QCoreApplication::translate("Acceso", "Login", nullptr));
        pbIngresar->setText(QCoreApplication::translate("Acceso", "Ingresar", nullptr));
        lClave->setText(QCoreApplication::translate("Acceso", "Clave", nullptr));
        lUsuario->setText(QCoreApplication::translate("Acceso", "Usuario", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Acceso: public Ui_Acceso {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCESO_H
