#ifndef QUERYSTUDENT_H
#define QUERYSTUDENT_H

//使用vs编译中文乱码
#ifdef WIN32
#pragma execution_character_set("utf-8")
#endif


#include <QList>
#include <QWidget>
#include <QString>
#include <QStringList>
#include <QStandardItem>
#include <QStandardItemModel>

namespace Ui {
class QueryStudent;
}

class QueryStudent : public QWidget
{
    Q_OBJECT

public:
    explicit QueryStudent(QWidget *parent = nullptr);
    ~QueryStudent();

    int readStudent();
    void modelAddStu(int row, QStringList stu);


private slots:
    void on_btnSearch_clicked();

private:
    Ui::QueryStudent *ui;

    QList<QString> list;
    QStandardItemModel *model;
};

#endif // QUERYSTUDENT_H
