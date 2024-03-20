#include <QCoreApplication>
#include <iostream>
#include "MiClase.h"
using namespace std;

void Separacion() {
    for(int X = 0; X < 50; X++) {
        cout << "-";
    }
    cout << endl;
}

void Ejecucion() {
    Calculadora* POINTER = new Calculadora();
    cout << "Calculadora Simple" << endl;
    Separacion();
    cout << "Bienvenido" << endl;

    int X = -1;
    char OP;
    while (X == -1) {
        cout << "Ingrese la Operacion que desea realizar" << endl;
        cout << "Las Operaciones Validas son: +, -, *, /" << endl;
        Separacion();
        cin >> OP;
        X = POINTER->setOperador(OP);
        Separacion();
    }

    float OP1, OP2;
    cout << "Ingrese su Primer Operando" << endl;
    Separacion();
    cin >> OP1;
    POINTER->setOperandoUno(OP1);
    Separacion();
    cout << "Ingrese su Segundo Operando" << endl;
    Separacion();
    cin >> OP2;
    POINTER->setOperandoDos(OP2);
    Separacion();
    float RESULT = POINTER->Operar();
    cout << "Su Resultado es: " << RESULT << endl;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Ejecucion();
    return a.exec();
}
