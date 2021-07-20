#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(600, 400);

    //MenuBar
    QMenuBar *bar = menuBar();
    setMenuBar(bar);
    QMenu *fileMenu = bar->addMenu("File");
    QMenu *EditMenu = bar->addMenu("Edit");
    QAction *newAction = fileMenu->addAction("New");
    fileMenu->addSeparator();
    QAction *openAction = fileMenu->addAction("Open");

    //ToolBar
    QToolBar *toolBar = new QToolBar(this);
    addToolBar(Qt::LeftToolBarArea, toolBar);
    toolBar->setFloatable(true);
    toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);
    toolBar->setMovable(false);
    toolBar->addAction(newAction);
    toolBar->addSeparator();
    toolBar->addAction(openAction);

    QPushButton *btn = new QPushButton("OPEN");
    toolBar->addWidget(btn);
    QPushButton *btn_close = new QPushButton("CLOSE");
    toolBar->addWidget(btn_close);
    connect(btn_close, &QPushButton::clicked, this, &QMainWindow::close);

    //StatusBar
    QStatusBar *staBar = statusBar();
    setStatusBar(staBar);

    QLabel *leftLabel = new QLabel("Left Status");
    QLabel *rightLabel = new QLabel("right Status");
    staBar->addWidget(leftLabel);
    staBar->addPermanentWidget(rightLabel);

    //Dock Windos
    QDockWidget *dockWnd = new QDockWidget("Float");
    dockWnd->setParent(this);
    addDockWidget(Qt::BottomDockWidgetArea, dockWnd);
    dockWnd->setAllowedAreas(Qt::BottomDockWidgetArea);

    //Center
    QTextEdit *edt = new QTextEdit(this);
    setCentralWidget(edt);
}

MainWindow::~MainWindow()
{
}

