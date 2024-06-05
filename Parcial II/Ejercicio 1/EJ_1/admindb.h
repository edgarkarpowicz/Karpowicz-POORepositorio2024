#ifndef ADMINDB_H
#define ADMINDB_H

#include <QObject>
#include <QSqlDatabase>
#include <QString>
#include <QByteArray>
#include <QCryptographicHash>

#include <rectangulo.h>

class AdminDB : public QObject
{
    Q_OBJECT
    public:
        static AdminDB * getInstancia();
        explicit AdminDB(QObject *parent = nullptr);

        bool conectar( QString archivoSqlite );
        QSqlDatabase getDB();

        bool validarUsuario( QString tabla, QString usuario, QString clave );
        void ingresarUsuario( QString tabla, QString usuario, QString clave, QString nombre, QString apellido, QString correo );
        bool existeUsuario( QString tabla, QString usuario );
        QSqlQuery getUsuarios( QString tabla);

        std::vector<Rectangulo> recuperarDatosRectangulos(QString tabla);

    private:
        QSqlDatabase db;

        static AdminDB* instancia;

    signals:
        void rectangulosRecuperados();
};

#endif // ADMINDB_H
