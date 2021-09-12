#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableView>
//#include <QStandardItem>
#include <QStandardItemModel>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void getCurrenItemData();
    void toggleSelection();

    void updateSelection(const QItemSelection &selected, const QItemSelection &deselected);
    void changeCurrent(const QModelIndex &current, const QModelIndex &pre);
private:
    QTableView *tableView;
    QTableView *tableView2;
};
#endif // MAINWINDOW_H
