#ifndef INSTRUMENTO_H
#define INSTRUMENTO_H

#include <QObject>
#include <QDebug>

class Instrumento : public QObject
{
    Q_OBJECT
    public:
        explicit Instrumento(QObject *parent = nullptr);

        void virtual afinar() { };
        void virtual print_data() { };
};

#endif // INSTRUMENTO_H
