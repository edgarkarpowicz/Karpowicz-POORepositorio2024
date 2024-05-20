#ifndef INSTRUMENTO_H
#define INSTRUMENTO_H

#include <QObject>
#include <QDebug>

class Instrumento : public QObject
{
    Q_OBJECT
    public:
        explicit Instrumento(QObject *parent = nullptr);
        void virtual sonar() { };
        void virtual verlo() { };

        QString get_Marca();
        void set_Marca(QString marca);

    private:
        QString marca;
};

#endif // INSTRUMENTO_H
