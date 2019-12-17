#include "xwidget.h"

XWidget::XWidget(QWidget *parent) : QWidget(parent)
{

}

void XWidget::runMove(int x, int y)
{
    move(x, y);
}
