#include "admindb.h"

#include <QSqlQuery>
#include <QVariant>
#include <QDebug>

AdminDB::AdminDB(QObject *parent) : QObject(parent)
{
    db = QSqlDatabase::addDatabase( "QSQLITE" );
}


bool AdminDB::conectar( QString archivoSqlite )  {
    db.setDatabaseName( archivoSqlite );

    if( db.open() )
        qDebug() << "Base de Datos abierta!";
    return true;

    return false;
}

QSqlDatabase AdminDB::getDB()  {
    return db;
}

bool AdminDB::validarUsuario(QString tabla, QString usuario, QString clave)
{
    qDebug() << "Usuario: " << usuario;
    qDebug() << "Clave: " << clave;
    if ( db.open() )  {
        qDebug() << "Estamos buscando..." << clave;
        QByteArray hash = QCryptographicHash::hash(clave.toUtf8(), QCryptographicHash::Md5).toHex();
        QSqlQuery query = db.exec( "SELECT nombre, apellido FROM " + tabla + " WHERE usuario = '" +
                                  usuario + "' AND clave = '" + hash + "'" );

        while( query.next() )  {
            qDebug() << query.value( 0 ).toString() << " " << query.value( 1 ).toString();
            qDebug() << "Se encontro el Usuario....";
            return true;
        }
    }
    qDebug() << "No se encontro el Usuario....";
    return false;
}

void AdminDB::ingresarUsuario(QString tabla, QString usuario, QString clave, QString nombre, QString apellido, QString correo) {
    qDebug() << "Intentando Ingresar..." << usuario;
    if ( db.open() ) {
        qDebug() << "Ingresando Usuario....";
        QByteArray hash = QCryptographicHash::hash(clave.toUtf8(), QCryptographicHash::Md5).toHex();
        QSqlQuery query = db.exec( "INSERT INTO " + tabla + " (usuario, clave, nombre, apellido, mail) values " + "('" + usuario + "','" + hash + "','" + nombre + "','" + apellido + "','" + correo + "')");

        QSqlQuery querytwo = db.exec( "SELECT nombre, apellido FROM " + tabla + " WHERE usuario = '" +
                                     usuario + "' AND clave = '" + hash + "'" );

        while( querytwo.next() )  {
            qDebug() << "Se ingreso con exito a la Base de Datos!";
            return;
        }
    }
    qDebug() << "No se pudo Ingresar..." << clave;
}

bool AdminDB::existeUsuario(QString tabla, QString usuario) {
    if ( db.open() ) {
        qDebug() << "Checkeando si Usuario ya existe....";
        QSqlQuery query = db.exec( "SELECT usuario FROM " + tabla + " WHERE usuario = '" +
                                  usuario + "'" );

        while( query.next() )  {
            qDebug() << query.value( 0 ).toString() << " " << query.value( 1 ).toString();
            return true;
        }
    }

    return false;
}

std::vector<int> AdminDB::recuperarDatosLinea(QString tabla)
{
    std::vector<int> vec;
    if ( db.open() )  {
        qDebug() << this->getDB();
        qDebug() << "Recuperando los Datos de la Linea...";
        QSqlQuery query = db.exec( "SELECT x_Inicial, y_Inicial, x_Final, y_Final FROM " + tabla);

        qDebug() << "Query obtenida, a punto de meterme a verla...";

        while( query.next() )  {
            qDebug() << "x_Inicial:" << query.value(0).toInt();
            qDebug() << "y_Inicial:" << query.value(1).toInt();
            qDebug() << "x_Final:" << query.value(2).toInt();
            qDebug() << "y_Final:" << query.value(3).toInt();

            vec.push_back(query.value(0).toInt());
            vec.push_back(query.value(1).toInt());
            vec.push_back(query.value(2).toInt());
            vec.push_back(query.value(3).toInt());

            qDebug() << "Orden Final del Vector:";
            qDebug() << "x_Inicial:" << vec.at(0);
            qDebug() << "y_Inicial:" << vec.at(1);
            qDebug() << "x_Final:" << vec.at(2);
            qDebug() << "y_Final:" << vec.at(3);

            return vec;
        }
    }
    qDebug() << "Error!";
    return vec;
}
