#include <QCoreApplication>
#include <iostream>
using namespace std;

void Ejecucion() {
    int* POINTER = new int [10];
    cout << "Sus 10 Cifras Aleatorias para esta Sesion son: " << endl;
    for(int X = 0; X < 10; X++) {
        *(POINTER + X) = rand() % 20 + 2;
        cout << *(POINTER + X) << endl;
    }
    return;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Ejecucion();
    return a.exec();
}
