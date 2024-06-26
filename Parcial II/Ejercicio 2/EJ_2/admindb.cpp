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
        return true;

    return false;
}

QSqlDatabase AdminDB::getDB()  {
    return db;
}

bool AdminDB::validarUsuario(QString tabla, QString usuario, QString clave)
{
    if ( db.open() )  {
        QByteArray hash = QCryptographicHash::hash(clave.toUtf8(), QCryptographicHash::Md5).toHex();
        QSqlQuery query = db.exec( "SELECT nombre, apellido FROM " + tabla + " WHERE usuario = '" +
                                  usuario + "' AND clave = '" + hash + "'" );

        while( query.next() )  {
            qDebug() << query.value( 0 ).toString() << " " << query.value( 1 ).toString();
            return true;
        }
    }

    return false;
}

void AdminDB::ingresarUsuario(QString tabla, QString usuario, QString clave, QString nombre, QString apellido, QString correo) {
    if ( db.open() ) {
        qDebug() << "Ingresando Usuario....";
        QByteArray hash = QCryptographicHash::hash(clave.toUtf8(), QCryptographicHash::Md5).toHex();
        QSqlQuery query = db.exec( "INSERT INTO " + tabla + " (usuario, clave, nombre, apellido, mail) values " + "('" + usuario + "','" + hash + "','" + nombre + "','" + apellido + "','" + correo + "')");

        QSqlQuery querytwo = db.exec( "SELECT nombre, apellido FROM " + tabla + " WHERE usuario = '" +
                                     usuario + "' AND clave = '" + hash + "'" );

        while( querytwo.next() )  {
            qDebug() << "Se ingreso con exito a la Base de Datos!";
        }
    }
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
