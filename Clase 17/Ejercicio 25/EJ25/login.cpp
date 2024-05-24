#include "login.h"

Login::Login(QWidget *parent)
    : QWidget(parent)
{
    layout = new QGridLayout();

    lUsuario = new QLabel ("Usuario:");
    lPassword = new QLabel("Password:");
    lIngresar = new ClickableLabel("Ingresar");
    lRegistrar = new ClickableLabel("Registrar");

    QFont* font = new QFont();
    font->setBold(true);
    font->setCapitalization(font->AllUppercase);
    font->setPixelSize(12);

    lUsuario->setFont(*font);
    lPassword->setFont(*font);
    lIngresar->setFont(*font);
    lRegistrar->setFont(*font);

    leUsuario = new QLineEdit();
    lePassword = new QLineEdit();
    lePassword->setEchoMode(QLineEdit::Password);

    leUsuario->setPlaceholderText("Su Usuario");
    lePassword->setPlaceholderText("Su Password");

    layout->addWidget(lUsuario, 0, 0, 1, 1);
    layout->addWidget(leUsuario, 0, 1, 1, 1);
    layout->addWidget(lPassword, 1, 0, 1, 1);
    layout->addWidget(lePassword, 1, 1, 1, 1);
    layout->addWidget(lIngresar, 2, 1, 1, 1);
    layout->addWidget(lRegistrar, 3, 1, 1, 1);

    this->setLayout(layout);

    connect(lIngresar, SIGNAL(signal_clicked()), this, SLOT(slot_ingresar()));
    connect(lRegistrar, SIGNAL(signal_clicked()), this, SLOT(slot_registrar()));
    connect(this, SIGNAL(signal_go_to_tree()), this, SLOT(slot_tree()));
}

Login::~Login() {}

void Login::slot_ingresar() {
    admindb = new AdminDB( this );
    if (admindb->conectar("C:/Qt/db/usuarios.sqlite") == true) {
        if (admindb->validarUsuario( "usuarios", leUsuario->text(), lePassword->text()))  {
            qDebug() << "Exito Ingresando con el Usuario!";
            emit signal_go_to_tree();
        }
        else  {
            qDebug() << "Algo ha ido mal en el Ingreso.";
            lePassword->setText("");
        }
    } else {
        qDebug() << "No se pudo conectar a la DB";
    }
}

void Login::slot_registrar() {
    ventana = new Ventana();
    this->close();
    ventana->show();
}

void Login::slot_tree() {
    crud = new CRUD();
    this->hide();
}
