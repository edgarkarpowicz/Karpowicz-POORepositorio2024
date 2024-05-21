#include "parser.h"
#include "ui_parser.h"

Parser::Parser(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Parser)
{
    ui->setupUi(this);

    connect(ui->pbBuscar, SIGNAL(clicked(bool)), this, SLOT(slot_descargar_html()));
    connect(this, SIGNAL(signal_HTML_descargado()), this, SLOT(slot_descargar_archivos()));
    connect(ui->pbDibujar, SIGNAL(clicked(bool)), this, SLOT(slot_QDialog_img_disco()));
}

Parser::~Parser()
{
    delete ui;
}

void Parser::getRecursos() {

    qDebug() << "Consiguiendo Recursos...";
    qDebug() << "HTML es Vacio?" << html_storage.isEmpty();

    css_list = new QStringList();

    QRegularExpression cssRegex("<link\\s+.*?href=\"(.*?)\".*?>");
    QRegularExpressionMatchIterator cssMatches = cssRegex.globalMatch(html_storage);
    while(cssMatches.hasNext()) {
        qDebug() << "Adentro de CSS";
        QRegularExpressionMatch match = cssMatches.next();
        QString cssURL = match.captured(1);
        css_list->push_back(cssURL);
    }

    qDebug() << "CSS obtenido";

    js_list = new QStringList();

    QRegularExpression jsRegex("<script\\s+.*?src=\"(.*?)\".*?>");
    QRegularExpressionMatchIterator jsMatches = jsRegex.globalMatch(html_storage);
    while(jsMatches.hasNext()) {
        qDebug() << "Adentro de JS";
        QRegularExpressionMatch match = jsMatches.next();
        QString jsURL = match.captured(1);
        js_list->push_back(jsURL);
    }

    qDebug() << "JS obtenido";

    img_list = new QStringList();

    QRegularExpression imgRegex("<img\\s+.*?src=\"(.*?)\".*?>");
    QRegularExpressionMatchIterator imgMatches = imgRegex.globalMatch(html_storage);
    while(imgMatches.hasNext()) {
        qDebug() << "Adentro de IMG";
        QRegularExpressionMatch match = imgMatches.next();
        QString imgURL = match.captured(1);
        img_list->push_back(imgURL);
    }

    qDebug() << "IMG obtenido";
    qDebug() << "Todos los Recursos Conseguidos...";
}

void Parser::slot_descargar_html() {
    if (!(ui->leURL->text().isEmpty()) && !(ui->leGuardado->text().isEmpty())) {
        qDebug() << "Descargando HTML...";

        filePath = ui->leGuardado->text();
        filePath += "/";
        qDebug() << "Direccion de Guardado:" << filePath;

        manager = new QNetworkAccessManager(this);
        connect(manager, SIGNAL(finished(QNetworkReply * )), this, SLOT(slot_html_descargado(QNetworkReply * )));
        QNetworkRequest request(QUrl(ui->leURL->text()));
        manager->get(request);
    } else {
        qDebug() << "Falta la URL y/o la Directorio de Guardado. Vuelva a Intentar";
    }
}

void Parser::slot_descargar_archivos() {
    getRecursos();

    qDebug() << "A punto de ponerme a descargar todos los Recursos...";

    css_list_pos = 0;
    connect(this, SIGNAL(signal_iniciar_descarga_css()), this, SLOT(slot_descargar_CSS()));
    emit signal_iniciar_descarga_css();

    js_list_pos = 0;
    connect(this, SIGNAL(signal_iniciar_descarga_js()), this, SLOT(slot_descargar_JS()));
    emit signal_iniciar_descarga_js();

    img_list_pos = 0;
    connect(this, SIGNAL(signal_iniciar_descarga_img()), this, SLOT(slot_descargar_IMG()));
    emit signal_iniciar_descarga_img();

    qDebug() << "Finalizado!";
}

void Parser::slot_html_descargado(QNetworkReply* reply) {
    qDebug() << "Guardando HTML y Emitiendo SIGNAL...";
    html_storage = reply->readAll();

    QString fileName = "/html.txt";
    QFile file(filePath + fileName);
    if(!file.open(QIODevice::ReadWrite))
    {
        qDebug() << "Se ha creado el Archivo HTML";
    }
    file.write(html_storage.toUtf8());

    ui->teHTML->setText(html_storage);
    emit signal_HTML_descargado();
}

void Parser::slot_descargar_CSS() {
    if (css_list->isEmpty() || css_list_pos == css_list->size()) {
        return;
    } else {
        manager = new QNetworkAccessManager();
        connect(manager, SIGNAL(finished(QNetworkReply * )), this, SLOT(slot_css_descargado(QNetworkReply *)));

        qDebug() << "Descargando CSS... Estoy en la Posicion" << css_list_pos << "| Size de Lista es:" << css_list->size();
        qDebug() << "URL en la Posicion Actual:" << css_list->at(css_list_pos);
        QNetworkRequest request(QUrl(css_list->at(css_list_pos)));
        manager->get(request);

        connect(this, SIGNAL(signal_CSS_descargado()), this, SLOT(slot_descargar_CSS()));
        css_list_pos++;
    }
}

