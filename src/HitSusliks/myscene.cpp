#include "myscene.h"

#include <QtGlobal>

MyScene::MyScene(QObject *parent) : QGraphicsScene(parent)
{
    double w, h;
    for(int i = 0; i < 16; ++i){
        item[i] = new MyItem();
        w = item[i]->boundingRect().width();//获取图片宽度
        h = item[i]->boundingRect().height();//获取图片高度
        item[i]->setPos(i/4*w, i%4*h);
        addItem(item[i]);//添加图片元素
    }

    ptimer = new QTimer();//创建定时器
    //绑定信号和槽
    connect(ptimer, SIGNAL(timeout()), this, SLOT(showMouse()));

}

void MyScene::showMouse()
{
    for(int i = 0; i < 16; ++i){
        item[i]->setPic(":/bg/imgs/background.png");
        item[i]->setMouse(false);
    }
    //随机一个数 0-15
    //1 -3
    int count = qrand()%3+1;
    for(int i = 0; i < count; ++i){
        int idx = qrand() % 16;
        item[idx]->setPic(":/bg/imgs/dishu.png");
        item[idx]->setMouse(true);
    }
}

void MyScene::startGame()
{
    for(int i = 0; i < 16; ++i){
        item[i]->setStart(true);
    }
    //500毫秒执行一次
    ptimer->start(500);//启动定时器
}

void MyScene::pauseGame()
{
    ptimer->stop();//暂停定时器
    for(int i = 0; i < 16; ++i){
        item[i]->setStart(false);
    }
}

void MyScene::stopGame()
{
    ptimer->stop();//暂停定时器
    for(int i = 0; i < 16; ++i){
        item[i]->setPic(":/bg/imgs/background.png");
        item[i]->setMouse(false);
        item[i]->setStart(false);
    }
}

