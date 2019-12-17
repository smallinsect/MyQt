#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    QString str;
//    str = QString("dddd%2 %1 %3")
//            .arg(100000)//显示十进制
//            .arg("小昆")//显示字符串 在这里加个虫 就会出问题
//            .arg(255, 0, 16);//显示16进制
//    qDebug() << str << endl;
//    QString num = QString::number(14);//将单个整形转换为字符串
//    int inum = num.toInt();//字符串转换为整形

//    //遍历字符串
//    //字符串查到
//    QString itstr = QString("dafdafdafdass");
//    itstr.indexOf("xc");
//    itstr.indexOf("xc", itstr.indexOf("xc")+2);
//    itstr.lastIndexOf("xc");
//    itstr.indexOf(QRegExp(""));//正则表达式查找
//    //字符串阶段
//    itstr.chop(5);
//    itstr.left(itstr.indexOf("xc"));
//    itstr.right(itstr.size());
//    //字符串替换
//    itstr.replace("[name]", "xiaokung");
//    itstr.replace(QRegExp("[0-9]"), "44");
    QString str = QStringLiteral("中文测试");
    qDebug() << str << endl;
    QMessageBox::information(nullptr, "title",str);
    return a.exec();
}
