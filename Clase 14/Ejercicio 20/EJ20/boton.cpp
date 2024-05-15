#include "boton.h"

Boton::Boton(QWidget *parent)
    : QWidget{parent}
{

}

void Boton::setColor(Color col)
{
    color = col;
    this->repaint();
}

void Boton::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    if (color == Color::ROJO) {
        painter.fillRect(0, 0, this->width(), this->height(), Qt::red);
    } else if (color == Color::AZUL) {
        painter.fillRect(0, 0, this->width(), this->height(), Qt::blue);
    } else if (color == Color::MAGENTA) {
        painter.fillRect(0, 0, this->width(), this->height(), Qt::magenta);
    } else {
        painter.fillRect(0, 0, this->width(), this->height(), Qt::darkGreen);
    }
}

void Boton::mousePressEvent(QMouseEvent *event)
{
    emit signal_click();
}
