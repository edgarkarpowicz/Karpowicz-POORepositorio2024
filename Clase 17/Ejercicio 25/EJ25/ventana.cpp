#include "ventana.h"

Ventana::Ventana(QWidget *parent)
    : QWidget{parent}
{
    layout = new QGridLayout();

    lUsuario = new QLabel("Usuario:");
    lPassword = new QLabel("Password:");
    lNombre = new QLabel("Nombre:");
    lApellido = new QLabel("Apellido:");
    lEmail = new QLabel("Email:");
    pbRegistrar = new QPushButton("Registrarse");

    QFont* font = new QFont();
    font->setBold(true);
    font->setCapitalization(font->AllUppercase);
    font->setPixelSize(12);

    lUsuario->setFont(*font);
    lPassword->setFont(*font);
    lNombre->setFont(*font);
    lApellido->setFont(*font);
    lEmail->setFont(*font);
    pbRegistrar->setFont(*font);

    leUsuario = new QLineEdit();
    leUsuario->setPlaceholderText("Su Nuevo Usuario");
    lePassword = new QLineEdit();
    lePassword->setPlaceholderText("Su Nueva Password");
    lePassword->setEchoMode(QLineEdit::Password);
    leNombre = new QLineEdit();
    leNombre->setPlaceholderText("Su Nombre");
    leApellido = new QLineEdit();
    leApellido->setPlaceholderText("Su Apellido");
    leEmail = new QLineEdit();
    leEmail->setPlaceholderText("Su Email");

    layout->addWidget(lUsuario, 0, 0, 1, 1);
    layout->addWidget(leUsuario, 0, 1, 1, 1);
    layout->addWidget(lPassword, 1, 0, 1, 1);
    layout->addWidget(lePassword, 1, 1, 1, 1);
    layout->addWidget(lNombre, 2, 0, 1, 1);
    layout->addWidget(leNombre, 2, 1, 1, 1);
    layout->addWidget(lApellido, 3, 0, 1, 1);
    layout->addWidget(leApellido, 3, 1, 1, 1);
    layout->addWidget(lEmail, 4, 0, 1, 1);
    layout->addWidget(leEmail, 4, 1, 1, 1);
    layout->addWidget(pbRegistrar, 5, 0, 1, 2);

    this->setLayout(layout);

    connect(pbRegistrar, SIGNAL(clicked(bool)), this, SLOT(slot_registrarse()));
}

void Ventana::slot_registrarse() {
    admindb = new AdminDB();
    if (admindb->conectar("C:/Qt/db/usuarios.sqlite") == true) {
        if (leUsuario->text() != "" && lePassword->text() != "" && leNombre->text() != "" && leApellido->text() != "" && leEmail->text() != "") {
            if (admindb->existeUsuario("usuarios", leUsuario->text()) == true) {
                qDebug() << "Ya existe el Usuario. Intente con otro Usuario";
                leUsuario->setText("");
                lePassword->setText("");
            } else {
                qDebug() << "Exito en el Registro!";
                admindb->ingresarUsuario("usuarios", leUsuario->text(), lePassword->text(), leNombre->text(), leApellido->text(), leEmail->text());
                this->close();
            }
        } else {
            qDebug() << "Alguno de los Datos requeridos esta Vacio";
        }
    } else {
        qDebug() << "No se pudo conectar a la DB";
    }
}
