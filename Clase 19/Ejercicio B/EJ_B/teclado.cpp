#include "teclado.h"

Teclado::Teclado(QObject *parent, QString mar, float pre, int cant_tec, QString met)
{
    marca = mar;
    precio = pre;
    cantidad_de_teclas = cant_tec;
    metal_usado = met;
}

void Teclado::afinar()
{
    qDebug() << "Afinando Teclado";
}

void Teclado::print_data()
{
    qDebug() << "Marca:" << marca;
    qDebug() << "Precio:" << precio;
    qDebug() << "Cantidad de Teclas:" << cantidad_de_teclas;
    qDebug() << "Metal Usado:" << metal_usado;
}
