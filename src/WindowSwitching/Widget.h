#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include "Form01.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
public:
    void init();
private slots:
    void onClick(bool);

private:
    Ui::Widget *ui;

    Form01 *pForm01;
};

#endif // WIDGET_H
