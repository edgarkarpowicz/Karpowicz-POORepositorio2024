#ifndef MAPA_H
#define MAPA_H

#include <QWidget>
#include <QPainter>

class Mapa : public QWidget {
    Q_OBJECT
    protected:
        void paintEvent(QPaintEvent*);
};

#endif // MAPA_H
