#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->treeWidget->setHeaderLabels(QStringList() << "Hero" << "Info");
    QTreeWidgetItem *itm1 = new QTreeWidgetItem(QStringList() << "ITM1");
    QTreeWidgetItem *itm2 = new QTreeWidgetItem(QStringList() << "ITM2");
    QTreeWidgetItem *itm3 = new QTreeWidgetItem(QStringList() << "ITM3");
    ui->treeWidget->addTopLevelItem(itm1);
    ui->treeWidget->addTopLevelItem(itm2);
    ui->treeWidget->addTopLevelItem(itm3);

    QStringList her1;
    her1 << "name1" << "info1";
    QStringList her2;
    her2 << "name2" << "info2";
    QTreeWidgetItem *itm11 = new QTreeWidgetItem(her1);
    QTreeWidgetItem *itm12 = new QTreeWidgetItem(her2);
    itm1->addChild(itm11);
    itm1->addChild(itm12);

    itm2->addChild(itm11);
    itm2->addChild(itm12);

    itm3->addChild(itm11);
    itm3->addChild(itm12);

}

Widget::~Widget()
{
    delete ui;
}

