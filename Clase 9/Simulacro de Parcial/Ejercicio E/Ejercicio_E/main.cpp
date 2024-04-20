// Edgar Mario Karpowicz
// Programación Orientada a Objetos
// Simulacro Parcial - Ejercicio E

#include <QApplication>
#include "ventana.h"

int main (int argc, char** argv) {
    QApplication a(argc, argv);
    Ventana ventana;

    ventana.show();

    return a.exec();
}
