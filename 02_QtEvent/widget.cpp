#include "widget.h"
#include "ui_widget.h"
#include <QString>
#include <QTimer>
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    id1 = startTimer(1000);
    id2 = startTimer(2000);

    QTimer *tm = new QTimer(this);
    connect(tm, &QTimer::timeout, this, [=]() {
        static int num = 1;
        ui->label_4->setText(QString().number(num++));
    });
    tm->start(500);

    connect(ui->pushButton, &QPushButton::clicked, [=](){
        if (tm->isActive())
        {
            tm->stop();
            ui->pushButton->setText("Start");
        }
        else
        {
            tm->start(500);
            ui->pushButton->setText("Pause");
        }
    });

    ui->label->installEventFilter(this);
}
bool Widget::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->label)
    {
        if (event->type() == QEvent::MouseButtonRelease)
        {
            qDebug() << "eventFilter function: MouseButtonRelease";
            return true;
        }

    }

    return QWidget::eventFilter(watched, event);
}
Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent *ev)
{
    if (id1 == ev->timerId())
    {
        static int num = 1;
        ui->label_2->setText(QString().number(num++));
    }

    if (id2 == ev->timerId())
    {
        static int num2 = 1;
        ui->label_3->setText(QString().number(num2++));
    }

}

