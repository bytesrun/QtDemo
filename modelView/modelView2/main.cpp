#include <QApplication>
#include <QTreeView>
#include <QStandardItemModel>
#include <QDebug>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	
	QStandardItemModel model;
    QStandardItem *parentItem = model.invisibleRootItem();
	QStandardItem *item0 = new QStandardItem;
	item0->setText("A");
	QPixmap pixmap0(50, 50);
	pixmap0.fill("red");
    item0->setIcon(QIcon(pixmap0));
	item0->setToolTip("indexA");

    parentItem->appendRow(item0);

    parentItem = item0;

    QStandardItem *item1 = new QStandardItem;
    item1->setText("B");
    QPixmap pixmap1(50,50);
    pixmap1.fill("blue");
    item1->setIcon(QIcon(pixmap1));
    item1->setToolTip("indexB");
    parentItem->appendRow(item1);

    QStandardItem *item2 = new QStandardItem;
    item2->setData("C", Qt::ItemDataRole::DisplayRole);
    QPixmap pixmap2(50, 50);
    pixmap2.fill(Qt::yellow);

    item2->setData(QIcon(pixmap2), Qt::ItemDataRole::DecorationRole);
    item2->setData("indexC", Qt::ItemDataRole::ToolTipRole);
    parentItem->appendRow(item2);

    QTreeView tree;
    model.setProperty()
    tree.setModel(&model);
    tree.show();

    QModelIndex indexA = model.index(0, 0, QModelIndex());


    qDebug() << "indexA row count:" << model.rowCount(indexA);
    QModelIndex indexB = model.index(0, 0, indexA);
    qDebug() << "indexB text:" << model.data(indexB, Qt::ItemDataRole::EditRole);
    QModelIndex indexC = model.index(1, 0, indexA);
    qDebug() << "indexC tooltip:" << model.data(indexC, Qt::ItemDataRole::ToolTipRole).toString();

	
	app.exec();	
}
