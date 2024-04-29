// acceso.h

#ifndef ACCESO_H
#define ACCESO_H

#include <QWidget>

#include <QImage>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>

#include <QPainter>

#include <ventana.h> // Incluimos la Clase de Ventana en acceso.h . Contiene una Clase llamada Ventana,
                    // la cual vamos a instanciar y despues vamos a necesitar ya que le vamos a hacer display en este Código

QT_BEGIN_NAMESPACE
namespace Ui {
class Acceso;
}
QT_END_NAMESPACE
// Clase de Acceso, esta actua como nuestro Login en este Programa
class Acceso : public QWidget
{
    Q_OBJECT

    public:
        Acceso(QWidget *parent = nullptr);
        ~Acceso();

    protected:
        void paintEvent(QPaintEvent *);

    private:
        Ui::Acceso *ui;

        Ventana* ventana; // Puntero a una la Clase Ventana, despues vamos a inicializarla cuando le querramos hacer .show();

        QImage im; // Donde vamos a guardar la Imágen que obtengamos de las Request que hagamos mediante el manager
        QNetworkAccessManager* manager; // Pointer de QNetworkAccessManager, lo vamos a inicializar en el Constructor de la Clase

        int intentos = 0; // Entero que controla la cantidad de Intentos de Ingresar un Usuario Incorrecto. Llega a 3 y el Programa se cierra

    private slots:
        void slot_verificar_usuario(); // Slot que se encarga de Verificar el Usuario y conlleva a que se instancie ventana y se abra
                                       // Solo existen dos Usuarios validos, admin con la contra 1234, y user con la contra 4321
        void slot_descarga_finalizada(QNetworkReply * reply); // Slot que se encarga de todos los Procesos y Acciones una vez la Imágen ha sido descargada
};
#endif // ACCESO_H
