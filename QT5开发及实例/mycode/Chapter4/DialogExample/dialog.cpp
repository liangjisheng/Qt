#include "dialog.h"
#include <QString>
#include <QFileDialog>
#include <QColor>
#include <QColorDialog>
#include <QPalette>
#include <QFont>
#include <QFontDialog>
#include <QFrame>
#include <QMessageBox>
#include <QPixmap>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("各种标准对话框的实例"));

    // 标准文件对话框
    fileBtn = new QPushButton;
    fileBtn->setText(tr("文件标准对话框实例"));
    fileLineEdit = new QLineEdit;   // 显示选择的文件名

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(fileBtn, 0, 0);
    mainLayout->addWidget(fileLineEdit, 0, 1);
    connect(fileBtn, &QPushButton::clicked, this, showFile);

    // 标准颜色对话框
    colorBtn = new QPushButton;
    colorBtn->setText(tr("颜色标准对话框实例"));
    // colorFrame用于根据用户选择的不同颜色更新不同的背景
    colorFrame = new QFrame;
    colorFrame->setFrameShape(QFrame::Box);
    colorFrame->setAutoFillBackground(true);

    mainLayout->addWidget(colorBtn, 1, 0);
    mainLayout->addWidget(colorFrame, 1, 1);
    connect(colorBtn, &QPushButton::clicked, this, showColor);

    // 标准字体对话框
    fontBtn = new QPushButton;
    fontBtn->setText(tr("字体标准对话框实例"));
    fontLineEdit = new QLineEdit;
    fontLineEdit->setText(tr("Welcome!"));

    mainLayout->addWidget(fontBtn, 2, 0);
    mainLayout->addWidget(fontLineEdit, 2, 1);
    connect(fontBtn, &QPushButton::clicked, this, showFont);

    inputBtn = new QPushButton;
    inputBtn->setText(tr("标准输入对话框实例"));
    mainLayout->addWidget(inputBtn, 3, 0);
    connect(inputBtn, &QPushButton::clicked, this, showInputDlg);

    MsgBtn = new QPushButton;
    MsgBtn->setText(tr("标准消息对话框实例"));
    mainLayout->addWidget(MsgBtn, 3, 1);
    connect(MsgBtn, &QPushButton::clicked, this, showMsgDlg);

    CustomBtn = new QPushButton;
    CustomBtn->setText(tr("用户自定义消息对话库实例"));
    label = new QLabel;
    label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    mainLayout->addWidget(CustomBtn, 4, 0);
    mainLayout->addWidget(label, 4, 1);
    connect(CustomBtn, &QPushButton::clicked, this, showCustomDlg);
}

void Dialog::showFile()
{
    QString s = QFileDialog::getOpenFileName(this, "open file dialog", ".",
                                             "C++ files(*.cpp)::C files(*.c)::Head files(*.h)");
    fileLineEdit->setText(s);
}

void Dialog::showColor()
{
    // 默认为蓝色
    QColor c = QColorDialog::getColor(Qt::blue);
    if (c.isValid())
        colorFrame->setPalette(QPalette(c));
}

void Dialog::showFont()
{
    bool ok;
    QFont f = QFontDialog::getFont(&ok);
    if (ok)
        fontLineEdit->setFont(f);
}

void Dialog::showInputDlg()
{
    inputDlg = new InputDlg(this);
    inputDlg->show();
}

void Dialog::showMsgDlg()
{
    msgDlg = new MsgBoxDlg();
    msgDlg->show();
}

void Dialog::showCustomDlg()
{
    label->setText(tr("Custom Message Box"));

    QMessageBox customMsgBox;
    customMsgBox.setWindowTitle(tr("用户自定义消息框"));
    // 第一个参数为按钮显示的名字，第二个参数为按钮类型的描述
    QPushButton *yesBtn = customMsgBox.addButton(tr("Yes"), QMessageBox::ActionRole);
    QPushButton *noBtn = customMsgBox.addButton(tr("No"), QMessageBox::ActionRole);
    QPushButton *cancelBtn = customMsgBox.addButton(QMessageBox::Cancel);

    customMsgBox.setText(tr("这是一个用户自定义消息框!"));
    customMsgBox.setIconPixmap(QPixmap("Qt.png"));
    customMsgBox.exec();

    if (customMsgBox.clickedButton() == yesBtn)
        label->setText(tr("Custom Message Box/Yes"));
    if (customMsgBox.clickedButton() == noBtn)
        label->setText(tr("Custom Message Box/No"));
    if (customMsgBox.clickedButton() == cancelBtn)
        label->setText(tr("Custom Message Box/Cancel"));
}

Dialog::~Dialog()
{

}
