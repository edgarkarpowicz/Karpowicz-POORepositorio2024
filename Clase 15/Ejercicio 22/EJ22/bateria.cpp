#include "bateria.h"

Bateria::Bateria(QObject *parent)
{
    this->Instrumento::set_Marca("Yamaha");
    this->set_Tambores(5);
}

void Bateria::sonar() {
    qDebug() << "Bateria suena...";
}

void Bateria::verlo() {
    qDebug() << "La Marca es: " << this->get_Marca();
}

void Bateria::set_Tambores(int tam) {
    tambores = tam;
}
