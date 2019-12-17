#include "ContentForm.h"
#include "ui_ContentForm.h"

ContentForm::ContentForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ContentForm)
{
    ui->setupUi(this);
    init();
}

ContentForm::~ContentForm()
{
    delete ui;
}

void ContentForm::setDatas(const QStringList &strList)
{
    ui->treeWidget->setHeaderLabels(QStringList()<<"名称");

    QTreeWidgetItem *itemJ = new QTreeWidgetItem(QStringList()<<"机车族");
    QTreeWidgetItem *itemM = new QTreeWidgetItem(QStringList()<<"猛兽族");

    ui->treeWidget->addTopLevelItem(itemJ);
    ui->treeWidget->addTopLevelItem(itemM);

    QTreeWidgetItem *J1 = new QTreeWidgetItem(QStringList()<<"雷霆半月斩");
    QTreeWidgetItem *J2 = new QTreeWidgetItem(QStringList()<<"惊天浪涛杀");
    QTreeWidgetItem *J3 = new QTreeWidgetItem(QStringList()<<"泰山陨石坠");
    QTreeWidgetItem *J4 = new QTreeWidgetItem(QStringList()<<"绝地流星锤");
    QTreeWidgetItem *J5 = new QTreeWidgetItem(QStringList()<<"闪电旋风劈");
    QTreeWidgetItem *J6 = new QTreeWidgetItem(QStringList()<<"破空寒冰砍");
    QTreeWidgetItem *M1 = new QTreeWidgetItem(QStringList()<<"极光神风爪");
    QTreeWidgetItem *M2 = new QTreeWidgetItem(QStringList()<<"暴风星云裂");
    QTreeWidgetItem *M3 = new QTreeWidgetItem(QStringList()<<"狂雷金刚拳");
    QTreeWidgetItem *M4 = new QTreeWidgetItem(QStringList()<<"开山金刚拳");
    QTreeWidgetItem *M5 = new QTreeWidgetItem(QStringList()<<"龙皇异次元");
    QTreeWidgetItem *M6 = new QTreeWidgetItem(QStringList()<<"龙云震天翅");

    itemJ->addChild(J1);
    itemJ->addChild(J2);
    itemJ->addChild(J3);
    itemJ->addChild(J4);
    itemJ->addChild(J5);
    itemJ->addChild(J6);

    itemM->addChild(M1);
    itemM->addChild(M2);
    itemM->addChild(M3);
    itemM->addChild(M4);
    itemM->addChild(M5);
    itemM->addChild(M6);

    //设置3列
    ui->tableWidgetContent->setColumnCount(2);

    //设置表头
    ui->tableWidgetContent->setHorizontalHeaderLabels(QStringList()<<"呵呵"<<"哈哈" );

    //设置5行
    ui->tableWidgetContent->setRowCount(5);

    QList<QString> lname;
    lname << "剑皇" << "剑帝" << "剑神" << "剑魔" << "剑影";
    QStringList lsex;
    lsex << "天帝" << "念帝" << "天使" << "魔神" << "弹药";
    for(int i = 0; i < 5; ++i){
        ui->tableWidgetContent->setItem(i, 0, new QTableWidgetItem(lname.at(i)));
        ui->tableWidgetContent->setItem(i, 1, new QTableWidgetItem(lsex[i]));
    }

}

void ContentForm::onItemClickedTree(QTreeWidgetItem *item, int column)
{
    qDebug() <<item->text(0)<<" "<< column;
    int row = ui->tableWidgetContent->rowCount();
    ui->tableWidgetContent->insertRow(row);
    ui->tableWidgetContent->setItem(row,0, new QTableWidgetItem(item->text(column)));
}

void ContentForm::init()
{
    connect(ui->treeWidget, SIGNAL(itemClicked(QTreeWidgetItem*,int)),
            this, SLOT(onItemClickedTree(QTreeWidgetItem*,int)));
}
