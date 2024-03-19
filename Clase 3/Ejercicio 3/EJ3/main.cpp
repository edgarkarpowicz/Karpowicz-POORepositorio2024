#include <QCoreApplication>
#include <iostream>
#include "MiBiblioteca.h"
using namespace std;

void Ejecucion() {
    cout << "Version de QT actual: ";
    EKFunctions::GET_LATEST_QT_VERSION();
    cout << "Version de la Libreria actual: ";
    EKFunctions::GET_LIBRARY_VERSION();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Ejecucion();
    return a.exec();
}
