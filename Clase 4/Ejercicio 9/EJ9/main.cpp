#include <QCoreApplication>
#include <iostream>
using namespace std;

void separacion() {
    for(int X = 0; X < 50; X++) {
        cout << "-";
    }
    cout << endl;
}

template<class T> void imprimir(T arr[], int cantidad, bool mayor_a_menor) {
    int i, j;
    float clave;
    for (i = 0; i < cantidad; i++) {
        clave = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > clave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = clave;
    }

    if(mayor_a_menor == 1) { // 1 = mayor a menor
        T* POINTER = new T [cantidad];
        int x = 0;
        for(i = cantidad - 1; i != -1; i--) {
            *(POINTER + x) = arr[i];
            x++;
        }
        arr = POINTER;
    }

    for(i = 0; i < cantidad - 1; i++) {
        cout << arr[i] << "-";
    }

    cout << arr[i] << endl;
    separacion();
}

void Flotante() {
    int size = 0;
    cout << "Ha seleccionado un Array Flotante" << endl;
    separacion();
    cout << "De que SIZE quiere su Array?" << endl;
    separacion();
    cin >> size;
    separacion();
    if (size <= 0) {
        cout << "No puede ingresar un SIZE menor o igual a 0" << endl;
        separacion();
        return;
    }

    float* arr_pointer = new float[size];

    float temp;
    for(int x = 0; x < size; x++) {
        cout << "Ingrese el Numero " << x + 1 << " de su Array" << endl;
        separacion();
        cin >> temp;
        separacion();
        *(arr_pointer + x) = temp;
    }

    int tempint = 0;
    cout << "Quiere que sea de Mayor a Menor (1) o Menor a Mayor (0)?" << endl;
    separacion();
    cin >> tempint;
    separacion();
    switch(tempint) {
        case 0:
        imprimir(arr_pointer, size, 0);
        break;

        case 1:
        imprimir(arr_pointer, size, 1);
        break;

        default:
        cout << "No ingreso ni 0 ni 1. Default es 0" << endl;
        separacion();
        imprimir(arr_pointer, size, 0);
        break;
    }
}

void Entero() {
    int size = 0;
    cout << "Ha seleccionado un Array Entero" << endl;
    separacion();
    cout << "De que SIZE quiere su Array?" << endl;
    separacion();
    cin >> size;
    separacion();
    if (size <= 0) {
        cout << "No puede ingresar un SIZE menor o igual a 0" << endl;
        separacion();
        return;
    }

    int* arr_pointer = new int[size];

    int temp;
    for(int x = 0; x < size; x++) {
        cout << "Ingrese el Numero " << x + 1 << " de su Array" << endl;
        separacion();
        cin >> temp;
        separacion();
        *(arr_pointer + x) = temp;
    }

    temp = 0;
    cout << "Quiere que sea de Mayor a Menor (1) o Menor a Mayor (0)?" << endl;
    separacion();
    cin >> temp;
    separacion();
    switch(temp) {
        case 0:
        imprimir(arr_pointer, size, 0);
        break;

        case 1:
        imprimir(arr_pointer, size, 1);
        break;

        default:
        cout << "No ingreso ni 0 ni 1. Default es 0" << endl;
        separacion();
        imprimir(arr_pointer, size, 0);
        break;
    }
}

void ejecucion() {
    int temp = 0;
    cout << "Bienvenido" << endl;
    separacion();
    while(true) {
        cout << "Cual tipo de Array quiere Ingresar y Organizar?" << endl;
        cout << "1 - Entero (INT)" << endl;
        cout << "2 - Flotante (FLOAT)" << endl;
        cout << "3 - Finalizar" << endl;
        separacion();
        cin >> temp;
        separacion();

        switch(temp) {
            case 1:
            Entero();
            break;

            case 2:
            Flotante();
            break;

            case 3:
            return;
            break;

            default:
            cout << "Ingreso no Valido. Reiniciando" << endl;
            break;
        }
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ejecucion();
    return a.exec();
}
