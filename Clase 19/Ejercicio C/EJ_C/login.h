#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QFont>

#include <admindb.h>

class Login : public QWidget
{
    Q_OBJECT

    public:
        static Login * getInstancia();
        Login(QWidget *parent = nullptr);
        ~Login();

    private:
        QGridLayout* layout;
        QLabel* lUsuario, *lPassword;
        QLineEdit* leUsuario, *lePassword;
        QPushButton* pbIngresar;

        static Login* instancia;

        AdminDB* admindb;

    private slots:
        void slot_verificar_usuario();

    signals:
        void signal_ir_ventana();

};
#endif // LOGIN_H
