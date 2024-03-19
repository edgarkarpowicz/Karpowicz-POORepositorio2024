#include <QCoreApplication>
#include <QtGlobal>
#include <iostream>
using namespace std ;

namespace EKFunctions {
    void GET_LATEST_QT_VERSION() {
        cout << qVersion() << endl;
    }

    void GET_LIBRARY_VERSION() {
        cout << "v0.0.1 - 18032024" << endl;
    }
}
