#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    // Show* show = new Show;

    // Mac mac("6a19dd9cf6cf");
    // show->PlayWavFile(mac);
    // show->OpenImgFile(mac);
}

