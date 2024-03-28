#ifndef FORM_H
#define FORM_H

#include <QApplication>
#include <QWidget>
#include <QGridLayout> // Sistema de Grillas del QT
#include <QPushButton> // Para crear Botones
#include <QLabel>
#include <QLineEdit>

// Al ser la Clase o tener la frase Q_OBJECT, le habilita crear sus propias señales
// Entonces, ahora tiene para usar public, private, protected, signals, private slots, public slots.

class Form : public QWidget {
    Q_OBJECT
    private:
        QLabel* lLegajo, *lNombre, *lApellido, *lCaptcha, *lCaptchaValue;
        QLineEdit* leLegajo, *leNombre, *leApellido;
        QPushButton* pbAlta;
        QGridLayout* layout;

    public:
        Form();

    private slots:
        void finalizar_Programa();
};

#endif // FORM_H
