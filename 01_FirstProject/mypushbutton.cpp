#include "mypushbutton.h"

MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
{
    qDebug() << "MyPushButton Constructor";
}

MyPushButton::~MyPushButton()
{
    qDebug() << "MyPushButton Destructor";
}
