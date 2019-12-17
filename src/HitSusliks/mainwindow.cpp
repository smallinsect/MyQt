#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "handler.h"
#include <QMessageBox>
#include <QSound>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sc = new MyScene();
    ui->graphicsView->setScene(sc);

    connect(ui->btnStart, SIGNAL(clicked()), sc, SLOT(startGame()));
    connect(ui->btnPause, SIGNAL(clicked()), sc, SLOT(pauseGame()));
    connect(ui->btnStop, SIGNAL(clicked()), sc, SLOT(stopGame()));

    score = 0;
    Handler *handler = Handler::getInstance();
    connect(handler, SIGNAL(beatMouse()), this, SLOT(updateScore()));

    QSound *sound = new QSound(":/music/musics/bgmusic.wav", this);
    sound->setLoops(-1);//设置循环次数
    sound->play();
//    QMediaPlayer *player = new QMediaPlayer();
//    connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
//    player->setMedia(QUrl::fromLocalFile(":/music/musics/backmusic.mp3"));

//    player->setVolume(30);
//    player->play();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    int ret = QMessageBox::question(this, "确认", "你真的要关闭吗？", "是", "否");
    if(ret == 1){
        event->ignore();
    }
}

void MainWindow::updateScore()
{
    score += 10;
    ui->lcdNumber->display(score);
}
