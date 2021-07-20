#include "playscene.h"
#include <QMenuBar>
#include <QPainter>
#include "mypushbutton.h"
#include <QTimer>
#include <QLabel>
#include "mycoin.h"
#include "dataconfig.h"
#include "QDebug"
#include <QSound>
#include <QPropertyAnimation>
//PlayScene::PlayScene(QWidget *parent) : QMainWindow(parent)
//{

//}

PlayScene::PlayScene(int levelNum)
{
    levelIndex = levelNum;
    this->setFixedSize(320, 588);
    this->setWindowIcon(QIcon(":/res/Coin0001.png"));
    this->setWindowTitle("翻金币场景");
    QMenuBar *bar = menuBar();
    this->setMenuBar(bar);

    QMenu *menu = new QMenu(this);
    menu->setTitle("开始");
    bar->addMenu(menu);

    QAction *actionQuit = new QAction(this);
    actionQuit->setText("退出");
    menu->addAction(actionQuit);
    connect(actionQuit, &QAction::triggered, [=](){
        this->close();
    });

    MyPushButton *back_btn = new MyPushButton(":/res/BackButton.png", ":/res/BackButtonSelected.png");
    back_btn->setParent(this);
    back_btn->move(this->width()-back_btn->width(), this->height()-back_btn->height());

    connect(back_btn, &QPushButton::clicked, [=](){
        QTimer::singleShot(500, this, [=](){
            this->hide();
            //this->close();
            emit playSceneBack();

            //
        });
    });

    QLabel *label_lev = new QLabel(this);
    label_lev->move(20, 530);
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    label_lev->setFont(font);
    label_lev->setText(QString("Level:  %1").arg(this->levelIndex));
    label_lev->setGeometry(QRect(30, this->height() - 50,120, 50));

    dataConfig data;
    for (int i=0; i<4; ++i)
    {
        for (int j=0; j<4; ++j)
        {
            gameArray[i][j] = data.mData[this->levelIndex][i][j];
        }
    }

    QLabel* winLabel = new QLabel;
    QPixmap tmpPix;
    tmpPix.load(":/res/LevelCompletedDialogBg.png");
    winLabel->setGeometry(0,0,tmpPix.width(),tmpPix.height());
    winLabel->setPixmap(tmpPix);
    winLabel->setParent(this);
    winLabel->move( (this->width() - tmpPix.width())*0.5 , -tmpPix.height());

    //翻金币音效
    QSound *flipSound = new QSound(":/res/ConFlipSound.wav",this);
    //胜利按钮音效
    QSound *winSound = new QSound(":/res/LevelWinSound.wav",this);
    for (int i=0; i<4; ++i)
    {
        for (int j=0; j<4; ++j)
        {
            //绘制背景图片
            QLabel* label = new QLabel;
            label->setGeometry(0,0,50,50);
            label->setPixmap(QPixmap(":/res/BoardNode.png"));
            label->setParent(this);
            label->move(57 + i*50,200+j*50);

            //MyCoin button
            QString img = ":/res/Coin0001.png";
            if (0 == gameArray[i][j]) img = ":/res/Coin0008.png";
            MyCoin *coin = new MyCoin(img);
            coin->setParent(this);
            coin->bFlag = gameArray[i][j];
            coin->posX = i;
            coin->posY = j;
            coin->setParent(this);
            coin->move(59 + i*50,204+j*50);

            coinBtn[i][j] = coin;
            connect(coin, &QPushButton::clicked, [=](){
                qDebug() << QString("Click Button: ");
                flipSound->play();
                coin->changeFlag();

                QTimer::singleShot(300, this,[=](){
                    if(coin->posX+1 <=3)
                    {
                        coinBtn[coin->posX+1][coin->posY]->changeFlag();
                        gameArray[coin->posX+1][coin->posY] = gameArray[coin->posX+1][coin->posY]== 0 ? 1 : 0;
                    }
                    if(coin->posX-1>=0)
                    {
                        coinBtn[coin->posX-1][coin->posY]->changeFlag();
                        gameArray[coin->posX-1][coin->posY] = gameArray[coin->posX-1][coin->posY]== 0 ? 1 : 0;
                    }
                    if(coin->posY+1<=3)
                    {
                        coinBtn[coin->posX][coin->posY+1]->changeFlag();
                        gameArray[coin->posX][coin->posY+1] = gameArray[coin->posX+1][coin->posY]== 0 ? 1 : 0;
                    }
                    if(coin->posY-1>=0)
                    {
                        coinBtn[coin->posX][coin->posY-1]->changeFlag();
                        gameArray[coin->posX][coin->posY-1] = gameArray[coin->posX+1][coin->posY]== 0 ? 1 : 0;
                    }

                    this->isWin = true;
                    for (int i=0; i<4; ++i)
                    {
                        for (int j=0; j<4; ++j)
                        {
                            if (!coinBtn[i][j]->bFlag)
                            {
                                this->isWin = false;
                                break;
                            }
                        }
                        if (!this->isWin) break;
                    }

                    if (this->isWin)
                    {
                        qDebug() << "Victory!";
                        winSound->play();
                        for(int i = 0 ; i < 4;i++)
                        {
                            for(int j = 0 ; j < 4; j++)
                            {
                                coinBtn[i][j]->isWin = true;
                            }
                        }

                        QPropertyAnimation * animation1 =  new QPropertyAnimation(winLabel,"geometry");
                        animation1->setDuration(1000);
                        animation1->setStartValue(QRect(winLabel->x(),winLabel->y(),winLabel->width(),winLabel->height()));
                        animation1->setEndValue(QRect(winLabel->x(),winLabel->y()+114,winLabel->width(),winLabel->height()));
                        animation1->setEasingCurve(QEasingCurve::OutBounce);
                        animation1->start();


                    }
                });
            });
        }
    }
}

void PlayScene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    pix.load(":/res/Title.png");
    pix = pix.scaled(pix.width()*0.5, pix.height()*0.5);
    painter.drawPixmap(10, 30, pix);
}
