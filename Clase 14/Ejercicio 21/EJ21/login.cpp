#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    connect(ui->pbIngresar, SIGNAL(clicked(bool)), this, SLOT(slot_verificar_usuario()));
    connect(ui->leClave, SIGNAL(returnPressed()), this, SLOT(slot_verificar_usuario()));
    connect(ui->pbRegistrarse, SIGNAL(clicked(bool)), this, SLOT(slot_registrarse()));
}

Login::~Login()
{
    delete ui;
}

void Login::slot_verificar_usuario() {
    adminDB = new AdminDB( this );
    adminDB->conectar("C:/Qt/db/usuarios.sqlite");
    if (adminDB->validarUsuario( "usuarios", ui->leUsuario->text(), ui->leClave->text()))  {
        emit signal_logging_in();
        ui->leUsuario->setText("");
        ui->leClave->setText("");
        this->hide();
    }
    else  {
        ui->leClave->setText("");
    }
}

void Login::slot_registrarse() {
    emit signal_go_to_registry();
    ui->leUsuario->setText("");
    ui->leClave->setText("");
    this->hide();
}
