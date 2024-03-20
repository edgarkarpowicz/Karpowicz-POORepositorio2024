#include <QCoreApplication>
#include <iostream>
#include <vector>
using namespace std;

void Ejecucion() {
    vector<int>* POINTER = new vector<int>;
    for(int X = 0; X < 30; X++) {
        int TEMP_VAL = rand() % 15;
        POINTER->push_back(TEMP_VAL);
    }

    cout << "Sus Numeros son:" << endl;
    for(int X = 0; X < 30; X++) {
        cout << POINTER->at(X) << endl;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Ejecucion();
    return a.exec();
}
