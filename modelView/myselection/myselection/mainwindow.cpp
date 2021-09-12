#include "mainwindow.h"
#include <QToolBar>
#include <QAction>
#include <QDebug>
#include <spinboxdelegate.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QStandardItemModel *model = new QStandardItemModel(7, 4, this);
    for (int row = 0; row < 7; ++row)
        for (int col = 0; col < 4; ++col)
        {
            QStandardItem *item = new QStandardItem(QString(" %1 ").arg(row * 4 + col));
            model->setItem(row, col, item);
        }

    tableView = new QTableView;
    tableView->setModel(model);
    setCentralWidget(tableView);

    QItemSelectionModel *selectionModel = tableView->selectionModel();
    connect(selectionModel, &QItemSelectionModel::selectionChanged, this, &MainWindow::updateSelection);
    connect(selectionModel, &QItemSelectionModel::currentChanged, this, &MainWindow::changeCurrent);
    QModelIndex topLeft;
    QModelIndex bottomRight;
    topLeft = model->index(1, 1, QModelIndex());
    bottomRight = model->index(5, 2, QModelIndex());
    QItemSelection selection(topLeft, bottomRight);
    selectionModel->select(selection, QItemSelectionModel::Select);

    QToolBar *toolBar = new QToolBar;
    addToolBar(Qt::TopToolBarArea, toolBar);

    QAction *getCurrentDataAction = new QAction(tr("Current Prj"));
    getCurrentDataAction->setToolTip("Print Current Prj Data");
    toolBar->addAction(getCurrentDataAction);
    connect(getCurrentDataAction, &QAction::triggered, this, &MainWindow::getCurrenItemData);

    QAction *toggleSelectionAction = new QAction(tr("Toggle"));
    toggleSelectionAction->setToolTip("Switch all items status");
    toolBar->addAction(toggleSelectionAction);
    connect(toggleSelectionAction, &QAction::triggered, this, &MainWindow::toggleSelection);
    resize(600, 400);

    tableView2 = new QTableView;
    tableView2->setWindowTitle("tableView2");
    tableView2->setModel(model);
    tableView2->resize(600, 400);
    tableView2->setSelectionModel(selectionModel);
    tableView2->show();

    SpinBoxDelegate *delegate = new SpinBoxDelegate(this);
    tableView->setItemDelegate(delegate);
}

void MainWindow::getCurrenItemData()
{
    qDebug() << "Current prj data: "
             << tableView->selectionModel()->currentIndex().data().toString();
}
void MainWindow::toggleSelection()
{
    QModelIndex topLeft;
    QModelIndex bottomRight;
    QAbstractItemModel *model = tableView->model();
    topLeft = model->index(0, 0, QModelIndex());
    bottomRight = model->index(model->rowCount()-1, model->columnCount() - 1);
    QItemSelection selection(topLeft, bottomRight);
    QItemSelectionModel *selectionModel = tableView->selectionModel();
    selectionModel->select(selection, QItemSelectionModel::Toggle);
}

void MainWindow::updateSelection(const QItemSelection &selected, const QItemSelection &deselected)
{
    QModelIndex index;
    qDebug() << "selcectionChanged to " << selected.indexes().count();
    foreach (index, selected.indexes())
    {
        tableView->model()->setData(index, QString("%1, %2").arg(index.row()).arg(index.column()));
    }
    foreach(index, deselected.indexes())
    {
        tableView->model()->setData(index, "");
    }
}
void MainWindow::changeCurrent(const QModelIndex &current, const QModelIndex &pre)
{
    qDebug() << "changed: " << QString("From %1,%2 to %3,%4").arg(pre.row()).arg(pre.column()).arg(current.row()).arg(current.column());
}

MainWindow::~MainWindow()
{
    delete tableView;
    delete tableView2;
}

