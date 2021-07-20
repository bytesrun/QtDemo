#ifndef MYCOIN_H
#define MYCOIN_H

#include <QWidget>
#include <QPushButton>
#include <QTimer>
class MyCoin : public QPushButton
{
    Q_OBJECT
public:

    MyCoin(QString butImg);

    void changeImg(int index);
    void changeFlag();
    QTimer *tm1;
    QTimer *tm2;
    bool bFlag = false;
    bool bFliping = false;
    int posX;
    int posY;

    int min = 1;
    int max = 8;
    bool isWin = false;
    void mousePressEvent(QMouseEvent *e);
signals:

};

#endif // MYCOIN_H
