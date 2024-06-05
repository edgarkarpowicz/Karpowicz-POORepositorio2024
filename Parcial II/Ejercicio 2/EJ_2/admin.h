#ifndef ADMIN_H
#define ADMIN_H

#include <QObject>

#include <login.h>
#include <ventana.h>

class Admin : public QObject
{
    Q_OBJECT
    public:
        explicit Admin(QObject *parent = nullptr);

    private:
        Login* login;
        Ventana* ventana;

    private slots:
        void slot_mostrar_ventana();
};

#endif // ADMIN_H
