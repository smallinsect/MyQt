#ifndef FORM01_H
#define FORM01_H

#include <QDebug>
#include <QWidget>
#include "Form02.h"

namespace Ui {
class Form01;
}

class Form01 : public QWidget
{
    Q_OBJECT

public:
    explicit Form01(QWidget *parent = 0);
    ~Form01();
public:
    void init();
private slots:
    void onClickToForm02(bool);

    void doForm02Request(QString);

private:
    Ui::Form01 *ui;

    Form02 *pForm02;
};

#endif // FORM01_H
