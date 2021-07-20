#include "smallwidget.h"
#include "ui_smallwidget.h"

SmallWidget::SmallWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SmallWidget)
{
    ui->setupUi(this);
    void (QSpinBox:: *spSignal)(int) = &QSpinBox::valueChanged;
    connect(ui->spinBox, spSignal, this, [=](int val){
        ui->horizontalScrollBar->setValue(val);
        _val = val;
    });

    connect(ui->horizontalScrollBar, &QScrollBar::valueChanged, this, [=](int val){
        ui->spinBox->setValue(val);
        _val = val;
    });

}

SmallWidget::~SmallWidget()
{
    delete ui;
}

int SmallWidget::getValue()
{
    return _val;
}
void SmallWidget::setValue(int val)
{
    ui->spinBox->setValue(val);
}
