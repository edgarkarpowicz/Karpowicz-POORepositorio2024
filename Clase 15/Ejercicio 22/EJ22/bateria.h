#ifndef BATERIA_H
#define BATERIA_H

#include <QObject>

#include <instrumento.h>

class Bateria : public Instrumento
{
    Q_OBJECT
    public:
        explicit Bateria(QObject *parent = nullptr);

        void sonar();
        void verlo();

        void set_Tambores(int tam);

    private:
        int tambores;
};

#endif // BATERIA_H
