#ifndef ELECTRICO_H
#define ELECTRICO_H

#include <QDebug>

class Electrico
{
    public:
        explicit Electrico(QObject *parent = nullptr);
        ~Electrico();

        void set_Voltaje(int volt);

    private:
        int voltaje;
};

#endif // ELECTRICO_H
