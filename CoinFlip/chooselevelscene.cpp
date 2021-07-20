#include "chooselevelscene.h"
#include <QPainter>
#include <QMenuBar>
#include "mypushbutton.h"
#include <QTimer>
#include <QLabel>
#include <QDebug>
#include "playscene.h"
#include <QSound>
ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent), play(NULL)
{
    this->setFixedSize(320, 588);
    this->setWindowIcon(QIcon(":/res/Coin0001.png"));
    QMenuBar *bar = menuBar();
    this->setMenuBar(bar);
    QMenu *menu = new QMenu(this);
    menu->setTitle("开始");
    bar->addMenu(menu);
    QAction *actionQuit = new QAction(this);
    actionQuit->setText("退出");
    menu->addAction(actionQuit);
    this->setWindowTitle("关卡选择场景");
    connect(actionQuit, &QAction::triggered, [=](){
        this->close();
    });

    MyPushButton *back_btn = new MyPushButton(":/res/BackButton.png", ":/res/BackButtonSelected.png");
    back_btn->setParent(this);
    back_btn->move(this->width()-back_btn->width(), this->height()-back_btn->height());

    connect(back_btn, &QPushButton::clicked, [=](){
        QTimer::singleShot(500, this, [=](){
            emit chooseSceneBack();
        });
    });

    QSound *chooseSound = new QSound(":/res/TapButtonSound.wav",this);
    for (int i=0; i<20; ++i)
    {
        MyPushButton *menuBtn = new MyPushButton(":/res/LevelIcon.png");
        menuBtn->setParent(this);
        menuBtn->move(25+i%4*70, 130 + i/4 *70);
        //menuBtn->setText(QString::number(i+1));
        //menuBtn->setWindowIconText(QString::number(i+1));
        connect(menuBtn, &QPushButton::clicked, [=](){
            QString str = QString("Seclect %1 level").arg(i+1);
            qDebug() << str;
            chooseSound->play();
            play = new PlayScene(i+1);
            this->hide();
            play->show();
            connect(play, &PlayScene::playSceneBack, [=](){
                this->show();
                //play->setAttribute(Qt::WidgetAttribute::WA_DeleteOnClose);
                //play->setParent(nullptr);
                //play->close();
                delete play;
                play = nullptr;
            });
        });
        QLabel *label = new QLabel(this);
        label->setFixedSize(menuBtn->width(), menuBtn->height());
        label->move(25+i%4*70, 130 + i/4 *70);
        label->setText(QString::number(i+1));
        label->setAlignment(Qt::AlignmentFlag::AlignHCenter | Qt::AlignmentFlag::AlignVCenter);
        label->setAttribute(Qt::WidgetAttribute::WA_TransparentForMouseEvents);
    }
}

void ChooseLevelScene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    pix.load(":/res/Title.png");
    painter.drawPixmap(this->width()*0.5-pix.width()*0.5, 30, pix);
}
