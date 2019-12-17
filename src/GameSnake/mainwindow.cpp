#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dir = 1;
//    connect(ui->actionstart, SIGNAL(triggered(bool)),
//            this, SLOT(doTriggered(bool)));
    connect(ui->menuBar, SIGNAL(triggered(QAction*)),
            this, SLOT(Triggering(QAction*)));
    //:/image/snakebackground.png
//    QPixmap *pixmap = new QPixmap();
//    pixmap->load(":/image/snakenode.png");
//    snake = new SnakeDialog(this);
//    SnakeNode *s = new SnakeNode(this);
//    s->show();
    x = y = 100;
    label = new QLabel(this);
    label->setText("haha");
    label->resize(UNIT_SIZE, UNIT_SIZE);
    label->move(x, y);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete snake;
    delete label;
}

void MainWindow::keyPressEvent(QKeyEvent *key)
{
    switch(key->key()){
    case 87:
        dir = 1;
        break;
    case 65:
        dir = 2;
        break;
    case 83:
        dir = 3;
        break;
    case 68:
        dir = 4;
        break;
    }
    moveSnake();
    //    snake->move(dir, this);
}

void MainWindow::moveSnake()
{
    switch(dir){
    case 1:
        y -= UNIT_SIZE;
        break;
    case 2:
        x -= UNIT_SIZE;
        break;
    case 3:
        y += UNIT_SIZE;
        break;
    case 4:
        x += UNIT_SIZE;
        break;
    }
    label->move(x, y);
}

void MainWindow::doTriggered(bool)
{
    qDebug() << "jjd";
//    int ms = 300;

//    while(1){
//        snake->move(dir, this);
//        QTest::qWait(ms);
//    }
}

void MainWindow::Triggering(QAction *ac)
{
    qDebug() << "dafdsad";
    if(ui->actionstart == ac){
//        while(true){
//            moveSnake();
//            QTest::qWait(300);
//        }
//        qDebug() << "111111111";
//        snake = new SnakeDialog(this);
//        qDebug() << "22222222";
//        while(true){
//            snake->move(dir, this);
//            QTest::qWait(ms);
//            QThread::sleep(300);
//        }
    }
}
