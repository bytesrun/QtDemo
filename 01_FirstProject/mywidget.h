#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include "mypushbutton.h"

class myWidget : public QWidget
{
    Q_OBJECT

public:
    myWidget(QWidget *parent = nullptr);
    ~myWidget();
    MyPushButton *btn4;
};
#endif // MYWIDGET_H
