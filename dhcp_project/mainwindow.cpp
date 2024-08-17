#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../src/show.h"

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

	QString macStr = QString::fromStdString(std::string(mac));
	macStr = macStr.replace(":", "").toLower();

	qDebug() << macStr;
	Show* show = new Show(nullptr, macStr);
	show->PlayWavFile();
	show->OpenImgFile();
}

void MainWindow::on_pushButton_clicked()
{
    thread_.intfName_ = ui->leInterface->text();
    thread_.start();
}

