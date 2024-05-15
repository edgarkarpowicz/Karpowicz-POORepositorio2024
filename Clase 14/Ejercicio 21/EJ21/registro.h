#ifndef REGISTRO_H
#define REGISTRO_H

#include <QWidget>
#include <admindb.h>

namespace Ui {
class Registro;
}

class Registro : public QWidget
{
    Q_OBJECT

    public:
        explicit Registro(QWidget *parent = nullptr);
        ~Registro();

    private:
        Ui::Registro *ui;
        AdminDB* adminDB;

    private slots:
        void slot_registrarUsuario();
        void slot_go_to_login();

    signals:
        void signal_go_to_login();
};

#endif // REGISTRO_H
