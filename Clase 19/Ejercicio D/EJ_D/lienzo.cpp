#include "lienzo.h"
#include "ui_lienzo.h"

Lienzo::Lienzo(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Lienzo)
{
    ui->setupUi(this);
    setMouseTracking(true);
    paintSize = 1;
    currentColor = 0;

    repaintTimer = new QTimer(this);
    connect(repaintTimer, SIGNAL(timeout()), this, SLOT(slot_keep_painting()));
    connect(ui->lBorrar, SIGNAL(signal_clicked()), this, SLOT(slot_borrar()));
}

Lienzo::~Lienzo()
{
    delete ui;
}

void Lienzo::set_Grueso(int trazo) {
    switch (trazo) {
        case 0:
            qDebug() << "Trazo Fino";
            paintSize = 5;
            break;

        case 1:
            qDebug() << "Trazo Mediano";
            paintSize = 10;
            break;

        case 2:
            qDebug() << "Trazo Grueso";
            paintSize = 20;
            break;

        default:
            qDebug() << "Trazo Default";
            paintSize = 10;
            break;
    }
}

void Lienzo::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        repaintTimer->start(25);
        qDebug() << "Pintando";
    }
}

void Lienzo::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        qDebug() << "No Pintando";
        repaintTimer->stop();
    }
}

void Lienzo::mouseMoveEvent(QMouseEvent *event) {
    position.setX(event->pos().x());
    position.setY(event->pos().y());
}

void Lienzo::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_A) {
        qDebug() << "Ciclo de la Tecla A, activado";
        repaintTimer->start(25);
    } else if (event->key() == Qt::Key_D) {
        qDebug() << "Ciclo de la Tecla A, detenido";
        repaintTimer->stop();
    }

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

// void Lienzo::wheelEvent(QWheelEvent *event) {

//     paintSize += event->angleDelta().y() > 0 ? 1 : -1;

//     paintSize = qMax(1, paintSize);

//     qDebug() << "Número de Pixeles es " << paintSize;
// }

void Lienzo::slot_keep_painting() {
    qDebug() << "Repintando";
    this->repaint();
}

void Lienzo::paintEvent(QPaintEvent *) {
    qDebug() << "PaintEvent en ejecucion";
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

    if (position.x() == 0 && position.y() == 0 && currentColor == 0) {
        return;
    }

    painter.drawPoint(position);

    Painter_Data temp;
    temp.position = position;
    temp.paintSize = paintSize;
    temp.currentColor = currentColor;

    allDrawings.push_front(temp);
}

void Lienzo::slot_borrar() {
    allDrawings.clear();
    eraseCheck = true;
    this->repaint();
}

