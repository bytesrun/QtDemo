#include "mywidget.h"
#include <QPushButton>
#include "mypushbutton.h"
//同名文件切换F4
//comment: ctrl + /

//run: ctrl + r
//auto to align: ctrl + i
//
myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *btn = new QPushButton();
//    btn->show();
    btn->setParent(this);
    btn->setText("第一个按钮");

    QPushButton *btn2 = new QPushButton("第二个按钮", this);
    btn2->show();
    btn2->move(100, 100);

    resize(600, 400);
    setWindowTitle("The First Window");
    setFixedSize(600, 400);

    MyPushButton *myBtn = new MyPushButton(this);
    myBtn->setText("My Button");
    myBtn->move(200, 100);
    myBtn->show();

    connect(myBtn, &MyPushButton::clicked, this, &myWidget::close);

    btn4 = new MyPushButton(this);
    btn4->move(200, 200);
    btn4->show();
}

myWidget::~myWidget()
{
    btn4->~MyPushButton();
    qDebug() << "myWidget destructor";
}

