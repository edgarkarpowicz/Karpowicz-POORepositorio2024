#ifndef VIENTO_H
#define VIENTO_H

#include <QObject>
#include <QDebug>

#include <Instrumento.h>

class Viento : public Instrumento
{
    Q_OBJECT
    public:
        explicit Viento(QObject *parent = nullptr, QString marca = NULL, float precio = NULL, int cantidad_de_cuerdas = NULL, QString metal = NULL);

        void afinar();

        void print_data();

    private:
        QString marca;
        float precio;
        int cantidad_de_cuerdas;
        QString metal_usado;
};

#endif // VIENTO_H
