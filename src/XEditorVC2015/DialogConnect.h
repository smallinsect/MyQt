#ifndef DIALOGCONNECT_H
#define DIALOGCONNECT_H

#include "PrefixInclude.h"

#define INIFILE "./config.ini"
#define HOST "XEditor/Host"
#define PORT "XEditor/Port"

namespace Ui {
class DialogConnect;
}

class DialogConnect : public QDialog
{
    Q_OBJECT
protected:

public:
    explicit DialogConnect(QWidget *parent = 0);
    ~DialogConnect();

    QString m_sAddress;//IP地址
    uint m_nPort;//端口

    void loadConfig();
    void saveConfig();
private:
    void init();
private slots:
    void onClickConnect(bool);
    void onClickCancel(bool);

signals:
    void signalDialogBackData(QString,QString);

private:
    Ui::DialogConnect *ui;
    QSettings *configInit;
};

#endif // DIALOGCONNECT_H
