#ifndef CONTENTFORM_H
#define CONTENTFORM_H

#include "PrefixInclude.h"

namespace Ui {
class ContentForm;
}

class ContentForm : public QWidget
{
    Q_OBJECT

public:
    explicit ContentForm(QWidget *parent = 0);
    ~ContentForm();

    void setDatas(const QStringList &);

public slots:
    void onItemClickedTree(QTreeWidgetItem *item,int column);

private:
    void init();

private:
    Ui::ContentForm *ui;
};

#endif // CONTENTFORM_H
