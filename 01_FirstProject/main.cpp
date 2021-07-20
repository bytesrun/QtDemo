#include "mywidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    //应用程序类实例
    QApplication a(argc, argv);
    //程序窗口
    myWidget w;
    //调用窗口方法
    w.show();
    //enter into a message loop
    return a.exec();
}
