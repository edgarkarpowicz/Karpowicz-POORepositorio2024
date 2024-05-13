#include "registro.h"
#include "ui_registro.h"

Registro::Registro(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Registro)
{
    ui->setupUi(this);

    adminDB = new AdminDB( this );
    qDebug() << "La base se abrio bien" << adminDB->conectar( "C:/Qt/db/usuarios.sqlite" );

    connect(ui->pbRegistrase, SIGNAL(clicked(bool)), this, SLOT(slot_registrarUsuario()));
}

Registro::~Registro()
{
    delete ui;
}

void Registro::slot_registrarUsuario() {
    if (ui->leUsuario->text() != "" && ui->leClave->text() != "" && ui->leNombre->text() != "" && ui->leApellido->text() != "" && ui->leCorreo->text() != "") {
        if (adminDB->existeUsuario("usuarios", ui->leUsuario->text()) == true) {
            ui->pbRegistrase->setText("Usuario ya Existe - Intente con otro Usuario");
        } else {
            adminDB->ingresarUsuario("usuarios", ui->leUsuario->text(), ui->leClave->text(), ui->leNombre->text(), ui->leApellido->text(), ui->leCorreo->text());
            this->close();
        }
    }
}
