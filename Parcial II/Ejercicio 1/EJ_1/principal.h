#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QWidget>
#include <QDebug>
#include <QPainter>
#include <QPaintEvent>

#include <admindb.h>
#include <rectangulo.h>

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

    private:
        Ui::Principal *ui;

        AdminDB* admindb;
        std::vector<Rectangulo> vector;

    protected:
        void paintEvent(QPaintEvent *event) override;

    private slots:
        void slot_paint();
};
#endif // PRINCIPAL_H
