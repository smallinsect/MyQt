#include "addstudent.h"
#include "ui_addstudent.h"

#include <QFile>
#include <QIODevice>
#include <QString>
#include <QMessageBox>
#include <QTextStream>

AddStudent::AddStudent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddStudent)
{
    ui->setupUi(this);
}

AddStudent::~AddStudent()
{
    delete ui;
}

void AddStudent::clearStudentInfo()
{
    ui->leName->clear();
    ui->leNum->clear();
    ui->cbxMan->setChecked(true);
    ui->cbxAge->setCurrentIndex(0);
    ui->cbxCollege->setCurrentIndex(0);
    QList<QAbstractButton*> list = ui->insGroup->buttons();
    for(int i = 0; i < list.size(); ++i){
        QAbstractButton *btn = list.at(i);
        btn->setChecked(false);
    }
}

void AddStudent::saveInfo(QString cnt)
{
    QFile pf("stu.txt");
    if(!pf.open(QIODevice::Append | QIODevice::Text)){
        QMessageBox::warning(this, "提示", "打开文件失败");
        return ;
    }
    QTextStream out(&pf);
    out << cnt;
    pf.close();
}

void AddStudent::on_btnOk_clicked()
{
    QString name = ui->leName->text();
    QString num = ui->leNum->text();

    if(name.length() < 1 || num.length() < 1){
        QMessageBox::warning(this, "提示", "姓名，学号，输入有误。");
        return ;
    }

    QString age = ui->cbxAge->currentText();
    QString college = ui->cbxCollege->currentText();

    QString sex = ui->sexGroup->checkedButton()->text();
    QList<QAbstractButton *> list = ui->insGroup->buttons();
    QString ins = "";
    for(int i = 0; i < list.size(); ++i){
        QAbstractButton *btn = list.at(i);
        if(btn->isChecked()){
            ins += btn->text()+",";
        }
    }

    QString contents = name+"\n"+num+"\n"+sex+"\n"+age+"\n"+college+"\n"+ins;
    int iret = QMessageBox::critical(this, "提示", contents, "确定", "取消");
    if(iret > 0){
        return ;
    }
    QString cnt = name+" "+num+" "+sex+" "+age+" "+college+" "+ins+"\n";
    clearStudentInfo();
    saveInfo(cnt);
}
