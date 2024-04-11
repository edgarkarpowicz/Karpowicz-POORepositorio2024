#ifndef FORM_H
#define FORM_H

#include <QApplication>
#include <QWidget>
#include <QGridLayout> // Sistema de Grillas del QT
#include <QPushButton> // Para crear Botones
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>

// Al ser la Clase o tener la frase Q_OBJECT, le habilita crear sus propias señales
// Entonces, ahora tiene para usar public, private, protected, signals, private slots, public slots.

class Form : public QWidget {
    Q_OBJECT
    private:
        QLabel* lIntroduction;
        QLineEdit* leURL;
        QTextEdit* teHTML;
        QPushButton* pbSalir, *pbConfirmar;
        QGridLayout* layout;

        QNetworkAccessManager* manager;
    public:
        Form();

    private slots:
        void finalizar_Programa();
        void slot_descargar_html();
        void slot_html_descargado(QNetworkReply* reply);
};

#endif // FORM_H
