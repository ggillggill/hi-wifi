#include "mainwindow.h"
#include "../src/mac-map.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    InitMacMap();
    MainWindow w;
    w.show();
    return a.exec();
}
