#include "widget.h"
#include <QPushButton>
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    th = new Teacher;
    st = new Student;

    void (Teacher::*tsignal)() = &Teacher::hungry;
    void (Student::*stSlot)() = &Student::treat;

    void (Teacher::*tsignal2)(QString) = &Teacher::hungry;
    void (Student::*stSlot2)(QString) = &Student::treat;


    //connect(th, &Teacher::hungry, st, &Student::treat);
    connect(th, tsignal2, st, stSlot2);
//    classOver();

    QPushButton *btn = new QPushButton("ClassOver", this);
    connect(btn, &QPushButton::clicked, this, &Widget::classOver);
    //connect(btn, &QPushButton::clicked, this->th, &Teacher::hungry);
    //connect(btn, &QPushButton::clicked, this->th, tsignal2);
    //resize(400, 600);
    setFixedSize(600, 400);

    QPushButton *btn_close = new QPushButton("CLOSE", this);
    btn_close->move(100, 100);
    connect(btn_close, &QPushButton::clicked, this, &Widget::close);

    QPushButton *btn_Lambda = new QPushButton("LAMBDA", this);
    btn_Lambda->move(200, 100);
    connect(btn_Lambda, &QPushButton::clicked, this,
            [=](){
             btn_Lambda->setText("HELLO");
             emit th->hungry("CAKE");
        });

//    int (* ret)() = []()->int {return 1000;} ;
//    int x = ret();
    int ret = []()->int {return 1000;} ();
    qDebug() << ret;

    QPushButton *btn_wnd = new QPushButton("WND", this);
    btn_wnd->move(300, 100);
    QWidget *pNew = nullptr;
    connect(btn_wnd, &QPushButton::clicked, this, [=]()mutable{
        if (!pNew) {
            pNew = new QWidget;
            pNew->show();
            pNew->resize(200, 200);
            pNew->move(100, 100);
            btn_wnd->setText("C_WND");
        }
        else {
            pNew->close();
            delete pNew;
            pNew = nullptr;
            btn_wnd->setText("WND");
        }
    });
}

Widget::~Widget()
{
}

void Widget::classOver()
{
    //emit th->hungry();
    emit th->hungry("CAKE");
}

