// Edgar Mario Karpowicz
// Programación Orientada a Objetos
// Simulacro Parcial - Ejercicio A

#include <QApplication>
#include "login.h"

int main (int argc, char** argv) {
    QApplication a(argc, argv);
    Login login;

    login.show();

    return a.exec();
}
