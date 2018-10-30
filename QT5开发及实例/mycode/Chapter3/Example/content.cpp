#include "content.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

Content::Content(QWidget *parent) : QFrame(parent)
{
    stack = new QStackedWidget(this);
    stack->setFrameStyle(QFrame::Panel | QFrame::Raised);
    baseInfo = new BaseInfo();
    contact = new Contact();
    detail = new Detail();
    stack->addWidget(baseInfo);
    stack->addWidget(contact);
    stack->addWidget(detail);

    AmendBtn = new QPushButton(tr("修改"));
    CloseBtn = new QPushButton(tr("关闭"));
    QHBoxLayout *BtnLayout = new QHBoxLayout;
    // addStretch:按比例分配空余空间，这里只调了一次，说明将修改和关闭按钮
    // 按默认大小放在本行的最后， 参数1表示有嵌套时的权重
    BtnLayout->addStretch(1);
    BtnLayout->addWidget(AmendBtn);
    BtnLayout->addWidget(CloseBtn);

    QVBoxLayout *RightLayout = new QVBoxLayout(this);
    RightLayout->setMargin(10);
    RightLayout->setSpacing(6);
    RightLayout->addWidget(stack);
    RightLayout->addLayout(BtnLayout);
}
