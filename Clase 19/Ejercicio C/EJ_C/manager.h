#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include <login.h>
#include <ventana.h>

class Manager : public QObject
{
    Q_OBJECT
    public:
        explicit Manager(QObject *parent = nullptr);

        Login* login;
        Ventana* ventana;

    private slots:
        void slot_ir_ventana();
};

#endif // MANAGER_H
