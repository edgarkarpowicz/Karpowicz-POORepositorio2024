#include "rectangulo.h"

Rectangulo::Rectangulo(const int x, const int y, const int ancho, const int alto)
    : x(x), y(y), ancho(ancho), alto(alto)
{

}

const int Rectangulo::get_x() {
    return x;
}

const int Rectangulo::get_y() {
    return y;
}

const int Rectangulo::get_ancho() {
    return ancho;
}

const int Rectangulo::get_alto() {
    return alto;
}
