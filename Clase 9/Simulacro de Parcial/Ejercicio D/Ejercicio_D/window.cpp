// window.cpp

#include <window.h>

Window::Window() {
    pbSiguiente = new QPushButton("Siguiente");
    pbAnterior = new QPushButton("Anterior");
    layout = new QGridLayout();

    layout->addWidget(pbSiguiente, 0, 1, 1, 1);
    layout->addWidget(pbAnterior, 0, 2, 1, 1);
    this->setLayout(layout);

    QString filePath = "C:/Users/edgar/Documents/URLs/URLsFotos.txt";
    QFile inputFile(filePath);
    int POS = 0;
    if (inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        while (!in.atEnd())
        {
            if (POS == 0) {
                lineone = in.readLine();
            } else if (POS == 1) {
                linetwo = in.readLine();
            } else {
                linethree = in.readLine();
            }
            POS++;
        }
        inputFile.close();
    }

    QObject::connect( pbSiguiente, SIGNAL( clicked(bool) ), this , SLOT( slot_Siguiente() ) );
    QObject::connect( pbAnterior, SIGNAL( clicked(bool) ), this , SLOT( slot_Anterior() ) );

    if (posicion == 1) {
        img_one();
    } else if (posicion == 2) {
        img_two();
    } else {
        img_three();
    }

}

void Window::img_one() {
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply * )), this, SLOT(slot_descargaFinalizada(QNetworkReply * )));
    QString urlString = lineone;
    QUrl url(urlString);
    QNetworkRequest request(url);
    manager->get(request);

    qDebug() << "img uno";
}

void Window::img_two() {
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply * )), this, SLOT(slot_descargaFinalizada(QNetworkReply * )));
    QString urlString = linetwo;
    QUrl url(urlString);
    QNetworkRequest request(url);
    manager->get(request);

    qDebug() << "img dos";
}

void Window::img_three() {
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply * )), this, SLOT(slot_descargaFinalizada(QNetworkReply * )));
    QString urlString = linethree;
    QUrl url(urlString);
    QNetworkRequest request(url);
    manager->get(request);

    qDebug() << "img tres";
}

void Window::slot_descargaFinalizada(QNetworkReply* reply) {
    img = QImage::fromData(reply->readAll());
    this->repaint();
    qDebug() << "descarga finalizada";
}

void Window::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    if(!img.isNull()) {
        this->show();
        painter.drawImage(0, 0, img.scaled(this->size()));
        qDebug() << "no es nula la imagen";
    }
}

void Window::slot_Siguiente() {
    switch (posicion) {
        case 1:
            posicion++;
            img_two();
            break;
        case 2:
            posicion++;
            img_three();
            break;
        case 3:
            posicion = 1;
            img_one();
            break;
    }
}

void Window::slot_Anterior() {
    switch (posicion) {
        case 1:
            posicion = 3;
            img_three();
            break;
        case 2:
            posicion = 1;
            img_one();
            break;
        case 3:
            posicion = 2;
            img_two();
            break;
    }
}
