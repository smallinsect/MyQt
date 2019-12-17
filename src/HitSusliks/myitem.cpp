#include "myitem.h"

#include <QPixmap>
#include <QDebug>

#include "handler.h"

MyItem::MyItem()
{
    setPixmap(QPixmap(":/bg/imgs/background.png"));
    mouse = false;
    start = false;
    setCursor(QCursor(QPixmap(":/bg/imgs/chuizi.png")));
    sound = new QSound(":/music/musics/backmusic.wav");
}

void MyItem::setPic(QString path)
{
    setPixmap(QPixmap(path));
}

void MyItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    setCursor(QCursor(QPixmap(":/bg/imgs/chuizichui.png")));
    if(isStart()){
        Handler *hand = Handler::getInstance();
        if(isMouse()){
            hand->addScore();
            setPixmap(QPixmap(":/bg/imgs/dishuda.png"));
            mouse = false;
            sound->play();//播放老鼠被击中的声音
        }
    }
}
//鼠标抬起时间
void MyItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    setCursor(QCursor(QPixmap(":/bg/imgs/chuizi.png")));
}

void MyItem::setMouse(bool mouse)
{
    this->mouse = mouse;
}

bool MyItem::isMouse()
{
    return mouse;
}

void MyItem::setStart(bool start)
{
    this->start = start;
}

bool MyItem::isStart()
{
    return start;
}
