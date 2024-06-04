#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>
#include <QObject>
#include <QGridLayout>
#include <QLineEdit>
#include <QFont>
#include <QDebug>

class ClickableLabel : public QLabel
{
    Q_OBJECT
    public:
        explicit ClickableLabel( QWidget* parent = nullptr );
        ~ClickableLabel() override;

    protected:
        void mousePressEvent(QMouseEvent* event) override;

    signals:
        void signal_clicked();
};

#endif // CLICKABLELABEL_H
