#include "instrumento.h"

Instrumento::Instrumento(QObject *parent)
    : QObject{parent}
{

}

QString Instrumento::get_Marca() {
    return marca;
}

void Instrumento::set_Marca(QString marca) {
    this->marca = marca;
}
