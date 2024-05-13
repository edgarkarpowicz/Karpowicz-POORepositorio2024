#include "alta.h"
#include "ui_alta.h"

Alta::Alta(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Alta)
{
    ui->setupUi(this);
}

Alta::~Alta()
{
    delete ui;
}
