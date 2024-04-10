//login.cpp

#include "form.h"


Form::Form() {

    lLegajo = new QLabel("Legajo");
    lNombre = new QLabel("Nombre");
    lApellido = new QLabel("Apellido");
    leLegajo = new QLineEdit;
    leNombre = new QLineEdit;
    leApellido = new QLineEdit;
    pbSalir = new QPushButton("Salir");

    layout = new QGridLayout;
    layout->addWidget(lLegajo, 0, 0, 1, 1); // Primer Valor = Fila, Segundo Valor = Columna, Tercer Valor = Cuantas Filas va a ocupar, Cuarto Valor = Cuantas Columnas va a ocupar
    layout->addWidget(lNombre, 1, 0, 1, 1);
    layout->addWidget(lApellido, 2, 0, 1, 1);
    layout->addWidget(leLegajo, 0, 1, 1, 2);
    layout->addWidget(leNombre, 1, 1, 1, 2);
    layout->addWidget(leApellido, 2, 1, 1, 2);
    layout->addWidget(pbSalir, 3, 0, 1, 3);

    QObject::connect( pbSalir, SIGNAL( clicked(bool) ), this , SLOT ( finalizar_Programa() ) );

    this->setLayout(layout);
}

void Form::finalizar_Programa() {
    QApplication::quit();
}
