// editor.cpp

#include <editor.h>

Editor::Editor() {
    QWidget::setWindowTitle("Editor de Texto");

    lTitle = new QLabel("Editor de Texto");
    QFont* fontTitle = new QFont();
    fontTitle->setBold(true);
    fontTitle->setPixelSize(20);
    lTitle->setFont(*fontTitle);

    teTexto = new QTextEdit();

    teTexto->setPlaceholderText("Aquí va su texto");

    pbBuscar = new QPushButton("Buscar");
    pbGuardar = new QPushButton("Guardar");
    leTXTBuscar = new QLineEdit();
    leFilename = new QLineEdit();

    leTXTBuscar->setPlaceholderText("Cadena o Frase");
    leFilename->setPlaceholderText("Nombre de su Archivo");

    layout = new QGridLayout();

    layout->addWidget(lTitle, 0, 1, 1, 2, Qt::AlignCenter);
    layout->addWidget(teTexto, 1, 1, 1, 2, Qt::AlignCenter);
    layout->addWidget(leTXTBuscar, 2, 1, 1, 1);
    layout->addWidget(pbBuscar, 2, 2, 1, 1);
    layout->addWidget(leFilename, 3, 1, 1, 1);
    layout->addWidget(pbGuardar, 3, 2, 1, 1);

    this->setLayout(layout);
    connect(pbBuscar, SIGNAL(clicked(bool)), this, SLOT(slot_buscar_texto()));
    connect(pbGuardar, SIGNAL(clicked(bool)), this, SLOT(slot_guardar_texto()));
}

void Editor::slot_buscar_texto() {
    if (leTXTBuscar->text().isEmpty() == 0 && teTexto->document()->isEmpty() == 0) {
        QString search = leTXTBuscar->text();
        QString text = teTexto->toPlainText();

        int value = 0;
        int found = 0;
        while ((value = text.indexOf(search, value)) != -1) {
            qDebug() << "Encontrado";
            found++;
            ++value;
        }

        QString set;
        QString add;
        if (found > 1) {
            set = QString::number(found);
            add = " ocurrencias";
            set = set + add;
        } else if (found == 1) {
            set = QString::number(found);
            add = " ocurrencia";
            set = set + add;
        } else {
            set = "No hubo ocurrencias";
        }

        lTitle->setText(set);
    }
}

void Editor::slot_guardar_texto() {
    if (leFilename->text().isEmpty() == 0) {
        QString filename = leFilename->text();
        filename = filename + ".txt";
        QFile file(filename);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            qDebug() << "No se puedo abrir";
            return;
        }
        QTextStream out(&file);
        out << teTexto->toPlainText() << "\n";
        qDebug() << "Se creo y el texto se ingreso";
    }
}
