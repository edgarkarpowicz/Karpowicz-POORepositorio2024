// ventana.cpp

#include "ventana.h"
#include "ui_ventana.h"

Ventana::Ventana(QWidget *parent) // Constructor de la Clase Ventana
    : QWidget(parent)
    , ui(new Ui::Ventana)
{
    ui->setupUi(this);
}

Ventana::~Ventana() // Desconstructor o Destructor de la Clase Ventana
{
    delete ui;
}

void Ventana::set_user(QString nom) { // Se usa para poner HOLA al Usuario que este entrando. Solo hay dos, ADMIN y USER, por ende solo hay estos dos casos. Esta función se usa en acceso.cpp y acceso.h
    if (nom == "admin") {
        ui->lSaludo->setText("Hola ADMIN"); // Setea el QLabel llamado lSaludo en HOLA ADMIN
    } else {
        ui->lSaludo->setText("Hola USER"); // Setea el QLabel llamado lSaludo en HOLA USER
    }
}
