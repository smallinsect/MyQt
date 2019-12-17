#include "listdialog.h"
#include "ui_listdialog.h"

ListDialog::ListDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ListDialog)
{
    ui->setupUi(this);

    QList<QString> nameList;
    nameList << "虹猫" << "蓝兔" << "逗逗" << "莎莉" << "大奔" << "跳跳" << "达达";

    QStringList iconNameList;
    iconNameList << ":/images/hongmao.png" << ":/images/lantu.png"
                 << ":/images/doudou.png" << ":/images/shali.png"
                 << ":/images/daben.png" << ":/images/tiaotiao.png"
                 << ":/images/dada.png";
    for(int i = 0; i < 7; ++i){
        QToolButton *btn = new QToolButton();
        //设置文本
        btn->setText(nameList.at(i));
        //设置图标
        btn->setIcon(QPixmap(iconNameList.at(i)));
        //设置图标大小
        btn->setIconSize(QPixmap(iconNameList.at(i)).size());
        //设置透明
        btn->setAutoRaise(true);
        //设置文字和图片同时存在
        btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        ui->vLayout->addWidget(btn);
        vToolBtn.push_back(btn);
        vIsShow.push_back(0);
    }

    //对7个按钮 进行添加信号槽
    for(int i = 0; i < vToolBtn.size(); ++i){
        connect(vToolBtn[i], &QToolButton::clicked, [=](){
            if(vIsShow[i]){
                QString str = QString("%1用户已经打开").arg(vToolBtn[i]->text());
                QMessageBox::warning(this, "警告", str);
                return ;
            }
            vIsShow[i] = 1;
            Chat *chat = new Chat(nullptr, vToolBtn[i]->text());
            //设置标题
            chat->setWindowTitle(vToolBtn[i]->text());
            //设置图标
            chat->setWindowIcon(vToolBtn[i]->icon());
            //显示
            chat->show();
            //关闭聊天窗口
            connect(chat, &Chat::closeChat, [=](){
                vIsShow[i] = 0;
            });
        });
    }
}

ListDialog::~ListDialog()
{
    delete ui;
}
