// window.h

#ifndef WINDOW_H
#define WINDOW_H

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

#include <QDebug>

#include <QFile>
#include <QString>

class Window : public QWidget {
    Q_OBJECT
    private:
        QGridLayout* layout;
        QPushButton* pbSiguiente, *pbAnterior;
        QNetworkAccessManager* manager;
        QImage img;
        QString lineone, linetwo, linethree;

        int posicion = 1;

    public:
        Window();
        void img_one();
        void img_two();
        void img_three();

    private slots:
        void slot_Siguiente();
        void slot_Anterior();
        void slot_descargaFinalizada(QNetworkReply* reply);

    protected:
        void paintEvent(QPaintEvent *event);
};

#endif // WINDOW_H
