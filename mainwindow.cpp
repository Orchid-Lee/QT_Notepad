#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QToolBar>
#include <QLabel>
#include <QDockWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //标题
    this->setWindowTitle("Qt Creator");
    //创建菜单栏
    // QMenuBar *menuBar = new QMenuBar(this);
    QMenuBar *menuBar = this->menuBar();
    this->setMenuBar(menuBar);
    //创建菜单
    QMenu *file = new QMenu("File");
    QMenu *edit = new QMenu("Edit");
    QMenu *build = new QMenu("Build");
    QMenu *debug = new QMenu("Debug");
    //添加菜单到菜单栏
    menuBar->addMenu(file);
    menuBar->addMenu(edit);
    menuBar->addMenu(build);
    menuBar->addMenu(debug);
    //创建菜单项
    QAction *newProject = new QAction("New Project");
    QAction *newFile = new QAction("New File");
    QAction *openFileOrProject = new QAction("Open File Or Project");
    QAction *openFileWith = new QAction("Open File With");
    QAction *openFromDevice = new QAction("Open From Device");
    QAction *close = new QAction("Close");

    file->addAction(newProject);
    file->addAction(newFile);
    file->addAction(openFileOrProject);
    file->addAction(openFileWith);
    file->addAction(openFromDevice);
    file->addAction(close);

    QAction *undo = new QAction("Undo");
    QAction *redo = new QAction("Redo");
    QAction *cut = new QAction("Cut");
    QAction *copy = new QAction("Copy");
    edit->addAction(undo);
    edit->addAction(redo);
    edit->addAction(cut);
    edit->addAction(copy);

    connect(close, &QAction::triggered, this, &QMainWindow::close);

    //工具栏
    QToolBar *toolBar = new QToolBar(this);
    QAction *welcome = new QAction("Welcome", this);
    QAction *editTool= new QAction("Edit", this);
    QAction *design = new QAction("Design", this);
    this->addToolBar(Qt::LeftToolBarArea, toolBar);
    toolBar->addAction(welcome);
    toolBar->addAction(editTool);
    toolBar->addAction(design);

    //工具栏属性
    toolBar->setMovable(true);
    toolBar->setAllowedAreas(Qt::LeftToolBarArea);
    toolBar->setFloatable(true);

    //状态栏
    // QStatusBar *statusBar = new QStatusBar(this);
    QStatusBar *statusBar = this->statusBar();
    //增加临时信息
    // statusBar->showMessage("欢迎使用Qt Creator", 3000);
    //增加正式信息(左侧)
    QLabel *label = new QLabel("打开文件", this);
    statusBar->addWidget(label);

    //增加永久信息
    QLabel *websiteUrl = new QLabel("http://www.google.com", this);
    statusBar->addPermanentWidget(websiteUrl);
    this->setStatusBar(statusBar);

    //铆接部件(浮动窗口)
    QDockWidget *dockWidget = new QDockWidget("测算工具", this);

    this->addDockWidget(Qt::TopDockWidgetArea, dockWidget);

}

MainWindow::~MainWindow()
{
    delete ui;
}
