
#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

#include "alta.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QWidget

{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private:
    Ui::Login *ui;

    Alta * alta;

private slots:
    void slot_alta();
};

#endif // LOGIN_H
