#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QDebug>
#include <cstdlib>
#include <iostream>
#include <QMessageBox>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionNew, &QAction::triggered, this, [=](){
        //Modal Dialog
//        QDialog dlg(this);
//        dlg.setWindowTitle("dlg1");
//        dlg.resize(200, 100);
//        dlg.exec();
//        qDebug() << "Modal dlg poped out.";

        //UnModal Dialog
//        QDialog dlg2(this);
//        dlg2.setWindowTitle("dlg2");
//        dlg2.resize(200, 100);
//        dlg2.show();

//        QDialog *dlg3 = new QDialog(this);
//        dlg3->setWindowTitle("dlg3");
//        dlg3->resize(200, 100);
//        dlg3->setAttribute(Qt::WA_DeleteOnClose);
//        dlg3->show();

//        system("pause");
//        std::cout << "Please press any key to release dlg2:" << std::endl;

        //QMessageBox
        QMessageBox::critical(this, "Critical", "CR");
        QMessageBox::information(this, "info", "INF");
        QMessageBox::question(this, "Question", "Right?");

        if (QMessageBox::StandardButton::Save == QMessageBox::question(this, "Q2", "Save ?", QMessageBox::StandardButton::Save | QMessageBox::StandardButton::No) )
        {
            qDebug() << "Save ....";
        }
        QMessageBox::warning(this, "warning", "OK?");

    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

