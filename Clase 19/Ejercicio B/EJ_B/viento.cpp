#include "viento.h"

Viento::Viento(QObject *parent, QString mar, float pre, int cant_cuer, QString met)
{
    marca = mar;
    precio = pre;
    cantidad_de_cuerdas = cant_cuer;
    metal_usado = met;
}

void Viento::afinar()
{
    qDebug() << "Afinando Viento";
}

void Viento::print_data()
{
    qDebug() << "Marca:" << marca;
    qDebug() << "Precio:" << precio;
    qDebug() << "Cantidad de Cuerdas:" << cantidad_de_cuerdas;
    qDebug() << "Metal Usado:" << metal_usado;
}
