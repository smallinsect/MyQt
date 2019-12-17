#include "MainWindow.h"
#include "ui_MainWindow.h"

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
    delete pDialogConnect;
}
//退出
void MainWindow::onTriggeredExit(bool)
{
//    SubText *subText = new SubText();
//    ui->mdiArea->addSubWindow(subText);
//    subText->show();
}
//连接
void MainWindow::onTriggeredConnect(bool)
{
    pDialogConnect->show();
    pDialogConnect->loadConfig();

}
//断开
void MainWindow::onTriggeredDiscon(bool)
{
    qDebug() << "discon";


}
//复位服务
void MainWindow::onTriggeredResetService(bool)
{
    qDebug() << "reset service";

}
//复位设备
void MainWindow::onTriggeredResetEquip(bool)
{
//    ContentForm *cForm = new ContentForm();
//    ui->mdiArea->addSubWindow(cForm);
//    cForm->show();
//    cForm->setDatas(QStringList()<<"hehe"<<"haha");

}
//新增
void MainWindow::onTreggeredAdd(bool)
{
    qDebug()<<"新增";

}
//修改
void MainWindow::onTreggeredModify(bool)
{
    qDebug()<<"修改";

}
//剪切
void MainWindow::onTreggeredCut(bool)
{
    qDebug()<<"剪切";
}
//复制
void MainWindow::onTreggeredCopy(bool)
{
    qDebug()<<"复制";
}
//粘贴
void MainWindow::onTreggeredPaste(bool)
{
    qDebug()<<"粘贴";
}
//状态栏
void MainWindow::onTreggeredStatusBar(bool)
{
    qDebug()<<"状态栏";
}
//标准
void MainWindow::onTreggeredStandard(bool)
{
    qDebug()<<"标准";
}
//设备类别列表
void MainWindow::onTreggeredEquipCatList(bool)
{
    qDebug()<<"设备类别列表";
}
//属性
void MainWindow::onTreggeredAttribute(bool)
{
    qDebug()<<"属性";
}
//自定义...
void MainWindow::onTreggeredCustom(bool)
{
    qDebug()<<"自定义";
}
//关于XEditor
void MainWindow::onTreggeredAbout(bool)
{
    qDebug()<<"关于XEditor";
}

void MainWindow::doSignalDialogBackData(QString strIp, QString strPort)
{
    qDebug() << strIp << " " << strPort;
}

void MainWindow::init()
{
    pDialogConnect = new DialogConnect(this);
    connect(pDialogConnect, SIGNAL(signalDialogBackData(QString,QString)),
            this, SLOT(doSignalDialogBackData(QString,QString)));

    //菜单
    connect(ui->action_file_exit, SIGNAL(triggered(bool)),
            this, SLOT(onTriggeredExit(bool)));//退出

    connect(ui->action_operation_connect, SIGNAL(triggered(bool)),
            this, SLOT(onTriggeredConnect(bool)));//连接
    connect(ui->action_operation_discon, SIGNAL(triggered(bool)),
            this, SLOT(onTriggeredDiscon(bool)));//断开
    connect(ui->action_operation_resetService, SIGNAL(triggered(bool)),
            this, SLOT(onTriggeredResetService(bool)));//复位服务
    connect(ui->action_operation_resetEquip, SIGNAL(triggered(bool)),
            this, SLOT(onTriggeredResetEquip(bool)));//复位设备

    connect(ui->action_editor_add, SIGNAL(triggered(bool)),
            this, SLOT(onTreggeredAdd(bool)));//增加
    connect(ui->action_editor_modify, SIGNAL(triggered(bool)),
            this, SLOT(onTreggeredModify(bool)));//修改
    connect(ui->action_editor_cut, SIGNAL(triggered(bool)),
            this, SLOT(onTreggeredCut(bool)));//剪切
    connect(ui->action_editor_copy, SIGNAL(triggered(bool)),
            this, SLOT(onTreggeredCopy(bool)));//复制
    connect(ui->action_editor_paste, SIGNAL(triggered(bool)),
            this, SLOT(onTreggeredPaste(bool)));//粘贴

    connect(ui->menu_view_statusBar, SIGNAL(triggered(bool)),
            this, SLOT(onTreggeredStatusBar(bool)));//状态栏
    connect(ui->menu_view_tool_standard, SIGNAL(triggered(bool)),
            this, SLOT(onTreggeredStandard(bool)));//标准
    connect(ui->menu_view_tool_equipCatList, SIGNAL(triggered(bool)),
            this, SLOT(onTreggeredEquipCatList(bool)));//设备类别列表
    connect(ui->menu_view_tool_attribute, SIGNAL(triggered(bool)),
            this, SLOT(onTreggeredAttribute(bool)));//属性
    connect(ui->menu_view_tool_custom, SIGNAL(triggered(bool)),
            this, SLOT(onTreggeredCustom(bool)));//自定义...

    connect(ui->action_help_about, SIGNAL(triggered(bool)),
            this, SLOT(onTreggeredAbout(bool)));//关于XEditor

}
