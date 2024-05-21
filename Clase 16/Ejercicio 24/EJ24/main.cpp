#include "parser.h"

#include <QApplication>

// Pruebame con la Dirección WEB: "https://www.basicwebsiteexample.com/" o con "https://www.ubp.edu.ar/"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Parser w;
    w.show();

    return a.exec();
}
