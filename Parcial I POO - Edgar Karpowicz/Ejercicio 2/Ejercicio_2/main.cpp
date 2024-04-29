// Edgar Mario Karpowicz
// Programación Orientada a Objetos
// Parcial - Ejercicio 2

#include <QApplication>
#include "descargador.h" // Incluimos a la Libería descargador.h que es donde se encuentra nuestra Clase llamada Descargador que vamos a instanciar en este Código

int main (int argc, char** argv) {
    QApplication a(argc, argv);
    Descargador descargador; // Instanciamos Descargador como descargador

    descargador.show(); // Mostramos descargador

    return a.exec();
}
