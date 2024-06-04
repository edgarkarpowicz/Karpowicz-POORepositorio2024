#include "formulario.h"
#include "ui_formulario.h"

Formulario::Formulario(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Formulario)
{
    ui->setupUi(this);

    connect(ui->cbInstrumento, SIGNAL(currentIndexChanged(int)), this, SLOT(slot_cambiar_instrumentos()));
    emit ui->cbInstrumento->currentIndexChanged(0);

    connect(ui->pbIntroducir, SIGNAL(clicked(bool)), this, SLOT(slot_introducir_instrumentos()));
    connect(ui->pbVerStock, SIGNAL(clicked(bool)), this, SLOT(slot_ver_stock()));
}

Formulario::~Formulario()
{
    delete ui;
}

void Formulario::slot_cambiar_instrumentos() {
    if (ui->cbInstrumento->currentIndex() == 0) {
        ui->leCantidadTeclas->setReadOnly(true);
        ui->leMetal->setReadOnly(true);
        ui->leCantidadCuerdas->setReadOnly(false);
    } else if (ui->cbInstrumento->currentIndex() == 1) {
        ui->leCantidadTeclas->setReadOnly(true);
        ui->leCantidadCuerdas->setReadOnly(false);
        ui->leMetal->setReadOnly(false);
    } else {
        ui->leCantidadCuerdas->setReadOnly(true);
        ui->leCantidadTeclas->setReadOnly(false);
        ui->leMetal->setReadOnly(false);
    }
}

void Formulario::limpiar_LineEdits() {
    ui->leMarca->setText("");
    ui->lePrecio->setText("");
    ui->leCantidadCuerdas->setText("");
    ui->leCantidadTeclas->setText("");
    ui->leMetal->setText("");
}

void Formulario::slot_introducir_instrumentos() {
    if (ui->cbInstrumento->currentIndex() == 0 && (ui->leMarca->text() != "" && ui->lePrecio->text() != "" && ui->leCantidadCuerdas->text() != "")) {
        Guitarra* guit = new Guitarra(this, ui->leMarca->text(), ui->lePrecio->text().toFloat(), ui->leCantidadCuerdas->text().toInt());
        information_vec.push_back(guit);
    } else if (ui->cbInstrumento->currentIndex() == 1 && (ui->leMarca->text() != "" && ui->lePrecio->text() != "" && ui->leCantidadCuerdas->text() != "" && ui->leMetal->text() != "")) {
        Viento* vien = new Viento(this, ui->leMarca->text(), ui->lePrecio->text().toFloat(), ui->leCantidadCuerdas->text().toInt(), ui->leMetal->text());
        information_vec.push_back(vien);

    } else if (ui->cbInstrumento->currentIndex() == 2 && (ui->leMarca->text() != "" && ui->lePrecio->text() != "" && ui->leCantidadTeclas->text() != "" && ui->leMetal->text() != "")) {
        Teclado* tecl = new Teclado(this, ui->leMarca->text(), ui->lePrecio->text().toFloat(), ui->leCantidadTeclas->text().toInt(), ui->leMetal->text());
        information_vec.push_back(tecl);
    }
    limpiar_LineEdits();
    return;
}

void Formulario::slot_ver_stock() {
    for (int i = 0; i != information_vec.size(); i++) {
        information_vec.at(i)->afinar();
        information_vec.at(i)->print_data();
    }
}
