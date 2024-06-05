#include "principal.h"
#include "ui_principal.h"

Principal::Principal(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);

    this->setMaximumSize(300, 300);
    this->setMinimumSize(300, 300);

    admindb = new AdminDB();
    qDebug() << "La base se abrio bien" << admindb->conectar( "C:/Qt/db/rectangles.sqlite" );


    vector = admindb->recuperarDatosRectangulos( "rectangulos" );

    connect(admindb, SIGNAL(rectangulosRecuperados()), this, SLOT(slot_paint()));
}

Principal::~Principal()
{
    delete ui;
}

void Principal::slot_paint() {
    this->repaint();
}

void Principal::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    int x = 0;
    while (x != vector.size()) {
        qDebug() << "Pintando Rectangulo con siguientes Datos:" << vector.at(x).get_x() << vector.at(x).get_y() << vector.at(x).get_ancho() << vector.at(x).get_alto();
        painter.drawRect(vector.at(x).get_x(), vector.at(x).get_y(), vector.at(x).get_ancho(), vector.at(x).get_alto());
        x++;
    }

    qDebug() << "Se pinto todo!!!";
}
