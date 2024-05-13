
#include "login.h"
#include "ui_login.h"


Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    alta = new Alta;

    connect( ui->lRegistrarse, SIGNAL(signal_pressed()), this, SLOT(slot_alta()));
}

Login::~Login()
{
    delete ui;
}

void Login::slot_alta()
{
    this->hide();
    alta->show();
}


