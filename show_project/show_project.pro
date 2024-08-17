QT       += core gui
QT += multimedia

DEST_DIR=../
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
LIBS += -lpcap

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    mainwindow.ui

HEADERS += \
    ../src/capture.h \
    ../src/ethhdr.h \
    ../src/ip.h \
    ../src/iphdr.h \
    ../src/mac-map.h \
    ../src/mac.h \
    ../src/show.h \
    ../src/udp.h \
    mainwindow.h

SOURCES += \
    ../src/capture.cpp \
    ../src/ethhdr.cpp \
    ../src/ip.cpp \
    ../src/iphdr.cpp \
    ../src/mac-map.cpp \
    ../src/mac.cpp \
    ../src/show.cpp \
    main.cpp \
    mainwindow.cpp
