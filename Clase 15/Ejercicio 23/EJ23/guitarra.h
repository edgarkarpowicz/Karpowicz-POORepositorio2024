#ifndef GUITARRA_H
#define GUITARRA_H

#include <QObject>

#include <instrumento.h>

class Guitarra : public Instrumento
{
    Q_OBJECT
    public:
        explicit Guitarra(QObject *parent = nullptr);

        Guitarra(int cue) : cuerdas(cue) {}

        void sonar();
        void verlo();

        void set_Cuerdas(int cue);

    private:
        int cuerdas;
};

inline void Guitarra::set_Cuerdas(int cue) {
    this->cuerdas = cue;
}

#endif // GUITARRA_H
