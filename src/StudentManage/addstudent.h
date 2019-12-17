#ifndef ADDSTUDENT_H
#define ADDSTUDENT_H

//使用vs编译中文乱码
#ifdef WIN32
#pragma execution_character_set("utf-8")
#endif

#include <QWidget>

namespace Ui {
class AddStudent;
}

class AddStudent : public QWidget
{
    Q_OBJECT

public:
    explicit AddStudent(QWidget *parent = nullptr);
    ~AddStudent();

    void clearStudentInfo();
    void saveInfo(QString cnt);

private slots:
    void on_btnOk_clicked();

private:
    Ui::AddStudent *ui;
};

#endif // ADDSTUDENT_H
