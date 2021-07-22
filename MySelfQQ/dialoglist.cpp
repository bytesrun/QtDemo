#include "dialoglist.h"
#include "ui_dialoglist.h"
#include <QToolButton>
#include <QVector>
#include "widget.h"
#include <QMessageBox>
#include <QDebug>

DialogList::DialogList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DialogList)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/Image/LuffyQ.png"));
    QList<QString> lst;
    lst << "butterfly.png" << "down.png" << "Frame.jpg" << "Luffy.png"
        << "OnePiece.png" << "Sunny.jpg" << "sunny.png" << "up.png" << "butterfly1.png";

    QVector<QToolButton*> vBtns;
    for (int i = 0; i < 9; ++i)
    {
        QToolButton *btn = new QToolButton;
        btn->setText(QString("member %1").arg(i));
        QPixmap icon(QString(":/Image/%1").arg(lst[i]));
        //QIcon icon(QString(":/Image/%1").arg(lst[i]));
        btn->setIcon(icon);
        //btn->setIconSize(icon.size());
        btn->setIconSize(QSize(100, 100));

        btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        btn->setAutoRaise(true);
        ui->vLayout->addWidget(btn);
        vBtns.push_back(btn);
    }

    QVector<bool> isShow(vBtns.size(), false);
    qDebug() << "vBtn size = " << vBtns.size();
    for (int i = 0; i < vBtns.size(); ++i)
    {
        connect(vBtns[i], &QToolButton::clicked, [=]()mutable{
            if (isShow[i])
            {
                QString str = QString("%1 is already opened").arg(vBtns[i]->text());
                QMessageBox::warning(this, "warning", str);
                return;
            }
            isShow[i] = true;
            Widget *wdg = new Widget(0, vBtns[i]->text());
            wdg->setAttribute(Qt::WA_DeleteOnClose);

            wdg->setWindowTitle(vBtns[i]->text());
            wdg->setWindowIcon(vBtns[i]->icon());
            wdg->show();
            connect(wdg, &Widget::closeWidget, this, [=, &isShow](){
                isShow[i] = false;
            });
        });

    }

}

DialogList::~DialogList()
{
    delete ui;
}
