#include "formulario.h"
#include "ui_formulario.h"

Formulario::Formulario(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Formulario)
{
    ui->setupUi(this);

    connect(ui->pbVolver, SIGNAL(clicked(bool)), this, SLOT(slot_emit_return()));
}

Formulario::~Formulario()
{
    delete ui;
}

void Formulario::slot_emit_return() {
    emit signal_volver_login();
    this->hide();
}
