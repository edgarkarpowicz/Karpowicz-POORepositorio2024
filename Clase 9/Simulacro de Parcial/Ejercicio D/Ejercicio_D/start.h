// start.h

#ifndef START_H
#define START_H

#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

#include <window.h>

class Start : public QWidget {
    Q_OBJECT
private:
    QLabel* lBienvenida, *lDescripcion;
    QPushButton* pbIngresar;
    QGridLayout* layout;
    Window* window;

public:
    Start();

private slots:
    void slot_Iniciar();
};

#endif // START_H
