#ifndef SMALLWIDGET_H
#define SMALLWIDGET_H

#include <QWidget>

namespace Ui {
class SmallWidget;
}

class SmallWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SmallWidget(QWidget *parent = nullptr);
    ~SmallWidget();
    int getValue();
    void setValue(int val);
private:
    Ui::SmallWidget *ui;
    int _val;
};

#endif // SMALLWIDGET_H
