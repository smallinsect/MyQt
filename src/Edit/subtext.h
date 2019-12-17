#ifndef SUBTEXT_H
#define SUBTEXT_H

//使用vs编译中文乱码
#ifdef WIN32
#pragma execution_character_set("utf-8")
#endif

#include <QString>
#include <QWidget>
#include <QTextEdit>
#include <QFileDialog>
#include <QFile>
#include <QIODevice>
#include <QMessageBox>
#include <QTextStream>

class SubText : public QTextEdit
{
    Q_OBJECT
public:
    explicit SubText(QWidget *parent = nullptr);

    void setCodecName(const QString &codecName);//设置文件编码

    void newFile();//新建文件
    void openFile();//打开文件
signals:

public slots:

private slots:
    void onContentsChanged();

private:
    QString fileName;//文件名
    QFile *file;
    QString codecName;//编码格式
};

#endif // SUBTEXT_H
