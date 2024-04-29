// acceso.cpp

#include "acceso.h"
#include "ui_acceso.h"

Acceso::Acceso(QWidget *parent) : QWidget(parent),
                                ui(new Ui::Acceso),
                                manager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);

    // La linea de Abajo conecta la señal de Finalizado (una vez se descargo la Imágen) con la de la función que se debe ejecutar una vez se hizo esto
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(slot_descarga_finalizada(QNetworkReply*)));

    QString sUrl = "https://upload.wikimedia.org/wikipedia/commons/0/0a/Newlands_-_geograph.org.uk_-_283875.jpg";
    manager->get(QNetworkRequest(QUrl(sUrl))); // Hago el Pedido de la Imágen con la URL en sUrl, para que se comience a descargar

    ui->leUsuario->setFocus(); // Pone el Enfoque en el lineEdit de Usuario

    connect(ui->pbIngresar, SIGNAL(pressed()), this, SLOT(slot_verificar_usuario())); // Conecto el boton de Ingresar con el slot_verificar_usuario
    connect(ui->leClave, SIGNAL(returnPressed()), this, SLOT(slot_verificar_usuario())); // Para que si se presione enter en el lineEdit de Clave, se ejecute el SLOT slot_verificar_usuario
}

Acceso::~Acceso() // Desconstructor de la Función
{
    delete ui;
}

void Acceso::paintEvent(QPaintEvent *) // Funcion de paintEvent. Pinta la Imágen de Fondo escalandola con el tamaño de la ventana
{
    QPainter painter(this);
    if (! im.isNull()) {
        painter.drawImage(0, 0, im.scaled(this->width(), this->height()));
    }
}

void Acceso::slot_descarga_finalizada(QNetworkReply *reply) // Slot de slot_descarga_finalizada. Se ejecuta una vez se termino de descargar la Imágen.
{
    im = QImage::fromData(reply->readAll());
    this->repaint();
    this->show(); // Muestra POR PRIMERA VEZ el Contenido / Ventana. Lo hace solo una vez se instancio la Clase. Solo ocurre cuando ya se descargo la Imágen de la URL en el Constructor.
}


void Acceso::slot_verificar_usuario() // SLOT para verificar el Usuario. Solo hay dos Usuarios validos admin y user.
{
    if ((ui->leUsuario->text() == "admin" && ui->leClave->text() == "1234") || (ui->leUsuario->text() == "user" && ui->leClave->text() == "4321")) {
        qDebug() << "Usuario Valido";
        ventana = new Ventana(); // Se instancia la Clase Ventana
        this->hide(); // Se oculta la instancia de acceso
        if (ui->leUsuario->text() == "admin") {
            ventana->set_user("admin"); // Si es admin el usuario entrante, usa la Función set_user de ventana para poner el QLabel de allí como "HOLA ADMIN"
        } else {
            ventana->set_user("user"); // Si es user el usuario entrante, usa la Función set_user de ventana para poner el QLabel de allí como "HOLA USER"
        }
        ventana->show(); // Se muestra la Instancia de Ventana
    }
    else { // Este else es para el Caso que los datos ingresados no pertenezcan a ninguno de los Dos Usuarios (admin y user)
        qDebug() << "Usuario no Valido";
        ui->leClave->setText(NULL);
        intentos++; // Se aumenta Intentos, si llega a tres se cierra el Programa por protección de los dos Usuarios (admin y user)
        if (intentos == 3) {
            this->close();
        }
    }
}

