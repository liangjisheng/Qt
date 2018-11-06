#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableView>
#include <QStandardItemModel>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    QTableView *tableView;
    QStandardItemModel *model;
    QString cPid;       // 当前选择的进程id
private slots:
    void sendContent(QModelIndex);  // QTableView行事件
    void deletePro();
};

#endif // MAINWINDOW_H
