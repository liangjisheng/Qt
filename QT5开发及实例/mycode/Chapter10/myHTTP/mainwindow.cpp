#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtNetwork>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // QNetworkAccessManager用来发送网络请求和接收应答
    manager = new QNetworkAccessManager(this);
    // 每当网络应答结束后，都会发送finished信号
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(replyFinished(QNetworkReply*)));
    // get()函数来发送网络请求， 返回一个QNetworkReply对象
    //manager->get(QNetworkRequest(QUrl("http://www.baidu.com")));

    ui->progressBar->hide();

    // 下面三行代码将窗口上所有的控件设置到主窗口中心
    QWidget *widget = new QWidget(this);
    widget->setLayout(ui->verticalLayout_2);
    this->setCentralWidget(widget);
}

void MainWindow::replyFinished(QNetworkReply *reply)
{
    // readAll()读取所有应答数据
    QString all = reply->readAll();
    ui->textBrowser->setText(all);
    reply->deleteLater();
}

void MainWindow::startRequest(QUrl url)
{
    reply = manager->get(QNetworkRequest(url));
    connect(reply,SIGNAL(readyRead()),this,SLOT(httpReadyRead()));
    connect(reply,SIGNAL(downloadProgress(qint64,qint64)),this,SLOT(updateDataReadProgress(qint64,qint64)));
    connect(reply,SIGNAL(finished()),this,SLOT(httpFinished()));
}

void MainWindow::httpReadyRead()
{
    if(file)
        file->write(reply->readAll());
}

void MainWindow::updateDataReadProgress(qint64 bytesRead, qint64 totalBytes)
{
    ui->progressBar->setMaximum(totalBytes);
    ui->progressBar->setValue(bytesRead);
}

void MainWindow::httpFinished()
{
    ui->progressBar->hide();
    file->flush();
    file->close();
    reply->deleteLater();
    reply = 0;
    delete file;
    file = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_downloadBtn_clicked()
{
    url = ui->urlLineEdit->text();
    QFileInfo info(url.path());
    QString fileName(info.fileName());
    file = new QFile(fileName);
    if(!file->open(QIODevice::WriteOnly))
    {
        qDebug()<<"file open error";
        delete file;
        file = 0;
        return;
    }
    startRequest(url);
    ui->progressBar->setValue(0);
    ui->progressBar->show();
}
