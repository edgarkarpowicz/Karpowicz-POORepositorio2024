#ifndef TECLADO_H
#define TECLADO_H

#include <QObject>
#include <QDebug>

#include <Instrumento.h>

class Teclado : public Instrumento
{
    Q_OBJECT
    public:
        explicit Teclado(QObject *parent = nullptr, QString marca = NULL, float precio = NULL, int cantidad_de_teclas = NULL, QString metal = NULL);

        void afinar();

        void print_data();

    private:
        QString marca;
        float precio;
        int cantidad_de_teclas;
        QString metal_usado;
};

#endif // TECLADO_H
