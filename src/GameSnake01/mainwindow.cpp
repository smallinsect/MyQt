#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timerSnake = new QTimer(this);
    connect(timerSnake, &QTimer::timeout, this, &MainWindow::moveSnake);
    dir = 1;

    qsrand(QTime().msec());
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::moveSnake()
{
    QLabel* node = snake.front();
    int x = node->x();
    int y = node->y();
    switch(dir){
    case 1: //上
        y -= UNIT_SIZE;
        break;
    case 2: //右
        x += UNIT_SIZE;
        break;
    case 3: //下
        y += UNIT_SIZE;
        break;
    case 4: //左
        x -= UNIT_SIZE;
        break;
    }

    if(isDead(x, y)){
        on_actionEnd_triggered(true);
        return ;
    }

    QLabel* newNode = new QLabel(ui->mywidget);
    newNode->resize(UNIT_SIZE, UNIT_SIZE);
    newNode->setStyleSheet(QString("background-color: rgb(211, 23, 202);"));
    newNode->move(x, y);
    newNode->show();
    snake.push_front(newNode);

    node = snake.back();
    node->hide();
    delete node;
    node = nullptr;
    snake.pop_back();

    eat();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case 87://上
        if(dir == 3)//防止倒退
            return ;
        dir = 1;
        break;
    case 68://右
        if(dir == 4)
            return ;
        dir = 2;
        break;
    case 83://下
        if(dir == 1)
            return ;
        dir = 3;
        break;
    case 65://左
        if(dir == 2)
            return ;
        dir = 4;
        break;
    }
    moveSnake();
}

void MainWindow::eat()
{
    QPoint spos = snake.front()->pos();
    QPoint fpos = food->pos();
    if(spos == fpos){
        food->hide();
        delete food;
        QLabel* node = new QLabel(ui->mywidget);
        snake.push_back(node);
        giveFood();
    }
}

void MainWindow::giveFood()
{
    int x = qrand() % (ui->mywidget->width() / UNIT_SIZE) * UNIT_SIZE;
    int y = qrand() % (ui->mywidget->height() / UNIT_SIZE) * UNIT_SIZE;
    food = new QLabel(ui->mywidget);
    food->setStyleSheet(QString("background-color: rgb(18, 200, 39);"));
    food->resize(UNIT_SIZE, UNIT_SIZE);
    food->move(x, y);
    food->show();
}

void MainWindow::on_actionStart_triggered(bool checked)
{
    QLabel* node = new QLabel(ui->mywidget);
    node->resize(UNIT_SIZE, UNIT_SIZE);
    node->setStyleSheet(QString("background-color: rgb(211, 23, 202);"));
    node->move(100, 100);
    node->show();
    snake.push_back(node);
    giveFood();

    timerSnake->start(300);
}

void MainWindow::on_actionStop_triggered(bool checked)
{
    timerSnake->stop();
}

void MainWindow::on_actionEnd_triggered(bool checked)
{
    timerSnake->stop();
    food->hide();
    delete food;
    for(int i = 0; i < snake.size(); ++i){
        QLabel* node = snake.at(i);
        node->hide();
        delete node;
    }
    snake.clear();

    QMessageBox msgBox;
    msgBox.setText("游戏结束");
    msgBox.exec();
}


void MainWindow::on_actionStart_triggered()
{

}

bool MainWindow::isDead(int x, int y)
{
    if(x < 0 || ui->mywidget->width() < x || y < 0 || ui->mywidget->height() < y){
        return true;
    }
    for(int i = 0; i < snake.size(); ++i){
        QLabel* node = snake.at(i);
        if(node->x() == x && node->y() == y){
            return true;
        }
    }
    return false;
}
