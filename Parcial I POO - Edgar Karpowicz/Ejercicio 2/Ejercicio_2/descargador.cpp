#include <descargador.h>

Descargador::Descargador() { // Constructor
    this->setMinimumSize(800, 800); // Tamaño Mínimo de la Ventana

    layout = new QGridLayout;
    // Inicializamos el Layout, y le ponemos el texto de nuestra URL, además le ponemos ReadOnly
    leUrl = new QLineEdit("https://images.pexels.com/photos/417074/pexels-photo-417074.jpeg");
    leUrl->setReadOnly(true);

    pbDescargar = new QPushButton("Descargar");
    // PushButton de Descarga. Inicializado
    pbBarra = new QProgressBar(this);
    pbBarra->setAlignment(Qt::AlignCenter);

    layout->addWidget(leUrl, 0, 0, 1, 1);
    layout->addWidget(pbDescargar, 0, 1, 1, 1);
    layout->addWidget(pbBarra, 1, 0, 1, 2);

    this->setLayout(layout);
    // De acá para arriba se arregla el Layout de la Ventana junto a los Contenidos de la Misma
    connect(pbDescargar, SIGNAL(clicked(bool)), this, SLOT(slot_iniciarDescarga()));
    // Conectamos el boton de Descarga al slot de slot_iniciar_descarga(), así una vez se clickea comienza la Descarga con la URL dada en el LineEdit (por ahora es fija)
}

void Descargador::slot_iniciarDescarga() { // SLOT que inicia el proceso de descarga de Imágen
    manager = new QNetworkAccessManager; // Se inicializa el QNetworkAccessManager
    connect(manager, SIGNAL(finished(QNetworkReply * )), this, SLOT(slot_descargaFinalizada(QNetworkReply * ))); // Se conecta para cuando el manager termine de descargar, se ejecute el SLOT de slot_descargaFinalizada
    QNetworkRequest request(QUrl(leUrl->text())); // Se ejecuta o lleva a cabo la request, así comienza a descargar
    QNetworkReply *reply = manager->get(request); // Nos guardamos la REPLY, así tenemos datos para actualizar la barra de progreso
    // connect(reply, &QNetworkReply::downloadProgress, this, &slot_DownloadProgress); // Para actualizar la Barra de Progreso
    connect(reply, SIGNAL(downloadProgress(qint64,qint64)), this, SLOT(slot_DownloadProgress(qint64,qint64)));
}

void Descargador::slot_descargaFinalizada(QNetworkReply* reply) { // Se ejecuta cuando la descarga se finaliza!
    img = QImage::fromData(reply->readAll()); // Guarda los Datos obtenidos de la Descarga en IMG
    this->repaint(); // Para ejecutar el paintEvent
}

void Descargador::paintEvent(QPaintEvent *) { // Pinta la Imágen de Fondo
    QPainter painter(this);
    if(!img.isNull()) {
        this->show();
        painter.drawImage(0, 0, img.scaled(this->size()));
    }
}

void Descargador::slot_DownloadProgress(qint64 ist, qint64 max) { // Actualiza la Barra de Progreso
    pbBarra->setRange(0,max);
    pbBarra->setValue(ist);
}
