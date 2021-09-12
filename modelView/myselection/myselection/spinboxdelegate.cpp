#include "spinboxdelegate.h"

SpinBoxDelegate::SpinBoxDelegate(QObject *parent) : QItemDelegate(parent)
{

}

QWidget* SpinBoxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QSpinBox *editor = new QSpinBox(parent);
    editor->setMinimum(0);
    editor->setMaximum(100);
    return editor;
}

void SpinBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QSpinBox *spinEditor = dynamic_cast<QSpinBox*>(editor);
    spinEditor->setValue(index.data(Qt::ItemDataRole::EditRole).toInt());
}

void SpinBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QSpinBox *spinEditor = dynamic_cast<QSpinBox*>(editor);
    spinEditor->interpretText();
    int value = spinEditor->value();
    model->setData(index, value, Qt::ItemDataRole::EditRole);
}

void SpinBoxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}
