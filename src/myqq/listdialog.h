#ifndef LISTDIALOG_H
#define LISTDIALOG_H

//使用vs编译中文乱码
#ifdef WIN32
#pragma execution_character_set("utf-8")
#endif

#include <QVector>
#include <QDebug>
#include <QPixmap>
#include <QWidget>
#include <QPushButton>
#include <QToolButton>
#include <QMessageBox>

#include "chat.h"

namespace Ui {
class ListDialog;
}

class ListDialog : public QWidget
{
    Q_OBJECT

public:
    explicit ListDialog(QWidget *parent = nullptr);
    ~ListDialog();

private:
    Ui::ListDialog *ui;

    QVector<QToolButton *> vToolBtn;
    QVector<int> vIsShow;
};

#endif // LISTDIALOG_H
