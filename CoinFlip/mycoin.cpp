#include "mycoin.h"
#include<QDebug>
#include<QTimer>
MyCoin::MyCoin(QString butImg)
{
    QPixmap pixmap;
    bool ret = pixmap.load(butImg);
    if(!ret)
    {
        qDebug() << butImg << "加载图片失败!";
    }

    this->setFixedSize( pixmap.width(), pixmap.height() );
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pixmap);
    this->setIconSize(QSize(pixmap.width(),pixmap.height()));

    tm1 = new QTimer(this);
    tm2 = new QTimer(this);

    connect(tm1, &QTimer::timeout, [=](){
        changeImg(++min);
        if (8 == min){
            min = 1;
            tm1->stop();
            bFliping = false;
            //return;
        }
    });

    connect(tm2, &QTimer::timeout, [=](){
        changeImg(--max);
        if (1 == max){
            max = 8;
            tm2->stop();
            bFliping = false;
            //return;
        }
    });
}

void MyCoin::changeImg(int index)
{
    QPixmap pixmap;
    QString butImg = QString(":/res/Coin000%1").arg(index);
    bool ret = pixmap.load(butImg);
    if(!ret)
    {
        qDebug() << butImg << "加载图片失败!";
    }

    this->setFixedSize( pixmap.width(), pixmap.height() );
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pixmap);
    this->setIconSize(QSize(pixmap.width(),pixmap.height()));
}

void MyCoin::changeFlag()
{
    if (bFliping) return;
    bFliping = true;
    if (bFlag)
    {
        tm1->start(30);
        bFlag = false;
    }
    else
    {
        tm2->start(30);
        bFlag = true;
    }
}

void MyCoin::mousePressEvent(QMouseEvent *e)
{
    if (bFliping || this->isWin) {
        return;
    }
    else
    {
        return QPushButton::mousePressEvent(e);
    }
}
