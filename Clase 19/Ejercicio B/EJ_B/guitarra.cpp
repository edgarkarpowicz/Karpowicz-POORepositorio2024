#include "guitarra.h"

Guitarra::Guitarra(QObject *parent, QString mar, float pre, int cant_cuer)
{
    marca = mar;
    precio = pre;
    cantidad_de_cuerdas = cant_cuer;
}

void Guitarra::afinar()
{
    qDebug() << "Afinando Guitarra";
}

void Guitarra::print_data()
{
    qDebug() << "Marca:" << marca;
    qDebug() << "Precio:" << precio;
    qDebug() << "Cantidad de Cuerdas:" << cantidad_de_cuerdas;
}
