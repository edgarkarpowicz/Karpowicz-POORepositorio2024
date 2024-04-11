//login.cpp

#include "form.h"


Form::Form() {

    lIntroduction = new QLabel("Ingrese su URL");
    lIntroduction->setAlignment(Qt::AlignCenter);
    QFont fontIntroduction = lIntroduction->font();
    fontIntroduction.setBold(true);
    fontIntroduction.setPixelSize(12);
    lIntroduction->setFont(fontIntroduction);

    leURL = new QLineEdit();
    teHTML = new QTextEdit();

    pbSalir = new QPushButton("Salir");
    pbConfirmar = new QPushButton("Buscar Datos HTML");

    layout = new QGridLayout;
    layout->addWidget(lIntroduction, 0, 1, 1, 3);
    layout->addWidget(leURL, 2, 1, 1, 3);
    layout->addWidget(pbConfirmar, 3, 1, 1, 3);
    layout->addWidget(pbSalir, 4, 1, 1, 3);
    layout->addWidget(teHTML, 5, 1, 1, 3);

    QObject::connect( pbSalir, SIGNAL( clicked(bool) ), this , SLOT ( finalizar_Programa() ) );
    QObject::connect ( pbConfirmar, SIGNAL ( clicked(bool) ), this, SLOT ( slot_descargar_html() ) );

    this->setLayout(layout);
}

void Form::finalizar_Programa() {
    QApplication::quit();
}

void Form::slot_descargar_html() {
    if (!(leURL->text().isEmpty())) {
        manager = new QNetworkAccessManager(this);
        connect(manager, SIGNAL(finished(QNetworkReply * )), this, SLOT(slot_html_descargado(QNetworkReply * )));
        QNetworkRequest request(QUrl(leURL->text()));
        manager->get(request);
    }
}

void Form::slot_html_descargado(QNetworkReply* reply) {
    QString html = reply->readAll();
    teHTML->setText(html);
}
