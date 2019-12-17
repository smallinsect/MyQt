#ifndef FORM02_H
#define FORM02_H

#include <QDebug>
#include <QWidget>
#include "Form03.h"

namespace Ui {
class Form02;
}

class Form02 : public QWidget
{
    Q_OBJECT

public:
    explicit Form02(QWidget *parent = 0);
    ~Form02();
public:
    void init();
private slots:
    void onClickToForm03(bool);
    void doForm03Request(QString);

    void onClickBackForm01(bool);
signals:
    void signalShowForm01(QString);

private:
    Ui::Form02 *ui;

    Form03 *pForm03;
    int count;
};

#endif // FORM02_H
