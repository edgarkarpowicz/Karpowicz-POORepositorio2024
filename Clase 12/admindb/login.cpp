
#include "login.h"
#include "ui_login.h"
#include <QDebug>

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    ventana = new Ventana;

    connect(ui->leClave, SIGNAL(returnPressed()), this, SLOT(slot_validarUsuario()));

    adminDB = new AdminDB( this );
    qDebug() << "La base se abrio bien" << adminDB->conectar( "C:/Qt/db/usuarios.sqlite" );
}

Login::~Login()
{
    delete ui;
}

void Login::slot_validarUsuario()
{

    if ( adminDB->validarUsuario( "usuarios", ui->leUsuario->text(), ui->leClave->text() ) )  {
        ventana->show();
        this->close();
    }
    else  {
        this->close();
    }
}


