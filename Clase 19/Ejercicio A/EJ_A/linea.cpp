#include "linea.h"

Linea::Linea(QObject *parent, const int initial_x, const int initial_y, const int final_x, const int final_y)
    : QObject{parent}, x_Inicial(initial_x), y_Inicial(initial_y), x_Final(final_x), y_Final(final_y)
{}

const int Linea::get_x_Inicial()
{
    return x_Inicial;
}

const int Linea::get_y_Inicial()
{
    return y_Inicial;
}

const int Linea::get_x_Final()
{
    return x_Final;
}

const int Linea::get_y_Final()
{
    return y_Final;
}
