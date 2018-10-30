#include "mainwindow.h"
#include <QtDebug>
#include <QFile>
#include <QDataStream>
#include <QDate>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    fileFun();
}

void MainWindow::fileFun()
{
    QFile file("binary.dat");
    file.open(QIODevice::WriteOnly | QIODevice::Truncate);
    QDataStream out(&file);
    out << QString(tr("梁基圣"));
    out << QDate::fromString("2018/10/24", "yyyy/MM/dd");
    out << (qint32)24;
    file.close();

    file.setFileName("binary.dat");
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "error";
        return;
    }
    QDataStream in(&file);
    QString name;
    QDate date;
    qint32 age;
    in >> name >> date >> age;
    qDebug() << name << date << age;
    file.close();
}

MainWindow::~MainWindow()
{

}
