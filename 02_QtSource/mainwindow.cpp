#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->actionNew->setIcon(QIcon(":/Image/rec2.bmp"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

