QT = core widgets

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        bateria.cpp \
        electrico.cpp \
        guitarra.cpp \
        instrumento.cpp \
        main.cpp \
        teclado.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    bateria.h \
    electrico.h \
    guitarra.h \
    instrumento.h \
    teclado.h
