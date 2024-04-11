//blocked.cpp

#include "blocked.h"


Blocked::Blocked() {
    lBloqueado = new QLabel("Bloqueado");
    lBloqueado->setAlignment(Qt::AlignCenter);
    QFont fontBloqueado = lBloqueado->font();
    fontBloqueado.setBold(true);
    fontBloqueado.setPointSize(24);
    lBloqueado->setFont(fontBloqueado);

    pbSalir = new QPushButton("Salir");

    layout = new QGridLayout;
    layout->addWidget(lBloqueado, 0, 0, 1, 3);
    layout->addWidget(pbSalir, 1, 0, 1, 3);

    QObject::connect( pbSalir, SIGNAL( clicked(bool) ), this , SLOT ( finalizar_Programa() ) );
    this->setLayout(layout);
}

void Blocked::finalizar_Programa() {
    QApplication::quit();
}
