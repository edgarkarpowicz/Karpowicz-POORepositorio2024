#ifndef WEATHER_H
#define WEATHER_H

#include <QApplication>
#include <QWidget>
#include <QGridLayout> // Sistema de Grillas del QT
#include <QPushButton> // Para crear Botones
#include <QLabel>
#include <QLineEdit>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>

// Al ser la Clase o tener la frase Q_OBJECT, le habilita crear sus propias señales
// Entonces, ahora tiene para usar public, private, protected, signals, private slots, public slots.

class Weather : public QObject {
    Q_OBJECT
private:
    double latitud, longitud, temperatura;
    QNetworkAccessManager* manager;

public:
    Weather(double latitud, double longitud, QObject* parent = nullptr);

signals:
    void weatherChanged(const QString &temperatura);

public slots:
    void obtenerTemperatura();

private slots:
    void slot_descargaFinalizada(QNetworkReply* reply);
};

#endif // WEATHER_H
