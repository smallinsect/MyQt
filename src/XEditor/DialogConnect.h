#ifndef DIALOGCONNECT_H
#define DIALOGCONNECT_H

#include "PrefixInclude.h"

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

    QString m_sAddress;
    ulong m_nAddress;
    uint m_nPort;
    virtual bool OnInitDialog();
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
};

#endif // DIALOGCONNECT_H
