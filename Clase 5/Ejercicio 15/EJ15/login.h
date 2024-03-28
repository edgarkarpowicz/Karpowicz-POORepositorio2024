#ifndef LOGIN_H
#define LOGIN_H

#include <QApplication>
#include <QWidget>
#include <QGridLayout> // Sistema de Grillas del QT
#include <QPushButton> // Para crear Botones
#include <QLabel>
#include <QLineEdit>
#include <form.h>

// Al ser la Clase o tener la frase Q_OBJECT, le habilita crear sus propias señales
// Entonces, ahora tiene para usar public, private, protected, signals, private slots, public slots.

class Login : public QWidget {
    Q_OBJECT
    private:
        QLabel* lUsuario, *lClave;
        QLineEdit* leUsuario, *leClave;
        QPushButton* pbEntrar;
        QGridLayout* layout;

    public:
        Login();

    private slots:
        void slot_validarUsuario(); // La Sintaxis de los Nombres de Variable de slots es slot_(para que sirve)
};

#endif // LOGIN_H
