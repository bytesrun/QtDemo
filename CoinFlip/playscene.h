#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include "mycoin.h"
class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    //explicit PlayScene(QWidget *parent = nullptr);
    PlayScene(int levelNum);

    void paintEvent(QPaintEvent *event);
    int levelIndex;
    int gameArray[4][4];
    MyCoin *coinBtn[4][4];
    bool isWin = false;
signals:
    void playSceneBack();
public slots:
};

#endif // PLAYSCENE_H
