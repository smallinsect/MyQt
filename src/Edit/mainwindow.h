#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void init();

public slots:
    void onTriggeredNew(bool);//新建文件
    void onTriggeredOpen(bool);//打开文件
    void onTriggeredSave(bool);//保存文件
    void onTriggeredSaveAs(bool);//另存为
    void onTriggeredQuit(bool);//退出

    void onTriggeredRevoke(bool);//撤销
    void onTriggeredRecovery(bool);//恢复
    void onTriggeredCut(bool);//剪切
    void onTriggeredCopy(bool);//复制
    void onTriggeredPaste(bool);//粘贴
    void onTriggeredUTF8(bool);//utf-8编码
    void onTriggeredGB18030(bool);//gb18030编码

private:
    Ui::MainWindow *ui;

    QString codecName;//文件编码
};

#endif // MAINWINDOW_H
