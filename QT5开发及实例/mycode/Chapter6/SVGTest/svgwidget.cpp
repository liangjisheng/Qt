#include "svgwidget.h"
#include <QSize>

SvgWidget::SvgWidget(QWidget *parent)
    :QSvgWidget(parent)
{
    render = renderer();
}

void SvgWidget::wheelEvent(QWheelEvent *e)
{
    // diff的值表示每次滚轮滚动一定的值，图片大小改变的比例
    const double diff = 0.1;
    // 获取图片显示区的尺寸大小
    QSize size = render->defaultSize();
    int width = size.width();
    int height = size.height();

    if (e->delta() > 0)
    {
        width = int(this->width() + this->width() * diff);
        height = int(this->height() + this->height() * diff);
    }
    else
    {
        width = int(this->width() - this->width() * diff);
        height = int(this->height() - this->height() * diff);
    }

    resize(width, height);
}
