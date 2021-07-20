#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Name" << "Gender" << "Age");

    ui->tableWidget->setRowCount(5);

    ui->tableWidget->setItem(0, 0, new QTableWidgetItem("A00"));
    for (int i=0; i<5; ++i)
    {
        char c = 'A' + i;
        std::string str;
        //str = c;
        for (int j=0; j<3; ++j)
        {
            str = c + std::to_string(j);
            ui->tableWidget->setItem( i, j, new QTableWidgetItem( QString(str.c_str()) ) );
        }
    }

    QTableWidgetItem *itm = ui->tableWidget->item(1, 1);
    itm->setTextColor(Qt::blue);
    itm->setBackgroundColor(Qt::red);
    itm->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
}

Widget::~Widget()
{
    delete ui;
}

