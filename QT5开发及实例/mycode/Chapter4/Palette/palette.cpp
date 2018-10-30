#include "palette.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStringList>
#include <QString>
#include <QPixmap>
#include <QSize>
#include <QColor>
#include <QIcon>
#include <QPalette>

Palette::Palette(QWidget *parent)
    : QDialog(parent)
{
    createCtrlFrame();
    createContentFrame();
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(ctrlFrame);
    mainLayout->addWidget(contentFrame);
}

void Palette::createCtrlFrame()
{
    ctrlFrame = new QFrame;     // 颜色选择面板
    // 背景色
    windowLabel = new QLabel(tr("QPalette::Window:"));
    windowComboBox = new QComboBox;
    fillColorList(windowComboBox);
    void (QComboBox::*singal)(int) = &QComboBox::activated;
    connect(windowComboBox, singal, this, ShowWindow);

    // 前景色
    windowTextLabel = new QLabel(tr("QPalette::WindowText: "));
    windowTextComboBox = new QComboBox;
    fillColorList(windowTextComboBox);
    connect(windowTextComboBox, singal, this, ShowWindowText);

    // 按钮
    buttonLabel = new QLabel(tr("QPalette::Button:"));
    buttonComboBox = new QComboBox;
    fillColorList(buttonComboBox);
    connect(buttonComboBox, singal, this, ShowButton);

    // 按钮文本
    buttonTextLabel = new QLabel(tr("QPalette::ButtonText:"));
    buttonTextComboBox = new QComboBox;
    fillColorList(buttonTextComboBox);
    connect(buttonTextComboBox, singal, this, ShowButtonText);

    baseLabel = new QLabel(tr("QPalette::Base:"));
    baseComboBox = new QComboBox;
    fillColorList(baseComboBox);
    connect(baseComboBox, singal, this, ShowBase);

    QGridLayout *mainLayout = new QGridLayout(ctrlFrame);
    mainLayout->setSpacing(20);
    mainLayout->addWidget(windowLabel, 0, 0);
    mainLayout->addWidget(windowComboBox, 0, 1);
    mainLayout->addWidget(windowTextLabel, 1, 0);
    mainLayout->addWidget(windowTextComboBox, 1, 1);
    mainLayout->addWidget(buttonLabel, 2, 0);
    mainLayout->addWidget(buttonComboBox, 2, 1);
    mainLayout->addWidget(buttonTextLabel, 3, 0);
    mainLayout->addWidget(buttonTextComboBox, 3, 1);
    mainLayout->addWidget(baseLabel, 4, 0);
    mainLayout->addWidget(baseComboBox, 4, 1);
}

void Palette::createContentFrame()
{
    contentFrame = new QFrame;      // 具体显示面板
    label1 = new QLabel(tr("请选择一个值:"));
    comboBox1 = new QComboBox;
    label2 = new QLabel(tr("请输入字符串:"));
    lineEdit2 = new QLineEdit;
    textEdit = new QTextEdit;

    QGridLayout *TopLayout = new QGridLayout;
    TopLayout->addWidget(label1, 0, 0);
    TopLayout->addWidget(comboBox1, 0, 1);
    TopLayout->addWidget(label2, 1, 0);
    TopLayout->addWidget(lineEdit2, 1, 1);
    TopLayout->addWidget(textEdit, 2, 0, 1, 2);

    OkBtn = new QPushButton(tr("确认"));
    CancelBtn = new QPushButton(tr("取消"));

    QHBoxLayout *BottomLayout = new QHBoxLayout;
    BottomLayout->addStretch(1);
    BottomLayout->addWidget(OkBtn);
    BottomLayout->addWidget(CancelBtn);

    QVBoxLayout *mainLayout = new QVBoxLayout(contentFrame);
    mainLayout->addLayout(TopLayout);
    mainLayout->addLayout(BottomLayout);
}

void Palette::fillColorList(QComboBox *comboBox)
{
    QStringList colorList = QColor::colorNames();
    QString color;
    foreach (color, colorList)
    {
        QPixmap pix(QSize(70, 20));
        pix.fill(QColor(color));
        // 名称为NULL，即不显示颜色的名称
        comboBox->addItem(QIcon(pix), NULL);
        comboBox->setIconSize(QSize(70, 20));
        // 设置尺寸调整策略为AdjustToContents，符合内容的大小
        comboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    }
}

// 响应背景颜色的选择
void Palette::ShowWindow()
{
    // 背景颜色的选择
    QStringList colorList = QColor::colorNames();
    QColor color = QColor(colorList[windowComboBox->currentIndex()]);

    QPalette p = contentFrame->palette();
    // 设置Window类颜色，即背景色，第一个参数为颜色主题，第二个为具体的颜色值
    p.setColor(QPalette::Window, color);
    // 调色板应用到contentFrame中
    contentFrame->setPalette(p);
    // 更新显示
    contentFrame->update();
}

// 响应文字颜色的选择，即对前景色进行设置
void Palette::ShowWindowText()
{
    QStringList colorList = QColor::colorNames();
    QColor color = QColor(colorList[windowTextComboBox->currentIndex()]);
    QPalette p = contentFrame->palette();
    p.setColor(QPalette::WindowText, color);
    contentFrame->setPalette(p);
    // contentFrame->update();
}

// 响应对按钮背景色的选择
void Palette::ShowButton()
{
    QStringList colorList = QColor::colorNames();
    QColor color = QColor(colorList[buttonComboBox->currentIndex()]);
    QPalette p = contentFrame->palette();
    p.setColor(QPalette::Button, color);
    contentFrame->setPalette(p);
    contentFrame->update();
}

// 响应按钮上文字颜色的选择
void Palette::ShowButtonText()
{
    QStringList colorList = QColor::colorNames();
    QColor color = QColor(colorList[buttonTextComboBox->currentIndex()]);
    QPalette p = contentFrame->palette();
    p.setColor(QPalette::ButtonText, color);
    contentFrame->setPalette(p);
}

// 响应对可输入文本框背景色的选择
void Palette::ShowBase()
{
    QStringList colorList = QColor::colorNames();
    QColor color = QColor(colorList[baseComboBox->currentIndex()]);
    QPalette p = contentFrame->palette();
    p.setColor(QPalette::Base, color);
    contentFrame->setPalette(p);
}

Palette::~Palette()
{

}
