#ifndef XTHREAD_H
#define XTHREAD_H

#include <QThread>

class XThread : public QThread
{
    Q_OBJECT

public:
    void run(){
        for(int i = 0; i < 1000; ++i){
            Move(i, i);
            msleep(100);
        }
    }
    XThread();
    ~XThread();
signals:
    void Move(int x, int y);
};

#endif // XTHREAD_H
