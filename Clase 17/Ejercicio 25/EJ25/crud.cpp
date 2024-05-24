#include "crud.h"
#include "ui_crud.h"

CRUD::CRUD(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CRUD)
{
    ui->setupUi(this);
    this->setWindowTitle("Base de Datos");
    admindb = new AdminDB();
    query = get_data();
    display_tree();

    this->show();
    qDebug() << this->width() << this->height();
}

CRUD::~CRUD()
{
    delete ui;
}

void CRUD::display_tree() {
    ui->tree->setColumnCount(6);

    QStringList headers;
    headers << "ID" << "Usuario" << "Password" << "Nombre" << "Apellido" << "Email";
    ui->tree->setHeaderLabels(headers);

    while (query.next()) {
        QTreeWidgetItem* item = new QTreeWidgetItem();
        qDebug() << query.value(0).toString() << query.value(1).toString() << query.value(2).toString() << query.value(3).toString() << query.value(4).toString() << query.value(5).toString();
        item->setText(0, query.value(0).toString());
        item->setText(1, query.value(1).toString());
        item->setText(2, query.value(2).toString());
        item->setText(3, query.value(3).toString());
        item->setText(4, query.value(4).toString());
        item->setText(5, query.value(5).toString());
        qDebug() << "Procesando...";
        item->setFlags(item->flags() | Qt::ItemIsEditable);
        ui->tree->addTopLevelItem(item);
    }

    // Para hacerlo con una Raiz

    // QTreeWidgetItem* raiz = new QTreeWidgetItem(ui->tree);
    // raiz->setText(0, "Tabla de Usuarios");
    // raiz->setText(1, "");
    // raiz->setText(2, "");
    // raiz->setText(3, "");
    // raiz->setText(4, "");
    // raiz->setText(5, "");
    // ui->tree->addTopLevelItem(raiz);

    // while (query.next()) {
    //     QTreeWidgetItem* item = new QTreeWidgetItem();
    //     qDebug() << query.value(0).toString() << query.value(1).toString() << query.value(2).toString() << query.value(3).toString() << query.value(4).toString() << query.value(5).toString();
    //     item->setText(0, query.value(0).toString());
    //     item->setText(1, query.value(1).toString());
    //     item->setText(2, query.value(2).toString());
    //     item->setText(3, query.value(3).toString());
    //     item->setText(4, query.value(4).toString());
    //     item->setText(5, query.value(5).toString());
    //     qDebug() << "Procesando...";
    //     raiz->addChild(item);
    // }
}

QSqlQuery CRUD::get_data() {
    if (admindb->conectar("C:/Qt/db/usuarios.sqlite") == true) {
        qDebug() << "Consiguiendo los Datos";
        return (admindb->getUsuarios("usuarios"));
    } else {
        qDebug() << "No se pudo conectar a la Base de Datos";
    }
}
