#ifndef THREADDLG_H
#define THREADDLG_H

#include <QDialog>
#include <QPushButton>
#include "workthread.h"
#include <QLabel>
#include <QLineEdit>

class ThreadDlg : public QDialog
{
    Q_OBJECT

public:
    ThreadDlg(QWidget *parent = 0);
    ~ThreadDlg();
public slots:
    void slotStart();
    void slotStop();

private:
    QPushButton *startBtn;
    QPushButton *stopBtn;
    QPushButton *quitBtn;

    QLabel *threadNumLabel;
    QLineEdit *threadNumLineEdit;
    int thread_num;

    WorkThread **workThread;
};

#endif // THREADDLG_H
