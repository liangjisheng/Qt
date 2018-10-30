#include "dialog.h"
#include <QHBoxLayout>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("StackedWidget"));
    list = new QListWidget(this);
    list->insertItem(0, tr("Window1"));
    list->insertItem(1, tr("Window2"));
    list->insertItem(2, tr("Window3"));

    label1 = new QLabel(tr("WindowTest1"));
    label2 = new QLabel(tr("WindowTest2"));
    label3 = new QLabel(tr("WindowTest3"));

    stack = new QStackedWidget(this);
    stack->addWidget(label1);
    stack->addWidget(label2);
    stack->addWidget(label3);

    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->setMargin(5);   // 设定对话框的边距为5
    mainLayout->setSpacing(5);  // 设定各个控件之间的间距为5
    mainLayout->addWidget(list);
    mainLayout->addWidget(stack, 0, Qt::AlignHCenter);
    mainLayout->setStretchFactor(list, 1);  // 设置可伸缩控件
    mainLayout->setStretchFactor(stack, 3);
    connect(list, &QListWidget::currentRowChanged,
            stack, &QStackedWidget::setCurrentIndex);
}

Dialog::~Dialog()
{

}
