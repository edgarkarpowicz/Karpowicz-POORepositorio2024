// descargador.h

#ifndef DESCARGADOR_H
#define DESCARGADOR_H

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

// Incluimos a varias librerías de Network para conseguir Imágenes de Internet
// Además, la QProgressBar para la Barra de Progreso

// Clase de Descargador. Esta es una Ventana con un espacio para meter URLs que esta en READ-ONLY por ahora, y un boton para iniciar la Descarga
// Una vez finalizada DESCARGA, la cual es una Imágen, se hace display como background
class Descargador : public QWidget {
    Q_OBJECT
    private:
        QLineEdit* leUrl;
        QPushButton* pbDescargar;
        QProgressBar* pbBarra; // Botones, LineEdits, y la ProgressBar (Punteros a estos) (Se inicializan en el Constructor)

        QNetworkAccessManager* manager; // Puntero a QNetworkAccessManager, se inicializa en el Constructor
        QImage img; // QImage para guardar la Imágen descargada

        QGridLayout* layout; // GridLayout para darle forma a la Ventana, dado que no se puede utilizar QTDesigner en este Ejercicio

    public:
        Descargador(); // Constructor de Descargador

    private slots:
        void slot_iniciarDescarga(); // Slot del Boton pbDescargar. Inicia el Proceso de Descarga de Imágen
        void slot_descargaFinalizada(QNetworkReply* reply); // Slot de DescargaFinalizada. Se encarga de lo que hay que hacer una vez finaliza la descarga, entonces setear la Imágen de fondo de la Ventana
        void slot_DownloadProgress(qint64 ist, qint64 max); // Para actualizar la Barra de Progreso en vivo en base al Progreso de Descarga.

    protected:
        void paintEvent(QPaintEvent *event); // Evento de PaintEvent. Para pintar la Imágen de Fondo en la Ventana
};

#endif // DESCARGADOR_H
