// Programación Orientada a Objetos
// Parcial II - Ejercicio 1
// Edgar Karpowicz

#include "principal.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Principal w;
    w.show();

    return a.exec();
}
