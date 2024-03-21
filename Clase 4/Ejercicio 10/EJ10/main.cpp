#include <QCoreApplication>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Jugador {
    private:
        int velocidad;
        int fuerza;
        string nombre;

    public:
        ~Jugador();
        Jugador();
        Jugador(int velocidad, int fuerza, string nombre);
        void setVelocidad(int velocidad);
        void setFuerza(int fuerza);
        void setNombre(string nombre);
        int getVelocidad();
        int getFuerza();
        string getNombre();
};

Jugador::~Jugador() {
    this->velocidad = 0;
    this->fuerza = 0;
    this->nombre = "Sin Nombre";
}

Jugador::Jugador() {
    this->velocidad = 0;
    this->fuerza = 0;
    this->nombre = "Sin Nombre";
}

Jugador::Jugador(int velocidad, int fuerza, string nombre) {
    this->velocidad = velocidad;
    this->fuerza = fuerza;
    this->nombre = nombre;
}

void Jugador::setVelocidad(int velocidad) {
    this->velocidad = velocidad;
}

void Jugador::setFuerza(int fuerza) {
    this->fuerza = fuerza;
}

void Jugador::setNombre(string nombre) {
    this->nombre = nombre;
}

int Jugador::getVelocidad() {
    return velocidad;
}

int Jugador::getFuerza() {
    return fuerza;
}

string Jugador::getNombre() {
    return nombre;
}

void separacion() {
    for(int i = 0; i < 50; i++) {
        cout << "-";
    }
    cout << endl;
}

void print_datos(vector<Jugador>* POINTER) {
    for(int x = 0; x < 9; x++) {
        cout << "Nombre: " << POINTER->at(x).getNombre() << " | Fuerza: " << POINTER->at(x).getFuerza() << " | Velocidad: " << POINTER->at(x).getVelocidad() << endl;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    vector<Jugador>* POINTER = new vector<Jugador>;

    POINTER->push_back(Jugador(2, 4, "Edgar"));
    POINTER->push_back(Jugador(1, 2, "Manuel"));
    POINTER->push_back(Jugador(6, 7, "Gonzalo"));
    POINTER->push_back(Jugador(8, 9, "Facundo"));
    POINTER->push_back(Jugador(12, 3, "Juan"));
    POINTER->push_back(Jugador(15, 6, "Waldo"));
    POINTER->push_back(Jugador(20, 3, "Jefe"));
    POINTER->push_back(Jugador(13, 8, "Comandante"));
    POINTER->push_back(Jugador(18, 18, "Otro"));
    POINTER->push_back(Jugador(23, 99, "Pedro"));

    print_datos(POINTER);
    return a.exec();
}
