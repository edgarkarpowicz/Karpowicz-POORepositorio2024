#ifndef ORQUESTA_H
#define ORQUESTA_H

#include <vector>
#include <bateria.h>
#include <guitarra.h>
#include <teclado.h>

class Orquesta : public QObject {
    Q_OBJECT
public:
    explicit Orquesta(QObject *parent = nullptr);
    Orquesta(std::vector<Instrumento*> sent, QObject *parent = nullptr);

    void agregarInstrumento(Bateria* bat);
    void agregarInstrumento(Guitarra* guit);
    void agregarInstrumento(Teclado* tec);

    void setVec(std::vector<Instrumento*> sent);
    void showOrquesta();

private:
    std::vector<Instrumento*> vec;
};

#endif // ORQUESTA_H
