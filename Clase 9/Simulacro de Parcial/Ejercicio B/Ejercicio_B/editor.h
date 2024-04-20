// editor.h

#ifndef EDITOR_H
#define EDITOR_H

#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>

#include <QFile>
#include <QTextStream>

#include <QDebug>

class Editor : public QWidget {
    Q_OBJECT
    private:
        QLabel* lTitle;
        QTextEdit* teTexto;
        QPushButton* pbBuscar, *pbGuardar;
        QLineEdit* leTXTBuscar, *leFilename;
        QGridLayout* layout;

    public:
        Editor();

    private slots:
        void slot_buscar_texto();
        void slot_guardar_texto();
};

#endif // EDITOR_H
