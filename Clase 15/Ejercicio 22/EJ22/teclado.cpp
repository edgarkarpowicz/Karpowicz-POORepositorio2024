#include "teclado.h"

Teclado::Teclado(QObject *parent)
{
    this->Instrumento::set_Marca("Yamaha");
    this->set_Teclas(61);
    this->Electrico::set_Voltaje(220);
}

void Teclado::sonar() {
    qDebug() << "Teclado suena...";
}

void Teclado::verlo() {
    qDebug() << "La Marca es: " << this->get_Marca();
}

void Teclado::set_Teclas(int tec) {
    teclas = tec;
}
