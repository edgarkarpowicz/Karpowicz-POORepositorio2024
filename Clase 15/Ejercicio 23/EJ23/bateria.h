#ifndef BATERIA_H
#define BATERIA_H

#include <QObject>

#include <instrumento.h>

class Bateria : public Instrumento
{
    Q_OBJECT
    public:
        explicit Bateria(QObject *parent = nullptr);

        Bateria(int tam) : tambores(tam) {}

        void sonar();
        void verlo();

        void set_Tambores(int tam);

    private:
        int tambores;
};

inline void Bateria::set_Tambores(int tam) {
    this->tambores = tam;
}

#endif // BATERIA_H
