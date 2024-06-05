// Programación Orientada a Objetos
// Parcial II - Ejercicio 2
// Edgar Karpowicz

#include <admin.h>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Admin* admin = new Admin();

    return a.exec();
}
