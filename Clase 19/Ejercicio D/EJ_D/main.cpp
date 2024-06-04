#include "lienzo.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    enum Grueso {TrazoFino, TrazoMediano, TrazoGrueso};
    qDebug() << "Valor del Trazo Fino:" << Grueso::TrazoFino;
    qDebug() << "Valor del Trazo Mediano:" << Grueso::TrazoMediano;
    qDebug() << "Valor del Trazo Grueso:" << Grueso::TrazoGrueso;
    Lienzo w;
    w.set_Grueso(Grueso::TrazoGrueso);
    w.show();

    return a.exec();
}
