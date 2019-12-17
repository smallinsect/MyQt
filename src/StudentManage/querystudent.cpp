#include "querystudent.h"
#include "ui_querystudent.h"

#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QMessageBox>

QueryStudent::QueryStudent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QueryStudent)
{
    ui->setupUi(this);

    model = new QStandardItemModel();

    model->setHorizontalHeaderItem(0, new QStandardItem("姓名"));
    model->setHorizontalHeaderItem(1, new QStandardItem("学号"));
    model->setHorizontalHeaderItem(2, new QStandardItem("性别"));
    model->setHorizontalHeaderItem(3, new QStandardItem("年龄"));
    model->setHorizontalHeaderItem(4, new QStandardItem("院系"));
    model->setHorizontalHeaderItem(5, new QStandardItem("兴趣"));

    ui->tvStudent->setModel(model);
    if(readStudent() == -1){
        QMessageBox::warning(this, "提示", "打开文件失败");
    }


}

QueryStudent::~QueryStudent()
{
    delete ui;
}

int QueryStudent::readStudent()
{
    QFile pf("stu.txt");
    if(!pf.open(QIODevice::ReadOnly | QFile::Truncate)){
        return -1;
    }
    QTextStream in(&pf);

    int row = 0;
    while(!in.atEnd()){
        QString line = in.readLine();
        QStringList sl = line.split(" ");
        modelAddStu(row++, sl);
        list.append(line);
    }



    pf.close();
    return 0;
}

void QueryStudent::modelAddStu(int row, QStringList stu)
{
    for(int i = 0; i < stu.size(); ++i){
        model->setItem(row, i, new QStandardItem(stu.at(i)));
    }
}

void QueryStudent::on_btnSearch_clicked()
{

}