void Parser::slot_descargar_JS() {
    if (js_list->isEmpty() || js_list_pos == js_list->size()) {
        return;
    } else {
        manager = new QNetworkAccessManager();
        connect(manager, SIGNAL(finished(QNetworkReply * )), this, SLOT(slot_js_descargado(QNetworkReply *)));

        qDebug() << "Descargando JS... Estoy en la Posicion" << js_list_pos << "| Size de Lista es:" << js_list->size();
        qDebug() << "URL en la Posicion Actual:" << js_list->at(js_list_pos);
        QNetworkRequest request(QUrl(js_list->at(js_list_pos)));
        manager->get(request);

        connect(this, SIGNAL(signal_JS_descargado()), this, SLOT(slot_descargar_JS()));
        js_list_pos++;
    }
}

void Parser::slot_descargar_IMG() {
    if (img_list->isEmpty() || img_list_pos == img_list->size()) {
        return;
    } else {
        manager = new QNetworkAccessManager();
        connect(manager, SIGNAL(finished(QNetworkReply * )), this, SLOT(slot_img_descargado(QNetworkReply *)));

        qDebug() << "Descargando IMG... Estoy en la Posicion" << img_list_pos << "| Size de Lista es:" << img_list->size();
        qDebug() << "URL en la Posicion Actual:" << img_list->at(img_list_pos);
        QNetworkRequest request(QUrl(img_list->at(img_list_pos)));
        manager->get(request);

        connect(this, SIGNAL(signal_IMG_descargado()), this, SLOT(slot_descargar_IMG()));
        img_list_pos++;
    }
}

void Parser::slot_css_descargado(QNetworkReply* reply) {
    qDebug() << "Descargando Archivo CSS y Guardando...";
    QString temp_storage = reply->readAll();

    QString fileName = QString::number(css_list_pos);
    fileName += "css.txt";
    qDebug() << "Filename del CSS:" << fileName;

    QFile file(filePath + fileName);
    if(!file.open(QIODevice::ReadWrite))
    {
        qDebug() << "Se ha creado un Archivo CSS con el Nombre" << fileName;
    }
    file.write(temp_storage.toUtf8());
    emit signal_CSS_descargado();
}

void Parser::slot_js_descargado(QNetworkReply* reply) {
    qDebug() << "Descargando Archivo JS y Guardando...";
    QString temp_storage = reply->readAll();

    QString fileName = QString::number(js_list_pos);
    fileName += "js.txt";
    qDebug() << "Filename del JS:" << fileName;

    QFile file(filePath + fileName);
    if(!file.open(QIODevice::ReadWrite))
    {
        qDebug() << "Se ha creado un Archivo JS con el Nombre" << fileName;
    }
    file.write(temp_storage.toUtf8());
    emit signal_JS_descargado();
}

void Parser::slot_img_descargado(QNetworkReply* reply) {
    qDebug() << "Descargando Archivo IMG y Guardando...";
    QImage temp_storage = QImage::fromData(reply->readAll());

    QString fileName = QString::number(img_list_pos);
    fileName += "img.png";
    qDebug() << "Filename de la IMG:" << fileName;

    QString fullFileName = filePath + fileName;
    QFile file(filePath + fileName);
    if(!file.open(QIODevice::ReadWrite))
    {
        qDebug() << "Se ha creado un Archivo IMG con el Nombre" << fileName;
    }
    temp_storage.save(fullFileName);
    emit signal_IMG_descargado();
}

void Parser::slot_QDialog_img_disco() {
    QFileDialog dialog(this, "Abrir");
    dialog.setNameFilter("Imagen (*.png *.jpg)");
    connect(&dialog, SIGNAL(fileSelected(QString)), this, SLOT(slot_imagen_obtenida(QString)));
    dialog.exec();

    //QString file = QFileDialog::getOpenFileName(this, "Abrir", "./", "Imagen (*.png *.jpg)");
    //connect(QFileDialog, SIGNAL(fileSelected(QString)), this, SLOT(slot_imagen_obtenida(QString)));
}

void Parser::slot_imagen_obtenida(QString str) {
    QFile file(str);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "No se pudo abrir el Archivo";
        return;
    }

    QByteArray imageData = file.readAll();

    img.loadFromData(imageData);
    this->repaint();


    // img = QImage::loadFromData(str);
    // this->repaint();
}

void Parser::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    if(!img.isNull()) {
        painter.drawImage(0, 0, img.scaled(this->size()));
    }
}
