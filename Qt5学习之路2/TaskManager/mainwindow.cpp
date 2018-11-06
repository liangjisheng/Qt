#include "mainwindow.h"
#include <QDebug>
#include "windows.h"  //1 顺序不可颠倒
#include "tlhelp32.h"  //2
#include <QPushButton>
#include <QMessageBox>
#include <QProcess>
#include <QHeaderView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    tableView = new QTableView(this);
    tableView->setGeometry(QRect(10,10,340,430));

    QPushButton *button = new QPushButton(this);
    button->setGeometry(QRect(260,450,80,25));
    button->setText("结束进程");
    connect(button,SIGNAL(clicked()),this,SLOT(deletePro()));

    model = new QStandardItemModel();
    model->setHorizontalHeaderItem(0, new QStandardItem("进程名"));
    model->setHorizontalHeaderItem(1, new QStandardItem("PID"));

    // 获取系统快照句柄，可以获取进程、线程、模块、进程使用的堆的句柄
    HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (FALSE == hProcessSnap)
    {
        qDebug() << "调用失败";
        return ;
    }

    PROCESSENTRY32 pe32;
    pe32.dwSize = sizeof(PROCESSENTRY32);
    BOOL bRet = Process32First(hProcessSnap, &pe32);
    int i = 0;
    while (bRet)
    {
        i++;
        if (i > 1)
        {
            // 进程名
            QString pName = QString::fromWCharArray(pe32.szExeFile);
            // 追加数据模型第一列
            model->setItem(i-2, 0, new QStandardItem(pName));
            QString pid = QString::number(pe32.th32ProcessID);
            model->setItem(i-2, 1, new QStandardItem(pid));
            bRet = Process32Next(hProcessSnap, &pe32);
        }
    }

    ::CloseHandle(hProcessSnap);

    tableView->setModel(model);
    tableView->setColumnWidth(0,190);
    tableView->setColumnWidth(1,130);
    //选取整行
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    //不可修改
    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //行单击事件
    connect(tableView,SIGNAL(clicked(QModelIndex)),SLOT(sendContent(QModelIndex)));
    //纵向头隐藏
    tableView->verticalHeader()->setVisible(false);
    //关闭滚动条
    //tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //隔行变色
    tableView->setAlternatingRowColors(true);
}

// 点击行事件
void MainWindow::sendContent(QModelIndex)
{
    int index = tableView->currentIndex().row();
    cPid = model->data(model->index(index, 1)).toString();
}

// 点击结束进程
void MainWindow::deletePro()
{
    if ("" == cPid)
        QMessageBox::warning(this, "warning", tr("请选择要结束的进程!"));
    else
    {
        QProcess process(0);
        QString dos = "Taskkill";
        QStringList list;
        list.append("/pid");
        list.append(cPid);

        process.start(dos, list);
        QMessageBox::warning(this, "warning", tr("成功结束"));
    }
}

MainWindow::~MainWindow()
{

}
