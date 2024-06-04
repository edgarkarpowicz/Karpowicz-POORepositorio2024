#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QWidget>
#include <QDebug>

#include <guitarra.h>
#include <teclado.h>
#include <viento.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class Formulario;
}
QT_END_NAMESPACE

class Formulario : public QWidget
{
    Q_OBJECT

    public:
        Formulario(QWidget *parent = nullptr);
        ~Formulario();

        void limpiar_LineEdits();

    private:
        Ui::Formulario *ui;

        std::vector <Instrumento*> information_vec;

    public slots:
        void slot_cambiar_instrumentos();
        void slot_introducir_instrumentos();
        void slot_ver_stock();
};
#endif // FORMULARIO_H
