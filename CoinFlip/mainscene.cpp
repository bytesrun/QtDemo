#include "mainscene.h"
#include "ui_mainscene.h"
#include <QPainter>
#include "mypushbutton.h"
#include <QTimer>
#include "mycoin.h"
#include <QSound>
MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);

    this->setFixedSize(320, 588);

    connect(ui->actionQuit, &QAction::triggered, this, [=](){
        this->close();
    });

    this->setWindowIcon(QIcon(":/res/Coin0001.png"));
    this->setWindowTitle("翻金币主场景");

    chooseLevelScene = new ChooseLevelScene(this);
    connect(chooseLevelScene, &ChooseLevelScene::chooseSceneBack, [=](){
        chooseLevelScene->hide();
        this->show();
    });

    MyPushButton *start_btn = new MyPushButton(":/res/MenuSceneStartButton.png");
    start_btn->setParent(this);
    start_btn->move(this->width()*0.5 - start_btn->width()*0.5, this->height()*0.7);
    QSound *startSound = new QSound(":/res/TapButtonSound.wav",this);
    connect(start_btn, &QPushButton::clicked, [=](){
        startSound->play();
        start_btn->zoom1();
        start_btn->zoom2();

        QTimer::singleShot(500, this, [=](){
            this->hide();
            chooseLevelScene->show();
        });

    });
//    MyCoin *coin = new MyCoin(":/res/Coin0001.png");
//    coin->setParent(this);
//    coin->move(100, 100);

}

MainScene::~MainScene()
{
    delete ui;
}

void MainScene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    //painter.drawPixmap(0, 0, pix);
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    pix.load(":/res/Title.png");
    pix = pix.scaled(pix.width()*0.5, pix.height()*0.5);
    painter.drawPixmap(10, 30, pix);


}

