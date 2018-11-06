#include "mainwindow.h"
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QStringList>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // 查询数据库的驱动
    QStringList drivers = QSqlDatabase::drivers();
    foreach (QString driver , drivers)
        qDebug() << "\r" << driver;
}

MainWindow::~MainWindow()
{

}
