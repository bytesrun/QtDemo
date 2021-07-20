#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QDebug>
#include <QTimer>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    posX_ = 0;
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        posX_ += 20;
        update();
    });

    QTimer *tm = new QTimer(this);
    tm->setInterval(1000);
    connect(tm, &QTimer::timeout, [=](){
        posX_ += 20;
        if (posX_ > this->width()) {
            posX_ = 0;
        }
        update();
    });
    tm->start();
}

void Widget::timerEvent(QTimerEvent *e)
{
//    posX_ += 20;
//    if (posX_ > this->width()) {
//        posX_ = 0;
//    }
//    update();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    //**********Painter 1***************
    QPainter paint(this);
    QPen pen;
    pen.setColor(Qt::red);
    pen.setStyle(Qt::PenStyle::DotLine);
    pen.setWidth(3);
    paint.setPen(pen);

    QBrush brush;
    brush.setColor(Qt::blue);
    brush.setStyle(Qt::BrushStyle::Dense7Pattern);
    paint.setBrush(brush);

    paint.drawLine(0, 0, 100, 100);
    paint.drawEllipse(QPoint(100, 100), 50, 50);
    paint.drawRect(20, 20, 50, 50);
    paint.drawText(QRect(10, 200, 100, 100), "Learn Everyday");

    //**********Painter 2***************
    QPainter painter(this);
    painter.drawEllipse(QPoint(100, 50), 50, 50);
    painter.setRenderHint(QPainter::RenderHint::Antialiasing);
    painter.drawEllipse(QPoint(150, 50), 50, 50);

    painter.drawRect(QRect(20, 200, 50, 50));
    painter.save();
    painter.translate(60, 0);
    painter.drawRect(QRect(20, 200, 50, 50));
    painter.translate(60, 0);
    painter.restore();
    painter.drawRect(QRect(20, 200, 50, 50));

    qDebug() << "drawing ...";

    QPainter painter3(this);
    QPixmap mp(":/Image/rec2.bmp");
    painter3.drawPixmap(posX_, 10, mp);
}
