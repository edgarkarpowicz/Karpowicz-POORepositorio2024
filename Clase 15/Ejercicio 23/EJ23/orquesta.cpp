#include "orquesta.h"

Orquesta::Orquesta(QObject *parent)
    : QObject(parent)
{
}

Orquesta::Orquesta(std::vector<Instrumento*> sent, QObject *parent)
    : QObject(parent), vec(sent)
{
}

void Orquesta::agregarInstrumento(Bateria* bat)
{
    vec.push_back(bat);
}

void Orquesta::agregarInstrumento(Guitarra* guit)
{
    vec.push_back(guit);
}

void Orquesta::agregarInstrumento(Teclado* tec)
{
    vec.push_back(tec);
}

void Orquesta::setVec(std::vector<Instrumento*> sent)
{
    vec = sent;
}

void Orquesta::showOrquesta()
{
    int control = 0;

    while (control != vec.size()) {
        qDebug() << "En la Posicion" << control + 1 << "el Instrumento es de Marca " << vec.at(control)->get_Marca();
        vec.at(control)->sonar();
        control++;
    }
}
