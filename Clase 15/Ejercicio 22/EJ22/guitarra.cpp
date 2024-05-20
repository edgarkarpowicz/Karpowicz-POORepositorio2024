#include "guitarra.h"

Guitarra::Guitarra(QObject *parent)
{
    this->Instrumento::set_Marca("Yamaha");
    this->set_Cuerdas(6);
}

void Guitarra::sonar() {
    qDebug() << "Guitarra suena...";
}

void Guitarra::verlo() {
    qDebug() << "La Marca es: " << this->get_Marca();
}

void Guitarra::set_Cuerdas(int cue) {
    cuerdas = cue;
}
