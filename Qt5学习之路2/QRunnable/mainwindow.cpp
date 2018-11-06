#include "mainwindow.h"
#include <QProgressBar>
#include <QThreadPool>
#include <runnable.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    progressBar = new QProgressBar(this);
    progressBar->setGeometry(QRect(50, 50, 200, 16));
    progressBar->setValue(0);
    progressBar->setRange(0, 100000 - 1);

    progressBar2 = new QProgressBar(this);
    progressBar2->setGeometry(QRect(50, 100, 200, 16));
    progressBar2->setValue(0);
    progressBar2->setRange(0, 100000 - 1);

    startButton = new QPushButton(this);
    startButton->setGeometry(QRect(260,45,80,25));
    startButton->setText("执行");
    connect(startButton,SIGNAL(clicked()),this,SLOT(startFun()));
}

void MainWindow::startFun()
{
    Runnable *hInst = new Runnable(progressBar);
    hInst = new Runnable(progressBar2);
    QThreadPool::globalInstance()->start(hInst);
}

MainWindow::~MainWindow()
{

}
