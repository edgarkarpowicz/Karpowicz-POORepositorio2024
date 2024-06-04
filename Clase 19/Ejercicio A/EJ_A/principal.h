#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QWidget>
#include <QDebug>
#include <QPainter>
#include <QPaintEvent>

#include <admindb.h>
#include <linea.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class Principal;
}
QT_END_NAMESPACE

class Principal : public QWidget
{
        Q_OBJECT

    public:
        Principal(QWidget *parent = nullptr);
        ~Principal();

    protected:
        void paintEvent(QPaintEvent *event) override;

    private:
        Ui::Principal *ui;

        AdminDB* admindb;
        Linea* linea;

        std::vector <int> *datos;

    public slots:
        void slot_recuperarYPintar();
};
#endif // PRINCIPAL_H
