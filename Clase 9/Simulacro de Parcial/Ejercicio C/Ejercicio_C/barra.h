// barra.h

#ifndef BARRA_H
#define BARRA_H

#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QImage>
#include <QPainter>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QProgressBar>

#include <QSlider>

class Barra : public QWidget {
    Q_OBJECT
    private:
        QLabel* lUrl;
        QLineEdit* leUrl;
        QGridLayout* layout;
        QProgressBar* pbBarra;
        QNetworkAccessManager* manager;
        QImage img;

    public:
        Barra();

    private slots:
        void slot_descargaFinalizada(QNetworkReply* reply);
        void slot_DownloadProgress(qint64 ist, qint64 max);

    protected:
        void paintEvent(QPaintEvent *event);
};

#endif // BARRA_H
