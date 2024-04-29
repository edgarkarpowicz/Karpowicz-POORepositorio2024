#include "ventana.h"
#include "ui_ventana.h"
#include <QPainter>

Ventana::Ventana(QWidget *parent) : QWidget(parent),
                                    ui(new Ui::Ventana),
                                    manager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);

    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(slot_descarga_finalizada(QNetworkReply*)));

    QString sUrl = "https://cdn.icon-icons.com/icons2/2699/PNG/512/openssl_logo_icon_170881.png";
    manager->get(QNetworkRequest(QUrl(sUrl)));

}

Ventana::~Ventana()
{
    delete ui;
}

void Ventana::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    if (! im.isNull()) {
        painter.drawImage(0, 0, im.scaled(this->width(), this->height()));
    }
}

void Ventana::slot_descarga_finalizada(QNetworkReply *reply)
{
    im = QImage::fromData(reply->readAll());
    this->repaint();
}
