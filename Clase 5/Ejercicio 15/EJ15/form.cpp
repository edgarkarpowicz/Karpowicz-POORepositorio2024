//login.cpp

#include "form.h"


Form::Form() {

    lLegajo = new QLabel("Legajo");
    lNombre = new QLabel("Nombre");
    lApellido = new QLabel("Apellido");
    lCaptcha = new QLabel("Captcha");

    int randValueCaptcha = ((rand() % 10000) + 1);
    lCaptchaValue = new QLabel((QString::number(randValueCaptcha)));

    leLegajo = new QLineEdit;
    leNombre = new QLineEdit;
    leApellido = new QLineEdit;
    pbAlta = new QPushButton("Alta");

    layout = new QGridLayout;
    layout->addWidget(lLegajo, 0, 0, 1, 1); // Primer Valor = Fila, Segundo Valor = Columna, Tercer Valor = Cuantas Filas va a ocupar, Cuarto Valor = Cuantas Columnas va a ocupar
    layout->addWidget(lNombre, 1, 0, 1, 1);
    layout->addWidget(lApellido, 2, 0, 1, 1);
    layout->addWidget(leLegajo, 0, 1, 1, 2);
    layout->addWidget(leNombre, 1, 1, 1, 2);
    layout->addWidget(leApellido, 2, 1, 1, 2);

    layout->addWidget(lCaptcha, 3, 0, 1, 1);
    layout->addWidget(lCaptchaValue, 4, 0, 1, 1);
    layout->addWidget(pbAlta, 3, 1, 2, 2);

    QObject::connect( pbAlta, SIGNAL( clicked(bool) ), this , SLOT ( finalizar_Programa() ) );

    this->setLayout(layout);
}

void Form::finalizar_Programa() {
    QApplication::quit();
}
