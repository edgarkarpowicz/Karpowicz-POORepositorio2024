#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLabel testone( "<H1> TESTING #1 </H1>" );
    QWidget testtwo;
    QPushButton testhree;
    QLineEdit testfour;
    testone.show();
    testtwo.show();
    testhree.show();
    testfour.show();
    return a.exec();
}
