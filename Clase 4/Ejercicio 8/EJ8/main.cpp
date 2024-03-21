#include <QCoreApplication>
#include <iostream>
#include <string>
using namespace std;

void Separacion() {
    for(int X = 0; X < 50; X++) {
        cout << "-";
    }
    cout << endl;
}

class Persona  {
private:
    string nombre;
    float altura;

public:
    Persona(string nombre , float altura);

    void getDatos(string & nombre , float & altura);
    void setDatos(string nombre , float altura);
};

Persona::Persona(string nombre, float altura) {
    this->nombre = nombre;
    this->altura = altura;
}

void Persona::getDatos(string & nombre , float & altura)  {
    nombre = this->nombre;
    altura = this->altura;
}

void Persona::setDatos(string nombre , float altura )  {
    this->nombre = nombre;
    this->altura = altura;
}

class Poste  {
private:
    int altura;
    int seccion;

public:
    Poste( int altura, int seccion );

    void getDatos( int & altura, int & seccion );
    void setDatos( int altura, int seccion );
};

Poste::Poste( int altura, int seccion ) : altura( altura ), seccion( seccion )  {

}

void Poste::getDatos( int & altura, int & seccion )  {
    altura = this->altura;
    seccion = this->seccion;
}

void Poste::setDatos( int altura, int seccion )  {
    this->altura = altura;
    this->seccion = seccion;
}

template <class T> void Descripcion(T* pointer) {
    cout << typeid (T).name() << endl;
}

template <> void Descripcion<Persona>(Persona* pointer) {
    string nom;
    float alt;
    pointer->getDatos(nom, alt);
    string class_name = typeid(Persona).name();
    class_name.erase(class_name.begin());
    cout << "Es una " << class_name << " de Nombre " << nom << " con una Altura de " << alt << endl;
}

template <> void Descripcion<Poste>(Poste* pointer) {
    int altura;
    int seccion;
    pointer->getDatos(altura, seccion);
    string class_name = typeid(Poste).name();
    class_name.erase(class_name.begin());
    cout << "Es una " << class_name << " de Altura " << altura << " con una Seccion de " << seccion << endl;
}

void Ejecucion() {
    Poste* poste_pointer_uno = new Poste(5, 10);
    Poste* poste_pointer_dos = new Poste(10, 5);
    Persona* persona_pointer_uno = new Persona("Edgar", 1.78);
    Persona* persona_pointer_dos = new Persona("Manuel", 1.8);
    Descripcion(poste_pointer_uno);
    Descripcion(poste_pointer_dos);
    Descripcion(persona_pointer_uno);
    Descripcion(persona_pointer_dos);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Ejecucion();
    return a.exec();
}
