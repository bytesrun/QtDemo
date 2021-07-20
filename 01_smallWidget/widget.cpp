#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->btn_Get, &QPushButton::clicked, this, [=](){
        int val = ui->widget->getValue();
        std::string str = std::to_string(val);
        QString s(str.c_str());
        ui->btn_Get->setText("GetValue (" + s + ")");
    });

    connect(ui->btn_Set, &QPushButton::clicked, [=](){
        ui->widget->setValue(55);
    });
}

Widget::~Widget()
{
    delete ui;
}

