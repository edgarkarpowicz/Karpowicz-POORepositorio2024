#include "manager.h"

Manager::Manager(QObject *parent)
    : QObject{parent}
{
    login = new Login();
    ventana = new Ventana();

    connect(login, SIGNAL(signal_ir_ventana()), this, SLOT(slot_ir_ventana()));

    login->show();
}

void Manager::slot_ir_ventana() {
    login->hide();
    ventana->show();
}
