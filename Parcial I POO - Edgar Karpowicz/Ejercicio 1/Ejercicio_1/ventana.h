// ventana.h

#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>

namespace Ui {
class Ventana;
}
// Clase Ventana, esta se abre después de la Clase de Acceso en acceso.h . Solamente saluda al Usuario quien haya Ingresado mediante el Login
class Ventana : public QWidget
{
    Q_OBJECT

    public:
        explicit Ventana(QWidget *parent = nullptr);
        ~Ventana();

        void set_user(QString nom); // Para setear quien es el Usuario entrante, USER O ADMIN. Son los unicos dos Usuarios registrados

    private:
        Ui::Ventana *ui;
};

#endif // VENTANA_H
