#ifndef LIENZO_H
#define LIENZO_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QWheelEvent>
#include <QTimer>

#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui {
class Lienzo;
}
QT_END_NAMESPACE

struct Painter_Data {
    QPoint position;
    int paintSize;
    int currentColor;
};

class Lienzo : public QWidget
{
    Q_OBJECT

    public:
        Lienzo(QWidget *parent = nullptr);
        ~Lienzo();

        void set_Grueso(int);

    protected:
        void paintEvent(QPaintEvent *event);

        virtual void mousePressEvent( QMouseEvent * event );
        virtual void mouseReleaseEvent( QMouseEvent * event );
        virtual void mouseMoveEvent(QMouseEvent *event);
        virtual void keyPressEvent( QKeyEvent * event );
        // virtual void wheelEvent(QWheelEvent * event);

    private:
        Ui::Lienzo *ui;
        QPoint position;
        int paintSize;
        int currentColor; // 0 = R (RED), 1 = G (GREEN), 2 = B (BLUE)
        QTimer* repaintTimer;
        bool eraseCheck; // 0 = No Borrando, 1 = Borrando
        QVector<Painter_Data> allDrawings;

    private slots:
        void slot_keep_painting();
        void slot_borrar();
};
#endif // LIENZO_H
