#include <QCoreApplication>
#include <QDebug>

#include <bateria.h>
#include <guitarra.h>
#include <teclado.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Bateria* batOne = new Bateria();
    Guitarra* guitOne = new Guitarra();
    Guitarra* guitTwo = new Guitarra();
    Bateria* batTwo = new Bateria();
    Teclado* tecOne = new Teclado();

    std::vector <Instrumento*> vec;

    vec.push_back(batOne);
    vec.push_back(guitOne);
    vec.push_back(guitTwo);
    vec.push_back(batTwo);
    vec.push_back(tecOne);

    int control = 0;

    while (control != vec.size()) {
        qDebug() << "En la Posicion" << control + 1 << "el Instrumento es de Marca "  << vec.at(control)->get_Marca();
        vec.at(control)->sonar();
        control++;
    }

    return a.exec();
}
