#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QDebug>

#include <admindb.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class Login;
}
QT_END_NAMESPACE

class Login : public QWidget
{
    Q_OBJECT

    public:
        Login(QWidget *parent = nullptr);
        ~Login();

    private:
        Ui::Login *ui;

        AdminDB* admindb;

    signals:
        void signal_usuarioValidado();

    private slots:
        void slot_verificar_usuario();
};
#endif // LOGIN_H
