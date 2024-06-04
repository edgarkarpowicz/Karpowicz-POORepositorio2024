#ifndef LINEA_H
#define LINEA_H

#include <QObject>

class Linea : public QObject
{
    Q_OBJECT
    public:
        explicit Linea(QObject *parent = nullptr, const int initial_x = NULL, const int initial_y = NULL, const int final_x = NULL, const int final_y = NULL);

        const int get_x_Inicial();
        const int get_y_Inicial();
        const int get_x_Final();
        const int get_y_Final();

    private:
        const int x_Inicial, y_Inicial, x_Final, y_Final;
};

#endif // LINEA_H
