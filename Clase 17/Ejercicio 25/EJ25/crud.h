#ifndef CRUD_H
#define CRUD_H

#include <QWidget>
#include <QTreeWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QByteArray>
#include <QCryptographicHash>
#include <QString>
#include <QDebug>

#include <admindb.h>

namespace Ui {
class CRUD;
}

class CRUD : public QWidget
{
    Q_OBJECT
    public:
        explicit CRUD(QWidget *parent = nullptr);
        ~CRUD();
        void display_tree();
        QSqlQuery get_data();

    private:
        Ui::CRUD *ui;
        AdminDB* admindb;
        QSqlQuery query;
};

#endif // CRUD_H
