#ifndef BLOCKED_H
#define BLOCKED_H

#include <QApplication>
#include <QWidget>
#include <QGridLayout> // Sistema de Grillas del QT
#include <QPushButton> // Para crear Botones
#include <QLabel>
#include <QLineEdit>
#include <QTimer>

// Al ser la Clase o tener la frase Q_OBJECT, le habilita crear sus propias señales
// Entonces, ahora tiene para usar public, private, protected, signals, private slots, public slots.

class Blocked : public QWidget {
    Q_OBJECT
private:
    QLabel* lBloqueado;
    QPushButton* pbSalir;
    QGridLayout* layout;

public:
    Blocked();

private slots:
    void finalizar_Programa();
};

#endif // BLOCKED_H
