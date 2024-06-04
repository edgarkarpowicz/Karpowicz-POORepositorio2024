#include "login.h"

Login * Login::instancia = nullptr;

Login * Login::getInstancia()  {
    if( instancia == nullptr )  {
        instancia = new Login;
    }
    return instancia;
}

Login::Login(QWidget *parent)
    : QWidget(parent)
{
    layout = new QGridLayout();

    lUsuario = new QLabel ("Usuario:");
    lPassword = new QLabel("Password:");

    QFont* font = new QFont();
    font->setBold(true);
    font->setCapitalization(font->AllUppercase);
    font->setPixelSize(12);

    lUsuario->setFont(*font);
    lPassword->setFont(*font);

    leUsuario = new QLineEdit();
    lePassword = new QLineEdit();
    lePassword->setEchoMode(QLineEdit::Password);

    leUsuario->setPlaceholderText("Su Usuario");
    lePassword->setPlaceholderText("Su Password");

    pbIngresar = new QPushButton();

    pbIngresar->setText("Ingresar");
    pbIngresar->setFont(*font);

    layout->addWidget(lUsuario, 0, 0, 1, 1);
    layout->addWidget(leUsuario, 0, 1, 1, 1);
    layout->addWidget(lPassword, 1, 0, 1, 1);
    layout->addWidget(lePassword, 1, 1, 1, 1);
    layout->addWidget(pbIngresar, 2, 0, 1, 1);

    this->setLayout(layout);

    connect(pbIngresar, SIGNAL(clicked(bool)), this, SLOT(slot_verificar_usuario()));
}

Login::~Login() {}

void Login::slot_verificar_usuario() {
    admindb = new AdminDB( this );
    if (admindb->conectar("C:/Qt/db/base.sqlite") == true) {
        if (admindb->validarUsuario( "usuarios", leUsuario->text(), lePassword->text()))  {
            qDebug() << "Exito Ingresando con el Usuario!";
            emit signal_ir_ventana();
        }
        else  {
            qDebug() << "Algo ha ido mal en el Ingreso.";
            lePassword->setText("");
        }
    } else {
        qDebug() << "No se pudo conectar a la DB";
    }
}
