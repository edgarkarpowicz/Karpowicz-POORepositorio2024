// Programación Orientada a Objetos
// Clase 11 - Ejercicio 19
// Edgar Karpowicz

#include "painter.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Painter w;
    w.show();

    return a.exec();
}
