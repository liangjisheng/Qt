#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    label = new QLabel(this);
    label->setText("选择日期：");
    label->setGeometry(QRect(50,50,100,25));

    lineEdit = new QLineEdit(this);
    lineEdit->setGeometry(QRect(110,50,150,22));
    connect(lineEdit,SIGNAL(cursorPositionChanged(int,int)),this,SLOT(showTime()));

    calendarWidget = new QCalendarWidget(this);
    calendarWidget->setGeometry(20,75,350,180);
    //隐藏时间控件
    calendarWidget->setHidden(true);
    connect(calendarWidget,SIGNAL(clicked(QDate)),this,SLOT(setData()));
}

void MainWindow::showTime()
{
    calendarWidget->setHidden(false);
}

void MainWindow::setData()
{
    QDate date =calendarWidget->selectedDate();
    QString str = date.toString(tr("yyyy-MM-dd"));
    lineEdit->setText(str);
    calendarWidget->setHidden(true);
}

MainWindow::~MainWindow()
{

}
