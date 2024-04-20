// Edgar Mario Karpowicz
// Programación Orientada a Objetos
// Simulacro Parcial - Ejercicio D

#include <QApplication>
#include "start.h"

int main (int argc, char** argv) {
    QApplication a(argc, argv);
    Start start;

    start.show();

    return a.exec();
}
