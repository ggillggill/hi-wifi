#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(&thread_, &CaptureThread::captured, this, &MainWindow::doCapture);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::doCapture(Mac mac) {
    qDebug() << "captured" << std::string(mac);
}

void MainWindow::on_pushButton_clicked()
{
    thread_.intfName_ = ui->leInterface->text();
    thread_.start();
}

