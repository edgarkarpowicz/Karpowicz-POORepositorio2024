#include "admin.h"

Admin::Admin(QObject *parent)
    : QObject{parent}
{
    login = new Login();
    login->show();


    ventana = new Ventana();

    connect(login, SIGNAL(signal_usuarioValidado()), this, SLOT(slot_mostrar_ventana()));
}

void Admin::slot_mostrar_ventana() {
    login->hide();
    ventana->show();
}
