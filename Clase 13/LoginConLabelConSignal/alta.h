#ifndef ALTA_H
#define ALTA_H

#include <QWidget>

namespace Ui {
class Alta;
}

class Alta : public QWidget
{
    Q_OBJECT

public:
    explicit Alta(QWidget *parent = nullptr);
    ~Alta();

private:
    Ui::Alta *ui;
};

#endif // ALTA_H
