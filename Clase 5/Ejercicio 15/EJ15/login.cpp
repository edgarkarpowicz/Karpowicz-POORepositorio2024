//login.cpp

#include "login.h"


Login::Login() {

    lUsuario = new QLabel("Usuario");
    lClave = new QLabel("Clave");
    leUsuario = new QLineEdit;
    leClave = new QLineEdit;
    leClave->setEchoMode( QLineEdit::Password );
    pbEntrar = new QPushButton("Entrar");

    layout = new QGridLayout;
    layout->addWidget(lUsuario, 0, 0, 1, 1);
    layout->addWidget(lClave, 1, 0, 1, 1);
    layout->addWidget(leUsuario, 0, 1, 1, 2);
    layout->addWidget(leClave, 1, 1, 1, 2);
    layout->addWidget(pbEntrar, 2, 1, 1, 1);

    QObject::connect( pbEntrar, SIGNAL( clicked(bool) ), this , SLOT( slot_validarUsuario() ) );

    this->setLayout(layout);
}

void Login::slot_validarUsuario() {
    if (leUsuario->text() == "admin" && leClave->text() == "1234") {
        Form* form_point = new Form;
        form_point->show();
        this->hide();
    } else {
        QApplication::quit();
    }
}
