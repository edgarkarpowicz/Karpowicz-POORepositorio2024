#ifndef TECLADO_H
#define TECLADO_H

#include <QObject>

#include <instrumento.h>
#include <electrico.h>

class Teclado : public Instrumento, public Electrico
{
    Q_OBJECT
    public:
        explicit Teclado(QObject *parent = nullptr);

        Teclado(int tec) : teclas(tec) {}

        void sonar();
        void verlo();

        void set_Teclas(int tec);

    private:
        int teclas;
};

inline void Teclado::set_Teclas(int tec) {
    this->teclas = tec;
}

#endif // TECLADO_H
