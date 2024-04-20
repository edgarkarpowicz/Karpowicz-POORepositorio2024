// barra.cpp

#include <barra.h>

Barra::Barra() {
    lUrl = new QLabel("URL:");
    leUrl = new QLineEdit("https://upload.wikimedia.org/wikipedia/commons/thumb/7/72/%22%2430_every_Thursday%22_pension_plan_out_as_President_discusses_political_situation_with_California_candidates._Washington%2C_D.C.%2C_Sept._27._Sheridan_Downey%2C_who_defeated_Senator_William_Gibbs_LCCN2016874059.tif/lossy-page1-1024px-thumbnail.tif.jpg");
    leUrl->setReadOnly(true);
    layout = new QGridLayout;
    pbBarra = new QProgressBar(this);
    pbBarra->setAlignment(Qt::AlignCenter);

    layout->addWidget(lUrl, 0, 0, 1, 1);
    layout->addWidget(leUrl, 0, 1, 1, 1);
    layout->addWidget(pbBarra, 1, 0, 1, 2);
    this->setLayout(layout);

    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply * )), this, SLOT(slot_descargaFinalizada(QNetworkReply * )));
    QNetworkRequest request(QUrl("https://upload.wikimedia.org/wikipedia/commons/thumb/7/72/%22%2430_every_Thursday%22_pension_plan_out_as_President_discusses_political_situation_with_California_candidates._Washington%2C_D.C.%2C_Sept._27._Sheridan_Downey%2C_who_defeated_Senator_William_Gibbs_LCCN2016874059.tif/lossy-page1-1024px-thumbnail.tif.jpg"));
    QNetworkReply *reply = manager->get(request);
    connect(reply, &QNetworkReply::downloadProgress, this, &slot_DownloadProgress);
}

void Barra::slot_descargaFinalizada(QNetworkReply* reply) {
    img = QImage::fromData(reply->readAll());
    this->repaint();
}

void Barra::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    if(!img.isNull()) {
        this->show();
        painter.drawImage(0, 0, img.scaled(this->size()));
    }
}

void Barra::slot_DownloadProgress(qint64 ist, qint64 max) {
    pbBarra->setRange(0,max);
    pbBarra->setValue(ist);
}
