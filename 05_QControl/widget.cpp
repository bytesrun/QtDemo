#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->rBtnMan->setChecked(true);
    connect(ui->rBtnFm, &QRadioButton::clicked, this, [=](){
        qDebug() << "Select Female";
    });

    connect(ui->cBox, &QCheckBox::stateChanged, this, [=](int state){
        qDebug() << state;
    });

    ui->listWidget->addItem("row 1");
    QListWidgetItem *itm = ui->listWidget->item(0);
    itm->setTextAlignment(Qt::AlignCenter);

    QListWidgetItem *itm2 = new QListWidgetItem("row 2");
    ui->listWidget->addItem(itm2);
    itm2->setTextColor(QColor(255, 0, 0));
    itm2->setTextAlignment(Qt::AlignRight);
    itm2->setBackgroundColor(Qt::black);

    QStringList list;
    list << "row 3" << "row 4";
    ui->listWidget->addItems(list);
}

Widget::~Widget()
{
    delete ui;
}

