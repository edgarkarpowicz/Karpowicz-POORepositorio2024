#include "registro.h"
#include "ui_registro.h"

Registro::Registro(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Registro)
{
    ui->setupUi(this);

    connect(ui->pbRegistrarse, SIGNAL(clicked(bool)), this, SLOT(slot_registrarUsuario()));
    connect(ui->pbVolver, SIGNAL(clicked(bool)), this, SLOT(slot_go_to_login()));
}

Registro::~Registro()
{
    delete ui;
}

void Registro::slot_registrarUsuario() {
    adminDB = new AdminDB( this );
    adminDB->conectar("C:/Qt/db/usuarios.sqlite");
    if (ui->leUsuario->text() != "" && ui->leClave->text() != "" && ui->leNombre->text() != "" && ui->leApellido->text() != "" && ui->leCorreo->text() != "") {
        if (adminDB->existeUsuario("usuarios", ui->leUsuario->text()) == true) {
            ui->pbRegistrarse->setText("Usuario ya Existe - Intente con otro Usuario");
        } else {
            adminDB->ingresarUsuario("usuarios", ui->leUsuario->text(), ui->leClave->text(), ui->leNombre->text(), ui->leApellido->text(), ui->leCorreo->text());
            emit signal_go_to_login();
            ui->leNombre->setText("");
            ui->leApellido->setText("");
            ui->leClave->setText("");
            ui->leCorreo->setText("");
            ui->leUsuario->setText("");
            this->hide();
        }
    }
}

void Registro::slot_go_to_login() {
    emit signal_go_to_login();
    ui->leNombre->setText("");
    ui->leApellido->setText("");
    ui->leClave->setText("");
    ui->leCorreo->setText("");
    ui->leUsuario->setText("");
    this->hide();
}
