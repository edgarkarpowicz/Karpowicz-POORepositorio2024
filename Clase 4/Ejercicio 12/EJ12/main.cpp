#include <QApplication>
#include <QLabel>
#include <QTimer>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QLabel IMG;
    IMG.setPixmap(QPixmap("C:\IMG.jpg"));
    IMG.setScaledContents(true);
    IMG.showMaximized();
    IMG.show();

    QTimer::singleShot(3000, &a, SLOT(quit()));

    return a.exec();
}
