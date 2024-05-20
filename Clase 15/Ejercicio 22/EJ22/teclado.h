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

        void sonar();
        void verlo();

        void set_Teclas(int tec);

    private:
        int teclas;
};

#endif // TECLADO_H
