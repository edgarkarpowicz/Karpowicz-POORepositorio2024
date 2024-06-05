#ifndef RECTANGULO_H
#define RECTANGULO_H

#include <QObject>

class Rectangulo
{
    public:
        Rectangulo( const int x = 0, const int y = 0, const int ancho = 100, const int alto = 100 );

        const int get_x();
        const int get_y();
        const int get_ancho();
        const int get_alto();

    private:
        const int x, y, ancho, alto;
};

#endif // RECTANGULO_H
