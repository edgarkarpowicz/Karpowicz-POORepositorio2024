#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string>* OrdenarAlfabeticamente(vector<string>* POINTER) {
    sort(POINTER->begin(), POINTER->end());
    return POINTER;
}

void Ejecucion() {
    vector<string>* POINTER = new vector<string>;
    for(int X = 0; X < 5; X++) {
        string STORAGE;
        cout << "Ingrese su Palabra NUM " << (X + 1) << endl;
        std::cin >> STORAGE;
        POINTER->push_back(STORAGE);
    }

    cout << "Las Palabras Ingresadas por usted han sido: " << endl;
    for(int X = 0; X < 5; X++) {
        cout << POINTER->at(X) << endl;
    }

    OrdenarAlfabeticamente(POINTER);

    cout << "Las Palabras Ingresadas por usted en Orden Alfabetico han sido: " << endl;
    for(int X = 0; X < 5; X++) {
        cout << POINTER->at(X) << endl;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Ejecucion();
    return a.exec();
}
