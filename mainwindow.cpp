#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMediaMetaData>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //QString radioString("https://air2.radiorecord.ru:9002/rr_128");
    mPlayer = new QMediaPlayer();
    //mPlayer->setMedia(QMediaContent(QUrl(radioString)));
    //mPlayer->setMedia(QUrl("https://air2.radiorecord.ru:9002/rr_128"));
    mPlayer->setMedia(QUrl("https://air2.radiorecord.ru:9003/rr_320"));
    mPlayer->setVolume(50);
    mPlayer->play();
    QString albumTitle = mPlayer->metaData(QMediaMetaData::AlbumTitle).toString();
    qDebug() << mPlayer->metaData(QMediaMetaData::Title);
    qDebug() << albumTitle;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    qDebug() << "state changed" << mPlayer->mediaStatus();
}

void MainWindow::on_pushButton_3_clicked()
{
    mPlayer->play();
    qDebug() << mPlayer->metaData(QMediaMetaData::Title);
    if(mPlayer->isMetaDataAvailable()){
        qDebug() << "ura";
    }
    else qDebug() << "no metadata";
}

void MainWindow::on_pushButton_2_clicked()
{
    mPlayer->pause();
}
