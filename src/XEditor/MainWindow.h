#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "PrefixInclude.h"

#include "SubText.h"
#include "ContentForm.h"
#include "DialogConnect.h"

#include "ClassView.h"
#include "PropertiesWnd.h"
#include "NetArgConfig.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    //菜单 槽
    void onTriggeredExit(bool);//退出

    void onTriggeredConnect(bool);//连接
    void onTriggeredDiscon(bool);//断开
    void onTriggeredResetService(bool);//复位服务
    void onTriggeredResetEquip(bool);//复位设备

    void onTreggeredAdd(bool);//增加
    void onTreggeredModify(bool);//修改
    void onTreggeredCut(bool);//剪切
    void onTreggeredCopy(bool);//复制
    void onTreggeredPaste(bool);//粘贴

    void onTreggeredStatusBar(bool);//状态栏
    void onTreggeredStandard(bool);//标准
    void onTreggeredEquipCatList(bool);//设备类别列表
    void onTreggeredAttribute(bool);//属性
    void onTreggeredCustom(bool);//自定义...

    void onTreggeredAbout(bool);//关于XEditor

    void doSignalDialogBackData(QString, QString);

private:
    void init();
    void UpdateStatusBar();

private:
    Ui::MainWindow *ui;

    DialogConnect *pDialogConnect;

//    CMFCMenuBar       m_wndMenuBar;
//    CMFCToolBar       m_wndToolBar;
//    CMFCStatusBar     m_wndStatusBar;
    CClassView        m_wndClassView;
    CPropertiesWnd    m_wndProperties;
    CNetArgConfig     m_wndNetConfig;
};

#endif // MAINWINDOW_H
