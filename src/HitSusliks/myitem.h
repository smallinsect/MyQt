#ifndef MYITEM_H
#define MYITEM_H

#include <QGraphicsPixmapItem>
#include <QString>
#include <QGraphicsSceneMouseEvent>
#include <QCursor>
#include <QSound>

class MyItem : public QGraphicsPixmapItem
{
public:
    MyItem();
    void setPic(QString path);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void setMouse(bool mouse);
    bool isMouse();
    void setStart(bool start);
    bool isStart();
private:
    bool mouse;
    bool start;
    QSound *sound;
};

#endif // MYITEM_H
