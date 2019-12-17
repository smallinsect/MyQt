#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

#include "subtext.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    codecName = "UTF-8";
    connect(ui->actionNew, SIGNAL(triggered(bool)),
            this, SLOT(onTriggeredNew(bool)));//新建文件
    connect(ui->actionOpen, SIGNAL(triggered(bool)),
            this, SLOT(onTriggeredOpen(bool)));//打开文件
    connect(ui->actionSave, SIGNAL(triggered(bool)),
            this, SLOT(onTriggeredSave(bool)));//保存文件
    connect(ui->actionSaveAs, SIGNAL(triggered(bool)),
            this, SLOT(onTriggeredSaveAs(bool)));//另存为
    connect(ui->actionQuit, SIGNAL(triggered(bool)),
            this, SLOT(onTriggeredQuit(bool)));//退出

    connect(ui->actionRevoke, SIGNAL(triggered(bool)),
            this, SLOT(onTriggeredRevoke(bool)));//撤销
    connect(ui->actionRecovery, SIGNAL(triggered(bool)),
            this, SLOT(onTriggeredRecovery(bool)));//恢复
    connect(ui->actionCut, SIGNAL(triggered(bool)),
            this, SLOT(onTriggeredCut(bool)));//剪切
    connect(ui->actionCopy, SIGNAL(triggered(bool)),
            this, SLOT(onTriggeredCopy(bool)));//复制
    connect(ui->actionPaste, SIGNAL(triggered(bool)),
            this, SLOT(onTriggeredPaste(bool)));//粘贴
    connect(ui->actionUTF_8, SIGNAL(triggered(bool)),
            this, SLOT(onTriggeredUTF8(bool)));//utf-8编码
    connect(ui->actionGB18030, SIGNAL(triggered(bool)),
            this, SLOT(onTriggeredGB18030(bool)));//gb18030编码
}

void MainWindow::onTriggeredNew(bool)
{
    SubText *subText = new SubText();
    ui->mdiArea->addSubWindow(subText);
    subText->newFile();
    subText->show();
}

void MainWindow::onTriggeredOpen(bool)
{
    SubText *subText = new SubText();
    ui->mdiArea->addSubWindow(subText);
    subText->setCodecName(codecName);
    subText->openFile();
    subText->show();
}

void MainWindow::onTriggeredSave(bool)
{

}

void MainWindow::onTriggeredSaveAs(bool)
{

}

void MainWindow::onTriggeredQuit(bool)
{

}

void MainWindow::onTriggeredRevoke(bool)
{

}

void MainWindow::onTriggeredRecovery(bool)
{

}

void MainWindow::onTriggeredCut(bool)
{

}

void MainWindow::onTriggeredCopy(bool)
{

}

void MainWindow::onTriggeredPaste(bool)
{

}

void MainWindow::onTriggeredUTF8(bool)
{
    codecName = "UTF-8";
}

void MainWindow::onTriggeredGB18030(bool)
{
    codecName = "GB18030";
}
