#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QFrame>
#include "inputdlg.h"
#include "msgboxdlg.h"
#include "customdlg.h"

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
private:
    // 标准文件对话框
    QPushButton *fileBtn;
    QLineEdit *fileLineEdit;
    QGridLayout *mainLayout;

    // 标准颜色对话框
    QPushButton *colorBtn;
    QFrame *colorFrame;

    // 标准字体对话框
    QPushButton *fontBtn;
    QLineEdit *fontLineEdit;

    // 标准输入对话框实例
    QPushButton *inputBtn;
    InputDlg *inputDlg;

    // 消息对话库
    QPushButton *MsgBtn;
    MsgBoxDlg *msgDlg;

    // 自定义消息对话库
    QPushButton *CustomBtn;
    QLabel *label;

private slots:
    void showFile();
    void showColor();
    void showFont();
    void showInputDlg();
    void showMsgDlg();
    void showCustomDlg();
};

#endif // DIALOG_H
