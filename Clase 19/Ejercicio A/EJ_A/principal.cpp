#include "principal.h"
#include "ui_principal.h"

Principal::Principal(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);

    admindb = new AdminDB(this);
    qDebug() << "La base se abrio bien" << admindb->conectar( "C:/Qt/db/lineas.sqlite" );

    datos = new std::vector <int>;
    *datos = admindb->recuperarDatosLinea( "lineas" );

    connect(ui->pbPintar, SIGNAL(clicked(bool)), this, SLOT(slot_recuperarYPintar()));
}

Principal::~Principal()
{
    delete ui;
}

void Principal::slot_recuperarYPintar() {
    if (datos->empty()) {
        qDebug() << "Error recuperando los Datos";
        return;
    } else {
        ui->leXInicial->setText( QString::number(datos->at(0)) );
        ui->leYInicial->setText( QString::number(datos->at(1)) );
        ui->leXFinal->setText( QString::number(datos->at(2)) );
        ui->leYFinal->setText( QString::number(datos->at(3)) );

        linea = new Linea (this, datos->at(0), datos->at(1), datos->at(2), datos->at(3));
        this->repaint();
        return;
    }
}


void Principal::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    painter.drawLine(linea->get_x_Inicial(), linea->get_y_Inicial(), linea->get_x_Final(), linea->get_y_Final());
}
