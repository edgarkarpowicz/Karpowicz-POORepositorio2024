#ifndef GUITARRA_H
#define GUITARRA_H

#include <QObject>
#include <QDebug>

#include <Instrumento.h>

class Guitarra : public Instrumento
{
    Q_OBJECT
    public:
        explicit Guitarra(QObject *parent = nullptr, QString marca = NULL, float precio = NULL, int cantidad_de_cuerdas = NULL);

        void afinar();

        void print_data();

    private:
        QString marca;
        float precio;
        int cantidad_de_cuerdas;
};

#endif // GUITARRA_H
