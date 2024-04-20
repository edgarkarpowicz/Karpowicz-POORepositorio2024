// login.h

#ifndef LOGIN_H
#define LOGIN_H

#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

#include <editor.h>

class Login : public QWidget {
    Q_OBJECT
private:
    QLabel* lUsuario, *lClave;
    QLineEdit* leUsuario, *leClave;
    QPushButton* pbIngresar;
    QGridLayout* layout;

    Editor* editor;

public:
    Login();

private slots:
    void slot_verificar_usuario();
};

#endif // LOGIN_H
