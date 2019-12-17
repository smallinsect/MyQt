#ifndef XWIDGET_H
#define XWIDGET_H

#include <QWidget>

class XWidget : public QWidget
{
    Q_OBJECT

public:
    explicit XWidget(QWidget *parent = nullptr);

signals:

public slots:
    void runMove(int x, int y);
};

#endif // XWIDGET_H
