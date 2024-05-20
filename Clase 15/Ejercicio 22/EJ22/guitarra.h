#ifndef GUITARRA_H
#define GUITARRA_H

#include <QObject>

#include <instrumento.h>

class Guitarra : public Instrumento
{
    Q_OBJECT
    public:
        explicit Guitarra(QObject *parent = nullptr);

        void sonar();
        void verlo();

        void set_Cuerdas(int cue);

    private:
        int cuerdas;
};

#endif // GUITARRA_H
