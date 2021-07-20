#include "mylabel.h"
#include <QDebug>
#include <QMouseEvent>
myLabel::myLabel(QWidget *parent) : QLabel(parent)
{
    setMouseTracking(true);
}

void myLabel::enterEvent(QEvent *event)
{
    qDebug() << "Mouse entering";
}
void myLabel::leaveEvent(QEvent *event)
{
    qDebug() << "Mouse leaving";
}

void myLabel::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "Button Preesing";
}
void myLabel::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << "Button Released";
}
void myLabel::mouseMoveEvent(QMouseEvent *event)
{
    QString str = QString("Moving x: %1 y: %2").arg(event->x()).arg(event->y());

    qDebug() << str;
}

bool myLabel::event(QEvent *e)
{
    if (e->type() == QEvent::MouseButtonPress)
    {
        qDebug() << "event function: MouseButtonPress";
        return true;
    }

    return QLabel::event(e);
}
