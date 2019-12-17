#ifndef FORM03_H
#define FORM03_H

#include <QDebug>
#include <QWidget>


namespace Ui {
class Form03;
}

class Form03 : public QWidget
{
    Q_OBJECT

public:
    explicit Form03(QWidget *parent = 0);
    ~Form03();
public:
    void init();
private slots:
    void onClickBackForm02(bool);
signals:
    void signalShowForm02(QString);
private:
    Ui::Form03 *ui;

    int count;
};

#endif // FORM03_H
