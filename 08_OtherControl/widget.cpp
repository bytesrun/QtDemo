#include "widget.h"
#include "ui_widget.h"
#include <QMovie>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //StackedWidget, ScrollArea, toolbox, tabWidget
    ui->stackedWidget->setCurrentIndex(1);
    connect(ui->btn_scroll, &QPushButton::clicked, this, [=](){
       ui->stackedWidget->setCurrentIndex(0);
    });

    connect(ui->btn_tool, &QPushButton::clicked, this, [=](){
       ui->stackedWidget->setCurrentIndex(2);
    });

    connect(ui->btn_tab, &QPushButton::clicked, this, [=](){
       ui->stackedWidget->setCurrentIndex(1);
    });

    //QComboBox
    ui->comboBox->addItem("item_1");
    ui->comboBox->addItems(QStringList() << "item_2" << "item_3" << "item_4");

    connect(ui->btn_select, &QPushButton::clicked, this, [=](){
        //ui->comboBox->setCurrentIndex(2);
        //ui->comboBox->setCurrentText("itme_3");
        ui->comboBox->setCurrentText("item_3");
    });

    //Label img
    QPixmap pimg(":/Image/test.bmp");
    QPixmap pimg2 = pimg.scaled(ui->label_img->size());
    //ui->label_img->setPixmap(pimg2);
    ui->label_img->setPixmap(pimg);
    ui->label_img->setScaledContents(true);

    //Label movie
    QMovie *mve = new QMovie(":/Image/gif.gif");
    ui->label_gif->setMovie(mve);
    ui->label_gif->setScaledContents(true);
    mve->start();
}

Widget::~Widget()
{
    delete ui;
}

