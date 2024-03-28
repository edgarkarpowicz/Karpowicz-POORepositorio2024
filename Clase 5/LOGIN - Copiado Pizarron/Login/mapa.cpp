#include <mapa.h>

void Mapa::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    painter.drawLine(0, 0, this->width(), this->height());
    QImage image("C:/img.jpg");
    painter.drawImage(0, 0, image);
}
