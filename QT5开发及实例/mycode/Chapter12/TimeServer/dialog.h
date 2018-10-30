#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>

class TimeServer;

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
public slots:
    void slotShow();        // 显示请求次数
private:
    QLabel *Label1;         // 显示监听的端口
    QLabel *Label2;         // 显示请求次数
    QPushButton *quitBtn;   // 退出

    TimeServer *timeServer;
    int count;              // 请求计数
};

#endif // DIALOG_H
