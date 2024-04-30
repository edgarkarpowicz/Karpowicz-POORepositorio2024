#include "painter.h"
#include "ui_painter.h"

Painter::Painter(QWidget *parent) : QWidget(parent),
                                    ui(new Ui::Painter)
{
    ui->setupUi(this);
    setMouseTracking(true);
    paintSize = 1;
    currentColor = 0;

    repaintTimer = new QTimer(this);
    connect(repaintTimer, SIGNAL(timeout()), this, SLOT(slot_keep_painting()));
}

Painter::~Painter()
{
    delete ui;
}

void Painter::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        repaintTimer->start(25);
        qDebug() << "Pintando";
    }
}

void Painter::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        repaintTimer->stop();
    }
}

void Painter::mouseMoveEvent(QMouseEvent *event) {
    position.setX(event->pos().x());
    position.setY(event->pos().y());
}

void Painter::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_R) {
        currentColor = 0;
        qDebug() << "Seteado en Rojo";
    } else if (event->key() == Qt::Key_G) {
        currentColor = 1;
        qDebug() << "Seteado en Verde";
    } else if (event->key() == Qt::Key_B) {
        currentColor = 2;
        qDebug() << "Seteado en Azul";
    } else if (event->key() == Qt::Key_Escape) {
        allDrawings.clear();
        eraseCheck = true;
        this->repaint();
    }
}

void Painter::wheelEvent(QWheelEvent *event) {

    paintSize += event->angleDelta().y() > 0 ? 1 : -1;

    paintSize = qMax(1, paintSize);

    qDebug() << "Número de Pixeles es " << paintSize;
}

void Painter::slot_keep_painting() {
    this->repaint();
}

void Painter::paintEvent(QPaintEvent *) {
    QPainter painter(this);

    if (eraseCheck == true) {
        eraseCheck = false;
        return;
    }

    if (!allDrawings.empty()) {
        int temp = 0;
        while (temp != allDrawings.size()) {
            if (allDrawings.at(temp).currentColor == 0) {
                painter.setPen(Qt::red);
            } else if (allDrawings.at(temp).currentColor == 1) {
                painter.setPen(Qt::green);
            } else {
                painter.setPen(Qt::blue);
            }

            QPen temp_pen = painter.pen();
            temp_pen.setWidth(allDrawings.at(temp).paintSize);
            painter.setPen(temp_pen);

            painter.drawPoint(allDrawings.at(temp).position);
            temp++;
        }
    }

    if (currentColor == 0) {
        painter.setPen(Qt::red);
    } else if (currentColor == 1) {
        painter.setPen(Qt::green);
    } else {
        painter.setPen(Qt::blue);
    }

    QPen temp_pen = painter.pen();
    temp_pen.setWidth(paintSize);
    painter.setPen(temp_pen);

    painter.drawPoint(position);

    Painter_Data temp;
    temp.position = position;
    temp.paintSize = paintSize;
    temp.currentColor = currentColor;
    allDrawings.push_front(temp);
}

