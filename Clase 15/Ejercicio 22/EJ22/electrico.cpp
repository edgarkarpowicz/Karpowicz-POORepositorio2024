#include "electrico.h"

Electrico::Electrico(QObject *parent)
{
    this->voltaje = 220;
}

Electrico::~Electrico() {
    qDebug() << "Desenchufado";
}

void Electrico::set_Voltaje(int volt) {
    this->voltaje = volt;
}
