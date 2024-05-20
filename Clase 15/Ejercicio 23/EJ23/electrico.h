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

inline void Electrico::set_Voltaje(int volt) {
    this->voltaje = volt;
}

#endif // ELECTRICO_H
