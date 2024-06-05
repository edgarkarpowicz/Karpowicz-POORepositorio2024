#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    admindb = new AdminDB();
    qDebug() << "La base se abrio bien" << admindb->conectar( "C:/Qt/db/base_poo.sqlite" );
    connect(ui->pbIngresar, SIGNAL(clicked(bool)), this, SLOT(slot_verificar_usuario()));
}

Login::~Login()
{
    delete ui;
}

void Login::slot_verificar_usuario() {
    qDebug() << "Intentando validar Usuario...";
    if (admindb->validarUsuario( "usuarios", ui->leUsuario->text(), ui->leClave->text()))  {
        qDebug() << "Usuario Validado!";
        emit signal_usuarioValidado();
    }
    else  {
        qDebug() << "Usuario no Validado!";
        ui->leClave->setText("");
    }
}
