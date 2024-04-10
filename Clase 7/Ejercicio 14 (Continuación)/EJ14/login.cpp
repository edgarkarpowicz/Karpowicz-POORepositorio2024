//login.cpp

#include "login.h"


Login::Login() {
    // qInfo() << QSslSocket::sslLibraryBuildVersionString(); Obtener Info de la Librería de OpenSSL instalada en el Sistema.
    // qInfo() << QSslSocket::sslLibraryVersionString(); Obtener Info de la Librería de OpenSSL instalada en el Sistema.
    // qDebug() << QSslSocket::supportsSsl(); Obtener Info de si soporta OpenSSL la instalación actual.

    lBienvenido = new QLabel("Bienvenido");
    lBienvenido->setAlignment(Qt::AlignCenter);
    QFont fontBienvenido = lBienvenido->font();
    fontBienvenido.setBold(true);
    fontBienvenido.setPointSize(12);
    lBienvenido->setFont(fontBienvenido);

    lTemperatura = new QLabel("Temperatura Actual: ");
    leTemperatura = new QLineEdit();
    leTemperatura->setEnabled(false);

    lUsuario = new QLabel("Usuario");
    lClave = new QLabel("Clave");
    leUsuario = new QLineEdit;
    leClave = new QLineEdit;
    leClave->setEchoMode( QLineEdit::Password );
    pbEntrar = new QPushButton("Entrar");
    pbEsconderTemperatura = new QPushButton("Esconder Temperatura");

    layout = new QGridLayout;
    layout->addWidget(lBienvenido, 0, 0, 1, 3);
    layout->addWidget(lTemperatura, 1, 0, 1, 1);
    layout->addWidget(leTemperatura, 1, 1, 1, 2);
    layout->addWidget(lUsuario, 2, 0, 1, 1);
    layout->addWidget(lClave, 3, 0, 1, 1);
    layout->addWidget(leUsuario, 2, 1, 1, 2);
    layout->addWidget(leClave, 3, 1, 1, 2);
    layout->addWidget(pbEntrar, 4, 0, 1, 3);
    layout->addWidget(pbEsconderTemperatura, 5, 0, 1, 3);

    QObject::connect( pbEntrar, SIGNAL( clicked(bool) ), this , SLOT( slot_validarUsuario() ) );
    QObject::connect( pbEsconderTemperatura, SIGNAL( clicked(bool) ), this , SLOT( slot_esconderTemperatura() ) );
    this->setLayout(layout);

    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply * )), this, SLOT(slot_descargaFinalizada(QNetworkReply * )));
    QNetworkRequest request(QUrl("https://media.geeksforgeeks.org/wp-content/uploads/20230426115225/computer-image-660.jpg"));
    manager->get(request);

    Weather* weather = new Weather(-31.4135, -64.18105);
    connect(weather, &Weather::weatherChanged, this, &Login::slot_actualizarTemperatura);
    weather->obtenerTemperatura();
}

void Login::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    if(!im.isNull()) {
        painter.drawImage(0, 0, im.scaled(this->size()));
        QLabel* lURL = new QLabel("URL IMG: https://media.geeksforgeeks.org/wp-content/uploads/20230426115225/computer-image-660.jpg");
        lURL->setAlignment(Qt::AlignCenter);
        layout->addWidget(lURL, 6, 0, 1, 0);
    }
}

void Login::slot_esconderTemperatura() {
    if (leTemperatura->echoMode() == QLineEdit::Normal) {
        leTemperatura->setEchoMode(QLineEdit::NoEcho);
    } else {
        leTemperatura->setEchoMode(QLineEdit::Normal);
    }
}

void Login::slot_descargaFinalizada(QNetworkReply* reply) {
    im = QImage::fromData(reply->readAll());
    this->repaint();
}

void Login::slot_actualizarTemperatura(const QString &temperatura) {
    leTemperatura->setText(temperatura);
}

void Login::slot_validarUsuario() {
    if (leUsuario->text() == "admin" && leClave->text() == "1234") {
        Form* form_point = new Form;
        form_point->show();
        this->hide();
    } else {
        leClave->clear();
    }
}
